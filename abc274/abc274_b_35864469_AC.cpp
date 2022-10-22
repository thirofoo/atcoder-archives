/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc274/submissions/35864469
 * Submitted at: 2022-10-22 21:03:52
 * Problem URL: https://atcoder.jp/contests/abc274/tasks/abc274_b
 * Result: AC
 * Execution Time: 12 ms
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
    
    ll h,w; input(h,w);
    vector<string> field(h);
    rep(i,h)input(field[i]);
    rep(j,w){
        ll tmp = 0;
        rep(i,h){
            if(field[i][j] == '#')tmp++;
        }
        cout << tmp << " ";
    }
    print();
    
    return 0;
}