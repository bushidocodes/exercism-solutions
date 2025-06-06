#!/usr/bin/env bash

# Shellcheck seems unable to account for namerefs when looking for unused variables
# shellcheck disable=SC2034

to_char_code() {
	local char=$1
	local -n __char_code=$2

	# Should be a string of length 1
	((${#char} > 1)) && return 1

	printf -v __char_code "%d\n" "'$char"
	return 0
}

from_char_code() {
	local plaintext_char_code=$1
	local -n __char=$2

	# Should be a valid ASCII char code
	((plaintext_char_code < 0)) || ((plaintext_char_code > 127)) && return 1

	printf -v __char "\x$(printf "%x" "$plaintext_char_code")"
	return 0
}

rotate() {
	local plaintext=$1
	local -i shift=$2
	local ciphertext=""

	for ((i = 0; i < ${#plaintext}; i++)); do
		local plaintext_char="${plaintext:i:1}"

		# Only rotates letters
		if [[ "$plaintext_char" =~ [a-zA-Z] ]]; then
			# Convert to character code
			local -i plaintext_char_code
			if ! to_char_code "$plaintext_char" plaintext_char_code; then
				return 1
			fi

			# Shift character code, maintaining case
			local -i char_code_A=65
			local -i char_code_a=97
			local -i ciphertext_char_code

			# lowercase has higher character codes in ASCII table. Infer uppercase if less than a
			if ((plaintext_char_code < char_code_a)); then
				ciphertext_char_code=$((char_code_A + ((plaintext_char_code - char_code_A + shift) % 26)))
			else
				ciphertext_char_code=$((char_code_a + ((plaintext_char_code - char_code_a + shift) % 26)))
			fi

			# Convert back to a character
			local ciphertext_char
			if ! from_char_code "$ciphertext_char_code" ciphertext_char; then
				return 1
			fi

			ciphertext+=$ciphertext_char
		else
			ciphertext+=$plaintext_char
		fi
	done

	echo "$ciphertext"
	return 0
}

rotate "$@"
