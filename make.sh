#!/bin/bash
gcc -c wifi_scan.c
g++ -c main.cc
g++ wifi_scan.o main.o -lmnl -o wifiscan
