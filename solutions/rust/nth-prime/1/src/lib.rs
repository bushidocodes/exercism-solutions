use std::collections::HashSet;

const PRIME_CEILING: u32  = 1_000_000;

pub fn nth(n: u32) -> u32 {
    let mut not_primes: HashSet<u32> = HashSet::new();
    let mut primes: Vec<u32> = Vec::new();
    
    not_primes.insert(0);
    not_primes.insert(1);

    let mut prime: Option<u32> = Some(2);
    
    while let Some(_prime) = prime {
        primes.push(_prime);

        if (n as usize) <= primes.len() - 1 {
            break;
        }
    
        for n in 2..=(PRIME_CEILING / _prime) {
            not_primes.insert(_prime * n);
        }

        for n in (_prime + 1)..=PRIME_CEILING {
            if !not_primes.contains(&n) {
                prime = Some(n);
                break;
            }
        }
        
        if prime == Some(_prime) {
            prime = None;
        }
    }

    primes[n as usize]
}
