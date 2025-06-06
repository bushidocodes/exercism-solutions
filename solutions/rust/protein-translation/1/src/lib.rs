use std::marker::PhantomData;

pub struct CodonsInfo<'a> {
    // This field is here to make the template compile and not to
    // complain about unused type lifetime parameter "'a". Once you start
    // solving the exercise, delete this field and the 'std::marker::PhantomData'
    // import.
    phantom: PhantomData<&'a ()>,
}

impl<'a> CodonsInfo<'a> {
    pub fn name_for(&self, codon: &str) -> Option<&'a str> {
        match codon {
            "AGA" => Some("arginine"),
            "AGG" => Some("arginine"),
            "AUG" => Some("methionine"),
            "AUU" => Some("isoleucine"),
            "CGA" => Some("arginine"),
            "GUU" => Some("valine"),
            "UGU" => Some("cysteine"),
            "UAU" => Some("tyrosine"),
            "UGG" => Some("tryptophan"),
            "UUU" => Some("phenylalanine"),
            "UAA" => Some("stop codon"),
            _ => None
        }
    }

    pub fn of_rna(&self, rna: &str) -> Option<Vec<&'a str>> {
        let chars = rna.chars().collect::<Vec<char>>();

        // TODO: Validate that name_for isn't running for values after the stop codon
        let mut iter = chars.chunks(3)
            .map(|e| e.iter().collect::<String>())
            .map(|e| self.name_for(&e))
            .map_while(|e| if e != Some("stop codon") {Some(e)} else {None});

        if iter.clone().any(|e| e == None) {
            return None;
        }

        Some(iter
             .filter_map(|e| e)
             .collect::<Vec<&'a str>>())
    }
}

pub fn parse<'a>(_pairs: Vec<(&'a str, &'a str)>) -> CodonsInfo<'a> {
    CodonsInfo{phantom: PhantomData{}}
}
