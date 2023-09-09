/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc319/submissions/45416547
 * Submitted at: 2023-09-09 22:39:38
 * Problem URL: https://atcoder.jp/contests/abc319/tasks/abc319_f
 * Result: WA
 * Execution Time: 2207 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> p(n), t(n,2), s(n,0), g(n,0);
    vector<vector<ll>> Graph(n);
    vector<ll> med_idx;
    rep(i,n-1) {
        cin >> p[i+1] >> t[i+1] >> s[i+1] >> g[i+1];
        Graph[i].emplace_back(p[i+1]-1);
        Graph[p[i+1]-1].emplace_back(i);
        if( t[i+1] == 2 ) med_idx.emplace_back(i);
    }
    // 薬は高々10個 ⇒ 薬の飲む順番の優劣を順列全探索
    vector<ll> per(med_idx.size(),0);
    iota(per.begin(), per.end(), 0);

    do {
        // 基本的に薬は出来るだけ敵を倒してから飲む方が良い
        // 変則なbfsみたいにシミュレーション(?)
        ll now_strength = 1;
        vector<bool> visited(n,false);
        priority_queue<P,vector<P>,greater<P>> todo1, todo2, todo3;

        // P(敵の強さ, 今の頂点番号)
        todo1.push(P(0,0));
        while( true ) {
            ll cnt = 0;
            while( !todo1.empty() ) {
                auto [ e_g, now ] = todo1.top(); todo1.pop();
                visited[now] = true;
                now_strength += g[now];

                for(auto to:Graph[now]) {
                    if( visited[to] ) continue;
                    if( s[to] == 0 ) todo3.push(P(per[to],to));
                    else if( s[to] <= now_strength ) {
                        todo1.push(P(s[to], to));
                        cnt++;
                    }
                    else {
                        todo2.push(P(s[to], to));
                    }
                }
            }
            if( cnt == 0 ) break;

            // 薬吸引 part
            if( !todo3.empty() ) {
                auto [_, to] = todo3.top(); todo3.pop();
                now_strength *= g[to];
                now_strength = min(1000000000ll, now_strength);
            }
            
            if( todo1.empty() && todo2.empty() && todo3.empty() ) break;
            swap(todo1, todo2);
        }

        bool f = true;
        rep(i,n) {
            f &= visited[i];
            // cout << visited[i] << " ";
        }
        // cout << endl;
        if( f ) return cout << "Yes" << endl, 0;

    }while(next_permutation(per.begin(), per.end()));
    cout << "No" << endl;
    
    return 0;
}