/**
* @file
* @brief Implementação das funções que testam os algoritmos de ordenação do namespace edb1
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 26/03/2017
* @date 20/06/17
*/

#ifndef TESTAR_ORDENACAO_H
#define TESTAR_ORDENACAO_H

#include <ctime>
#include "natalia.h"

void fillVector(int *v, int N);	/**< Preenche um arranjo de inteiros com valores aleatórios entre 0 e 30. */
void printVector(int *v, int N);	/**< Imprime o conteúdo de um arranjo de inteiros no terminal (cout) */
void sort_test(int *v, int N, void (*alg_sort) (int*,int,int) );	/**< Preenche um arranjo de inteiros com valores aleatorios e depois os ordena utilizando uma função sort */

/**
* @brief Testa os algoritmos de ordenação com arranjos de interios gerados aleatoriamente e alocados dinamicamente
*/
void testar_ordenacao( )	
{

	// Teste com arranjos de tamanho 0, 1, 2, 3, 16 e 17.
	
	int sizes[6] = {0, 1, 2, 3, 16, 17};	/*< Arranjo de inteiros que armazenará o tamanho dos arranjos apontados por 'arrays' */
	//				0  1  2  3   4   5
	
	cout << "Alocando arranjos dinamicamente (tamanhos: 0, 1, 2, 3, 16 e 17)...";
	
	int** arrays = new int*[6];	/**< Ponteiro para arranjo de inteiros dinamicamente alocado de tamanho '6' */

	for (int i = 0; i < 6; i++) arrays[i] = new int[sizes[i]];	// Alocando arranjos dinamicamente

	cout << "Pronto." << endl;

	for(auto i = 0; i < 6; i++)
	//for(auto i = 0; i <= 4; i++)
	{
		cout << "=======================================================================================" << endl;
		cout << " Testes com vetor de tamanho: ( " << sizes[i] << " )" << endl;
		cout << "---------------- myBubbleSort----------------" << endl;
		sort_test(arrays[i], sizes[i], edb1::myBubbleSort);
		cout << "---------------------------------------------" << endl;
		cout << "---------------- myInsertSort----------------" << endl;
		sort_test(arrays[i], sizes[i], edb1::myInsertSort);
		cout << "---------------------------------------------" << endl;
		cout << "---------------- mySelectionSort----------------" << endl;
		sort_test(arrays[i], sizes[i], edb1::mySelectionSort);
		cout << "---------------------------------------------" << endl;
		cout << "---------------- myQuickSort----------------" << endl;
		sort_test(arrays[i], sizes[i], edb1::myQuickSort);
		cout << "---------------------------------------------" << endl;
		cout << "---------------- mySplitSort----------------" << endl;
		sort_test(arrays[i], sizes[i], edb1::mySplitSort);
		cout << "---------------------------------------------" << endl;
		cout << "=======================================================================================" << endl;
	}

	cout << "Deletando arranjos alocados dinamicamente. " << endl;
	for (int i = 0; i < 6; i++) delete[] arrays[i];
	delete[] arrays;
}

/**
* @param v arranjo de inteiros a ser preenchido
* @param N tamanho do arranjo a ser preenchido
*/
void fillVector(int *v, int N)
{	
	srand (time(NULL));		// Usa o tempo de máquina atual como semente para gerar rand()

	for (int i = 0; i < N; ++i) v[i] = rand() % 31;	// Atribui a cada posição 'i' um valor aleatório que pertença a [0,30]
}

/**
* @param v arranjo de inteiros a ser impresso
* @param N tamanho do arranjo a ser impresso
*/
void printVector(int *v, int N)
{
	cout << "Arranjo: [ ";
	for (int i = 0; i < N; ++i) cout << v[i] << " ";
	cout << "]";
}

/**
* @param v arranjo de inteiros
* @param N tamanho do arranjo
* @param alg_sort ponteiro para a função de ordenação a ser utilizada
*/
void sort_test(int *v, int N, void (*alg_sort) (int*,int,int) )
{
	cout << "Preenchendo meu arranjo de inteiros com valores aleatorios...";
	fillVector(v,N);	// Preenche arranjo com valores aleatorios entre 0 e 30.

	cout << "Pronto." << endl;
	printVector(v,N);	// Mostra o conteudo do arranjo gerado aleatoriamente no terminal.

	cout << endl << "Ordenando arranjo...";
	alg_sort( v, 0, N-1);	// Ordena o arranjo usando o algoritmo escolhido.

	cout << "Pronto." << endl;
	printVector(v,N);	// Mostra o conteudo do arranjo após ter sido oredenado.
	cout << endl;
}

#endif