/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc302/submissions/41889549
 * Submitted at: 2023-06-01 18:54:36
 * Problem URL: https://atcoder.jp/contests/abc302/tasks/abc302_c
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll n,m ;input(n,m);
    vector<string> s(n);
    rep(i,n)input(s[i]);
    sort(s.begin(),s.end());
    do{
        bool f = true;
        string now = s[0];
        for(ll i=1;i<n;i++){
            ll cnt = 0;
            rep(j,m)if(now[j] != s[i][j])cnt++;
            if(cnt == 1)now = s[i];
            else{
                f = false;
                break;
            }
        }
        if(f){
            print("Yes");
            return 0;
        }
    }while(next_permutation(s.begin(),s.end()));
    print("No");

    return 0;
}