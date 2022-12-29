/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/37615989
 * Submitted at: 2022-12-29 19:34:07
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_e
 * Result: AC
 * Execution Time: 56 ms
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

ll euclid(ll a,ll b){
    if(b != 0)return euclid(b,a%b);
    else return a;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,k; input(n,k);
    vector<P> edge;
    rep(i,n){
        ll a,b; input(a,b);
        edge.push_back(P(a,b));
    }
    if(k == 1)return print("Infinity"),0;

    // 2点を通る直線を列挙 => 各直線に対して何個の頂点が乗ってるかを調べる
    set<T> line;
    rep(i,n){
        auto [x1,y1] = edge[i];
        for(ll j=i+1;j<n;j++){
            auto [x2,y2] = edge[j];
            ll dx = x1-x2,dy = y1-y2;
            ll tmp = euclid(dx,euclid(dy,dx*y1-dy*x1));
            line.insert(T(dy/tmp,dx/tmp,(dx*y1-dy*x1)/tmp));
        }
    }
    ll ans = 0;
    for(auto [a,b,c]:line){
        ll on = 0;
        rep(i,n){
            auto [x,y] = edge[i];
            if(a*x-b*y+c == 0)on++;
        }
        if(on >= k)ans++;
    }
    print(ans);
    
    return 0;
}