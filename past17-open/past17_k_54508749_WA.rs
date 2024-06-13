/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54508749
 * Submitted at: 2024-06-13 23:53:29
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_k
 * Result: WA
 * Execution Time: 3 ms
 */

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut lines = input.split_whitespace();
    let n: usize = lines.next().unwrap().parse().unwrap();
    let s: Vec<char> = lines.next().unwrap().chars().collect();

    let mut possible = vec![vec![-1; 10]; 9];
    for i in 0..9 {
        for j in 0..10 {
            possible[i][(i + 1) * j % 10] = j as i32;
        }
    }

    let mut hatena = vec![None; 10];
    let mut sum = 0;
    for i in 0..n {
        if s[i] == '?' {
            if hatena[i % 10].is_none() {
                hatena[i % 10] = Some(i);
            }
        } else {
            sum += (s[i] as u8 - '0' as u8) as i32 * (i % 10 + 1) as i32;
        }
    }
    sum = (10 - sum % 10) % 10;

    let mut odd = None;
    for i in (0..10).step_by(2) {
        if hatena[i].is_some() && i != 4 {
            odd = Some(i);
            break;
        }
    }
    if let Some(odd_idx) = odd {
        let idx = hatena[odd_idx].unwrap();
        let mut s = s;
        s[idx] = (possible[odd_idx][sum as usize] as u8 + '0' as u8) as char;
        println!("Yes");
        println!("{}", s.iter().collect::<String>());
        return;
    }

    let five = hatena[4].map(|_| 4);
    let mut even = None;
    for i in (1..9).step_by(2) {
        if hatena[i].is_some() {
            even = Some(i);
            break;
        }
    }

    if let (Some(five_idx), Some(even_idx)) = (five, even) {
        let mut s = s;
        s[hatena[five_idx].unwrap()] = (possible[five_idx][if sum % 2 == 0 { 0 } else { 5 } as usize] as u8 + '0' as u8) as char;
        if sum % 2 == 1 {
            sum = (sum + 5) % 10;
        }
        s[hatena[even_idx].unwrap()] = (possible[even_idx][sum as usize] as u8 + '0' as u8) as char;
        println!("Yes");
        println!("{}", s.iter().collect::<String>());
        return;
    }

    if let Some(even_idx) = even {
        if sum % 2 == 0 {
            let mut s = s;
            s[hatena[even_idx].unwrap()] = (possible[even_idx][sum as usize] as u8 + '0' as u8) as char;
            println!("Yes");
            println!("{}", s.iter().collect::<String>());
            return;
        }
    }

    if let Some(five_idx) = five {
        if sum % 5 == 0 {
            let mut s = s;
            s[hatena[five_idx].unwrap()] = (possible[five_idx][sum as usize] as u8 + '0' as u8) as char;
            println!("Yes");
            println!("{}", s.iter().collect::<String>());
            return;
        }
    }

    if sum == 0 {
        println!("Yes");
        println!("{}", s.iter().collect::<String>());
        return;
    }

    println!("No");
}
