#[derive(Debug, PartialEq)]
pub enum Error {
    InvalidInputBase,
    InvalidOutputBase,
    InvalidDigit(u32),
}

pub fn convert(number: &[u32], from_base: u32, to_base: u32) -> Result<Vec<u32>, Error> {
    if to_base < 2 {
        return Err(Error::InvalidOutputBase);
    }
    
    if from_base < 2 {
        return Err(Error::InvalidInputBase);
    }

    let mut sumBase10: u32 = 0;
    for (i, digit) in number.iter().rev().enumerate() {
        if *digit >= from_base {return Err(Error::InvalidDigit(*digit));}
        sumBase10 += digit * from_base.pow(i as u32);
    }

    let mut result: Vec<u32> = vec![];
    while sumBase10 > 0 {
        result.insert(0, sumBase10 % to_base);
        sumBase10 /= to_base;
    }

    if result.len() == 0 {
        result.push(0);
    }

    Ok(result)
}
