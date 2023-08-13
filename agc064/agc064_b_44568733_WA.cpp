/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc064/submissions/44568733
 * Submitted at: 2023-08-13 23:43:16
 * Problem URL: https://atcoder.jp/contests/agc064/tasks/agc064_b
 * Result: WA
 * Execution Time: 77 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, char, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<T> edge;
    vector<ll> r_cnt(n,0), b_cnt(n,0);
    rep(i,m) {
        ll a,b; char c; cin >> a >> b >> c;
        a--; b--;
        edge.push_back(T(a,b,c,i));
        if( c == 'R' ) {
            r_cnt[a]++;
            r_cnt[b]++;
        }
        else {
            b_cnt[a]++;
            b_cnt[b]++;
        }
    }
    string s; cin >> s;
    vector<ll> ans;
    vector<bool> ok(n,false);
    queue<T> rest, tmp;
    dsu uf(n);
    // 初めに題意を満たすにはこれを使うしかないという辺を使う
    rep(i,m) {
        auto [a,b,c,_] = edge[i];
        if( uf.same(a,b) ) continue;
        if( (s[a] == c && ( (c == 'R' && r_cnt[a] == 1 ) || (c == 'B' && b_cnt[a] == 1 ) )) ) {
            ok[a] = true;
            if( s[b] == c ) ok[b] = true;
            uf.merge(a,b);
            ans.push_back(i+1);
        }
        else if( (s[b] == c && ( (c == 'R' && r_cnt[b] == 1 ) || (c == 'B' && b_cnt[b] == 1 ) )) ) {
            ok[b] = true;
            if( s[a] == c ) ok[a] = true;
            uf.merge(a,b);
            ans.push_back(i+1);
        }
        else rest.push(edge[i]);
    }

    // 同じ色 && 端点が共にどの色を欲する場合は先に付け得
    while( !rest.empty() ) {
        auto [a,b,c,i] = rest.front(); rest.pop();
        if( uf.same(a,b) ) {
            tmp.push(T(a,b,c,i));
            continue;
        }

        if( !ok[a] && !ok[b] && ( s[a] == s[b] && s[a] == c ) ) {
            ok[a] = true;
            ok[b] = true;
            uf.merge(a,b);
            ans.push_back(i+1);
        }
        else tmp.push(edge[i]);
    }
    swap(rest,tmp);
    
    // 未使用の辺 && 題意を満たしていない端点がある辺を使う
    while( !rest.empty() ) {
        auto [a,b,c,i] = rest.front(); rest.pop();
        if( uf.same(a,b) ) {
            tmp.push(T(a,b,c,i));
            continue;
        }

        if( !ok[b] && s[b] == c ) {
            ok[a] = true;
            if( s[b] == c ) ok[b] = true;
            uf.merge(a,b);
            ans.push_back(i+1);
        }
        else if( !ok[a] && s[a] == c ) {
            ok[b] = true;
            if( s[a] == c ) ok[a] = true;
            uf.merge(a,b);
            ans.push_back(i+1);
        }
        else tmp.push(edge[i]);
    }
    swap(rest,tmp);

    // 最後に連結になるようにあまりで補う
    while( !rest.empty() ) {
        auto [a,b,c,i] = rest.front(); rest.pop();
        if( uf.same(a,b) ) continue;
        uf.merge(a,b);
        ans.push_back(i+1);
    }

    bool f = true;
    rep(i,n) f = (f && ok[i]);

    if( !f ) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        for(auto ele:ans) cout << ele << " ";
        cout << endl;
    }
    
    return 0;
}