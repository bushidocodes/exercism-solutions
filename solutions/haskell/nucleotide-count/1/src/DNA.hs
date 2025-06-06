module DNA (nucleotideCounts, Nucleotide(..)) where

import Data.Map (Map, fromList, adjust)

data Nucleotide = A | C | G | T deriving (Eq, Ord, Read, Show)

validNucleotides c = c `elem` "ACGT"
emptyNucleotideCount = fromList [(A,0),(C,0),(G,0),(T,0)]

nucleotideCounts :: String -> Either String (Map Nucleotide Int)
nucleotideCounts nucleotidesStr =
  if all validNucleotides nucleotidesStr
    then do
      let nucleotides = Prelude.map (\x -> read [x]) nucleotidesStr :: [Nucleotide]
      Right (foldl (\acc e -> adjust (\v -> v + 1) e acc) emptyNucleotideCount nucleotides)
    else 
      Left "invalid char"
