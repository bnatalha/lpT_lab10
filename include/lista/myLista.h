/**
* @file
* @brief Definição de myLista e implementação das sobrecargas de operadores dela
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 14/05/2017
* @date 15/06/2017
* @sa std::stack (http://www.cplusplus.com/reference/stack/stack/, http://en.cppreference.com/w/cpp/container/list)
*/

#ifndef MYLISTA_H
#define MYLISTA_H

#include "header_2.h"

namespace edb1
{
// Implementação de Sobrecargas

/**
* @brief Sobrecarga do operador "==". Checa se duas listas são iguais.
* @param l_direita Lista a ser comparada
*/
template <typename T>
bool myLista<T>::operator== ( myLista<T> l_direita)
{
	if(size() != l_direita.size()) // Se as listas forem de tamanhos diferentes
		return false;	// São diferentes
	
	//else	

	myNode *esq = sentinela_head;	// Cria ponteiro para o início desta lista
	myNode *dir = l_direita.sentinela_head;	// Cria ponteiro para o início da lista a ser comparada
	
	while( esq != NULL )	// Enquanto não chegar ao fim da lista*
	{
		if (esq->elemento != dir->elemento) return false;	// Se o conteúdo dos ponteiros forem diferentes entre sí, não são listas iguais

		esq = esq->proximo;	// Movimento o ponteiro para frente
		dir = dir->proximo;	// Movimento o ponteiro para frente
	}

	return true;

	// *Os dois ponteiros andam na mesma velocidade em listas de tamanhos iguais
}

/**
* @brief Sobrecarga do operador "!=". Checa se duas listas são diferente.
* @param l_direita Lista a ser comparada
*/
template <typename T>
bool myLista<T>::operator!= ( myLista<T> l_direita)
{
	return ( not( *this == l_direita ) );
}

/**
* @brief Sobrecarga do operador "="
* @param copy Lista a ser copiada
*/
template <typename T>
myLista<T>& myLista<T>::operator= (const myLista<T> copy)
{
	if ( *this != copy )
	{
		clear();	// Destroi os elementos da lista que vai ser modificada
		
		myNode *_pointer = copy.sentinela_head;	// Cria um ponteiro não constante para o início da lista a ser copiada
		while( _pointer != NULL )	// Enquanto ponteiro não chegar no fim da lista a ser copiada (NULL)
		{
			push_back(_pointer->elemento);	// Acrescenta o elemento do nó da vez ao fim desta lista
			_pointer = _pointer->proximo;	// Ponteiro anda no sentido do fim da lista a ser copida
		}
	}

	return *this;
}

/**
* @brief Sobrecarga do operador "<<"
* @param out ostream a ser usada
* @param lista myLista a ser impressa
* @sa Explicação para uso do typename dentro da função em http://stackoverflow.com/questions/610245/
*/
/*
template <typename foo>
std::ostream& operator<< (std::ostream& out, const myLista<foo> lista)
{
	typename myLista<foo>::myNode *_pointer = lista.sentinela_head;	// Ponteiro para o primeiro nó da lista

	out << "[ ";
	while( _pointer != NULL )
	{
		out << _pointer->elemento << (_pointer->proximo == NULL ? " ": ", ");
		_pointer = _pointer->proximo;
	}
	out << "]";

	return out;
}
*/

}

#include "myLista_00_Iterator.h"
#include "myLista_01_Ite_methods.h"
#include "myLista_1_Construtor.h"
#include "myLista_2_Destrutor.h"
#include "myLista_3_Acess.h"
#include "myLista_4_Capacity.h"
#include "myLista_5_Modifiers.h"
#include "myLista_6_Operations.h"

#endif