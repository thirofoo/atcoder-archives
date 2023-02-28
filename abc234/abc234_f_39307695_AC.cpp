/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc234/submissions/39307695
 * Submitted at: 2023-02-28 15:29:19
 * Problem URL: https://atcoder.jp/contests/abc234/tasks/abc234_f
 * Result: AC
 * Execution Time: 1313 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long double ld;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef modint998244353 mint;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; input(s);
    vector<int> num(26,0);
    int size = s.size();
    rep(i,size)num[s[i]-'a']++;
    vector<mint> kaizyo(size+1,0);
    kaizyo[0] = 1;
    for(int i=1;i<=size;i++)kaizyo[i] = kaizyo[i-1]*i;

    vector<vector<mint>> dp(27,vector<mint>(size+1,0));
    dp[0][0] = 1;
    rep(i,26){
        for(int j=0;j<=size;j++){
            if(dp[i][j] == 0)continue;
            for(int k=0;k<=num[i];k++){
                if(j+k > size)break;
                dp[i+1][j+k] += dp[i][j]/kaizyo[k];
            }
        }
    }
    mint ans = 0;
    for(int i=1;i<=size;i++){
        ans += dp[26][i]*kaizyo[i];
    }
    print(ans.val());
    
    return 0;
}