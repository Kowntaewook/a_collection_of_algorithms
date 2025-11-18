#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    for(int i = 0; i < 3; i++)
    {
        if(a > b && a > c)
        {
            printf("가장 인기 있는 메뉴는 %d표를 얻었습니다.", a);
            break;
        }
        else if(b > a && b > c)
        {
            printf("가장 인기 있는 메뉴는 %d표를 얻었습니다.", b);
            break;
        }
        else if(c > a && c > b)
        {
            printf("가장 인기 있는 메뉴는 %d표를 얻었습니다.", c);
            break;
        }
        else if(a == b && a > c)
        {
            printf("가장 인기 있는 메뉴는 %d표를 얻었습니다.", a);
            break;
        }
        else if(b == c && b > a)
        {
            printf("가장 인기 있는 메뉴는 %d표를 얻었습니다.", b);
            break;
        }
        else if(a == c && a > b)
        {
            printf("가장 인기 있는 메뉴는 %d표를 얻었습니다.", a);
            break;
        }
        else
        {
            printf("모두 같습니다.");
            break;
        }
    }
    return 0;
}