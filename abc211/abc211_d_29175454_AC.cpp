/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc211/submissions/29175454
 * Submitted at: 2022-02-09 12:46:18
 * Problem URL: https://atcoder.jp/contests/abc211/tasks/abc211_d
 * Result: AC
 * Execution Time: 143 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int mod = 1000000007;

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> edge(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    vector<int> seen(n,0),cnt(n,0);
    queue<int> todo;
    todo.push(0);
    cnt[0] = 1;
    while(!todo.empty()){
        int tmp = todo.front(); todo.pop();
        for(auto k:edge[tmp]){
            if(!seen[k]){
                todo.push(k);
                seen[k] = seen[tmp] + 1;
                cnt[k] += cnt[tmp];
                cnt[k] %= mod;
            }
            else if(seen[k] == seen[tmp] + 1){
                cnt[k] += cnt[tmp];
                cnt[k] %= mod;
            }
        }
    }
    cout << cnt[n-1] << endl;
    return 0;
}