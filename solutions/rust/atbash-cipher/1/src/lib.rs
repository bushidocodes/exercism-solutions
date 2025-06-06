/// "Encipher" with the Atbash cipher.
pub fn encode(plain: &str) -> String {
    plain.to_lowercase().chars()
        .filter(|c| c.is_ascii_alphanumeric())
        .map(|c| if c.is_ascii_alphabetic() {(('z' as u8) - ((c as u8) - ('a' as u8))) as char} else {c})
        .enumerate()
        .flat_map(|(i, c)| {
            // Should be replaced by intersperse once stable
            if i != 0 && i % 5 == 0 {
                Some(' ')
            } else {
                None
            }.into_iter()
            .chain(std::iter::once(c))
        }).collect()
}



/// "Decipher" with the Atbash cipher.
pub fn decode(cipher: &str) -> String {
    cipher.chars()
        .filter(|c| c.is_ascii_alphanumeric())
        .map(|c| if c.is_ascii_alphabetic() {(('z' as u8) - ((c as u8) - ('a' as u8))) as char} else {c})
        .collect()
}
