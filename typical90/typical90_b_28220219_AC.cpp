/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28220219
 * Submitted at: 2021-12-29 19:23:58
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_b
 * Result: AC
 * Execution Time: 181 ms
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

bool hantei(string s){
    int tmp = 0;
    rep(i,s.size()){
        if(s[i] == '(') tmp++;
        if(s[i] == ')') tmp--;
        if(tmp < 0)return false;
    }
    if(tmp == 0)return true;
    else return false;
}

int main() {
    int n; cin >> n;
    for(int i=0;i<(1 << n);i++){
        string s = "";
        for(int j=n-1;j>=0;j--){
            if((i & (1 << j)) == 0) s += "(";
            else s += ")";
        }
        if(hantei(s)) cout << s << endl;
    }
    return 0;
}