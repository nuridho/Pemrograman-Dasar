#include<iostream>
#include<cmath>
using namespace std;

struct pasanganxy {
    float x;
    float y;
    float xy;
    float xkuadrat;
    float ykuadrat;
};
pasanganxy input_xy[50];

int main(){
    int n;
    float sigmax, sigmaxkuadrat, sigmay, sigmaykuadrat, sigmaxy, jum_sigmaxkuadrat, jum_sigmaykuadrat, bar_atas, bar_bawah, akar_x, akar_y, oprs_x, oprs_y, r;
    sigmax = 0; sigmay = 0; sigmaxy = 0; sigmaxkuadrat = 0; sigmaykuadrat = 0; jum_sigmaxkuadrat = 0; jum_sigmaykuadrat = 0; bar_atas =0; bar_bawah=0; akar_x=0; akar_y=0;
    oprs_x =0; oprs_y = 0; r = 0;
    cout << "Masukkan banyak n : ";
    cin >> n;
    for(int i = 1; i<=n;i++){
        cout << "Input x-" << i << " : ";
        cin >> input_xy[i].x;
        cout << "Input y-" << i << " : ";
        cin >> input_xy[i].y;
        cout << "====" << endl; 
    }

    cout << "===OUTPUT sigma x, sigma y, sigmaxy==" << endl;
    //sigma x, y, xy
    for(int i = 1; i <= n; i++){
        sigmax = input_xy[i].x + sigmax;
        sigmay = input_xy[i].y + sigmay;
        input_xy[i].xy= input_xy[i].x * input_xy[i].y;
        sigmaxy += input_xy[i].xy;
    }
        cout << "Penampilan sigma x : " << sigmax << endl;
        cout << "Penampilan sigma y : " << sigmay << endl;
        cout << "Penampilan sigma xy : " << sigmaxy << endl;
    cout << "====bar atas===" << endl;
    // bar atas
        bar_atas = sigmaxy - (sigmax*sigmay);
        cout << bar_atas << endl;
        cout << "===Output sigma x kuadrat, sigma y kuadrat======" << endl;
    for(int i =1; i <=n; i++) {
        input_xy[i].xkuadrat = input_xy[i].x * input_xy[i].x;
        sigmaxkuadrat += input_xy[i].xkuadrat;
        input_xy[i].ykuadrat = input_xy[i].y * input_xy[i].y;
        sigmaykuadrat += input_xy[i].ykuadrat;
    }
    jum_sigmaxkuadrat = sigmax * sigmax;
    jum_sigmaykuadrat = sigmay * sigmay;
    oprs_x = sigmaxkuadrat - jum_sigmaxkuadrat;
    oprs_y = sigmaykuadrat - jum_sigmaykuadrat;
    bar_bawah = sqrt(sigmaxkuadrat - jum_sigmaxkuadrat) * sqrt(sigmaykuadrat - jum_sigmaykuadrat);
    cout << "Penampilan sigma x kuadrat : " << sigmaxkuadrat << endl;
    cout << "Penampilan sigma y kuadrat : " << sigmaykuadrat << endl;
    cout << "Penampilan jumlah sigma x kuadrat : " << jum_sigmaxkuadrat << endl;
    cout << "Penampilan jumlah sigma y kuadrat : " << jum_sigmaykuadrat << endl;
    cout << "===Bar Bawah====" << endl;
    cout << bar_bawah << endl;
    r = (sigmaxy - sigmax*sigmay) / (sqrt(sigmaxkuadrat - jum_sigmaxkuadrat) * sqrt(sigmaykuadrat - jum_sigmaykuadrat)); 
    cout << "=====Hasil R======" << endl;
    cout << "r = " << r << endl;
    float koef_determinasi_r = r * r * 100 /100;
    cout << "Koefisien Determinasi R = " << koef_determinasi_r << endl;
    cout << "Kekuatan Hubungan dari nilai Korelasi : " ;
    if(r <= 0.09) cout << "Hubungan Korelasinya diabaikan" << endl;
    else if (r <= 0.29) cout << "Hubungan Korelasinya rendah" << endl;
    else if(r <= 0.49) cout << "Hubungan Korelasinya moderat" << endl;
    else if(r <= 0.7) cout << "Hubungan Korelasinya sedang" << endl;
    else if(r >0.7) cout << "Hubungan Korelasinya sangat kuat" << endl;
    
    cout << "======" << endl;
    if(r> 0) cout << "Hubungan antara variabel x dan y adalah positif, dimana jika nilai x bertambah, maka nilai y pun bertambah, dan juga sebaliknya" << endl;
    else if(r<0) cout << "Hubungan antara variabel x dan y adalah negatif, dimana jika nilai x betambah, maka nilai y akan mengecil, dan juga sebaliknya" << endl;
    else if(r==0) cout << "Tidak Ada Hubungan antara antara variabel x dan y" << endl; 
}
