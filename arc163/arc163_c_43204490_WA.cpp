/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc163/submissions/43204490
 * Submitted at: 2023-07-03 00:27:23
 * Problem URL: https://atcoder.jp/contests/arc163/tasks/arc163_c
 * Result: WA
 * Execution Time: 54 ms
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
    
    ll t; input(t);
    while(t--){
        ll n; input(n);

        // 解説AC (超天才)
        // ある単位分数は部分分数分解より自分より小さい単位分数2つに分解可能。
        // → 1/K = 1/(K+1) + 1/(K(K+1)) の前項をひたすら分解しまくる
        // → この方法だと、N = l(l+1) の形で表せてしまう時だけ重複を許してしまう
        // → l(l+1)-1 は x(x+1) の形では表せないから 1つ前の答えを使おう
        // → 1つ前の答えを2倍すると、分数の和は 1/2 になる
        // → そこには 2 が含まれていない為、2を付け加えればそれが答え！
        if(n == 2){
            print("No");
            continue;
        }
        vector<ll> answer;
        answer.push_back(1);
        set<ll> st;
        rep(i,n-1){
            ll now = answer.back(); answer.pop_back();
            answer.push_back(now*(now+1));
            answer.push_back(now+1);
            st.insert(now*(now+1));
        }
        if( st.count(answer.back()) ){
            cout << 2 << " ";
            sort(answer.begin(),answer.end());
            rep(i,n-1)cout << answer[i]*2 << " ";
            print();
        }
        else{
            sort(answer.begin(),answer.end());
            rep(i,n)cout << answer[i] << " ";
            print();
        }
    }
    
    return 0;
}