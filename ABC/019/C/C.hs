import qualified Data.ByteString.Char8 as BS
import qualified Data.IntSet as IntSet
import           Data.Maybe


getInt :: IO Int
getInt = readLn

getInts :: IO [Int]
getInts = do
  bs <- BS.getLine
  return $ map (fst . fromJust . BS.readInt) $ BS.words bs

main :: IO ()
main = do
  n <- getInt
  as <- getInts
  let ans = IntSet.size $ IntSet.fromList $ map f as
      f x | even x = f $ x `div` 2
          | otherwise = x
  print ans
