/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc247/submissions/30857112
 * Submitted at: 2022-04-10 21:12:18
 * Problem URL: https://atcoder.jp/contests/abc247/tasks/abc247_b
 * Result: WA
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<string, string> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    map<string,int> x,z;
    vector<P> w;
    
    rep(i,n){
        string a,b; cin >> a >> b;
        w.push_back(P(a,b));
        x[a]++; x[b]++;
    }

    rep(i,n){
        if(x[w[i].first] <= 1 && z[w[i].first] == 0){
            z[w[i].first]++;
        }
        else if(x[w[i].second] <= 1 && z[w[i].second] == 0){
            z[w[i].second]++;
        }
        else return cout << "No" << endl,0;
    }
    cout << "Yes" << endl;
    return 0;
}