/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc212/submissions/29163953
 * Submitted at: 2022-02-08 20:08:22
 * Problem URL: https://atcoder.jp/contests/abc212/tasks/abc212_b
 * Result: AC
 * Execution Time: 16 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    string x; cin >> x;
    bool frag = false;
    if(x[0] == x[1] && x[1] == x[2] && x[2] == x[3])return cout << "Weak" << endl,0;
    rep(i,3){
        if(x[i] != '9' && x[i+1] == x[i] + 1)continue;
        else if(x[i] != '9'){frag=true; break;}
        else{
            if(x[i+1] == '0')continue;
            else{frag=true; break;}
        }
    }
    if(frag)cout << "Strong" << endl;
    else cout << "Weak" << endl;
    return 0;
}