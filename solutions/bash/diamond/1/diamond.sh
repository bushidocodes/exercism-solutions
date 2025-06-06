#!/usr/bin/env bash

source "ascii.sh"

main() {
	local -r last="$1"
	local -r last_code=$(ord "$last")
	local -r first="A"
	local -r first_code=$(ord "$first")

	# Validate arg is single char from A-Z
	((${#last} != 1)) && exit 1
	((last_code < first_code)) && exit 1
	((last_code > $(ord "Z"))) && exit 1

	local current_letter
	for ((c = first_code; c <= last_code; c++)); do
		current_letter="$(chr "$c")"
		for ((i = 0; i < last_code - c; i++)); do echo -n " "; done
		echo -n "$current_letter"
		if ((c > first_code)); then
			for ((i = 0; i < 2 * (c - first_code) - 1; i++)); do echo -n " "; done
			echo -n "$current_letter"
		fi
		for ((i = 0; i < last_code - c; i++)); do echo -n " "; done
		echo ""
	done

	if ((last_code > first_code)); then
		for ((c = last_code - 1; c >= first_code; c--)); do
			for ((i = 0; i < last_code - c; i++)); do echo -n " "; done
			current_letter="$(chr "$c")"
			echo -n "$current_letter"
			if ((c > first_code)); then
				for ((i = 0; i < 2 * (c - first_code) - 1; i++)); do echo -n " "; done
				echo -n "$current_letter"
			fi
			for ((i = 0; i < last_code - c; i++)); do echo -n " "; done
			echo ""
		done
	fi

}

main "$@"
