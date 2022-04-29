/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc196/submissions/31335137
 * Submitted at: 2022-04-29 12:55:33
 * Problem URL: https://atcoder.jp/contests/abc196/tasks/abc196_d
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

int H, W, A, B, ans = 0;
void dfs(int s,int a,int b,int now){
    if(s == H*W-1){
        ans++; return;
    }
    if(now & (1LL << s))return dfs(s+1,a,b,now);

    if(b)dfs(s+1,a,b-1,now | (1LL << s));
    if(a && s%W != W-1 && !(now & (1LL << s+1)))dfs(s+1,a-1,b,now | (1LL << s) | (1LL << s+1));
    if(a && s+W < W*H && !(now & (1LL << s+W)))dfs(s+1,a-1,b,now | (1LL << s) | (1LL << s+W));

    return;
}

int main(){
    cin >> H >> W >> A >> B;
    dfs(0, A, B, 0);
    cout << ans << endl;
}