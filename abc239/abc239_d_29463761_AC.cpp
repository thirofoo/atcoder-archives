/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc239/submissions/29463761
 * Submitted at: 2022-02-19 22:08:23
 * Problem URL: https://atcoder.jp/contests/abc239/tasks/abc239_d
 * Result: AC
 * Execution Time: 13 ms
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
    int a,b,c,d; cin >> a >> b >> c >> d;
    vector<bool> era(200,true);
    for(int i=2;i*i<=200;i++){
        if(!era[i])continue;
        for(int j=2;i*j<=200;j++)era[i*j] = false;
    }
    for(int i=a;i<=b;i++){
        bool frag = true;
        for(int j=c;j<=d;j++){
            if(era[i+j]){frag = false; break;}
        }
        if(frag)return cout << "Takahashi" << endl,0;
    }
    cout << "Aoki" << endl;
    return 0;
}