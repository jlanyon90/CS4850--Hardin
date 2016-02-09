    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>


int main(){
    int i=4;
    printf("poop\n");
    char po [100] = "piop";
    printf(">%s<\n",po);
    int length = strlen(po);
    printf("length %d\n", length);
    po[length] = i+'0';
    length = strlen(po);
    printf("length %d\n", length);
    printf("KLKLKJLJK\n");
    printf(">%s<\n",po);
}