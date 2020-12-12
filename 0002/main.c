#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
   //b^2-4ac=delta
    //x1,2=-b+-kokdelta/2a
    printf("2. dereceden f(x) fonksiyonun a,b,c katsayilarini giriniz :");

    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int delta = pow(b,2)-4*a*c;
    int x1=(-b+sqrt(delta))/2*a;
    int x2=(-b-sqrt(delta))/2*a;
    printf("x1: %d , x2 : %d",x1,x2);
    return 0;
}
