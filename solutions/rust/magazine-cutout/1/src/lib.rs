use std::collections::HashMap;

pub fn can_construct_note(magazine: &[&str], note: &[&str]) -> bool {

    let mut magazine_words = HashMap::new();
    
    for word in magazine {
        if let Some(count) = magazine_words.get_mut(&word) {
            *count += 1;
        } else {
            magazine_words.insert(word, 1);
        }
    }

    for word in note {
        if let Some(count) = magazine_words.get_mut(&word) {
            if *count == 0 {
                return false;
            } else {
                *count -= 1;
            }
        } else {
            return false;
        }
    }

    return true;
}
