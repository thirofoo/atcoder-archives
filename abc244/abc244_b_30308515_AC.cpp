/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc244/submissions/30308515
 * Submitted at: 2022-03-20 23:19:49
 * Problem URL: https://atcoder.jp/contests/abc244/tasks/abc244_b
 * Result: AC
 * Execution Time: 11 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef struct xy{
    int x = 0;
    int y = 0;
}XY;
void move(char T[], int N, XY *takahashi){
    int c = 0;
    for(int i = 0; i < N; i++){
        if(T[i] == 'R'){
            c++;
            continue;
        }
        else if(T[i] == 'S'){
            if((c % 2 == 1)&&(c % 4 == 1)){
                takahashi->y--;
            }else if((c % 2 == 1)&&(c % 4 == 3)){
                takahashi->y++;
            }else if((c % 2 == 0)&&(c % 4 == 2)){
                takahashi->x--;
            }else if((c % 2 == 0)&&(c % 4 == 0)){
                takahashi->x++;
            }
        }
    }
}
int main(){
    int N;
    XY takahashi;
    cin >> N;
    char T[100010];
    for(int i = 0; i < N; i++){
        cin >> T[i];
    }
    move(T, N, &takahashi);
    cout << takahashi.x << " " << takahashi.y << endl;
}