import java.util.*;

class BaseConverter {
    private int base;
    private int[] digits;

    public BaseConverter(int base, int[] digits){
        if (base < 2) throw new IllegalArgumentException("Bases must be at least 2.");

        for (int i = 0; i < digits.length; i++){
            if (digits[i] < 0 ) throw new IllegalArgumentException("Digits may not be negative.");
            if (digits[i] >= base) throw new IllegalArgumentException("All digits must be strictly less than the base.");
        }
        
        this.base = base;
        this.digits = digits;
    }

    public int[] convertToBase(int targetBase){
        if (targetBase < 2) throw new IllegalArgumentException("Bases must be at least 2.");
        
        int sum = 0;
        int digitsPlace = 0;
        for (int i = this.digits.length - 1; i >= 0; i--){
            sum += this.digits[i] * Math.pow(this.base, digitsPlace++);
        }
        
        if (sum == 0) return new int[]{0};
        
        ArrayList<Integer> results = new ArrayList<Integer>();
        while (sum > 0){
            results.add(0, sum % targetBase);
            sum /= targetBase;
        }
        
        return results.stream().mapToInt(i -> i).toArray();
    }
}