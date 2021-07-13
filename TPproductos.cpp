#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <iomanip>
using namespace std;


struct producto
{
	int codProd;
	double pCompra;
	double pVenta;
	int stock;
	int stockMin;
};

//cabeceras de las funciones
double ganancia(struct producto [], int);
void imprimir(struct producto [], int);
bool pedir(struct producto [], int);
double maximoyMinimo(struct producto [], int, double &, double &);


int main (void)
{
	int i, dim, contStockActual, contStockMin;
	char resp;
	double maxP, minP;
	
	dim=100;
	producto Productos[dim];
	
	do
	{
        cout<<" Hay productos para cargar? s/n "<<endl;
		cin>>resp;
	}
	while((resp!='s')&&(resp!='n'));
	
	while (resp=='s')
	{
		cout<<" Ingrese codigo de producto: "<<endl;
		cin>>Productos[i].codProd;
		
		cout<<" Ingrese precio de compra: "<<endl;
		cin>>Productos[i].pCompra;
		
		cout<<" Ingrese precio de venta: "<<endl;
		cin>>Productos[i].pVenta;
		
		cout<<" Ingrese stock actual: "<<endl;
		cin>>Productos[i].stock;
		
		cout<<" Ingrese stock minimo: "<<endl;
		cin>>Productos[i].stockMin;
		
		i++;
		
		do
		{
		cout<<" Hay productos para cargar? s/n"<<endl;
		cin>>resp;
	    }
	    while((resp!='s')&&(resp!='n'));
	}
	dim=i;
	
	cout<<endl;
	cout<<"*****punto1******"<<endl;
	for (i=0;i<dim;i++)
	{
		cout<<endl;
		cout<<" Codigo de producto: "<<Productos[i].codProd<<endl;
		cout<<" Precio de compra: "<<Productos[i].pCompra<<endl;
		cout<<" Precio de venta: "<<Productos[i].pVenta<<endl;
		cout<<" Stock actual: "<<Productos[i].stock<<endl;
		cout<<" Stock minimo: "<<Productos[i].stockMin<<endl;
		cout<<endl;
	}
	
	cout<<endl;
	cout<<"*****punto2******"<<endl;
	//2)	El margen de ganancia total sobre el stock actual.
	contStockActual=0;
	for (i=0;i<dim;i++)
	{
		contStockActual+=Productos[i].stock * (Productos[i].pVenta - Productos[i].pCompra);
	}
	cout<< "El margen de ganancia total sobre el stock actual: "<<contStockActual<<endl;
	
	cout<<endl;
	cout<<"*****punto3******"<<endl;
	//3)	Cantidad de productos que alcanzan el stock mínimo.
	contStockMin=0;
	for (i=0;i<dim;i++)
	{
		if (Productos[i].stock <= Productos[i].stockMin)
		{
			contStockMin++;
		}
		
	}
	cout<<"Cantidad de productos que alcanzan el stock minimo: "<<contStockMin<<endl;
	
	
	
	
	
	
    cout<<"*****************FUNCIONES***********************"<<endl;
	cout<<endl;
	cout<<" Margen de ganancia total sobre el stock actual: "<<ganancia(Productos, dim)<<endl;
	
	//2da funcion
	cout<<endl;
	imprimir(Productos, dim);
	
	//4 funcion
	
	cout<<endl;
	maximoyMinimo(Productos, dim, maxP, minP);
	cout<<" El menor precio de venta: "<<minP<<endl;
	cout<<" El mayor precio de venta: "<<maxP<<endl;
	
	
    getch();
	return(0);
}

/*
-	Función Ordenar: Dado un vector con los datos de los productos, devolver el vector ordenado, de acuerdo al código de producto.
*/

//Función Ganancia: Dado un vector con los datos de los productos, devolver el cual sería el margen de ganancia total sobre el stock actual.

double ganancia(struct producto v[], int dimm)
{
	int i;
	int cont=0;
	
	for (i=0;i<dimm;i++)
	{
		cont+=v[i].stock * (v[i].pVenta - v[i].pCompra);	
	}
	
	return (cont);
}//fin funcion ganancia



//-	Función Imprimir: Dado un vector con los datos de los productos, mostrar por pantalla los datos de cada producto.
void imprimir(struct producto v[], int dimm)
{
	int i;
	
	for (i=0;i<dimm;i++)
	{
		cout<<endl;
		cout<<" Codigo de producto: "<<v[i].codProd<<endl;
		cout<<" Precio de compra: "<<v[i].pCompra<<endl;
		cout<<" Precio de venta: "<<v[i].pVenta<<endl;
		cout<<" Stock actual: "<<v[i].stock<<endl;
		cout<<" Stock minimo: "<<v[i].stockMin<<endl;
		cout<<endl;	
	}	
}//fin funcion imprimir



//-	Función Pedir: Dado un producto, devolver un indicador si el stock actual del producto alcanza el stock mínimo.

bool pedir(struct producto v[], int dimm)
{
	int i;
	
	for (i=0;i<dimm;i++)
	{
		if (v[i].stock<=v[i].stockMin)
		{
			return(true);
		}
		else
		{
			return(false);
		}
		
	}
	
}//fin funcion pedir



//-	Función MaximoyMinimo: Dado un vector con los datos de los productos, devolver el menor precio de Venta y el mayor precio de Venta.

double maximoyMinimo(struct producto vec[], int dimm, double &max, double &min)
{
	int i;
	
	max=vec[0].pVenta;
	min=vec[0].pVenta;
	
	for (i=1;i<dimm;i++)
	{
		
		if (vec[i].pVenta>max)
		{
			max=vec[i].pVenta;
	    }
		else
		if (vec[i].pVenta<min)
		{
			min=vec[i].pVenta;
	    }
			
	}
		
}//fin funcion maximoyMinimo 




//-	Función SobreStock: Dado un vector con los datos de los productos, devolver otro vector con los productos cuyo stock actual supere en 50 % al stock mínimo.
















