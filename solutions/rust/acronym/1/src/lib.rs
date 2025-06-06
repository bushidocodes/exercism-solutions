pub fn abbreviate(phrase: &str) -> String {
    // Lookback and inject whitespace on camelCase
    let mut buffer: String = String::from("");
    let mut last: char = 'a';
    for (i, c) in phrase.chars().enumerate() {
        if c.is_ascii_uppercase() && i > 0 && last.is_ascii_lowercase() {
            buffer.push(' ');
        }
        buffer.push(c);
        last = c;
    }

    let res: String = buffer
        .split(|c: char| !c.is_alphabetic() && c != '\'')
        .filter(|word| word.len() > 0)
        .map(|word| word.get(..1).unwrap().to_uppercase())
        .collect();
    res
}
