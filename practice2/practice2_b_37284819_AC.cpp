/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/practice2/submissions/37284819
 * Submitted at: 2022-12-15 19:16:51
 * Problem URL: https://atcoder.jp/contests/practice2/tasks/practice2_b
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

struct BIT{
    public:
        BIT(ll _n){
            n = _n;
            data.resize(n);
        }
        void add(ll i,ll x){
            i++; // 1-indexed (LSBを用いる都合上)
            while(i <= n){
                data[i-1] += x;
                i += (i & -i); // LSBを足した先にも考慮
            }
        }
        ll sum(ll l,ll r){
            return _sum(r) - _sum(l);
        }

    private:
        ll n;
        vector<ll> data;
        ll _sum(ll i){
            ll s = 0;
            // ここのiは1-indexed
            while(i){
                s += data[i-1];
                i -= (i & -i);
            }
            return s;
        }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q; input(n,q);
    BIT b(n);
    rep(i,n){
        ll ele; input(ele);
        b.add(i,ele);
    }
    while(q--){
        ll t,x,y; input(t,x,y);
        if(t == 0)b.add(x,y);
        else print(b.sum(x,y));
    }
    
    return 0;
}