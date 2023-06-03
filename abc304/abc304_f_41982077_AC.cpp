/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc304/submissions/41982077
 * Submitted at: 2023-06-04 01:18:52
 * Problem URL: https://atcoder.jp/contests/abc304/tasks/abc304_f
 * Result: AC
 * Execution Time: 339 ms
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
    
    // 解説AC。
    // コンテスト中：大きい約数から調べて、重複を消そうとした
    // → 重複を消すのに包除が複雑になって死ぬ
    // 模範解答：小さい約数から調べる
    // → 過去の結果は重複がのぞいてあるから、連鎖的に包除しなくて済む

    ll n; string s; input(n,s);
    vector<ll> shift;
    rep(i,n)if(s[i] == '.')shift.push_back(i);

    vector<ll> div = divisor(n);
    map<ll,mint> mp;
    mint ans = 0;
    rep(i,div.size()){
        // div[i] サイクルの時の重複除去
        set<ll> st;
        for(auto day:shift)st.insert(day%div[i]);
        ll cand = div[i] - st.size();
        mint add = 1;
        while(cand--)add *= 2;

        vector<ll> d = divisor(div[i]);
        for(auto ele:d)if(mp.count(ele))add -= mp[ele];
        mp[div[i]] = add;
        ans += add;
    }
    print(ans.val());
    
    return 0;
}