/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc301/submissions/41394978
 * Submitted at: 2023-05-13 23:18:03
 * Problem URL: https://atcoder.jp/contests/abc301/tasks/abc301_c
 * Result: AC
 * Execution Time: 17 ms
 */

#include <bits/stdc++.h>
using namespace std;

vector<char> ch = {'a','t','c','o','d','e','r'};

int main() {
    // ~~ Maximum用 簡易解説ver ~~ //
    string s,t; cin >> s >> t;

    // c1 : sに含まれるローマ字のcount
    // c2 : tに含まれるローマ字のcount
    vector<int> c1(26,0),c2(26,0);
    // ok : @の個数
    int ok = 0;

    for(int i = 0;i < s.size();i++){
        if(s[i] != '@')c1[s[i]-'a']++;
        else ok++;
    }
    for(int i = 0;i < t.size();i++){
        if(t[i] != '@')c2[t[i]-'a']++;
        else ok++;
    }

    // ローマ字の個数分 for文
    for(int i = 0;i < 26;i++){
        // f : ローマ字 "a"+i が "atcoder"に含まれるか
        bool f = false;

        // "atcoder"の7文字文 for文
        for(int j = 0;j < 7;j++){
            if(ch[j]-'a' == i)f = true;
        }

        // "atcoder"に含まれて居ない & sとtに出てくる文字数が違う
        // → @マークでも補えないので NG
        if(!f && abs(c1[i]-c2[i]) > 0){
            cout << "No" << endl;
            return 0;
        }

        // @のうち補った分だけマイナスする
        ok -= abs(c1[i]-c2[i]);
    }

    if(ok >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}