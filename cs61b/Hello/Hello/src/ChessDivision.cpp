#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

const int MAX_N = 15;
const int INF = numeric_limits<int>::max();

int n;
int grid[MAX_N][MAX_N];
int sum[MAX_N + 1][MAX_N + 1];

// 计算从 (x1, y1) 到 (x2, y2) 的矩形和
int rectSum(int x1, int y1, int x2, int y2) {
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

void calculateSum() {
    // 计算累积和
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum[i][j] = grid[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
}

// 计算最小方差
double solve(int x1, int y1, int x2, int y2, int k, vector<vector<vector<vector<double>>>>& dp) {
    // 如果已经计算过，直接返回
    if (dp[x1][y1][x2][y2] != INF) return dp[x1][y1][x2][y2];

    // 计算当前矩形的和
    int currentSum = rectSum(x1, y1, x2, y2);

    // 如果 k == 1，方差为 0
    if (k == 1) {
        double avg = (double)currentSum;
        return dp[x1][y1][x2][y2] = avg * avg;
    }

    double res = INF;

    // 尝试水平分割
    for (int i = x1; i < x2; ++i) {
        res = min(res, solve(x1, y1, i, y2, k - 1, dp) + solve(i + 1, y1, x2, y2, 1, dp));
        res = min(res, solve(x1, y1, i, y2, 1, dp) + solve(i + 1, y1, x2, y2, k - 1, dp));
    }

    // 尝试竖直分割
    for (int j = y1; j < y2; ++j) {
        res = min(res, solve(x1, y1, x2, j, k - 1, dp) + solve(x1, j + 1, x2, y2, 1, dp));
        res = min(res, solve(x1, y1, x2, j, 1, dp) + solve(x1, j + 1, x2, y2, k - 1, dp));
    }

    // 更新 dp
    return dp[x1][y1][x2][y2] = res;
}

int main() {
    cin >> n;
    int totalSum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            totalSum += grid[i][j];
        }
    }

    calculateSum();

    // 初始化 dp，4 维数组用于存储结果
    vector<vector<vector<vector<double>>>> dp(n + 1, vector<vector<vector<double>>>(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, INF))));

    // 计算最终结果
    double result = solve(1, 1, n, n, n, dp);
    cout.precision(5);
    cout << fixed << result / n << endl;

    return 0;
}
