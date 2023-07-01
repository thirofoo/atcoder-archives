/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc308/submissions/43097289
 * Submitted at: 2023-07-01 21:08:20
 * Problem URL: https://atcoder.jp/contests/abc308/tasks/abc308_a
 * Result: AC
 * Execution Time: 8 ms
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
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<ll> s(8);
    rep(i,8)input(s[i]);
    rep(i,7){
        if(s[i] > s[i+1]){
            print("No");
            return 0;
        }
    }
    rep(i,8){
        if( s[i] < 100 || 675 < s[i]){
            print("No");
            return 0;
        }
    }
    rep(i,8){
        if(s[i]%25 != 0){
            print("No");
            return 0;
        }
    }
    print("Yes");
    
    return 0;
}