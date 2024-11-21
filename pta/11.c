#include <stdio.h>

int main() {
    int N, X;
    
    // 输入N和X
    scanf("%d %d", &N, &X);
    
    int numbers[20]; // 定义一个大小为20的数组来储存输入的整数
    // 输入N个整数
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    // 查找X的位置
    for (int i = 0; i < N; i++) {
        if (numbers[i] == X) {
            printf("%d\n", i); // 如果找到，输出位置
            return 0; // 找到后退出程序
        }
    }
    
    // 如果没有找到，输出“Not Found”
    printf("Not Found\n");
    return 0;
}
