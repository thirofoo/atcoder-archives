/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc250/submissions/31520884
 * Submitted at: 2022-05-08 21:11:48
 * Problem URL: https://atcoder.jp/contests/abc250/tasks/abc250_b
 * Result: AC
 * Execution Time: 5 ms
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
    
    int n,a,b; cin >> n >> a >> b;
    string t1 = "",t2 = "",t3 = "",t4 = "";
    rep(i,b){
        t1 += ".";
        t2 += "#";
    }
    rep(i,n){
        if(i%2 == 0){
            t3 += t1;
            t4 += t2;
        }
        else{
            t3 += t2;
            t4 += t1;
        }    
    }
    rep(i,n){
        rep(j,a){
            if(i%2 == 0)cout << t3 << endl;
            else cout << t4 << endl;;
        }
    }
    return 0;
}