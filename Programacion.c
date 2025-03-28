#include <stdio.h>

int main() {
    int id = 0, stock = 0, cantidad;
    float precio, total_ganancias = 0, descuento;

    int opcion;
    do {
        printf("\n\tMenu de Gestion de Ventas:\n");
        printf("\t1. Ingresar ID del producto\n");
        printf("\t2. Vender producto\n");
        printf("\t3. Reabastecer stock\n");
        printf("\t4. Consultar informacion del producto\n");
        printf("\t5. Ver ganancias acumuladas\n");
        printf("\t6. Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Error: Debe ingresar un numero valido.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                do {
                    printf("Ingrese el ID del producto (1234 para continuar): ");
                    if (scanf("%d", &id) != 1) {
                        printf("Error: Ingrese un ID valido.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                } while (id != 1234);

                printf("Ingrese el nombre del producto: Naranjas\n");

                do {
                    printf("Ingrese el precio unitario del producto: ");
                    if (scanf("%f", &precio) != 1 || precio <= 0) {
                        printf("Error: El precio debe ser un numero mayor a 0.\n");
                        while (getchar() != '\n');
                    }
                } while (precio <= 0);

                do {
                    printf("Ingrese la cantidad inicial en stock: ");
                    if (scanf("%d", &stock) != 1 || stock < 0) {
                        printf("Error: El stock no puede ser negativo.\n");
                        while (getchar() != '\n');
                    }
                } while (stock < 0);
                break;

            case 2:
                if (id != 1234) {
                    printf("Error: Debe ingresar el ID del producto primero.\n");
                    break;
                }
                do {
                    printf("Ingrese la cantidad de naranjas a vender: ");
                    if (scanf("%d", &cantidad) != 1 || cantidad <= 0) {
                        printf("Error: No puede vender una cantidad negativa o cero.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                } while (cantidad <= 0);

                if (cantidad > stock) {
                    printf("Error: No hay suficientes naranjas en stock.\n");
                } else {
                    do {
                        printf("Ingrese el porcentaje de descuento (0-100): ");
                        if (scanf("%f", &descuento) != 1 || descuento < 0 || descuento > 100) {
                            printf("Error: Descuento invalido. Debe estar entre 0 y 100.\n");
                            while (getchar() != '\n');
                        }
                    } while (descuento < 0 || descuento > 100);

                    float precio_final = precio * (1 - descuento / 100);
                    stock -= cantidad;
                    total_ganancias += cantidad * precio_final;
                    printf("Venta realizada con exito! Precio final por unidad: %.2f\n", precio_final);
                }
                break;

            case 3:
                if (id != 1234) {
                    printf("Error: Debe ingresar el ID del producto primero.\n");
                    break;
                }
                do {
                    printf("Ingrese la cantidad de naranjas a agregar al stock: ");
                    if (scanf("%d", &cantidad) != 1 || cantidad < 1) {
                        printf("Error: No puede agregar una cantidad negativa o cero.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                } while (cantidad < 1);

                stock += cantidad;
                printf("Stock actualizado! Nuevo stock: %d\n", stock);
                break;

            case 4:
                if (id != 1234) {
                    printf("Error: Debe ingresar el ID del producto primero.\n");
                    break;
                }
                printf("\n\tInformacion del Producto:\n");
                printf("\tNombre: Naranjas\n");
                printf("\tPrecio Unitario: %.2f\n", precio);
                printf("\tStock Disponible: %d\n", stock);
                break;

            case 5:
                if (id != 1234) {
                    printf("Error: Debe ingresar el ID del producto primero.\n");
                    break;
                }
                printf("Total de ganancias acumuladas: %.2f\n", total_ganancias);
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Error: Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}