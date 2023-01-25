/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc285/submissions/38312580
 * Submitted at: 2023-01-25 13:15:46
 * Problem URL: https://atcoder.jp/contests/abc285/tasks/abc285_f
 * Result: WA
 * Execution Time: 942 ms
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

//セグ木状に乗せる型。
using S = array<ll,26>;

S op(S a,S b){
    array<ll,26> ar;
    rep(i,26)ar[i] = a[i]+b[i];
    return ar;
} // operator(作用素)
S e(){
    array<ll,26> ar;
    rep(i,26)ar[i] = 0;
    return ar;
} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q; string s;input(n,s,q);
    segtree<S,op,e> sg(n);
    vector<ll> cnt(26,0);
    rep(i,n){
        array<ll,26> ar;
        rep(i,26)ar[i] = 0;
        cnt[s[i]-'a']++;
        ar[s[i]-'a']++;
        sg.set(i,ar);
    }

    while(q--){
        ll t; input(t);
        if(t == 1){
            ll x; char c; input(x,c);
            array<ll,26> ar;
            rep(i,26)ar[i] = 0;
            cnt[s[x-1]-'a']--;
            cnt[c-'a']++;
            ar[c-'a']++;
            sg.set(x-1,ar);
        }
        else{
            ll l,r; input(l,r);
            array<ll,26> ar = sg.prod(l-1,r);
            ll start = 0,goal = 25;
            while(!ar[start++]);
            while(!ar[goal--]);

            // 区間内が昇順 and 区間内の最初と最後以外がcntと等しい
            bool f = true;
            for(ll i=start+1;i<goal;i++){
                ll c = ar[i];
                if(c != cnt[i])f = false;
                if(!f)break;
            }

            ll now = l-1;
            rep(i,26){
                ll c = ar[i];
                if(c){
                    array<ll,26> tmp = sg.prod(now,now+c);
                    if(c != tmp[i])f = false;
                    now += c;
                }
                if(!f || now == r)break;
            }
            print(f ? "Yes" : "No");
        }
    }
    
    return 0;
}