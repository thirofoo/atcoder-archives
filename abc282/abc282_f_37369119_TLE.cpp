/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc282/submissions/37369119
 * Submitted at: 2022-12-18 11:21:15
 * Problem URL: https://atcoder.jp/contests/abc282/tasks/abc282_f
 * Result: TLE
 * Execution Time: 4419 ms
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
    
    // 解説AC
    // SparseTableというもの考え方を利用。
    // 区間長2^kのセグメントをスライドさせた区間(計NlogN個)を前準備。
    // => [L,R]内でL,Rから最も長い区間を取り出せば和集合が必ず題意に一致。

    ll n,m = 0; input(n);
    vector<vector<P>> segment(log2(n)+1);
    vector<ll> cnt(log2(n)+1);
    for(ll d=1;d<=n;d <<= 1LL){
        ll i = log2(d);
        for(ll l=1;l+d-1<=n;l++){
            segment[i].push_back(P(l,l+d-1));
            cout << "(" << l << "," << l+d-1 << ") ";
        }
        print();
        m += n-d+1;
        if(d == 1)cnt[i] = n-d+1;
        else cnt[i] = cnt[i-1] + n-d+1;
    }
    print(m);
    for(auto s:segment){
        for(auto [l,r]:s){
            print(l,r);
            cout << flush;
        }
    }
    ll q; input(q);
    while(q--){
        ll l,r; input(l,r);
        ll i = log2(r-l+1); // 2^iのsegmentを利用
        ll p = (i == 0 ? 0 : cnt[i-1]); // それ以前に何個のsegmentがあるか
        print( p + l , p + r - (1LL << i) + 1 );
        cout << flush;
    }

    return 0;
}