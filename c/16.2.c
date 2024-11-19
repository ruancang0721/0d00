#include <stdio.h>
#define tiaohe(x, y) (2.0 / ((1.0 / (x)) + (1.0 / (y))))

int main() {
    double num1, num2;
    printf("请输入第一个数: ");
    scanf("%lf", &num1);
    printf("请输入第二个数: ");
    scanf("%lf", &num2);
    double result = tiaohe(num1, num2);
    printf("数字 %.2f 和 %.2f 的调和平均数是: %.2f\n", num1, num2, result);
    return 0;
}
