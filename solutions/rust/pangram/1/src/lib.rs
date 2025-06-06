use std::collections::HashSet;

/// Determine whether a sentence is a pangram.
pub fn is_pangram(sentence: &str) -> bool {
    let mut letters = HashSet::new();

    // Convert word to lowercase and add each character to set
    sentence.to_lowercase().chars().for_each(|c| {letters.insert(c);});

    // Check that a..=z are all in set
    (b'a' ..= b'z').map(char::from).all(|c| letters.contains(&c))
}
