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

	/**
	* @brief Realoca o container da fila para o dobro de sua capacidade total
	*/
	template <typename T>
	void myPilha<T>::my_reallocator()
	{
		T* new_pilha;	// ponteiro para o novo pilha;

		// tenta alocar o dobro da capacidade da fila atual
		try{
			new_pilha = new T[capacidade*2];	// cria uma nova pilha com o dobro de capacidade
		}catch (std::bad_alloc& ba)		{
			cout << "bad_alloc caught: " << ba.what() << endl;
		}
		
		for (int i = 0; i < size(); i++)	// atribui ao novo bloco de memoria informações do atual
			new_pilha[i] = pilha[i];

		delete[] pilha;	// Deleta bloco de memoria apontado por 'pilha' (antigo)
		pilha = new_pilha;	// aponta 'pilha' para o bloco de memoria criado
		capacidade = capacidade*2;	// dobra 'capacidade'
	}

	// =================================================================================================
	// ======================================= Construtores ============================================
	// =================================================================================================


	/**
	* @brief Constroi um objeto myPilha sem passar atributos.
	*/
	template <typename T>
	myPilha<T>::myPilha()	:  capacidade(20), tamanho(0)
	{
		//tenta alocar a pilha dinamicamente
		try{
			pilha = new T[capacidade];
		}catch (std::bad_alloc& ba)		{
			cout << "bad_alloc caught: " << ba.what() << endl;
		}
	}

	/**
	* @brief Constroi um objeto myPilha  partir de uma pilha já definida pelo usuário
	* @param my_stack myPilha já existente que será sada pra construir a atual
	*/
	template <typename T>
	myPilha<T>::myPilha(const myPilha &my_stack)	: capacidade(my_stack.capacidade), tamanho(my_stack.tamanho)
	{
		//tenta alocar a pilha dinamicamente
		try{
			pilha = new T[capacidade];
		}catch (std::bad_alloc& ba)		{
			cout << "bad_alloc caught: " << ba.what() << endl;
		}

		for (int i = 0; i < capacidade; ++i)
			this->pilha[i] = my_stack.pilha[i];	// Copia elementos da pilha passada por argumento para a pilha a ser criada
		
	}

	// =================================================================================================
	// ========================================= Destrutor =============================================
	// =================================================================================================


	/**
	* @brief Desaloca 'pilha' após chamar o destrutor de seus respectivos elementos
	*/
	template <typename T>
	myPilha<T>::~myPilha()
	{
		delete[] pilha;
	}


	// =================================================================================================
	// ========================================= Capacidade ============================================
	// =================================================================================================


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

	// =================================================================================================
	// ======================================= Modificadores ===========================================
	// =================================================================================================

	/**
	* @param element Elemento do tipo T a ser acrescentado ao topo da pilha
	*/
	template <typename T >
	void myPilha<T>::push(const T& element)
	{
		if(tamanho == capacidade)
			my_reallocator();

		pilha[tamanho++] = element;	// Acrescenta elemento e depois aumenta o tamanho da pilha
	}

	template <typename T >
	void myPilha<T>::pop()
	{
		if (empty())
			throw std::length_error ("[EXCEPTION] pop(): Não pode remover elementos de uma pilha vazia");

		pilha[(tamanho--)-1].~T();	// Remove elemento e depois diminui o tamanho da pilha
	}

	// =================================================================================================
	// ================================== Sobrecarga de operadores =====================================
	// =================================================================================================


}

#endif