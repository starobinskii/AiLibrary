#!/bin/bash

CXX='g++'
CXFLAGS='-O3 -std=c++11 -I../include/catch2'

mainName=tests-main
mainLink=./${mainName}.o
testOut=./tests.out
testFiles="tests-LibraryInfo.cc tests-StringFunctions.cc tests-DebugFunctions.cc tests-InterfaceFunctions.cc"

cd ./tests

rm -f ${testOut}

if ! [ -f ${mainLink} ]; then
    echo "Compiling main..."
    ${CXX} ${CXFLAGS} -o ${mainLink} ${mainName}.cc -c
fi

echo "Compiling tests..."
${CXX} ${CXFLAGS} -o ${testOut} ${mainLink} ${testFiles} && ${testOut} -r compact