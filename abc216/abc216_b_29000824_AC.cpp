/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc216/submissions/29000824
 * Submitted at: 2022-02-02 11:57:03
 * Problem URL: https://atcoder.jp/contests/abc216/tasks/abc216_b
 * Result: AC
 * Execution Time: 10 ms
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
    map<string,vector<string>> name;
    rep(i,n){
        string myo,na; cin >> myo >> na;
        if(count(name[myo].begin(),name[myo].end(),na))return cout << "Yes" << endl,0;
        else name[myo].push_back(na);
    }
    cout << "No" << endl;
    return 0;
}