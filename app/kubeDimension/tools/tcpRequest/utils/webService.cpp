// Temporary Copy/Paste

std::string jsonParser(const find_object::DetectionInfo & info, bool debugDetails, Json::Value debugInfo) {
  Json::Value root;
  root["Status"] = 200; 
  if(info.objDetected_.size())
  {
    Json::Value detections;
    Json::Value details;
    QMultiMap<int, int>::const_iterator iterInliers = info.objDetectedInliersCount_.constBegin();
    QMultiMap<int, int>::const_iterator iterOutliers = info.objDetectedOutliersCount_.constBegin();
    QMultiMap<int, QSize>::const_iterator iterSizes = info.objDetectedSizes_.constBegin();
    QMultiMap<int, QString>::const_iterator iterFilePaths = info.objDetectedFilePaths_.constBegin();
    for(QMultiMap<int, QTransform>::const_iterator iter = info.objDetected_.constBegin(); iter!= info.objDetected_.end();)
    {
      char index = 'a';
      int id = iter.key();
      while(iter != info.objDetected_.constEnd() && id == iter.key())
      {

        QString name = QString("object_%1%2").arg(id).arg(info.objDetected_.count(id)>1?QString(index++):"");
        Json::Value connect;
        connect["MarkerId"] = "98825";
        connect["Score"]  = iterInliers.value();
        connect["Keywords"] = name.toStdString();
        detections.append(connect);

        root["Results"].append(connect);

        if(debugDetails) {
            Json::Value homography;
            homography.append(iter.value().m11());
            homography.append(iter.value().m12());
            homography.append(iter.value().m13());
            homography.append(iter.value().m21());
            homography.append(iter.value().m22());
            homography.append(iter.value().m23());
            homography.append(iter.value().m31());  // dx
            homography.append(iter.value().m32());  // dy
            homography.append(iter.value().m33());

            float objectWidth = iterSizes.value().width();
            float objectHeight = iterSizes.value().height();

            // Find corners Qt
            QTransform qtHomography = iter.value();
            QPointF qtTopLeft = qtHomography.map(QPointF(0,0));
            QPointF qtTopRight = qtHomography.map(QPointF(objectWidth,0));
            QPointF qtBottomLeft = qtHomography.map(QPointF(0,objectHeight));
            QPointF qtBottomRight = qtHomography.map(QPointF(objectWidth,objectHeight));

            root["Details"][name.toStdString()]["boundingBox"]["qtTopLeft"].append(qtTopLeft.x());
            root["Details"][name.toStdString()]["boundingBox"]["qtTopLeft"].append(qtTopLeft.y());

            root["Details"][name.toStdString()]["boundingBox"]["qtTopRight"].append(qtTopRight.x());
            root["Details"][name.toStdString()]["boundingBox"]["qtTopRight"].append(qtTopRight.y());

            root["Details"][name.toStdString()]["boundingBox"]["qtBottomLeft"].append(qtBottomLeft.x());
            root["Details"][name.toStdString()]["boundingBox"]["qtBottomLeft"].append(qtBottomLeft.y());

            root["Details"][name.toStdString()]["boundingBox"]["qtBottomRight"].append(qtBottomRight.x());
            root["Details"][name.toStdString()]["boundingBox"]["qtBottomRight"].append(qtBottomRight.y());

            root["Details"][name.toStdString()]["dimensions"]["width"] = iterSizes.value().width();
            root["Details"][name.toStdString()]["dimensions"]["height"] = iterSizes.value().height();
            root["Details"][name.toStdString()]["homography"] = homography;
            root["Details"][name.toStdString()]["detection"]["inliers"] = iterInliers.value();
            root["Details"][name.toStdString()]["detection"]["outliers"] = iterOutliers.value();
            root["Details"][name.toStdString()]["source"]["filepath"] = iterFilePaths.value().toStdString();
            QString filename;

            if(!iterFilePaths.value().isEmpty())
            {
              QFileInfo file(iterFilePaths.value());
              filename=file.fileName();
            }
            root["Details"][name.toStdString()]["source"]["filename"] = filename.toStdString();
        }
        ++iter;
        ++iterInliers;
        ++iterOutliers;
        ++iterSizes;
        ++iterFilePaths;
      }
    }
  } else {
    root["Results"] = "[]";
  }

    if(debugDetails) {
        root["Debug"] = debugInfo;
    }

  // write in a nice readible way
  Json::FastWriter fastWriter;
  return fastWriter.write(root).c_str();
}

std::string mediaExt(std::string data){
    if(data.find("image/jpeg") != std::string::npos){
        return ".jpg";
    }else if(data.find("image/png") != std::string::npos){
        return ".png";
    }else if(data.find("image/gif") != std::string::npos){
        return ".gif";
    }else if(data.find("image/jpg") != std::string::npos){
        return ".jpg";
    }else if(data.find(".jpeg") != std::string::npos){
        return ".jpg";
    }else if(data.find(".png") != std::string::npos){
        return ".png";
    }else if(data.find(".jpg") != std::string::npos){
        return ".jpg";
    } else {
        return "";
    }
}

// Will be util for Connect response wrapper
std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

QString toDebug(const QByteArray & line) {

    QString s;
    uchar c;

    for ( int i=0 ; i < line.size() ; i++ ){
        c = line[i];
        if ( c >= 0x20 and c <= 126 ) {
            s.append(c);
        } else {
            s.append(QString("<%1>").arg(c, 2, 16, QChar('0')));
        }
    }
    return s;
}

static inline bool is_base64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64_decode(std::string const& encoded_string) {
    int in_len = encoded_string.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string ret;

    while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
        char_array_4[i++] = encoded_string[in_]; in_++;
        if (i == 4) {
            for (i = 0; i < 4; i++)
                char_array_4[i] = base64_chars.find(char_array_4[i]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; (i < 3); i++)
                ret += char_array_3[i];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 4; j++)
            char_array_4[j] = 0;

        for (j = 0; j < 4; j++)
            char_array_4[j] = base64_chars.find(char_array_4[j]);

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
    }

    return ret;
}