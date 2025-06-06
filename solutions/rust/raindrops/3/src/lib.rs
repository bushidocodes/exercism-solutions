const FACTOR_SOUNDS: [(u32, &str); 3] = [(3, "Pling"), (5, "Plang"), (7, "Plong")];

pub fn raindrops(n: u32) -> String {
    let result: String = FACTOR_SOUNDS
        .iter()
        .fold(String::new(), |acc, (factor, sound)| {
            if n % factor == 0 {
                format!("{}{}", acc, sound)
            } else {
                acc
            }
        });

    if !result.is_empty() {
        result
    } else {
        n.to_string()
    }
}
