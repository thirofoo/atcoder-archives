/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc119/submissions/42117195
 * Submitted at: 2023-06-10 19:15:07
 * Problem URL: https://atcoder.jp/contests/abc119/tasks/abc119_c
 * Result: AC
 * Execution Time: 716 ms
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
    
    ll n,a,b,c; input(n,a,b,c);
    // a <= b <= c
    if(a >= b)swap(a,b);
    if(a >= c)swap(a,c);
    if(b >= c)swap(b,c);

    vector<ll> l(n),p(n);
    rep(i,n)input(l[i]);

    ll ans = LLONG_MAX;
    rep(k,(1LL << n)){
        vector<ll> nl;
        rep(i,n)if(k & (1LL << i))nl.push_back(l[i]);
        p.assign(nl.size(),0);
        iota(p.begin(),p.end(),0);
        do{
            rep(i,(1LL << (nl.size()-1))){
                ll point = 0;
                vector<ll> cand = { nl[p[0]] };
                rep(j,nl.size()-1){
                    if(i & (1LL << j)){
                        // 合成
                        ll last = cand.back(); cand.pop_back();
                        cand.push_back(last + nl[p[j+1]]);
                        point += 10;
                    }
                    else cand.push_back(nl[p[j+1]]);
                }
                if(cand.size() != 3)continue;
                sort(cand.begin(),cand.end());
                ans = min(ans,point + abs(cand[0]-a) + abs(cand[1]-b) + abs(cand[2]-c));
            }
        }while(next_permutation(p.begin(),p.end()));
    }
    print(ans);
    
    return 0;
}