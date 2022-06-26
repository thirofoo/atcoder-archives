/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc127/submissions/32761514
 * Submitted at: 2022-06-26 10:59:23
 * Problem URL: https://atcoder.jp/contests/arc127/tasks/arc127_a
 * Result: WA
 * Execution Time: 9 ms
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

ll solve(ll s){
    if(s == 1)return 1;
    else return pow(10,s-1)+solve(s-1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    string nstr = to_string(n);
    ll ans = 0,size = nstr.size();
    
    rep(i,size){
        if(nstr[i] != '1'){
            ans += solve(size-i);
            break;
        }
        else{
            string tmp = "";
            for(int j=i;j<size;j++)tmp += nstr[j];
            ans += stoll(tmp)-(ll)pow(10LL,size-i-1)+1;
        }
    }

    for(int j=size-1;j>=1;j--)ans += solve(j);
    cout << ans << endl;

    return 0;
}