/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc176/submissions/36173324
 * Submitted at: 2022-11-03 17:00:43
 * Problem URL: https://atcoder.jp/contests/abc176/tasks/abc176_e
 * Result: AC
 * Execution Time: 301 ms
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
    
    ll h,w,m; input(h,w,m);
    vector<ll> bx(h,0),by(w,0);
    vector<P> px,py;
    set<P> st;
    rep(i,m){
        ll th,tw; input(th,tw);
        th--; tw--;
        bx[th]++; by[tw]++;
        st.insert(P(th,tw));
    }
    rep(i,h)px.push_back(P(bx[i],i));
    rep(i,w)py.push_back(P(by[i],i));
    sort(px.begin(),px.end());
    sort(py.begin(),py.end());
    reverse(px.begin(),px.end());
    reverse(py.begin(),py.end());

    bool f = false;
    ll ans = px[0].first+py[0].first-1;
    ll mx = px[0].first,my = py[0].first;
    rep(i,h){
        if(px[i].first != mx)break;
        rep(j,w){
            if(py[j].first != my)break;
            if(!st.count(P(px[i].second,py[j].second))){
                ans = px[i].first + py[j].first;
                f = true;
                break;
            }
        }
        if(f)break;
    }
    print(ans);

    return 0;
}