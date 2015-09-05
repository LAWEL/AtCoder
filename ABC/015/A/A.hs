main :: IO ()
main = do
  a <- getLine
  b <- getLine
  putStrLn $ if length a < length b then b else a
