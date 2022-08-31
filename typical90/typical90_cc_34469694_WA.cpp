/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34469694
 * Submitted at: 2022-08-31 12:12:26
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_cc
 * Result: WA
 * Execution Time: 56 ms
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,k; input(n,k);
    vector<P> info;
    rep(i,n){
        ll a,b; cin >> a >> b;
        info.push_back(P(a,b));
    }
    sort(info.begin(),info.end());
    ll l = 0, r = 0,cnt = 0,ans = 0;
    while(r != n){
        auto [a1,b1] = info[l];
        auto [a2,b2] = info[r];
        if(a2-a1 > k){
            cnt--;
            ++l;
        }
        else{
            if(abs(b2-b1) <= k)cnt++;
            ans = max(ans,cnt);
            ++r;
        }
    }
    cout << ans << endl;
    
    return 0;
}