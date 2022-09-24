/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc270/submissions/35136893
 * Submitted at: 2022-09-24 22:39:52
 * Problem URL: https://atcoder.jp/contests/abc270/tasks/abc270_d
 * Result: RE
 * Execution Time: 699 ms
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

ll n,k,ans = 0;
vector<ll> a;
void dfs(ll p,ll now,ll cand,int idx){
    if(now == 0){
        ans = max(ans,cand);
        return;
    }
    for(int i=idx;i<k;i++){
        if(now >= a[i]){
            dfs(p+1,now-a[i],cand+(p%2 == 0 ? a[i] : 0),i);
            break;
        }
        else{
            dfs(p+1,now-a[i],cand+(p%2 == 0 ? a[i] : 0),i);
            if(i != 0)dfs(p+1,now-a[i-1],cand+(p%2 == 0 ? a[i-1] : 0),i-1);
            break;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(n,k);
    a.assign(k,0);
    rep(i,k)input(a[i]);
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    dfs(0,n,0,0);
    print(ans);
    
    return 0;
}