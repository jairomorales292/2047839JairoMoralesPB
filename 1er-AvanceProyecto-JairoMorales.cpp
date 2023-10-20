//El proyecto es una simulación de la página que deberá simular una un punto de venta de un restaurante 
// en el cual deberán constar al menos de los siguientes campos :
//Datos Generales de la razon social del restaurante  
// Numero de ticket (no se puede repetir)  
// Nombre del vendedor 
//  Fecha  
// Lista de los articulos ● 
// Precio de los articulos ●
//  Lista del numero total de articulos ● 
// Precio unitario del total de los articulos ● 
// Descuentos o promociones ●
//  Propina 10%,15%,20% sobre el precio unitario. ● 
// Impuesto ● 
// Total ●

//La simulación del punto de venta debe tener un menú para navegar a lo largo del programa.
// Deberá contener las siguientes opciones : 
// ● Alta de Ordenes 
// ● Modificar Orden 
// ● Eliminar o Cancelar Orden 
// ● Lista de Ordenes 
// ● Limpiar pantalla 
// ● Salir

//primero agregaremos las bibliotecas que posiblemente ocuparemos

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdio>

using namespace std;

//ahora haremos nuestra estructura y pensaremos en las variables que utilizaremos

struct Restaurante
{
	string NombreRestaurante;
	int NumeroTicket;
	string NombreVendedor;
	string Fecha;
	string Articulo;
	float PrecioArticulo;
	int TotalArticulos;
	float PrecioUnitario;
	float Descuento;
	float Propina;
	float Impuesto;
	float Total;
};

int main()
{
	//creamos arreglo
	Restaurante Ticket[3];
	//y una variable para abrir el menu, sera entero para que escoger con un numero
	int opcion;

	do {
		printf("\n Ingrese opcion a realizar \n 1.Alta de Ordenes \n 2.Modificar Ordenes \n 3.Eliminar o Cancelar Orden \n 4.Lista de Ordenes \n 5.Limpiar Pantalla \n 6.Salida \n ");
		scanf_s("%d", &opcion);

		switch (opcion)
		{
		case 1: //ALTA DE ORDENES
			for (int i = 0; i < 3; i++)
			{
				printf("Ingrese Nombre del Restaurante: \n");
				cin.ignore();
				getline(cin, Ticket[i].NombreRestaurante);

				Ticket[i].NumeroTicket=i;
				printf("Su Numero de Ticket: %d\n", Ticket[i].NumeroTicket);

				printf("Ingrese Nombre del Vendedor: \n");
				getline(cin, Ticket[i].NombreVendedor);

				printf("Fecha Actual: \n");
				getline(cin, Ticket[i].Fecha);


			}
			break;
		case 2: //MODIFICAR ORDEN
			break;
		case 3: //ELIMINAR O CANCELAR ORDEN
			break;
		case 4: //LISTA DE ORDENES
			for (int i = 0; i < 3; i++)
			{
				printf("Nombre del Restaurante: %s \n", Ticket[i].NombreRestaurante.c_str());
				printf("Numero de Ticket: %d \n", Ticket[i].NumeroTicket);
				printf("Nombre del Vendedor: %s \n", Ticket[i].NombreVendedor.c_str());
				printf("Fecha: %s \n", Ticket[i].Fecha.c_str());
			}
			break;
		case 5: //LIMPIAR PANTALLA
			system("cls");
			break;
		case 6: //SALIDA
			exit(1);
			break;
		default:
			opcion = 7;
			cout << "la opcion es incorrecta" << endl;
			break;
		}
	} while (opcion >= 1 || opcion <= 6);

	system("pause");
}