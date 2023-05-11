/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc003/submissions/41305029
 * Submitted at: 2023-05-11 19:06:52
 * Problem URL: https://atcoder.jp/contests/abc003/tasks/abc003_2
 * Result: AC
 * Execution Time: 8 ms
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

vector<char> ch = {'a','t','c','o','d','e','r'};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s,t; input(s,t);
    rep(i,s.size()){
        if(s[i] == '@' && t[i] == '@')continue;
        else if(s[i] == '@' || t[i] == '@'){
            bool f = false;
            for(auto c:ch){
                if(s[i] == c || t[i] == c)f = true;
            }
            if(!f)return print("You will lose"),0;
        }
        else if(s[i] != t[i])return print("You will lose"),0;
    }
    print("You can win");
    
    return 0;
}