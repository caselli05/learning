#include <stdio.h>
#include <math.h>

int main(void){
    float x1, y1, x2, y2;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    printf("%.4f\n", sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));



    return 0;
}