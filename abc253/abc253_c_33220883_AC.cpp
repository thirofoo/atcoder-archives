/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/33220883
 * Submitted at: 2022-07-14 20:31:23
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
    set<P> num;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            auto itr = num.lower_bound(P(x,0));
            if((*itr).first != x){
                num.insert(P(x,1));
            }
            else{
                num.erase(itr);
                num.insert(P(x,(*itr).second+1));
            }
        }
        else if(t == 2){
            int x,c; cin >> x >> c;
            auto itr = num.lower_bound(P(x,0));
            if((*itr).first == x){
                num.erase(itr);
                if((*itr).second > c)num.insert(P(x,(*itr).second-c));
            }
        }
        else{
            auto itr = num.end();
            itr--;
            cout << (*itr).first - (*num.begin()).first << endl;
        }
    }
    
    return 0;
}