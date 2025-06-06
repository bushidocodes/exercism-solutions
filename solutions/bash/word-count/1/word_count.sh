#!/usr/bin/env bash

# Disable globbing and history expansion
# set -o noglob
# set +H

main() {
	if (($# != 1)); then
		printf "Unexpected number of arguments. Saw %d. Expected 1" "$#"
		exit 1
	fi

	# I had trouble evaluating and removing \n without interpreting it \ and n as delimiters
	# This solution forces the incoming string to evaluate \n into a newline, and then uses tr
	# to strip them out. There may be a cleaner way to do this with IFS
	IFS=$' ,'
	read -r -a words <<< "$(echo -e "$1" | tr -d '\n')"

	local -A word_count

	# Cast words to lower case
	local -l cleaned_word
	for word in "${words[@]}"; do

		# Strip punctuation other than single quotes used as apostrophes
		cleaned_word=${word//[!a-zA-Z0-9\']/}

		# Remove wrapping quotes
		# We need to set the shell to extended glob to turn ''''large'''' into large
		shopt -s extglob
		cleaned_word=${cleaned_word/#*(\')/}
		cleaned_word=${cleaned_word/%*(\')/}

		# Skip any empty strings
		if [[ -z "$cleaned_word" ]]; then
			continue
		fi

		if [[ ${word_count[$cleaned_word]+_} ]]; then
			# Note: Trying to use arithmetic expansion and the increment operator seems to fail because the key has an apostrophe
			# ((word_count["$cleaned_word"] += 1))
			# ./word_count.sh: line 28: ((: word_count[don't] += 1: bad array subscript (error token is "word_count[don't] += 1")
			# This is discussed further in https://unix.stackexchange.com/questions/627474/how-to-use-associative-arrays-safely-inside-arithmetic-expressions
			word_count["$cleaned_word"]=$((${word_count["$cleaned_word"]} + 1))
		else
			word_count+=(["$cleaned_word"]=1)
		fi
	done

	for key in "${!word_count[@]}"; do
		printf "%s: %d\n" "$key" "${word_count[$key]}"
	done

	return 0
}

main   "$@"
