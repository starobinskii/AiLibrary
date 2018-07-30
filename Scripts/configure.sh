#!/bin/bash

if [ -f ~/.bash_interface ]; then
    source ~/.bash_interface
else
    printHeader(){
        tput bold
        tput setaf 4
        echo -n "==> "
        tput setaf 0
        echo ${1}
        tput sgr0
    }
    printError(){
        tput bold
        tput setaf 1
        echo -n "ERROR: "
        tput setaf 0
        echo ${1}
        tput sgr0
    }
    showProgressBar(){
        i=${1};
        if [ ${i} -lt 0 ]; then i=0; fi
        if [ ${i} -gt 100 ]; then i=100; fi
        bar1="================================================================================"
        bar2="--------------------------------------------------------------------------------"
        n=$((73 * ${i} / 100))
        echo -ne "\r"${bar1:0:${n}}${bar2:${n}:$((73 - ${n}))}" "${i}".0%"
    }
fi

#*# ************************************************************************ #*#
libraryFile="./ai.source"
libraryLink="https://raw.githubusercontent.com/starobinskii/AiLibrary/master/Sources/ai.hh"
wildcard="./*.h ./*.cpp ./*.hpp ./*.cxx ./*.hxx ./*.cc ./*.hh"
destinationFile="./ai.hh"
temporaryFile="./ai.tmp"

#*# ************************************************************************ #*#
printIncludes(){
    includes=$(grep "#include" ${libraryFile})

    for include in "${includes[@]}"; do
        echo "${include}"
    done
}
printFunction(){
    functionName=${1}

    linesInTotal=$(cat ${libraryFile} | wc -l)

    lineNumbersToStart=$(grep -n " ${functionName}(" ${libraryFile} | awk '{print $1+0}')

    if [ -z "${lineNumbersToStart}" ]; then
        printError "Cannot find function ${functionName}"
        exit 2
    fi

    for lineNumberToStart in ${lineNumbersToStart}; do
        lineNumberToTest=$((${lineNumberToStart} - 1))
        additionalLine=$(sed "${lineNumberToTest}q;d" ${libraryFile} | grep "template")

        linesInFunction=$(sed -n "$((${lineNumberToStart} + 1)),${linesInTotal}p" ${libraryFile} | awk '/^    }/{print NR}' | head -n 1);
    
        if [ -z "${lineNumberToStart}" ]; then
            printError "Cannot calculate number of lines in ${funcName}"
            exit 3
        fi

        lineNumberToFinish=$((${lineNumberToStart} + ${linesInFunction}))

        if [ "${additionalLine}" ]; then
            echo "${additionalLine}"
        fi
        sed -n "${lineNumberToStart},${lineNumberToFinish}p" ${libraryFile}
    done
}

#*# ************************************************************************ #*#
if [ ! -f ${libraryFile} ]; then
    wget "${libraryLink}" -O ${libraryFile}
    
    if [ ! -f ${libraryFile} ]; then
        printError "Cannot download ${libraryLink}"
        exit 4
    fi

    libraryLink=''
fi

#*# ************************************************************************ #*#
printHeader "Checking that all required functions exist... "

functionList=$(cat ${wildcard} 2>/dev/null | grep -oE 'ai::[a-zA-Z\d]+' | sort -u | sed -e 's/ai:://g')

allFunctionWereFound=true
iter=0
functionArray=(${functionList})
total=${#functionArray[@]}
for functionName in ${functionList}; do
    functionFound=$(grep " ${functionName}(" ${libraryFile})

    if [ -z "${functionFound}" ]; then
        printError "Cannot find function ${functionName}"
        
        allFunctionWereFound=false
    fi
    
    iter=$((${iter} + 1))

    showProgressBar $((100 * ${iter} / ${total}))
done

if [ false = "${allFunctionWereFound}" ] ; then
    exit 5
fi

showProgressBar 100

#*# ************************************************************************ #*#
printHeader "Listing dependencies... "

echo "" > ${temporaryFile}
iter=0
functionArray=(${functionList})
total=${#functionArray[@]}
for functionName in ${functionList}; do
    printFunction "${functionName}" >> ${temporaryFile}
    
    iter=$((${iter} + 1))
    
    showProgressBar $((100 * ${iter} / ${total}))
done

functionList=$(cat "${temporaryFile}" ${wildcard} 2>/dev/null | grep -oE 'ai::[a-zA-Z\d]+' | perl -ne 'if(!defined $x{$_}){print $_; $x{$_} = 1;}' | sed -e 's/ai:://g')

rm -f ${temporaryFile}

showProgressBar 100

#*# ************************************************************************ #*#
printHeader "Saving library... "

echo "#pragma once" > ${destinationFile}
echo "" >> ${destinationFile}
printIncludes >> ${destinationFile}
echo "" >> ${destinationFile}
echo "namespace ai{" >> ${destinationFile}

iter=0
functionArray=(${functionList})
total=${#functionArray[@]}
for functionName in ${functionList}; do
    printFunction "${functionName}" >> ${destinationFile}
    
    iter=$((${iter} + 1))
    
    showProgressBar $((100 * ${iter} / ${total}))
done

echo "}" >> ${destinationFile}

showProgressBar 100

#*# ************************************************************************ #*#
if [ -z "${libraryLink}" ]; then
    rm -f ${libraryFile}
fi