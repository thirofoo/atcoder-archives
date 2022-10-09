/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc150/submissions/35544487
 * Submitted at: 2022-10-09 22:13:45
 * Problem URL: https://atcoder.jp/contests/arc150/tasks/arc150_a
 * Result: AC
 * Execution Time: 17 ms
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
    while(t--){
        ll n,k,now = 0,ans = 0; string s; input(n,k,s);
        ll right = k-1,one = 0,to = 0;
        rep(i,n)if(s[i] == '1')to++;
        rep(i,k){
            if(s[i] != '0')now++;
            if(s[i] == '1')one++;
        }
        while(right < n){
            if(now == k && (right-k+1 == 0 || s[right-k] != '1') && (right == n-1 || s[right+1] != '1')){
                if(to == one)ans++;
            }
            if(s[right-k+1] != '0')now--;
            if(right+1 < n && s[right+1] != '0')now++;
            if(s[right-k+1] == '1')one--;
            if(right+1 < n && s[right+1] == '1')one++;
            right++;
        }
        print((ans == 1 ? "Yes" : "No"));
    }
    
    return 0;
}