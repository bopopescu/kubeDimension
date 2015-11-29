FROM mhart/alpine-node:4.0.0

#Install packages
RUN apk update \
	&& apk add python python-dev gfortran py-pip build-base libuv nodejs c-ares libgcc mtools lddtree ca-certificates openssl \
                   pkgconf libstdc++ libc-dev mpc1 gcc g++ cmake libuv make python git && \
		   rm -rf /var/cache/apk/*

#Install vanilla gyp because that's how I learned to compile C
RUN cd /tmp && curl https://bootstrap.pypa.io/ez_setup.py -o - | python \
	&& git clone https://chromium.googlesource.com/external/gyp.git \
	&& cd gyp \
 	&& python setup.py install \
 	&& cd .. \
 	&& rm -rf gyp

COPY . /usr/src/kubeOpencv
WORKDIR /usr/src/kubeOpenCV
RUN cd /usr/src/kubeOpencv && \
    curl -kL https://github.com/Itseez/opencv/archive/2.4.11.zip -o ocv.zip && \
    unzip ocv.zip && \
    cd opencv-2.4.11 && \
    mkdir release && \
    cd release && \
    cmake -D CMAKE_BUILD_TYPE=RELEASE \
          -D CMAKE_INSTALL_PREFIX=/usr/local \
          .. && \
    make -j8 && \
    make install && \
    ldconfig && \

RUN cd /usr/src/kubeOpencv && \
	git clone https://github.com/davisking/dlib.git && \
	cd dlib && \
	mkdir build && \
	cd build && \
	cmake .. && \
	make -j8 && \
	make install

RUN cd /usr/src/kubeOpencv && \
	git clone https://github.com/thierrymalon/DBoW2.git && \ 
	git checkout sift && \ 
	cd /usr/local/src/DBoW2 && \ 
	git clone https://github.com/dorian3d/DLib.git && \ 
	cd DLib && \
	mkdir build && \ 
	cmake .. && \ 
	make -j8

RUN	cd /usr/local/src/DBoW2 && \
	mkdir build && \ 
	cmake .. && \ 
	make -j8

CMD ["/bin/sh"]
