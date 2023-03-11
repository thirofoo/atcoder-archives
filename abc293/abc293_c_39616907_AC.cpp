/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc293/submissions/39616907
 * Submitted at: 2023-03-11 21:22:36
 * Problem URL: https://atcoder.jp/contests/abc293/tasks/abc293_c
 * Result: AC
 * Execution Time: 61 ms
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

vector<int> dx = {0,1};
vector<int> dy = {1,0};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w; input(h,w);
    vector<vector<ll>> field(h,vector<ll>(w));
    rep(i,h)rep(j,w)input(field[i][j]);
    ll ans = 0;
    for(ll i=0;i<(1LL << (h+w-2));i++){
        ll cnt = 0;
        rep(j,h+w-2)cnt += ((i & (1LL << j)) > 0);
        if(cnt != h-1)continue;
        ll nx = 0,ny = 0;
        set<ll> st;
        st.insert(field[nx][ny]);
        bool f = false;
        rep(j,w+h-2){
            nx += dx[(i & (1LL << j)) > 0];
            ny += dy[(i & (1LL << j)) > 0];
            if(st.count(field[nx][ny])){
                f = true;
                break;
            }
            st.insert(field[nx][ny]);
        }
        if(!f)ans++;
    }
    print(ans);
    
    return 0;
}