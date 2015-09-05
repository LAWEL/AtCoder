import Data.List

main :: IO ()
main = do
  s <- getLine
  let gs = group s
      res = concatMap (\g -> head g : show (length g)) gs
  putStrLn res
