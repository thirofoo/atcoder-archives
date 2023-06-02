/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc190/submissions/41913393
 * Submitted at: 2023-06-02 22:30:21
 * Problem URL: https://atcoder.jp/contests/abc190/tasks/abc190_c
 * Result: AC
 * Execution Time: 246 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m;
    vector<pair<int,int>> a(m);
    for(int i=0; i<m; i++){
        cin >> a.at(i).first >> a.at(i).second;
    }
    cin >> k;
    vector<pair<int,int>> b(k);
    for(int i=0; i<k; i++){
        cin >> b.at(i).first >> b.at(i).second;
    }//ここまで入力
    int ans=0;
    for(int bit=0; bit<(1<<k);bit++){
        int count=0;
        set<int> c;//Setを宣言

        // bitはk桁の2進数 → 0~k-1回 bit shift してbit全探索
        for(int i=0; i<k; i++){
            if(bit&(1<<i)){
                c.insert(b.at(i).first);//setにビット演算の結果を入れていく
            }
            else {
                c.insert(b.at(i).second);
            }
            // ↓は0を bit shift しても 0 だから 100%成り立たないif文になってるよ！
            // else if(bit&(0<<i)){
            //     c.insert(b.at(i).second);
            // }
        }
        for(int i=0; i<m; i++){
            // countの中で && は出来ないよ！
            // ( c.count(?) は?がcに存在したら true , 存在しなかったら false を返す )
            if(c.count(a.at(i).first) && c.count(a.at(i).second)){
                count++;
            }
        }
        if(count > ans){
            ans = count;
        }
    }
    cout << ans << endl;
}