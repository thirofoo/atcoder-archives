/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc235/submissions/28600973
 * Submitted at: 2022-01-17 18:54:53
 * Problem URL: https://atcoder.jp/contests/abc235/tasks/abc235_d
 * Result: AC
 * Execution Time: 47 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int a,n,digit = 1; cin >> a >> n;
    int z = n;
    while(z/10 >= 1){
        digit++; z /= 10;
    }
    vector<int> seen(1e6,0);
    queue<int> todo;
    todo.push(1);
    seen[1] = 1;
    while(!todo.empty()){
        int tmp = todo.front();
        // if(tmp == n)break;
        todo.pop();
        // cout << tmp << " " << seen[tmp]-1 << endl;
        string c = to_string(tmp);
        string d = to_string(tmp*a);
        if(tmp >= 10 && tmp%10 != 0){
            string b = ""; b += c[c.size()-1];
            c.insert(0,b);
            c.erase(c.size()-1,1);
            if(!seen[stoi(c)]){
                seen[stoi(c)] = seen[tmp] + 1;
                todo.push(stoi(c));
            }
        }
        if(d.size() > digit || seen[tmp*a])continue;
        if(!seen[tmp*a]){
            seen[tmp*a] = seen[tmp] + 1;
            todo.push(tmp*a);
        }
    }
    cout << (seen[n] == 0 ? -1 : seen[n]-1) << endl;
    return 0;
}