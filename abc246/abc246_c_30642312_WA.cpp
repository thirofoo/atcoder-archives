/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc246/submissions/30642312
 * Submitted at: 2022-04-02 21:22:47
 * Problem URL: https://atcoder.jp/contests/abc246/tasks/abc246_c
 * Result: WA
 * Execution Time: 101 ms
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
    int n,k,x; cin >> n >> k >> x;
    priority_queue<int> v;
    rep(i,n){
        int a; cin >> a;
        v.push(a);
    }

    while(k){
        int tmp = v.top();
        if(tmp <= x)break;
        v.pop();
        int a = tmp/x;
        if(k >= a){
            k -= a;
            tmp %= x;
        }
        else{
            k = 0;
            tmp -= k*x;
        }
        if(tmp == 0)tmp = x;
        v.push(tmp);
    }

    ll ans = 0;
    while(!v.empty()){
        if(k)v.pop(),k--;
        else ans += v.top(),v.pop();
    }
    cout << ans << endl;
    return 0;
}