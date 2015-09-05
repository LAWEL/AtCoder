import Control.Monad
import Control.Applicative

main :: IO ()
main = do
  scores <- replicateM 3 $ map (read :: String -> Int) . words <$> getLine
  print $ foldl (\acc x -> acc + calc x) 0 scores

calc :: [Int] -> Int
calc [] = 0
calc [_] = 0
calc (s:e:_) = s * e `div` 10
