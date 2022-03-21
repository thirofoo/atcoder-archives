/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30318180
 * Submitted at: 2022-03-21 11:44:12
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_cg
 * Result: CE
 * Execution Time: None ms
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
    for(ll i=1;i*i<=k){
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
            ans += size-j;
        }
    }
    cout << ans << endl;
    return 0;
}