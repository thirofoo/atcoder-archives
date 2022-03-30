/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/tenka1-2016-quala/submissions/30567977
 * Submitted at: 2022-03-30 17:47:20
 * Problem URL: https://atcoder.jp/contests/tenka1-2016-quala/tasks/tenka1_2016_qualA_c
 * Result: AC
 * Execution Time: 39 ms
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
    int n; cin >> n;
    set<char> ch;
    rep(i,26)ch.insert('a'+i);

    //トポロジカルソート用グラフ作成編
    vector<int> in_deg(26,-1);
    vector<vector<int>> graph(26);
    bool f = false;
    rep(i,n){
        string a,b; cin >> a >> b;
        int cnt = 0;
        int as = a.size(),bs = b.size();
        rep(j,min(as,bs)){
            if(a[cnt] != b[cnt]){
                graph[a[cnt]-'a'].push_back(b[cnt]-'a');
                if(in_deg[a[cnt]-'a'] == -1)in_deg[a[cnt]-'a'] = 0;
                if(in_deg[b[cnt]-'a'] == -1)in_deg[b[cnt]-'a'] = 0;
                in_deg[b[cnt]-'a']++;
                break;
            }
            cnt++;
        }

        //辞書順を変更しても100%条件を満たさない物があれば終了。
        //ex: abcde , abcd のようなaがbの先頭からの真部分列の場合。
        if(cnt == bs)f = true;
    }
    if(f)return cout << -1 << endl,0;

    //トポロジカルソート編
    priority_queue<char,vector<char>,greater<char>> todo;
    queue<char> topo;
    rep(i,26)if(!in_deg[i])todo.push(i);
    while(!todo.empty()){
        int tmp = todo.top();todo.pop();
        topo.push('a'+tmp);
        ch.erase('a'+tmp);
        for(auto k:graph[tmp]){
            in_deg[k]--;
            if(!in_deg[k])todo.push(k);
        }
    }
    //DGAでない場合は即終了。(サイクルがある=>トポロジカルソート不可=>条件満たさず。)
    rep(i,26)if(in_deg[i] > 0)return cout << -1 << endl,0;
    
    //answer作り編
    queue<char> rest;
    for(auto k:ch)rest.push(k);
    
    string ans = "";
    while(!rest.empty() && !topo.empty()){
        char ch1 = rest.front(),ch2 = topo.front();
        if(ch1 < ch2)ans += ch1,rest.pop();
        else ans += ch2,topo.pop();
    }

    while(!rest.empty())ans += rest.front(),rest.pop();
    while(!topo.empty())ans += topo.front(),topo.pop();

    cout << ans << endl;

    return 0;
}