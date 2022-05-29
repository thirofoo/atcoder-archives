/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc141/submissions/32092374
 * Submitted at: 2022-05-29 22:40:35
 * Problem URL: https://atcoder.jp/contests/arc141/tasks/arc141_a
 * Result: AC
 * Execution Time: 46 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

void enum_div(ll n,vector<ll>& divisor){
    divisor.push_back(1);
    if(n != 1)divisor.push_back(n);
    for(ll i=2;i*i<=n;i++){
        if(n%i)continue;
        divisor.push_back(i);
        if(i != n/i)divisor.push_back(n/i);
    }
    sort(divisor.begin(),divisor.end());
    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        vector<ll> divisor;
        string n,ans = ""; cin >> n;
        ll size = n.size();
        rep(i,size-1)ans += "9";

        enum_div(size,divisor);
        divisor.pop_back();

        for(auto k:divisor){
            string tmp1 = "",tmp2 = "",tmp3 = "";
            rep(i,k)tmp1 += n[i];
            rep(i,size/k)tmp2 += tmp1;

            ll t = stoll(tmp1)-1;
            tmp1 = to_string(t);
            rep(i,size/k)tmp3 += tmp1;

            ll a = stoll(ans),T2 = stoll(tmp2),T3 = stoll(tmp3),N = stoll(n);
            if(T2 <= N){
                if(T2 >= a)ans = tmp2;
            }
            else if(T3 <= N){
                if(T3 >= a)ans = tmp3;
            }
        }
        cout << ans << endl;
    }
    return 0;
}