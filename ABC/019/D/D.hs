import Control.Applicative
import System.IO

getInt :: IO Int
getInt = readLn

ask :: Int -> Int -> IO (Int, Int)
ask s t = do
  putStrLn $ "? " ++ show s ++ " " ++ show t
  hFlush stdout
  r <- readLn
  return (r, t)

main :: IO ()
main = do
  n <- getInt

  (_, far) <- maximum <$> mapM (\i -> ask 1 i) [1..n]
  (dia, _) <- maximum <$> mapM (\i -> ask far i) [1..n]

  putStrLn $ "! " ++ show dia
