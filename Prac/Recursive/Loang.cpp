#include <iostream>
using namespace std;

const int ROW = 5;
const int COL = 6;

int O[ROW][COL] = {
    {1, 1, 0, 0, 2, 2},
    {1, 0, 0, 2, 2, 2},
    {0, 0, 1, 1, 2, 0},
    {3, 3, 1, 0, 0, 0},
    {3, 3, 0, 0, 1, 1}
};

bool flag[ROW][COL] = {false};

void loang(int i, int j){
    flag[i][j] = true;

    if(j>0){
        if(O[i][j-1]==O[i][j]&&!flag[i][j-1]){
            loang(i, j-1);
        }
    }
    if(i>0){
        if(O[i-1][j]==O[i][j]&&!flag[i-1][j]){
            loang(i-1, j);
        }
    }
    if(j<5){
        if(O[i][j+1]==O[i][j]&&!flag[i][j+1]){
            loang(i, j+1);
        }
    }
    if(i<4){
        if(O[i+1][j]==O[i][j]&&!flag[i+1][j]){
            loang(i+1, j);
        }
    }
}

int main() {
    int count = 0;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (!flag[i][j]) {
                loang(i, j);
                count++;
            }
        }
    }

    cout << "So thanh phan lien thong: " << count << endl;

    return 0;
}