#!/bin/bash

rm -rf ./docs

doxygen ./Scripts/doxygen.txt

moxygen --output API.md  ./xml

rm -rf ./xml
