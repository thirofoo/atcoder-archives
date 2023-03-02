/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc242/submissions/39348113
 * Submitted at: 2023-03-02 13:04:52
 * Problem URL: https://atcoder.jp/contests/abc242/tasks/abc242_e
 * Result: AC
 * Execution Time: 50 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t; input(t);
    while(t--){
        ll n; string s; input(n,s);
        // 基本的に前半分が答えだが、境界だけ答えに入るか否か分からない
        mint ans = 0;
        rep(i,(n+1)/2){
            ans *= 26;
            ans += s[i]-'A';
        }
        ans++;
        reverse(s.begin(),s.begin()+(n/2));
        rep(i,n/2){
            if(s[i] == s[(n+1)/2+i])continue;
            if(s[i] > s[(n+1)/2+i])ans--;
            break;
        }
        print(ans.val());
    }
    
    return 0;
}