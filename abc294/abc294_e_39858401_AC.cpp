/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc294/submissions/39858401
 * Submitted at: 2023-03-19 21:21:00
 * Problem URL: https://atcoder.jp/contests/abc294/tasks/abc294_e
 * Result: AC
 * Execution Time: 65 ms
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
    
    ll L,n1,n2; input(L,n1,n2);
    vector<P> cut;
    vector<ll> s1,s2;
    ll now = 0;
    rep(i,n1){
        ll v,l; input(v,l);
        now += l;
        cut.push_back(P(now,1));
        s1.push_back(v);
    }
    now = 0;
    rep(i,n2){
        ll v,l; input(v,l);
        now += l;
        cut.push_back(P(now,2));
        s2.push_back(v);
    }
    sort(cut.begin(),cut.end());

    ll ans = 0;
    now = 0;
    ll now1 = s1[0],now2 = s2[0];
    ll i1 = 0,i2 = 0;
    for(auto [l,i]:cut){
        if(now1 == now2)ans += l-now;
        now = l;
        if(i == 1){
            i1++;
            now1 = s1[i1];
        }
        else{
            i2++;
            now2 = s2[i2];
        }
    }
    print(ans);
    
    return 0;
}