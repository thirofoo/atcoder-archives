/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc308/submissions/43135840
 * Submitted at: 2023-07-01 22:06:26
 * Problem URL: https://atcoder.jp/contests/abc308/tasks/abc308_e
 * Result: AC
 * Execution Time: 179 ms
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
    
    ll n; input(n);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    string s; input(s);

    vector<vector<ll>> rM(3,vector<ll>(n+1,0)), rX(3,vector<ll>(n+1,0));
    rep(i,n){
        if(s[i] == 'M')rM[a[i]][i+1]++;
        if(s[i] == 'X')rX[a[i]][i+1]++;
    }
    rep(i,n){
        rep(j,3){
            rM[j][i+1] += rM[j][i];
            rX[j][i+1] += rX[j][i];
        }
    }
    
    // 中間全探索
    ll ans = 0;
    rep(i,n){
        if(i == 0 || i == n-1)continue;
        if(s[i] != 'E')continue;
        
        rep(j,3){
            rep(k,3){
                vector<ll> tmp;
                tmp.push_back(a[i]);
                tmp.push_back(j);
                tmp.push_back(k);

                ll mex = 0;
                sort(tmp.begin(), tmp.end());
                tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
                rep(l,3){
                    if(mex == tmp[l])mex++;
                    else break;
                }
                ans += mex*(rM[j][i]-rM[j][0])*(rX[k][n]-rX[k][i+1]);
            }
        }
    }
    print(ans);
    
    return 0;
}