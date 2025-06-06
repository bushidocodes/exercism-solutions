#!/usr/bin/env bash

main () {
    declare -i sourceRadix=$1;
    declare source=$2;
    declare -i targetRadix=$3;

    # Validate Radices
    ((sourceRadix < 2)) && {
        echo "sourceRadix must be 2 or higher";
        return 1;
    }
    ((targetRadix < 2)) && {
        echo "targetRadix must be 2 or higher";
        return 1;
    }

    # Split source string into an array of digits
    declare -a sourceDigits=();
    OIFS=$IFS;
    IFS=' ';
    for digit in $source; do
        sourceDigits+=("$digit");
    done

    # Calculate decimal value
    declare -i decimalBuffer=0;
    for ((i = 0; i < ${#sourceDigits[@]}; i++)); do
        if ((sourceDigits[i] < 0 || sourceDigits[i] >= sourceRadix)); then
            echo "digit must be between 0 and sourceRadix - 1";
            return 1;
        fi
        ((decimalBuffer = decimalBuffer * sourceRadix + sourceDigits[i]))
    done

    # Convert decimal value to target radix, with digits reverse
    declare -a targetDigitsReversed=();
    while ((decimalBuffer > 0)); do
        targetDigitsReversed+=("$((decimalBuffer % targetRadix))");
        ((decimalBuffer /= targetRadix));
    done

    # Reverse digits and join using spaces as delimiter
    declare -a targetDigits=();
    for ((i = ${#targetDigitsReversed[@]}; i >= 0; i--)); do
        targetDigits+=(${targetDigitsReversed[i]})
    done

    echo "${targetDigits[*]}";
    IFS=$OIFS;
}

main "$@"
