/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc190/submissions/41913778
 * Submitted at: 2023-06-02 22:44:05
 * Problem URL: https://atcoder.jp/contests/abc190/tasks/abc190_c
 * Result: AC
 * Execution Time: 249 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m;
    vector<pair<int,int>> a, b;
    for(int i=0; i<m; i++){
        int na,nb; cin >> na >> nb;
        // push_back : 名の通り配列の後ろに要素追加。O(1)
        // ※ 今回はaのsizeが0だから、そこに追加していってる感じ。
        a.push_back(pair(na,nb));
    }
    cin >> k;
    for(int i=0; i<k; i++){
        int nc,nd; cin >> nc >> nd;
        b.push_back(pair(nc,nd));
    }

    int ans=0;
    for(int bit=0; bit<(1 << k);bit++){
        int count=0;
        set<int> st;

        for(int i=0; i<k; i++){
            // ↓ 構造化束縛という手法
            // pair, tuple の中身を展開出来る優れもの。
            // 今回は bの要素をc,dに代入してくれてる。(.firstとか書かなくてよい)
            auto [c,d] = b[i];
            if(bit & (1 << i))st.insert(c);
            else st.insert(d);
        }
        for(int i=0; i<m; i++){
            auto [x,y] = a[i];
            if(st.count(x) && st.count(y))count++;
        }
        // max関数で更新
        ans = max(ans,count);
    }
    cout << ans << endl;
}