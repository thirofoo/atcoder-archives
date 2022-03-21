/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30318866
 * Submitted at: 2022-03-21 12:25:57
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_b
 * Result: AC
 * Execution Time: 54 ms
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
    int n,ans = 0; cin >> n;
    for(int i=(1 << n)-1;i>=0;i--){
        int cnt1 = 0,cnt2 = 0;
        bool frag = true;
        for(int j=n-1;j>=0;j--){
            if(i & (1 << j))cnt1++;
            else cnt2++;
            if(cnt1 >= cnt2)continue;
            frag = false; break;
        }
        if(frag && cnt1 == cnt2){
            for(int j=n-1;j>=0;j--){
                cout << (i & (1 << j) ? '(' : ')');
            }
            cout << endl;
        }
    }
    return 0;
}