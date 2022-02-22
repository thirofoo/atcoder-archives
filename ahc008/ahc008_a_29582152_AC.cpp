/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc008/submissions/29582152
 * Submitted at: 2022-02-22 16:15:52
 * Problem URL: https://atcoder.jp/contests/ahc008/tasks/ahc008_a
 * Result: AC
 * Execution Time: 51 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int,int,int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)
 
//横一列並べ用の移動文字列
string pdo0 = "DrDrDrDrDrDrDrDrDrDrDrDrDrDrDuDrDruDrDrDrDrDrDrDrDrDrDrDrDrLlUlUlUlUlUlUlUlUlUlUlUlUlUlUUlUlUlUlUlUlUlUlUlUlUlUlUlUlUd";
string pdo = "DrDrDrDrDrDrDrDrDrDrDrDrDrDrDuDrDruDrDrDrDrDrDrDrDrDrDrDrDrLlUlUlUlUlUlUlUlUlUlUlUlUlULlUdUlRlUlUlUlUlUlUlUlUlUlUlUlUlUlUd";

//最後の巡回用文字列
string go01 = "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLLLLLLLLLLLLLLLL";
string go23 = "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRRR";

vector<vector<int>> field(32,vector<int>(32,0));
vector<vector<int>> pet_cnt(305,vector<int>(22,0));
vector<int> pet_cnt_top(305,0);
vector<string> player_action;
vector<int> p_index(10,0);
vector<int> mx = {0,0,1,-1};
vector<int> my = {1,-1,0,0};
vector<P> people;
vector<T> pet;
vector<vector<P>> manhattan(5);
int n,m,turn,dog_cnt = 0,letgo = 0;
bool frag1 = true,frag2 = false;
 
 
//petのfield-update(人は行動するときに別で更新)
void pet_field_update(int x,int y,int dx,int dy){
    field[x][y] -= 10;
    field[x+dx][y+dy] += 10;
    rep(i,4)if(field[x+mx[i]][y+my[i]] != -2)field[x+mx[i]][y+my[i]]--;
    rep(i,4)if(field[x+dx+mx[i]][y+dy+my[i]] != -2)field[x+dx+mx[i]][y+dy+my[i]]++;
}
 
//petの位置情報更新
void pet_do(string m,int i){
    int dx = 0,dy = 0;
    rep(i,m.size()){
        if(m[i] == '.')continue;
        else if(m[i] == 'U') dx--;
        else if(m[i] == 'D') dx++;
        else if(m[i] == 'L') dy--;
        else                 dy++;
    }
    auto [x,y,t] = pet[i];
    pet[i] = {x+dx,y+dy,t};

    //field更新
    if(dx || dy)pet_field_update(x,y,dx,dy);

    //petが5分割中のどこいるか
    if(2 <= x+dx && x+dx <= 14) pet_cnt[turn][(y+dy)/3]++;
    else if(18 <= x+dx && x+dx <= 30) pet_cnt[turn][11+(y+dy)/3]++;

    if(x+dx == 1)pet_cnt_top[turn]++;
}

//人の行動決定(横一列に並べる為の初期位置への移動)
void people_action_deciding(){
    rep(i,m){
        string tmp = ".";
        auto[x,y] = people[i];
        //5分割中どこにいるか
        int place = p_index[i]%5,left_cnt = 0;
 
        if(p_index[i] <= 4){
            if(y%6 == 5){tmp += "L"; left_cnt++;}
            rep(j,x)tmp += "U";
            if(y >= 4+6*place+left_cnt)rep(j,y-(4+6*place+left_cnt))tmp += "L";
            else rep(j,4+6*place+left_cnt-y)tmp += "R";
            if(p_index[i] == 0)tmp += pdo0;
            else tmp += pdo;
            tmp += "..........";
            if(p_index[i] == 4)tmp += ".....";
            if(place != 4)tmp += "RdRRdRd";
            else tmp += "Rd";
        }
        else{
            if(y%6 == 5)tmp += "L";
            rep(j,x)tmp += "U";
            rep(j,y)tmp += "L";
        }

        switch(p_index[i]){
            case 0: tmp += "LLLLLL......"; break;
            case 1: tmp += "LLLLLLLLLLLL"; break;
            case 2: tmp += "RRRRRRRRRRR."; break;
            case 3: tmp += "RRRRR......."; break;
            case 4: tmp += "RR.........."; break;
            default : break;
        }
 
        while(tmp.size() <= 300)tmp += ".";

        //i人目の行動送信
        player_action.push_back(tmp);
    }
}
 
//人の行動処理
string people_do(){
    string todo = "";
    vector<P> tmp(m,P(0,0));
    rep(i,m){
        int dx = 0,dy = 0;
        char action = player_action[i][turn];
        auto [x,y] = people[i];

        bool frag = true;
        rep(j,m){
            if(people[j].second == 1 || people[j].second == 30)continue;
            frag = false; break;
        }
        if(frag && frag1 && turn >= 190){
            if(turn >= 240 || !(field[1][1] >= 10 || field[2][1] >= 10 || field[3][1] >= 10 || field[1][30] >= 10 || field[2][30] >= 10 || field[3][30] >= 10 || field[1][2] || field[1][29])){
                frag2 = true;
                rep(j,m){
                    player_action[j].insert(turn+1,"DDDDDDDDDDDDDDD");

                    switch(p_index[j]){
                        case 0:player_action[j].insert(turn+17,go01);          break;
                        case 1:player_action[j].insert(turn+17+(30/m)*1,go01); break;
                        case 2:player_action[j].insert(turn+17,go23);          break;
                        case 3:player_action[j].insert(turn+17+(30/m)*1,go23); break;
                        case 4:player_action[j].insert(turn+17+(30/m)*2,go23); break;
                        case 5:player_action[j].insert(turn+17+(30/m)*2,go01); break;
                        case 6:player_action[j].insert(turn+17+(30/m)*3,go01); break; 
                        case 7:player_action[j].insert(turn+17+(30/m)*3,go23); break;
                        case 8:player_action[j].insert(turn+17+(30/m)*4,go23); break;
                        case 9:player_action[j].insert(turn+17+(30/m)*5,go23); break;
                    }
                }
                frag1 = false;
                letgo = turn+16;  
            }
        }
        if(frag2){
            if(pet_cnt_top[turn-1]){
                if(p_index[i]%5 <= 1)action = 'r';
                else action = 'l';
            }
            if(i == m-1)frag2 = false;
        }

        //巡回中の閉じ込め動作挿入部分
        if(turn >= letgo && !frag1 && ((y != 29 && pet_cnt[turn-1][y/3]) || (y == 29 && pet_cnt[turn-1][10]))){
            if(field[x-1][y] == 0)action = 'u';
        }
        if(turn >= letgo && !frag1 && ((y != 29 && pet_cnt[turn-1][11+y/3]) || (y == 29 && pet_cnt[turn-1][21]))){
            if(field[x+1][y] == 0)action = 'd';
        }
 
        if     (action == 'U' || action == 'u') dx--; 
        else if(action == 'D' || action == 'd') dx++;
        else if(action == 'L' || action == 'l') dy--;
        else if(action == 'R' || action == 'r') dy++;
 
        //操作先が柵もしくは操作がない時。
        if(field[x+dx][y+dy] == -2 || (dx == 0 && dy == 0)){todo += '.'; continue;}
        if('a' <= action && action <= 'z'){
            if(field[x+dx][y+dy] == 0){field[x+dx][y+dy] = -2; todo += action;}
            //操作先が何かある時に次の行動も置くに変更。
            else{
                string a = ""; a += action;
                player_action[i].insert(turn+1,a);
                todo += '.'; continue;
            }
        }
        else{
            people[i] = {x+dx,y+dy};
            field[x+dx][y+dy]++;
            tmp[i] = P(dx,dy);
            todo += action;
        }
    }
    //そのターン開始に操作出来ない場所は操作不可→fieldの削除更新は最後。
    rep(i,m){
        auto [x,y] = people[i];
        auto [dx,dy] = tmp[i];
        char action = player_action[i][turn];
        if('A' <= action && action <= 'Z' && (dx || dy))field[x-dx][y-dy]--;
    }
    return todo;
}
 
 
int main(){
    rep(i,32)rep(j,32)if(i == 0 || j == 0 || i == 31 || j == 31)field[i][j] = -2;
    //初期入力
    cin >> n;
    rep(i,n){
        int x,y,t; cin >> x >> y >> t;
        pet.push_back(T(x,y,t));
        if(t == 4)dog_cnt++;
        field[x][y] += 10;
        rep(j,4)if(field[x+mx[j]][y+my[j]] != -2)field[x+mx[j]][y+my[j]]++;
    }
    cin >> m;
    rep(i,m){
        int x,y; cin >> x >> y;
        people.push_back(P(x,y));
        field[x][y]++;
    }
    
    //マンハッタン距離が近い順に柵を作る人を決める部分
    rep(i,m){
        auto [x,y] = people[i];
        rep(j,5)manhattan[j].push_back(P(abs(y-(5+6*j)),i));
    }
    vector<int> elected;
    rep(i,5){
        sort(manhattan[i].begin(),manhattan[i].end(),[](P a,P b){
            return a.first > b.first;
        });
        bool frag = true;
        while(frag){
            auto [d,index] = manhattan[i].back();
            if(count(elected.begin(),elected.end(),index)) manhattan[i].pop_back();
            else{
                elected.push_back(index);
                p_index[index] = i;
                frag = false;
            }
        }
    }
    //選ばれなかった五人以外のindex写像作成
    int rest = 5;
    for(int i=0;i<m;i++){
        if(!count(elected.begin(),elected.end(),i)){p_index[i] = rest; rest++;}
    }

    people_action_deciding();

    //移動処理
    vector<string> ans(305);
    for(turn=1;turn<=300;turn++){
        //人間の行動出力部分
        string person = people_do();
        ans[turn] = person;
        cout << person << endl;
        fflush(stdout);
        
        //人間の行動後のペットの行動処理
        rep(i,n){
            string tmp; cin >> tmp;
            pet_do(tmp,i);
        }
    }
}