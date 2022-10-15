/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc273/submissions/35699959
 * Submitted at: 2022-10-16 00:42:56
 * Problem URL: https://atcoder.jp/contests/abc273/tasks/abc273_e
 * Result: AC
 * Execution Time: 422 ms
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
    
    ll q,now = 0,cnt = 0; input(q);
    map<int,int> back,node,save;
    back[0] = 0; node[0] = -1;
    while(q--){
        string s; ll x; input(s);
        if(s == "ADD"){
            input(x);
            cnt++;
            back[cnt] = now;
            node[cnt] = x;
            now = cnt;
        }
        else if(s == "DELETE"){
            now = back[now];
        }
        else if(s == "SAVE"){
            input(x);
            save[x] = now;
        }
        else{
            input(x);
            now = save[x];
        }
        cout << node[now] << " ";
    }
    print();
    
    return 0;
}