/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc155/submissions/38472137
 * Submitted at: 2023-01-30 08:50:55
 * Problem URL: https://atcoder.jp/contests/arc155/tasks/arc155_a
 * Result: WA
 * Execution Time: 14 ms
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
        // 解説AC
        ll n,k; string s; input(n,k,s);
        // S'の前min(n,k)文字が、revese(S)に一致する &&
        // S'の後min(n,k)文字が、revese(S)に一致する
        // には気づけたが、周期をnで解いてしまった。
        k %= (2*n);
        string ans = "";
        rep(i,k)ans += '0';
        rep(i,min(n,k))ans[i] = s[i];

        bool f = true;
        rep(i,min(n,k)){
            if(ans[k-1-i] == '0')continue;
            f &= (ans[k-1-i] == s[n-1-i]);
        }
        print(f ? "Yes" : "No");
    }
    
    return 0;
}