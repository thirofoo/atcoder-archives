/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc128/submissions/28631351
 * Submitted at: 2022-01-19 16:52:24
 * Problem URL: https://atcoder.jp/contests/abc128/tasks/abc128_b
 * Result: AC
 * Execution Time: 9 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    map<string,vector<P>> review;
    rep(i,n){
        string s; int p; cin >> s >> p;
        review[s].push_back(P(p,i+1));
        sort(review[s].begin(),review[s].end());
        reverse(review[s].begin(),review[s].end());
    }
    for(auto k:review){
        rep(i,k.second.size()){
            cout << k.second[i].second << endl;
        }
    }
    return 0;
}