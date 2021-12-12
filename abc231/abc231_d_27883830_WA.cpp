/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc231/submissions/27883830
 * Submitted at: 2021-12-12 22:11:51
 * Problem URL: https://atcoder.jp/contests/abc231/tasks/abc231_d
 * Result: WA
 * Execution Time: 182 ms
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
    vector<P> condition(0);
    map<ll,ll> count;
    // rep(i,n+1)count[i] = 0;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        condition.push_back(make_pair(a,b));
    }
    rep(i,n-m-1)condition.push_back(make_pair(i+n,i+n));
    rep(i,n-1){
        int a,b;
        tie(a,b) = condition[i];
        count[a]++;count[b]++;
    }
    ll oneD = 0,twoD = 0;
    rep(i,2*n){
        if(count[i] == 1)oneD++;
        if(count[i] == 2)twoD++;
    }
    if(oneD == 2 && twoD == n-2)return cout << "Yes" << endl,0;
    cout << "No" << endl;
    return 0;
}