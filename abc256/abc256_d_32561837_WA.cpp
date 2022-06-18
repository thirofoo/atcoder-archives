/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc256/submissions/32561837
 * Submitted at: 2022-06-18 21:57:49
 * Problem URL: https://atcoder.jp/contests/abc256/tasks/abc256_d
 * Result: WA
 * Execution Time: 121 ms
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
    
    int n; cin >> n;
    priority_queue<T,vector<T>,greater<T>> p1,p2;
    rep(i,n){
        int l,r; cin >> l >> r;
        p1.push(T(r,l,i));
        p2.push(T(l,r,i));
    }
    vector<bool> used(n,false);
    while(!p1.empty()){
        auto [r,l,i] = p1.top(); p1.pop();
        if(used[i])continue;
        used[i] = true;

        while(!p2.empty()){
            auto [nl,nr,ni] = p2.top();
            if(used[ni]){
                p2.pop();
                continue;
            }

            if(r >= nl){
                used[ni] = true;
                p2.pop();
                r = nr;
                l = min(l,nl);
            }
            else break;
        }
        cout << l << " " << r << endl;
    }

    return 0;
}