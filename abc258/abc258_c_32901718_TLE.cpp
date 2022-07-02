/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/32901718
 * Submitted at: 2022-07-02 21:23:12
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_c
 * Result: TLE
 * Execution Time: 2205 ms
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
    
    int n,q;string s; cin >> n >> q >> s;
    deque<char> que;
    rep(i,n)que.push_back(s[i]);
    while(q--){
        int t,x; cin >> t >> x;
        if(t == 1){
            while(x--){
                que.push_front(que.back());
                que.pop_back();
            }
        }
        else{
            x--;
            cout << que[x] << endl;
        }
    }    
    
    return 0;
}