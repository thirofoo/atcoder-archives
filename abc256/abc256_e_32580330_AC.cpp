/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc256/submissions/32580330
 * Submitted at: 2022-06-19 09:10:16
 * Problem URL: https://atcoder.jp/contests/abc256/tasks/abc256_e
 * Result: AC
 * Execution Time: 46 ms
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
    
    //union-find解(各連結成分においては1の犠牲で十分)
    int n; cin >> n;
    dsu uf(n);
    vector<int> x(n),c(n);
    rep(i,n)cin >> x[i],x[i]--;
    rep(i,n)cin >> c[i];
    ll ans = 0;
    rep(i,n){
        if(!uf.same(i,x[i])){
            uf.merge(i,x[i]);
            continue;
        }
        //閉路が完成したら閉路内でのminをansに足す。
        int tmp = INT_MAX,start = i,now = i;
        while(true){
            tmp = min(c[now],tmp);
            now = x[now];
            if(now == start)break;
        }
        ans += tmp;
    }
    cout << ans << endl;

    return 0;
}