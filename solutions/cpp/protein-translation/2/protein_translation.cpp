#include "protein_translation.h"

#include <map>
#include <string_view>

namespace protein_translation
{
    const std::map<std::string_view, std::string_view> codon_to_protein = {
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
        std::string_view rna_view{rna};

        for (auto i = 0lu; i < rna_view.size(); i += 3) {
            std::string_view protein = codon_to_protein.at(rna_view.substr(i,3));
            if (protein == "STOP") break;
            else proteins.push_back(std::string{protein});
        }

        return proteins;
    }

} // namespace protein_translation
