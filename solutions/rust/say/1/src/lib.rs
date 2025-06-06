pub fn encode(n: u64) -> String {
    let mut buffer = String::new();
    if n == 0 {
        buffer.push_str("zero");
        return buffer;
    }

    // Cases can be recursively calculated and appended because >=100 is regular
    let mut remaining = n;
    let places: Vec<(u64, &str)> = vec![
        (1_000_000_000_000_000_000, "quintillion"),
        (1_000_000_000_000_000, "quadrillion"),
        (1_000_000_000_000, "trillion"),
        (1_000_000_000, "billion"),
        (1_000_000, "million"),
        (1_000, "thousand"),
        (100, "hundred"),
    ];

    for (digit, word) in places {
        if remaining >= digit {
            buffer.push_str(&encode(remaining / digit));
            buffer.push(' ');
            buffer.push_str(word);
            remaining %= digit;
            if remaining > 0 {
                buffer.push(' ');
            }
        }
    }

    // Base Case: Less than 100, when rules are irregular
    let fragments: Vec<(u64, &str)> = vec![
        (90, "ninety"),
        (80, "eighty"),
        (70, "seventy"),
        (60, "sixty"),
        (50, "fifty"),
        (40, "forty"),
        (30, "thirty"),
        (20, "twenty"),
        (19, "nineteen"),
        (18, "eighteen"),
        (17, "seventeen"),
        (16, "sixteen"),
        (15, "fifteen"),
        (14, "fourteen"),
        (13, "thirteen"),
        (12, "twelve"),
        (11, "eleven"),
        (10, "ten"),
        (9, "nine"),
        (8, "eight"),
        (7, "seven"),
        (6, "six"),
        (5, "five"),
        (4, "four"),
        (3, "three"),
        (2, "two"),
        (1, "one"),
    ];

    while remaining > 0 {
        for (digit, word) in &fragments {
            if remaining >= *digit {
                buffer.push_str(word);
                remaining -= digit;
                if remaining > 0 {
                    buffer.push('-')
                } else {
                    break;
                }
            }
        }
    }

    buffer
}
