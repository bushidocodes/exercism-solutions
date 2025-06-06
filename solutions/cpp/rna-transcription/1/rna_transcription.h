#pragma once

#include <string>

using namespace std;

namespace rna_transcription
{
    char to_rna(char cytidine);
    string to_rna(string nucleotides);

} // namespace rna_transcription
