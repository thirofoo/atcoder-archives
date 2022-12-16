/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc276/submissions/37293450
 * Submitted at: 2022-12-16 09:33:37
 * Problem URL: https://atcoder.jp/contests/abc276/tasks/abc276_f
 * Result: AC
 * Execution Time: 86 ms
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

struct BIT{
    public:
        BIT(ll _n){
            n = _n;
            data.resize(n);
        }
        void add(ll i,mint x){
            i++; // 1-indexed (LSBを用いる都合上)
            while(i <= n){
                data[i-1] += x;
                i += (i & -i); // LSBを足した先にも考慮
            }
        }
        mint sum(ll l,ll r){
            return _sum(r) - _sum(l); // 裏関係
        }

    private:
        ll n;
        vector<mint> data;
        mint _sum(mint i){
            mint s = 0;
            // ここのiは1-indexed
            while(i.val()){
                s += data[i.val()-1];
                i -= (i.val() & -i.val());
            }
            return s;
        }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    // b1 : 個数 , b2 : 総和
    BIT b1(200005),b2(200005);
    mint ans; 
    ll first; input(first);
    ans = first;

    b1.add(ans.val(),1);
    b2.add(ans.val(),ans);
    print(ans.val());
    for(ll i=1;i<n;i++){
        ll ele; input(ele);
        ans = (ans*i*i + (b2.sum(ele,200005)+b1.sum(0,ele)*ele)*2 + ele) / ((i+1)*(i+1));
        b1.add(ele,1);
        b2.add(ele,ele);
        print(ans.val());
    }
    
    return 0;
}