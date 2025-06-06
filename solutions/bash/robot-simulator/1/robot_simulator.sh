#!/usr/bin/env bash

right() {
	local -n n_direction="$1"
	case "$n_direction" in
		north) n_direction="east" ;;
		east) n_direction="south" ;;
		south) n_direction="west" ;;
		west) n_direction="north" ;;
		*)
			echo "invalid direction"
			exit 1
			;;
	esac
}

left() {
	local -n n_direction="$1"
	case "$n_direction" in
		north) n_direction="west" ;;
		west) n_direction="south" ;;
		south) n_direction="east" ;;
		east) n_direction="north" ;;
		*)
			echo "invalid direction"
			exit 1
			;;
	esac
}

advance() {
	local -n n_direction="$1"
	local -n n_x="$2"
	local -n n_y="$3"
	case "$n_direction" in
		north) ((n_y++)) ;;
		west) ((n_x--)) ;;
		south) ((n_y--)) ;;
		east) ((n_x++)) ;;
		*)
			echo "invalid direction"
			exit 1
			;;
	esac
}

validate_direction() {
	local -n n_direction="$1"
	case "$n_direction" in
		north) ;;
		west) ;;
		south) ;;
		east) ;;
		*)
			echo "invalid direction"
			exit 1
			;;
	esac
}

main() {
	local -ir start_x="${1:-0}"
	local -ir start_y="${2:-0}"
	local -r start_direction="${3:-north}"
	local -r instructions="$4"

	validate_direction start_direction

	local -i x="$start_x"
	local -i y="$start_y"
	local direction="$start_direction"

	for ((i = 0; i < ${#instructions}; i++)); do
		case ${instructions:$i:1} in
			R) right direction ;;
			L) left direction ;;
			A) advance direction x y ;;
			*)
				echo "invalid instruction"
				exit 1
				;;
		esac
	done

	echo "$x $y $direction"
	return 0
}

main   "$@"
