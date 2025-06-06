use std::collections::HashMap;

const VALID_NUCLEOTIDES: [char; 4] = ['A', 'C', 'G', 'T'];

pub fn count(nucleotide: char, dna: &str) -> Result<usize, char> {
    if !VALID_NUCLEOTIDES.contains(&nucleotide) {
        return Err(nucleotide);
    };

    dna.chars().try_fold(0, |acc, elem| -> Result<usize, char> {
        if !VALID_NUCLEOTIDES.contains(&elem) {
            return Err(elem);
        }
        if elem == nucleotide {
            Ok(acc + 1)
        } else {
            Ok(acc)
        }
    })
}

pub fn nucleotide_counts(dna: &str) -> Result<HashMap<char, usize>, char> {
    let mut counts: HashMap<char, usize> = VALID_NUCLEOTIDES
        .to_vec()
        .into_iter()
        .map(|e| (e, 0))
        .collect();

    for c in dna.chars() {
        if !VALID_NUCLEOTIDES.contains(&c) {
            return Err(c);
        }

        if let Some(count) = counts.get_mut(&c) {
            *count += 1;
        }
    }

    Ok(counts)
}
