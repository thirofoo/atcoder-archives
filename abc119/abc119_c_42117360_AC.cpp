/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc119/submissions/42117360
 * Submitted at: 2023-06-10 19:26:08
 * Problem URL: https://atcoder.jp/contests/abc119/tasks/abc119_c
 * Result: AC
 * Execution Time: 9 ms
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

ll n, a, b, c, ans = LLONG_MAX;
vector<ll> sele, l;

void dfs(ll idx){
    if(idx == n){
        ll al = 0, bl = 0, cl = 0, gousei = 0;
        rep(i,n){
            if(sele[i] == 0){
                if(al)gousei++;
                al += l[i];
            }
            else if(sele[i] == 1){
                if(bl)gousei++;
                bl += l[i];
            }
            else if(sele[i] == 2){
                if(cl)gousei++;
                cl += l[i];
            }
        }
        if(al && bl && cl){
            ans = min(ans,gousei*10 + abs(al-a) + abs(bl-b) + abs(cl-c));
        }
    }
    else{
        rep(i,4){
            sele[idx] = i;
            dfs(idx + 1);
        }
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(n,a,b,c);
    sele.assign(n,0);
    l.assign(n,0);
    rep(i,n)input(l[i]);

    dfs(0);
    print(ans);
    
    return 0;
}