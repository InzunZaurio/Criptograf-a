#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>



int key_generator(int n, int n2, int n3){
    int conjunto_z[n + 1];
    int z_index = 0;
    int zStar_index = 0;
    int tope_Conjunto = n;
    int x=0;

    for (int i = 0; i <= tope_Conjunto; i++) {
        conjunto_z[z_index++] = i;
        if ((i % n2 != 0) && (i % n3 != 0) && (i<=tope_Conjunto) && (i>0)) {
            x++;
        }
    }

    int conjunto_zStar[x];
    for(int i = 0; i <= tope_Conjunto; i++){
        if (i % n2 != 0 && i % n3 != 0 && i<=tope_Conjunto && i>0) {
            conjunto_zStar[zStar_index++] = i;
        }
    }

    printf("Conjunto Z: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", conjunto_z[i]);
    }
    printf("\n");

    printf("Conjunto Z Star: ");
    for (int i = 0; i < x; i++) {
        if (conjunto_zStar[i] != 0) {
            printf("%d ", conjunto_zStar[i]);
        }
    }

    int keyB , keyA = 0;

    int controllerA = rand() % (n);
    int controllerB = rand() % (x);
    keyB = conjunto_zStar[controllerB];
    keyA = rand() % (n+1);

    printf("\nTu clave generada es: (%d, %d)", keyA, keyB);
    printf("\n");
}

bool stray(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int find_strays(int n) {
    int primo1, primo2;
    for (int i = 2; i <= n / 2; i++) {
        if (stray(i) && stray(n / i)) {
            primo1 = i;
            primo2 = n / i;
            break;
        }
    }
    if (primo1 != 0 && primo2 != 0) {
        printf("Los numeros primos a considerar son: %d y %d\n", primo1, primo2);
        key_generator(n, primo1, primo2);
        return 1;
    } else {
        printf("No se encontraron dos numeros primos que multiplicados den %d\n", n);
        return 0;
    }
}

int main() {
    srand(time(NULL));
    int n;
    printf("Dame el valor del conjunto n:");
    scanf("%d", &n);

    find_strays(n);
    return 0;
}