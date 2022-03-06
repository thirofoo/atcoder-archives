/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc242/submissions/29921823
 * Submitted at: 2022-03-06 20:29:00
 * Problem URL: https://atcoder.jp/contests/abc242/tasks/abc242_d
 * Result: AC
 * Execution Time: 276 ms
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

vector<char> A = {'B','C'};
vector<char> B = {'C','A'};
vector<char> C = {'A','B'};

int main() {
    string s; int q; cin >> s >> q;
    rep(i,q){
        ll t,k; cin >> t >> k;
        k--;

        //num：初期文字列の何文字目が派生したものか。
        //f：初期文字列のnum文字目の文字(t>63の時は違う)
        ll num; char f;
        if(t <= 63){
            num = k/(ll)pow(2,t);
            //k：num文字目が派生した文字列のうちの何番目か。
            k %= (ll)pow(2,t);
            f = s[num];
        }
        else{
            //t>63の時は周期性を利用してt=63の時の文字列の0文字目をfとする。
            //miss：周期性を利用する際の初期値。
            ll miss;
            switch(s[0]){
                case 'A': miss = 0; break;
                case 'B': miss = 1; break;
                case 'C': miss = 2; break;
            }
            if((t+miss-64)%3 == 0)f = 'A';
            else if((t+miss-64)%3 == 1)f = 'B';
            else f = 'C';
        }

        //T：これから何回の操作があるか(t>63の時は上の操作でt=63の時まで移動済み)
        ll T = min(t-1,(ll)63);

        for(int j=T;j>=0;j--){
            int p = (k & (1LL << j) ? 1 : 0);
            if(f == 'A')f = A[p];
            else if(f == 'B')f = B[p];
            else if(f == 'C')f = C[p];
        }
        cout << f << "\n";
    }
    return 0;
}