#include <iostream>
#include <cmath>

using namespace std;

// 将度分秒转换为弧度
double dmsToRadians(int degrees, int minutes, int seconds) {
    double decimalDegrees = degrees + minutes / 60.0 + seconds / 3600.0;
    return decimalDegrees * M_PI / 180.0; // 转换为弧度
}

int main() {
    // 输入已知边长
    double AB, BC, CD;
    cout << "请输入三条相邻边的长度 (AB, BC, CD): ";
    cin >> AB >> BC >> CD;

    // 输入五个内角的度分秒
    int angles[5][3]; // 每个角度存储 [度, 分, 秒]
    for (int i = 0; i < 5; ++i) {
        cout << "请输入第 " << i + 1 << " 个内角的度分秒（格式：度 分 秒）: ";
        cin >> angles[i][0] >> angles[i][1] >> angles[i][2];
    }

    // 将五个内角转换为弧度
    double angleA = dmsToRadians(angles[0][0], angles[0][1], angles[0][2]);
    double angleB = dmsToRadians(angles[1][0], angles[1][1], angles[1][2]);
    double angleC = dmsToRadians(angles[2][0], angles[2][1], angles[2][2]);
    double angleD = dmsToRadians(angles[3][0], angles[3][1], angles[3][2]);
    double angleE = dmsToRadians(angles[4][0], angles[4][1], angles[4][2]);

    // 计算剩余两条边 DE 和 EA
    // 使用余弦定理逐步计算
    double BD; // 对角线 BD 的长度
    double BE; // 对角线 BE 的长度

    // 计算对角线 BD 的长度（通过三角形 ABD）
    BD = sqrt(AB * AB + BC * BC - 2 * AB * BC * cos(angleB));

    // 计算对角线 BE 的长度（通过三角形 BCD）
    BE = sqrt(BC * BC + CD * CD - 2 * BC * CD * cos(angleC));

    // 计算边 DE 的长度（通过三角形 BDE）
    double angleDBE = angleE - angleB; // BDE 角度差
    double DE = sqrt(BD * BD + BE * BE - 2 * BD * BE * cos(angleDBE));

    // 计算边 EA 的长度（通过三角形 ABE）
    double angleABE = angleA + angleB; // ABE 角度和
    double EA = sqrt(AB * AB + BE * BE - 2 * AB * BE * cos(angleABE));

    // 输出结果
    cout << "边 DE 的长度为: " << DE << endl;
    cout << "边 EA 的长度为: " << EA << endl;

    return 0;
}