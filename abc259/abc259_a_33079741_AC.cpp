/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc259/submissions/33079741
 * Submitted at: 2022-07-09 21:10:51
 * Problem URL: https://atcoder.jp/contests/abc259/tasks/abc259_a
 * Result: AC
 * Execution Time: 6 ms
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
    
    int n,m,x,t,d; cin >> n >> m >> x >> t >> d;
    if(m <= x){
        if(n <= x){
            if(n <= m)cout << t+abs(m-n)*d << endl;
            else cout << t-abs(m-n)*d << endl;
        }
        else{
            cout << t-abs(x-m)*d << endl;
        }
    }
    else{
        if(n >= m)cout << t << endl;
        else{
            if(n >= x)cout << t << endl;
            else cout << t+abs(x-n)*d << endl;
        }
    }
    
    return 0;
}