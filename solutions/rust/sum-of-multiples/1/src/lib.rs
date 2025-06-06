pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
    let non_zero_factors: Vec<&u32> = factors.iter().filter(|factor| **factor != 0).collect();

    (1..limit)
        .filter(|elem| non_zero_factors.iter().any(|factor| elem % *factor == 0))
        .fold(0, |acc, elem| acc + elem)
}
