/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc301/submissions/41359569
 * Submitted at: 2023-05-13 21:20:58
 * Problem URL: https://atcoder.jp/contests/abc301/tasks/abc301_d
 * Result: AC
 * Execution Time: 7 ms
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
    
    string s; ll n; input(s,n);
    ll ans = 0;
    vector<ll> cand;
    rep(i,s.size()){
        ans *= 2;
        if(s[i] == '1')ans++;
        else if(s[i] == '?'){
            cand.push_back(pow(2LL,(ll)s.size()-i-1));
        }
    }
    if(ans > n)return print(-1),0;
    ll rest = n-ans;
    for(auto ele:cand){
        if(rest >= ele){
            rest -= ele;
            ans += ele;
        }
    }
    print(ans);
    
    return 0;
}