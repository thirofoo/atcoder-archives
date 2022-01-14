/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28506087
 * Submitted at: 2022-01-14 19:28:32
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bw
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
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<P> prime_factorize(ll n){
    ll tmp = n;
    vector<P> ans(0);
    for(ll i=2;i*i<=n;i++){
        if(n == 1)break;
        ll count = 0;
        while(n%i == 0){
            n /= i;
            count++;
        }
        if(count == 0)continue;
        ans.push_back(P(i,count));
    }
    if(n != 1 && n != tmp)ans.push_back(P(n,1));
    return ans;
}

int main() {
    ll n; cin >> n;
    vector<P> prime = prime_factorize(n);
    if(prime.empty())return cout << 0 << endl,0;
    ll count = 0;
    for(P k:prime){
        count += k.second;
    }
    for(int i=1;i<64;i++){
        if(count <= (1LL << i)) return cout << i << endl,0;
    }
    return 0;
}