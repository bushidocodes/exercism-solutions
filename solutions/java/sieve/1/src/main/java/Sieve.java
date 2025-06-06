import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

class Sieve {
    private int maxPrime;
    private List<Integer> result;
    private boolean didCompute;
    
    Sieve(int maxPrime) {
        this.maxPrime = maxPrime;
        this.result = new ArrayList();;
        this.didCompute = false;
    }

    List<Integer> getPrimes() {
        if (this.maxPrime < 2 || this.didCompute) return this.result;

        Set<Integer> primes = new HashSet();
        for (int i = 2; i <= this.maxPrime; i++) primes.add(i);

        for (int i = 2; i < this.maxPrime; i++) {
            if (primes.contains(i)) {
                for (int j = 2; i * j <= this.maxPrime; j++) primes.remove(i * j);
            }
        }

        for (int i : primes) this.result.add(i);
        
        return this.result;
    }
}
