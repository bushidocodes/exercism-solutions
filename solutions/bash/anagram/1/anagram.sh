#!/usr/bin/env bash

count_chars() {
	if (($# != 2)); then
		printf "Unexpected number of arguments. Saw %d. Expected 2" "$#"
		exit 1
	fi

	local -r word="$1"
	local -n char_count="$2"

	# Add all characters as uppercase
	local buffer
	for ((i = 0; i < ${#word}; i++)); do
		buffer=${word:$i:1}
		buffer=${buffer^^}
		((char_count["$buffer"] += 1))
	done
}

char_count_is_equal() {
	if (($# != 2)); then
		printf "Unexpected number of arguments. Saw %d. Expected 2" "$#"
		exit 1
	fi

	local -n first="$1"
	local -n second="$2"

	# If key count is not the same, not equal
	((${#first[@]} != ${#second[@]})) && return 1

	# If a value differs, not equal
	for key in "${!first[@]}"; do
		((first["$key"] != second["$key"])) && return 1
	done

	return 0
}

main() {
	if (($# != 2)); then
		printf "Unexpected number of arguments. Saw %d. Expected 2" "$#"
		exit 1
	fi

	local -r word=$1
	local -a anagrams=()

	local -A word_char_count=()
	local -A candidate_char_count=()
	count_chars "$word" word_char_count

	IFS=" " read -r -a candidates <<< "${@:2}"

	for candidate in "${candidates[@]}"; do
		[[ "${candidate^^}" == "${word^^}" ]] && continue

		candidate_char_count=()
		count_chars "$candidate" candidate_char_count
		if char_count_is_equal word_char_count candidate_char_count; then
			anagrams+=("$candidate")
		fi
	done

	printf "%s\n" "${anagrams[*]}"
	return 0
}

main "$@"
