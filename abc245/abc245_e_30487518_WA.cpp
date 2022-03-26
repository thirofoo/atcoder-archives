/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc245/submissions/30487518
 * Submitted at: 2022-03-27 00:10:07
 * Problem URL: https://atcoder.jp/contests/abc245/tasks/abc245_e
 * Result: WA
 * Execution Time: 4412 ms
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

int main() {
    int n,m; cin >> n >> m;
    vector<int> a(n),b(n),c(m),d(m);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,m)cin >> c[i];
    rep(i,m)cin >> d[i];

    set<P> size;
    map<P,int> num;
    rep(i,m){
        size.insert(P(c[i],d[i]));
        num[P(c[i],d[i])]++;
    }

    vector<P> choco;
    rep(i,n)choco.push_back(P(a[i],b[i]));
    sort(choco.begin(),choco.end(),[](P a,P b){
        return a.second < b.second;
    });

    rep(i,n){
        auto itr = size.lower_bound(choco[i]);
        while(itr != size.end()){
            if(num[*itr] && (*itr).second >= b[i]){
                num[*itr]--;
                break;
            }
            itr++;
        }
        if(itr == size.end())return cout << "No" << endl,0;
    }
    cout << "Yes" << endl;
    return 0;
}