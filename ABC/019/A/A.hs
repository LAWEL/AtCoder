import Control.Applicative
import Data.List

main :: IO ()
main = do
  xs <- map read . words <$> getLine
  print (sort xs !! 1 :: Int)
