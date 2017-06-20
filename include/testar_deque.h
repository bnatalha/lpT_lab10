/**
* @file
* @brief Testes com myDeque.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 20/06/2017
* @date 20/06/17
* @date 20/06/17
*/

#ifndef TESTAR_DEQUE
#define TESTAR_DEQUE

#include "natalia.h"

template <typename T >
void test_size_empty(edb1::myDeque<T>& test, const char queue_name);

template <typename T >
void try_front_back(edb1::myDeque<T>& test, const char queue_name);

template <typename T >
void try_at_op(edb1::myDeque<T>& test, const char queue_name);

template <typename T >
void try_push_front(edb1::myDeque<T>& test, const char queue_name, const T element);

template <typename T >
void try_pop_front(edb1::myDeque<T>& test, const char queue_name);

template <typename T >
void try_pop_back(edb1::myDeque<T>& test, const char queue_name);

template <typename T >
void try_push_back(edb1::myDeque<T>& test, const char queue_name, const T element);

/**
* @brief Realiza testes com objetoss da classe myDeque
*/
void testar_deque()
{
	// Criando opilha vazia
	cout << "Criando deque A (vazio)...";
	edb1::myDeque<int> A;
	cout << "Pronto.====================================" << endl;

	// Testes com pilhas vazias
	test_size_empty(A,'A');
	try_front_back(A,'A');
	try_at_op(A,'A');
	try_pop_back(A,'A');
	try_pop_front(A,'A');

	cout << "Pushing A...====================================" << endl;
	//for (int i = 1; i < 4; i++)
	for (int i = 1; i < 12; i++)
	{	
		try_push_back(A,'A',(2 * i) - 1);
		test_size_empty(A,'A');
		try_front_back(A,'A');
		try_at_op(A,'A');		
		try_push_front(A,'A',(2 * i));
		test_size_empty(A,'A');
		try_front_back(A,'A');
		try_at_op(A,'A');
		cout << "--" << endl;
	}
	cout << endl;

	cout << "Criando deque B de A(22 elementos)...";
	edb1::myDeque<int> B(A);
	cout << "Pronto.====================================" << endl;

	cout << "Testando B...====================================" << endl;
	test_size_empty(B,'B');
	try_front_back(B,'B');
	try_pop_back(B,'B');
	test_size_empty(B,'B');
	try_front_back(B,'B');
	try_at_op(B,'B');
	cout << "==" << endl;

	cout << "Popping A...====================================" << endl;
	for (int i = 0; i < 5; i++)
	{	
		if (i%2 == 0)try_pop_back(A,'A');
		else try_pop_front(A,'A');
		test_size_empty(A,'A');
		try_front_back(A,'A');
		try_at_op(A,'A');
		cout << "--" << endl;
	}
	cout << endl;

	cout << "Pushing A...====================================" << endl;
	for (int i = 7; i < 9; i++)
	{	
		try_push_back(A,'A',i);
		test_size_empty(A,'A');
		try_front_back(A,'A');
		cout << "--" << endl;
	}
	cout << endl;

	cout << "Criando deque C e atribuindo A à C A...";
	edb1::myDeque<int> C;
	C = A;
	cout << "Pronto.====================================" << endl;

	try_at_op(A,'A');
	try_at_op(B,'B');
	try_at_op(C,'C');

	cout << "A e C " << (A == C? "":"não ") << "são iguais "<< endl;
	cout << "C e A " << (C == A? "":"não ") << "são iguais "<< endl;

	cout << "Limpando A...";
	A.clear();
	cout << "Pronto.====================================" << endl;

	cout << "Testando C:====================================" << endl;
	
	cout << "A e C " << (A == C? "":"não ") << "são iguais "<< endl;
	cout << "C e A " << (C == A? "":"não ") << "são iguais "<< endl;
	cout << "A e B " << (A == B? "":"não ") << "são iguais "<< endl;
	cout << "B e A " << (B == A? "":"não ") << "são iguais "<< endl;
	
}

/**
* @brief Imprime no terminal o tamanho de um objeto edb1::myDeque e se ele está vazio ou não.
* Testa edb1::myDeque<T>::size() e edb1::myDeque<T>::empty()
* @param test Referência para um objeto edb1::myDeque
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void test_size_empty(edb1::myDeque<T>& test, const char queue_name)
{
	cout << queue_name << ".size(): " << test.size() << "\t";
	cout << "'" << queue_name <<"'" << (test.empty()? "":" não") << " está vazia." << endl;
}

/**
* @brief Imprime no terminal o primeiro e ultimo elemento de um objeto edb1::myDeque, se não cair em uma exceção
* Testa edb1::myDeque<T>::front() e edb1::myDeque<T>::back()
* @param test Referência para um objeto edb1::myDeque
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_front_back(edb1::myDeque<T>& test, const char queue_name)
{
	// tenta acessar elemento da frente da deque
	try	{
		cout << queue_name << ".front(): " << test.front();
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}

	// tenta acessar elemento do fim da deque
	try	{
		cout << " e " << queue_name <<".back(): " << test.back() << "." << endl;
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Tenta imprimir no terminal todos os elementos do Deque através dos métodos
* edb1::myDeque<T>::at() e edb1::myDeque<T>::operator[]
* @param test Referência para um objeto edb1::myDeque
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_at_op(edb1::myDeque<T>& test, const char queue_name)
{
	// tenta acessar elementos da deque com operator[]
	try	{
		cout << queue_name <<"[]: [ ";
		for( int i = 0;  i < test.size(); i++ ) cout << test[i] << " ";
		cout << "]" << endl;
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}

	// tenta acessar elementos da deque com at()
	try	{
		cout << queue_name <<".at(): ( ";
		for( int i = 0;  i < test.size(); i++ ) cout << test.at(i) << " ";
		cout << ")" << endl;
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}	
}

/**
* @brief Testa edb1::myDeque<T>::push_back()
* @param test Referência para um objeto edb1::myDeque
* @param queue_name Nome da variável que guarda 'test'
* @param element Elemento a ser acrescentado em 'test'
*/
template <typename T >
void try_push_back(edb1::myDeque<T>& test, const char queue_name, const T element)
{
	// tenta colocar um elemento ao fim da deque
	try	{
		cout << queue_name << ".push_back("<< element << ");" << endl;
		test.push_back(element);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa edb1::myDeque<T>::pop_back()
* @param test Referência para um objeto edb1::myDeque
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_pop_back(edb1::myDeque<T>& test, const char queue_name)
{
	// tenta remover o elemento mais velho da deque
	try	{
		cout << queue_name << ".pop_back();" << endl;
		test.pop_back();
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa edb1::myDeque<T>::push_front()
* @param test Referência para um objeto edb1::myDeque
* @param queue_name Nome da variável que guarda 'test'
* @param element Elemento a ser acrescentado em 'test'
*/
template <typename T >
void try_push_front(edb1::myDeque<T>& test, const char queue_name, const T element)
{
	// tenta colocar um elemento ao fim da deque
	try	{
		cout << queue_name << ".push_front("<< element << ");" << endl;
		test.push_front(element);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa edb1::myDeque<T>::pop_front()
* @param test Referência para um objeto edb1::myDeque
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_pop_front(edb1::myDeque<T>& test, const char queue_name)
{
	// tenta remover o elemento mais velho da deque
	try	{
		cout << queue_name << ".pop_front();" << endl;
		test.pop_front();
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

#endif