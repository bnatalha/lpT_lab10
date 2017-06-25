/**
* @file
* @brief Testes com myPilha.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 18/06/2017
* @date 20/06/17
*/

#ifndef TESTAR_PILHA_H
#define TESTAR_PILHA_H

#include "natalia.h"

template <typename T >
void test_size_empty(edb1::myPilha<T>& test, const char queue_name);

template <typename T >
void try_top(edb1::myPilha<T>& test, const char queue_name);

template <typename T >
void try_pop(edb1::myPilha<T>& test, const char queue_name);

template <typename T >
void try_push(edb1::myPilha<T>& test, const char queue_name, const T element);

/**
* @brief Realiza testes com objetoss da classe myPilha
*/
void testar_pilha()
{
	// Criando pilhas
	cout << "Criando pilha A<int>..."; 
	edb1::myPilha<int> A;	// capacidade: padrão (2)
	cout << "Pronto." << endl;

	// Testes com pilhas vazias
	cout << "------------------------------------------------------------------" << endl;
	cout << "Iniciando testes com pilhas vazias..." << endl;
	test_size_empty(A,'A');
	try_top(A,'A');	
	try_pop(A,'A');	
	cout << "--" << endl;

	// Testando push
	cout << "Pushing A..." << endl;

	for(int i = 1; i <= 21; i++)
	{
		try_push(A,'A',i);
		try_top(A,'A');
		test_size_empty(A,'A');
		cout << endl << "--" << endl;
	}
	cout << endl;

	// Testanto Construtor myPilha(myPilha)
	cout << "Criando pilha C de A..."; 
	edb1::myPilha<int> C(A);
	cout << "Pronto." << endl;

	// Testando pop
	cout << "Popping C" << endl;
	while( C.empty() == false)
	{
		test_size_empty(C,'C');
		try_top(C,'C');	
		try_pop(C,'C');
		cout << endl << "--" << endl;
	}

	test_size_empty(C,'C');
	try_top(C,'C');	// Pilha ja vazia
	cout << endl;
}

/**
* @brief Imprime no terminal o tamanho de um objeto edb1::myPilha e se ele está vazio ou não.
* Testa edb1::myPilha<T>::size() e edb1::myPilha<T>::empty()
* @param test Referência para um objeto edb1::myPilha
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void test_size_empty(edb1::myPilha<T>& test, const char queue_name)
{
	cout << queue_name << ".size(): " << test.size() << "\t";
	cout << "'" << queue_name <<"'" << (test.empty()? "":" não") << " está vazia. ";
}

/**
* @brief Imprime no terminal o primeiro e ultimo elemento de um objeto edb1::myPilha, se não cair em uma exceção
* Testa edb1::myPilha<T>::front() e edb1::myPilha<T>::back()
* @param test Referência para um objeto edb1::myPilha
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_top(edb1::myPilha<T>& test, const char queue_name)
{
	// tenta acessar elemento da frente da fila
	try	{
		cout << queue_name << ".top(): " << test.top() << " ";;
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa edb1::myPilha<T>::pop()
* @param test Referência para um objeto edb1::myPilha
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_pop(edb1::myPilha<T>& test, const char queue_name)
{
	// tenta remover o elemento mais velho da fila
	try	{
		cout << queue_name << ".pop(); ";
		test.pop();
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa edb1::myPilha<T>::push()
* @param test Referência para um objeto edb1::myPilha
* @param queue_name Nome da variável que guarda 'test'
* @param element Elemento a ser acrescentado em 'test'
*/
template <typename T >
void try_push(edb1::myPilha<T>& test, const char queue_name, const T element)
{
	// tenta colocar um elemento ao fim da fila
	try	{
		cout << queue_name << ".push("<< element << "); ";
		test.push(element);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

#endif