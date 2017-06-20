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

	/**
	* @param element Elemento do tipo T a ser acrescentado na frente da fila
	*/
	template <typename T >
	void myFila<T>::push(const T& element)
	{
		if(size() == capacidade)
			throw std::length_error ("[EXCEPTION] push(): A capacidade máxima da fila (fixa em 50) já foi atingida.");
		

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