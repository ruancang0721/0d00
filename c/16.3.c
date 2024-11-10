#include <stdio.h>
#include <math.h>
typedef struct{
    double mu;
    double angle;
}ji;
typedef struct
{
    double x;
    double y;
}point;
point zhuanhuan(ji *j)
{
    point c;
    double angle_rad = j->angle * (3.1415926 / 180.0); // 将角度转换为弧度
    c.x = j->mu * cos(angle_rad);
    c.y = j->mu * sin(angle_rad);
    return c;
}

int main()
{
    ji p;
    printf("输入模");
    scanf("%lf", &p.mu);
    printf("输入角度");
    scanf("%lf", &p.angle);
    point c = zhuanhuan(&p);
    printf("x坐标%lf\n", c.x);
    printf("y坐标%lf\n", c.y);
    return 0;
}

