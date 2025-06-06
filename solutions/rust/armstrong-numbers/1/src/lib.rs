pub fn is_armstrong_number(num: u32) -> bool {
    let num_digits = num.to_string().chars().clone().count();
    let sum: u32 = num
        .to_string()
        .chars()
        .map(|char_digit| char_digit.to_digit(10).unwrap())
        .map(|digit| digit.pow(num_digits as u32))
        .sum();
    sum == num
}
