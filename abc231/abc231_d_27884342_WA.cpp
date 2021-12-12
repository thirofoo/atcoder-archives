/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc231/submissions/27884342
 * Submitted at: 2021-12-12 22:35:07
 * Problem URL: https://atcoder.jp/contests/abc231/tasks/abc231_d
 * Result: WA
 * Execution Time: 173 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m;
    cin >> n >> m;
    map<ll,ll> count;
    for(int i=1;i<n+1;i++)count[i] = 0;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        count[a]++;count[b]++;
    }
    ll oneD = 0,twoD = 0;
    for(int i=1;i<n+1;i++){
        if(count[i] == 1)oneD++;
        if(count[i] == 2 || count[i] == 0)twoD++;
    }
    if(oneD%2 == 0 && twoD == n-oneD)return cout << "Yes" << endl,0;
    cout << "No" << endl;
    return 0;
}