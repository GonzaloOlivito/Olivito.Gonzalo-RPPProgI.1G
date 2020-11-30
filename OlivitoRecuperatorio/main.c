#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4

typedef struct{
int id;
char marca[20];
char procesador[20];
float precio;
int isEmpty;
}eNotebook;

float calcularIva(float precio);
int reemplazarCaracter(char palabra[20], char caracterReemplazar, char nuevoCaracter);
int ordenamiento(eNotebook vec[], int tam);
void mostrarNotebook(eNotebook note, int tam);
void mostrarNotebooks(eNotebook vec[], int tam);
int main()
{
    eNotebook lista[TAM]={{100,"Asus","AMD",32500,0},{101,"HP","Intel",45000,0},{102,"HP","AMD",32000,0},{103,"Lenovo","Intel",45000,0}};
    printf("%.2f",calcularIva(100));
    mostrarNotebooks(lista,TAM);
    return 0;
}
float calcularIva(float precio){
float precioIva=precio*0.89;

return precioIva;
}

int reemplazarCaracter(char palabra[20], char caracterReemplazar, char nuevoCaracter)
{
  int contador=0;
    int letras = strlen(palabra);
    for(int i = 0; i < letras; i++)
   {
     if(palabra[i] == caracterReemplazar)
     {
        palabra[i]=nuevoCaracter;
        contador++;
     }
   }
return contador;
}
void mostrarNotebook(eNotebook note, int tam)
{


   printf("%d   %10s  %10s      %.2f\n",note.id,note.marca,note.procesador,note.precio);


}

void mostrarNotebooks(eNotebook vec[], int tam)
{
    int flag=0;
    printf("****Listado Notebooks****\n\n");
    printf(" Id        Marca     Procesador   Precio\n");
    for(int i = 0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarNotebook(vec[i],tam);
            flag=1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay notebooks que listar\n");
    }
}
int ordenamiento(eNotebook vec[], int tam)
{
    eNotebook aux;
    int comp;
    for(int i=0;i<tam;i++)
    {
        for(int j=i+1;j<tam-1;j++)
        {
            comp=strcmp(vec[i].marca,vec[j].marca);
            if(vec[i].isEmpty==0 && comp>0)
        {
            aux=vec[i];
            vec[i]=vec[j];
            vec[j]=aux;
        }
        else{
                if(comp == 0 && vec[i].precio>vec[j].precio)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
        }
    }
}

return 0;
}
