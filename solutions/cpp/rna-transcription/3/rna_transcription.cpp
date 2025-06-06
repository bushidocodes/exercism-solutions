#include "rna_transcription.h"

#include <map>

namespace rna_transcription {
std::map<char, char> transcription_pairs = {
    {'C', 'G'}, {'G', 'C'}, {'A', 'U'}, {'T', 'A'}};

void validate_dna_nucleotide(char nucleotide) {
	if (nucleotide != 'A' && nucleotide != 'C' && nucleotide != 'G' &&
	    nucleotide != 'T') {
		throw std::invalid_argument{"Character is not a valid nucleotide"};
	};
}

char to_rna(char nucleotide) {
	validate_dna_nucleotide(nucleotide);
	return transcription_pairs.at(nucleotide);
}

std::string to_rna(std::string dna) {
	std::string rna = "";
	for (char nucleotide : dna) {
		rna += to_rna(nucleotide);
	}

	return rna;
}

}  // namespace rna_transcription
