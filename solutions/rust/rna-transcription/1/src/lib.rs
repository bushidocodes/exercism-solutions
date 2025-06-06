use std::collections::HashMap;

#[derive(Debug, PartialEq)]
pub struct Dna {
    _data: String,
}

#[derive(Debug, PartialEq)]
pub struct Rna {
    _data: String,
}

const VALID_NUCLEOTIDES: [char; 4] = ['A', 'C', 'G', 'T'];
const VALID_COMPLEMENTS: [char; 4] = ['U', 'G', 'C', 'A'];

impl Dna {
    pub fn new(dna: &str) -> Result<Dna, usize> {
        // Validate Nucleotides
        for (i, c) in dna.chars().enumerate() {
            if !VALID_NUCLEOTIDES.contains(&c) {
                return Err(i);
            }
        }
        Ok(Dna {
            _data: dna.to_owned(),
        })
    }

    pub fn into_rna(self) -> Rna {
        let map: HashMap<&char, &char> = VALID_NUCLEOTIDES
            .iter()
            .zip(VALID_COMPLEMENTS.iter())
            .collect();

        Rna {
            _data: self
                ._data
                .chars()
                .map(|c| map.get(&c).unwrap())
                .copied()
                .collect(),
        }
    }
}

impl Rna {
    pub fn new(rna: &str) -> Result<Rna, usize> {
        // Validate Nucleotides
        for (i, c) in rna.chars().enumerate() {
            if !VALID_COMPLEMENTS.contains(&c) {
                return Err(i);
            }
        }
        Ok(Rna {
            _data: rna.to_owned(),
        })
    }
}
