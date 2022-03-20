/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc244/submissions/30277047
 * Submitted at: 2022-03-20 21:10:29
 * Problem URL: https://atcoder.jp/contests/abc244/tasks/abc244_c
 * Result: AC
 * Execution Time: 25 ms
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
    set<int> a;
    for(int i=1;i<=2*n+1;i++)a.insert(i);
    while(true){
        cout << *a.begin() << endl;
        a.erase(*a.begin());
        int aoki; cin >> aoki;
        if(aoki == 0)return 0;
        a.erase(aoki);
    }
    return 0;
}