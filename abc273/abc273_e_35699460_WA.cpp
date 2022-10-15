/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc273/submissions/35699460
 * Submitted at: 2022-10-16 00:20:31
 * Problem URL: https://atcoder.jp/contests/abc273/tasks/abc273_e
 * Result: WA
 * Execution Time: 386 ms
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
    
    ll q,now = -1; input(q);
    map<int,int> back,to;
    back[-1] = -1; to[-1] = -1;
    while(q--){
        string s; ll x; input(s);
        if(s == "ADD"){
            input(x);
            back[x] = now;
            now = x;
        }
        else if(s == "DELETE"){
            if(back[now] == 0)now = -1;
            else now = back[now];
        }
        else if(s == "SAVE"){
            input(x);
            to[x] = now;
        }
        else{
            input(x);
            if(to[x] == 0)now = -1;
            else now = to[x];
        }
        cout << now << " ";
    }
    print();
    
    return 0;
}