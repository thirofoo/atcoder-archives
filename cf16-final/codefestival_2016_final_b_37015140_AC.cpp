/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/cf16-final/submissions/37015140
 * Submitted at: 2022-12-04 17:23:48
 * Problem URL: https://atcoder.jp/contests/cf16-final/tasks/codefestival_2016_final_b
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll n; input(n);
    vector<ll> ans;
    ll now = 1;
    while(true){
        if(n-now < 0)break;
        n -= now;
        ans.push_back(now);
        now++;
    }
    
    ll size = ans.size();
    for(auto ele:ans){
        if(ele == size - n + 1)ans.push_back(ele+n);
        else print(ele);
    }
    if(n)print(ans.back());
    
    return 0;
}