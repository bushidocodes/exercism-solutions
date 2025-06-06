#!/usr/bin/env bash

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

is_allergic_to() {
	local -i allergy_score="$1"
	local allergen="$2"
	(((allergy_score & allergen_scores[$allergen]) != 0))
}

get_allergies() {
	local -i allergy_score="$1"
	local -n __alergen_array="$2"

	for allergen in "${allergen_scores_ordered_keys[@]}"; do
		is_allergic_to "$allergy_score" "$allergen" && __alergen_array+=("$allergen")
	done
}

main() {
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
