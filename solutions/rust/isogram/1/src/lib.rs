use std::collections::HashSet;

pub fn check(candidate: &str) -> bool {
    candidate
        .to_lowercase()
        .chars()
        .filter(|e| e.is_ascii_alphabetic())
        .try_fold(HashSet::new(), |mut acc, e| if acc.insert(e) {Some(acc)} else {None})
        .is_some()
}
