/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc243/submissions/30048389
 * Submitted at: 2022-03-12 21:28:18
 * Problem URL: https://atcoder.jp/contests/abc243/tasks/abc243_c
 * Result: AC
 * Execution Time: 221 ms
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
    int n; cin >> n;
    vector<P> place(n);
    rep(i,n){
        int x,y; cin >> x >> y;
        place[i] = P(x,y);
    }
    string s; cin >> s;

    map<int,int> m;
    rep(i,n){
        if(s[i] == 'R')continue;
        auto [x,y] = place[i];
        m[y] = max(m[y],x);
    }
    rep(i,n){
        if(s[i] == 'L')continue;
        auto [x,y] = place[i];
        if(x < m[y]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}