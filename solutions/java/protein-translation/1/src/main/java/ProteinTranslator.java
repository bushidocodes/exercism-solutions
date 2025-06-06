import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.stream.Collectors;

class ProteinTranslator {
    private static HashMap<String, String> codonToAminoAcid;

    static {
        codonToAminoAcid = new HashMap<String, String>();
        codonToAminoAcid.put("AUG", "Methionine");
        codonToAminoAcid.put("UUU", "Phenylalanine");
        codonToAminoAcid.put("UUC", "Phenylalanine");
        codonToAminoAcid.put("UUA", "Leucine");
        codonToAminoAcid.put("UUG", "Leucine");
        codonToAminoAcid.put("UCU", "Serine");
        codonToAminoAcid.put("UCC", "Serine");
        codonToAminoAcid.put("UCA", "Serine");
        codonToAminoAcid.put("UCG", "Serine");
        codonToAminoAcid.put("UAU", "Tyrosine");
        codonToAminoAcid.put("UAC", "Tyrosine");
        codonToAminoAcid.put("UGU", "Cysteine");
        codonToAminoAcid.put("UGC", "Cysteine");
        codonToAminoAcid.put("UGG", "Tryptophan");
        codonToAminoAcid.put("UAA", "STOP");
        codonToAminoAcid.put("UAG", "STOP");
        codonToAminoAcid.put("UGA", "STOP");
    }

    ArrayList<String> translate(String rnaSequence) {
        ArrayList<String> polypeptide = new ArrayList<String>();
        char[] codon = new char[3];
        String outputBuffer = new String();

        ArrayList<Character> rnaSequenceAsChars = rnaSequence.chars().mapToObj(e -> (char) e)
                .collect(Collectors.toCollection(ArrayList::new));

        while (rnaSequenceAsChars.size() > 0) {

            codon[0] = rnaSequenceAsChars.remove(0);
            codon[1] = rnaSequenceAsChars.remove(0);
            codon[2] = rnaSequenceAsChars.remove(0);

            outputBuffer = ProteinTranslator.codonToAminoAcid.get(String.valueOf(codon));

            if (outputBuffer == "STOP")
                break;

            if (outputBuffer != null) {
                polypeptide.add(outputBuffer);
            }

        }

        return polypeptide;
    }
}