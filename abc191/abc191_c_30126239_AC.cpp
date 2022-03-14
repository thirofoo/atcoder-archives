/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc191/submissions/30126239
 * Submitted at: 2022-03-14 19:57:16
 * Problem URL: https://atcoder.jp/contests/abc191/tasks/abc191_c
 * Result: AC
 * Execution Time: 7 ms
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

vector<int> mx = {0,0,1,1};
vector<int> my = {0,1,0,1};

int main() {
    int h,w; cin >> h >> w;
    vector<string> field(h);
    rep(i,h)cin >> field[i];
    int ans = 0;
    rep(i,h-1){
        rep(j,w-1){
            int cnt = 0;
            rep(k,4){
                if(field[i+mx[k]][j+my[k]] == '#')cnt++;
            }
            if(cnt == 1 || cnt == 3)ans++;
        }
    }
    cout << ans << endl;
    return 0;
}