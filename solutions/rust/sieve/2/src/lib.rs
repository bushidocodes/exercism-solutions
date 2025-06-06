pub fn primes_up_to(upper_bound: u64) -> Vec<u64> {
    if upper_bound < 2 {return vec![]}

    let mut primes: Vec<bool> = vec![true; (upper_bound + 1) as usize];
    primes[0] = false;
    primes[1] = false;

    for i in 2..=upper_bound {
        if primes[i as usize] == true {
            for j in 2..=(upper_bound / i) {
                primes[(i * j) as usize] = false;
            }
        }
    }

    primes.iter()
        .enumerate()
        .filter_map(|(i, e)| if *e == true {Some(i as u64)} else {None})
        .collect()
}
