/*
Declara un tipo de dato estructura:
i) Para representar a una PC; los campos serán: 

velocidad de procesamiento en GHz, 
año de fabricación, 
tipo de procesador, 
cantidad de núcleos.

ii) Considera valores enteros aleatorios para la velocidad: entre 1 y 3, 
para el año: entre 2015 y 2024, 
para la cantidad de núcleos: entre 1 y 8.

iii) Para evitar ingresar por teclado los tipos de procesador, considera que estos se
encuentran en un arreglo de cadenas de caracteres:
char tipos[6][10]={“Intel”, “AMD”, “Celeron”, “Athlon”, “Core”, “Pentium”}

La estructura será la siguiente:

struct compu {
int velocidad;//entre 1 y 3 GHz
int anio;//entre 2015 y 2023
int cantidad;//entre 1 y 8
char *tipo_cpu; //valores del arreglo tipos
};

b) Define una variable del tipo arreglo de estructura para guardar las características de 5 PC
que cargará el usuario.
c) Escribe una función que presente la lista de las PC, cada una con sus características.
d) Escribe una función que presente la PC más vieja.
e) Escribe una función que presente la PC que tiene mayor velocidad.
*/
#include<stdio.h>
#include<stdlib.h>

#define CANTPC 5

struct {
    int velocidad;      //entre 1 y 3 GHz
    int anio;           //entre 2015 y 2023
    int cantidad;       //entre 1 y 8
    char *tipo_cpu;     //valores del arreglo tipos
}typedef compu;

void cargaPc(compu *lista){
    
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    for (int i = 0; i < CANTPC; i++)
    {
        int aux = 0;

        printf("\n**ingrese los datos de la %d pc **",i);
        fflush(stdin);
        // Ingresa el AÑO de la PC
        do
        {    
            printf("\nIngrese el anio: (2015-2023) ");
            scanf("%d", &aux);
            if(aux < 2015 || aux >2023){
                printf("\n el año debe estar entre 2015 y 2023");
            }else{
                lista->anio = aux;
            }
        } while (aux < 2015 || aux >2023);
        fflush(stdin);
        //Ingresa la cantidad de NUCLEOS de la PC
        do
        {
            printf("\ningrese la cantidad de nucleos que tiene: (1-8) ");
            scanf("%d", &aux);
            if(aux < 1 || aux > 8){
                printf("\nLa cantidad de nucleos debe estar ser entre 1 y 8 ");
            }else{
                lista->cantidad = aux;
            }
        } while (aux < 1 || aux > 8);
        fflush(stdin);
        //Ingresa la VELOCIDAD de la PC
        do
        {
            printf("\ningrese la velocidad en Ghz: (1-3) ");
            scanf("%d", &aux);
            if(aux < 1 || aux > 3){
                printf("\nLa velocidad debe estar ser entre 1 y 3 ");
            }else{
                lista->velocidad = aux;
            }
        } while (aux < 1 || aux > 8);
        fflush(stdin);
        //Tipo de CPU
        do
        {
            printf("\ningrese el tipo de CPU de la siguiente lista:  ");

            for (int i = 0; i < 6; i++)
            {
                printf("\n** %d- %s **",(i+1),tipos[i]);
            }
            scanf("%d", &aux);
            aux --;
            if(aux < 0 || aux > 5){
                printf("\nDebe elegir una de las opciones de la lista ");
            }else{
                lista->tipo_cpu = tipos[aux];
            }
        } while (aux < 1 || aux > 8);
        fflush(stdin);

    }
};

void listaPc(compu *lista){
    for (int i = 0; i < CANTPC; i++)
    {
        printf ("\n**Pc nº %d **\n",(i+1));
        printf ("\n**Velocidad: %d **", lista->velocidad);
        printf ("\n**anio: %d **",lista->anio);
        printf ("\n**Tipo: %s **",lista->tipo_cpu);
        printf("\n**Cantidad: %d **\n",lista->cantidad);
    }
};

void pcAntigua(compu *lista){
    int antigua = 2024, aux = 0;
    for (int i = 0; i < CANTPC; i++){
        antigua = ((lista+i)->anio < antigua)? (lista+i)->anio : antigua;
        aux = ((lista+i)->anio < antigua)? i : aux;
    }

    printf ("\n**Pc nº %d **\n",(aux+1));
    printf ("\n**Velocidad: %d **", (lista+aux)->velocidad);
    printf ("\n**anio: %d **",(lista+aux)->anio);
    printf ("\n**Tipo: %s **",(lista+aux)->tipo_cpu);
    printf("\n**Cantidad: %d **\n",(lista+aux)->cantidad);

};

void pcVelocidad(compu *lista){
    int velo = 0, aux = 0;
    for (int i = 0; i < CANTPC; i++){
        velo = ((lista+i)->velocidad > velo)? (lista+i)->velocidad : velo;
        aux = ((lista+i)->velocidad > velo)? i : aux;
    }

    printf ("\n**Pc nº %d **\n",(aux+1));
    printf ("\n**Velocidad: %d **", (lista+aux)->velocidad);
    printf ("\n**anio: %d **",(lista+aux)->anio);
    printf ("\n**Tipo: %s **",(lista+aux)->tipo_cpu);
    printf("\n**Cantidad: %d **\n",(lista+aux)->cantidad);
};


int main(int argc, char const *argv[])
{
    compu *listaCompu;
    listaCompu = (compu*)malloc(CANTPC * sizeof(compu));
    cargaPc(listaCompu);

    listaPc(listaCompu);
    
    pcAntigua(listaCompu);
    
    pcVelocidad(listaCompu);

    free(listaCompu);
    return 0;
}
