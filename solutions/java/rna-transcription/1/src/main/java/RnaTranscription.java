import java.util.Arrays;
import java.util.HashMap;
import java.util.stream.Collectors;

class RnaTranscription {
    private static HashMap<String, String> dnaToRna;

    static {
        RnaTranscription.dnaToRna = new HashMap<String, String>();
        RnaTranscription.dnaToRna.put("C", "G");
        RnaTranscription.dnaToRna.put("G", "C");
        RnaTranscription.dnaToRna.put("T", "A");
        RnaTranscription.dnaToRna.put("A", "U");

    }

    String transcribe(String dnaStrand) {
        return Arrays.asList(dnaStrand.split("")).stream().map(e -> RnaTranscription.dnaToRna.get(e))
                .filter(e -> e != null).collect(Collectors.joining());

    }

}
