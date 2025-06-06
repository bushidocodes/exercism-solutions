pub fn collatz(n: u64) -> Option<u64> {
    if (n < 1) {
        return None;
    }

    let mut steps: u64 = 0;
    
    let mut buffer: Option<u64> = Some(n);
    while buffer.is_some() && buffer.unwrap() > 1 {
        if buffer.unwrap() % 2 == 0 {
            buffer = buffer.unwrap().checked_div(2);
            steps += 1;
        } else {
            buffer = buffer.unwrap().checked_mul(3).and_then(|x| x.checked_add(1));
            steps += 1;
        }
    }

    if buffer.is_some() {
        Some(steps)
    } else {
        None
    }
}
