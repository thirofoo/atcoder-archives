/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc275/submissions/36054669
 * Submitted at: 2022-10-29 21:33:06
 * Problem URL: https://atcoder.jp/contests/abc275/tasks/abc275_c
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
    
    vector<string> field(9);
    rep(i,9)input(field[i]);
    ll ans = 0;
    // 各マス全探索
    rep(h,9){
        rep(w,9){
            // 全変位探索
            for(int i=-8;i<=8;i++){
                for(int j=-8;j<=8;j++){
                    if(i == 0 && j == 0)continue;
                    if(h < 0 || h >= 9 || w < 0 || w >= 9 || h+i < 0 || h+i >= 9 || w+j < 0 || w+j >= 9 || h-j < 0 || h-j >= 9 || w+i < 0 || w+i >= 9 || h+i-j < 0 || h+i-j >= 9 || w+j+i < 0 || w+j+i >= 9)continue;
                    if(field[h][w] == '#' && field[h+i][w+j] == '#' && field[h-j][w+i] == '#' && field[h+i-j][w+j+i] == '#'){
                        ans++;
                    }
                }
            }
        }
    }
    print(ans/4);
    
    return 0;
}