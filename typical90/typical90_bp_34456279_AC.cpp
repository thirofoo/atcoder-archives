/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34456279
 * Submitted at: 2022-08-30 16:40:55
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bp
 * Result: AC
 * Execution Time: 117 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    //解説AC。天才。
    //クエリ系でもクエリ前後で一意性があるなら先読みしても全くモーマンタイ。
    ll n,q,Q; cin >> n >> q; Q = q;
    vector<ll> cnt(n,-1);
    queue<T> todo;
    dsu uf(n);
    while(q--) {
        ll t,x,y,v; cin >> t >> x >> y >> v; x--; y--;
        if(t == 0)cnt[y] = v;
        todo.push(T(t,x,y,v));
    }

    rep(i,n-1){
        if(cnt[i+1] != -1){
            if(cnt[i] == -1)cnt[i] = 0;
            cnt[i+1] -= cnt[i];
        }
    }
    
    //クエリ答えるpart
    while(!todo.empty()){
        auto [t,x,y,v] = todo.front(); todo.pop();
        if(t == 0)uf.merge(x,y);
        else{
            if(!uf.same(x,y))cout << "Ambiguous" << endl;
            else cout << cnt[y] + ( ((y-x)%2+2)%2 == 1 ? cnt[x]-v : -(cnt[x]-v) ) << endl;
        }
    }

    return 0;
}