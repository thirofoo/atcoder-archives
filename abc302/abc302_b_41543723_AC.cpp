/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc302/submissions/41543723
 * Submitted at: 2023-05-20 21:07:16
 * Problem URL: https://atcoder.jp/contests/abc302/tasks/abc302_b
 * Result: AC
 * Execution Time: 9 ms
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

vector<int> dx = {0,-1,0,1,-1,1,-1, 1};
vector<int> dy = {-1,0,1,0,-1,1, 1,-1};

ll h,w;
bool outField(ll x, ll y){
    if(x < 0 || x >= h || y < 0 || y >= w)return true;
    else return false;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(h,w);
    vector<string> s(h);
    rep(i,h)input(s[i]);
    rep(i,h){
        rep(j,w){
            rep(k,8){
                string cand = "";
                rep(d,5){
                    ll nx = i + dx[k]*d;
                    ll ny = j + dy[k]*d;
                    if(outField(nx,ny))break;
                    cand += s[nx][ny];
                }
                if(cand == "snuke"){
                    rep(d,5){
                        ll nx = i + dx[k]*d;
                        ll ny = j + dy[k]*d;
                        print(nx+1,ny+1);
                    }
                    return 0;
                }
            }
        }
    }
    
    return 0;
}