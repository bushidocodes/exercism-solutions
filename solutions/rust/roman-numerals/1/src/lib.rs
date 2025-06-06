use std::fmt::{Display, Formatter, Result};

const arabicRomans: [(&str, u32); 13] = [
    ("M", 1000),
    ("CM", 900),
    ("D", 500),
    ("CD", 400),
    ("C", 100),
    ("XC", 90),
    ("L", 50),
    ("XL", 40),
    ("X", 10),
    ("IX", 9),
    ("V", 5),
    ("IV", 4),
    ("I", 1),
];

pub struct Roman{
    value: String
}

impl Display for Roman {
    fn fmt(&self, _f: &mut Formatter<'_>) -> Result {
        write!(_f, "{}", self.value)
    }
}

impl From<u32> for Roman {
    fn from(num: u32) -> Self {
        let mut buffer = num;
        let mut result: Vec<&str> = vec![];
        for (roman, arabic) in arabicRomans {
            while buffer >= arabic {
                result.push(roman);
                buffer -= arabic;
            }
        }

        Roman{value: result.join("")}
    }
}
