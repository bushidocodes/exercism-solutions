use regex::Regex;

pub fn is_valid_isbn(isbn: &str) -> bool {
    let normal: Regex = Regex::new(r"^[0-9]$").unwrap();
    let check: Regex = Regex::new(r"^[0-9X]$").unwrap();
    let chars = isbn.chars().filter(|c| *c != '-').map(|c| c.to_string());

    // Validate Length
    if chars.clone().count() < 10 {
        return false;
    };
    // Validate Proper Characters
    if chars.clone().enumerate().any(|(i, c)| {
        if i < 9 {
            !normal.is_match(&c)
        } else if i == 9 {
            !check.is_match(&c)
        } else {
            false
        }
    }) {
        return false;
    }

    // Validate Checksum
    let checksum: i32 = chars
        .map(|c| {
            {
                if c == "X" {
                    "10".to_string()
                } else {
                    c
                }
            }
            .parse::<i32>()
            .unwrap()
        })
        .enumerate()
        .map(|(i, n)| (10 - i as i32) * n)
        .sum();

    checksum % 11 == 0
}
