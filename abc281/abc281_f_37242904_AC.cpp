/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc281/submissions/37242904
 * Submitted at: 2022-12-13 10:37:52
 * Problem URL: https://atcoder.jp/contests/abc281/tasks/abc281_f
 * Result: AC
 * Execution Time: 174 ms
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

ll dfs(ll digit,vector<ll> v){
    if(digit == -1)return 0;
    vector<ll> zero,one;
    for(auto ele:v){
        if(ele & (1LL << digit))one.push_back(ele);
        else zero.push_back(ele);
    }
    if(zero.size() == 0)return dfs(digit-1,one);
    if(one.size() == 0)return dfs(digit-1,zero);
    return min(dfs(digit-1,zero),dfs(digit-1,one)) | (1LL << digit);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> a(n);
    rep(i,n)input(a[i]);

    // 解説AC : dfs再起で小問題に帰着させる

    // ~keypoint~
    // ① 任意のa_iの2進数の桁が同じ → 0コストでMを小さく出来る
    // ② 2進数の桁に0と1が混在      → どうしてもその桁のbitは立ってしまう

    // ②の場合、
    // xのbitを立たせると   xorを取った時、その桁が1のa_iはMに成りえない
    // xのbitを立たせないと xorを取った時、その桁が0のa_iはMに成りえない

    // これらをうまく精査すると小さい桁の小問題に帰着させる再起が書ける！
    print(dfs(29,a));
    
    return 0;
}