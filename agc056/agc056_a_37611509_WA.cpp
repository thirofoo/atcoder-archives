/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc056/submissions/37611509
 * Submitted at: 2022-12-29 15:16:47
 * Problem URL: https://atcoder.jp/contests/agc056/tasks/agc056_a
 * Result: WA
 * Execution Time: 13 ms
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

vector<vector<string>> hard = {
    {
        "###",
        "###",
        "###",
    },
    {
        ".###",
        "#.##",
        "##.#",
        "###.",
    },
    {
        "..###",
        "..###",
        "##..#",
        "##.#.",
        "###..",
    },
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    // rep(i,(1LL << n*n)){
    //     bool f = true;
    //     // 行確認
    //     rep(j,n){
    //         ll tmp = 0;
    //         rep(k,n)if(i & (1LL << (j*n+k)))tmp++;
    //         f &= (tmp == 3);
    //     }
    //     // 列確認
    //     rep(j,n){
    //         ll tmp = 0;
    //         rep(k,n)if(i & (1LL << (k*n+j)))tmp++;
    //         f &= (tmp == 3);
    //     }
    //     if(f){
    //         stack<ll> st;
    //         while(i){
    //             st.push(i%2);
    //             i >>= 1;
    //         }
    //         while(st.size() != n*n)st.push(0);
    //         ll now = 0;
    //         while(!st.empty()){
    //             cout << st.top();
    //             st.pop();
    //             if(now%n == n-1)print();
    //             now++;
    //         }
    //         return 0;
    //     }
    // }
    
    vector<vector<char>> ans(n,vector<char>(n,'.'));
    ll now = 0;
    if(n%3 == 1){
        rep(i,4)rep(j,4)ans[i][j] = hard[1][i][j];
        now = 4;
    }
    if(n%3 == 2){
        rep(i,5)rep(j,5)ans[i][j] = hard[2][i][j];
        now = 5;
    }
    while(now < n){
        rep(i,3)rep(j,3)ans[i+now][j+now] = hard[0][i][j];
        now += 3;
    }
    rep(i,n){
        rep(j,n)cout << ans[i][j];
        print();
    }
    
    return 0;
}