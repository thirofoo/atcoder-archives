/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc241/submissions/39328857
 * Submitted at: 2023-03-01 14:59:59
 * Problem URL: https://atcoder.jp/contests/abc241/tasks/abc241_e
 * Result: AC
 * Execution Time: 36 ms
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
    
    ll n,k; input(n,k);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    ll ans = 0;
    if(k <= n){
        while(k--)ans += a[ans%n];
        print(ans);
        return 0;
    }

    // b : 飴が X mod N 個の時の皿にある飴の数
    // turn : 何回目にxにたどり着いたか
    vector<ll> b(n,0),turn(n,0);
    ll now = 0,time = 1,total = 0;
    while(true){
        b[now] = total + a[now];
        turn[now] = time;
        if(b[(now+a[now])%n])break;
        total += a[now];
        now = (now+a[now])%n;
        time++;
    }

    ll next = (now+a[now])%n;
    k -= turn[next];
    ll T = turn[now]-turn[next]+1;
    ll T_num = b[now]-b[next]+a[next];
    ans = b[next] + T_num*(k/T);
    k %= T;
    now = next;
    while(k--){
        now = (now+a[now])%n;
        ans += a[now];
    }
    print(ans);
    
    return 0;
}