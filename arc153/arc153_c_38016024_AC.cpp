/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc153/submissions/38016024
 * Submitted at: 2023-01-14 22:38:47
 * Problem URL: https://atcoder.jp/contests/arc153/tasks/arc153_c
 * Result: AC
 * Execution Time: 41 ms
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
    vector<ll> a(n),b(n),c(n);
    rep(i,n)input(a[i]);

    if(n == 1){
        print("Yes");
        print(0);
        return 0;
    }

    b[0] = a[0],c[n-1] = a[n-1];
    rep(i,n-1)b[i+1] = a[i+1]+b[i];
    for(ll i=n-2;i>=0;i--)c[i] = a[i]+c[i+1];

    ll m1 = -LLONG_MAX,m2 = LLONG_MAX;
    rep(i,n){
        m1 = max(m1,-b[i]);
        m2 = min(m2,-b[i]);
    }
    rep(i,n){
        m1 = max(m1,c[i]);
        m2 = min(m2,c[i]);
    }

    ll tmp = 0;
    rep(i,n)tmp += (i+1)*a[i];
    if(tmp == 0){
        print("Yes");
        rep(i,n)cout << i+1 << " ";
        print();
        return 0;
    }

    if(tmp > 0 && m2 >= 0 || tmp < 0 && m1 <= 0){
        print("No");
        return 0;
    }

    print("Yes");
    rep(i,n){
        if((tmp > 0 && c[i] == -1) || (tmp < 0 && c[i] == 1)){
            rep(j,n){
                if(j < i)cout << j + 1 << " ";
                else cout << abs(tmp) + j + 1 << " ";
            }
            print();
            return 0;
        }
    }
    rep(i,n){
        if((tmp > 0 && b[i] == 1) || (tmp < 0 && b[i] == -1)){
            // print(tmp);
            rep(j,n){
                if(j <= i)cout << j+1-abs(tmp) << " ";
                else cout << j+1 << " ";
            }
            print();
            return 0;
        }
    }
    
    return 0;
}