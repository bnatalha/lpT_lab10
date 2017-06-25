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

template <typename T >
void test_size_empty(edb1::myLista<T>& test, const char list_name);

template <typename T >
void try_back(edb1::myLista<T>& test, const char list_name);

template <typename T >
void try_front(edb1::myLista<T>& test, const char list_name);

template <typename T >
void try_pop_front(edb1::myLista<T>& test, const char list_name);

template <typename T >
void try_pop_back(edb1::myLista<T>& test, const char list_name);

template <typename T >
void try_push_back(edb1::myLista<T>& test, const char list_name, const T element);

template <typename T >
void try_push_front(edb1::myLista<T>& test, const char list_name, const T element);

/**
* @brief Realiza testes com objetoss da classe myPilha
*/
void testar_lista()
{
	
	//Criando listas
	cout << "Criando listas A, B, C e D (todas vazias).";
	edb1::myLista<int> A;
	edb1::myLista<int> B;
	edb1::myLista<int> C;
	edb1::myLista<int> D;
	cout << "Pronto." << endl;

	cout << "------------------------------------------------------------------" << endl;
	cout << "Iniciando testes com listas vazias..." << endl;
	test_size_empty(A, 'A');
	try_front(A,'A');
	try_back(A,'A');
	try_pop_back(A,'A');
	try_pop_front(A,'A');

	cout << "------------------------------------------------------------------" << endl;
	cout << "Iniciando testes com push_front() e push_back()..." << endl;
	for (int i = 0; i < 5; i++)
	{
		print_myLista(A,'A');
		i%2 == 0 ? (try_push_front(A,'A',i)) : (try_push_back(A,'A',i));
		try_front(A,'A');	try_back(A,'A');
	}
	test_size_empty(A,'A');

	cout << "------------------------------------------------------------------" << endl;
	cout << "Iniciando testes com pop_front() e pop_back()..." << endl;
	for (int i = 0; !A.empty() ; i++)
	{
		print_myLista(A,'A');
		try_front(A,'A');	try_back(A,'A');
		i%2 == 0 ? (try_pop_front(A,'A')) : (try_pop_back(A,'A'));
		cout << endl;
	}
	test_size_empty(A,'A');

	cout << "------------------------------------------------------------------" << endl;
	
	// preenchendo listas
	cout << "Preenchendo listas A, D e B para testes..." << endl;
	for (int i = 0; i <= 10; ++i)
	{
		A.push_back(i);
		if(i != 0 )	D.push_back(i);
		else D.push_back(34);
		if(i%2 == 0) B.push_back(i);
	}
	cout << "Pronto." << endl;
	
	cout << "Atribuindo a lista A à lista C..." << endl;
	C = A;
	cout << "Pronto." << endl;

	cout << "Criando myLista E de A usando contrutor...";
	edb1::myLista<int> E(A);
	cout << "Pronto." << endl; 	

	// imprimindo listas
	cout << "\nConteúdo das listas: " << endl;
	print_myLista(A, 'A');
	print_myLista(B, 'B');
	print_myLista(C, 'C');
	print_myLista(D, 'D');
	print_myLista(E, 'E');

	//comparando listas
	cout << "------------------------------------------------------------------" << endl;
	cout << "\nComparando as listas:" << endl;
	cout << "A e B" << (A == B?" ":" não ") << "são iguais" << endl;
	cout << "A e C" << (A == C?" ":" não ") << "são iguais" << endl;
	cout << "A e D" << (A == D?" ":" não ") << "são iguais" << endl;	
	cout << "A e E" << (A == E?" ":" não ") << "são iguais" << endl;
	cout << "Direção oposta:" << endl;
	cout << "B e A" << (B == A?" ":" não ") << "são iguais" << endl;
	cout << "C e A" << (C == A?" ":" não ") << "são iguais" << endl;
	cout << "D e A" << (D == A?" ":" não ") << "são iguais" << endl;	
	cout << "E e A" << (E == A?" ":" não ") << "são iguais" << endl;		
}


/**
* @brief Imprime o conteúdo de um objeto myLista no terminal
* @param test myLista a ser impresso
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

/**
* @brief Imprime no terminal o tamanho de um objeto edb1::myLista e se ele está vazio ou não.
* Testa edb1::myLista<T>::size() e edb1::myLista<T>::empty()
* @param test Referência para um objeto edb1::myLista
* @param list_name Nome da variável que guarda 'test'
*/
template <typename T >
void test_size_empty(edb1::myLista<T>& test, const char list_name)
{
	cout << list_name << ".size(): " << test.size() << "\t";
	cout << "'" << list_name <<"'" << (test.empty()? "":" não") << " está vazia." << endl;
}

/**
* @brief Imprime no terminal o primeiro de um objeto edb1::myLista, se não cair em uma exceção.
* Testa edb1::myLista<T>::front().
* @param test Referência para um objeto edb1::myLista
* @param list_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_front(edb1::myLista<T>& test, const char list_name)
{
	// tenta acessar elemento da frente da lista
	try	{
		cout << "Tentando fazer "<< list_name <<".front(): ";
		cout << test.front() << ". ";
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Imprime no terminal o ultimo elemento de um objeto edb1::myLista, se não cair em uma exceção.
* Testa edb1::myLista<T>::back().
* @param test Referência para um objeto edb1::myLista
* @param list_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_back(edb1::myLista<T>& test, const char list_name)
{
	// tenta acessar elemento do fim da lista
	try	{
		cout << "Tentando fazer " << list_name <<".back(): ";
		cout << test.back() << "." << endl;
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa edb1::myLista<T>::pop_back()
* @param test Referência para um objeto edb1::myLista
* @param list_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_pop_back(edb1::myLista<T>& test, const char list_name)
{
	// tenta remover o elemento do fim da lista
	try	{
		cout << "Tentando fazer "<< list_name << ".pop_back();";
		test.pop_back();
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa edb1::myLista<T>::pop_front()
* @param test Referência para um objeto edb1::myLista
* @param list_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_pop_front(edb1::myLista<T>& test, const char list_name)
{
	// tenta remover o elemento do início da lista
	try	{
		cout << "Tentando fazer "<< list_name << ".pop_front();";
		test.pop_front();
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa edb1::myLista<T>::push_back()
* @param test Referência para um objeto edb1::myLista
* @param list_name Nome da variável que guarda 'test'
* @param element Elemento a ser acrescentado em 'test'
*/
template <typename T >
void try_push_back(edb1::myLista<T>& test, const char list_name, const T element)
{
	// tenta colocar um elemento no fim da lista
	try	{
		cout << "Tentando fazer " << list_name << ".push_back("<< element << ");" << endl;
		test.push_back(element);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa edb1::myLista<T>::push_front()
* @param test Referência para um objeto edb1::myLista
* @param list_name Nome da variável que guarda 'test'
* @param element Elemento a ser acrescentado em 'test'
*/
template <typename T >
void try_push_front(edb1::myLista<T>& test, const char list_name, const T element)
{
	// tenta colocar um elemento no início da lista
	try	{
		cout << "Tentando fazer " << list_name << ".push_front("<< element << ");" << endl;
		test.push_front(element);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Cria uma cópia estática de um objeto myLista e imprime seu conteúdo no terminal
* utilizando dos metodos back() e pop(); 
* @param test Referência para um objeto edb1::myLista
* @param list_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_print_copy(edb1::myLista<T>& test, const char list_name)
{
	edb1::myLista<T> copy(test);

	try{
		//test_size_empty(copy,'c');
		cout << "Tentando imprimir um cópia de '" << list_name << "'... [ ";
		for (int i = 0 ; i < copy.size(); ){
			cout << copy.front() << " ";
			copy.pop();
		}
		cout << "]" << endl;

	}catch (std::exception &e){
		cout << e.what() << endl;
	}

}


#endif