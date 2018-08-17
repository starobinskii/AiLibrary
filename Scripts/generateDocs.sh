#!/bin/bash

rm -rf ./docs

doxygen ./Scripts/doxygen.html.txt

doxygen ./Scripts/doxygen.xml.txt

moxygen ./xml

mv api.md API.md

rm -rf ./xml
