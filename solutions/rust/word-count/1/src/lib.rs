use std::collections::HashMap;

/// Count occurrences of words.

pub fn remote_wrapping_single_quotes(word: &str) -> &str {
    if word.chars().nth(0) == Some('\'') && word.chars().nth(word.len() - 1) == Some('\'') {
        word.get(1..word.len()-1).unwrap()
    } else {
        word
    }
}

pub fn increment_word_count<'a> (mut map: HashMap::<String, u32>, word: &'a str) -> HashMap::<String, u32> {
    if let Some(count) = map.get_mut(word) {
        *count += 1;
        map
    } else {
        map.insert(word.to_string(), 1);
        map
    }
}

pub fn word_count(words: &str) -> HashMap<String, u32> {
    words
        .to_lowercase()
        .split(|c: char| c != '\'' && !c.is_ascii_alphanumeric())
        .map(|word| word.trim())
        .map(remote_wrapping_single_quotes)
        .filter(|word| word.len() > 0)
        .fold(HashMap::<String, u32>::new(), increment_word_count)
}
