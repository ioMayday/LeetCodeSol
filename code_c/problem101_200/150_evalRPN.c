#define HALF_NUM 2
int StackCal(const char *p, int *stackArray, int top)
{
    if (p[1] == '\0' && p[0] == '+') {
        stackArray[top - 1] += stackArray[top];
        top--;
    } else if (p[1] == '\0' && p[0] == '-') {
        stackArray[top - 1] -= stackArray[top];
        top--;
    } else if (p[1] == '\0' && p[0] == '*') {
        stackArray[top - 1] *= stackArray[top];
        top--;
    } else if (p[1] == '\0' && p[0] == '/') {
        stackArray[top - 1] /= stackArray[top];
        top--;
    } else {
        stackArray[++top] = atoi(p);
    }
    return top;
}

int evalRPN(char ** tokens, int tokensSize)
{
    int res;
    int *stackArray = (int*)malloc((tokensSize / HALF_NUM + 1) * sizeof(int)); // û��1ʱ��Խ�磬��["4","13","5","/","+"]
    int top = -1;

    int i;
    for (i = 0; i < tokensSize; i++) {
        top = StackCal(tokens[i], stackArray, top);
    }
    if (top == 0) { // ����ɹ���top�ص�����ջ��β
        res = stackArray[0];
        free(stackArray);
        return res;
    }
    return -1;
}
