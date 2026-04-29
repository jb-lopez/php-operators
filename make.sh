#!/usr/bin/env bash

phpize
./configure --enable-operator=shared
make
make install
cp modules/operator.so output/operator.so
