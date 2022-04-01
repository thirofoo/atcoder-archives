/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc190/submissions/30611403
 * Submitted at: 2022-04-02 00:17:12
 * Problem URL: https://atcoder.jp/contests/abc190/tasks/abc190_d
 * Result: AC
 * Execution Time: 18 ms
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

vector<P> fact;
void factorize(ll n){
    ll a = n;
    for(ll i=2;i*i<=n;i++){
        int cnt = 0;
        if(a%i)continue;
        while(a%i == 0){
            cnt++; a /= i;
        }
        fact.push_back(P(i,cnt));
    }
    if(a != 1)fact.push_back(P(a,1));
}

int main() {
    ll n; cin >> n;
    factorize(n);
    ll ans = 1;
    for(auto [a,b]:fact){
        if(a%2)ans *= b+1;
    }
    cout << ans*2 << endl;

    return 0;
}