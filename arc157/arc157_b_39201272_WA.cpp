/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc157/submissions/39201272
 * Submitted at: 2023-02-25 23:30:21
 * Problem URL: https://atcoder.jp/contests/arc157/tasks/arc157_b
 * Result: WA
 * Execution Time: 19 ms
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
    
    ll n,k; string s; input(n,k,s);
    ll cnt = 0;
    rep(i,n)if(s[i] == 'X')cnt++;
    ll ans = 0;
    if(k == 0){
        ll ans = 0;
        rep(i,n-1)if(s[i] == 'Y' && s[i+1] == 'Y')ans++;
        return print(ans),0;
    }
    if(k == n){
        ll ans = 0;
        rep(i,n-1)if(s[i] == 'X' && s[i+1] == 'X')ans++;
        return print(ans),0;
    }
    if(k > cnt){
        k = n-k;
        rep(i,n){
            if(s[i] == 'X')s[i] = 'Y';
            else s[i] = 'X';
        }
    }

    priority_queue<T,vector<T>,greater<T>> todo;
    bool f = false;
    ll left = 0;
    rep(i,n){
        if(f && s[i] == 'Y'){
            todo.push(T(i-left+ (i == 0 || i == n-1 || left == 0 || left == n-1 ? 100000000 : 0),left,i));
            f = false;
        }
        if(s[i] == 'X'){
            f = true;
            left = i;
        }
    }
    todo.push(T(INT_MAX,left,n));
    while(!todo.empty()){
        auto [len,left,right] = todo.top(); todo.pop();
        for(ll i=left;i<right;i++){
            s[i] = 'Y';
            k--;
            if(k == 0)break;
        }
        if(k == 0)break;
    }
    rep(i,n-1)if(s[i] == 'Y' && s[i+1] == 'Y')ans++;
    print(ans);
    
    return 0;
}