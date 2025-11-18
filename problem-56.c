#include <stdio.h>

typedef struct Circle
{
    double radius;
} Circle;

void ShowResult(Circle c)
{
    printf("지름: %.2lf, 원의 둘레: %.2lf, 원주율: %.2lf\n",
           c.radius * 2, 2 * 3.14 * c.radius, (c.radius * 2) * 3);
}

Circle GetCurrentCircle(void)
{
    Circle c;
    printf("Input radius: ");
    scanf("%lf", &c.radius);
    return c;
}

int main()
{
    Circle myCircle = GetCurrentCircle();
    ShowResult(myCircle);
    return 0;
}