/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc034/submissions/31473508
 * Submitted at: 2022-05-06 23:08:47
 * Problem URL: https://atcoder.jp/contests/agc034/tasks/agc034_b
 * Result: WA
 * Execution Time: 13 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    ll ans = 0,size = s.size();
    queue<char> todo;
    char tmp = 'x';
    rep(i,size){
        if(tmp == 'x')tmp = s[i];
        else if(tmp == 'B' && s[i] == 'C'){
            todo.push('D');
            tmp = 'x';
        }
        else{
            todo.push(tmp);
            tmp = s[i];
        }
    }
    if(tmp != 'x')todo.push(tmp);

    while(!todo.empty()){
        string z = "";
        while(!todo.empty()){
            char t = todo.front(); todo.pop();
            if(t == 'B' || t == 'C')break;
            z += t;
        }

        int tento = 0;
        size = z.size();
        fenwick_tree<int> fw(2);
        rep(i,size){
            tento += i - fw.sum(0,(z[i] == 'D' ? 1 : 2));
            if(z[i] == 'D')fw.add(0,1);
            else fw.add(1,1);
        }
        ans += tento;
    }
    cout << ans << endl;

    return 0;
}