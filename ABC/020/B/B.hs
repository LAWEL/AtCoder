main :: IO ()
main = do
  s <- getLine
  print . (*2) . read $ filter (/= ' ') s
