#include <map>

#include "rna_transcription.h"

using namespace std;

namespace rna_transcription
{
    map<char, char> transcription_pairs = {{'C', 'G'}, {'G', 'C'}, {'A', 'U'}, {'T', 'A'}};

    char to_rna(char cytidine)
    {
        return transcription_pairs.at(cytidine);
    };

    string to_rna(string nucleotides)
    {
        string complement = "";
        for (char nucleotide : nucleotides)
        {
            complement += to_rna(nucleotide);
        }

        return complement;
    }

} // namespace rna_transcription
