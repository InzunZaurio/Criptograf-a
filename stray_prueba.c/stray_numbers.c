#include <stdio.h>
#include <stdbool.h>

bool es_primo(int num) {
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

void encontrar_primos_multiplicados(int n) {
    int primo1, primo2;
    for (int i = 2; i <= n / 2; i++) {
        if (es_primo(i) && es_primo(n / i)) {
            primo1 = i;
            primo2 = n / i;
            break;
        }
    }
    if (primo1 != 0 && primo2 != 0) {
        printf("Dos números primos que multiplicados dan %d son: %d y %d\n", n, primo1, primo2);
    } else {
        printf("No se encontraron dos números primos que multiplicados den %d\n", n);
    }
}

int main() {
    int n;
    
    printf("Ingresa un número para encontrar dos primos que multiplicados den ese número: ");
    scanf("%d", &n);
    
    encontrar_primos_multiplicados(n);
    
    return 0;
}
