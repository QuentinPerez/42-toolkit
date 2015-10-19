FROM ubuntu:latest

RUN apt-get install -y software-properties-common \
 && add-apt-repository ppa:ubuntu-toolchain-r/test \
 && apt-get update \
 && apt-get -y upgrade

RUN apt-get -y install \
      build-essential \
      gcc-5 \
	  g++-5 \
	  vim

RUN ln -fs /usr/bin/gcc-5 /usr/bin/gcc \
 && ln -fs /usr/bin/g++-5 /usr/bin/g++

RUN gcc --version \
 && g++ --version

RUN mkdir -p /usr/root/42-toolkit
WORKDIR /usr/root/42-toolkit

RUN apt-get clean
