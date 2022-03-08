/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29949216
 * Submitted at: 2022-03-08 13:01:15
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_j
 * Result: AC
 * Execution Time: 334 ms
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
typedef modint1000000007 mint1;
typedef modint998244353 mint2;
#define rep(i, n) for(ll i = 0; i < n; i++)

int n,k;

double dfs(int cnt1,int cnt2,int cnt3,vector<vector<vector<double>>>& dp,vector<vector<vector<bool>>>& frag){
    //このやり方だと期待値が0の場合も考えてるから、別途fragが必要。
    if(frag[cnt1][cnt2][cnt3])return dp[cnt1][cnt2][cnt3];
    frag[cnt1][cnt2][cnt3] = true;

    //dp[cnt1][cnt2][cnt3]は,dp[cnt-1][cnt2][cnt3]の状態から追加で皿に1つ寿司があるものを食べる
    // => 追加で(最後に)食べる皿の選び方は,今まで食べてきた寿司1つの皿の数だけある => cnt1_C_1 = cnt1通り
    double v1 = (cnt1 > 0 ? dfs(cnt1-1,cnt2,cnt3,dp,frag)*((double)cnt1/n) : 0);
    //同様にして,dp[cnt1+1][cnt2-1][cnt3]の状態で,1つの寿司を食べた皿から更にもう一つ寿司を食べる遷移。
    double v2 = (cnt2 > 0 ? dfs(cnt1+1,cnt2-1,cnt3,dp,frag)*((double)cnt2/n) : 0);
    //以下同様の考え方。
    double v3 = (cnt3 > 0 ? dfs(cnt1,cnt2+1,cnt3-1,dp,frag)*((double)cnt3/n) : 0);

    //0個の皿を選んだ時を考慮する。
    dp[cnt1][cnt2][cnt3] = (1 + v1 + v2 + v3)/(1 - ((double)(n- cnt1 - cnt2 - cnt3)/n));

    return dp[cnt1][cnt2][cnt3];
}

int main() {
    cout << fixed << setprecision(10);
    cin >> n;
    vector<int> a(n);
    int cnt1 = 0,cnt2 = 0,cnt3 = 0;
    rep(i,n){
        cin >> a[i];
        switch(a[i]){
            case 1:cnt1++; break;
            case 2:cnt2++; break;
            case 3:cnt3++; break;
        }
    }
    //確立漸化式的な感じ
    //dp[i][j][k]:寿司が1つ、2つ、3つのった皿をi,j,k枚食べた時の期待値。
    vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(n+1,vector<double>(n+1,0)));
    vector<vector<vector<bool>>> frag(n+1,vector<vector<bool>>(n+1,vector<bool>(n+1,false)));
    frag[0][0][0] = true;

    cout << dfs(cnt1,cnt2,cnt3,dp,frag) << '\n';
    return 0;
}