import java.util.Optional;

class Twofer {
    static String twofer(String name) {
        // Java does not support default parameters
        // String you = name != null ? name : "you";

        // Using java.util.Optional
        String you = Optional.ofNullable(name).orElse("you");
        
        return "One for " + you + ", one for me.";
    }
}
