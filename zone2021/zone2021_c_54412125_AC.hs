/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/zone2021/submissions/54412125
 * Submitted at: 2024-06-09 23:41:02
 * Problem URL: https://atcoder.jp/contests/zone2021/tasks/zone2021_c
 * Result: AC
 * Execution Time: 41 ms
 */

import Data.Bits (bit, (.|.))
import Data.List (nub)
import Control.Monad (replicateM)

-- Function to read a list of lists
readMatrix :: Int -> Int -> IO [[Int]]
readMatrix n m = replicateM n $ do
  line <- getLine
  return $ map read $ words line

-- Function to check if it's possible to satisfy the condition with a given threshold
check :: Int -> [[Int]] -> Bool
check x p = any (\(v1, v2, v3) -> (v1 .|. v2 .|. v3) == (bit ability - 1)) combinations
  where
    ability = 5 :: Int
    bits = map (foldr (\(j, v) acc -> if v >= x then acc .|. bit j else acc) (0 :: Int) . zip [0..]) p
    uniqueBits = nub bits
    combinations = [(v1, v2, v3) | v1 <- uniqueBits, v2 <- uniqueBits, v3 <- uniqueBits]

-- Binary search to find the maximum possible threshold
binarySearch :: Int -> Int -> [[Int]] -> Int
binarySearch left right p
  | right - left <= 1 = left
  | check mid p = binarySearch mid right p
  | otherwise = binarySearch left mid p
  where
    mid = (left + right) `div` 2

main :: IO ()
main = do
  -- Read input values
  n <- readLn
  let ability = 5
  p <- readMatrix n ability

  -- Find and print the result using binary search
  let result = binarySearch 0 (10^9 + 5) p
  print result
