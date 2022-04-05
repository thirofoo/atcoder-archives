/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc195/submissions/30744161
 * Submitted at: 2022-04-06 00:46:56
 * Problem URL: https://atcoder.jp/contests/abc195/tasks/abc195_b
 * Result: AC
 * Execution Time: 9 ms
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
    cout << fixed << setprecision(10);
    ll a,b,w; cin >> a >> b >> w;
    w *= 1000;
    int mini = INT_MAX,maxi = INT_MAX;
    if(w%b == 0)mini = w/b;
    else{
        int d = w/b,r = w%b;
        if(d*(b-a) >= a-r)mini = d+1;
        else return cout << "UNSATISFIABLE" << endl,0;
    }
    if(w%a == 0)maxi = w/a;
    else{
        int d = w/a,r = w%a;
        if(d*(b-a) >= r)maxi = d;
        else return cout << "UNSATISFIABLE" << endl,0;
    }
    cout << mini << " " << maxi << endl;
    return 0;
}