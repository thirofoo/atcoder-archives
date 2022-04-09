/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc138/submissions/30820337
 * Submitted at: 2022-04-09 22:19:55
 * Problem URL: https://atcoder.jp/contests/arc138/tasks/arc138_b
 * Result: AC
 * Execution Time: 38 ms
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
    int n,cnt = 0; cin >> n;
    deque<int> a;
    rep(i,n){
        int x; cin >> x;
        a.push_back(x);
    }
    while(!a.empty()){
        while(!a.empty() && a.back() == (cnt%2 == 0 ? 0 : 1))a.pop_back();

        if(a.empty() || a.front() == (cnt%2 == 0 ? 1 : 0))break;
        else a.pop_front();
        cnt++;
    }
    if(a.empty())cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}