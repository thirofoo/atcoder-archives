/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc133/submissions/28691378
 * Submitted at: 2022-01-22 21:59:03
 * Problem URL: https://atcoder.jp/contests/arc133/tasks/arc133_a
 * Result: WA
 * Execution Time: 67 ms
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
    queue<int> v;
    queue<int> ans;
    int m = 0;
    rep(i,n){
        int a; cin >> a;
        v.push(a);
        m = max(m,a);
    }
    while(!v.empty()){
        int a = v.front();
        v.pop();
        if(a == m)continue;
        ans.push(a);
    }
    while(!ans.empty()){
        int a = ans.front();
        ans.pop();
        cout << a << " ";
    }
    cout << endl;
    return 0;
}