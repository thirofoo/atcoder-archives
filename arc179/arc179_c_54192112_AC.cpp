/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc179/submissions/54192112
 * Submitted at: 2024-06-03 11:10:03
 * Problem URL: https://atcoder.jp/contests/arc179/tasks/arc179_c
 * Result: AC
 * Execution Time: 92 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    // 1. 挿入ソートの要領で比較クエリを用いる
    // 2. 最大の要素と最小の要素を足すクエリを用いる
    // 3. その足した値をまた挿入ソートの要領で比較クエリを用いる
    // 4. 2 と 3 を繰り返す

    // 1. 最初にソートする
    // idx[i] : i番目に大きい値のインデックス
    vector<ll> idx(n, INF);
    idx[0] = 0;
    reps(i, 1, n) {
        ll left = 0, right = i;
        while( right - left > 1 ) {
            ll mid = (left + right) / 2;
            cout << "? " << i+1 << " " << idx[mid]+1 << endl << flush;
            ll res; cin >> res;
            if( res == 1 ) right = mid;
            else left = mid;
        }
        // 最後に left と比較
        cout << "? " << i+1 << " " << idx[left]+1 << endl << flush;
        ll res; cin >> res;
        if( res == 0 ) left++;
        // idx の left 番目に i を挿入
        for(ll j=i; j>left; j--) idx[j] = idx[j-1];
        idx[left] = i;
    }

    // rep(i,n) cout << idx[i] << " ";
    // cout << endl;
    // return 0;

    ll add_cnt = 1;
    while( true ) {
        cout << "+ " << idx.back()+1 << " " << idx[0]+1 << endl << flush;
        ll res; cin >> res;
        add_cnt++;
        if( add_cnt == n ) break;

        // idx[n-1] と idx[0] の分を前に詰める
        rep(i,n-2) idx[i] = idx[i+1];
        idx.pop_back();
        idx.pop_back();

        // 再度比較
        ll left = 0, right = n-add_cnt;
        while( right - left > 1 ) {
            ll mid = (left + right) / 2;
            cout << "? " << res << " " << idx[mid]+1 << endl << flush;
            ll tr; cin >> tr;
            if( tr == 1 ) right = mid;
            else left = mid;
        }

        // 最後に left と比較
        cout << "? " << res << " " << idx[left]+1 << endl << flush;
        ll tr; cin >> tr;
        if( tr == 0 ) left++;

        // idx の left 番目に res を挿入
        idx.emplace_back(0);
        for(ll i=n-add_cnt; i>left; i--) idx[i] = idx[i-1];
        idx[left] = res-1;
    }
    cout << "!" << endl << flush;
    return 0;
}
// 3 1 4 5 2