/**
* @file
* @brief Implementação de myFila do namespace edb1
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 18/06/2017
* @date 20/06/17
* @sa std::stack (http://www.cplusplus.com/reference/stack/stack/)
*/

#ifndef MYFILA_H
#define MYFILA_H

#include "natalia.h"

namespace edb1
{
	// Implementações de myFila

	/**
	* @brief Realoca o container do deque para o dobro de sua capacidade total
	*/
	template <typename T>
	void myFila<T>::my_reallocator()
	{
		bool is_empty = empty();	// guarda se o deuque está vazio ou não

		T* new_fila;	// ponteiro para o novo fila;

		// tenta alocar o dobro da capacidade do deque atual
		try{
			new_fila = new T[capacidade*2];	// cria um novo fila com o dobro de capacidade
		}catch (std::bad_alloc& ba)		{
			cout << "bad_alloc caught: " << ba.what() << endl;
		}
		
		int new_fim = 0;
		for (int i = ini; new_fim < size(); new_fim++)	// atribui ao novo bloco de memoria informações do atual
		{
			new_fila[new_fim] = fila[i];
			//cout << fila[i] << " ";
			i = ((i+1) % capacidade);
		}

		// fixa indices 
		ini = ( is_empty? -1 : 0 );
		fim = ( is_empty? -1 : new_fim-1 );

		delete[] fila;	// Deleta bloco de memoria apontado por 'fila' (antigo)
		fila = new_fila;	// aponta 'fila' para o bloco de memoria criado
		capacidade = capacidade*2;	// dobra 'capacidade'
	}

	// =================================================================================================
	// =========================================== Construtores ========================================
	// =================================================================================================

	/**
	* @brief Constroi um objeto myFila sem passar atributos.
	*/
	template <typename T>
	myFila<T>::myFila()	: capacidade(20), ini(-1), fim(-1)
	{
		// tenta alocar o container da fila
		try{
			fila = new T[capacidade];
		}catch (std::bad_alloc& ba)		{
			cout << "bad_alloc caught: " << ba.what() << endl;
		}
	}

	/**
	* @brief Constroi um objeto myFila  partir de uma fila já definida pelo usuário
	* @param orig myFila já existente que será sada pra construir a atual
	*/
	template <typename T>
	myFila<T>::myFila(const myFila &orig)	: capacidade(orig.capacidade), ini(orig.ini), fim(orig.fim)
	{
		for (int i = 0; i < capacidade; ++i)
		{
			this->fila[i] = orig.fila[i];	// Copia elementos da fila passada por argumento para a fila a ser criada
		}
		
	}

	// ========================================= Destrutor =============================================

	/**
	* @brief Desaloca 'fila' após chamar o destrutor de seus respectivos elementos
	*/
	template <typename T>
	myFila<T>::~myFila()
	{
		delete[] fila;
	}

	// =================================================================================================
	// ======================================== Capacidade =============================================
	// =================================================================================================


	/**
	* @retval true A fila está vazia
	* @retval false A fila \b não está vazia
	*/
	template <typename T >
	bool myFila<T>::empty()
	{
		return (size() == 0);
	}

	/**
	* @return Referência para o tamanho da fila
	*/
	template <typename T >
	int myFila<T>::size()
	{
		if (ini == -1) return 0;
		else if(ini == fim ) return 1;
		else if(ini < fim) return ((fim-ini)+1);
		//else if (ini > fim)
		return ( (fim + (capacidade - ini) )+ 1);
	}

	// =================================================================================================
	// =========================================== Acesso ==============================================
	// =================================================================================================


	/**
	* @return Referência para o elemento na frente da fila
	*/
	template <typename T >
	T& myFila<T>::front()
	{
		if (empty())
			throw std::out_of_range ("[EXCEPTION] front(): Não há elementos na fila");
		

		return fila[ini];
	}

	/**
	* @return Referência para o elemento no fim da fila
	*/
	template <typename T >
	T& myFila<T>::back()
	{
		if (empty())
			throw std::out_of_range ("[EXCEPTION] back(): Não há elementos na fila");
		

		return fila[fim];
	}

	// =================================================================================================
	// ======================================= Modificadores ===========================================
	// =================================================================================================

	/**
	* @param element Elemento do tipo T a ser acrescentado na frente da fila
	*/
	template <typename T >
	void myFila<T>::push(const T& element)
	{
		if(size() == capacidade)	my_reallocator();

		if (empty())	// se for o primeiro elemento a entrar na fila
			ini++;	// coloca 'ini' para apontar

		fim = (fim+1)%capacidade;	// avança indice 'fim'
		fila[fim] = element;	// Acrescenta elemento e depois aumenta o tamanho da fila
	}

	template <typename T >
	void myFila<T>::pop()
	{
		if (empty())
			throw std::length_error ("[EXCEPTION] pop(): Não pode remover elementos de uma fila vazia");
		

		fila[ini].~T();	// Remove elemento da frente

		if (size() == 1)	// se só existir um elemento na fila antes do pop()
		{
			ini = -1;	// fixa índices para fora da fila
			fim = -1;
		}
		else
			ini = (ini+1)%capacidade;	// avança indice 'ini'
		
	}
}

#endif