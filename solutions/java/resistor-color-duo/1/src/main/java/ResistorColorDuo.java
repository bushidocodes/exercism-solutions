import java.util.HashMap;

class ResistorColorDuo {

    static final int MAX_COLOR_COUNT = 2;
    private static HashMap<String, Integer> colorValues;
    static {
        colorValues = new HashMap<String, Integer>();
        colorValues.put("black", 0);
        colorValues.put("brown", 1);
        colorValues.put("red", 2);
        colorValues.put("orange", 3);
        colorValues.put("yellow", 4);
        colorValues.put("green", 5);
        colorValues.put("blue", 6);
        colorValues.put("violet", 7);
        colorValues.put("grey", 8);
        colorValues.put("white", 9);
    }

    int value(String[] colors) {
        int result = 0;

        for (int i = 0; i < colors.length && i < MAX_COLOR_COUNT; i++) {
            if (!colorValues.containsKey(colors[i]))
                throw new IllegalArgumentException(colors[i] + "is not a valid color");

            // Add the color value
            result += colorValues.get(colors[i]);

            // If not the last color, shift the base-10 digits left
            if (i < colors.length - 1 && i < MAX_COLOR_COUNT - 1)
                result *= 10;
        }

        return result;
    }
}
