/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/43014822
 * Submitted at: 2023-06-28 10:39:31
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_u
 * Result: AC
 * Execution Time: 423 ms
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
    
    // 解説AC
    // dp[S] : 集合Sの要素でチーム分けした時の最高得点
    // → Sの部分集合でチームを切断してその2つの和を取ると再帰的に答えが求まる！
    // ( Sの部分集合も再帰的に切断されて求まるから、結局全てのチーム分けが求まる )

    // ただ、Sの部分集合を愚直に回すと O(2^N) かかり、total O(4^N) になってNG
    // → 部分集合をうまく回すテクニックを用いて、全体 O(3^N) にすることが可能！

    ll n; input(n);
    vector<vector<ll>> a(n,vector<ll>(n,0));
    rep(i,n)rep(j,n)input(a[i][j]);
    vector<ll> dp((1LL << n),0);
    vector<bool> visited((1LL << n),false);
    
    auto f = [&](auto self, ll now){
        if( visited[now] )return dp[now];
        visited[now] = true;

        // 訪れたら最初に初期値を入れておく (今現在の状態コスト)
        dp[now] = 0;
        rep(i,n)for(ll j=i+1;j<n;j++){
            if( (now & (1LL << i)) && (now & (1LL << j)) ){
                dp[now] += a[i][j];
            }
        }

        for(ll T=now;T>=0;T--){
            // ↓が超天才 (これをすることでT以下の最大の部分集合までfor文を skip している)
            // → 結果的に式変形すると、二項定理より total O(3^N) であることが示せる！
            T &= now;
            if(T == now || T == 0)continue;
            dp[now] = max( dp[now], self(self,T) + self(self,now^T) );
        }
        return dp[now];
    };
    print( f(f,(1LL << n)-1) );
    
    return 0;
}