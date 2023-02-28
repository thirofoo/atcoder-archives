/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc233/submissions/39303287
 * Submitted at: 2023-02-28 10:33:29
 * Problem URL: https://atcoder.jp/contests/abc233/tasks/abc233_e
 * Result: AC
 * Execution Time: 15 ms
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
    
    string x; input(x);
    string ans = "";
    ll now = 0,store = 0;
    reverse(x.begin(),x.end());
    rep(i,x.size())now += x[i]-'0';
    rep(i,x.size()){
        store += now;
        ans.push_back('0'+store%10);
        now -= x[i]-'0';
        store /= 10;
    }
    while(store != 0){
        ans.push_back('0'+store%10);
        store /= 10;
    }
    reverse(ans.begin(),ans.end());
    print(ans);
    
    return 0;
}