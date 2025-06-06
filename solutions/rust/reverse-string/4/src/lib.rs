use unicode_segmentation::UnicodeSegmentation;

pub fn reverse(input: &str) -> String {
    // Solution excluding graphemes
    // input.chars().rev().collect::<String>()

    // Solution including graphemes
    input.graphemes(true).rev().collect::<String>()
}
