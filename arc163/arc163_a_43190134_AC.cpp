/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc163/submissions/43190134
 * Submitted at: 2023-07-02 21:29:12
 * Problem URL: https://atcoder.jp/contests/arc163/tasks/arc163_a
 * Result: AC
 * Execution Time: 16 ms
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
typedef pair<string, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t; input(t);
    while(t--){
        ll n; string s; input(n,s);

        bool f = false;
        rep(i,s.size()-1){
            string s1 = "", s2 = "";
            rep(j,s.size()){
                if(j <= i)s1 += s[j];
                else s2 += s[j];
            }
            if( s1 < s2 ){
                f = true;
                break;
            }
        }
        if(f)print("Yes");
        else print("No");
    }
    
    return 0;
}