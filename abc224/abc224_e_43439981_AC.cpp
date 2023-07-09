/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc224/submissions/43439981
 * Submitted at: 2023-07-10 02:13:38
 * Problem URL: https://atcoder.jp/contests/abc224/tasks/abc224_e
 * Result: AC
 * Execution Time: 105 ms
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
typedef tuple<ll, ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

// 左上右下の順番
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

inline bool outField(int x,int y,int h,int w){
    if(0 <= x && x < h && 0 <= y && y < w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC
    // dp は思いつくが、O(N^2)から下せず。
    // dp を更新する時に、行・列の最大値も更新することで、任意の遷移をO(1)で行える。天才。

    ll h,w,n; input(h,w,n);
    vector<T> place;
    vector<ll> rmax(h,0), cmax(w,0);
    rep(i,n){
        ll r,c,a; input(r,c,a);
        r--; c--;
        place.push_back(T(a,r,c,i));
    }
    sort(place.begin(), place.end());
    reverse(place.begin(), place.end());
    queue<T> todo;
    vector<ll> dp(n,0);
    ll pre = 0;
    rep(i,n){
        auto [a,r,c,idx] = place[i];
        if(pre == 0)pre = a;

        if( pre != a ){
            while(!todo.empty()){
                auto [_, rr, cc, nidx] = todo.front(); todo.pop();
                rmax[rr] = max(rmax[rr],dp[nidx]+1);
                cmax[cc] = max(cmax[cc],dp[nidx]+1);
            }
        }
        dp[idx] = max({rmax[r],cmax[c],dp[idx]});
        todo.push(place[i]);
        pre = a;
    }
    ll ans = 0;
    rep(i,n) print( dp[i] );
    
    return 0;
}