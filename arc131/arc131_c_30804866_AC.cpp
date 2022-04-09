/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc131/submissions/30804866
 * Submitted at: 2022-04-09 17:45:44
 * Problem URL: https://atcoder.jp/contests/arc131/tasks/arc131_c
 * Result: AC
 * Execution Time: 407 ms
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

int cnt = 0;
set<int> num;

void solve(int now){
    bool frag = true;
    for(auto k:num){
        if(!frag)break;
        if(num.count(now^k))continue;
        num.erase(k); cnt++;
        solve(now^k); frag = false;
    }
    if(frag){
        if(cnt%2 == 0)cout << "Lose" << endl;
        else cout << "Win" << endl;
        return;
    }
}

int main() {
    int n,now = 0; cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        num.insert(a[i]);
        now ^= a[i];
    }
    if(num.count(now))cout << "Win" << endl;
    else solve(now);
    return 0;
}