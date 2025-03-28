#include <stdio.h>

int main() {
    int id = 0, stock = 0, cantidad;
    float precio, total_ganancias = 0;
    const float DESCUENTO = 50.0;
    char nombre_producto[50];

    int opcion;
    do {
        printf("\nMenu de Ventas:\n");
        printf("1. Ingresar producto\n");
        printf("2. Vender\n");
        printf("3. Reabastecer\n");
        printf("4. Consultar producto\n");
        printf("5. Ver ganancias\n");
        printf("6. Salir\n");
        printf("Opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Error: Numero invalido.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                printf("Ingrese el ID del producto: ");
                if (scanf("%d", &id) != 1) {
                    printf("Error: ID invalido.\n");
                    while (getchar() != '\n');
                    continue;
                }

                printf("Ingrese el nombre del producto: ");
                scanf("%s", nombre_producto);

                do {
                    printf("Ingrese el precio del producto: ");
                    if (scanf("%f", &precio) != 1 || precio <= 0) {
                        printf("Error: Precio invalido.\n");
                        while (getchar() != '\n');
                    }
                } while (precio <= 0);

                do {
                    printf("Ingrese la cantidad inicial en stock: ");
                    if (scanf("%d", &stock) != 1 || stock < 0) {
                        printf("Error: Stock invalido.\n");
                        while (getchar() != '\n');
                    }
                } while (stock < 0);
                break;

            case 2:
                if (id == 0) {
                    printf("Error: Debe ingresar un producto primero.\n");
                    break;
                }
                do {
                    printf("Ingrese la cantidad a vender: ");
                    if (scanf("%d", &cantidad) != 1 || cantidad <= 0) {
                        printf("Error: Cantidad invalida.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                } while (cantidad <= 0);

                if (cantidad > stock) {
                    printf("Error: Stock insuficiente.\n");
                } else {
                    float precio_final = precio;
                    
                    if (cantidad >= 20) {
                        precio_final = precio * (1 - DESCUENTO / 100);
                        printf("Descuento aplicado! Precio con 50%% de descuento.\n");
                    }

                    stock -= cantidad;
                    total_ganancias += cantidad * precio_final;
                    printf("Venta exitosa! Precio final por unidad: %.2f\n", precio_final);
                }
                break;

            case 3:
                if (id == 0) {
                    printf("Error: Debe ingresar un producto primero.\n");
                    break;
                }
                do {
                    printf("Ingrese la cantidad a agregar al stock: ");
                    if (scanf("%d", &cantidad) != 1 || cantidad < 1) {
                        printf("Error: Cantidad invalida.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                } while (cantidad < 1);

                stock += cantidad;
                printf("Stock actualizado! Nuevo stock: %d\n", stock);
                break;

            case 4:
                if (id == 0) {
                    printf("Error: Debe ingresar un producto primero.\n");
                    break;
                }
                printf("\nProducto:\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s\n", nombre_producto);
                printf("Precio original: %.2f\n", precio);
                printf("Stock disponible: %d\n", stock);
                printf("Descuento del 50%% si compras 20 o mas unidades.\n");
                break;

            case 5:
                if (id == 0) {
                    printf("Error: Debe ingresar un producto primero.\n");
                    break;
                }
                printf("Ganancias acumuladas: %.2f\n", total_ganancias);
                break;

            case 6:
                printf("Saliendo del sistema...\n");
                break;

            default:
                printf("Error: Opcion invalida.\n");
        }
    } while (opcion != 6);

    return 0;
}
