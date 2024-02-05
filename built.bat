@echo off
if not exist dist (mkdir dist)
g++ main.cpp -o dist\phantom.exe