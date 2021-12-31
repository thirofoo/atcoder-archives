/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc220/submissions/28250240
 * Submitted at: 2021-12-31 10:38:54
 * Problem URL: https://atcoder.jp/contests/abc220/tasks/abc220_b
 * Result: WA
 * Execution Time: 9 ms
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

int baseK_to_base10(string a,int k){
    int tmp = 1,ans = 0;
    for(int i=a.size()-1;i>=0;i--){
        ans += tmp*(a[i]-'0');
        tmp *= k;
    }
    return ans;
}

int main() {
    int k; string a,b; cin >> k >> a >> b;
    cout << baseK_to_base10(a,k)*baseK_to_base10(b,k) << endl;
    return 0;
}