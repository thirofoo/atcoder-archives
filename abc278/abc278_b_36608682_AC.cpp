/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc278/submissions/36608682
 * Submitted at: 2022-11-19 21:13:20
 * Problem URL: https://atcoder.jp/contests/abc278/tasks/abc278_b
 * Result: AC
 * Execution Time: 7 ms
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
    
    int h,m; input(h,m);

    while(true){
        if(m == 60){
            m = 0;
            h++;
        }
        if(h == 24)h = 0;

        int nh = h/10*10 + m/10;
        int nm = (h%10)*10 + (m%10);
        if(0 <= nh && nh <= 23 && 0 <= nm && nm <= 59)break;
        m++;
    }
    print(h,m);
    
    return 0;
}