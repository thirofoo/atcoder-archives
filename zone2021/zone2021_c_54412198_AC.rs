/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/zone2021/submissions/54412198
 * Submitted at: 2024-06-09 23:43:30
 * Problem URL: https://atcoder.jp/contests/zone2021/tasks/zone2021_c
 * Result: AC
 * Execution Time: 2 ms
 */

use std::collections::HashSet;
use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    
    let n: usize = lines.next().unwrap().unwrap().parse().unwrap();
    const ABILITY: usize = 5;
    
    let mut p: Vec<Vec<i32>> = Vec::with_capacity(n);
    for _ in 0..n {
        let line = lines.next().unwrap().unwrap();
        let abilities: Vec<i32> = line.split_whitespace()
                                      .map(|s| s.parse().unwrap())
                                      .collect();
        p.push(abilities);
    }
    
    fn check(x: i32, p: &Vec<Vec<i32>>, n: usize) -> bool {
        let mut s: HashSet<i32> = HashSet::new();
        for i in 0..n {
            let mut bit = 0;
            for j in 0..ABILITY {
                if p[i][j] >= x {
                    bit |= 1 << j;
                }
            }
            s.insert(bit);
        }

        let bits: Vec<i32> = s.into_iter().collect();
        for &v1 in &bits {
            for &v2 in &bits {
                for &v3 in &bits {
                    if (v1 | v2 | v3) == (1 << ABILITY) - 1 {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    let mut left = 0;
    let mut right = 1_000_000_005;
    while right - left > 1 {
        let mid = (left + right) / 2;
        if check(mid, &p, n) {
            left = mid;
        } else {
            right = mid;
        }
    }
    
    println!("{}", left);
}
