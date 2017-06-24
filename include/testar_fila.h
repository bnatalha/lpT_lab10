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
void try_back(edb1::myFila<T>& test, const char queue_name);

template <typename T >
void try_front(edb1::myFila<T>& test, const char queue_name);

template <typename T >
void try_pop(edb1::myFila<T>& test, const char queue_name);

template <typename T >
void try_push(edb1::myFila<T>& test, const char queue_name, const T element);

template <typename T >
void try_print_copy(edb1::myFila<T>& test, const char queue_name);

/**
* @brief Realiza testes com objetoss da classe myFila
*/
void testar_fila()
{
	// Criando pilha vazia
	cout << "Criando fila A (vazia)...";
	edb1::myFila<int> A;
	cout << "Pronto." << endl;

	// Testes com fila vazias
	test_size_empty(A,'A');
	cout << "------------------------------------------------------------------" << endl;
	cout << "Iniciando testes com fila vazias..." << endl;
	try_front(A,'A'); try_back(A,'A');
	try_pop(A,'A');

	cout << "------------------------------------------------------------------" << endl;
	cout << endl << "Fazendo A.push(i) 21 vezes para testar my_reallocator() (capacidade inicial de myFila = 20)..." << endl;
	for (int i = 1; i <= 21; i++)
	{	
		try_push(A,'A',i);
		test_size_empty(A,'A');
		try_front(A,'A'); try_back(A,'A');
		cout << "--" << endl;
	}
	cout << endl;

	// Teste com filas criadas a partir de outras;
	cout << "Criando fila B de A(21 elementos)...";
	edb1::myFila<int> B(A);
	cout << "Pronto." << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "Iniciando testes com filas criadas a partir de outras..." << endl;

	cout << "A e B " << (A == B? "": "não ") << "são iguais" << endl;
	cout << "B e A " << (B == A? "": "não ") << "são iguais" << endl;

	try_print_copy(A,'A');
	try_front(A,'A'); try_back(A,'A');
	test_size_empty(A,'A');
	cout << endl;

	try_print_copy(B,'B');
	try_front(B,'B'); try_back(B,'B');
	test_size_empty(B,'B');
	
	cout << "------------------------------------------------------------------" << endl;
	cout << endl << "Deixando A vazio... (testando estado da fila depois do pop())" << endl;
	while (!A.empty())
	{	
		test_size_empty(A,'A');
		try_front(A,'A'); try_back(A,'A');
		try_pop(A,'A');
		cout << endl <<  "--" << endl;
	}

	try_print_copy(A,'A');
	try_print_copy(B,'B');

	cout << "A e B " << (A == B? "": "não ") << "são iguais" << endl;
	cout << "B e A " << (B == A? "": "não ") << "são iguais" << endl;


	cout << endl;

	cout << "------------------------------------------------------------------" << endl;
	cout << "Colocando elementos em A diferentes de B deixando A com o mesmo tamanho de B(" << B.size() << ")." << endl;
	for (int i = 0; i < B.size(); i++)
	{	
		try_push(A,'A',i+7);
		test_size_empty(A,'A');
		try_front(A,'A'); try_back(A,'A');
		cout << "--" << endl;
	}
	cout << endl;

	try_print_copy(A,'A');
	try_print_copy(B,'B');

	cout << "A e B " << (A == B? "": "não ") << "são iguais" << endl;
	cout << "B e A " << (B == A? "": "não ") << "são iguais" << endl;

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
* @brief Imprime no terminal o primeiro de um objeto edb1::myFila, se não cair em uma exceção.
* Testa edb1::myFila<T>::front().
* @param test Referência para um objeto edb1::myFila
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_front(edb1::myFila<T>& test, const char queue_name)
{
	// tenta acessar elemento da frente da fila
	try	{
		cout << "Tentando fazer "<< queue_name <<".front(): ";
		cout << test.front() << ". ";
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Imprime no terminal o ultimo elemento de um objeto edb1::myFila, se não cair em uma exceção.
* Testa edb1::myFila<T>::back().
* @param test Referência para um objeto edb1::myFila
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_back(edb1::myFila<T>& test, const char queue_name)
{
	// tenta acessar elemento do fim da fila
	try	{
		cout << "Tentando fazer "<< queue_name <<".back(): ";
		cout << test.back() << "." << endl;
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
		cout << "Tentando fazer "<< queue_name << ".pop();";
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
		cout << "Tentando fazer " << queue_name << ".push("<< element << ");" << endl;
		test.push(element);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Cria uma cópia estática de um objeto myFila e imprime seu conteúdo no terminal
* utilizando dos metodos back() e pop(); 
* @param test Referência para um objeto edb1::myFila
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_print_copy(edb1::myFila<T>& test, const char queue_name)
{
	edb1::myFila<T> copy(test);

	try{
		//test_size_empty(copy,'c');
		cout << "Tentando imprimir um cópia de '" << queue_name << "'... [ ";
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