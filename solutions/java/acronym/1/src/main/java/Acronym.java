import java.util.Arrays;
import java.util.stream.Collectors;

class Acronym {
    String phrase;
    String acronym;

    Acronym(String phrase) {
        this.phrase = phrase;

        this.acronym = String.join("",
                Arrays.asList(phrase.split("[- ]")).stream().map(str -> str.replaceAll("[^a-zA-Z]", ""))
                        .filter(str -> !str.isEmpty()).map(str -> str.substring(0, 1).toUpperCase())
                        .collect(Collectors.toList()));
    }

    String get() {
        return this.acronym;
    }

}
