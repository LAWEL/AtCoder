getInt :: IO Int
getInt = readLn

main :: IO ()
main = do
  n <- getInt
  s <- getLine
  print $ if s == (func $ n `div` 2) then (n - 1) `div` 2 else -1

func :: Int -> String
func n
  | n == 0 = "b"
  | n `mod` 3 == 0 = "b" ++ func (n - 1) ++ "b"
  | n `mod` 3 == 1 = "a" ++ func (n - 1) ++ "c"
  | n `mod` 3 == 2 = "c" ++ func (n - 1) ++ "a"
