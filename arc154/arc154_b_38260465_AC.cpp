/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc154/submissions/38260465
 * Submitted at: 2023-01-22 22:00:35
 * Problem URL: https://atcoder.jp/contests/arc154/tasks/arc154_b
 * Result: AC
 * Execution Time: 29 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string s,t; input(n,s,t);
    vector<ll> c1(26,0),c2(26,0);
    rep(i,n)c1[s[i]-'a']++;
    rep(i,n)c2[t[i]-'a']++;
    rep(i,26)if(c1[i] != c2[i])return print(-1),0;

    vector<vector<ll>> idx(26);
    rep(i,n)idx[t[i]-'a'].push_back(i);

    ll left = -1,right = n-1;
    while(right-left > 1){
        ll mid = (right+left)/2;
        bool f = true;
        ll now = 0;
        for(ll j=mid;j<n;j++){
            auto itr = lower_bound(idx[s[j]-'a'].begin(),idx[s[j]-'a'].end(),now);
            if(itr == idx[s[j]-'a'].end()){
                f = false;
                break;
            }
            now = *itr+1;
        }
        if(f)right = mid;
        else left = mid; 
    }
    print(right);
    
    return 0;
}