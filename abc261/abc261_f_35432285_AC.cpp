/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc261/submissions/35432285
 * Submitted at: 2022-10-06 19:59:53
 * Problem URL: https://atcoder.jp/contests/abc261/tasks/abc261_f
 * Result: AC
 * Execution Time: 223 ms
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
typedef pair<ll,vector<ll>> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

P invNum(ll n,vector<ll> &a){
    if(n == 1)return P(0,a);

    vector<ll> left(a.begin(),a.begin()+n/2);
    vector<ll> right(a.begin()+n/2,a.end());
    P l = invNum(n/2,left);
    P r = invNum(n-n/2,right);

    // score : 転倒数, v : sort済み配列
    vector<ll> v;
    ll score = l.first + r.first, i1 = 0,i2 = 0;
    while(i1 < n/2 || i2 < n-n/2){
        if(i1 == n/2){
            v.push_back(r.second[i2]);
            i2++;
        }
        else if(i2 == n-n/2){
            v.push_back(l.second[i1]);
            i1++;
        }
        else{
            if(l.second[i1] <= r.second[i2]){
                v.push_back(l.second[i1]);
                i1++;
            }
            else{
                score += n/2-i1;
                v.push_back(r.second[i2]);
                // leftの中でright[i2]より大きいものだけ転倒数↑
                i2++;
            }
        }
    }
    return P(score,v);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> c(n),x(n);
    vector<vector<ll>> color(n);
    rep(i,n)input(c[i]);
    rep(i,n)input(x[i]);
    rep(i,n)color[c[i]-1].push_back(x[i]);
    ll ans = invNum(n,x).first;
    rep(i,n){
        if(color[i].size() == 0)continue;
        ans -= invNum(color[i].size(),color[i]).first;
    }
    print(ans);
    
    return 0;
}