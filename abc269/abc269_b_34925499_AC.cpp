/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc269/submissions/34925499
 * Submitted at: 2022-09-17 21:07:24
 * Problem URL: https://atcoder.jp/contests/abc269/tasks/abc269_b
 * Result: AC
 * Execution Time: 10 ms
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
    
    vector<string> str(10);
    rep(i,10)input(str[i]);
    ll a = 10,b = 10,c = 10,d = 10;
    bool f = false;
    rep(i,10){
        rep(j,10){
            if(str[i][j] == '#'){
                a = i+1;
                b = j+1;
                f = true;
                break;
            }
        }
        if(f)break;
    }
    for(int i=a-1;i<10;i++){
        if(str[i][b-1] == '.'){
            c = i;
            break;
        }
    }
    for(int i=b-1;i<10;i++){
        if(str[a-1][i] == '.'){
            d = i;
            break;
        }
    }
    cout << a << " " << c << endl;
    cout << b << " " << d << endl;
    
    return 0;
}