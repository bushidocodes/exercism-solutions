#!/usr/bin/env bash
main() {
	local -a pig_latin=()

	for english in "$@"; do
		case "$english" in
			squ* | sch* | thr*)
				pig_latin+=("${english:3}${english:0:3}ay")
				;;
			ch* | th* | rh* | qu*)
				pig_latin+=("${english:2}${english:0:2}ay")
				;;
			[aeiou]* | equ* | yt* | xr*)
				pig_latin+=("${english}ay")
				;;
			*)
				pig_latin+=("${english:1}${english:0:1}ay")
				;;
		esac
	done

	echo "${pig_latin[*]}"
	return 0
}
main "$@"
