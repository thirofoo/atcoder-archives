/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30353476
 * Submitted at: 2022-03-22 23:27:27
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_f
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
typedef pair<char, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,k; string s; cin >> n >> k >> s;
    map<char,vector<int>> latter;
    rep(i,n)latter[s[i]].push_back(i+1);
    vector<vector<int>> next(26,vector<int>(n,INT_MAX));
    rep(i,26){
        int tmp = 0;
        for(auto k:latter['a'+i]){
            for(tmp;tmp<k;tmp++)next[i][tmp] = k;
        }
    }

    int now = k;
    string ans = "";
    rep(i,n){
        if(ans.size() == k)break;
        rep(j,26){
            if(n-next[j][i]+1 >= now){
                ans += 'a'+j;
                i = next[j][i]-1;
                now--; break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}