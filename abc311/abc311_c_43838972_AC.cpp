/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc311/submissions/43838972
 * Submitted at: 2023-07-22 21:11:15
 * Problem URL: https://atcoder.jp/contests/abc311/tasks/abc311_c
 * Result: AC
 * Execution Time: 60 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n), dig(n,0);
    rep(i,n) {
        cin >> a[i];
        a[i]--;
        dig[a[i]]++;
    }

    queue<ll> todo;
    rep(i,n) if(dig[i] == 0) todo.push(i);
    vector<bool> visited(n,false);
    while(!todo.empty()){
        ll now = todo.front(); todo.pop();
        if( visited[now] ) continue;
        visited[now] = true;
        dig[a[now]]--;
        if( dig[a[now]] == 0 ) todo.push(a[now]);
    }

    ll start;
    vector<ll> ans;
    rep(i,n){
        if( !visited[i] ){
            todo.push(a[i]);
            start = i;
            ans.push_back(i+1);
            break;
        }
    }
    while(!todo.empty()){
        ll now = todo.front(); todo.pop();
        if( start == now ) break;
        ans.push_back(now+1);
        todo.push(a[now]);
    }
    cout << ans.size() << endl;
    rep(i,ans.size()) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}