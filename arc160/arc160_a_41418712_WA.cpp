/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc160/submissions/41418712
 * Submitted at: 2023-05-14 21:49:44
 * Problem URL: https://atcoder.jp/contests/arc160/tasks/arc160_a
 * Result: WA
 * Execution Time: 276 ms
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

bool f = true;
ll n,k,cnt = 1;
vector<ll> a,ans,tmp;
vector<bool> used;
void dfs(ll now, ll dig){
    // now : 今扱ってる数字
    // dig : 今扱ってる桁
    // cnt : 何番目の数列か
    used[now] = true;
    tmp.push_back(now);

    if(dig == n-1){
        if(cnt >= k && f){
            rep(i,n)ans.push_back(tmp[i]);
            f = false;
        }
        cnt += n;
        used[now] = false;
        tmp.pop_back();
        return;
    }
    if(a[dig] != now){
        if(cnt >= k && f){
            ll idx = 0;
            rep(i,n){
                if(a[i] == now)idx = i;
                ans.push_back(a[i]);
            }
            reverse(ans.begin()+dig,ans.begin()+idx+1);
            f = false;
        }
        cnt++;
        used[now] = false;
        tmp.pop_back();
        return;
    }

    for(ll i=1;i<=n;i++){
        if(used[i])continue;
        dfs(i,dig+1);
    }
    used[now] = false;
    tmp.pop_back();
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(n,k);
    a.assign(n,0);
    used.assign(n+1,false);
    rep(i,n)input(a[i]);
    for(ll i=1;i<=n;i++)dfs(i,0);
    
    for(auto ele:ans)cout << ele << " ";
    // rep(i,n)cout << ans[i] << " ";
    print();
    
    return 0;
}