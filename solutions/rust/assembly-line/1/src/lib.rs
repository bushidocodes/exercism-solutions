pub fn production_rate_per_hour(speed: u8) -> f64 {
    let success_rate: f64 = match speed {
        1..=4 => 1.0,
        5..=8 => 0.90,
        9 | 10 => 0.77,
        _ => 0.0
    };
    
    221.0 * success_rate * speed as f64
}

pub fn working_items_per_minute(speed: u8) -> u32 {
    (production_rate_per_hour(speed) / 60 as f64) as u32
}
