/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc146/submissions/42738024
 * Submitted at: 2023-06-19 13:47:13
 * Problem URL: https://atcoder.jp/contests/abc146/tasks/abc146_f
 * Result: AC
 * Execution Time: 96 ms
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

//セグ木状に乗せる型。
using S = int;

S op(S a,S b){return min(a,b);} // operator(作用素)
S e(){return 1e9;} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
    string s; input(s);

    segtree<S,op,e> dp(n+1);
    dp.set(0,0);
    for(ll i=1;i<=n;i++){
        if(s[i] == '1')continue;
        ll pre = dp.prod(max(0ll,i-m),i);
        if(pre >= 1e9)continue;
        dp.set(i,pre+1);
    }
    if(dp.get(n) >= 1e9){
        print(-1);
        return 0;
    }
    ll now = dp.get(n)-1, r = n;
    vector<vector<ll>> idx(dp.get(n)+1,vector<ll>{});
    rep(i,n+1){
        if(dp.get(i) >= 1e9)continue;
        idx[dp.get(i)].push_back(i);
    }
    stack<ll> ans;
    while(now >= 0){
        ll ok = r-1, ng = -1;
        while(ok-ng > 1){
            ll mid = (ng+ok)/2;
            if(dp.prod(mid,r) >= now)ok = mid;
            else ng = mid;
        }
        auto itr = lower_bound(idx[now].begin(),idx[now].end(),max(ok,r-m));
        ans.push(r-(*itr));
        r = (*itr);
        now--;
    }
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
    print();
    
    return 0;
}