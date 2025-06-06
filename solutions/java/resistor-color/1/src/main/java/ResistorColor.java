import java.util.Arrays;
import java.util.List;

class ResistorColor {
    private List<String> colors;

    ResistorColor() {
        this.colors = Arrays.asList("black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey",
                "white");
    }

    int colorCode(final String color) {
        if (!this.colors.contains(color))
            throw new IllegalArgumentException();
        return this.colors.indexOf(color);
    }

    String[] colors() {
        return this.colors.stream().toArray(String[]::new);
    }
}
