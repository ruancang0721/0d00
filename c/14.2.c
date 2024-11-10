#include <stdio.h>
#include <string.h>
#include <ctype.h>
int runnian(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int mouthnumber(const char *month) 
{
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December",
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    for (int i = 0; i < 24; i++) 
    {
        if (strcasecmp(month, months[i]) == 0) 
        {
            return (i % 12) + 1;
        }
    }
    return atoi(month);
}

int dayinmonth(int month, int year) 
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && runnian(year))
    {
        return 29;
    }
    return days[month - 1];
}
int sumdays(int day, int month, int year)
 {
    int totalDays = day;
    for (int i = 1; i < month; i++)
    {
        totalDays += dayinmonth(i, year);
    }
    return totalDays;
}

int main() {
    int day, year;
    char monthinput[20];
    printf("请输入年: ");
    scanf("%d", &year);
    printf("请输入月(数值、名称或缩写): ");
    scanf("%s", monthinput);
    printf("请输入日: ");
    scanf("%d", &day);
    int month = mouthnumber(monthinput);
    if (month < 1 || month > 12 || day < 1 || day > dayinmonth(month, year))
    {
        printf("日期无效。\n");
        return 1;
    }
    int result = sumdays(day, month, year);
    printf("从年初到您指定的日期共有 %d 天.\n", result);

    return 0;
}
