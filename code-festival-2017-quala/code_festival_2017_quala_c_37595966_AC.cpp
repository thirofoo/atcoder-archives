/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/code-festival-2017-quala/submissions/37595966
 * Submitted at: 2022-12-28 17:13:03
 * Problem URL: https://atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_c
 * Result: AC
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
    
    ll h,w; input(h,w);
    vector<string> f(h);
    rep(i,h)input(f[i]);
    vector<ll> cnt(26,0);
    rep(i,h)rep(j,w)cnt[f[i][j]-'a']++;
    if(h%2 == 0 && w%2 == 0){
        rep(i,26)if(cnt[i]%4 != 0)return print("No"),0;
        print("Yes");
    }
    else if(h%2 && w%2){
        ll f1 = 0,f2 = 0;
        rep(i,26){
            if(cnt[i]%2 != 0){
                f2++;
                if((cnt[i]-1)%4 != 0)f1++;
            }
            else if(cnt[i]%4 != 0)f1++;
        }
        print(f1 <= (h-1)/2 + (w-1)/2 && f2 == 1 ? "Yes" : "No");
    }
    else if(h%2){
        ll f = 0;
        rep(i,26){
            if(cnt[i]%2 != 0)return print("No"),0;
            if(cnt[i]%4 != 0)f++;
        }
        print(f <= w/2 ? "Yes" : "No");
    }
    else{
        ll f = 0;
        rep(i,26){
            if(cnt[i]%2 != 0)return print("No"),0;
            if(cnt[i]%4 != 0)f++;
        }
        print(f <= h/2 ? "Yes" : "No");
    }
    
    return 0;
}