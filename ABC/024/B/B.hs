import Data.Maybe
import qualified Data.ByteString.Char8 as BS
import qualified Data.Vector.Unboxed as U

getInt :: IO Int
getInt = readLn

getInts :: IO [Int]
getInts = do
  bs <- BS.getLine
  return $ map (fst . fromJust . BS.readInt) $ BS.words bs


main :: IO ()
main = do
  [n, t] <- getInts
  a <- U.replicateM n getInt
  print $ U.foldl (+) 0 ( U.map (min t) $ U.zipWith (-) (U.tail a) a ) + t
