main :: IO ()
main = readLn >>= (\a -> readLn >>= (\b -> print(a - b :: Int)))
