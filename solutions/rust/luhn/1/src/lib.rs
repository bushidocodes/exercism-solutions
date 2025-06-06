/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    let code_no_whitespace: String = code.chars()
        .filter(|c| !c.is_whitespace())
        .collect();
    
    if code_no_whitespace.len() < 2 || code_no_whitespace.chars().any(|c| !c.is_digit(10)) {
        return false;
    };
    
    let checksum: u32 = code_no_whitespace.chars()
        .filter_map(|c| c.to_digit(10))
        .rev()
        .enumerate()
        .map(|(i, c)| if i % 2 == 1 {2 * c} else {c})
        .map(|c| if c > 9 {c - 9} else {c})
        .sum();

    checksum % 10 == 0
}
