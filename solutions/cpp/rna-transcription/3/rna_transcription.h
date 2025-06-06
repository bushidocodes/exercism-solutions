#pragma once

#include <string>

namespace rna_transcription {
char to_rna(char cytidine);
std::string to_rna(std::string nucleotides);

}  // namespace rna_transcription
