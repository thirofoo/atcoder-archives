/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/32015099
 * Submitted at: 2022-05-28 21:15:49
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_c
 * Result: AC
 * Execution Time: 206 ms
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
    
    int q; cin >> q;
    priority_queue<int> a1;
    priority_queue<int,vector<int>,greater<int>> a2;
    map<int,int> cnt;
    while(q--){
        int t; cin >> t;
        if(t == 1){ 
            int x; cin >> x;
            a1.push(x);
            a2.push(x);
            cnt[x]++;
        }
        else if(t == 2){
            int x,c; cin >> x >> c;
            c = min(c,cnt[x]);
            cnt[x] -= c;
        }
        else{
            while(!cnt[a1.top()])a1.pop();
            while(!cnt[a2.top()])a2.pop();
            cout << a1.top()-a2.top() << endl;
        }
    }
    return 0;
}