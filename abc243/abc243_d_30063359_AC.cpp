/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc243/submissions/30063359
 * Submitted at: 2022-03-12 22:00:06
 * Problem URL: https://atcoder.jp/contests/abc243/tasks/abc243_d
 * Result: AC
 * Execution Time: 36 ms
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
    int n; ll x; cin >> n >> x;
    string s; cin >> s;
    string ans = "";
    int digit = 0;
    rep(i,63){
        if((ll)pow(2,i) <= x && x < (ll)pow(2,i+1)){
            digit = i;
            break;
        }
    }
    if(digit == 0)digit = 63;
    rep(i,digit+1){
        if(x & (1LL << i))ans += "1";
        else ans += "0";
    }
    reverse(ans.begin(),ans.end());
    rep(i,s.size()){
        if(s[i] == 'R')ans += "1";
        else if(s[i] == 'L')ans += "0";
        else ans.pop_back();
    }
    ll answer = 0;
    rep(i,ans.size()){
        answer *= 2;
        if(ans[i] == '1')answer += 1;
    }
    cout << answer << endl;
    return 0;
}