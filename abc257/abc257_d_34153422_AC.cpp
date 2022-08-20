/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc257/submissions/34153422
 * Submitted at: 2022-08-20 12:17:44
 * Problem URL: https://atcoder.jp/contests/abc257/tasks/abc257_d
 * Result: AC
 * Execution Time: 588 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<T> ju;
    rep(i,n){
        ll x,y,p; cin >> x >> y >> p;
        ju.push_back(T(x,y,p));
    }

    ll left = 0,right = 1e10;
    queue<ll> todo;
    while(right-left > 1){
        ll mid = (right+left)/2;
        bool flag = false;
        rep(i,n){
            dsu uf(n);
            auto [x1,y1,p1] = ju[i];
            rep(j,n){
                auto [x2,y2,p2] = ju[j];
                if(p1*mid >= abs(x1-x2)+abs(y1-y2)){
                    uf.merge(i,j);
                    todo.push(j);
                }
            }
            while(!todo.empty()){
                ll tmp = todo.front(); todo.pop();
                auto [x1,y1,p1] = ju[tmp];
                rep(j,n){
                    if(uf.same(i,j))continue;
                    auto [x2,y2,p2] = ju[j];
                    if(p1*mid >= abs(x1-x2)+abs(y1-y2)){
                        uf.merge(i,j);
                        todo.push(j);
                    }
                }
            }
            if(uf.size(0) == n){
                flag = true;
                break;
            }
        }

        if(flag)right = mid;
        else left = mid;
    }
    cout << right << endl;

    return 0;
}