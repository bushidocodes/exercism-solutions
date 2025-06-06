pub fn primes_up_to(upper_bound: u64) -> Vec<u64> {
    if upper_bound < 2 {return vec![]}

    let mut primes: Vec<u64> = vec![1; (upper_bound + 1) as usize];
    primes[0] = 0;
    primes[1] = 0;

    for i in 2..=upper_bound {
        if primes[i as usize] == 1 {
            for j in 2..=(upper_bound / i) {
                primes[(i * j) as usize] = 0;
            }
        }
    }

    primes.iter()
        .enumerate()
        .filter_map(|(i, e)| if *e == 1 {Some(i as u64)} else {None})
        .collect()
}
