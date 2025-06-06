pub fn build_proverb(list: &[&str]) -> String {
    let mut result: String = String::from("");
    for (i, item) in list.iter().enumerate() {
        if i != list.len() - 1 {
            result.push_str(&format!(
                "For want of a {} the {} was lost.\n",
                item,
                list[i + 1]
            ));
        }
    }
    if !list.is_empty() {
        result.push_str(&format!("And all for the want of a {}.", list[0]));
    }
    result
}
