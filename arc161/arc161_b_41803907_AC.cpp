/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc161/submissions/41803907
 * Submitted at: 2023-05-28 21:21:52
 * Problem URL: https://atcoder.jp/contests/arc161/tasks/arc161_b
 * Result: AC
 * Execution Time: 53 ms
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
    
    ll t; input(t);
    set<ll> st;
    for(ll i=0;i<63;i++){
        for(ll j=i+1;j<63;j++){
            for(ll k=j+1;k<63;k++){
                st.insert( (1LL << i) + (1LL << j) + (1LL << k) );
            }
        }
    }

    rep(i,t){
        ll n; input(n);
        auto itr = st.upper_bound(n);
        if(itr == st.begin())print(-1);
        else{
            itr--;
            print(*itr);
        }
    }
    
    return 0;
}