/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc079/submissions/29855213
 * Submitted at: 2022-03-05 15:08:05
 * Problem URL: https://atcoder.jp/contests/abc079/tasks/abc079_c
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
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<string> op = {"+","-"};

int main() {
    string a; cin >> a;
    for(auto k:op){
        for(auto l:op){
            for(auto m:op){
                int tmp = a[0]-'0';
                tmp += (k == "+" ? a[1]-'0' : -(a[1]-'0'));
                tmp += (l == "+" ? a[2]-'0' : -(a[2]-'0'));
                tmp += (m == "+" ? a[3]-'0' : -(a[3]-'0'));
                if(tmp == 7){
                    cout << a[0] << k << a[1] << l << a[2] << m << a[3] << "=" << 7 << '\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}