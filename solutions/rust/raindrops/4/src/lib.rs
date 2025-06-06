const FACTOR_SOUNDS: [(u32, &str); 3] = [(3, "Pling"), (5, "Plang"), (7, "Plong")];

pub fn raindrops(n: u32) -> String {
    let mut result: String = String::new();

    for (factor, sound) in &FACTOR_SOUNDS {
        if n % factor == 0 {
            result.push_str(sound)
        }
    }
    if result.is_empty() {
        result = n.to_string();
    }
    result
}
