#!/usr/bin/env bash

codon_to_protein() {
	local -r codon="$1"
	local -n __protein="$2"
	case $1 in
		AUG) __protein="Methionine" ;;
		UUU | UUC) __protein="Phenylalanine" ;;
		UUA | UUG) __protein="Leucine" ;;
		UCU | UCC | UCA | UCG) __protein="Serine" ;;
		UAU | UAC) __protein="Tyrosine" ;;
		UGU | UGC) __protein="Cysteine" ;;
		UGG) __protein="Tryptophan" ;;
		UAA | UAG | UGA) __protein="STOP" ;;
		*) return 1 ;;
	esac
	return 0
}

main() {
	local -r rna="$1"
	local -u codon=""
	local protein=""
	local result=""
	for ((i = 0; i < ${#rna}; i += 3)); do
		codon="${rna:i:3}"
		codon_to_protein "$codon" protein || {
			printf "Invalid codon\n"
			return 1
		}

		[[ "$protein" == "STOP" ]] && break

		((i > 0)) && result+=" "
		result+="$protein"
	done

	printf "%s\n" "$result"
	return 0
}

main "$@"
