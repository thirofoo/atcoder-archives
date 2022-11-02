/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc184/submissions/36156949
 * Submitted at: 2022-11-02 20:07:10
 * Problem URL: https://atcoder.jp/contests/abc184/tasks/abc184_f
 * Result: AC
 * Execution Time: 295 ms
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
    
    ll n,t; input(n,t);
    vector<ll> t1,t2,a(n);
    rep(i,n)input(a[i]);

    rep(i,(1LL << n/2)){
        ll time = 0;
        rep(j,n/2){
            if(i & (1LL << j)){
                time += a[j];
            }
        }
        t1.push_back(time);
    }
    rep(i,(1LL << (n-n/2))){
        ll time = 0;
        rep(j,n-n/2){
            if(i & (1LL << j)){
                time += a[n/2+j];
            }
        }
        t2.push_back(time);
    }
    sort(t1.begin(),t1.end());
    sort(t2.begin(),t2.end());
    ll ans = -LLONG_MAX;
    for(auto x:t1){
        auto itr = upper_bound(t2.begin(),t2.end(),t-x);
        if(itr == t2.begin() || x+*(itr-1) > t)continue;
        ans = max(ans,x+*(itr-1));
    }
    print(ans);
    
    return 0;
}