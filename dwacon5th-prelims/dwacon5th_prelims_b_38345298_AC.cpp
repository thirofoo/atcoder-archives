/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dwacon5th-prelims/submissions/38345298
 * Submitted at: 2023-01-27 10:00:04
 * Problem URL: https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_b
 * Result: AC
 * Execution Time: 250 ms
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

    vector<vector<bool>> bit(n*(n+1)/2,vector<bool>(64,0));
    ll idx = 0;
    rep(i,n){
        ll now = 0;
        for(ll j=i;j<n;j++){
            now += a[j];
            ll tmp = now,dig = 0;
            while(tmp){
                bit[idx][63-dig] = (1 & tmp);
                tmp >>= 1;
                dig++;
            }
            idx++;
        }
    }

    vector<bool> except(n*(n+1)/2,false);
    ll ans = 0;
    rep(i,64){
        ans *= 2;
        ll pop_cnt = 0;
        rep(j,n*(n+1)/2){
            if(bit[j][i] && !except[j]){
                pop_cnt++;
            }
        }
        if(pop_cnt >= k){
            rep(j,n*(n+1)/2){
                if(!(bit[j][i] && !except[j])){
                    except[j] = true;
                }
            }
            ans++;
        }
    }
    print(ans);
    
    return 0;
}