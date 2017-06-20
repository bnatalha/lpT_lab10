/**
* @file
* @brief Implementação de myPilha do namespace edb1
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 14/05/2017
* @date 20/06/17
* @sa std::stack (http://www.cplusplus.com/reference/stack/stack/)
*/

#ifndef MYPILHA_H
#define MYPILHA_H

#include "natalia.h"

namespace edb1
{
	// Implementações de myPilha

	/**
	* @retval true A pilha está vazia
	* @retval false A pilha \b não está vazia
	*/
	template <typename T >
	bool myPilha<T>::empty()
	{
		return (tamanho == 0);
	}

	/**
	* @return Referência para o tamanho da pilha
	*/
	template <typename T >
	int& myPilha<T>::size()
	{
		return tamanho;
	}

	/**
	* @return Referência para o elemento no topo da pilha
	*/
	template <typename T >
	T& myPilha<T>::top()
	{
		if (empty())
			throw std::out_of_range ("[EXCEPTION] top(): Não há elementos na pilha");

		return pilha[tamanho-1];
	}

	/**
	* @param element Elemento do tipo T a ser acrescentado ao topo da pilha
	*/
	template <typename T >
	void myPilha<T>::push(const T& element)
	{
		if(tamanho == capacidade)
			throw std::length_error ("[EXCEPTION] push(): A capacidade máxima da pilha (fixa em 50) já foi atingida.");

		pilha[tamanho++] = element;	// Acrescenta elemento e depois aumenta o tamanho da pilha
	}

	template <typename T >
	void myPilha<T>::pop()
	{
		if (empty())
			throw std::length_error ("[EXCEPTION] pop(): Não pode remover elementos de uma pilha vazia");

		pilha[(tamanho--)-1].~T();	// Remove elemento e depois diminui o tamanho da pilha
	}
}

#endif