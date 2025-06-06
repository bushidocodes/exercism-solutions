#!/usr/bin/env bash

# Because the scores are power of 2, we can use scores and masks in bitwise operations
declare -rA allergen_scores=(
	[eggs]=1
	[peanuts]=2
	[shellfish]=4
	[strawberries]=8
	[tomatoes]=16
	[chocolate]=32
	[pollen]=64
	[cats]=128
)

# Keys are unordered in associative arrays, so we need an additional structure
# to explicitly force us to iterate in the order the tests expect
declare -ra allergen_scores_ordered_keys=(
	eggs
	peanuts
	shellfish
	strawberries
	tomatoes
	chocolate
	pollen
	cats
)

is_allergic_to() {
	(($# != 2)) && panic "Invalid Arg Count. Saw $#. Expected 2"
	local -i allergy_score="$1"
	local allergen="$2"
	(((allergy_score & allergen_scores[$allergen]) != 0))
}

get_allergies() {
	(($# != 2)) && panic "Invalid Arg Count. Saw $#. Expected 2"
	local -i allergy_score="$1"
	local -n __alergen_array="$2"

	for allergen in "${allergen_scores_ordered_keys[@]}"; do
		is_allergic_to "$allergy_score" "$allergen" && __alergen_array+=("$allergen")
	done
}

main() {
	(($# < 2 || $# > 3)) && panic "Invalid Arg Count. Saw $#. Expected 2 or 3"
	local -i allergy_score="$1"
	local command="$2"

	case "$command" in
		allergic_to)
			if is_allergic_to "$allergy_score" "$3"; then
				echo "true"
			else
				echo "false"
			fi
			;;
		list)
			local -a allergies=()
			get_allergies "$allergy_score" allergies
			echo "${allergies[*]}"
			;;
	esac

	return 0
}

main "$@"
