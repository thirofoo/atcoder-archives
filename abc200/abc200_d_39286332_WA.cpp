/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc200/submissions/39286332
 * Submitted at: 2023-02-27 15:26:23
 * Problem URL: https://atcoder.jp/contests/abc200/tasks/abc200_d
 * Result: WA
 * Execution Time: 13 ms
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
    
    ll n; input(n);
    vector<ll> a(n);
    rep(i,n)input(a[i]);

    rep(i,n){
        if(a[i]%200 == 0){
            print("Yes");
            if(i == 0){
                print(1,1);
                print(2,1,2);
            }
            else {
                print(1,i);
                print(2,i,i+1);
            }
            return 0;
        }
    }

    vector<vector<bool>> dp(n+1,vector<bool>(200,false));
    vector<vector<ll>> pre(n+1,vector<ll>(200,-1));
    vector<vector<vector<ll>>> route(200);
    dp[0][0] = true;
    rep(i,n){
        rep(j,200){
            if(!dp[i][j])continue;
            dp[i+1][j] = true;
            pre[i+1][j] = j;
            dp[i+1][(j+a[i])%200] = true;
            pre[i+1][(j+a[i])%200] = j;
            vector<ll> tmp_route;
            ll now_x = i+1,now_y = (j+a[i])%200;
            while(pre[now_x][now_y] != -1){
                if(pre[now_x][now_y] != now_y){
                    tmp_route.emplace_back(now_x);
                }
                now_y = pre[now_x][now_y];
                now_x--;
            }
            route[(j+a[i])%200].emplace_back(tmp_route);
            if(route[(j+a[i])%200].size() > 1){
                print("Yes");
                for(auto r:route[(j+a[i])%200]){
                    reverse(r.begin(),r.end());
                    cout << r.size() << " ";
                    for(auto ele:r)cout << ele << " ";
                    print();
                }
                return 0;
            }
        }
    }
    print("No");
    
    return 0;
}