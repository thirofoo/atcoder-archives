/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc030/submissions/30605383
 * Submitted at: 2022-04-01 18:19:21
 * Problem URL: https://atcoder.jp/contests/arc030/tasks/arc030_3
 * Result: AC
 * Execution Time: 23 ms
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
    //入力受付part。
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

    //強連結成分を1つの頂点としたグラフの作成part。
    vector<vector<int>> scc = ele.scc();
    vector<int> emplace(n,-1);
    vector<string> str;
    rep(i,scc.size()){
        //強連結成分内の文字は自由な順番で取れる => 辞書順で小さいものから取ればいい => sort
        string tmp = "";
        for(auto p:scc[i])emplace[p] = i,tmp += s[p];
        sort(tmp.begin(),tmp.end());
        str.push_back(tmp);
    }
    rep(i,Graph.size()){
        //新たなグラフの辺作成
        for(auto p:Graph[i]){
            int e1 = emplace[i],e2 = emplace[p];
            if(e1 != e2)graph[e1].push_back(e2);
        }
    }

    //dpの初期値設定part。
    //強連結成分内なら要素を何個とってもok。(全部でも1つも取らなくてもok)
    int size = str.size();
    vector<vector<string>> dp(k+1,vector<string>(size,"0"));
    rep(i,size){
        string tmp = "";
        rep(j,min((int)str[i].size(),k)){
            tmp += str[i][j];
            dp[j+1][i] = tmp;
        }
    }

    //dp part。dp[i][j]:i文字選び,頂点jにいる時の文字列において辞書順最小のもの。
    //強連結成分が頂点のDGAだから一回訪れた経路は100%訪れないことを利用。
    for(int i=1;i<k;i++){
        rep(j,size){
            if(dp[i][j] == "0")continue;
            for(auto l:graph[j]){
                string tmp = dp[i][j];
                int str_size = str[l].size(),tmp_size = tmp.size();
                //強連結成分j内の要素をひとつもえらばないときの遷移。
                if(dp[tmp_size][l] == "0")dp[tmp_size][l] = tmp;
                else dp[tmp_size][l] = min(dp[tmp_size][l],tmp);

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

    //dpから答え求めpart。
    string ans = "0";
    rep(i,size){
        if(dp[k][i] == "0")continue;
        if(ans == "0")ans = dp[k][i];
        else ans = min(ans,dp[k][i]);
    }
    cout << (ans == "0" ? "-1" : ans) << endl;

    return 0;
}