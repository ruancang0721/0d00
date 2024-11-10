#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int beint(const char * QAQ) {
    int result = 0;
    while (*QAQ) {
        result = (result << 1) | (*QAQ++ - '0');
    }
    return result;
}

void bechar(int num, char *QAQ, int length) {
    QAQ[length] = '\0';
    for (int i = length - 1; i >= 0; i--) {
        QAQ[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("使用方法: %s <二进制字符串1> <二进制字符串2>\n", argv[0]);
        return 1;
    }

    int num1 = beint(argv[1]);
    int num2 = beint(argv[2]);
    int length = (strlen(argv[1]) > strlen(argv[2])) ? strlen(argv[1]) : strlen(argv[2]);
    char result[length + 1];

    bechar(~num1, result, length);
    printf("~%s = %s\n", argv[1], result);

    bechar(~num2, result, length);
    printf("~%s = %s\n", argv[2], result);

    bechar(num1 & num2, result, length);
    printf("%s & %s = %s\n", argv[1], argv[2], result);

    bechar(num1 | num2, result, length);
    printf("%s | %s = %s\n", argv[1], argv[2], result);

    bechar(num1 ^ num2, result, length);
    printf("%s ^ %s = %s\n", argv[1], argv[2], result);

    return 0;
}
