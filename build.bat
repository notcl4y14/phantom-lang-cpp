@echo off
if not exist dist (mkdir dist)
g++ main.cpp src/*.cpp util/*.cpp -o dist\phantom.exe %*