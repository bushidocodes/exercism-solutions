#!/usr/bin/env bash

is_leap_year(){
    local year=$1
    ((year % 4 == 0)) && ( ((year % 100 != 0)) || ((year % 400 == 0)) )
}

main () {
    local year=$1

    if [[ $# -ne 1 ]] || ! [[ "$1" =~ ^[0-9]+$ ]]
    then
        printf "Usage: leap.sh <year>\n"
        return 1
    fi

    is_leap_year "$year" && echo "true" || echo "false"
    return 0
}

main "$@"
