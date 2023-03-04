/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc242/submissions/39391582
 * Submitted at: 2023-03-04 14:27:01
 * Problem URL: https://atcoder.jp/contests/abc242/tasks/abc242_d
 * Result: AC
 * Execution Time: 63 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    const vector<vector<char>> ch = { {'B','C'} , {'C','A'} , {'A','B'} };
    string s; ll q; input(s,q);
    while(q--){
        ll t,k; input(t,k); k--;
        char first = s[0];
        if(t >= 64){
            first = 'A' + (s[0]-'A'+t-64)%3;
            t = 64;
        }
        else{
            ull tmp = (1ULL << t);
            first = s[k/tmp];
            k %= tmp;
        }
        while(t--){
            first = ch[first-'A'][((k & (1ULL << t)) > 0)];
        }
        print(first);
    }
    
    return 0;
}