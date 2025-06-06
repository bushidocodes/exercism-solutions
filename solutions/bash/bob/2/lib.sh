#!/usr/bin/env bash

validate_parameter_count() {
	local -i expected_count="$1"
	local -a parameters=("${@:2}")
	local -i parameter_count="${#parameters[@]}"

	if ((parameter_count != expected_count)); then
		printf "%s requires %d parameters, but %s:%d provided %d.\n" \
			"${FUNCNAME[i + 1]}" \
			"$expected_count" \
			"${BASH_SOURCE[i + 1]}" \
			"${BASH_LINENO[i + 1]}" \
			"$parameter_count"
		exit 1
	fi
}

validate_parameter_count_between() {
	local -i expected_count_floor="$1"
	local -i expected_count_ceiling="$2"
	local -a parameters=("${@:3}")
	local -i parameter_count="${#parameters[@]}"

	if ((parameter_count < expected_count_floor || parameter_count > expected_count_ceiling)); then
		printf "%s requires between %d and %d parameters, but %s:%d provided %d.\n" \
			"${FUNCNAME[i + 1]}" \
			"$expected_count_floor" \
			"$expected_count_ceiling" \
			"${BASH_SOURCE[i + 1]}" \
			"${BASH_LINENO[i + 1]}" \
			"$parameter_count"
		exit 1
	fi
}
