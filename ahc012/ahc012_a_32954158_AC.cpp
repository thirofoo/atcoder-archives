/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc012/submissions/32954158
 * Submitted at: 2022-07-03 15:43:28
 * Problem URL: https://atcoder.jp/contests/ahc012/tasks/ahc012_a
 * Result: AC
 * Execution Time: 21 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<int> a(10);
vector<P> stro;
int n,k;

namespace utility {
    struct timer {
        chrono::system_clock::time_point start;
        // 開始時間を記録
        void CodeStart() {
            start = chrono::system_clock::now();
        }
        // 経過時間 (s) を返す
        double elapsed() const {
        using namespace std::chrono;
            return (double)duration_cast<milliseconds>(system_clock::now() - start).count();
        }
    } mytm;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> k;
    rep(i,10)cin >> a[i];
    rep(i,n){
        int x,y; cin >> x >> y;
        stro.push_back(P(x,y));
    }

    utility::mytm.CodeStart();
    //line : T(x1,y1,x2,y2)で定義
    vector<T> line;

    //縦横垂直切り作戦 => 辺追加・削除・移動等で点数を上げる
    int cnt = 1,now_cnt = 0;
    sort(stro.begin(),stro.end());
    for(int i=0;i<n;i+=cnt){
        if(k == 0 || cnt == 11)break;
        //縦線作成
        auto [x,y] = stro[i];
        line.push_back(T(x+1,0,x+1,1));
        k--;
        now_cnt++;
        if(now_cnt >= a[cnt-1]){
            cnt++;
            now_cnt = 0;
        }
    }


    // while(utility::mytm.elapsed() <= 2900){

    // }

    cout << line.size() << endl;
    for(auto [x1,y1,x2,y2]:line){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    
    return 0;
}