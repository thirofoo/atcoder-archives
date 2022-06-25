/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc257/submissions/32752208
 * Submitted at: 2022-06-25 22:59:51
 * Problem URL: https://atcoder.jp/contests/abc257/tasks/abc257_d
 * Result: WA
 * Execution Time: 831 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ld, ld, ld> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(6) << fixed;
    
    int n; cin >> n;
    vector<T> ju;
    map<P,ld> d;
    rep(i,n){
        ld x,y,p; cin >> x >> y >> p;
        ju.push_back(T(x,y,p));
    }
    rep(i,n){
        auto [x1,y1,p1] = ju[i];
        for(int j=i+1;j<n;j++){
            if(i == j)continue;
            auto [x2,y2,p2] = ju[j];
            d[P(i,j)] = abs(x1-x2)+abs(y1-y2);
        }
    }
    ll left = 0,right = 1e10;
    while(right-left > 1){
        ll mid = (right+left)/2;
        bool flag = false;
        vector<vector<int>> Graph(n);
        rep(i,n){
            auto [x1,y1,p1] = ju[i];
            rep(j,n){
                if(i == j)continue;
                if(p1*mid >=  d[P(min(i,j),max(i,j))])Graph[i].push_back(j);
            }
        }

        queue<int> todo;
        rep(i,n){
            vector<bool> visited(n,false);
            todo.push(i);
            while(!todo.empty()){
                auto l = todo.front(); todo.pop();
                if(visited[l])continue;
                visited[l] = true;
                for(auto next:Graph[l]){
                    todo.push(next);
                }
            }
            bool f = true;
            rep(j,n)f &= visited[j];
            flag |= f;
        }

        if(flag)right = mid;
        else left = mid;
        cout << left << " " << right << endl;
    }
    cout << right << endl;

    return 0;
}