/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc307/submissions/42913949
 * Submitted at: 2023-06-24 21:44:25
 * Problem URL: https://atcoder.jp/contests/abc307/tasks/abc307_d
 * Result: RE
 * Execution Time: 109 ms
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
    
    ll n; string s; input(n,s);
    ll depth = 0;
    vector<vector<ll>> idx(n,vector<ll>{});
    rep(i,s.size()){
        if(s[i] == '('){
            depth++;
            idx[depth].push_back(i);
        }
        else if(s[i] == ')' && depth > 0){
            idx[depth].push_back(i);
            depth--;
        }
    }
    vector<ll> rui(s.size()+1);
    rep(i,n){
        rep(j,idx[i].size()){
            if(idx[i].size()-1 == j)break;
            rui[idx[i][j]]++;
            rui[idx[i][j+1]+1]--;
            j++;
        }
    }
    rep(i,s.size())rui[i+1] += rui[i];
    rep(i,s.size()){
        if(!rui[i])cout << s[i];
    }
    print();
    
    return 0;
}