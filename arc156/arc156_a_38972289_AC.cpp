/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc156/submissions/38972289
 * Submitted at: 2023-02-18 21:19:52
 * Problem URL: https://atcoder.jp/contests/arc156/tasks/arc156_a
 * Result: AC
 * Execution Time: 22 ms
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
        ll n; string s; input(n,s);
        ll cnt = 0,idx = 0;
        rep(i,n){
            if(s[i] == '1'){
                cnt++;
                idx = i;
            }
        }
        if(cnt%2 == 1){
            print(-1);
            continue;
        }
        if(cnt == 2 && ((idx != n-1 && s[idx+1] == '1') || (idx != 0 && s[idx-1] == '1'))){
            if(n == 3)print(-1);
            else if(n == 4 && idx == 2)print(3);
            else print(2);
        }
        else print(cnt/2);
    }
    
    return 0;
}