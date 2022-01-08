/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc234/submissions/28398868
 * Submitted at: 2022-01-08 21:30:58
 * Problem URL: https://atcoder.jp/contests/abc234/tasks/abc234_c
 * Result: AC
 * Execution Time: 4 ms
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
    ll k; cin >> k;
    string ans = "";
    bitset<100> bit(k);
    for(int i=99;i>=0;i--){
        if(bit.test(i)) ans.insert(ans.size(),"2");
        else ans.insert(ans.size(),"0");
    }
    while(ans[0] == '0')ans.erase(0,1);
    cout << ans << endl;
    return 0;
}