/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc140/submissions/31718981
 * Submitted at: 2022-05-15 21:32:45
 * Problem URL: https://atcoder.jp/contests/arc140/tasks/arc140_a
 * Result: WA
 * Execution Time: 8 ms
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
    
    ll n,k; string s; cin >> n >> k >> s;
    enum_div(n);

    for(auto k:divisor){
        //周期kのサイクルを作る。
        int tmp = 0;
        rep(i,k){
            int t = 0;
            map<char,int> ch;
            rep(j,n/k){
                ch[s[j*k+i]]++;
            }
            rep(j,26)t = max(t,ch['a'+i]);
            tmp += t;
        }
        if(n-tmp <= k)return cout << k << endl,0;
    }

    return 0;
}