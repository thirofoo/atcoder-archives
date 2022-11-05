/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc276/submissions/36237018
 * Submitted at: 2022-11-05 21:20:59
 * Problem URL: https://atcoder.jp/contests/abc276/tasks/abc276_c
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
    
    ll n; input(n);
    vector<ll> p(n);
    rep(i,n)input(p[i]);
    set<int> st;
    st.insert(p.back());

    for(int i=n-2;i>=0;i--){
        auto itr = st.begin();
        if(*itr > p[i]){
            st.insert(p[i]);
            continue;
        }
        int i2 = 0;
        for(int j=i+1;j<n;j++){
            if(p[i] > p[j])i2 = j;
        }
        swap(p[i],p[i2]);
        sort(p.begin()+i+1,p.end());
        reverse(p.begin()+i+1,p.end());
        rep(i,n)cout << p[i] << " ";
        print();
        break;
    }
    
    return 0;
}