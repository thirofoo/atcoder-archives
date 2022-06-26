/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc143/submissions/32782329
 * Submitted at: 2022-06-26 22:59:54
 * Problem URL: https://atcoder.jp/contests/arc143/tasks/arc143_c
 * Result: WA
 * Execution Time: 31 ms
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

ll euclid(ll a,ll b){
    if(b != 0)return euclid(b,a%b);
    else return a;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,x,y; cin >> n >> x >> y;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    ll a1 = 0,a2 = 0;
    rep(i,n){
        a[i] %= (x+y);
        if(a[i] >= x && a[i] < x+y)a1++;
        else a2++;
    }
    if(a1 > a2)cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}