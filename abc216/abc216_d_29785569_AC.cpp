/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc216/submissions/29785569
 * Submitted at: 2022-03-01 15:04:29
 * Problem URL: https://atcoder.jp/contests/abc216/tasks/abc216_d
 * Result: AC
 * Execution Time: 455 ms
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

int main() {
    int n,m; cin >> n >> m;
    vector<queue<int>> ball(m);
    vector<queue<int>> top(n+1);
    queue<int> todo;
    rep(i,m){
        int k,a; cin >> k;
        rep(j,k){
            cin >> a;
            ball[i].push(a);
            if(!j){
                if(!top[a].empty())todo.push(a);
                top[a].push(i);
            }
        }
    }
    while(!todo.empty()){
        int two = todo.front(); todo.pop();
        rep(i,2){
            int k = top[two].front(); top[two].pop(); 
            ball[k].pop();
            if(ball[k].empty())continue;
            int tmp = ball[k].front();
            if(!top[tmp].empty())todo.push(tmp);
            top[tmp].push(k);
        }
    }
    rep(i,m){
        if(!ball[i].empty())return cout << "No" << endl,0;
    }
    cout << "Yes" << endl;
    return 0;
}