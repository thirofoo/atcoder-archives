/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc153/submissions/38010469
 * Submitted at: 2023-01-14 21:49:09
 * Problem URL: https://atcoder.jp/contests/arc153/tasks/arc153_b
 * Result: AC
 * Execution Time: 150 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w; input(h,w);
    vector<string> a(h);
    vector<vector<char>> f(2*h,vector<char>(2*w));
    rep(i,h)input(a[i]);
    rep(i,2*h)rep(j,2*w)f[i][j] = a[i%h][j%w];

    ll q; input(q);
    bool flag = (q%2);

    P ans = P(0,0);
    while(q--){
        auto [x,y] = ans;
        ll b,c; input(b,c);

        x += b+h, y += c+w;
        x %= 2*h, y %= 2*w;

        x = 2*h-x;
        y = 2*w-y;

        ans = P(x,y);
    }

    auto [x,y] = ans;
    if(flag){
        for(ll i=2*h-x-1;i>=h-x;i--){
            for(ll j=2*w-y-1;j>=w-y;j--){
                cout << f[(i%(2*h) + 2*h)%(2*h)][(j%(2*w) + 2*w)%(2*w)];
            }
            print();
        }
    }
    else{
        for(ll i=x;i<x+h;i++){
            for(ll j=y;j<y+w;j++){
                cout << f[(i%(2*h) + 2*h)%(2*h)][(j%(2*w) + 2*w)%(2*w)];
            }
            print();
        }
    }
    
    return 0;
}