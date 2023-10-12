/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc149/submissions/46474057
 * Submitted at: 2023-10-12 18:58:44
 * Problem URL: https://atcoder.jp/contests/abc149/tasks/abc149_d
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

     ll n,k,r,s,p; cin >> n >> k >> r >> s >> p;
    string t; cin >> t;
    ll ans = 0;
    vector<char> h(n);
    map<char,char> mp1;
    map<char,int> mp2;
    mp1['r'] = 'p', mp1['s'] = 'r', mp1['p'] = 's';
    mp2['r'] = p, mp2['s'] = r, mp2['p'] = s;
    rep(i,n){
        if(i-k < 0){
            h[i] = mp1[t[i]];
            ans += mp2[t[i]];
        }
        else{
            if(t[i] == 'r'){
                if(h[i-k] == 'p'){
                    if(i+k < n && t[i+k] == 's')h[i] = 's';
                    else h[i] = 'r';
                }
                else{
                    ans += p;
                    h[i] = 'p';
                }
            }
            else if(t[i] == 's'){
                if(h[i-k] == 'r'){
                    if(i+k < n && t[i+k] == 'p')h[i] = 'p';
                    else h[i] = 's';
                }
                else{
                    ans += r;
                    h[i] = 'r';
                }
            }
            else {
                if(h[i-k] == 's'){
                    if(i+k < n && t[i+k] == 'r')h[i] = 'r';
                    else h[i] = 'p';
                }
                else{
                    ans += s;
                    h[i] = 's';
                }
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}