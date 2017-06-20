/**
* @file
* @brief Testes com myFila.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 18/06/2017
* @date 20/06/17
*/

#ifndef TESTAR_FILA_H
#define TESTAR_FILA_H

#include "natalia.h"

template <typename T >
void test_size_empty(edb1::myFila<T>& test, const char queue_name);

template <typename T >
void try_front_back(edb1::myFila<T>& test, const char queue_name);

template <typename T >
void try_pop(edb1::myFila<T>& test, const char queue_name);

template <typename T >
void try_push(edb1::myFila<T>& test, const char queue_name, const T element);

/**
* @brief Realiza testes com objetoss da classe myFila
*/
void testar_fila()
{
	// Criando opilha vazia
	cout << "Criando fila A (vazia)...";
	edb1::myFila<int> A;
	cout << "Pronto." << endl;

	// Testes com pilhas vazias
	test_size_empty(A,'A');
	try_front_back(A,'A');
	try_pop(A,'A');

	cout << "Pushing A..." << endl;
	//for (int i = 1; i < 4; i++)
	for (int i = 1; i <3; i++)
	{	
		try_push(A,'A',i);
		test_size_empty(A,'A');
		try_front_back(A,'A');
		cout << "--" << endl;
	}
	cout << endl;

	cout << "Criando fila B de A(1 elemento)...";
	edb1::myFila<int> B(A);
	cout << "Pronto." << endl;

	cout << "Testando B..." << endl;
	test_size_empty(B,'B');
	try_front_back(B,'B');
	try_pop(B,'B');
	test_size_empty(B,'B');
	try_front_back(B,'B');
	cout << endl;

	cout << "Popping A..." << endl;
	for (int i = 1; i < 3; i++)
	{	
		try_pop(A,'A');
		test_size_empty(A,'A');
		try_front_back(A,'A');
		cout << "--" << endl;
	}
	cout << endl;

	cout << "Pushing A..." << endl;
	for (int i = 7; i < 9; i++)
	{	
		try_push(A,'A',i);
		test_size_empty(A,'A');
		try_front_back(A,'A');
		cout << "--" << endl;
	}
	cout << endl;

	cout << "Criando Fila C de A...";
	edb1::myFila<int> C(A);
	cout << "Pronto." << endl;

	cout << "Limpando A...";
	while (A.empty() == false) A.pop();
	cout << "Pronto." << endl;

	cout << "Testando C:" << endl;
	test_size_empty(C,'C');
	try_front_back(C,'C');
	try_pop(C,'C');
	test_size_empty(C,'C');
	try_front_back(C,'C');
	
}

/**
* @brief Imprime no terminal o tamanho de um objeto edb1::myFila e se ele está vazio ou não.
* Testa edb1::myFila<T>::size() e edb1::myFila<T>::empty()
* @param test Referência para um objeto edb1::myFila
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void test_size_empty(edb1::myFila<T>& test, const char queue_name)
{
	cout << queue_name << ".size(): " << test.size() << "\t";
	cout << "'" << queue_name <<"'" << (test.empty()? "":" não") << " está vazia." << endl;
}

/**
* @brief Imprime no terminal o primeiro e ultimo elemento de um objeto edb1::myFila, se não cair em uma exceção
* Testa edb1::myFila<T>::front() e edb1::myFila<T>::back()
* @param test Referência para um objeto edb1::myFila
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_front_back(edb1::myFila<T>& test, const char queue_name)
{
	// tenta acessar elemento da frente da fila
	try	{
		cout << queue_name << ".front(): " << test.front();
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}

	// tenta acessar elemento do fim da fila
	try	{
		cout << " e " << queue_name <<".back(): " << test.back() << "." << endl;
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa edb1::myFila<T>::pop()
* @param test Referência para um objeto edb1::myFila
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_pop(edb1::myFila<T>& test, const char queue_name)
{
	// tenta remover o elemento mais velho da fila
	try	{
		cout << queue_name << ".pop();" << endl;
		test.pop();
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa edb1::myFila<T>::push()
* @param test Referência para um objeto edb1::myFila
* @param queue_name Nome da variável que guarda 'test'
* @param element Elemento a ser acrescentado em 'test'
*/
template <typename T >
void try_push(edb1::myFila<T>& test, const char queue_name, const T element)
{
	// tenta colocar um elemento ao fim da fila
	try	{
		cout << queue_name << ".push("<< element << ");" << endl;
		test.push(element);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

#endif