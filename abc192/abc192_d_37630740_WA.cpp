/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc192/submissions/37630740
 * Submitted at: 2022-12-30 16:34:58
 * Problem URL: https://atcoder.jp/contests/abc192/tasks/abc192_d
 * Result: WA
 * Execution Time: 7 ms
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
    
    string x; ll m; input(x,m);
    char d = x[0];
    for(char ch:x)if(d < ch)d = ch;
    
    ll left = d-'0'+1,right = 1e18+1;
    while(right-left > 1){
        ll mid = (right+left)/2;
        stack<ll> st;
        ll tmp = m;
        while(tmp){
            st.push(tmp%mid);
            tmp /= mid;
        }
        if(st.size() > x.size())left = mid;
        else if(st.size() < x.size())right = mid;
        else{
            bool f = true;
            for(char ch:x){
                char now = st.top(); st.pop();
                if(ch-'0' < now)break;
                else if(ch-'0' > now){
                    f = false;
                    break;
                }
            }
            if(f)left = mid;
            else right = mid;
        }
    }
    print(left-(d-'0'));
    
    return 0;
}