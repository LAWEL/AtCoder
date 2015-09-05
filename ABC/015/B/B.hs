import Control.Applicative

main :: IO ()
main = do
  _ <- getLine
  a <- filter (> 0) <$> map read . words  <$> getLine
  let n = fromIntegral $ length a
  putStrLn . show . ceiling $ (/) (foldl (+) 0 a) n
