/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc313/submissions/44287533
 * Submitted at: 2023-08-05 21:49:40
 * Problem URL: https://atcoder.jp/contests/abc313/tasks/abc313_d
 * Result: WA
 * Execution Time: 2205 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,k; cin >> n >> k;
    // ある1頂点で関係性全把握 → 最後に01確かめる
    dsu uf(n);
    ll res1, res2, cnt = 0;

    // 1. まず偶奇のグループ分け
    for(ll i=1;i<n;i++) {
        cnt = 0;
        cout << "?";
        rep(j,n) {
            cout << " " << j+1;
            cnt++;
            if(cnt == k) break;
        }
        cout << endl << flush;
        cin >> res1;

        cnt = 0;
        cout << "?";
        rep(j,n) {
            if( j != i ) cout << " " << j+1;
            else cnt--;
            cnt++;
            if(cnt == k) break;
        }
        cout << endl << flush;
        cin >> res2;

        if( res1 == res2 ) uf.merge(0,i);
    }

    // cout << "Yeah!" << endl << flush;

    if( uf.size(0) == n ) {
        cout << "?";
        rep(i,k) cout << " " << i+1;
        cout << endl << flush;
        cin >> res1;
        cout << "!";
        rep(i,n) cout << res1 << " ";
        cout << endl << flush;
        return 0;
    }

    // 2. 1番目が0 or 1 か
    vector<P> p;
    rep(i,n) p.push_back(P(uf.same(0,i),i));
    sort(p.begin(),p.end());

    cout << "?";
    cnt = 0;
    rep(i,k) cout << " " << p[i].second + 1;
    cout << endl << flush;
    cin >> res1;

    cout << "?";
    cnt = 0;
    cout << " " << p.back().second + 1;
    rep(i,k-1) cout << " " << p[i].second + 1;
    cout << endl << flush;
    cin >> res2;
    
    if( res1 == res2 ) {
        cout << "!";
        rep(i,n) cout << " " << (uf.same(0,i) ? 0 : 1);
        cout << endl << flush;
    }
    else {
        cout << "!";
        rep(i,n) cout << " " << (uf.same(0,i) ? 1 : 0);
        cout << endl << flush;
    }
    
    return 0;
}