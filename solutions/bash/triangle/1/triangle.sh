#!/usr/bin/env bash

equilateral() {
	if (("$#" != 3)); then
		printf "Incorrect number of arguments. Saw %d. Expected 3\n" "$#"
		return 1
	fi

	if [[ "$1" != "$2" || "$2" != "$3" ]]; then
		printf "false\n"
		return 0
	fi

	printf "true\n"
	return 0
}

isosceles() {
	if (("$#" != 3)); then
		printf "Incorrect number of arguments. Saw %d. Expected 3\n" "$#"
		return 1
	fi

	if [[ "$1" == "$2" || "$2" == "$3" || "$1" == "$3" ]]; then
		printf "true\n"
		return 0
	fi

	printf "false\n"
	return 0
}

scalene() {
	if (("$#" != 3)); then
		printf "Incorrect number of arguments. Saw %d. Expected 3\n" "$#"
		return 1
	fi

	if [[ "$1" == "$2" || "$2" == "$3" || "$1" == "$3" ]]; then
		printf "false\n"
		return 0
	fi

	printf "true\n"
	return 0
}

validate() {
	# Sort. The longest side is at index 2
	readarray -t sorted < <(echo "$@" | tr " " "\n" | sort)

	# Check for degenerate triangles
	if [[ $(echo "${sorted[0]} == 0 || ${sorted[1]} == 0 || ${sorted[2]} == 0" | bc) -eq 1 ]] \
		|| [[ $(echo "${sorted[0]} + ${sorted[1]} < ${sorted[2]}" | bc) -eq 1 ]]; then
		return 1
	fi

	return 0
}

main() {
	if (("$#" != 4)); then
		printf "Incorrect number of arguments. Saw %d. Expected 4\n" "$#"
		return 1
	elif [[ ! "$1" =~ ^(equilateral|isosceles|scalene)$ ]]; then
		printf "%s is not a known command. Expected equilateral, isosceles, or scalene\n" "$1"
		return 1
	fi

	validate "${@:2}" || {
		printf "false\n"
		exit 0
	}

	case "$1" in
		"equilateral")
			equilateral "${@:2}"
			;;
		"isosceles")
			isosceles "${@:2}"
			;;
		"scalene")
			scalene "${@:2}"
			;;
	esac
}

main "$@"
