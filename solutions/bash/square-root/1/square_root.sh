#!/usr/bin/env bash

# From https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
main () {
    local -i n="$1"

    if ((n < 0)); then
        exit 1
    fi

    local -i x="$n"
    local -i c=0
    local -i d=$((1 << 30))

    while ((d > n)); do
        ((d >>= 2))
    done

    while ((d != 0)); do
        if ((x >= c + d)); then
            ((x -= (c + d)))
            c=$(( (c / 2) + d ))
        else
            ((c >>= 1))
        fi

        ((d >>= 2))
    done

    echo "$c"
    exit 0
}

main "$@"
