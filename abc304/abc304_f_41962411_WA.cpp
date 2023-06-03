/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc304/submissions/41962411
 * Submitted at: 2023-06-03 21:55:29
 * Problem URL: https://atcoder.jp/contests/abc304/tasks/abc304_f
 * Result: WA
 * Execution Time: 43 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

//約数列挙ver(1,nも含む)
vector<ll> divisor(ll n){
    vector<ll> div;
    for(ll i=1;i*i<=n;i++){
        if(n%i)continue;
        div.push_back(i);
        if(i != n/i)div.push_back(n/i);
    }
    sort(div.begin(),div.end());
    div.pop_back();
    return div;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string s; input(n,s);
    vector<ll> shift; // 必ず入らなくちゃいけない日
    rep(i,s.size())if(s[i] == '.')shift.push_back(i);

    vector<mint> r(60);
    r[0] = 2;
    for(ll i=1;i<60;i++)r[i] = r[i-1]*r[i-1];

    vector<ll> div = divisor(n);
    reverse(div.begin(),div.end());
    set<ll> st;
    mint ans = 0;
    rep(i,div.size()){
        if(st.count(div[i]))continue;
        vector<ll> d = divisor(div[i]);
        for(auto ele:d)st.insert(ele);
        
        set<ll> mod;
        for(auto day:shift)mod.insert(day%div[i]);
        ll cand = div[i]-mod.size();
        mint add = 1;
        rep(j,20)if(cand & (1LL << j))add *= r[j];
        ans += add - 1;
    }
    ans++;
    print(ans.val());
    
    return 0;
}