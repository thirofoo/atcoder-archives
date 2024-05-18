/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc170/submissions/53565615
 * Submitted at: 2024-05-18 12:37:24
 * Problem URL: https://atcoder.jp/contests/abc170/tasks/abc170_b
 * Result: AC
 * Execution Time: 1 ms
 */

use proconio::input;

fn main() {
    input! {
        x: i32,
        y: i32,
    }
    for i in 0..=x {
        if 2 * i + 4 * (x - i) == y {
            println!("Yes");
            return;
        }
    }
    println!("No");
}