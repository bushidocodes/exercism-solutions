class LargestSeriesProductCalculator {
    String inputNumber;
    LargestSeriesProductCalculator(String inputNumber) {
        if (!inputNumber.chars().allMatch(c -> c >= '0' && c <= '9')) 
            throw new IllegalArgumentException("String to search may only contain digits.");
        
        this.inputNumber = inputNumber;
    }

    long calculateLargestProductForSeriesLength(int numberOfDigits) {
        if (numberOfDigits > this.inputNumber.length()) 
            throw new IllegalArgumentException("Series length must be less than or equal to the length of the string to search.");
        
        if (numberOfDigits < 0) throw new IllegalArgumentException("Series length must be non-negative.");
        
        if (numberOfDigits == 0 || this.inputNumber.length() == 0) return 1;
        
        long largestProduct = 0;
        for (int i = 0; i + numberOfDigits <= this.inputNumber.length(); i++){
            long currentProduct = 1;
            for (int j = i; j < i + numberOfDigits; j++){
                currentProduct *= Character.getNumericValue(this.inputNumber.charAt(j));
            }
            if (currentProduct > largestProduct) largestProduct = currentProduct;
        }

        return largestProduct;
    }
}
