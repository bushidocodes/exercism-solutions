import java.util.regex.Matcher;
import java.util.regex.Pattern;

class SqueakyClean {
    static String clean(String identifier) {
        String result = identifier
            .replace(' ', '_')
            .replaceAll("\\p{Cntrl}", "CTRL")
            .replaceAll("[^\\p{L}_-]", "")
            .replaceAll("[α-ω]", "");

        var regex = "-\\p{javaLowerCase}";
        var pattern = Pattern.compile(regex);
        var matcher = pattern.matcher(result);
        StringBuilder sb = new StringBuilder(result);
        while (matcher.find()) {
            sb.setCharAt(matcher.start() + 1, Character.toUpperCase(sb.charAt(matcher.start() + 1)));
            sb.deleteCharAt(matcher.start());
        }

        return sb.toString();
    }
}
