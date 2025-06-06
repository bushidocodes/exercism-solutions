module DNA (toRNA) where

import Data.Either
import Data.Maybe
import Data.List

complement 'G' = 'C'
complement 'C' = 'G'
complement 'T' = 'A'
complement 'A' = 'U'
complement x   = error "Should be unreachable"

toRNA x = do
  let firstInvalid = find (\c -> (elem c "GCTA") == False) x
  if isJust firstInvalid then Left (fromJust firstInvalid) else Right (map complement x)
