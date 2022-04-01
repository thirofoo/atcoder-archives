/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc030/submissions/30604398
 * Submitted at: 2022-04-01 17:09:42
 * Problem URL: https://atcoder.jp/contests/arc030/tasks/arc030_3
 * Result: RE
 * Execution Time: 110 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m,k; cin >> n >> m >> k;
    string s = "";
    rep(i,n){
        char tmp; cin >> tmp;
        s += tmp;
    }
    vector<vector<int>> Graph(n),graph(n);
    scc_graph ele(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
        ele.add_edge(a,b);
    }

    vector<vector<int>> scc = ele.scc();
    vector<int> emplace(n,-1);
    vector<string> str;
    int cnt = 0;
    for(auto l:scc){
        string tmp = "";
        for(auto p:l){
            emplace[p] = cnt;
            tmp += s[p];
        }
        sort(tmp.begin(),tmp.end());
        str.push_back(tmp);
        cnt++;
    }

    cnt = 0;
    for(auto l:Graph){
        for(auto p:l){
            int e1 = emplace[cnt],e2 = emplace[p];
            if(e1 != e2)graph[e1].push_back(e2);
        }
        cnt++;
    }

    int size = str.size();
    vector<vector<string>> dp(k+1,vector<string>(size,"0"));
    rep(i,size)dp[str[i].size()][i] = str[i];
    rep(i,k){
        rep(j,size){
            if(dp[i][j] == "0")continue;
            for(auto l:graph[j]){
                int str_size = str[l].size();
                string tmp = dp[i][j];
                rep(p,str_size){
                    tmp += str[l][p];

                    int now = tmp.size();
                    if(now > k)break;

                    if(dp[now][l] == "0")dp[now][l] = tmp;
                    else dp[now][l] = min(dp[now][l],tmp);
                }

            }
        }
    }

    string ans = "0";
    rep(i,size){
        if(dp[k][i] == "0")continue;
        if(ans == "0")ans = dp[k][i];
        else ans = min(ans,dp[k][i]);
    }
    cout << (ans == "0" ? "-1" : ans) << endl;

    return 0;
}