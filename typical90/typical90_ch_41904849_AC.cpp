/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/41904849
 * Submitted at: 2023-06-02 15:38:05
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ch
 * Result: AC
 * Execution Time: 53 ms
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
typedef tuple<ll, ll, ll, ll> T;
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q; input(n,q);
    // bit演算は各桁が独立 → 各桁をbit全探索
    vector<T> query;
    rep(i,q){
        ll x,y,z,w; input(x,y,z,w);
        x--; y--; z--;
        query.push_back(T(z,y,x,w));
    }
    mint ans = 1;
    rep(i,60){
        // i : 今操作中の桁
        mint now = 0;
        rep(j,(1LL << n)){
            bool f = true;
            for(auto &&[x,y,z,w]:query){
                if(w & (1LL << i)){
                    f &= ( (j & (1LL << x)) || (j & (1LL << y)) || (j & (1LL << z)) );
                }
                else{
                    f &= !( (j & (1LL << x)) || (j & (1LL << y)) || (j & (1LL << z)) );
                }
            }
            if(f)now++;
        }
        ans *= now;
    }
    print(ans.val());
    
    return 0;
}