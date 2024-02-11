FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    cmake \
    build-essential \
    qtbase5-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /s21_smartcalc/src

COPY . /s21_smartcalc/src

RUN make qmake_build
