#!/usr/bin/env bash

function binary_search () {
    declare -i needle=$1
    declare -i low=$2
    declare -i high=$3
    declare -i mid=$(( low + ((high - low) / 2) ))
    
    if (("${haystack[$mid]}" == needle)); then
        echo "$mid"
        exit
    elif ((mid == low)); then
        echo "-1"
        exit
    elif (( needle < "${haystack[mid]}")); then
        binary_search "$needle" "$low" "$((mid - 1))" 
    elif (( needle > "${haystack[mid]}")); then
        binary_search "$needle" "$((mid + 1))" "$high"
    fi
}

main () {
    declare -i needle=$1
    declare -a haystack=("${@:2}")

    if ((${#haystack[@]} == 0)); then
        echo "-1"
        exit
    fi

    binary_search "$needle" 0 "$(("${#haystack[@]}" - 1))"
}

main "$@"

