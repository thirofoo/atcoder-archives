/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/32904050
 * Submitted at: 2022-07-02 21:27:56
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_c
 * Result: RE
 * Execution Time: 277 ms
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
    
    int n,q,now = 0;string s; cin >> n >> q >> s;
    deque<char> que;
    rep(i,n)que.push_back(s[i]);
    while(q--){
        int t,x; cin >> t >> x;
        if(t == 1){
            now += n-x;
        }
        else{
            x--;
            cout << que[(now+x)%n] << endl;
        }
    }    
    
    return 0;
}