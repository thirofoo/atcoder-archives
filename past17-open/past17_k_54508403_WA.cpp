/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54508403
 * Submitted at: 2024-06-13 23:38:26
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_k
 * Result: WA
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n; string s; cin >> n >> s;
    vector possible(9, vector<int>(10, -1));
    for(int i=0; i<9; i++) for(int j=0; j<10; j++) possible[i][(i+1)*j%10] = j;

    vector<int> hatena(9, -1);
    int sum = 0;
    for(int i=0; i<9; i++) {
        int add = 0;
        for(int j=i; j<n; j+=10) {
            if(s[j] == '?') {
                if(hatena[i] == -1) hatena[i] = j;
                s[j] = '0';
            }
            else add += s[j]-'0';
        }
        sum += ((i+1)*add) % 10;
        sum %= 10;
    }
    sum = (10-sum) % 10;

    int odd = -1;
    for(int i=0; i<10; i+=2) if(hatena[i] != -1 && i != 4) odd = i;
    if(odd != -1) {
        cout << "Yes" << endl;
        s[hatena[odd]] = possible[odd][sum] + '0';
        cout << s << endl;
        return 0;
    }

    int five = (hatena[4] != -1 ? 4 : -1);
    int even = -1;
    for(int i=1; i<9; i+=2) if(hatena[i] != -1) even = i;

    if(five != -1 && even != -1) {
        cout << "Yes" << endl;
        s[hatena[five]] = possible[five][(sum%2 == 0 ? 0 : 5)] + '0';
        if(sum%2 == 1) sum = (sum+5) % 10;
        s[hatena[even]] = possible[even][sum] + '0';
        cout << s << endl;
        return 0;
    }

    if(even != -1 && sum%2 == 0) {
        cout << "Yes" << endl;
        s[hatena[even]] = possible[even][sum] + '0';
        cout << s << endl;
        return 0;
    }

    if(five != -1 && sum%5 == 0) {
        cout << "Yes" << endl;
        s[hatena[five]] = possible[five][sum] + '0';
        cout << s << endl;
        return 0;
    }

    if(sum == 0) {
        cout << "Yes" << endl;
        cout << s << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}