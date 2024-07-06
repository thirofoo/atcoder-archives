/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc361/submissions/55296156
 * Submitted at: 2024-07-06 21:54:33
 * Problem URL: https://atcoder.jp/contests/abc361/tasks/abc361_d
 * Result: WA
 * Execution Time: 1283 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    string s, t; cin >> s >> t;
    s += "..";
    t += "..";
    // string を 2 進数で持つ
    ll tll = 0, sll = 0;
    rep(i, n) {
        tll *= 3;
        sll *= 3;
        if(t[i] == 'W') tll++;
        else if(t[i] == 'B') tll += 2;
        if(s[i] == 'W') sll++;
        else if(s[i] == 'B') sll += 2;
    }

    vector<bool> visited(200000000, false);
    queue<T> q;
    q.push(T(0, n, tll));
    while(!q.empty()) {
        auto [cnt, idx, now] = q.front(); q.pop();
        if(visited[now]) continue;
        visited[now] = true;
        if(now == sll) {
            cout << cnt << endl;
            return 0;
        }
        rep(i, n+2) {
            if(idx-1 <= i && i <= idx+1) continue;
            ll next = now;
            if((now / (ll)pow(3ll, i)) % 3 == 1) {
                next -= (ll)pow(3ll, i);
                next += (ll)pow(3ll, idx);
            }
            else if((now / (ll)pow(3ll, i)) % 3 == 2) {
                next -= 2*(ll)pow(3ll, i);
                next += 2*(ll)pow(3ll, idx);
            }
            if((now / (ll)pow(3ll, i+1)) % 3 == 1) {
                next -= (ll)pow(3ll, i+1);
                next += (ll)pow(3ll, idx+1);
            }
            else if((now / (ll)pow(3ll, i+1)) % 3 == 2) {
                next -= 2*(ll)pow(3ll, i+1);
                next += 2*(ll)pow(3ll, idx+1);
            }
            if(!visited[next]) q.push(T(cnt+1, i, next));
        }
    }
    cout << -1 << endl;
    
    return 0;
}