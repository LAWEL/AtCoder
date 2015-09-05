import Data.Char

main :: IO ()
main = do
  s <- getLine
  print . foldr (+) 0 $ map digitToInt s
