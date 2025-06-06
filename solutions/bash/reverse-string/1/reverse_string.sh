#!/usr/bin/env bash

reverse_string(){
    local original_string=$1
    local length_of_string=${#original_string}
    local result=""
    for ((i=length_of_string-1;i>=0;i--))
    do
        result="${result}${original_string:$i:1}"
    done
    echo "$result"
}

main () {
    IFS='%'
    string="$1"
    result=$(reverse_string "$string")
    printf "%s" $result
    printf "\n"
}

main "$@"