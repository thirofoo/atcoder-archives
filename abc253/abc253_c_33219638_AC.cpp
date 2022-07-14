/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/33219638
 * Submitted at: 2022-07-14 19:11:13
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_c
 * Result: AC
 * Execution Time: 211 ms
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
    
    int q,size = 0; cin >> q;
    map<int,int> cnt;
    priority_queue<int> ma;
    priority_queue<int,vector<int>,greater<int>> mi;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            ma.push(x);
            mi.push(x);
            cnt[x]++;
        }
        else if(t == 2){
            int x,c; cin >> x >> c;
            cnt[x] = max(cnt[x]-c,0);
        }
        else{
            while(!cnt[ma.top()])ma.pop();
            while(!cnt[mi.top()])mi.pop();
            cout << ma.top() - mi.top() << endl;
        }
    }
    
    return 0;
}