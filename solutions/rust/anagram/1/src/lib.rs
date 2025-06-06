use std::collections::{HashMap, HashSet};

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &'a [&str]) -> HashSet<&'a str> {
    let mut anagrams: HashSet<&'a str> = HashSet::new();

    let word_chars =
        word.to_lowercase()
            .chars()
            .fold(HashMap::<char, u32>::new(), |mut acc, val| {
                *acc.entry(val).or_insert(0) += 1;
                acc
            });

    for possible_anagram in possible_anagrams {
        if word.to_lowercase() == *possible_anagram.to_lowercase() {
            continue;
        }

        let candidate_chars = possible_anagram.to_lowercase().chars().fold(
            HashMap::<char, u32>::new(),
            |mut acc, val| {
                *acc.entry(val).or_insert(0) += 1;
                acc
            },
        );

        if candidate_chars == word_chars {
            anagrams.insert(possible_anagram);
        }
    }

    anagrams
}
