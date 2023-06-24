/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc307/submissions/42907791
 * Submitted at: 2023-06-24 21:26:05
 * Problem URL: https://atcoder.jp/contests/abc307/tasks/abc307_c
 * Result: AC
 * Execution Time: 15 ms
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
    
    ll x1 = -1,y1 = -1,x2 = -1,y2 = -1;

    ll ha,wa; input(ha,wa);
    vector<string> a1(ha);
    rep(i,ha)input(a1[i]);
    rep(i,ha){
        rep(j,wa){
            if(a1[i][j] == '#'){
                x1 = i;
                y1 = j;
                break;
            }
        }
        if(x1 >= 0)break;
    }

    ll hb,wb; input(hb,wb);
    vector<string> a2(hb);
    rep(i,hb)input(a2[i]);
    rep(i,hb){
        rep(j,wb){
            if(a2[i][j] == '#'){
                x2 = i;
                y2 = j;
                break;
            }
        }
        if(x2 >= 0)break;
    }

    ll hx,wx; input(hx,wx);
    vector<string> a3(hx);
    rep(i,hx)input(a3[i]);
    set<P> xst;
    rep(i,hx){
        rep(j,wx){
            if(a3[i][j] == '#'){
                xst.insert(P(i,j));
            }
        }
    }

    rep(i,hx){
        rep(j,wx){
            if(a3[i][j] == '.')continue;
            rep(k,hx){
                rep(l,wx){
                    if(a3[k][l] == '.')continue;
                    // ここまでで基準の#を探索]
                    set<P> v;
                    ll dx1 = i-x1, dy1 = j-y1;
                    rep(n,ha){
                        rep(m,wa){
                            if(a1[n][m] == '#')v.insert(P(n+dx1,m+dy1));
                        }
                    }
                    ll dx2 = k-x2, dy2 = l-y2;
                    rep(n,hb){
                        rep(m,wb){
                            if(a2[n][m] == '#')v.insert(P(n+dx2,m+dy2));
                        }
                    }
                    if(xst == v){
                        print("Yes");
                        return 0;
                    }
                }
            }
        }
    }
    print("No");
    
    return 0;
}