use std::collections::HashSet;

fn get_sorted(word: &str) -> Vec<char> {
    let mut word_sorted: Vec<char> = word.chars().collect();
    word_sorted.sort_unstable();
    word_sorted
}

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &'a [&str]) -> HashSet<&'a str> {
    let word_lower = word.to_lowercase();
    let word_sorted = get_sorted(&word_lower);

    possible_anagrams
        .iter()
        .filter(|e| e.len() == word_lower.len())
        .filter(|e| {
            let e_lowercase = e.to_lowercase();
            e_lowercase != word_lower && get_sorted(&e_lowercase) == word_sorted
        })
        .copied()
        .collect()
}
