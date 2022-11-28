/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc229/submissions/36858235
 * Submitted at: 2022-11-28 14:09:42
 * Problem URL: https://atcoder.jp/contests/abc229/tasks/abc229_d
 * Result: WA
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
    
    string s; ll k; input(s,k);
    ll right = 0,ans = 0;
    rep(left,s.size()){
        while(right < s.size() && k > 0){
            if(s[right] == '.')k--;
            right++;
        }
        ans = max(ans,min((ll)s.size()-1,right)-left+1);
        if(s[left] == '.')k++;
    }
    print(ans);
    
    return 0;
}