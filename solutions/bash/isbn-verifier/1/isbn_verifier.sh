#!/usr/bin/env bash

main () {
    isbnString="${1//-}"

    if ((${#isbnString} != 10)); then
        echo "false"
        return
    fi

    re='^[0-9X]+$'
    for ((i = 0; i < 9; i++)); do
        if ! [[ ${isbnString:$i:1} =~ $re ]]; then
            echo "false"
            return 0;
        fi
    done

    declare -i sum=0
    for ((i = 0; i < 9; i++)); do
        ((sum += ${isbnString:$i:1} * (10 - i)))
    done

    declare -i checksum=0
    if [[ ${isbnString:9:1} == "X" ]]; then
        checksum=10
    else 
        checksum=${isbnString:9:1}
    fi


    if (((sum + checksum) % 11 == 0)); then
        echo "true"
        return 0
    fi 

    echo "false"
    return 0
}

main "$@"
