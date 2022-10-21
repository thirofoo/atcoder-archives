/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc182/submissions/35838423
 * Submitted at: 2022-10-21 23:03:37
 * Problem URL: https://atcoder.jp/contests/abc182/tasks/abc182_e
 * Result: AC
 * Execution Time: 346 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

// 右下左上の順番
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w,n,m; input(h,w,n,m);
    vector<set<ll>> ro(h),co(w);
    rep(i,h){
        ro[i].insert(-1);
        ro[i].insert(w);
    }
    rep(i,w){
        co[i].insert(-1);
        co[i].insert(h);
    }
    queue<P> todo;
    rep(i,n){
        ll a,b; input(a,b);
        a--; b--;
        todo.push(P(a,b));
    }
    rep(j,m){
        ll c,d; input(c,d);
        c--; d--;
        ro[c].insert(d);
        co[d].insert(c);
    }
    vector<vector<ll>> imos1(h+1,vector<ll>(w+1,0)),imos2(h+1,vector<ll>(w+1,0));
    while(!todo.empty()){
        auto [x,y] = todo.front(); todo.pop();
        auto itr1 = ro[x].lower_bound(y);
        auto itr2 = co[y].lower_bound(x);
        imos1[x][*itr1]--;
        itr1--;
        imos1[x][(*itr1)+1]++;
        imos2[*itr2][y]--;
        itr2--;
        imos2[(*itr2)+1][y]++;
    }
    rep(i,h){
        for(int j=1;j<=w;j++){
            imos1[i][j] += imos1[i][j-1];
        }
    }
    for(int i=1;i<=h;i++){
        rep(j,w){
            imos2[i][j] += imos2[i-1][j];
        }
    }
    ll ans = 0;
    rep(i,h)rep(j,w)if(imos1[i][j] || imos2[i][j])ans++;
    print(ans);
    
    return 0;
}