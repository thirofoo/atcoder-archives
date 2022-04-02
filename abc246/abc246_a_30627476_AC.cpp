/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc246/submissions/30627476
 * Submitted at: 2022-04-02 21:03:39
 * Problem URL: https://atcoder.jp/contests/abc246/tasks/abc246_a
 * Result: AC
 * Execution Time: 8 ms
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
    int x1,y1,x2,y2,x3,y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    map<int,int> a,b;
    a[x1]++;
    b[y1]++;
    a[x2]++;
    b[y2]++;
    a[x3]++;
    b[y3]++;
    if(a[x1] == 1)cout << x1 << " ";
    else if(a[x2] == 1)cout << x2 << " ";
    else if(a[x3] == 1)cout << x3 << " ";
    if(b[y1] == 1)cout << y1 << " ";
    else if(b[y2] == 1)cout << y2 << " ";
    else if(b[y3] == 1)cout << y3 << " ";
    cout << endl;
    return 0;
}