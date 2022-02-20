/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc240/submissions/29546426
 * Submitted at: 2022-02-20 22:39:55
 * Problem URL: https://atcoder.jp/contests/abc240/tasks/abc240_d
 * Result: RE
 * Execution Time: 418 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,cnt = 0,ball = 0; cin >> n;
    stack<int> sta;
    map<int,vector<int>> z;
    while(n--){
        int a; cin >> a;
        if(a != ball){
            cnt = 1; sta.push(a);
            ball = a;
            z[ball].push_back(1);
        }
        else{
            cnt++;
            if(cnt == a){
                for(int j=0;j<a-1;j++)sta.pop();
                if(sta.empty())ball = 0;
                else ball = sta.top();
                if(!ball){
                    cnt = *(z[ball].end()-1);
                    z[a].erase(z[ball].end()-1);
                }
                else cnt = 0;
            }
            else{
                sta.push(a);
                z[ball][z[ball].size()]++;
            }
        }
        if(sta.empty())cout << 0 << endl;
        else cout << sta.size() << endl;
    }
    return 0;
}