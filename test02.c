/*MILLARAY THIARE ATENEA ZAMBRANO SANTANA RUT 21.196.585-1*/
/*DIEGO ANTONIO VARGAS GOMEZ RUT 21.012.009-2*/
/*TEST 2*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODO
{
    int numerador;
    int denominador;
    float numero_racional;
    int posicion;
    struct NODO *siguiente;
} NODO;

typedef struct NODO_ASCENDENTE
{
    int numerador;
    int denominador;
    float numero_racional;
    int posicion;
    struct NODO_ASCENDENTE *siguiente;
} NODO1;

typedef struct NODO_DESCENDENTE
{
    int numerador;
    int denominador;
    float numero_racional;
    int posicion;
    struct NODO_DESCENDENTE *siguiente;
} NODO2;



int validar_n();
int menu(NODO *aux);
NODO *generar_lista(int n);
void imprimir_lista(NODO *aux);
void imprimir_lista_ascendente(NODO1 *aux);
void imprimir_lista_descendente(NODO2 *aux);
NODO *push(NODO *cabeza, int numerador, int denominador);
NODO eliminar_elemento(NODO *cabeza);
float suma_total(NODO *cabeza);
float pedir_numero_eliminar();
NODO *eliminar(NODO *cabeza);
float producto_total(NODO *cabeza);
int pedir_numerador();
int pedir_denominador();
int buscar(NODO *cabeza, int numerador, int denominador);
NODO *buscar_mayor(NODO *cabeza);
NODO *buscar_menor(NODO *cabeza);
float division(NODO *mayor, NODO *menor);
NODO *orden_ascendente(NODO *cabeza);
NODO *push_en_donde_sea(NODO *cabeza, int numerador, int denominador, int posicion);
int recorrer_lista_posicion(NODO *cabeza, int numerador, int denominador);
int recorrer_lista_contador(NODO *cabeza, int numerador, int denominador);
NODO *recalcular_posicion(NODO *cabeza);
NODO1 *ordenar_lista_ascendente(NODO1 *cabeza);
NODO2 *ordenar_lista_descendente(NODO2 *cabeza);
NODO1 *eliminar_duplicados(NODO1 *cabeza);
NODO2 *eliminar_duplica2(NODO2 *cabeza);
NODO1 *copyList(NODO *cabeza);
NODO2 *copyLista(NODO *cabeza);
int recorrer_lista_contador1(NODO *cabeza);


int main()
{
    srand(time(NULL));
    NODO *cabeza = NULL;
    int n;
    int opcion;
    n = validar_n();
    cabeza = generar_lista(n);
    do
    {
        opcion = menu(cabeza);
        switch (opcion)
        {
        case 1:
        {
            int numerador;
            int denominador;
            int n_elementos;
            int i;
            printf("\n Cuantos elementos ingresara??\n");
            do
            {
                scanf("%d", &n_elementos);
            } while (n_elementos < 0);

            for (i = 1; i <= n_elementos; i++)
            {
                numerador = pedir_numerador();
                denominador = pedir_denominador();
                cabeza = push(cabeza, numerador, denominador);
                imprimir_lista(cabeza);
            }
            printf("\n LISTA CON ELEMENTOS AGREGADOS: \n");
            imprimir_lista(cabeza);
            system("pause");
        }

        break;
        case 2:
        {
            int posicion;
            int numerador;
            int denominador;
            int contador1;
            contador1 = recorrer_lista_contador1(cabeza);
            printf("\nEn que posicion quiere agregar un elemento\n");
            do
            {
                scanf("%d", &posicion);
                if(posicion <= 0 || posicion > contador1 + 1){
                    printf("\nLa posicion donde quiere insertar esta fuera de rango, reingrese\n");
                }
            }while (posicion <= 0 || posicion > contador1 + 1);
            numerador = pedir_numerador();
            denominador = pedir_denominador();
            cabeza = push_en_donde_sea(cabeza, numerador, denominador, posicion);
            cabeza = recalcular_posicion(cabeza);
            imprimir_lista(cabeza);
            system("pause");
        }
        break;

        case 3:
        {
            cabeza = eliminar(cabeza);
            cabeza = recalcular_posicion(cabeza);
            printf("\n LISTA CON ELEMENTO ELIMINADO: \n");
            imprimir_lista(cabeza);
            system("pause");
        }
        break;
        case 4:
        {
            float resultado_suma_total;
            resultado_suma_total = suma_total(cabeza);
            printf("\nLa suma de los elementos de la lista es: %f\n", resultado_suma_total);
            system("pause");
        }
        break;
        case 5:
        {
            float resultado_producto_total;
            resultado_producto_total = producto_total(cabeza);
            printf("\n El resultado de multiplicar los elementos de la lista es: %f \n", resultado_producto_total);
            system("pause");
        }
        break;
        case 6:
        {
            printf("\nIngrese numero a buscar\n");
            int bandera;
            int numerador;
            int denominador;
            numerador = pedir_numerador();
            denominador = pedir_denominador();
            bandera = buscar(cabeza, numerador, denominador);
            if (bandera == 1)
            {
                printf("\n El numero (%d/%d) si se encuentra en la lista!!!\n", numerador, denominador);
                system("pause");
            }
            else
            {
                printf("\nEl numero (%d/%d) no se encuentra en la lista\n!!!", numerador, denominador);
                system("pause");
            }
        }
        break;
        case 7:
        {
            NODO *mayor;
            int posicion;
            mayor = buscar_mayor(cabeza);
            posicion = recorrer_lista_posicion(cabeza, mayor->numerador, mayor->denominador);
            printf("\nEL numero mayor es (%d/%d) y esta en la posicion %d \n", mayor->numerador, mayor->denominador, posicion);
            system("pause");
        }
        break;
        case 8:
        {
            NODO *menor;
            int contador;
            menor = buscar_menor(cabeza);
            contador = recorrer_lista_contador(cabeza, menor->numerador, menor->denominador);
            printf("\nEl numero menor es (%d/%d) y se repite %d veces \n", menor->numerador, menor->denominador, contador);
            system("pause");
        }
        break;
        case 9:
        {
            NODO *mayorr;
            mayorr = buscar_mayor(cabeza);
            NODO *menorr;
            menorr = buscar_menor(cabeza);
            float resultado_division;
            resultado_division = division(mayorr, menorr);
            printf("\nEl resultado de dividir el mayor (%d/%d) por el menor (%d/%d) = %f\n", mayorr->numerador, mayorr->denominador, menorr->numerador, menorr->denominador, resultado_division);
            system("pause");
        }
        break;
        case 10:
        {
            NODO1 *cabeza1;
            cabeza1 = copyList(cabeza);
            cabeza1 = ordenar_lista_ascendente(cabeza1);
            cabeza1 = eliminar_duplicados(cabeza1);
            printf("\n La nueva lista sin valores repetidos y ordenada ascendentemente es: \n");
            imprimir_lista_ascendente(cabeza1);
            system("pause");
        }
        break;
        case 11:
        {
            /* el caso chistoso */
            NODO2 *cabeza2;
            cabeza2 = copyLista(cabeza);
            cabeza2 = ordenar_lista_descendente(cabeza2);
            cabeza2 = eliminar_duplica2(cabeza2);
            printf("\n  La nueva lista sin valores repetidos y ordenada descendentemente es: \n");
            imprimir_lista_descendente(cabeza2);
            system("pause");
        }
        break;
        case 12:
        {
            imprimir_lista(cabeza);
            system("pause");
        }
        break;
        case 13:
         {

         } 

        break;
        }

    } while (opcion != 13);

    system("pause");
    return 0;
}

int validar_n()
{
    int n;
    do
    {
        printf("\nBIENVENIDO AL SISTEMA PARA CREAR LISTAS ENLAZADAS\n\n");

        printf("\nIngrese con cuantos elementos creara la lista\n");
        scanf("%d", &n);
        if (n < 0)
        {
            printf("\nReingrese por favor\n");
        }
    } while (n < 0);
    return n;
}

int menu(NODO *aux)
{
    int x;
    do
    {
        system("cls");
        printf("\n \t \t            MENU          \n ");
        printf("\n \t .-Seleccione un numero para la tarea a realizar-.\n");
        printf("\n .-LISTA PRINCIPAL-. \n");
        printf("\n");
        imprimir_lista(aux);
        printf("\n 1. Para ingresar 1 o mas elementos a la lista en orden de llegada ");
        printf("\n 2. Para ingresar 1 elemento a la lista en una posicion especifica");
        printf("\n 3. Para eliminar un elemento de la lista");
        printf("\n 4. Para mostrar el resultado de la suma de todos los elementos de la lista");
        printf("\n 5. Para mostrar el resultado del producto de todos los elementos de la lista");
        printf("\n 6. Para efectuar la busqueda de un elemento de la lista ");
        printf("\n 7. Para efectuar la busqueda del elemento de mayor valor en la lista");
        printf("\n 8. Para efectuar la busqueda del elemento de menor valor en la lista");
        printf("\n 9. Para efectuar la division del elemento de mayor valor de la lista por el del menor valor");
        printf("\n 10. Para ordenar la lista ascendentemente eliminando los elementos repetidos y guardarla en una nueva lista");
        printf("\n 11. Para ordenar la lista descendentemente eliminando los elementos repetidos y guardarla en una nueva lista");
        printf("\n 12. Para imprimir la lista\n");
        printf("\n 13. Para salir \n");
        scanf("%d", &x);
        if (x < 1 || x > 13)
        {
            system("cls");
            printf("\nIngrese un numero dentro del rango de opciones\n");
            system("pause");
        }
    } while (x < 1 || x > 13);
    return x;
}

NODO *generar_lista(int n)
{
    srand(time(NULL));
    NODO *aux, *lista = NULL, *nuevo;
    int cont = 0;
    if (n > 0)
    {
        lista = (NODO *)malloc(sizeof(NODO));
        lista->numerador = (rand() % 10 + 1);
        lista->denominador = (rand() % 10 + 1);
        lista->numero_racional = ((float)lista->numerador / (float)lista->denominador);
        aux = lista;
        cont = 1;
        lista->posicion = cont;
        while (cont != n)
        {
            nuevo = (NODO *)malloc(sizeof(NODO));
            nuevo->numerador = (rand() % 10 + 1);
            nuevo->denominador = (rand() % 10 + 1);
            nuevo->numero_racional = ((float)nuevo->numerador / (float)nuevo->denominador);
            nuevo->siguiente = NULL;
            aux->siguiente = nuevo;
            aux = aux->siguiente;
            cont++;
            nuevo->posicion = cont;
        }
    }

    return lista;
}

void imprimir_lista(NODO *aux)
{
    if (aux != NULL)
    {
        while (aux != NULL)
        {
            /*profe puede comparar con los decimales desactivando los comentarios*/
            /* printf("[%1.3f]", aux->numero_racional); */
            printf("(%d/%d)", aux->numerador, aux->denominador);
            /* printf("<-[%d]", aux->posicion); */ 
            printf("\n");
            aux = aux->siguiente;
        }
        printf("\n\n");
    }
    else
    {
        printf("Lista vacia\n\n");
    }
}
void imprimir_lista_ascendente(NODO1 *aux)
{
    if (aux != NULL)
    {
        while (aux != NULL)
        {
           /* printf("[%1.3f]", aux->numero_racional);*/
            printf("(%d/%d)", aux->numerador, aux->denominador);
          /*printf("<-[%d]", aux->posicion);*/
            printf("\n");
            aux = aux->siguiente;
        }
        printf("\n\n");
    }
    else
    {
        printf("Lista vacia\n\n");
    }
}

void imprimir_lista_descendente(NODO2 *aux)
{
    if (aux != NULL)
    {
        while (aux != NULL)
        {
            /* printf("[%1.3f]", aux->numero_racional); */
            printf("(%d/%d)", aux->numerador, aux->denominador);
           /* printf("<-[%d]", aux->posicion);*/
            printf("\n");
            aux = aux->siguiente;
        }
        printf("\n\n");
    }
    else
    {
        printf("Lista vacia\n\n");
    }
}

NODO *push(NODO *cabeza, int numerador, int denominador)
{
    NODO *newNodo = (NODO *)malloc(sizeof(NODO));
    newNodo->numerador = numerador;
    newNodo->denominador = denominador;
    newNodo->numero_racional = ((float)numerador / (float)denominador);
    newNodo->siguiente = cabeza;
    newNodo->posicion = 1;
    cabeza = newNodo;
    return cabeza;
}

NODO *push_en_donde_sea(NODO *cabeza, int numerador, int denominador, int posicion)
{
    //recorrer todas los nodos hasta encontrar donde se quiere insertar, luego se desplaza hacia la derecha el resto de nodos
    NODO *current, *nuevo_nodo = (NODO *)malloc(sizeof(NODO));
    int insertado = 0;

    // Caso base y aislado
    if (posicion == 1)
    {
        cabeza = push(cabeza, numerador, denominador);
        insertado = 1;
    }
    current = cabeza;

    // Creamos el nuevo nodo
    nuevo_nodo->numerador = numerador;
    nuevo_nodo->denominador = denominador;
    nuevo_nodo->numero_racional = ((float)numerador / (float)denominador);
    nuevo_nodo->posicion = posicion;

    // nos damos a la tarea de buscar la posicion del nodo
    while (current != NULL)
    { // mientras no hayamos insertado nada seguimos en busqueda
        if (insertado == 0)
        {
            // caso base con indice sobre el maximo
            if (current->siguiente == NULL)
            {
                nuevo_nodo->posicion = current->posicion + 1;
                nuevo_nodo->siguiente = NULL;
                current->siguiente = nuevo_nodo;
                current = nuevo_nodo->siguiente;
                continue;
            }
            // si la posicion del nodo que queremos insertar es el siguiente en la lista
            if (current->siguiente->posicion == posicion)
            {
                // al nodo que queremos insertar le asignamos el nodo que ocupa nuestro lugar
                nuevo_nodo->siguiente = current->siguiente;
                // quitamos el enlace y lo enlazamos al nuevo nodo para ubicar entre ambos nodos al que queremos insertar
                current->siguiente = nuevo_nodo;
                insertado = 1;
                current = nuevo_nodo->siguiente;
            }
            else
            {
                current = current->siguiente;
            }
        }
        else
        {
            // Si ya insertamos debemos iterar sobre el resto para sumar una posicion dado el elemento agregado
            current->posicion++;
            current = current->siguiente;
        }
        // iteramos en otro nodo
    }

    return cabeza;
}

NODO *eliminar(NODO *cabeza)
{
    NODO *temporal = cabeza;
    int a;
    int b;
    printf("\n Ingrese numero a eliminar \n");
    a = pedir_numerador();
    b = pedir_denominador();
    while (temporal != NULL)
    { // caso base especial que esta fuera de la regularidad
        if (temporal->numerador == a && temporal->denominador == b && temporal->posicion == 1)
        {
            cabeza = temporal->siguiente;
            cabeza->posicion = 1;
            temporal = cabeza;
            continue;
        }

        if (temporal->siguiente != NULL)
        {
            if (temporal->siguiente->numerador == a && temporal->siguiente->denominador == b)
            {
                // permutamos enlace para saltarnos el nodo
                temporal->siguiente = temporal->siguiente->siguiente;
                continue;
            }
        }
        temporal = temporal->siguiente;
    }
    return cabeza;
}

float pedir_numero_eliminar()
{
    int numerador;
    int denominador;
    float numero_decimal;
    printf("\nIngrese numero a eliminar\n");
    printf("\nNumerador:");
    scanf("%d", &numerador);
    printf("\n Denominador:");
    scanf("%d", &denominador);
    numero_decimal = ((float)numerador / (float)denominador);
    return numero_decimal;
}

int pedir_numerador()
{
    int numerador;
    do
    {
        printf("\nNumerador:");
        scanf("%d", &numerador);
    } while (numerador < 0);
    return numerador;
}

int pedir_denominador()
{
    int denominador;
    do
    {
        printf("\nDenominador:");
        scanf("%d", &denominador);
    } while (denominador < 0);
    return denominador;
}

float suma_total(NODO *cabeza)
{
    NODO *auxiliar;
    auxiliar = cabeza;
    float sumatoria = auxiliar->numero_racional;
    do
    {
        auxiliar = auxiliar->siguiente;
        sumatoria = sumatoria + auxiliar->numero_racional;
    } while (auxiliar->siguiente != NULL);
    return (sumatoria);
}

float producto_total(NODO *cabeza)
{
    NODO *auxiliar;
    auxiliar = cabeza;
    float producto = auxiliar->numero_racional;
    do
    {
        auxiliar = auxiliar->siguiente;
        producto = producto * auxiliar->numero_racional;
    } while (auxiliar->siguiente != NULL);
    return (producto);
}

int buscar(NODO *cabeza, int numerador, int denominador)
{
    int bandera = 0;
    while (cabeza->siguiente != NULL)
    {
        if (cabeza->numerador == numerador && cabeza->denominador == denominador)
        {
            bandera = 1;
        }
        cabeza = cabeza->siguiente;
    }
     if (cabeza->numerador == numerador && cabeza->denominador == denominador)
        {
            bandera = 1;
        }

    return bandera;
}

NODO *buscar_mayor(NODO *cabeza)
{
    NODO *mayor = cabeza;
    cabeza = cabeza->siguiente;
    while (cabeza->siguiente != NULL)
    {

        if (cabeza->numero_racional > mayor->numero_racional)
        {
            mayor = cabeza;
        }
        cabeza = cabeza->siguiente;
    }
    if (cabeza->numero_racional > mayor->numero_racional)
    {
        mayor = cabeza;
    }
    return mayor;
}

NODO *buscar_menor(NODO *cabeza)
{
    NODO *menor = cabeza;
    cabeza = cabeza->siguiente;
    while (cabeza->siguiente != NULL)
    {
        if (cabeza->numero_racional < menor->numero_racional)
        {
            menor = cabeza;
        }
        cabeza = cabeza->siguiente;
    }
    if (cabeza->numero_racional < menor->numero_racional)
    {
        menor = cabeza;
    }
    return menor;
}

float division(NODO *mayor, NODO *menor)
{
    float resultado;
    resultado = ((float)mayor->numero_racional / (float)menor->numero_racional);
    return resultado;
}

int recorrer_lista_posicion(NODO *cabeza, int numerador, int denominador)
{
    int aux = 0;
    int contador = 0;
    int bandera = 0;
    NODO *temporal;
    temporal = cabeza;
    while (bandera != 1)
    {
        if (temporal->numerador == numerador && temporal->denominador == denominador)
        {
            bandera = 1;
        }
        temporal = temporal->siguiente;
        contador++;
    }
    return contador;
}

int recorrer_lista_contador(NODO *cabeza, int numerador, int denominador)
{
    int aux = 0;
    int contador = 0;
    int bandera = 0;
    NODO *temporal;
    temporal = cabeza;
    while (temporal->siguiente != NULL)
    {
        if (temporal->numerador == numerador && temporal->denominador == denominador)
        {
            contador++;
        }
        temporal = temporal->siguiente;
    }
    return contador;
}

int recorrer_lista_contador1(NODO *cabeza)
{
    int aux = 0;
    int contador = 1;
    int bandera = 0;
    NODO *temporal;
    temporal = cabeza;
    while (temporal->siguiente != NULL)
    {    
        contador++;
        temporal = temporal->siguiente;
    }
    return contador;
}

NODO *recalcular_posicion(NODO *cabeza)
{
    NODO *temporal = cabeza;
    int contador = 1;

    while (temporal != NULL)
    {
        temporal->posicion = contador;
        contador++;
        temporal = temporal->siguiente;
    }
    return cabeza;
}

NODO1 *ordenar_lista_ascendente(NODO1 *cabeza)
{
    NODO1 *actual = cabeza;
    NODO1 *temp = NULL;
    while (actual != NULL)
    {
        NODO1 *siguiente = actual->siguiente;
        if (temp == NULL || actual->numero_racional < temp->numero_racional)
        {
            actual->siguiente = temp;
            temp = actual;
        }
        else
        {
            NODO1 *temp2 = temp;
            while (temp2->siguiente != NULL && actual->numero_racional > temp2->siguiente->numero_racional)
            {
                temp2 = temp2->siguiente;
            }
            actual->siguiente = temp2->siguiente;
            temp2->siguiente = actual;
        }
        actual = siguiente;
    }
    cabeza = temp;

    return cabeza; 
}

NODO2 *ordenar_lista_descendente(NODO2 *cabeza)
{
    NODO2 *actual = cabeza;
    NODO2 *temp = NULL;
    while (actual != NULL)
    {
        NODO2 *siguiente = actual->siguiente;
        if (temp == NULL || actual->numero_racional > temp->numero_racional)
        {
            actual->siguiente = temp;
            temp = actual;
        }
        else
        {
            NODO2 *temp2 = temp;
            while (temp2->siguiente != NULL && actual->numero_racional < temp2->siguiente->numero_racional)
            {
                temp2 = temp2->siguiente;
            }
            actual->siguiente = temp2->siguiente;
            temp2->siguiente = actual;
        }
        actual = siguiente;
    }
    cabeza = temp;
    return cabeza;
}

NODO1 *eliminar_duplicados(NODO1 *cabeza) {
    NODO1 *current = cabeza;
    NODO1 *temp = NULL;

    while (current != NULL) {
        temp = current;

        while (temp->siguiente != NULL) {
            if (current->numerador  == temp->siguiente->numerador && current->denominador== temp->siguiente->denominador) {
                NODO1 *duplicate = temp->siguiente;
                temp->siguiente = temp->siguiente->siguiente;
                free(duplicate);
            } else {
                temp = temp->siguiente;
            }
        }

        current = current->siguiente;
    }
    return cabeza;
}
NODO2 *eliminar_duplica2(NODO2 *cabeza) {
    NODO2 *current = cabeza;
    NODO2 *temp = NULL;

    while (current != NULL) {
        temp = current;

        while (temp->siguiente != NULL) {
            if (current->numerador  == temp->siguiente->numerador && current->denominador == temp->siguiente->denominador) {
                NODO2 *duplicate = temp->siguiente;
                temp->siguiente = temp->siguiente->siguiente;
                free(duplicate);
            } else {
                temp = temp->siguiente;
            }
        }

        current = current->siguiente;
    }
    return cabeza;
}

//* La función toma una lista enlazada y devuelve su copia completa */
NODO1 *copyList(NODO *cabeza)
{
    NODO *current = cabeza;    // usado para iterar sobre la lista original
    NODO1 *newList = NULL;    // cabeza de la nueva lista
    NODO1 *tail = NULL;       // apunta al último nodo en una nueva lista
 
    while (current != NULL)
    {
        // caso especial para el primer nodo nuevo
        if (newList == NULL)
        {
            newList = (NODO1 *)malloc(sizeof(NODO1));
            newList->numerador = current->numerador;
            newList->denominador = current->denominador;
            newList->numero_racional = current->numero_racional;
            newList->siguiente = NULL;
            tail = newList;
        }
        else {
            tail->siguiente = (NODO1 *)malloc(sizeof(NODO1));
            tail = tail->siguiente;
            tail->numerador = current->numerador;
            tail->denominador = current->denominador;
            tail->numero_racional = current->numero_racional;
            tail->siguiente= NULL;
        }
        current = current->siguiente;
    }
 
    return newList;
}

NODO2 *copyLista(NODO *cabeza)
{
    NODO *current = cabeza;    // usado para iterar sobre la lista original
    NODO2 *newList = NULL;    // cabeza de la nueva lista
    NODO2 *tail = NULL;       // apunta al último nodo en una nueva lista
 
    while (current != NULL)
    {
        // caso especial para el primer nodo nuevo
        if (newList == NULL)
        {
            newList = (NODO2 *)malloc(sizeof(NODO2));
            newList->numerador = current->numerador;
            newList->denominador = current->denominador;
            newList->numero_racional = current->numero_racional;
            newList->siguiente = NULL;
            tail = newList;
        }
        else {
            tail->siguiente = (NODO2 *)malloc(sizeof(NODO2));
            tail = tail->siguiente;
            tail->numerador = current->numerador;
            tail->denominador = current->denominador;
            tail->numero_racional = current->numero_racional;
            tail->siguiente= NULL;
        }
        current = current->siguiente;
    }
    return newList;
}
