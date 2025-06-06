#!/usr/bin/env bash

panic() {
	(($# == 1)) && printf "Err: %s\n" "$1"
	exit 1
}

# Source: https://unix.stackexchange.com/questions/92447/bash-script-to-get-ascii-values-for-alphabet
chr() {
	(($# != 1)) && panic "Invalid Arg Count. Saw $#. Expected 1"
	(($1 > 256)) && panic "$1 is not an ASCII char code" "$1"
	printf "\\$(printf '%03o' "$1")"
}

ord() {
	LC_CTYPE=C printf '%d' "'$1"
}

declare char_code_a
char_code_a=$(ord "a")
declare char_code_z
char_code_z=$(ord "z")

encode() {
	# Cast to lowercase and strip all non alphanumerics
	local plaintext="${1,,}"
	plaintext="${plaintext//[![:alnum:]]/}"

	local ciphertext=""
	local -i ciphertext_char_code=0
	local plaintext_char=""
	local -i plaintext_char_code=0
	local -i plaintext_len=${#plaintext}
	local -i offset=0

	for ((i = 0; i < plaintext_len; i++)); do
		plaintext_char="${plaintext:i:1}"
		# Encode all letters, just append numbers
		if [[ $plaintext_char =~ [[:alpha:]] ]]; then
			plaintext_char_code=$(ord "$plaintext_char")
			offset=$((char_code_z - plaintext_char_code))
			ciphertext_char_code=$((char_code_a + offset))
			ciphertext+="$(chr $ciphertext_char_code)"
		else
			ciphertext+="$plaintext_char"
		fi
		# Break into 5 character "words"
		if ((i != plaintext_len - 1)) && (((i + 1) % 5 == 0)); then
			ciphertext+=" "
		fi
	done

	printf "%s\n" "$ciphertext"
	return 0
}

decode() {
	local ciphertext="${1// /}"
	local ciphertext_char=""
	local -i ciphertext_char_code=0
	local -i plaintext_char_code=0
	local plaintext=""
	for ((i = 0; i < ${#ciphertext}; i++)); do
		ciphertext_char="${ciphertext:i:1}"
		# Decode letters, just append numbers
		if [[ $ciphertext_char =~ [[:alpha:]] ]]; then
			ciphertext_char_code=$(ord "$ciphertext_char")
			offset=$((char_code_z - ciphertext_char_code))
			plaintext_char_code=$((char_code_a + offset))
			plaintext+="$(chr $plaintext_char_code)"
		else
			plaintext+="$ciphertext_char"
		fi
	done

	printf "%s\n" "$plaintext"
	return 0
}

usage() {
	printf "Usage: %s (encode|decode) (plaintext|ciphertext)\n" "$0"
	exit 0
}

main() {
	(($# != 2)) && usage
	local -r command="$1"

	case $command in
		encode)
			encode "$2"
			;;
		decode)
			decode "$2"
			;;
		*)
			usage
			;;
	esac

	return 0
}

main "$@"
