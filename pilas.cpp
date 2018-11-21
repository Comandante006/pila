#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct Alumno{
	int clave;
	char nombre[30];
	float calificacion;
};
struct Nodo{
	Alumno datos;
	Nodo *siguiente;
};
void menu();
void agregarDatos(Alumno &);
void inDatos(Nodo *&,Alumno);
int main(){
	Alumno datos;
	Nodo *pila=NULL;
	Nodo *aux=NULL;
	char opcion;
	do{
		menu();
		cin>>opcion;
		fflush(stdin);
		switch(opcion){
			case '1':
				agregarDatos(datos);
				inDatos(pila,datos);
				break;
			case '2':
				cout<<"MOSTRANDO ELEMNTOS--->"<<endl;
    			aux=pila;
    			cout<<"CLAVE"<<"\tNOMBRE\t\t\t"<<"CALIFICACION"<<endl;
	    		while(aux !=NULL){
	    			cout<<aux->datos.clave<<"\t"<<aux->datos.nombre<<"\t\t\t"<<aux->datos.calificacion<<endl;
	    			aux=aux->siguiente;
				}
				break;
			case '3':
				cout<<"Salio del programa"<<endl;
				break;
			default:
				cout<<"\nOpcion invalida"<<endl;
				break;
		}
		cout<<"\nPresione una tecla para continuar"<<endl;
		getch();
		system("cls");
	}while(opcion !='3');
}
void menu()
{
	cout<<"\nP   I   L   A   S   "<<endl;
	cout<<" M  E  N  U "<<endl
	    <<"1. Ingresar datos"<<endl
	    <<"2. Mostrar datos"<<endl
	    <<"3. Salir"<<endl
	    <<"INGRESE UNA ACCION";
}
void agregarDatos(Alumno &datos){
	cout<<"\nNOMBRE--> "; cin.getline(datos.nombre,30,'\n');
	cout<<"CLAVE--> "; cin>>datos.clave;
	cout<<"CALIFICACION--> "; cin>>datos.calificacion;
	cout<<endl;
}

void inDatos(Nodo *&pila,Alumno datos){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->datos=datos;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}
