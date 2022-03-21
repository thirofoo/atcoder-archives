/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30318288
 * Submitted at: 2022-03-21 11:50:47
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_cg
 * Result: RE
 * Execution Time: 203 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<ll> fact;
void factrize(ll k){
    for(ll i=1;i*i<=k;i++){
        if(k%i)continue;
        fact.push_back(i);
        if(i != (k/i))fact.push_back(k/i);
    }
}

int main() {
    ll k; cin >> k;
    factrize(k);
    sort(fact.begin(),fact.end());
    ll size = fact.size(),ans = 0;

    rep(i,size){
        for(int j=i;j<size;j++){
            if(k%(fact[i]*fact[j]) == 0 && k/(fact[i]*fact[j]) >= fact[j])ans++;
        }
    }
    cout << ans << endl;
    return 0;
}