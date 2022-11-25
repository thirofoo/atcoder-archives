/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc138/submissions/36769851
 * Submitted at: 2022-11-25 17:04:16
 * Problem URL: https://atcoder.jp/contests/abc138/tasks/abc138_e
 * Result: AC
 * Execution Time: 26 ms
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
    
    string s,t; input(s,t);
    vector<vector<ll>> idx(26,vector<ll>{});
    rep(i,s.size()){
        idx[s[i]-'a'].push_back(i);
        idx[s[i]-'a'].push_back(i+s.size());
    }
    rep(i,26)sort(idx[i].begin(),idx[i].end());
    ll ans = -1,s1 = t.size(),s2 = s.size();
    rep(i,s1){
        auto itr = upper_bound(idx[t[i]-'a'].begin(),idx[t[i]-'a'].end(),ans%s2);
        if(itr == idx[t[i]-'a'].end())return print(-1),0;
        // print(*itr,ans%s2);
        ans += *itr - ans%s2;
        // print(ans);
    }
    print(ans+1);
    
    return 0;
}