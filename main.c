#include <stdio.h>
#include <stdlib.h>

int main() {
    int pin, intentos = 0;
    int saldo = 500000; 
    int opcion;
    int movimientos[5]; 
    int tipos[5];       
    int mov_count = 0;

    // Validar PIN
    for (intentos = 0; intentos < 3; intentos++) {
        printf("Ingrese su PIN: ");
        scanf(" %d", &pin);
        if (pin == 1234) {
            printf("PIN correcto.\n");
            break;
        } else {
            printf("PIN incorrecto.\n");
        }
    }
    if (intentos == 3) {
        printf("Demasiados intentos. Programa terminado.\n");
        return 0;
    }

    // Menú principal
    do {
        printf("\n--- MENU ---\n");
        printf("1. Consultar saldo\n");
        printf("2. Depositar dinero\n");
        printf("3. Retirar dinero\n");
        printf("4. Ver ultimos movimientos\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf(" %d", &opcion);

        switch(opcion) {
            case 1:
                printf("Saldo actual: %d\n", saldo);
                break;

            case 2: {
                int monto;
                printf("Ingrese monto a depositar: ");
                scanf(" %d", &monto);
                if (monto > 0) {
                    saldo += monto;
                    printf("Deposito exitoso.\n");
                    movimientos[mov_count % 5] = monto;
                    tipos[mov_count % 5] = 1;
                    mov_count++;
                } else {
                    printf("Monto invalido.\n");
                }
                break;
            }

            case 3: {
                int monto;
                do {
                    printf("Ingrese monto a retirar: ");
                    scanf(" %d", &monto);
                    if (monto <= 0) {
                        printf("Monto invalido.\n");
                    } else if (monto > saldo) {
                        printf("Saldo insuficiente.\n");
                    } else if (monto % 10000 != 0) {
                        printf("El monto debe ser multiplo de 10000.\n");
                    } else {
                        saldo -= monto;
                        printf("Retiro exitoso.\n");
                        movimientos[mov_count % 5] = monto;
                        tipos[mov_count % 5] = 2;
                        mov_count++;
                        break;
                    }
                } while (1);
                break;
            }

            case 4:
                printf("Ultimos movimientos:\n");
                for (int i = 0; i < (mov_count < 5 ? mov_count : 5); i++) {
                    int idx = (mov_count - i - 1 + 5) % 5;
                    if (tipos[idx] == 1)
                        printf("%d. Deposito: %d\n", i+1, movimientos[idx]);
                    else if (tipos[idx] == 2)
                        printf("%d. Retiro: %d\n", i+1, movimientos[idx]);
                }
                break;

            case 5:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }
    } while(opcion != 5);

    return 0;
}
