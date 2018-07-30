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
destinationFile="./ai.hh"
differenceFile="./ai.diff"

#*# ************************************************************************ #*#
getVersion(){
    filename=${1}

    lineNumber=$(grep -n " getVersion" ${filename} | awk '{print $1+0}')

    sed -n $((${lineNumber} + 1))p ${filename} | awk -F'\"' '{print $2}'
}

compareVersions(){
    if [ "${1}" = "${2}" ]; then
        echo "0"
    elif [ "${1}" = "$(echo -e "${1}\n${2}" | sort -V | head -n 1)" ]; then
        echo "1"
    else
        echo "-1"
    fi
}

#*# ************************************************************************ #*#
printHeader "Checking version... "

wget -q "${libraryLink}" -O ${libraryFile}

if [ ! -f ${libraryFile} ]; then
    printError "Cannot download ${libraryLink}"
    exit 2
fi

if [ ! -f ${libraryFile} ]; then
    mv -f ${libraryFile} ${destinationFile}
    
    echo "You have no instance of the library."
    echo "Installed version from Git".
    
    exit
fi

localVersion=$(getVersion ${destinationFile})
gitVersion=$(getVersion ${libraryFile})

if [ "$(compareVersions ${localVersion} ${gitVersion})" -lt "1" ]; then
    echo "No need to update, your version is actual."
else
    diff ${destinationFile} ${libraryFile} > ${differenceFile}
    
    localFile=${destinationFile}"-${localVersion}.source"
    
    mv -f ${destinationFile} ${localFile}
    
    mv -f ${libraryFile} ${destinationFile}
    
    echo "Updated successfully."
    echo ""
    
    while true; do
        read -p "Save your version? [y/N]" yn
        case ${yn} in
            [Yy]* )
                echo "Saved to ${localFile}."
                break
                ;;
            * )
                rm -f ${localFile}
                echo "Deleted."
                break
                ;;
        esac
    done
    
    while true; do
        read -p "Save diff-file? [y/N]" yn
        case ${yn} in
            [Yy]* )
                echo "Saved to ${differenceFile}."
                break
                ;;
            * )
                rm -f ${differenceFile}
                echo "Deleted."
                break
                ;;
        esac
    done
fi

