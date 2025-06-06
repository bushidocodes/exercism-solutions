pub fn build_proverb(list: &[&str]) -> String {
    let mut result: String = list
        .windows(2)
        .map(|window| format!("For want of a {} the {} was lost.\n", window[0], window[1]))
        .collect();

    if !list.is_empty() {
        result.push_str(&format!("And all for the want of a {}.", list[0]));
    }
    result
}
