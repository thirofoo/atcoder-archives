/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc141/submissions/36770285
 * Submitted at: 2022-11-25 17:27:19
 * Problem URL: https://atcoder.jp/contests/abc141/tasks/abc141_e
 * Result: RE
 * Execution Time: 3224 ms
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
    vector<vector<string>> l(n);
    // 連続部分列全列挙
    rep(left,n){
        string tmp = "";
        for(ll right=left;right<n;right++){
            tmp += s[right];
            l[left].push_back(tmp);
        }
    }

    ll ans = 0;
    rep(i,n){
        for(auto str1:l[i]){
            for(int j=i+str1.size();j<n;j++){
                for(auto str2:l[j]){
                    if(str1 == str2)ans = max(ans,(ll)str1.size());
                }
            }
        }
    }
    print(ans);

    return 0;
}