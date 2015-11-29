// Tempory Copy/Paste

inline int dec(uchar x){ //convert uchar to int
    if (x>='0'&&x<='9') return (x-'0');
    else if (x>='a'&&x<='f') return (x-'a'+10);
    else if (x>='A'&&x<='F') return (x-'A'+10);
    return 0;
}
cv::Mat bytea2Mat(const string& f){
    const char* buffer=f.c_str();  
    vector<uchar>::size_type size = strlen((const char*)buffer);
    vector<uchar> jpgbytes(size/2-1); 

    for (size_t i=0; i!=size/2-1;i++) { 
        jpgbytes[i]=(dec(buffer[2*(i+1)])<<4)+dec(buffer[2*(i+1)+1]);
    }
    cout <<size/2<<";"<<jpgbytes.size()<<endl;
    return imdecode(jpgbytes, CV_LOAD_IMAGE_COLOR);
}

int thresh = 50, N = 11;

/// perform the Simplest Color Balancing algorithm
void SimplestCB(const cv::Mat& in,const cv::Mat& out, float percent) {
    assert(in.channels() == 3);
    assert(percent > 0 && percent < 100);

    float half_percent = percent / 200.0f;

    vector<cv::Mat> tmpsplit; split(in,tmpsplit);
    for(int i=0;i<3;i++) {
        //find the low and high precentile values (based on the input percentile)
        cv::Mat flat; tmpsplit[i].reshape(1,1).copyTo(flat);
        cv::sort(flat,flat,CV_SORT_EVERY_ROW + CV_SORT_ASCENDING);
        int lowval = flat.at<uchar>(cvFloor(((float)flat.cols) * half_percent));
        int highval = flat.at<uchar>(cvCeil(((float)flat.cols) * (1.0 - half_percent)));
        cout << lowval << " " << highval << endl;
        
        //saturate below the low percentile and above the high percentile
        tmpsplit[i].setTo(lowval,tmpsplit[i] < lowval);
        tmpsplit[i].setTo(highval,tmpsplit[i] > highval);
        
        //scale the channel
        normalize(tmpsplit[i],tmpsplit[i],0,255,NORM_MINMAX);
    }
    merge(tmpsplit,out);
}

cv::Mat equalizeIntensity(const cv::Mat& image)
{
    if(image.channels() >= 3)
    {
        cv::Mat ycrcb;

        cv::cvtColor(image,ycrcb,CV_BGR2YCrCb);

        std::vector<cv::Mat> channels;
        cv::split(ycrcb,channels);

        cv::equalizeHist(channels[0], channels[0]);

        cv::Mat result;
        cv::merge(channels,ycrcb);

        cv::cvtColor(ycrcb,result,CV_YCrCb2BGR);

        return result;
    }
    return cv::Mat();
}

bool is_border(cv::Mat& edge, cv::Vec3b color)
{
    cv::Mat im = edge.clone().reshape(0,1);

    bool res = true;
    for (int i = 0; i < im.cols; ++i)
        res &= (color == im.at<cv::Vec3b>(0,i));

    return res;
}

/* angle: finds a cosine of angle between vectors, from pt0->pt1 and from pt0->pt2
 */
double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0)
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

/* findSquares: returns sequence of squares detected on the image
 */
void findSquares(const cv::Mat& src, std::vector<std::vector<cv::Point> >& squares)
{
    cv::Mat src_gray;
    cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);

    // Blur helps to decrease the amount of detected edges
    cv::Mat filtered;
    cv::blur(src_gray, filtered, cv::Size(3, 3));
    //cv::imwrite("out_blur.jpg", filtered);

    // Detect edges
    cv::Mat edges;
    int thresh = 128;
    cv::Canny(filtered, edges, thresh, thresh*2, 3);
    //cv::imwrite("out_edges.jpg", edges);

    // Dilate helps to connect nearby line segments
    cv::Mat dilated_edges;
    cv::dilate(edges, dilated_edges, cv::Mat(), cv::Point(-1, -1), 2, 1, 1); // default 3x3 kernel
    //cv::imwrite("out_dilated.jpg", dilated_edges);

    // Find contours and store them in a list
    std::vector<std::vector<cv::Point> > contours;
    cv::findContours(dilated_edges, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);

    // Test contours and assemble squares out of them
    std::vector<cv::Point> approx;
    for (size_t i = 0; i < contours.size(); i++)
    {
        // approximate contour with accuracy proportional to the contour perimeter
        cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);

        // Note: absolute value of an area is used because
        // area may be positive or negative - in accordance with the
        // contour orientation
        if (approx.size() == 4 && std::fabs(contourArea(cv::Mat(approx))) > 1000 &&
            cv::isContourConvex(cv::Mat(approx)))
        {
            double maxCosine = 0;
            for (int j = 2; j < 5; j++)
            {
                double cosine = std::fabs(angle(approx[j%4], approx[j-2], approx[j-1]));
                maxCosine = MAX(maxCosine, cosine);
            }

            if (maxCosine < 0.3)
                squares.push_back(approx);
        }
    }
}

void rotationMatrix(double angle, const cv::Mat& src, const cv::Mat& dst) {
    // get rotation matrix for rotating the image around its center
    cv::Point2f center(src.cols/2.0, src.rows/2.0);
    cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
    // determine bounding rectangle
    cv::Rect bbox = cv::RotatedRect(center,src.size(), angle).boundingRect();
    // adjust transformation matrix
    rot.at<double>(0,2) += bbox.width/2.0 - center.x;
    rot.at<double>(1,2) += bbox.height/2.0 - center.y;

    cv::warpAffine(src, dst, rot, bbox.size());
}

/* findLargestSquare: find the largest square within a set of squares
 */
void findLargestSquare(const std::vector<std::vector<cv::Point> >& squares,
                       std::vector<cv::Point>& biggest_square)
{
    if (!squares.size())
    {
        std::cout << "findLargestSquare !!! No squares detect, nothing to do." << std::endl;
        return;
    }

    int max_width = 0;
    int max_height = 0;
    int max_square_idx = 0;
    for (size_t i = 0; i < squares.size(); i++)
    {
        // Convert a set of 4 unordered Points into a meaningful cv::Rect structure.
        cv::Rect rectangle = cv::boundingRect(cv::Mat(squares[i]));

        //std::cout << "find_largest_square: #" << i << " rectangle x:" << rectangle.x << " y:" << rectangle.y << " " << rectangle.width << "x" << rectangle.height << endl;

        // Store the index position of the biggest square found
        if ((rectangle.width >= max_width) && (rectangle.height >= max_height))
        {
            max_width = rectangle.width;
            max_height = rectangle.height;
            max_square_idx = i;
        }
    }

    biggest_square = squares[max_square_idx];
}

cv::Mat debugSquares(std::vector<std::vector<cv::Point> >& squares, cv::Mat image )
{
    for( size_t i = 0; i< squares.size(); i++ ) {
        // draw contour
        cv::drawContours(image, squares, i, cv::Scalar(255,0,0), 1, 8, std::vector<cv::Vec4i>(), 0, cv::Point());

        // draw bounding rect
        cv::Rect rect = boundingRect(cv::Mat(squares[i]));
        cv::rectangle(image, rect.tl(), rect.br(), cv::Scalar(0,255,0), 2, 8, 0);

        // draw rotated rect
        cv::RotatedRect minRect = minAreaRect(cv::Mat(squares[i]));
        cv::Point2f rect_points[4];
        minRect.points( rect_points );
        for ( int j = 0; j < 4; j++ ) {
            cv::line( image, rect_points[j], rect_points[(j+1)%4], cv::Scalar(0,0,255), 1, 8 ); // blue
        }
    }
    return image;
}

void autocrop(cv::Mat& src, cv::Mat& dst)
{
    cv::Rect win(0, 0, src.cols, src.rows);

    std::vector<cv::Rect> edges;
    edges.push_back(cv::Rect(0, 0, src.cols, 1));
    edges.push_back(cv::Rect(src.cols-2, 0, 1, src.rows));
    edges.push_back(cv::Rect(0, src.rows-2, src.cols, 1));
    edges.push_back(cv::Rect(0, 0, 1, src.rows));

    cv::Mat edge;
    int nborder = 0;
    cv::Vec3b color = src.at<cv::Vec3b>(0,0);

    for(size_t i = 0; i < edges.size(); ++i)
    {
        edge = src(edges[i]);
        nborder += is_border(edge, color);
    }

    if (nborder < 4)
    {
        src.copyTo(dst);
        return;
    }

    bool next;

    do {
        edge = src(cv::Rect(win.x, win.height-2, win.width, 1));
        if ((next = is_border(edge, color)))
            win.height--;
    }
    while (next && win.height > 0);

    do {
        edge = src(cv::Rect(win.width-2, win.y, 1, win.height));
        if ((next = is_border(edge, color)))
            win.width--;
    }
    while (next && win.width > 0);

    do {
        edge = src(cv::Rect(win.x, win.y, win.width, 1));
        if ((next = is_border(edge, color)))
            win.y++, win.height--;
    }
    while (next && win.y <= src.rows);

    do {
        edge = src(cv::Rect(win.x, win.y, 1, win.height));
        if ((next = is_border(edge, color)))
            win.x++, win.width--;
    }
    while (next && win.x <= src.cols);

    dst = src(win);
}

static cv::Scalar randomColor(cv::RNG& rng)
{
    int icolor = (unsigned)rng;

    return cv::Scalar(icolor&0xFF, (icolor>>8)&0xFF, (icolor>>16)&0xFF);
}

void plotMatches(const cv::Mat &srcColorImage, const cv::Mat &dstColorImage, vector<cv::Point2f> &srcPoints, vector<cv::Point2f> &dstPoints){
    
    // Create a image for displaying mathing keypoints
    cv::Size sz = cv::Size(srcColorImage.size().width + dstColorImage.size().width, srcColorImage.size().height + dstColorImage.size().height);
    cv::Mat matchingImage = cv::Mat::zeros(sz, CV_8UC3);
    
    // Draw camera frame
    cv::Mat roi1 = cv::Mat(matchingImage, cv::Rect(0, 0, srcColorImage.size().width, srcColorImage.size().height));
    srcColorImage.copyTo(roi1);
    // Draw original image
    cv::Mat roi2 = cv::Mat(matchingImage, cv::Rect(srcColorImage.size().width, srcColorImage.size().height, 
        dstColorImage.size().width, dstColorImage.size().height));
    dstColorImage.copyTo(roi2);

    cv::RNG rng(0xFFFFFFFF);
    // Draw line between nearest neighbor pairs
    for (int i = 0; i < (int)srcPoints.size(); ++i) {
        cv::Point2f pt1 = srcPoints[i];
        cv::Point2f pt2 = dstPoints[i];
        cv::Point2f from = pt1;
        cv::Point2f to   = cv::Point(srcColorImage.size().width + pt2.x, srcColorImage.size().height + pt2.y);
        cv::line(matchingImage, from, to, randomColor(rng), 2);
    }

    // Display mathing image
    cv::resize(matchingImage, matchingImage, cv::Size(matchingImage.cols/2, matchingImage.rows/2));
}

void findInliers(vector<cv::KeyPoint> &qKeypoints, vector<cv::KeyPoint> &objKeypoints, 
    vector<cv::DMatch> &matches, const cv::Mat &srcColorImage, const cv::Mat &dstColorImage){
    vector<cv::Point2f> queryCoord;
    vector<cv::Point2f> objectCoord;
    for( unsigned int i = 0; i < matches.size(); i++){
        queryCoord.push_back((qKeypoints[matches[i].queryIdx]).pt);
        objectCoord.push_back((objKeypoints[matches[i].trainIdx]).pt);
    }
    plotMatches(srcColorImage, dstColorImage, queryCoord, objectCoord);
    
    cv::Mat mask;
    vector<cv::Point2f> queryInliers;
    vector<cv::Point2f> sceneInliers;
    cv::Mat H = findFundamentalMat(queryCoord, objectCoord, mask, CV_FM_RANSAC);
    //Mat H = findHomography( queryCoord, objectCoord, CV_RANSAC, 10, mask);
    int inliers_cnt = 0, outliers_cnt = 0;
    for (int j = 0; j < mask.rows; j++){
        if (mask.at<uchar>(j) == 1){
            queryInliers.push_back(queryCoord[j]);
            sceneInliers.push_back(objectCoord[j]);
            inliers_cnt++;
        }else {
            outliers_cnt++;
        }
    }
    plotMatches(srcColorImage, dstColorImage, queryInliers, sceneInliers);
}