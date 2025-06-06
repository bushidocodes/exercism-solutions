#!/usr/bin/env bash

encode () {
    declare plaintext="$1"
    declare lastChar="\0"
    declare -i lastCharCount=0

    declare ciphertext=""

    for ((i=0; i < ${#plaintext}; i++)); do
        char="${plaintext:$i:1}"
        if [[ "$lastChar" == "\0" ]]; then
            lastChar="$char"
            lastCharCount=1
        elif [[ "$lastChar" == "$char" ]]; then
            ((lastCharCount++))
        else
            if (($lastCharCount > 1)); then
                ciphertext="$ciphertext$lastCharCount"
            fi
            ciphertext="$ciphertext$lastChar"

            lastChar="$char"
            lastCharCount=1
        fi
    done

    if [[ "$lastChar" != "\0" ]]; then
        if (($lastCharCount > 1)); then
            ciphertext="$ciphertext$lastCharCount"
        fi
        ciphertext="$ciphertext$lastChar"
    fi

    echo "$ciphertext"
    exit 0
}

decode () {
    declare ciphertext="$1"
    declare plaintext=""

    declare -i countBuffer=0

    for ((i=0; i < ${#ciphertext}; i++)); do
        char="${ciphertext:$i:1}"

        if [[ $char =~ [[:digit:]] ]]; then
            countBuffer=$((countBuffer * 10 + $char))
        else 
            if ((countBuffer > 0)); then
                for ((j=0; j < countBuffer; j++)); do
                    plaintext="$plaintext$char"
                done
            else
                plaintext="$plaintext$char"
            fi
            countBuffer=0
        fi
    done

    echo "$plaintext"
    exit 0
}

main () {
    declare command="$1"
    declare input="$2"

    case "$command" in
        encode)
            encode "$input"
            ;;
        decode)
            decode "$input"
            ;;
        *)
            echo "Usage: $0 <encode|decode> input"
            ;;
    esac

    exit 0
}

main "$@"
