import Control.Applicative

main :: IO ()
main = do
  [a,b] <- map (read :: String -> Int).words <$> getLine
  putStrLn $ if a `mod` b == 0 then "YES" else "NO"
