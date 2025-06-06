#!/bin/bash

# Source: https://unix.stackexchange.com/questions/92447/bash-script-to-get-ascii-values-for-alphabet

chr() {
	[ "$1" -lt 256 ] || return 1
	printf "\\$(printf '%03o' "$1")"
}

ord() {
	LC_CTYPE=C printf '%d' "'$1"
}
