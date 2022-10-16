/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc151/submissions/35724293
 * Submitted at: 2022-10-16 21:13:03
 * Problem URL: https://atcoder.jp/contests/arc151/tasks/arc151_a
 * Result: AC
 * Execution Time: 22 ms
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
    
    ll n,d = 0,d1 = 0,d2; string s,t; input(n,s,t);
    rep(i,n){
        if(s[i] != t[i])d++;
        if(s[i] == '0' && t[i] == '1')d1++;
    }
    if(d%2 == 1)return print(-1),0;

    stack<char> ans;
    d2 = d-d1;
    if(d1 >= d2){
        ll tmp = (d1-d2)/2;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '0' && t[i] == '1'){
                if(tmp){
                    ans.push('1');
                    tmp--;
                }
                else ans.push('0');
            }
            else ans.push('0');
        }
    }
    else{
        ll tmp = (d2-d1)/2;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '1' && t[i] == '0'){
                if(tmp){
                    ans.push('1');
                    tmp--;
                }
                else ans.push('0');
            }
            else ans.push('0');
        }
    }

    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    print();

    return 0;
}