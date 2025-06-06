#!/usr/bin/env bash

main () {
    readarray -t rows

    declare -i longest=0;
    for row in "${rows[@]}"; do
        if ((${#row} > longest)); then
            ((longest = ${#row}))
        fi
    done

    declare -a transposed=()
    for (( i=0; i < longest; i++)); do
        for (( j=0; j < ${#rows[@]}; j++)); do
            # Extract current char
            currentRow="${rows[$j]}"
            currentChar="${currentRow:$i:1}"

            # Pad the left of transposed row
            if ((${#currentChar} > 0)); then
                while ((${#transposed[$i]} < $j)); do
                    transposed[$i]="${transposed[$i]} "
                done
            fi

            # Append current char
            transposed[$i]="${transposed[$i]}${currentChar}"
        done
    done 

    for row in "${transposed[@]}"; do
        echo "$row"
    done

    exit 0
}

main "$@"
