/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc133/submissions/28690116
 * Submitted at: 2022-01-22 21:49:07
 * Problem URL: https://atcoder.jp/contests/arc133/tasks/arc133_a
 * Result: TLE
 * Execution Time: 2250 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    set<int> v;
    queue<int> que;
    vector<vector<int>> dict(n);
    rep(i,n){
        int a; cin >> a;
        que.push(a);
        v.insert(a);
    }
    for(auto k:v){
        rep(j,n){
            int a = que.front();
            que.pop(); que.push(a);
            if(a == k)continue;
            dict[k-1].push_back(a);
        }
    }
    int idx = 0;
    sort(dict.begin(),dict.end());
    rep(i,n){
        if(dict[i].size() == 0){idx++; continue;}
        break;
    }
    if(idx == n)return cout << endl,0;
    while(!dict[idx].empty()){
        int a = dict[idx][0];
        dict[idx].erase(dict[idx].begin());
        cout << a << " ";
    }
    cout << endl;
    return 0;
}