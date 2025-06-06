#include "protein_translation.h"

#include <map>

namespace protein_translation
{
    const std::map<std::string, std::string> codon_to_protein = {
        {"AUG", "Methionine"},
        {"UUU", "Phenylalanine"},
        {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"},
        {"UUG", "Leucine"},
        {"UCU", "Serine"},
        {"UCC", "Serine"},
        {"UCA", "Serine"},
        {"UCG", "Serine"},
        {"UAU", "Tyrosine"},
        {"UAC", "Tyrosine"},
        {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"},
        {"UAA", "STOP"},
        {"UAG", "STOP"},
        {"UGA", "STOP"},
    };

    std::vector<std::string> proteins(const std::string &rna)
    {
        std::vector<std::string> proteins{};
        std::string codon_buffer = "";

        for (char c : rna)
        {
            codon_buffer.push_back(c);
            if (codon_buffer.length() < 3)
                continue;

            std::string protein = codon_to_protein.at(codon_buffer);
            codon_buffer.clear();

            if (protein == "STOP")
            {
                break;
            }
            else
            {
                proteins.push_back(protein);
            }
        }

        return proteins;
    }

} // namespace protein_translation
