class Twofer {
    String twofer(String name) {
        String you = name != null && !name.isEmpty() ? name : "you";
        return "One for " + you + ", one for me.";
    }
}
