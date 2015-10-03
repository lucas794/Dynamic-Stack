#include "pila.h"
#include <stdlib.h>


/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void **datos;
    size_t tam;
    size_t largo;
};

#define TAM_INICIAL 100 
#define FACTOR_UTILIZACION_MEMORIA 4
#define FACTOR_MULTIPLICADOR 2

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

// ...

/* ESTRUCTURAS AUXILIARES */
bool pila_cambiar_tamanio(pila_t *pila, size_t tamanio_a_reasignar)
{
	/*Dada una pila válida, reasigna el tamaño a la misma para lograr
	ingresar mas elementos, en caso de fallar, devolverá false, en caso contrario
	devolvera true*/

	void *aux = realloc(pila->datos, sizeof(void*) * tamanio_a_reasignar);

	if( aux == NULL )
		return false;

	pila->datos = aux;
	pila->largo = tamanio_a_reasignar;
	
	return true;
}
/* FIN ESTRUCTURAS AUXILIARES */ 


pila_t* pila_crear() {
	pila_t* nueva_pila = malloc( sizeof(pila_t) );
	
	if( nueva_pila == NULL ) {
		return NULL;
	}
	nueva_pila->datos = malloc( TAM_INICIAL * sizeof(void*) );
	
	if( nueva_pila->datos == NULL )
	{
		/* hay que liberar lo que se pidió previamente */
		free(nueva_pila);
		return NULL;
	}
	nueva_pila->largo = TAM_INICIAL;
	nueva_pila->tam = 0; 

	return nueva_pila;
}

void pila_destruir( pila_t *pila )
{
	free(pila->datos);
	free(pila);
	pila = NULL;
}

bool pila_esta_vacia(const pila_t *pila)
{
	if( pila == NULL ||  pila->tam == 0 )
		return true;
	else
		return false;
}

bool pila_apilar(pila_t *pila, void* valor)
{
	if( pila == NULL )
		return false;

	if( pila->tam >= pila->largo ) /* ¿Pasamos el límite asignado? */
	{	
		if( !pila_cambiar_tamanio(pila, pila->largo * FACTOR_MULTIPLICADOR) ) /* no se puede alargar el doble ? */
			return false;
	}
	pila->datos[pila->tam++] = valor;
	return true;
}

void* pila_ver_tope(const pila_t *pila)
{
	if( pila == NULL ||  pila_esta_vacia(pila) )
		return NULL;

	return pila->datos[pila->tam - 1];
}

void* pila_desapilar(pila_t *pila)
{
	if( pila == NULL || !pila->tam )
		return NULL;

	void* valor_aux;
	valor_aux = pila_ver_tope(pila); /*desapilamos el último */

	if( pila->tam < (pila->largo / FACTOR_UTILIZACION_MEMORIA) ) /* ¿Usamos el cuarto del espacio obtenido ? */
		if( !pila_cambiar_tamanio(pila, pila->largo / FACTOR_MULTIPLICADOR) ) // redimencionamos la pila para no usar tanta memoria
			return NULL;
	pila->tam--;

	return valor_aux;
}
