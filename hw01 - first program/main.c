#include <stdio.h>

int main(void){
    int x;
    int y;
    scanf("%d %d", &x, &y);
    if ((x>10000||x<-10000)||(y > 10000||y < -10000))
    {
        printf("Vstup je mimo interval!\n");
        return 0;
    } else{
        printf("Desitkova soustava: %d %d\n", x, y);
        printf("Sestnactkova soustava: %x %x\n", x, y);
        int soucet = x +y;
        printf("Soucet: %d + %d = %d\n", x, y, soucet);
        int rozdil = x - y;
        printf("Rozdil: %d - %d = %d\n", x, y, rozdil);
        int soucin = x * y;
        printf("Soucin: %d * %d = %d\n", x, y, soucin);
        if (y == 0)
        {
            printf("Nedefinovany vysledek!\n");
        } else {
            int podil = x/y;
            printf("Podil: %d / %d = %d\n", x, y, podil);
        }
        double dva = 2;
        double prumer = ((x+y)/dva);
        printf("Prumer: %.1f\n", prumer);
        return 0;
    }
}
    
