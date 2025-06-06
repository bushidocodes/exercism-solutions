use std::collections::HashMap;

pub fn brackets_are_balanced(string: &str) -> bool {
    // I seem to have to declare this in a function
    // Unclear how to do this as a constexpr equivalent
    // There also doesn't seem to be a hashmap equivalent to vec!
    // https://users.rust-lang.org/t/how-to-create-an-immutable-hash-map/34932
    let bracket_pairs: HashMap<char, char> = vec![('[', ']'), ('(', ')'), ('{', '}')]
        .into_iter()
        .collect();

    // There isn't a dedicated stack, but Vec offers push/pop
    let mut stack: Vec<char> = Vec::new();

    for c in string.chars() {
        match c {
            '[' | '(' | '{' => {
                stack.push(c);
            }
            ']' | ')' | '}' => {
                if let Some(top) = stack.pop() {
                    // Safe to unwrap because hashmap covers all cases of this arm
                    if bracket_pairs.get(&top).copied().unwrap() != c {
                        return false;
                    };
                } else {
                    return false;
                }
            }
            _ => continue,
        }
    }
    stack.is_empty()
}
