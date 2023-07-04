/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/43253374
 * Submitted at: 2023-07-04 23:36:50
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_y
 * Result: AC
 * Execution Time: 60 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC (えぐすぎる)
    // O(HW) が通らないのでマンハッタン距離でsortしてstartに近い順から見ていきたいと思う
    // → i番目の壁を通る時が 1~i-1番目の壁を通る時から求められないか考える (ここまでは自力)
    // → 包除っぽく得のもありだが、計算量が間に合わない
    // → 『dp[i] : 初めに壁iに当たる行き方』が列挙出来れば包除しなくても求まるのでは？
    // → 求めるdpは、(i番目への行き方) - (1~i-1番目の壁を通ってi番目へ行く行き方)
    // → dp[i] = (i番目への行き方) - ∑_{j=1}^{i-1} dp[j]*(壁jへの行き方)

    ll h,w,n; input(h,w,n);
    vector<P> wall;
    rep(i,n){
        ll r,c; input(r,c);
        r--; c--;
        wall.push_back(P(r,c));
    }
    sort(wall.begin(),wall.end(),[](P a1, P a2){
        return a1.first+a1.second < a2.first+a2.second;
    });

    vector<mint> fact(h+w+1,1);
    vector<mint> r_fact(h+w+1,1);
    for(int i=1;i<=h+w;i++){
        fact[i] = fact[i-1]*i;
        r_fact[i] = (mint)1/fact[i];
    }
    auto f = [&](ll r,ll c){
        // Gridの↓→の行き方 : (r+c)! / r! / c!
        if( r < 0  || c < 0) return mint(0);
        return fact[r+c] * r_fact[r] * r_fact[c];
    };

    vector<mint> dp(n,0);
    rep(i,n){
        auto [r1, c1] = wall[i];
        dp[i] = f(r1, c1);
        for(ll j=0;j<i;j++){
            auto [r2, c2] = wall[j];
            dp[i] -= dp[j] * f(r1-r2, c1-c2);
        }
    }
    mint ans = f(h-1, w-1);
    rep(i,n){
        auto [r, c] = wall[i];
        ans -= dp[i] * f(h-1-r, w-1-c);
    }
    print( ans.val() );
    
    return 0;
}