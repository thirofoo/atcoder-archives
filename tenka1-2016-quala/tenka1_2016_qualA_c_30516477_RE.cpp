/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/tenka1-2016-quala/submissions/30516477
 * Submitted at: 2022-03-28 01:24:30
 * Problem URL: https://atcoder.jp/contests/tenka1-2016-quala/tasks/tenka1_2016_qualA_c
 * Result: RE
 * Execution Time: 123 ms
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
    rep(i,n){
        string a,b; cin >> a >> b;
        int cnt = 0;
        while(true){
            if(a[cnt] != b[cnt]){
                graph[a[cnt]-'a'].push_back(b[cnt]-'a');
                if(in_deg[a[cnt]-'a'] == -1)in_deg[a[cnt]-'a'] = 0;
                if(in_deg[b[cnt]-'a'] == -1)in_deg[b[cnt]-'a'] = 0;

                in_deg[b[cnt]-'a']++;
                // cout << a[cnt] << " => " << b[cnt] << endl;
                break;
            }
            cnt++;
        }
    }
    // rep(i,26)cout << in_deg[i] << " ";
    // cout << endl;

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
    // rep(i,26)cout << in_deg[i] << " ";
    // cout << endl;
    // int size = topo.size();
    // while(size--){
    //     cout << topo.front() << " ";
    //     topo.push(topo.front());
    //     topo.pop();
    // }
    // cout << endl;
    //そもそもトポロジカルソートできない(DGAでない)場合。
    rep(i,26)if(in_deg[i] > 0)return cout << -1 << endl,0;
    
    //answer作り編
    queue<char> rest;
    for(auto k:ch){
        // cout << k << " ";
        rest.push(k);
    }
    // cout << endl;
    
    string ans = "";
    while(!rest.empty() || !topo.empty()){
        if(rest.empty()){
            ans += topo.front(); topo.pop();
            continue;
        }
        if(topo.empty()){
            ans += rest.front(); rest.pop();
            continue;
        }

        char ch1 = rest.front(),ch2 = topo.front();
        if(ch1 < ch2)ans += ch1,rest.pop();
        else ans += ch2,topo.pop();
    }

    cout << ans << endl;

    return 0;
}