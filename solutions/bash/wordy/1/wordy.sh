#!/usr/bin/env bash

regex="(What is)?\s*(-?[0-9]+)?\s*(plus|minus|multiplied by|divided by)?\s*(-?[0-9]+)?\s*(plus|minus|multiplied by|divided by)?\s*(-?[0-9]+)?\?$"

declare -A string_to_symbol=(
	["plus"]="+"
	["minus"]="-"
	["multiplied by"]="*"
	["divided by"]="/"
	["divided by"]="/"
)

main() {
	local sentence="$1"

	if [[ $sentence =~ $regex ]]; then
		local question_words=${BASH_REMATCH[1]}
		local number1=${BASH_REMATCH[2]}
		local operation1=${BASH_REMATCH[3]}
		local number2=${BASH_REMATCH[4]}
		local operation2=${BASH_REMATCH[5]}
		local number3=${BASH_REMATCH[6]}

		# Check that game starts with "What is"
		if [[ "$question_words" != "What is" ]]; then
			echo "unknown operation"
			return 1
		fi

		# Validate contiguous tokens
		local -i last_non_empty=0
		for ((i = 1; i <= "${#BASH_REMATCH[@]}"; i++)); do
			if [[ -n "${BASH_REMATCH[$i]}" ]]; then
				if ((i - 1 != last_non_empty)); then
					echo "syntax error"
					return 1
				fi
				((last_non_empty++))
			fi
		done

		# Match against valid formats
		case $last_non_empty in
			2)
				printf "%d\n" "$number1"
				return 0
				;;
			4)
				echo "$number1 ${string_to_symbol[$operation1]} $number2" | bc
				return 0
				;;
			6)
				# Use paranthesis to get strict left to right syntax
				echo "($number1 ${string_to_symbol[$operation1]} $number2) ${string_to_symbol[$operation2]} $number3" | bc
				return 0
				;;
			*)
				echo "syntax error"
				return 1
				;;
		esac

	else
		echo "syntax error"
		return 1
	fi
}

main    "$@"
