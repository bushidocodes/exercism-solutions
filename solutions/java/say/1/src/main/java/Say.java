public class Say {

    public String subTwenty(long number){
        if (number == 19) return "nineteen";
        else if (number == 18) return "eighteen";
        else if (number == 17) return "seventeen";
        else if (number == 16) return "sixteen";
        else if (number == 15) return "fifteen";
        else if (number == 14) return "fourteen";
        else if (number == 13) return "thirteen";
        else if (number == 12) return "twelve";
        else if (number == 11) return "eleven";
        else if (number == 10) return "ten";
        else if (number == 9) return "nine";
        else if (number == 8) return "eight";
        else if (number == 7) return "seven";
        else if (number == 6) return "six";
        else if (number == 5) return "five";
        else if (number == 4) return "four";
        else if (number == 3) return "three";
        else if (number == 2) return "two";
        else if (number == 1) return "one";
        return "";
    }

    public String subThousand(long number){
        String result = "";
        if (number < 1_000L && number >= 100L) {
            long hundreds = number / 100L;
            result += subTwenty(hundreds) + " hundred";
            number = number % 100L;

            if (number > 0L) result += " ";
        } 
        
        if (number < 100L && number >= 20L) {
            long tens = number / 10L;
            
            if (tens == 9L) result += "ninty";
            if (tens == 8L) result += "eighty";
            if (tens == 7L) result += "seventy";
            if (tens == 6L) result += "sixty";
            if (tens == 5L) result += "fifty";
            if (tens == 4L) result += "forty";
            if (tens == 3L) result += "thirty";
            if (tens == 2L) result += "twenty";

            number = number % 10L;

            if (number > 0L) result += "-";
        }
        
        if (number <= 20L){
            result += subTwenty(number);
            number = 0L;
        }

        return result;
    }

    public String say(long number) {
        if (number < 0L) throw new java.lang.IllegalArgumentException();
        if (number >= 1_000_000_000_000L) throw new java.lang.IllegalArgumentException();
        
        if (number == 0L) return "zero";

        String result = "";

        if (number >= 1_000_000_000L) {
            long billions = number / 1_000_000_000L;
            result += subThousand(billions) + " billion";
            number %= 1_000_000_000L;
            if (number > 0L) result += " ";
        }
        
        if (number >= 1_000_000L) {
            long millions = number / 1_000_000L;
            result += subThousand(millions) + " million";
            number %= 1_000_000L;
            if (number > 0L) result += " ";
        }

        if (number >= 1_000L) {
            long thousands = number / 1_000L;
            result += subThousand(thousands) + " thousand";
            number %= 1_000L;
            if (number > 0L) result += " ";
        }  

        if (number > 0L){
            result += subThousand(number);
            number = 0L;
        }

        return result;
    }
}
