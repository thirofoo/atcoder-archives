/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc231/submissions/27883273
 * Submitted at: 2021-12-12 21:43:43
 * Problem URL: https://atcoder.jp/contests/abc231/tasks/abc231_d
 * Result: WA
 * Execution Time: 168 ms
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
    map<int,int> count;
    rep(i,n+1)count[i] = 0;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        condition.push_back(make_pair(a,b));
    }
    rep(i,m){
        int a,b;
        tie(a,b) = condition[i];
        count[a]++;count[b]++;
    }
    int oneD = 0;
    rep(i,n+1){
        if(count[i] == 1)oneD++;
        if(count[i] >= 3)return cout << "No" << endl,0;
    }
    if(oneD != 2)return cout << "No" << endl,0;
    cout << "Yes" << endl;
    return 0;
}