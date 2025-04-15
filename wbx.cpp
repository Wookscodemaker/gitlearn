#include <iostream>
#include <cmath>
using namespace std;

// 定义常量
const double PI = 3.14159265358979323846;

// 函数：将度分秒转换为十进制度数
double toDecimalDegrees(int degrees, int minutes, double seconds) {
    return degrees + minutes / 60.0 + seconds / 3600.0;
}

// 函数：将角度转换为弧度
double toRadians(double degrees) {
    return degrees * PI / 180.0;
}

// 函数：计算两条边和夹角的余弦定理
double calculateSide(double a, double b, double angle) {
    return sqrt(a * a + b * b - 2 * a * b * cos(toRadians(angle)));
}

int main() {
    // 输入已知的三条边的长度
    double a, b, c;
    cout << "请输入五边形的三条相邻边的长度 a, b, c: ";
    cin >> a >> b >> c;

    // 输入五个内角的度分秒
    int angleADeg, angleAMin;
    double angleASec;
    int angleBDeg, angleBMin;
    double angleBSec;
    int angleCDeg, angleCMin;
    double angleCSec;
    int angleDDeg, angleDMin;
    double angleDSec;
    int angleEDeg, angleEMin;
    double angleESec;

    cout << "请输入五边形的五个内角的度分秒（格式：度 分 秒）: " << endl;
    cout << "角A: ";
    cin >> angleADeg >> angleAMin >> angleASec;
    cout << "角B: ";
    cin >> angleBDeg >> angleBMin >> angleBSec;
    cout << "角C: ";
    cin >> angleCDeg >> angleCMin >> angleCSec;
    cout << "角D: ";
    cin >> angleDDeg >> angleDMin >> angleDSec;
    cout << "角E: ";
    cin >> angleEDeg >> angleEMin >> angleESec;

    // 将度分秒转换为十进制度数
    double angleA = toDecimalDegrees(angleADeg, angleAMin, angleASec);
    double angleB = toDecimalDegrees(angleBDeg, angleBMin, angleBSec);
    double angleC = toDecimalDegrees(angleCDeg, angleCMin, angleCSec);
    double angleD = toDecimalDegrees(angleDDeg, angleDMin, angleDSec);
    double angleE = toDecimalDegrees(angleEDeg, angleEMin, angleESec);

    // 检查内角和是否为540度
    double angleSum = angleA + angleB + angleC + angleD + angleE;
    if (abs(angleSum - 540.0) > 0.001) {
        cout << "输入的内角和不等于540度，无法构成五边形！" << endl;
        return 1;
    }

    // 假设五边形可以通过某些几何关系近似求解
    // 计算对角线 d 的长度（假设 d 是连接顶点 A 和 C 的对角线）
    double d = calculateSide(a, b, 180.0 - angleA);

    // 假设对角线 d 和边 c 可以构成另一个三角形
    // 计算边 e 的长度（假设 e 是连接顶点 C 和 E 的边）
    double e = calculateSide(d, c, 180.0 - angleC);

    // 输出结果
    cout << "计算得到的另外两条边的长度为：" << endl;
    cout << "对角线 d = " << d << endl;
    cout << "边 e = " << e << endl;

    return 0;
}
    