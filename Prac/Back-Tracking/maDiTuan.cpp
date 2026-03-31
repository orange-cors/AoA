#include <iostream>
#include <iomanip>

using namespace std;

#define N 6 // Kích thước bàn cờ 5x5 như minh họa

int board[N][N];
bool thanh_cong = false; // Cờ đánh dấu trạng thái đã tìm thấy đường đi

// 8 hướng di chuyển có thể có của quân mã
int X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// Hàm in bàn cờ
void inBanCo() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << board[i][j] << " ";
        }
        cout << endl;
    }
}

void Try(int k, int x, int y) {
    // Khởi động việc chọn nước đi;
    int i = 0; // i là chỉ số của mảng hướng đi (từ 0 đến 7)
    
    do {
        // Chọn nước đi tiếp từ danh sách ứng cử;
        int u = x + X[i];
        int v = y + Y[i];
        
        // if (chấp nhận được) {
        // (Điều kiện: nằm trong bàn cờ và ô đó chưa đi qua)
        if (u >= 0 && u < N && v >= 0 && v < N && board[u][v] == 0) {
            
            // Ghi nhớ nước đi;
            board[u][v] = k;
            
            // if (bàn cờ chưa kín) {
            if (k < N * N) {
                Try(k + 1, u, v);
                
                // if (không thành)
                if (!thanh_cong) {
                    // Xóa ghi nhớ trước;
                    board[u][v] = 0;
                }
            } 
            // Bổ sung xử lý khi bàn cờ đã kín (hàm ý của bài toán)
            else {
                thanh_cong = true;
            }
        }
        
        // Chuyển sang nước đi ứng cử tiếp theo
        i++;
        
    // }while ( (!thành_công) && (còn_nước_đi_trong_danh_sách_ứng_cử) );
    } while (!thanh_cong && i < 8); 
}

int main() {
    // Khởi tạo bàn cờ trống
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    // Chọn vị trí xuất phát (0, 0)
    int start_x = 0;
    int start_y = 0;

    board[start_x][start_y] = 1; // Đánh dấu bước 1

    cout << "Ket qua Ma di tuan (" << N << "x" << N << "):\n\n";

    // Bắt đầu thử từ bước thứ 2
    Try(2, start_x, start_y);

    if (thanh_cong) {
        inBanCo();
    } else {
        cout << "Khong tim thay duong di nao!" << endl;
    }

    return 0;
}