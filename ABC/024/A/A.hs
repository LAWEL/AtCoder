import Data.Maybe
import qualified Data.ByteString.Char8 as BS

getInts :: IO [Int]
getInts = do
  bs <- BS.getLine
  return $ map (fst . fromJust . BS.readInt) $ BS.words bs

main :: IO ()
main = do
  [a, b, c, k] <- getInts
  [s, t] <- getInts
  print $ a * s + b * t - (if s + t >= k then (s + t) * c else 0)
