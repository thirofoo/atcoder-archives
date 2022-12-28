/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc247/submissions/37602508
 * Submitted at: 2022-12-28 23:09:29
 * Problem URL: https://atcoder.jp/contests/abc247/tasks/abc247_e
 * Result: AC
 * Execution Time: 29 ms
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
    
    ll n,x,y; input(n,x,y);
    vector<ll> a(n);
    rep(i,n)input(a[i]);

    ll right = 0,ans = 0;

    // [left,right)のx,yのidx
    deque<ll> x_idx,y_idx;

    rep(left,n){
        // [left,right)
        for(right;right<n;right++){
            if(right == n || a[right] < y || a[right] > x)break;
            if(a[right] == x)x_idx.push_back(right);
            if(a[right] == y)y_idx.push_back(right);
        }
        if(x_idx.empty() || y_idx.empty()){
            while(!x_idx.empty())x_idx.pop_back();
            while(!y_idx.empty())y_idx.pop_back();
            left = right;
            right = left+1;
            continue;
        }

        ans += right - max(x_idx[0],y_idx[0]);

        bool f = false;
        if(a[left] == y){
            if(y_idx.size() == 1)f = true;
            else y_idx.pop_front();
        }
        if(a[left] == x){
            if(x_idx.size() == 1)f = true;
            else x_idx.pop_front();
        }

        if(f){
            while(!x_idx.empty())x_idx.pop_back();
            while(!y_idx.empty())y_idx.pop_back();
            left = right;
            right = left+1;
        }
        if(left == right)right++;
    }
    print(ans);
    
    return 0;
}