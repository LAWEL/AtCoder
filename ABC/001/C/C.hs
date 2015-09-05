main :: IO ()
main = do
  [deg, dis] <- map read . words <$> getLine
