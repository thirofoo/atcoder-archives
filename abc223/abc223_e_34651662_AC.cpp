/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc223/submissions/34651662
 * Submitted at: 2022-09-06 16:57:35
 * Problem URL: https://atcoder.jp/contests/abc223/tasks/abc223_e
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

bool inRect2(ll x,ll y,ll a,ll b){
    // fieldの縦横2通り
    rep(i,2){
        // a,bどれを基準にするかの2通り(aを基準としてswapで回していく)
        rep(j,2){
            // aを入れるための必要最低限の高さ
            ll length = ceil((ld)a/(ld)x);
            if(y > length && (y-length)*x >= b)return true;
            swap(a,b);
        }
        swap(x,y);
    }
    return false;
}

bool inRect3(ll x,ll y,ll a,ll b,ll c){
    // fieldの縦横の2通り
    rep(i,2){
        // a,b,cどれを基準にするかの3通り(aを基準としてswapで回していく)
        rep(j,3){
            // aを入れるための必要最低限の高さ
            ll length = ceil((ld)a/(ld)x);
            if(y > length && inRect2(x,y-length,b,c))return true;
            // a => c , b => a, c => a に入れ替え
            swap(a,c); swap(a,b);
        }
        swap(x,y);
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC。天才パズルゲー&実装が思いつかない。
    // fieldの縦横・A,B,Cそれぞれの縦横を全てシミュレーションする。
    ll x,y,a,b,c; input(x,y,a,b,c);
    print((inRect3(x,y,a,b,c) ? "Yes" : "No"));
    
    return 0;
}