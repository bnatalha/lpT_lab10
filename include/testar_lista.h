/**
* @file
* @brief Testes com myPilha.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 18/06/2017
* @date 20/06/17
*/

#ifndef TESTAR_LISTA_H
#define TESTAR_LISTA_H

#include "natalia.h"

template< typename T>
void print_myLista(edb1::myLista<T>& test, const char list_name);

/**
* @brief Realiza testes com objetoss da classe myPilha
*/
void testar_lista()
{
	

	edb1::myLista<int> A;
	edb1::myLista<int> B;
	edb1::myLista<int> C;
	edb1::myLista<int> D;

	// preenchendo listas
	cout << "Preenchendo listas para testes..." << endl;
	for (int i = 0; i <= 10; ++i)
	{
		A.push_back(i);
		if(i != 0 )D.push_back(i);
		else D.push_back(34);
		if(i%2 == 0) B.push_back(i);
	}
	
	C = A;

	cout << "Criando myLista E de A...";
	edb1::myLista<int> E(A);
	cout << "Pronto." << endl; 	

	// imprimindo listas
	print_myLista(A, 'A');
	print_myLista(B, 'B');
	print_myLista(C, 'C');
	print_myLista(D, 'D');
	print_myLista(E, 'E');

	//comparando listas
	cout << "------------------------------------------------------------------" << endl;
	cout << "Comparando as listas" << endl;
	cout << "A e B" << (A == B?" ":" não ") << "são iguais" << endl;
	cout << "A e C" << (A == C?" ":" não ") << "são iguais" << endl;
	cout << "A e D" << (A == D?" ":" não ") << "são iguais" << endl;	
	cout << "A e E" << (A == E?" ":" não ") << "são iguais" << endl;

	cout << "B e A" << (B == A?" ":" não ") << "são iguais" << endl;
	cout << "C e A" << (C == A?" ":" não ") << "são iguais" << endl;
	cout << "D e A" << (D == A?" ":" não ") << "são iguais" << endl;	
	cout << "E e A" << (E == A?" ":" não ") << "são iguais" << endl;		
}


/**
* @brief Imprime o conteúdo de um objeto myLista no terminal
* @param test myFila a ser impresso
* @param list_name nome da variável que guarda 'test'
*/
template< typename T>
void print_myLista(edb1::myLista<T>& test, const char list_name)
{
	cout << list_name <<": [ ";
	for (auto &e : test)
		cout << e << " ";
	cout << "]" << endl;
}


#endif