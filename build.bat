@echo off

mkdir build

cd build

cmake -G ..
cmake --build .

cd ..
