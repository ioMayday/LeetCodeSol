#include limits.h

 ����״̬��������
 ��ǰ�������꣬����������ȥ����һ�ʽ���
 ģ�� 
״̬ת�Ʒ��̣�
dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + price[i]);
dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - price[i]);

Base Case
dp[-1][k][0] = 0;
dp[-1][k][1] = -Infinity; ������
dp[i][0][0] = 0;
dp[i][0][1] = -Infinity;

 output dp[n - 1][k][0]
#define max(a, b) (a)  (b)  (a)  (b)
#define MAX_K_NUM 2
 �䶳��һ������ת��Ϊ��һ��������������������һ��ѭ��  = ��˼·���ԣ��ᵼ���޷��ƹ�ת�ƾ��󣬵õ����п������
 ��ȷ�������޸�״̬ת�Ʒ��̣�����ʱ����ǰ���첻����״̬������ת�ƹ�����i-1 ��Ϊ i-2
int maxProfit(int prices, int pricesSize)
{
     k = +infinity
    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    int i;
    int pre_dp_i_0 = 0;
    for (i = 0; i  pricesSize; i++) {
         dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + price[i]);  ����������
         dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 2][k - 1][0] - price[i]);  ����������
        int tmp = dp_i_0;  ����ǰ
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);  ��ǰ���º�
        dp_i_1 = max(dp_i_1, pre_dp_i_0 - prices[i]);
        pre_dp_i_0 = tmp;  �´�ѭ����ʱ���ͱ����ǰ�����
    }
    return dp_i_0;
}