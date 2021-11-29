/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/27587006
 * Submitted at: 2021-11-29 16:00:57
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_by
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;

struct Clock{
    int hour;
    int minute;
    int second;

    void set(int h,int m,int s){
        hour = h;
        minute = m;
        second = s;
    }

    string to_str(){
        string h,m,s;
        if(hour >= 0 && hour < 10){
            h = "0" + to_string(hour);
        }
        else{
            h = to_string(hour);
        }
        if(minute >= 0 && minute < 10){
            m = "0" + to_string(minute);
        }
        else{
            m = to_string(minute);
        }
        if(second >= 0 && second < 10){
            s = "0" + to_string(second);
        }
        else{
            s = to_string(second);
        }
        return h + ":" + m + ":" + s;
    }

    void shift(int diff_second){
        int diff_minute,diff_hour;
        if(diff_second >= 0){
            second += diff_second%60;
            diff_minute = (diff_second - diff_second%60)/60;
            if(second >= 60){
                second = second%60;
                minute++;
            }
            minute += diff_minute%60;
            diff_hour = (diff_minute - diff_minute%60)/60;
            if(minute >= 60){
                minute = minute%60;
                hour++;
            }
            hour += diff_hour;
            if(hour >= 24){
                hour = hour%24;
            }
        }
        else{
            second += diff_second%60;
            diff_minute = (diff_second - diff_second%60)/60;
            if(second < 0){
                second += 60;
                minute--;
            }
            minute += diff_minute%60;
            diff_hour = (diff_minute - diff_minute%60)/60;
            if(minute < 0){
                minute += 60;
                hour--;
            }
            hour += diff_hour;
            if(hour < 0){
                hour += 24;
            }
        }
    }
};

int main(){
        // 入力を受け取る
    int hour, minute, second;
    cin >> hour >> minute >> second;
    int diff_second;
    cin >> diff_second;
    
    // Clock構造体のオブジェクトを宣言
    Clock clock;
    
    // set関数を呼び出して時刻を設定する
    clock.set(hour, minute, second);
    
    // 時刻を出力
    cout << clock.to_str() << endl;
    
    // 時計を進める(戻す)
    clock.shift(diff_second);
    
    // 変更後の時刻を出力
    cout << clock.to_str() << endl;
    return 0;
}   