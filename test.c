#include "pila.h"
#include "testing.h"
#include <stdlib.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_pila_alumno() {
	/* ******************************************************************
 	*                   PILA NULA
 	* *****************************************************************/
    pila_t* ejemplo = NULL;

    print_test("Puntero inicializado a NULL", ejemplo == NULL);
	print_test("\nPrueba pila EJEMPLO (null) Apilar es falso...", !(pila_apilar(ejemplo, (int *) 5))); /* just example */
	print_test("Prueba pila EJEMPLO (null) Desapilar es NULL...", pila_desapilar(ejemplo) == NULL );
	print_test("Prueba pila EJEMPLO (null) Ver tope es NULL... ", pila_ver_tope(ejemplo) == NULL);
	print_test("Prueba pila EJEMPLO (null) Pila vacia?..", pila_esta_vacia(ejemplo));

	/* ******************************************************************
 	*                   PILA CON 4 ELEMENTOS (ÍNFIMA)
 	* *****************************************************************/
	pila_t* pPila = pila_crear();

	print_test("\nPrueba pila 1 - Nueva pila de enteros (infima) creada! ¿Distinto de NULL? ...", pPila != NULL);
	
	int iValoresApilables[ ] = { 5, 22, 36, 512 };
	int iValores = 0;

	print_test("Prueba pila 1 Apilar elemento 5...", pila_apilar(pPila, &iValoresApilables[iValores]) );
	print_test("Prueba pila 1 Apilar elemento 22...", pila_apilar(pPila, &iValoresApilables[++iValores]) );
	print_test("Prueba pila 1 Apilar elemento 36...", pila_apilar(pPila, &iValoresApilables[++iValores]) );
	print_test("Prueba pila 1 Apilar elemento 512...", pila_apilar(pPila, &iValoresApilables[++iValores])) ;
	
	/* pila hasta el momento
	[ 5, 22, 36 , 512 ] , NO está vacia y el tope es 512...
	*/

	// p = pila_ver_tope(pila) ó pila_desapilar(pila)

	print_test("Prueba pila 1 ¿La pila, NO está vacia? ...", !(pila_esta_vacia(pPila)));
	print_test("Prueba pila 1 ¿El tope es la referencia a 512? ... ", pila_ver_tope(pPila) == &iValoresApilables[iValores]); // p == iValoresApilables[3] ?
	print_test("Prueba pila 1 Desapilando valor, ¿Es la referencia a 512?", pila_desapilar(pPila) == &iValoresApilables[iValores]); // p == iValoresApilables[3]
	print_test("Prueba pila 1 Desapilando valor, ¿Es la referencia a 36?", pila_desapilar(pPila) == &iValoresApilables[--iValores]); // p == iValoresApilables[2] ?
	print_test("Prueba pila 1 Desapilando valor, ¿Es la referencia a 22?", pila_desapilar(pPila) == &iValoresApilables[--iValores]); // p == iValoresApilables[1] ?
	print_test("Prueba pila 1 Desapilando valor, ¿Es la referencia a 5?", pila_desapilar(pPila) == &iValoresApilables[--iValores]); // p == iValoresApilables[0] ?

	print_test("Prueba pila 1La pila está vacia?...", pila_esta_vacia(pPila));
	print_test("Prueba pila 1 El tope es NULL? ... ", pila_ver_tope(pPila) == NULL);

	pila_destruir(pPila);
	print_test("Prueba pila 1 Destruir la pila de enteros (infima)...", true);

	/* ******************************************************************
 	*                   PILA CON VOLUMEN (VARIOS ENTEROS)
 	* *****************************************************************/

	pila_t* pPila1 = pila_crear();

	print_test("\nPrueba pila 2 Nueva pila de enteros con volumen creada!, ¿Distinto de NULL?...", pPila1 != NULL );
	print_test("Prueba pila 2 Desapilar es NULL...", pila_desapilar(pPila1) == NULL );
	print_test("Prueba pila 2 Ver tope es NULL... ", pila_ver_tope(pPila1) == NULL);
	print_test("Prueba pila 2 Pila vacia?..", pila_esta_vacia(pPila1));

	size_t tamanio_de_ingreso = 50000;
	size_t i = 0;
    bool ok = true;
    for ( ; i < tamanio_de_ingreso; i++) {
        // Si algun elemento no se pudo guardar correctamente, ok sera false (gracias VD)
        ok &= pila_apilar(pPila1, &i);
    }
	
	// aquí i debe valer 1336 (Afuera del bucle!)

	print_test("Prueba pila 2 ¿Se pudieron apilar todos los elementos? ... ", ok);
	print_test("Prueba pila 2 El tope es la referencia a 49999? ...", pila_ver_tope(pPila1) == &i );
	print_test("Prueba pila 2 La pila NO esta vacia?...", !pila_esta_vacia(pPila1));

	ok = true;
    while( !pila_esta_vacia(pPila1) )
	{
        ok &= (pila_desapilar(pPila1) == &i);
		i--;
    }
	print_test("Prueba pila 2 se pudieron obtener todos los elementos", ok);

	pila_destruir(pPila1);
	print_test("Prueba pila 2 Destruir la pila masiva de enteros...", true);
	
	/* ******************************************************************
 	*                   PILA CON STRINGS (DOCENTES)
 	* *****************************************************************/

	pila_t* pPila2 = pila_crear();

	print_test("\nPrueba pila 3 Nueva pila de cadenas creada!, ¿Distinto de NULL?...", pPila2 != NULL );
	print_test("Prueba pila 3 Desapilar es NULL...", pila_desapilar(pPila2) == NULL );
	print_test("Prueba pila 3 Ver tope es NULL... ", pila_ver_tope(pPila2) == NULL);
	print_test("Prueba pila 3 Pila vacia?..", pila_esta_vacia(pPila2));

	char *szDocentesParaApilar[] = { "dato", "fede b", "martin b", "sebas", "daniela",
									 "rosita", "ana", "jenny", "fede e", "emiliano", "nacho" };
	
	const int iCantidadDocentes = sizeof(szDocentesParaApilar) / sizeof(szDocentesParaApilar[0]);

	print_test("Prueba pila 3 Apilar la referencia de szDocentesParaApilar?...", pila_apilar(pPila2, szDocentesParaApilar));

	print_test("Prueba pila 3 Desapilar la referencia en pila coincide con el vector de docentes?...", pila_desapilar(pPila2) == szDocentesParaApilar);
	
	ok = true;

	for(char **docente = szDocentesParaApilar; docente != &szDocentesParaApilar[iCantidadDocentes]; docente++)
		ok &= pila_apilar(pPila2, docente);


	print_test("Prueba pila 3 ¿Se pudieron apilar todos los profesores? ... ", ok);
	print_test("Prueba pila 3 El tope es la referencia a nacho??? ...", pila_ver_tope(pPila2) == (szDocentesParaApilar + iCantidadDocentes - 1));
	print_test("Prueba pila 3 La pila NO esta vacia?...", !pila_esta_vacia(pPila2));

	ok = true;
    for(char **docente = &szDocentesParaApilar[iCantidadDocentes - 1]; docente != szDocentesParaApilar - 1; docente-- )
        ok &= (pila_desapilar(pPila2) == docente);

	print_test("Prueba pila 3 se pudieron obtener todos los elementos", ok);
	pila_destruir(pPila2);
	print_test("Prueba pila 3 Destruir la pila de cadenas...", true);

	pila_t* pPila3 = pila_crear();
	
	print_test("Prueba pila 4 apilar NULL... ", pila_apilar(pPila3, NULL));
	print_test("Prueba pila 4 pila NO vacia?? ...", !pila_esta_vacia(pPila3));
	print_test("Prueba pila 4 desapilar es NULL...", pila_desapilar(pPila3) == NULL);
	print_test("Prueba pila 4 pila VACIA??? ... ", pila_esta_vacia(pPila3));

	pila_destruir(pPila3);
}
