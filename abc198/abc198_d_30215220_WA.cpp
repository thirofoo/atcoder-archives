/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc198/submissions/30215220
 * Submitted at: 2022-03-19 09:52:07
 * Problem URL: https://atcoder.jp/contests/abc198/tasks/abc198_d
 * Result: WA
 * Execution Time: 1380 ms
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
    string s1,s2,s3; cin >> s1 >> s2 >> s3;
    vector<char> n;
    int s1_s = s1.size(),s2_s = s2.size(),s3_s = s3.size();

    rep(i,s1_s){
        if(count(n.begin(),n.end(),s1[i]))continue;
        n.push_back(s1[i]);
    }
    rep(i,s2_s){
        if(count(n.begin(),n.end(),s2[i]))continue;
        n.push_back(s2[i]);
    }
    rep(i,s3_s){
        if(count(n.begin(),n.end(),s3[i]))continue;
        n.push_back(s3[i]);
    }
    int size = n.size();
    if(size >= 11)return cout << "UNSOLVABLE" << endl,0;

    int total = 1;
    rep(i,size)total *= 10-i;
    for(int i=0;i<(1 << 10);i++){
        int cnt = 0;
        vector<int> num;
        rep(j,10){
            if(i & (1 << j)){
                num.push_back(j);
                cnt++;
            }
        }
        if(cnt != size)continue;
        do{
            map<char,int> ch;
            rep(j,size)ch[n[j]] = num[j];
            if(ch[s1[0]] == 0 || ch[s2[0]] == 0 || ch[s3[0]] == 0)continue;
            int a = 0,b = 0,c = 0;
            rep(j,s1_s){
                a *= 10;
                a += ch[s1[j]];
            }
            rep(j,s2_s){
                b *= 10;
                b += ch[s2[j]];
            }
            rep(j,s3_s){
                c *= 10;
                c += ch[s3[j]];
            }
            if(a + b == c){
                cout << a << endl << b << endl << c << endl;
                return 0;
            }
        }while(next_permutation(num.begin(),num.end()));
    }
    
    cout << "UNSOLVABLE" << endl;
    return 0;
}