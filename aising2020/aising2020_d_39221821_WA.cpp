/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/aising2020/submissions/39221821
 * Submitted at: 2023-02-26 19:37:20
 * Problem URL: https://atcoder.jp/contests/aising2020/tasks/aising2020_d
 * Result: WA
 * Execution Time: 52 ms
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
    // 1回操作したらN未満
    // 2^xをpopcountで割った余り
    ll pop_count = 0;
    rep(i,n)pop_count += (s[i] == '1');
    vector<vector<ll>> x(3,vector<ll>(n+1,1));
    for(ll i=1;i<=n;i++){
        if(pop_count > 1)x[0][i] = (2*x[0][i-1])%(pop_count-1);
        if(pop_count > 0)x[1][i] = (2*x[1][i-1])%pop_count;
        x[2][i] = (2*x[2][i-1])%(pop_count+1);
    }
    // 2回目以降は前計算
    vector<ll> a(200005,0);
    for(ll i=1;i<=200000;i++){
        ll cnt = 0;
        rep(j,64)if(i & (1LL << j))cnt++;
        a[i] = a[i%cnt] + 1;
    }
    // sの回数を求める
    ll tmp1 = 0,tmp2 = 0;
    reverse(s.begin(),s.end());
    rep(i,n){
        if(s[i] == '1'){
            if(pop_count > 1)tmp1 += x[0][i];
            if(pop_count > 1)tmp1 %= (pop_count-1);
            tmp2 += x[2][i];
            tmp2 %= (pop_count+1);
        }
    }
    // 下位bitから反転させたものを答える
    stack<ll> ans;
    rep(i,n){
        if(s[i] == '1'){
            if(pop_count == 1)ans.push(1);
            else ans.push( a[(tmp1-x[0][i]+pop_count-1)%(pop_count-1)] + 1 );
        }
        else{
            ans.push( a[(tmp2+x[2][i]+pop_count+1)%(pop_count+1)] + 1 );
        }
    }
    while(!ans.empty()){
        print(ans.top());
        ans.pop();
    }
    
    return 0;
}