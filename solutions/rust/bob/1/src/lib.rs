pub fn reply(message: &str) -> &str {
    // Handle silent messages
    if message.trim().is_empty() {
        return "Fine. Be that way!";
    }

    // iterator::all resolves to true if empty, so we need to explicitly check to know if yelling
    let has_letters = message.chars().filter(|char| char.is_alphabetic()).count() > 0;
    let is_yelling = has_letters
        && message
            .chars()
            .filter(|char| char.is_alphabetic())
            .all(|char| char.is_uppercase());

    let is_question = message.trim().ends_with('?');

    if is_question && !is_yelling {
        return "Sure.";
    } else if is_question && is_yelling {
        return "Calm down, I know what I'm doing!";
    } else if !is_question && is_yelling {
        return "Whoa, chill out!";
    } else {
        return "Whatever.";
    }
}
