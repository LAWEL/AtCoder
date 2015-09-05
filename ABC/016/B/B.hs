import Control.Applicative

main :: IO ()
main = do
  [a,b,c] <- map (read :: String -> Int).words <$> getLine
  putStrLn $ solve a b c

solve :: Int -> Int -> Int -> String
solve a b c
  | a + b == c && a - b == c = "?"
  | a + b == c = "+"
  | a - b == c = "-"
  | otherwise = "!"
