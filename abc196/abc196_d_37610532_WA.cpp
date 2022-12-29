/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc196/submissions/37610532
 * Submitted at: 2022-12-29 14:11:47
 * Problem URL: https://atcoder.jp/contests/abc196/tasks/abc196_d
 * Result: WA
 * Execution Time: 10 ms
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

ll h,w;
ll dfs(ll state,ll now,ll a,ll b){
    if(state >= (1LL << h*w)-1)return 1;
    while(state & (1LL << now))now++;

    ll ans = 0;
    if(b != 0){
        // 1*1
        ans += dfs(state | 1LL << now,now,a,b-1);
    }
    if(a != 0){
        // 2*1横
        if(now%w != w-1){
            ans += dfs(state | (1LL << now) | (1LL << now+1),now,a-1,b);
        }
        // 2*1縦
        if(now/h + 1 != h){
            ans += dfs(state | (1LL << now) | (1LL << now+w),now,a-1,b);
        }
    }
    return ans;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a,b; input(h,w,a,b);
    print(dfs(0,0,a,b));
    
    return 0;
}