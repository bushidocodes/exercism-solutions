pub fn square_of_sum(n: u32) -> u32 {
    (1..=n).fold(0, |acc, elem| acc + elem).pow(2)
}

pub fn sum_of_squares(n: u32) -> u32 {
    (1..=n)
        .map(|elem| elem.pow(2))
        .fold(0, |acc, elem| acc + elem)
}

pub fn difference(n: u32) -> u32 {
    square_of_sum(n) - sum_of_squares(n)
}
