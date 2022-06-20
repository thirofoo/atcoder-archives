/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc142/submissions/32616500
 * Submitted at: 2022-06-20 11:46:43
 * Problem URL: https://atcoder.jp/contests/arc142/tasks/arc142_c
 * Result: WA
 * Execution Time: 13 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,m = -INT_MAX,next = -1; cin >> n;
    for(int i=3;i<=n;i++){
        cout << "? " << 1 << " " << i << endl;
        int d; cin >> d;
        if(m < d){
            m = d;
            next = i;
        }
    }
    int d1,d2;
    bool flag = false;
    for(int i=1;i<=n;i++){
        cout << "? " << next << " " << i << endl;
        int d; cin >> d;
        if(i == 1)d1 = d;
        else if(i == 2)d2 = d;
        else if(d1 == d || d2 == d || d1 == d2)flag = true;
    }
    if(!flag)cout << "! " << abs(d1-d2) << endl;
    else cout << "! " << d1+d2 << endl;


    return 0;
}