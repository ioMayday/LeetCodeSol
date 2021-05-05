#include <limits.h>

// ����״̬��������
// ��ǰ�������꣬����������ȥ����һ�ʽ���
/**** ģ�� **********
״̬ת�Ʒ��̣�
dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + price[i]);
dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - price[i]);

Base Case:
dp[-1][k][0] = 0;
dp[-1][k][1] = -Infinity; //������
dp[i][0][0] = 0;
dp[i][0][1] = -Infinity;
********************/
// output: dp[n - 1][k][0]
#define max(a, b) (a) > (b) ? (a) : (b)
int maxProfit(int* prices, int pricesSize){
    // k = 1
    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    int i;
    for (i = 0; i < pricesSize; i++) {
        // dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + price[i]);
        // dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][0] - price[i]);
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1,  -prices[i]);
    }
    return dp_i_0;
}