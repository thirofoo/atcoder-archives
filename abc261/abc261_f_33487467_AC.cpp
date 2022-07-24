/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc261/submissions/33487467
 * Submitted at: 2022-07-24 11:43:27
 * Problem URL: https://atcoder.jp/contests/abc261/tasks/abc261_f
 * Result: AC
 * Execution Time: 148 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    //解説AC
    ll n; cin >> n;
    fenwick_tree<ll> tree(n+1);
    //方針：全体の転倒数-同色における転倒数
    //各色においてFWを作成するのはアホ → ある色において調査し終わったら元に戻す(合計2n個の変更しか無いためok)

    ll ans = 0;
    //色iの時の値を格納。(i=0の時は全ての色)
    vector<vector<ll>> color(n+1);
    vector<ll> tmp(n);
    rep(i,n)cin >> tmp[i];
    rep(i,n){
        ll x; cin >> x;
        color[0].push_back(x);
        color[tmp[i]].push_back(x);
    }

    fenwick_tree<ll> fw(n+1);
    //まず全体における転倒数を求めるpart
    rep(i,n){
        ans += i-fw.sum(0,color[0][i]);
        fw.add(color[0][i]-1,1);
    }
    //fwを元に戻すpart
    rep(i,n)fw.add(color[0][i]-1,-1);

    //同色における転倒数を求めて引くpart
    for(int i=1;i<=n;i++){
        //転倒数求
        ll cnt = 0;
        for(auto k:color[i]){
            ans -= cnt-fw.sum(0,k);
            fw.add(k-1,1);
            cnt++;
        }
        //fw元戻
        for(auto k:color[i])fw.add(k-1,-1);
    }
    cout << ans << endl;
    
    return 0;
}