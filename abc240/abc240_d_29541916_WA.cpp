/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc240/submissions/29541916
 * Submitted at: 2022-02-20 22:24:21
 * Problem URL: https://atcoder.jp/contests/abc240/tasks/abc240_d
 * Result: WA
 * Execution Time: 348 ms
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
    int n,cnt = 0,ball = 0; cin >> n;
    stack<int> sta;
    while(n--){
        int a; cin >> a;
        if(a != ball){
            cnt = 1; sta.push(a);
            ball = a;
        }
        else{
            cnt++;
            if(cnt == a){
                rep(j,a-1)sta.pop();
                if(sta.empty())ball = 0;
                else ball = sta.top();
                cnt = 1;
            }
            else sta.push(a);
        }
        if(sta.empty())cout << 0 << endl;
        else cout << sta.size() << endl;
    }
    return 0;
}