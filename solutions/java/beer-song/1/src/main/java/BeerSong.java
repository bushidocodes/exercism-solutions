public class BeerSong {

    public String generateBottleString(int count) {
        return (count > 1) ? (count + " bottles") : (count + " bottle");
    }

    public String verse(int startCount) {

        if (startCount == 0) {
            return "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy "
                    + "some more, 99 bottles of beer on the wall.\n\n";
        } else if (startCount == 1) {
            return "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, "
                    + "no more bottles of beer on the wall.\n\n";
        } else {
            return generateBottleString(startCount) + " of beer on the wall, " + generateBottleString(startCount)
                    + " of beer.\n" + "Take one down and pass it around, " + generateBottleString(startCount - 1)
                    + " of beer on the wall.\n\n";
        }
    }

    public String sing(int startCount, int verseCount) {
        String result = "";
        for (int i = 0; i < verseCount; i++) {
            result = result.concat(verse(startCount - i));
        }
        return result;
    }

    public String singSong() {
        return sing(99, 100);
    }

}