#!/bin/bash

rm -rf ./docs

doxygen ./Scripts/doxygen.html.txt

doxygen ./Scripts/doxygen.xml.txt

moxygen --output API.md  ./xml

rm -rf ./xml
