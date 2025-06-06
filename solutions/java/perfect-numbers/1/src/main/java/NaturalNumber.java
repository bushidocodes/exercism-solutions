import java.util.List;
import java.util.ArrayList;

class NaturalNumber {
    int number;
    
    public NaturalNumber(int number) {
        if (number < 1) throw new IllegalArgumentException("You must supply a natural number (positive integer)");
        
        this.number = number;
    }

    static int aliquotSum(int number){
        int sum = 0;
        
        for (int i = 1; i < number / i; i++){
            if (number % i == 0) {
                sum += i;
                int other = number / i;
                if (other != i) sum += other;
            } 
        }
        
        sum -= number;

        return sum;
    }

    public Classification getClassification(){
        int aliquotSum = this.aliquotSum(this.number);
        
        if (aliquotSum == this.number){
            return Classification.PERFECT;
        } else if (aliquotSum > this.number){
            return Classification.ABUNDANT;
        } else {
            return Classification.DEFICIENT;
        }
    }

    

    



}
