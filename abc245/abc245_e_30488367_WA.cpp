/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc245/submissions/30488367
 * Submitted at: 2022-03-27 00:34:25
 * Problem URL: https://atcoder.jp/contests/abc245/tasks/abc245_e
 * Result: WA
 * Execution Time: 322 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m; cin >> n >> m;
    vector<int> a(n),b(n),c(m),d(m);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,m)cin >> c[i];
    rep(i,m)cin >> d[i];

    priority_queue<T> todo;
    multiset<P> size;
    rep(i,m)todo.push(T(c[i],d[i],1));
    rep(i,n)todo.push(T(a[i],b[i],0));

    while(!todo.empty()){
        auto [x,y,i] = todo.top(); todo.pop();
        if(i)size.insert(P(y,x));
        else{
            if(size.empty())return cout << "No" << endl,0;
            auto itr = size.lower_bound(P(y,x));
            while(itr != size.end()){
                if((*itr).first >= y)break;
                itr++;
            }
            if(itr == size.end())return cout << "No" << endl,0;
            size.erase(*itr);
        }
    }
    cout << "Yes" << endl;
    return 0;
}