import Text.Printf

main :: IO ()
main = readLn >>= (\m -> putStrLn $ f m)

f :: Int -> String
f m
  | m < 100 = "00"
  | m <= 5000 = printf "%02d" $ m `div` 100
  | m <= 30000 = show $ m `div` 1000 + 50
  | m <= 70000 = show $ (m `div` 1000 - 30) `div` 5 + 80
  | otherwise = "89"
