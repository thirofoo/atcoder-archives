/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc290/submissions/39049749
 * Submitted at: 2023-02-19 23:52:17
 * Problem URL: https://atcoder.jp/contests/abc290/tasks/abc290_e
 * Result: AC
 * Execution Time: 53 ms
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
    
    // 主客転倒
    // 同じ数のペアがあると回文にしやすい。
    // 端のペアほどその貢献度が少ない 
    // → 同じ数のグループの中で一番端に近い頂点を固定した時のペア数を求める
    // すると O(N)で数え上げ可能。

    // あるペアがどれくらいの貢献度かを求めると、ペアの取り方max O(N^2)で死ぬが、
    // 部位で考えると O(N) に落ちる。
    ll n; input(n);
    vector<vector<ll>> num(200005);
    rep(i,n){
        ll a; input(a);
        num[a].emplace_back(i);
    }
    ll ans = 0;
    for(ll i=2;i<=n;i++)ans += (i/2)*(n-i+1);
    rep(i,200000){
        ll l = 0, r = num[i+1].size()-1;
        while(l < r){
            //  左端の余裕        右端の余裕
            if(num[i+1][l]+1 <= n-num[i+1][r]){
                // 左端固定して, 右端のペア*左端の余裕 分減らす
                ans -= (num[i+1][l]+1)*(r-l);
                l++;
            }
            else{
                ans -= (n-num[i+1][r])*(r-l);
                r--;
            }
        }
    }
    print(ans);
    
    return 0;
}