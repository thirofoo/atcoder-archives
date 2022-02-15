/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc215/submissions/29345776
 * Submitted at: 2022-02-15 12:05:50
 * Problem URL: https://atcoder.jp/contests/abc215/tasks/abc215_d
 * Result: WA
 * Execution Time: 219 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

map<int,int> ans;
 
vector<int> prime_fact(ll n){
    vector<int> prime;
    if(n == 1)return prime;
    ll tmp = n;
    for(int i=2;i*i<=tmp;i++){
        if(n%i == 0){
            prime.push_back(i);
            while(n%i == 0)n /= i;
        }
    }
    if(n != 1)prime.push_back(n);
    return prime;
}

int main() {
    ll n,m; cin >> n >> m;
    vector<int> b;
    rep(i,n){
        ll a; cin >> a;
        if(ans.count(a))continue;
        vector<int> tmp = prime_fact(a);
        for(auto k:tmp){
            if(ans.count(k))continue;
            for(int j=1;j*k<=m;j++)ans[j*k]++;
        }
    }
    for(int i=1;i<=m;i++)if(ans[i] == 0)b.push_back(i);
    cout << b.size() << endl;
    rep(i,b.size())cout << b[i] << endl;
    return 0;
}