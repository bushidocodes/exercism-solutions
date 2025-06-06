class Proverb {
    private String text = "";

    Proverb(String[] words) {

        for (int i = 0; i < words.length; i++) {
            if (i == words.length - 1) {
                this.text = this.text.concat("And all for the want of a " + words[0] + ".");
            } else {
                this.text = this.text.concat("For want of a " + words[i] + " the " + words[i + 1] + " was lost.\n");
            }
        }

    }

    String recite() {
        return this.text;
    }

}
