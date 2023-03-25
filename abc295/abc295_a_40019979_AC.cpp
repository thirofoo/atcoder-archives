/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc295/submissions/40019979
 * Submitted at: 2023-03-25 21:01:29
 * Problem URL: https://atcoder.jp/contests/abc295/tasks/abc295_a
 * Result: AC
 * Execution Time: 5 ms
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
    
    ll n; input(n);
    vector<string> t = {"and","not","that","the","you"};
    vector<string> w(n);
    rep(i,n)input(w[i]);
    rep(i,n){
        rep(j,5){
            if(w[i] == t[j]){
                print("Yes");
                return 0;
            }
        }
    }
    print("No");
    
    return 0;
}