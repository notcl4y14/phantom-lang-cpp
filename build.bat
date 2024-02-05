@echo off
if not exist dist (mkdir dist)
rem g++ -c src/token.cpp
rem g++ main.cpp -o dist\phantom.exe token.o %*
rem del token.o
g++ main.cpp -o dist\phantom.exe %*