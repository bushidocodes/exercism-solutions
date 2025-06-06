module ProteinTranslation(proteins) where

fromJust :: Maybe a -> a
fromJust Nothing = error "Maybe.fromJust: Nothing"
fromJust (Just x) = x

proteins :: String -> Maybe [String]
proteins [] = Just []
-- Stop Codons
proteins ('U':'A':'A':x) = Just []
proteins ('U':'A':'G':x) = Just []
proteins ('U':'G':'A':x) = Just []
-- Other Codons
proteins ('A':'U':'G':x) = Just ("Methionine" : fromJust(proteins x))
proteins ('U':'U':'U':x) = Just ("Phenylalanine" : fromJust(proteins x))
proteins ('U':'U':'C':x) = Just ("Phenylalanine" : fromJust(proteins x))
proteins ('U':'U':'A':x) = Just ("Leucine" : fromJust(proteins x))
proteins ('U':'U':'G':x) = Just ("Leucine" : fromJust(proteins x))
proteins ('U':'C':'U':x) = Just ("Serine" : fromJust(proteins x))
proteins ('U':'C':'C':x) = Just ("Serine" : fromJust(proteins x))
proteins ('U':'C':'A':x) = Just ("Serine" : fromJust(proteins x))
proteins ('U':'C':'G':x) = Just ("Serine" : fromJust(proteins x))
proteins ('U':'A':'U':x) = Just ("Tyrosine" : fromJust(proteins x))
proteins ('U':'A':'C':x) = Just ("Tyrosine" : fromJust(proteins x))
proteins ('U':'G':'U':x) = Just ("Cysteine" : fromJust(proteins x))
proteins ('U':'G':'C':x) = Just ("Cysteine" : fromJust(proteins x))
proteins ('U':'G':'G':x) = Just ("Tryptophan" : fromJust(proteins x))
proteins _ = Nothing