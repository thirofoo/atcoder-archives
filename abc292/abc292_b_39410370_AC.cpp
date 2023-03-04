/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc292/submissions/39410370
 * Submitted at: 2023-03-04 21:05:13
 * Problem URL: https://atcoder.jp/contests/abc292/tasks/abc292_b
 * Result: AC
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
    
    ll n,q; input(n,q);
    vector<ll> cnt(n,0);
    while(q--){
        ll t,x; input(t,x); x--;
        if(t == 1){
            cnt[x] += 1;
        }
        else if(t == 2){
            cnt[x] += 2;
        }
        else{
            if(cnt[x] >= 2)print("Yes");
            else print("No");
        }
    }
    
    return 0;
}