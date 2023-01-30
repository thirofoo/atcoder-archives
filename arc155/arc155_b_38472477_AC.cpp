/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc155/submissions/38472477
 * Submitted at: 2023-01-30 09:30:10
 * Problem URL: https://atcoder.jp/contests/arc155/tasks/arc155_b
 * Result: AC
 * Execution Time: 188 ms
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
    
    ll q,a,b; input(q,a,b);
    set<ll> st;
    st.insert(a+b);
    st.insert(a-b);
    while(q--){
        // 与式の最小値が0なのを忘れてた。
        ll t,c,d; input(t,c,d);
        if(t == 1){
            st.insert(c+d);
            st.insert(c-d);
        }
        else{
            auto itr = st.lower_bound(c);
            if(itr != st.end() && c <= *itr && *itr <= d)print(0);
            else{
                ll ans = LLONG_MAX;
                if(itr != st.begin()){
                    itr--;
                    ans = min(ans,abs(*itr-c));
                    itr++;
                }
                if(itr != st.end())ans = min(ans,abs(d-*itr));
                print(ans);
            }
        }
    }
    
    return 0;
}