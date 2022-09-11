/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc148/submissions/34790972
 * Submitted at: 2022-09-11 21:46:24
 * Problem URL: https://atcoder.jp/contests/arc148/tasks/arc148_b
 * Result: TLE
 * Execution Time: 2262 ms
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
    
    ll n; string s; input(n,s);
    ll size = s.size();
    set<string> st;
    st.insert(s);
    rep(i,size){
        if(s[i] == 'd')continue;
        else{
            for(ll j=i;j<n;j++){
                string tmp = s;
                for(ll k=i;k<(j+i+1)/2;k++){
                    swap(tmp[k],tmp[j+i-k]);
                    if(tmp[k] == 'p')tmp[k] = 'd';
                    else tmp[k] = 'p';
                    if(tmp[j+i-k] == 'p')tmp[j+i-k] = 'd';
                    else tmp[j+i-k] = 'p';
                }
                if((j-i+1)%2 == 1){
                    if(tmp[(j+i)/2] == 'p')tmp[(j+i)/2] = 'd';
                    else tmp[(j+i)/2] = 'p';
                }
                st.insert(tmp);
            }
        }
    }
    print(*st.begin());
    
    return 0;
}