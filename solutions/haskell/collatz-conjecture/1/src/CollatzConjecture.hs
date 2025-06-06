module CollatzConjecture (collatz) where

fromJust :: Maybe a -> a
fromJust Nothing = error "Maybe.fromJust: Nothing"
fromJust (Just x) = x

collatz :: Integer -> Maybe Integer
collatz n
    | n <= 0 = Nothing
    | n == 1 = Just 0
    | even n = Just (1 + fromJust (collatz (n `div` 2)))
    | otherwise = Just (1 + fromJust (collatz (3 * n + 1)))



