#include <iostream>
#include <cmath>
using namespace std;

// 度分秒转换为弧度
double dmsToRadians(int degrees, int minutes, int seconds) {
    double decimalDegrees = degrees + minutes / 60.0 + seconds / 3600.0;
    return decimalDegrees * M_PI / 180.0;
}

// 解五边形
void solvePentagon(double a, double b, double c,
                   int Adeg, int Amin, int Asec,
                   int Bdeg, int Bmin, int Bsec,
                   int Cdeg, int Cmin, int Csec,
                   int Ddeg, int Dmin, int Dsec,
                   int Edeg, int Emin, int Esec) {
    double A = dmsToRadians(Adeg, Amin, Asec);
    double B = dmsToRadians(Bdeg, Bmin, Bsec);
    double C = dmsToRadians(Cdeg, Cmin, Csec);
    double D = dmsToRadians(Ddeg, Dmin, Dsec);
    double E = dmsToRadians(Edeg, Emin, Esec);

    // 使用正弦定理和几何关系求解另外两条边
    // 这里假设已知边为a, b, c，依次相邻
    // 首先计算辅助角
    double alpha = M_PI - A - B;
    double beta = M_PI - C - (M_PI - alpha);

    double d = b * sin(alpha) / sin(beta);
    double e = d * sin(D) / sin(E);

    cout << "边d的长度为: " << d << endl;
    cout << "边e的长度为: " << e << endl;
}


int main() {
    double a, b, c;
    int Adeg, Amin, Asec;
    int Bdeg, Bmin, Bsec;
    int Cdeg, int Cmin, int Csec;
    int Ddeg, Dmin, Dsec;
    int Edeg, Emin, Esec;

    cout << "请输入已知边a的长度: ";
    cin >> a;
    cout << "请输入已知边b的长度: ";
    cin >> b;
    cout << "请输入已知边c的长度: ";
    cin >> c;

    cout << "请输入角A的度数、分数、秒数: ";
    cin >> Adeg >> Amin >> Asec;
    cout << "请输入角B的度数、分数、秒数: ";
    cin >> Bdeg >> Bmin >> Bsec;
    cout << "请输入角C的度数、分数、秒数: ";
    cin >> Cdeg >> Cmin >> Csec;
    cout << "请输入角D的度数、分数、秒数: ";
    cin >> Ddeg >> Dmin >> Dsec;
    cout << "请输入角E的度数、分数、秒数: ";
    cin >> Edeg >> Emin >> Esec;

    solvePentagon(a, b, c, Adeg, Amin, Asec, Bdeg, Bmin, Bsec, Cdeg, Cmin, Csec, Ddeg, Dmin, Dsec, Edeg, Emin, Esec);

    return 0;
}


