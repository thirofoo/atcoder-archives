/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc231/submissions/39292229
 * Submitted at: 2023-02-27 20:10:15
 * Problem URL: https://atcoder.jp/contests/abc231/tasks/abc231_e
 * Result: WA
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

map<ll,ll> mp;
vector<ll> a;
ll n,x;
ll dfs(ll x,ll i){
    if(i == n-1){
        mp[x] = x/a[i];
        return x/a[i];
    }
    if(mp.count(x))return mp[x];
    // ※ x = 20000 とかで 貨幣10 がある時明らかに10は要らない
    if(x%a[i+1] == 0)dfs(x,i+1);
    else{
        mp[x-x%a[i+1]] = dfs(x-x%a[i+1],i+1);
        mp[x-x%a[i+1]+a[i+1]] = dfs(x-x%a[i+1]+a[i+1],i+1);
    }
    return min(mp[x-x%a[i+1]] + (x%a[i+1])/a[i] , mp[x-x%a[i+1]+a[i+1]] + (-x%a[i+1]+a[i+1])/a[i]);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(n,x);
    a.assign(n,0);
    rep(i,n)input(a[i]);

    // 繰り上がりあるかないかで場合分けする
    // ( 小さい貨幣から、おつりを貰って繰り上げる or 端数分払う )
    // 下位桁が2つ以上上位桁に影響を及ぼすことが無い → 再帰的に解いても状態が膨れ上がらない
    
    print(dfs(x,0));

    return 0;
}