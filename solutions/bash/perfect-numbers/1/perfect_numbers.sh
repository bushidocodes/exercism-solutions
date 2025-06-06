#!/usr/bin/env bash

factorize() {
    local -i n="$1"
    local -i second=$n

    for ((first = 1; first < second; first++)); do
        second=$((n / first))
        if ((n % first == 0)); then   
            factors+=("$first")
            if ((second != n && second != first)); then
                factors+=("$second")
            fi
        fi
    done

    return;
}

main () {
    local n="$1"

    if ((n <= 0)); then
        echo "Classification is only possible for natural numbers."
        exit 1
    fi

    local -a factors=()
    factorize "$n"

    local -i sum=0
    for (( i=0; i < ${#factors[@]}; i++)); do
        ((sum += factors[i]))
    done 

    if ((sum == n)); then
        echo "perfect"
    elif ((sum > n)); then
        echo "abundant"
    else 
        echo "deficient"
    fi
}

main "$@"
