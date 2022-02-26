/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc241/submissions/29715458
 * Submitted at: 2022-02-26 23:31:02
 * Problem URL: https://atcoder.jp/contests/abc241/tasks/abc241_d
 * Result: AC
 * Execution Time: 403 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int q; cin >> q;
    multiset<ll> a;
    rep(i,q){
        int t; cin >> t;
        if(t == 1){
            ll x; cin >> x;
            a.insert(x);
        }
        else if(t == 2){
            ll x,k; cin >> x >> k;
            auto itr = a.upper_bound(x);
            bool frag = false;
            for(int j=1;j<=k;j++){
                if(itr == a.begin()){frag = true; break;}
                itr--;
            }
            if(frag)cout << -1 << endl;
            else cout << *itr << endl;
        }
        else{
            ll x,k; cin >> x >> k;
            auto itr = a.lower_bound(x);
            if(itr == a.end())cout << -1 << endl;
            else{
                bool frag = false;
                for(int j=1;j<=k-1;j++){
                    itr++;
                    if(itr == a.end()){frag = true; break;}
                }
                if(frag)cout << -1 << endl;
                else cout << *itr << endl;
            }
        }
    }
    
    return 0;
}