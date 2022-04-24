/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc249/submissions/31220662
 * Submitted at: 2022-04-24 09:48:42
 * Problem URL: https://atcoder.jp/contests/abc249/tasks/abc249_a
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

int main() {
    int a,b,c,d,e,f,x; cin >> a >> b >> c >> d >> e >> f >> x;
    int takahashi = 0,aoki = 0,t = 0;
    while(true){
        if(x < a + t){
            if(x > t)takahashi += (x-t)*b;
            break;
        }
        else{
            takahashi += a*b;
            t += a;
        }
        t += c;
    }
    t = 0;
    while(true){
        if(x < d + t){
            if(x > t)aoki += (x-t)*e;
            break;
        }
        else{
            aoki += d*e;
            t += d;
        }
        t += f;
    }
    if(takahashi == aoki)cout << "Draw" << endl;
    else cout << (takahashi > aoki ? "Takahashi" : "Aoki") << endl;
    return 0;
}