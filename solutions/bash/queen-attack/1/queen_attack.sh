#!/usr/bin/env bash

main () {
    OFS=IFS
    IFS=,
    local -a whiteQueenPos=()
    local -a blackQueenPos=()

    while (($# > 0)); do
        local temp=""
        case "$1" in
            -w)
                temp=$2
                whiteQueenPos=(${temp[*]})
                shift 2
                ;;
            -b)
                temp=$2
                blackQueenPos=(${temp[*]})
                shift 2
                ;;
            *)
                shift
                ;;
        esac
    done

    if ((whiteQueenPos[0] < 0|| blackQueenPos[0] < 0 )); then
        echo "row not positive"
        exit 1
    fi

    if ((whiteQueenPos[1] < 0 || blackQueenPos[1] < 0 )); then
        echo "column not positive"
        exit 1
    fi

    if ((whiteQueenPos[0] > 7 || blackQueenPos[0] > 7 )); then
        echo "row not on board"
        exit 1
    fi

    if ((whiteQueenPos[1] > 7 || blackQueenPos[1] > 7 )); then
        echo "column not on board"
        exit 1
    fi

    if ((whiteQueenPos[0] == blackQueenPos[0] && whiteQueenPos[1] == blackQueenPos[1])); then
        echo "same position"
        exit 1
    fi

    if ((whiteQueenPos[0] == blackQueenPos[0] || whiteQueenPos[1] == blackQueenPos[1])); then
        echo "true"
        exit 0
    fi

    declare -i xDistance=$((whiteQueenPos[0] - blackQueenPos[0]))
    if ((xDistance < 0)); then
        ((xDistance *= -1))
    fi

    declare -i yDistance=$((whiteQueenPos[1] - blackQueenPos[1]))
    if ((yDistance < 0)); then
        ((yDistance *= -1))
    fi

    if ((xDistance == yDistance)); then
        echo "true"
        exit 0
    fi

    echo "false"
    exit 0
}

main "$@"
