#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

//Funcion 2
int do_inverse(int n, int a){
    int inverse;
    for(int i=1; i<n;i++){
        if(((a*i)%n) == 1){
            inverse = i;
            printf("The inverse of %d is %d\n", a, inverse);
            return inverse;
        }
    }
}

//Funcion 4
int ascii_decipher(int n, int n2, int n3){
    n = 126;
    int conjunto_z[n + 1];
    int z_index = 0;
    int zStar_index = 0;
    int tope_Conjunto = n;
    int x=0;
    char cadena[100];

    printf("Ingresa la palabra a descifrar: \n");
    scanf("%s", &cadena);

    int neoKeyA=0, neoKeyB=0;
    printf("Ingresa la tupla de llaves a utilizar, primero A: \n");
    scanf("%d", &neoKeyA);
    fflush(stdin);
    printf("Ahora B: \n");
    scanf("%d", &neoKeyB);
    fflush(stdin);

    // Eliminar el salto de línea, si existe
    if (cadena[strlen(cadena) - 1] == '\n') {
        cadena[strlen(cadena) - 1] = '\0';
    }

    int ext_C = strlen(cadena);
    int C[ext_C];
    char decipherText[ext_C];

    for (int i = 0; cadena[i] != '\0'; i++) {
        C[i] = (int)cadena[i];
    }

    for (int i = 32; i <= tope_Conjunto; i++) {
        conjunto_z[z_index++] = i;
        if ((i % n2 != 0) && (i % n3 != 0) && (i<=tope_Conjunto) && (i>0)) {
            x++;
        }
    }

    int conjunto_zStar[x];
    for(int i = 32; i <= tope_Conjunto; i++){
        if (i % n2 != 0 && i % n3 != 0 && i<=tope_Conjunto && i>0) {
            conjunto_zStar[zStar_index++] = i;
        }
    }

    int gcd(int a, int b){
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    if(gcd(neoKeyA, n) != 1){
        printf("Tu clave A es probable que no funcione...");
    }
    else if(gcd(neoKeyB, n) != 1){
        printf("Tu clave B es probable que no funcione...");
    }

    printf("C en ASCII: [");
    for (int i = 0; cadena[i] != '\0'; i++) {
        printf("%d", C[i]);
        if (cadena[i + 1] != '\0') {
            printf(", ");
        }
    }
    printf("]\n");
    
    int a_inversa = do_inverse(94, neoKeyA);
    int decipherModuleNEG = 0, decipherModulePOS = 0;
    for (int i = 0; i < ext_C; i++) {
        int temp = (C[i] - neoKeyB) * a_inversa;  // Calcular el resultado sin tomar el módulo aún
        if (temp < 0) {
            decipherModuleNEG = (94 + (temp % 94)) % 94;  // Asegurar que el resultado sea positivo y esté en el rango correcto
            decipherText[i] = conjunto_z[decipherModuleNEG];
        } else {
            decipherModulePOS = temp % 94; 
            decipherText[i] = conjunto_z[decipherModulePOS];
        }
    }

    decipherText[ext_C] = '\0'; // Agregar el carácter nulo al final de la cadena cifrada

    printf("%s", decipherText);
}

//Funcion 3
int ascii_cipher(int n, int n2, int n3){
    n = 126;
    int conjunto_z[n + 1];
    int z_index = 0;
    int zStar_index = 0;
    int tope_Conjunto = n;
    int x=0;
    char cadena[100];

    printf("Ingresa la palabra a cifrar: ");
    scanf("%s", &cadena);

    // Eliminar el salto de línea, si existe
    if (cadena[strlen(cadena) - 1] == '\n') {
        cadena[strlen(cadena) - 1] = '\0';
    }

    int ext_M = strlen(cadena);
    int M[ext_M];
    char cipherText[ext_M];

    for (int i = 0; cadena[i] != '\0'; i++) {
        M[i] = (int)cadena[i];
    }

    for (int i = 32; i <= tope_Conjunto; i++) {
        conjunto_z[z_index++] = i;
        if ((i % n2 != 0) && (i % n3 != 0) && (i<=tope_Conjunto) && (i>0)) {
            x++;
        }
    }

    int conjunto_zStar[x];
    for(int i = 32; i <= tope_Conjunto; i++){
        if (i % n2 != 0 && i % n3 != 0 && i<=tope_Conjunto && i>0) {
            conjunto_zStar[zStar_index++] = i;
        }
    }

    int keyB , keyA = 0;
    int gcd(int a, int b){
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    do {
        int controllerB = rand() % (x);
        keyB = conjunto_zStar[controllerB];
    } while (gcd(keyB, n) != 1);

    do {
        keyA = 32 + rand() % n;  // Generar número aleatorio entre 1 y n
    } while (gcd(keyA, n) != 1);

    printf("\nTu clave generada PARA ASCII es: (%d, %d)", keyA, keyB);
    printf("\n");
    printf("M en ASCII: [");
    for (int i = 0; cadena[i] != '\0'; i++) {
        printf("%d", M[i]);
        if (cadena[i + 1] != '\0') {
            printf(", ");
        }
    }
    printf("]\n");

    for(int i = 0;i<ext_M;i++){
        int cipherModule = (keyA*M[i]+keyB)%94;
        cipherText[i]=conjunto_z[cipherModule];
    }
    cipherText[ext_M] = '\0'; // Agregar el carácter nulo al final de la cadena cifrada
    printf("%s", cipherText);
}


//Funcion 1
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

    int keyB , keyA = 0;

    int gcd(int a, int b){
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    do {
        int controllerB = rand() % (x);
        keyB = conjunto_zStar[controllerB];
    } while (gcd(keyB, n) != 1);

    do {
        keyA = 1 + rand() % n;  // Generar número aleatorio entre 1 y n
    } while (gcd(keyA, n) != 1);

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

int find_strays(int n, int controller) {
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
        if(controller==0){
            ascii_cipher(n, primo1, primo2);
        }
        else if(controller==1){
            key_generator(n, primo1, primo2);
        }
        else if(controller==2){
            ascii_decipher(n, primo1, primo2);
        }
        return 1;
    } else {
        printf("No se encontraron dos numeros primos que multiplicados den %d\n", n);
        return 0;
    }
}




int main() {
    srand(time(NULL));  // Cambiar la semilla de aleatoriedad
    int opcion;
    int n,a;
    char cadena[100];
    printf("Select the function that you want to try:\n");
    printf("1.- Function 1: Find a valid key\n");
    printf("2.- Function 2: Find the multiplicative inverse\n");
    printf("3.- Function 3: Cipher\n");
    printf("4.- Function 4: Decipher\n");
    printf("Choose your option:\n");
    scanf("%d", &opcion);

    switch(opcion){
        case 1: printf("Give me the value of n:");
                scanf("%d", &n);
                find_strays(n,1);
                break;
        case 2: printf("Give me the value of n:");
                scanf("%d", &n);
                printf("Insert the number that you'd like to know it's inverse:");
                scanf("%d", &a);
                do_inverse(n,a);
                break;
        case 3: n=94;
                find_strays(n,0);
                break;
        case 4: n=94;
                find_strays(n,2);
                break;
        case 5: printf("Letra: ");
                char numcar = 'k';
                printf("El numero es: %d", numcar);
                break;
        default:printf("Opción no válida");
                break;
    }
    
    return 0;
}
