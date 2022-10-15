/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc273/submissions/35698766
 * Submitted at: 2022-10-15 23:54:34
 * Problem URL: https://atcoder.jp/contests/abc273/tasks/abc273_d
 * Result: AC
 * Execution Time: 583 ms
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
    map<int,set<int>> r,c;
    rep(i,n){
        int x,y; input(x,y);
        x--; y--;
        r[x].insert(y);
        c[y].insert(x);
    }
    int q; input(q);
    while(q--){
        char ch; int l; input(ch,l);
        if(ch == 'L'){
            if(!r.count(rs))cs = max(0,cs-l);
            else{
                auto itr = r[rs].lower_bound(cs);
                if(itr != r[rs].begin()){
                    itr--;
                    if(*itr < cs-l)cs -= l;
                    else cs = *itr+1;
                }
                else cs = max(0,cs-l);
            }
        }
        else if(ch == 'R'){
            if(!r.count(rs))cs = min(w-1,cs+l);
            else{
                auto itr = r[rs].lower_bound(cs);
                if(itr != r[rs].end()){
                    if(*itr > cs+l)cs += l;
                    else cs = *itr-1;
                }
                else cs = min(w-1,cs+l);
            }
        }
        else if(ch == 'U'){
            if(!c.count(cs))rs = max(0,rs-l);
            else{
                auto itr = c[cs].lower_bound(rs);
                if(itr != c[cs].begin()){
                    itr--;
                    if(*itr < rs-l)rs -= l;
                    else rs = *itr+1;
                }
                else rs = max(0,rs-l);
            }
        }
        else{
            if(!c.count(cs))rs = min(h-1,rs+l);
            else{
                auto itr = c[cs].lower_bound(rs);
                if(itr != c[cs].end()){
                    if(*itr > rs+l)rs += l;
                    else rs = *itr-1;
                }
                else rs = min(h-1,rs+l);
            }
        }
        print(rs+1,cs+1);
    }
    
    return 0;
}