import Control.Monad
import Control.Applicative

main :: IO ()
main = do
  [n,m] <- map (read :: String -> Int).words <$> getLine
  edges <- replicateM m $ map (read :: String -> Int) . words <$> getLine
  putStrLn $ solve a b c

{- DFS -}
dfs :: Int -> Int -> Int -> Int -> Array (Int,Int) Char -> Array (Int,Int) Char
dfs x y n m garden_init = dfs_rec (garden_init//[((x,y),'.')]) [(nx,ny)|(nx,ny) <- [(x-1,y-1),(x,y-1),(x+1,y-1),(x-1,y),(x+1,y),(x-1,y+1),(x,y+1),(x+1,y+1)] , nx>=0 , nx<n , ny>=0 , ny<m]
    where
      dfs_rec garden [] = garden
      dfs_rec garden ((nx,ny):cs) = if garden!(nx,ny) == 'w' then
                                        let new_garden = dfs nx ny n m garden
                                        in
                                          dfs_rec new_garden cs
                                    else
                                        dfs_rec garden cs
