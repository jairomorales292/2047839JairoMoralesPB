#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <iomanip>

using namespace std;

struct RESTAURANTE
{
    string statusbaja; 
    char nomrestaurante[100], nomvendedor[100], fecha[100], articulo[100];
    float precio, propina, iva, total, sum = 0, preciounitario, totalaPagar, descuento=0;
};

//sum es el precio unitario del total de articulos

int alta, otroalta, otraopc, option;
RESTAURANTE* PUNTERO;

void Alta();
void Eliminar();
void Listas();
void Modificar();
void Archivos();

int main()
{
    int opc;
    printf("INGRESE LA OPCION A LA QUE QUISIESE INGRESAR: \n");
    printf("1-Alta\n2-Mostrar\n3-Limpiar pantalla\n4-Modificar\n5-Eliminar o Cancelar\n6-Salir\n");
    scanf_s("%d", &opc);

    switch (opc)
    {
    case 1:
        Alta();
        return main();
        break;

    case 2:
        Listas();
        return main();
        break;

    case 3:
        system("cls");
        return main();
        break;

    case 4:
        Modificar();
        return main();
        break;

    case 5:
        Eliminar();
        return main();
        break;

    case 6:
        Archivos();
        exit(1);
        break;
    }
}

void Alta()
{
    printf("Cuantos registros desea dar de alta \n");
    scanf_s("%d", &alta);
    PUNTERO = new RESTAURANTE[alta];

    for (int i = 0; i < alta; i++)
    {
        
        printf("TICKET NUMERO: %d \n", i + 1);
        while (getchar() != '\n');
        printf("Ingrese nombre del restaurante: \n");
        fgets(PUNTERO[i].nomrestaurante, 100, stdin);
        //getline(cin, PUNTERO[i].nomrestaurante);
        //no me deja hacer con scanf_s("%s", &PUNTERO[i].nomrestaurante);
        printf("Ingrese nombre del vendedor: \n");
        fgets(PUNTERO[i].nomvendedor, 100, stdin);
        //getline(cin, PUNTERO[i].nomvendedor);
        printf("Ingrese fecha: \n");
        fgets(PUNTERO[i].fecha, 100, stdin);
        //getline(cin, PUNTERO[i].fecha);
        printf("Cuantos articulos desea dar de alta: \n");
        scanf_s("%d", &otroalta);
        while (getchar() != '\n');
        for (int j = 0; j < otroalta; j++)
        {
            printf("Ingrese articulo: \n");
            fgets(PUNTERO[i].articulo, 100, stdin);
            printf("Ingrese precio del articulo: \n");
            scanf_s("%f", &PUNTERO[i].precio);
            while (getchar() != '\n');
            PUNTERO[i].sum = PUNTERO[i].sum + PUNTERO[j].precio;

        }
        printf("\n Total de articulos: %d \n", otroalta);
        PUNTERO[i].descuento = 0;

        printf("Cuanto agregar de propina: \n 1- 10 porciento \n 2- 15 porciento \n 3- 20 porciento \n 4- 0 \n ");
        scanf_s("%d", &otraopc);
        if (otraopc == 1)
        {
            PUNTERO[i].propina = PUNTERO[i].sum * .10;
        }
        if (otraopc == 2)
        {
            PUNTERO[i].propina = PUNTERO[i].sum * .15;
        }
        if (otraopc == 3)
        {
            PUNTERO[i].propina = PUNTERO[i].sum * .20;
        }
        if (otraopc == 4)
        {
            PUNTERO[i].propina = 0;
        }
        printf("Desea agregar 10 porciento de descuento? \n 1- Si \n 2- No \n");
        scanf_s("%d", &option);
        if (option == 1)
        {
            PUNTERO[i].preciounitario = PUNTERO[i].sum;
            PUNTERO[i].iva = PUNTERO[i].sum * .16;
            PUNTERO[i].total = PUNTERO[i].sum + PUNTERO[i].iva + PUNTERO[i].propina;
            PUNTERO[i].descuento = PUNTERO[i].total * .10;
            PUNTERO[i].totalaPagar = PUNTERO[i].total - PUNTERO[i].descuento;
            PUNTERO[i].sum = 0;
        }
        if (option == 2)
        {
            PUNTERO[i].preciounitario = PUNTERO[i].sum;
            PUNTERO[i].iva = PUNTERO[i].sum * .16;
            PUNTERO[i].total = PUNTERO[i].sum + PUNTERO[i].iva + PUNTERO[i].propina;
            PUNTERO[i].totalaPagar = PUNTERO[i].total;
            PUNTERO[i].sum = 0;
        }
    }
}

void Eliminar()
{
    
    int baja, menumenu;

    printf("ingrese a que opcion desea entrar \n 1-Eliminar \n 2-Cancelar \n");
    scanf_s("%d", &menumenu);

    switch (menumenu)
    {
    case 1 : printf("ingrese el  registro a eliminar \n");
        scanf_s("%d", &baja);
        baja = baja - 1;

        for (int i = baja; i == baja; i++)
        {
            printf("Eliminando registro %d \n", baja + 1);
            PUNTERO[i].statusbaja = "ELIMINADO";

        }
        break;
    case 2 :
        printf("ingrese el  registro a cancelar \n");
        scanf_s("%d", &baja);
        baja = baja - 1;

        for (int i = baja; i == baja; i++)
        {
            printf("CANCELANDO registro %d \n", baja + 1);
            PUNTERO[i].statusbaja = "CANCELADO";

        }
        break;
    }
    
}

void Listas()
{
    
    for (int i = 0; i < alta; i++)
    {
        if (PUNTERO[i].statusbaja == "ELIMINADO")
        {
            printf("\n REGISTRO ELIMINADO %d \n", i + 1);
        }
        else
        {
            if (PUNTERO[i].statusbaja == "CANCELADO")
            {
                printf("\n REGISTRO CANCELADO %d \n", i + 1);
                printf("%s \n", PUNTERO[i].nomrestaurante);
                printf("TICKET NUMERO: %d \n", i + 1);
                printf("%s \n", PUNTERO[i].nomvendedor);
                printf("%s \n", PUNTERO[i].fecha);

                for (int j = 0; j < otroalta; j++)
                {
                    printf("%s \t", PUNTERO[i].articulo);
                    printf("%f \n", PUNTERO[i].precio);
                }
                printf("\n Total de articulos: %d \t", otroalta);
                printf("Precio Unitario %f \n", PUNTERO[i].preciounitario);
                printf("Propina %f \n", PUNTERO[i].propina);
                printf("Impuestos %f \n", PUNTERO[i].iva);
                printf("Total%f \n", PUNTERO[i].total);
                printf("Descuento de:%f \n", PUNTERO[i].descuento);
                printf("Total a pagar%f \n", PUNTERO[i].totalaPagar);
            }
            else
            {
                printf("%s \n", PUNTERO[i].nomrestaurante);
                printf("TICKET NUMERO: %d \n", i + 1);
                printf("%s \n", PUNTERO[i].nomvendedor);
                printf("%s \n", PUNTERO[i].fecha);

                for (int j = 0; j < otroalta; j++)
                {
                    printf("%s \t", PUNTERO[i].articulo);
                    printf("%f \n", PUNTERO[i].precio);
                }
                printf("\n Total de articulos: %d \t", otroalta);
                printf("Precio Unitario %f \n", PUNTERO[i].preciounitario);
                printf("Propina %f \n", PUNTERO[i].propina);
                printf("Impuestos %f \n", PUNTERO[i].iva);
                printf("Total%f \n", PUNTERO[i].total);
                printf("Descuento de:%f \n", PUNTERO[i].descuento);
                printf("Total a pagar%f \n", PUNTERO[i].totalaPagar);
            }

        }
    }
}

void Modificar()
{
    int modificar, opcion;
    printf("ingrese el numero registro a modificar \n");
    scanf_s("%d", &modificar);
    modificar = modificar - 1;
    for (int i = modificar; i == modificar; i++)
    {

        if (PUNTERO[i].statusbaja == "ELIMINADO")
        {
            printf("EL REGISTRO A SIDO ELIMINADO %d \n", i + 1);
            printf("ingrese un registro valido \n");
            return Modificar();
        }

        printf("Ingrese que desea modificar 1.-Nombre del restaurante,2.-Nombre del vendedor, 3.- Fecha \n");
        scanf_s("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese nombre del restaurante \n");
            cin.ignore();
            fgets(PUNTERO[i].nomrestaurante, 100, stdin);

            break;
        case 2:
            printf("Ingrese nombre del vendedor \n");
            cin.ignore();
            fgets(PUNTERO[i].nomvendedor, 100, stdin);
            break;

        case 3:
            printf("Ingrese Fecha \n");
            cin.ignore();
            fgets(PUNTERO[i].fecha, 100, stdin);
            break;
        }
    }
}

void Archivos()
{
    ofstream archivo;
    string nombrearchivo;
    nombrearchivo = "TICKET DEL RESTAURANTE.txt";
    archivo.open(nombrearchivo.c_str(), ios::out);

    if (archivo.fail())
    {
        printf("ERROR NO SE PUDO CREAR EL ARCHIVO");
        exit(1);
    }
    else
    {
        printf("EL ARCHIVO SE GENERO CORRECTAMENTE");
    }
    for (int i = 0; i < alta; i++)
    {
        archivo << "RESTAURANTE" << "\n";
        archivo << PUNTERO[i].nomrestaurante << "\n";
        archivo << "NUMERO TICKET" << "\n";
        archivo << i + 1 << "\n";
        archivo << "NOMBRE DEL VENDEDOR" << "\n";
        archivo << PUNTERO[i].nomvendedor << "\n";
        archivo << "FECHA" << "\n";
        archivo << PUNTERO[i].fecha << "\n";
        for (int j = 0; j < otroalta; j++)
        {
            archivo << "ARTICULOS Y PRECIOS" << "\n";
            archivo << PUNTERO[j].articulo << "\n";
            archivo << PUNTERO[j].precio << "\n";
        }
        archivo << "PROPINA" << "\n";
        archivo << PUNTERO[i].propina << "\n";
        archivo << "IVA" << "\n";
        archivo << PUNTERO[i].iva << "\n";
        archivo << "TOTAL" << "\n";
        archivo << PUNTERO[i].total << "\n";
        archivo << "DESCUENTO" << "\n";
        archivo << PUNTERO[i].descuento << "\n";
        archivo << "TOTAL A PAGAR" << "\n";
        archivo << PUNTERO[i].totalaPagar << "\n";
        archivo << "STATUS REGISTRO" << "\n";
        archivo << PUNTERO[i].statusbaja << "\n";
    }
    archivo.close();
}