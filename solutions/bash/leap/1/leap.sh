#!/usr/bin/env bash

is_leap_year(){
    local year=$1
    if [[ $(($year % 4)) -eq 0 && ( $(($year % 100)) -ne 0 || $(($year % 400)) -eq 0 ) ]]
    then
        return 1
    else
        return 0
    fi
}

main () {
    local year=$1

    if [[ $# -ne 1 ]] || ! [[ "$1" =~ ^[0-9]+$ ]]
    then
        printf "Usage: leap.sh <year>\n"
        return 1
    fi

    is_leap_year "$year"

    if [ $? -eq 1 ]
    then
        printf "true\n"
    else
        printf "false\n"
    fi
    
    return 0
}

main "$@"
