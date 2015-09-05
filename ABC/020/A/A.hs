getInt :: IO Int
getInt = readLn

main :: IO ()
main = do
  q <- getInt
  putStrLn $ if q == 1 then "ABC" else "chokudai"
