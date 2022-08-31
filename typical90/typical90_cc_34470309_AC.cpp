/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34470309
 * Submitted at: 2022-08-31 13:15:49
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_cc
 * Result: AC
 * Execution Time: 618 ms
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC。二次元累積和。天才。
    // 自分の尺取り解法は伸長が同じ場合に好きな順序で選べるところを、体重が軽い順位しか試して無い故に駄目になってる気がする。
    ll n,k; input(n,k);
    vector cum(5005,vector<ll>(5005,0));
    rep(i,n){
        ll a,b; input(a,b);
        cum[a][b]++;
    }

    //累積和
    rep(i,5005)rep(j,5004)cum[i][j+1] += cum[i][j];
    rep(i,5005)rep(j,5004)cum[j+1][i] += cum[j][i];

    ll ans = 0;
    for(int i=1;i<=5000;i++){
        for(int j=1;j<=5000;j++){
            ans = max(ans,cum[i][j]-cum[max(0LL,i-k-1)][j]-cum[i][max(0LL,j-k-1)]+cum[max(0LL,i-k-1)][max(0LL,j-k-1)]);
        }
    }

    print(ans);

    return 0;
}