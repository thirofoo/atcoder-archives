/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc231/submissions/28984285
 * Submitted at: 2022-02-01 11:32:57
 * Problem URL: https://atcoder.jp/contests/abc231/tasks/abc231_d
 * Result: AC
 * Execution Time: 52 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;

int main() {
    int n,m; cin >> n >> m;
    vector<int> dim(n+1);
    dsu d(n+1);
    for(int i=1;i<=m;i++){
        int a,b; cin >> a >> b;
        dim[a]++; dim[b]++;
        if(d.same(a,b))return cout << "No" << endl,0;
        d.merge(a,b);
        if(dim[a] == 3 || dim[b] == 3)return cout << "No" << endl,0;
    }
    cout << "Yes" << endl;
    return 0;
}