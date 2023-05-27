/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc303/submissions/41771267
 * Submitted at: 2023-05-27 22:34:00
 * Problem URL: https://atcoder.jp/contests/abc303/tasks/abc303_f
 * Result: WA
 * Execution Time: 155 ms
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
    
    ll n,h; input(n,h);
    vector<T> mahou;
    rep(i,n){
        ll t,d; input(t,d);
        mahou.push_back(T(t*d,t,d));
    }
    sort(mahou.begin(),mahou.end());
    reverse(mahou.begin(),mahou.end());

    ll left = 0, right = h;
    while(right-left > 1){
        ll mid = (right+left)/2;
        ll cnt = 0, turn = mid;
        for(auto &&[td,t,d]:mahou){
            if( (turn-t+1) <= 0 )continue;
            cnt += (turn-t+1)*td;
            turn -= (turn-t+1);
        }
        if(cnt >= h)right = mid;
        else left = mid;
    }
    print(right);
    
    return 0;
}