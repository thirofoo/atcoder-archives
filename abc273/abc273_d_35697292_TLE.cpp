/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc273/submissions/35697292
 * Submitted at: 2022-10-15 23:15:06
 * Problem URL: https://atcoder.jp/contests/abc273/tasks/abc273_d
 * Result: TLE
 * Execution Time: 3310 ms
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
    
    int h,w,rs,cs,n; input(h,w,rs,cs,n);
    rs--; cs--;
    map<int,set<int>> r,c,rr,cc;
    rep(i,n){
        int x,y; input(x,y);
        x--; y--;
        r[x].insert(y);
        rr[x].insert(w-y-1);
        c[y].insert(x);
        cc[y].insert(h-x-1);
    }
    int q; input(q);
    while(q--){
        char ch; int l; input(ch,l);
        if(ch == 'L'){
            auto itr = lower_bound(rr[rs].begin(),rr[rs].end(),w-cs-1);
            if(itr != rr[rs].end()){
                if(*itr > w-cs-1 + l)cs -= l;
                else cs = -(*itr)+w;
            }
            else cs = max(0,cs-l);
        }
        else if(ch == 'R'){
            auto itr = lower_bound(r[rs].begin(),r[rs].end(),cs);
            if(itr != r[rs].end()){
                if(*itr > cs+l)cs += l;
                else cs = *itr-1;
            }
            else cs = min(w-1,cs+l);
        }
        else if(ch == 'U'){
            auto itr = lower_bound(cc[cs].begin(),cc[cs].end(),h-rs-1);
            if(itr != cc[cs].end()){
                if(*itr > h-rs-1+l){
                    rs -= l;
                }
                else rs = -(*itr)+h;
            }
            else rs = max(0,rs-l);
        }
        else{
            auto itr = lower_bound(c[cs].begin(),c[cs].end(),rs);
            if(itr != c[cs].end()){
                if(*itr > rs+l)rs += l;
                else rs = *itr-1;
            }
            else rs = min(h-1,rs+l);
        }
        print(rs+1,cs+1);
    }
    
    return 0;
}