#include <iostream>
#include <iomanip>

using namespace std;

#define N 8 // Số lượng quân hậu và kích thước bàn cờ 8x8

int a[N + 1];           // a[k] = i nghĩa là quân hậu ở hàng k được đặt tại cột i
bool thanh_cong = false; // Cờ đánh dấu đã xếp xong 8 quân hậu

// Các mảng dùng để kiểm tra tính "an toàn" (true = an toàn/chưa bị chiếm)
bool cot[N + 1];         // Đánh dấu cột
bool cheoXuoi[2 * N];    // Đánh dấu đường chéo xuôi (k - i + N)
bool cheoNguoc[2 * N];   // Đánh dấu đường chéo ngược (k + i)

// Hàm in bàn cờ khi tìm được kết quả
void inBanCo() {
    cout << "Cach dat " << N << " quan hau an toan:\n\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (a[i] == j) {
                cout << setw(3) << "X" << " "; // Vị trí có hậu
            } else {
                cout << setw(3) << "." << " "; // Ô trống
            }
        }
        cout << "\n";
    }
    cout << "\n--------------------------------\n";
}

// Hàm đệ quy Try bám sát mã giả trong slide
// k: hàng đang xét để đặt quân hậu thứ k
void Try(int k) {
    // Khởi động chọn vị trí cho hậu thứ k; (thử từ cột 1)
    int i = 1; 
    
    do {
        // Thực hiện việc chọn vị trí cho hậu thứ k (vị trí (k, i))
        
        // if (an toàn) {
        if (cot[i] && cheoXuoi[k - i + N] && cheoNguoc[k + i]) {
            
            // Đặt hậu vào vị trí;
            a[k] = i; 
            cot[i] = false;               // Cột i đã bị chiếm
            cheoXuoi[k - i + N] = false;  // Đường chéo xuôi đã bị chiếm
            cheoNguoc[k + i] = false;     // Đường chéo ngược đã bị chiếm
            
            // if (k < 8) {
            if (k < N) {
                Try(k + 1); // Đệ quy đặt quân hậu tiếp theo
                
                // if (không thành)
                if (!thanh_cong) {
                    // Cất hậu; (Trạng thái quay lui - Backtracking)
                    cot[i] = true;
                    cheoXuoi[k - i + N] = true;
                    cheoNguoc[k + i] = true;
                }
            } 
            // Đoạn này xử lý khi k = 8 (đã đặt xong quân hậu cuối cùng)
            else {
                thanh_cong = true; // Đánh dấu thành công để thoát các vòng lặp do...while
            }
        }
        
        // Chuyển sang thử vị trí cột tiếp theo
        i++; 
        
    // }while ( (chưa thành công) && (chưa hết chỗ đặt hậu) );
    } while (!thanh_cong && i <= N);
}

int main() {
    // Khởi tạo ban đầu: mọi cột và đường chéo đều an toàn (chưa có hậu)
    for (int i = 1; i <= N; i++) cot[i] = true;
    for (int i = 1; i < 2 * N; i++) {
        cheoXuoi[i] = true;
        cheoNguoc[i] = true;
    }

    // Bắt đầu đặt quân hậu đầu tiên ở hàng 1
    Try(1);

    // Kiểm tra kết quả
    if (thanh_cong) {
        inBanCo();
    } else {
        cout << "Khong tim thay cach dat nao!" << endl;
    }

    return 0;
}
