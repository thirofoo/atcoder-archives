/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc310/submissions/43650508
 * Submitted at: 2023-07-16 00:44:58
 * Problem URL: https://atcoder.jp/contests/abc310/tasks/abc310_d
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n,t,m,ans = 0; input(n,t,m);
    vector<bitset<10>> ng(n,0), team(t,0);
    bitset<10> tmp;
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        ng[a].set(b);
        ng[b].set(a);
    }

    bool flag;
    auto f = [&](auto &self, int now){
        if( now == n ){
            flag = true;
            rep(i,t) if( team[i].none() ) {
                flag = false;
                break;
            }
            ans += flag;
            return;
        }
        rep(i,t){
            tmp = ng[now] & team[i];
            if( tmp.any() )continue;
            team[i] ^= (1 << now);
            self(self, now+1);
            team[i] ^= (1 << now);
            if( team[i].none() ) break;
        }
    };
    f(f, 0);
    print( ans );
    
    return 0;
}