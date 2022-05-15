/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc140/submissions/31718056
 * Submitted at: 2022-05-15 21:26:22
 * Problem URL: https://atcoder.jp/contests/arc140/tasks/arc140_a
 * Result: WA
 * Execution Time: 3 ms
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

vector<ll> divisor;
void enum_div(ll n){
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
    
    int n,k; string s; cin >> n >> k >> s;
    enum_div(n);

    for(auto k:divisor){
        //周期kのサイクルを作る。
        int tmp = 0;
        rep(i,k){
            rep(j,n/k - 1){
                if(s[j*k+i] != s[(j+1)*k+i])tmp++;
            }
        }
        if(tmp <= k)return cout << k << endl,0;
    }

    return 0;
}