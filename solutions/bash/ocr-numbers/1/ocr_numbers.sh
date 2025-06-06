#!/usr/bin/env bash

main() {
    local -i line_count=0
    local -i word_count=0
    local should_comma=false;
	local -a digit_buffer
    local result
	
    while IFS= read -r line; do
        if $should_comma ; then
            result="${result},"
            should_comma=false
        fi
      
        if ((${#line} % 3 != 0)); then 
            echo "Number of input columns is not a multiple of three"
            return 1
        fi

        if ((line_count++ < 3)); then
            # Build up a buffer of digits
            for ((i=0; i*3 < ${#line}; i++)); do
                digit_buffer[i]="${digit_buffer[$i]}${line:$((i*3)):3}"
            done
        else
            # After four lines, parse the digits in our buffer
            for digit in "${digit_buffer[@]}"; do
                case "$digit" in
                " _ | ||_|") result="${result}0" ;;
                "     |  |") result="${result}1" ;;
                " _  _||_ ") result="${result}2" ;;
                " _  _| _|") result="${result}3" ;;
                "   |_|  |") result="${result}4" ;;
                " _ |_  _|") result="${result}5" ;;
                " _ |_ |_|") result="${result}6" ;;
                " _   |  |") result="${result}7" ;;
                " _ |_||_|") result="${result}8" ;;
                " _ |_| _|") result="${result}9" ;;
                *) result="${result}?" ;;
                esac
            done
            line_count=0
            should_comma=true
            digit_buffer=()
        fi
	done < /dev/stdin

    # We could theoretically check this prior to parsing if we read into an intermediate
    # array as the expense of additional memory consumption. Since the size of the input
    # is unbounded, I prefer not to do this
    if ((line_count % 4 != 0)); then
        echo "Number of input lines is not a multiple of four"
        return 1
    fi 

    printf "%s\n" "$result"
    return 0
}

main "$@"
