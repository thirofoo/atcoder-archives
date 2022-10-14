/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/35631911
 * Submitted at: 2022-10-14 10:23:01
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_e
 * Result: AC
 * Execution Time: 866 ms
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
    
    ll n,q,x,total = 0; input(n,q,x);
    vector<ll> w(n);
    rep(i,n){
        input(w[i]);
        total += w[i];
    }

    vector<vector<ll>> table(n,vector<ll>(50));
    ll num = (x/total)*n,sum = (x/total)*total,left = 0,right = 0;
    // 初期値設定part(尺取り法)
    while(left < n){
        if(sum >= x){
            table[left][0] = num;
            sum -= w[left];
            left++;
            num--;
        }
        else{
            sum += w[right%n];
            right++;
            num++;
        }
    }

    // ダブリングpart
    rep(j,49){
        rep(i,n){
            table[i][j+1] = (table[i][j] + table[(i+table[i][j])%n][j])%n;
        }
    }
    
    while(q--){
        ll k,now = 0; input(k);
        k--;
        rep(i,50){
            if(k & (1LL << i)){
                now = (now + table[now][i])%n;
            }
        }
        print(table[now][0]);
    }
    
    return 0;
}