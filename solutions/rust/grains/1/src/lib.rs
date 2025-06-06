const CHESSBOARD_SQUARE_MIN: u32 = 1;
const CHESSBOARD_SQUARE_MAX: u32 = 64;

pub fn square(s: u32) -> u64 {
    if s < CHESSBOARD_SQUARE_MIN || s > CHESSBOARD_SQUARE_MAX {
        panic!(
            "Square must be between {} and {}",
            CHESSBOARD_SQUARE_MIN, CHESSBOARD_SQUARE_MAX
        )
    };
    let base: u64 = 2;
    base.pow(s - 1)
}

pub fn total() -> u64 {
    (CHESSBOARD_SQUARE_MIN..=CHESSBOARD_SQUARE_MAX).fold(0, |acc, s| acc + square(s))
}
