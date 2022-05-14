/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc185/submissions/31651302
 * Submitted at: 2022-05-14 18:22:23
 * Problem URL: https://atcoder.jp/contests/abc185/tasks/abc185_f
 * Result: AC
 * Execution Time: 570 ms
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

int op(int a,int b){
    return a^b;
}

int e(){
    return 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,q; cin >> n >> q;
    segtree<int,op,e> sg(n+1);
    sg.set(n,0);
    rep(i,n){
        int b; cin >> b;
        sg.set(i,b);
    }
    while(q--){
        int t,x,y; cin >> t >> x >> y;
        if(t == 1)sg.set(x-1,sg.get(x-1)^y);
        else cout << sg.prod(x-1,y) << endl;
    }
    return 0;
}