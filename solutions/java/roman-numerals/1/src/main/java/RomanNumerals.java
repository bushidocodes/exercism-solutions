class RomanNumeral {
    private String numeral = "";

    RomanNumeral(int arabicNumber) {

        while (arabicNumber >= 1_000) {
            numeral = numeral.concat("M");
            arabicNumber -= 1_000;
        }

        if (arabicNumber >= 900) {
            numeral = numeral.concat("CM");
            arabicNumber -= 900;
        } else if (arabicNumber >= 500) {
            numeral = numeral.concat("D");
            arabicNumber -= 500;
        } else if (arabicNumber >= 400) {
            numeral = numeral.concat("CD");
            arabicNumber -= 400;
        }

        while (arabicNumber >= 100) {
            numeral = numeral.concat("C");
            arabicNumber -= 100;
        }

        if (arabicNumber >= 90) {
            numeral = numeral.concat("XC");
            arabicNumber -= 90;
        } else if (arabicNumber >= 50) {
            numeral = numeral.concat("L");
            arabicNumber -= 50;
        } else if (arabicNumber >= 40) {
            numeral = numeral.concat("XL");
            arabicNumber -= 40;
        }

        while (arabicNumber >= 10) {
            numeral = numeral.concat("X");
            arabicNumber -= 10;
        }

        if (arabicNumber == 9) {
            numeral = numeral.concat("IX");
            arabicNumber -= 9;
        } else if (arabicNumber >= 5) {
            numeral = numeral.concat("V");
            arabicNumber -= 5;
        } else if (arabicNumber == 4) {
            numeral = numeral.concat("IV");
            arabicNumber -= 4;
        }

        while (arabicNumber > 0) {
            numeral = numeral.concat("I");
            arabicNumber--;
        }
    }

    public String getRomanNumeral() {
        return this.numeral;
    }
}