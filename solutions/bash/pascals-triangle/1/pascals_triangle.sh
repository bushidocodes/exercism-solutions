#!/usr/bin/env bash

NEWLINE=$'\n'

main () {
    local -i nrows="$1"
    local result=""
    local -a rowBuffer=()

    for (( i=0; i<nrows; i++ )); do
        if ((i == 0)); then
            rowBuffer=(1)
        else
            for (( j=${#rowBuffer[@]} - 1; j >= 1; j-- )); do
                ((rowBuffer[j] += rowBuffer[j - 1]))
            done
            rowBuffer+=(1)
        fi

        OFS=IFS
        IFS=
        for ((j=0; j < nrows - i - 1; j++)); do
            result="$result "
        done

        IFS=OFS
        result="$result${rowBuffer[*]}\n"
    done

    echo -e $result
    exit 0
}

main "$@"
