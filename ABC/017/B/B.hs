main :: IO ()
main = do
  s <- getLine
  putStrLn $ if solve $ reverse s then "YES" else "NO"

solve :: String -> Bool
solve (a:b:as)
  | a == 'o' = solve $ b:as
  | a == 'k' = solve $ b:as
  | a == 'u' = solve $ b:as
  | a == 'h' && b == 'c' = solve as
  | otherwise = False
solve (a:as)
  | a == 'o' = solve as
  | a == 'k' = solve as
  | a == 'u' = solve as
  | otherwise = False
solve [] = True
