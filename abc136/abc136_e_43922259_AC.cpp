/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc136/submissions/43922259
 * Submitted at: 2023-07-24 14:28:23
 * Problem URL: https://atcoder.jp/contests/abc136/tasks/abc136_e
 * Result: AC
 * Execution Time: 49 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

//約数列挙ver(1,nも含む)
vector<ll> divisor(ll n){
    vector<ll> div;
    for(ll i=1;i*i<=n;i++){
        if(n%i)continue;
        div.push_back(i);
        if(i != n/i)div.push_back(n/i);
    }
    return div;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 負を許しても各項の絶対値の差分が高々 ∑A_i しか開かない
    // → ∑A_i の約数右が答えの候補
    ll n, k, sum = 0; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    vector div = divisor(sum);
    sort( div.begin(), div.end(), [](ll e1, ll e2){
        return e1 > e2;
    } );

    ll ans = 1;
    for(auto ele:div) {
        // a[i] % ele or (ele-a[i]) % ele が候補になりそう
        vector<P> e;
        rep(i,n) e.push_back( P( (( a[i]%ele + ele ) % ele), ((ele-a[i])%ele + ele ) % ele) );
        sort( e.begin(), e.end() );
        rep(i,e.size()-1) {
            e[i+1].first += e[i].first;
            e[i+1].second += e[i].second;
        }

        // cout << ele << endl;
        // rep(i,e.size()) cout << e[i].first << " ";
        // cout << endl;
        // rep(i,e.size()) cout << e[i].second << " ";
        // cout << endl;

        rep(i,e.size()) {
            if( e[i].first == e[e.size()-1].second - e[i].second ){
                // 実は小さい順から見て初めて適切な操作になった時が最小
                // ele = 5 の時
                // 1,1,2,3,4,4
                // 4,4,3,2,1,1
                // idx = 0, 1, 4 を選ぶと 6 になるが
                // idx = 0, 1, 2 を選ぶと 4 に最小化
                // 候補は上記の様に他にも存在するが、候補が存在した時うまく入れ替えると、
                // 条件を満たしたまま最小化出来て、それが小さい順からの累積和に該当
                // cout << e[i].first << " " << k << " " << ele << endl;
                if( e[i].first <= k ) ans = max(ans,ele);
                break;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}



