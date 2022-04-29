/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc149/submissions/31333508
 * Submitted at: 2022-04-29 11:09:31
 * Problem URL: https://atcoder.jp/contests/abc149/tasks/abc149_c
 * Result: AC
 * Execution Time: 8 ms
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

vector<bool> is_prime;
void Eratosthenes(int n){
    for(int i=2;i<=n;i++){
        if(!is_prime[i])continue;
        for(int j=2;i*j<=n;j++)is_prime[i*j] = false;
    }
}

int main() {
    ll x; cin >> x;
    is_prime.assign(2*x,true);
    Eratosthenes(2*x);
    while(!is_prime[x])x++;
    cout << x << endl;
    return 0;
}