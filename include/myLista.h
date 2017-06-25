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

#include "natalia.h"

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


	// ====================================================================================================
	// ======================================== CONST_ITERATOR ============================================
	// ====================================================================================================

	// Construtor 

	/**
	* @brief Constroi um iterador constante vazio
	*/
	template < typename T >
	myLista<T>::const_iterator::const_iterator()
	{
		atual = NULL;	// Aponta o ponteiro para nó interno do iterator para NULL
	}

	// Acesso

	/**
	* @brief Sobrecarga do operador '*' para iteradores constantes
	* @return Retorna o nó apontado pelo iterator
	*/
	template < typename T >
	const T& myLista<T>::const_iterator::operator*() const
	{
		return *(atual)->data;
	}


	// Incremento e Decremento

	/**
	* @brief Sobrecarga do operador++ para iteradores constantes (pós-incrementação)
	* @return Iterator temporário criado dentro da função
	* @sa posfix Increment and decrement (http://www.learncpp.com/cpp-tutorial/97-overloading-the-increment-and-decrement-operators/)
	*/
	template < typename T >
	typename myLista<T>::const_iterator myLista<T>::const_iterator::operator++(int)
	{
		const_iterator temp(atual); // Cria um const_iterator temporário com as informações do iterator usado antes da chamada desta função
		atual = atual->proximo; // Aumenta o valor do iterator usado
		return temp;
	}

	/**
	* @brief Sobrecarga do operador++ para iteradores constantes (pré-incrementação)
	* @return Iterator atualizado com a incrementação
	* @sa prefix Increment and decrement (http://en.cppreference.com/w/cpp/language/operators)
	*/
	template < typename T >
	typename myLista<T>::const_iterator& myLista<T>::const_iterator::operator++()
	{
		atual = atual->proximo; // iterator usado aponta para o próximo nó da lista
		return *this;
	}

	/**
	* @brief Sobrecarga do operador-- para iteradores constantes (pós-decrementação)
	* @return Iterator temporário criado dentro da função
	* @sa posfix Increment and decrement (http://www.learncpp.com/cpp-tutorial/97-overloading-the-increment-and-decrement-operators/)
	*/
	template < typename T >
	typename myLista<T>::const_iterator myLista<T>::const_iterator::operator--(int)
	{
		const_iterator temp(atual); // Cria um const_iterator temporário com as informações do iterator usado antes de sofrer a decrementação
		atual = atual->anterior; // Manado o iterator para o nó anterior o valor do iterator usado
		return temp;
	}

	/**
	* @brief Sobrecarga do operador++ para iteradores constantes (pré-decrementação)
	* @return Iterator atualizado com a decrementação
	* @sa prefix Increment and decrement (http://en.cppreference.com/w/cpp/language/operators)
	*/
	template < typename T >
	typename myLista<T>::const_iterator& myLista<T>::const_iterator::operator--()
	{
		atual = atual->anterior; // iterator usado passa a apontar para nó anterior na lista
		return *this;
	}

	// Comparação

	/**
	* @brief Sobrecarga do operador== para iteradores constantes
	* @return Verifica se os iterators estam apontando para o mesmo nó
	*/
	template < typename T >
	bool myLista<T>::const_iterator::operator== (const const_iterator& it_direita) const
	{
		return (atual == it_direita.atual); 
	}

	/**
	* @brief Sobrecarga do operador!= para iteradores constantes
	* @return Verifica se os iterators estam apontando para nós doferentes
	*/
	template < typename T >
	bool myLista<T>::const_iterator::operator!= (const const_iterator& it_direita) const
	{
		return (atual != it_direita.atual); // Retorne true se os dois atuals são diferentes
	}

	// ====================================================================================================
	// ============================================ ITERATOR ==============================================
	// ====================================================================================================

	// Acesso

	/**
	* @brief Sobrecarga do operador* para iteradores não constantes em listas constantes
	* @return Valor/elemento armazenado no nó apontado pelo iterator
	*/
	template < typename T >
	const T & myLista<T>::iterator::operator* () const
	{
		return (this->atual)->elemento; 
	}

	/**
	* @brief Sobrecarga do operador* para iteradores não constantes
	* @return Valor/elemento armazenado no nó apontado pelo iterator
	*/
	template < typename T >
	T & myLista<T>::iterator::operator* ()
	{
		return (this->atual)->elemento;
	}

	// Incremento e Decremento

	/**
	* @brief Sobrecarga do operador++ para iteradores constantes (pós-incrementação)
	* @return Iterator temporário criado dentro da função
	* @sa posfix Increment and decrement (http://www.learncpp.com/cpp-tutorial/97-overloading-the-increment-and-decrement-operators/)
	*/
	template < typename T >
	typename myLista<T>::iterator myLista<T>::iterator::operator++(int)
	{
		iterator temp(this->atual); // Cria um const_iterator temporário com as informações do iterator usado antes da chamada desta função
		this->atual = (this->atual)->proximo; // Aumenta o valor do iterator usado
		return temp;
	}

	/**
	* @brief Sobrecarga do operador++ para iteradores constantes (pré-incrementação)
	* @return Iterator atualizado com a incrementação
	* @sa prefix Increment and decrement (http://en.cppreference.com/w/cpp/language/operators)
	*/
	template < typename T >
	typename myLista<T>::iterator& myLista<T>::iterator::operator++()
	{
	    this->atual = (this->atual)->proximo; // iterator usado aponta para o próximo nó da lista
	    return *this;
	}

	/**
	* @brief Sobrecarga do operador-- para iteradores não constantes (pós-decrementação)
	* @return Iterator temporário criado dentro da função
	* @sa posfix Increment and decrement (http://www.learncpp.com/cpp-tutorial/97-overloading-the-increment-and-decrement-operators/)
	*/
	template < typename T >
	typename myLista<T>::iterator myLista<T>::iterator::operator--(int)
	{
		iterator temp(this->atual); // Cria um const_iterator temporário com as informações do iterator usado antes de sofrer a decrementação
		this->atual = (this->atual)->anterior; // iterator usado passa a apontar para nó anterior na lista
		return temp;
	}

	/**
	* @brief Sobrecarga do operador++ para iteradores não constantes (pré-decrementação)
	* @return Iterator atualizado com a decrementação
	* @sa prefix Increment and decrement (http://en.cppreference.com/w/cpp/language/operators)
	*/
	template < typename T >
	typename myLista<T>::iterator& myLista<T>::iterator::operator--()
	{
		this->atual = (this->atual)->anterior; // iterator usado passa a apontar para nó anterior na lista
		return *this;
	}

	// ?
	/**
	* @brief Sobrecarga do operador= (atribuição)
	* @return Valor/elemento armazenado no nó apontado pelo iterator
	*/
	template < typename T >
	typename myLista<T>::iterator& myLista<T>::iterator::operator=( const iterator& it_direita )
	{
		this->atual = it_direita.atual;
		return *this;
	}

	// ====================================================================================================
	// ======================================= ITERATOR_METODOS ===========================================
	// ====================================================================================================

	/**
	* @brief Constrói um const_iterator que aponta para o início da lista (primeiro elemento)
	*/
	template < typename T>
	typename myLista<T>::const_iterator myLista<T>::begin() const
	{
		typename myLista<T>::const_iterator cit(sentinela_head);
		return cit;
	}

	/**
	* @brief Constrói um iterator que aponta para o início da lista (primeiro elemento)
	*/
	template < typename T>
	typename myLista<T>::iterator myLista<T>::begin()
	{
		typename myLista<T>::iterator cit(sentinela_head);
		return cit;
	}

	/**
	* @brief Constrói um const_iterator que aponta para o elemento após o último
	*/
	template < typename T>
	typename myLista<T>::const_iterator myLista<T>::end() const
	{
		typename myLista<T>::const_iterator cit(NULL);	// NULL = sentinela_tail->proximo
		return cit;
	}

	/**
	* @brief Constrói um iterator que aponta para o elemento após o último
	*/
	template < typename T>
	typename myLista<T>::iterator myLista<T>::end()
	{
		typename myLista<T>::iterator cit(NULL);	// NULL = sentinela_tail->proximo
		return cit;
	}

	/**
	* @brief Constrói uma lista vazia
	*/
	template < typename T>
	myLista<T>::myLista()
		: sentinela_head(NULL), sentinela_tail(NULL), qtd_elementos(0)
	{}

	// ====================================================================================================
	// ========================================== COSTRUTORES =============================================
	// ====================================================================================================

	/**
	* @brief Constrói uma lista a partir de uma lista já existente
	* @param copy Lista a ser copiada
	*/
	template < typename T>
	myLista<T>::myLista( const myLista & copy )
		: sentinela_head(NULL), sentinela_tail(NULL), qtd_elementos(0)
	{
		myNode * _pointer = copy.sentinela_head;

		while (_pointer != NULL)
		{
			push_back(_pointer->elemento);
			_pointer = _pointer->proximo;
		}
	}

	/**
	* @brief [INVALIDO]Constrói uma lista com 'n' elementos, todos elementos sendo 'val'
	* (.: //Invalidado pela nova implementação dos metodos push (só entra algum elemento na lista caso ele ainda não exista nela)
	* @param n Quantidade de elementos a ser criados
	* @param val Valor que cada elemento criado a partir desta função receberá
	*/
	template < typename T>	// fill;
	myLista<T>::myLista(const int& n, const T& val)
	: sentinela_head(NULL), sentinela_tail(NULL), qtd_elementos(0)
	{
		while (size() < n)	// Enquanto o tamanho da lista for menor que 'n'
			push_front(val);	// Adiciona a lista nós com elemento 'val'
	}

	// ====================================================================================================
	// ============================================ DESTRUTOR =============================================
	// ====================================================================================================

	/**
	* @brief Destroi a lista, destruindo seus elementos.
	*/
	template < typename T>
	myLista<T>::~myLista()
	{
		clear();
	}

	// ====================================================================================================
	// ============================================= ACESSO ===============================================
	// ====================================================================================================

	/**
	* @brief Acessa o elemento mais a frente na lista
	* @return O elemento do nó apontado pela cabeça;
	*/
	template < typename T>
	T& myLista<T>::front()
	{
		// exceção caso lista esteja vazia
		if(empty())
			throw std::out_of_range ("[EXCEPTION] front(): Não há elementos na lista");

		return (sentinela_head->elemento);
	}

	/**
	* @brief Acessa o elemento no último nó da lista
	* @return O elemento do nó apontado pela cauda;
	*/
	template < typename T>
	T& myLista<T>::back()
	{
		if(empty())
			throw std::out_of_range ("[EXCEPTION] back(): Não há elementos na lista");

		return (sentinela_tail->elemento);
	}

	// ====================================================================================================
	// =========================================== CAPACIDADE =============================================
	// ====================================================================================================

	/**
	* @brief Checa se a quantidade de nós da lista
	* @return atributo qtd_elementos
	*/
	template < typename T>
	int myLista<T>::size()
	{
		return qtd_elementos;
	}

	/**
	* @brief Checa se a lista está vazia
	*/
	template < typename T>
	bool myLista<T>::empty()
	{
		return ( size() == 0 );
	}

	/**
	* @brief Remove todos os elementos da lista, a deixando com tamanho = 0.
	*/
	template < typename T>
	void myLista<T>::clear()
	{
		while ( sentinela_head != NULL )	// Se tiver mais de um elemento na lista,
		{
			pop_back();
		}
	}

	// ====================================================================================================
	// ======================================== MODIFICADORES =============================================
	// ====================================================================================================

	/**
	* @brief Adiciona um elemento a lista respeitando a ordem DECRESCENTE (Tem comportamento inesperado se a lista não estiver nesta ordem)
	* @param elem Elemento a ser adicionado ao início da lista
	*/
	template < typename T>
	void myLista<T>::push_sorted( T elem )
	{
		myNode *new_node;

		//tenta alocar um novo nó
		try	{
			new_node = new myNode(elem);	// Cria um novo nó dinamicamente com o elemento a ser adicionado
		}catch (std::bad_alloc& ba)		{
			cout << "bad_alloc caught: " << ba.what() << endl;
		}

		if ( empty() )	 // Se for o primeiro nó da lista (sentinelas não contam)
		{
			sentinela_tail = new_node;	// O nó criado agora é o ultimo da lista	
			sentinela_head = new_node;	// O nó criado agora também é o primeiro da lista	

			qtd_elementos++;	// Total de elementos da lista aumenta	
		}
			
		else // Se já existir algum elemento na lista
		{
			if(elem >= sentinela_head->elemento)	// Se o elemento a ser acrescentado for maior ou igual do que o que está na frente da lista
			{
				delete new_node;	// Não vai ser mais necessário o nó criado graças as função push_front()
				push_front(elem);	// Coloca o elemento na frente da Lista
			}
			else if(sentinela_tail->elemento >= elem)	// Se o elemento do fim da lista for maior ou igual do que o que vai ser acrescentado
			{
				delete new_node;	// Não vai ser mais necessário o nó criado graças as função push_back()
				push_back(elem);	// Coloca o elemento no final da lista
			}
			else if(sentinela_head->elemento > elem and sentinela_tail->elemento < elem )	// else
			{
				myNode *_pointer = NULL;	// Cria um ponteiro para nós

				_pointer = sentinela_head;	// Atribui a _pointer um ponteiro para o primeiro nó da lista

				while(elem <= _pointer->elemento)	// Até encontrar um nó com um elemento que seja menor do que o que será acrescentado a lista			_pointer = _pointer->proximo;	// Avança o _pointer em direção a fim da lista 

				// Associa o new_node com os nós proximos a ele
				// Situação inicial: [elem]	[_p-1]-[_p]
				new_node->proximo = _pointer;	// [elem]->[_p] | [_p-1]-[_p]
				new_node->anterior = _pointer->anterior;	// [_p-1]<-[elem]->[_p] | [_p-1]-[_p]
				// Coloca new_node entre os elementos _pointer->anterior e _pointer
				_pointer->anterior->proximo = new_node;	// [_p-1]-[elem] | [_p-1]<-[_p]
				_pointer->anterior = new_node;	// [_p-1]-[elem]-[_p]

				qtd_elementos++;	// Total de elementos da lista aumenta	
			
			}
		}
	}

	/**
	* @brief Adiciona um elemento ao fim da lista
	* @param elem Elemento a ser adicionado ao fim da lista
	*/
	template < typename T>
	void myLista<T>::push_back( const T& elem )
	{
		myNode *new_node;
		//tenta alocar um novo nó
		try	{
			new_node = new myNode(elem, sentinela_tail);	// Cria um novo nó dinamicamente com o elemento adicionado, com o anterior dele sendo o último atual (apontado pela cauda)
		}catch (std::bad_alloc& ba)		{
			cout << "bad_alloc caught: " << ba.what() << endl;
		}

		if ( empty() ) // Se for o primeiro nó da lista (sentinelas não contam)
			sentinela_head = new_node;	// O nó criado agora é o primeiro da lista	
			
		else // Se já existir algum elemento na lista
			sentinela_tail->proximo = new_node;	// Faz com que o ultimo nó da lista aponte para o nó criado

		sentinela_tail = new_node;	// O nó criado agora é o ultimo da lista

		qtd_elementos++;	// Total de elementos da lista aumenta	
	}

	/**
	* @brief Remove um elemento do fim da lista, se está não estiver vazia
	*/
	template < typename T>
	void myLista<T>::pop_back()
	{
		if (empty())
			throw std::length_error ("[EXCEPTION] pop_back(): Não pode remover elementos de uma lista vazia");

		myNode *_destruir = sentinela_tail;	// Atribui o endereço apontado pela cauda a um ponteiro
		sentinela_tail = sentinela_tail->anterior;	// A cauda agora aponta para o *penúltimo* nó (ou null, se tamanho da lista for 1)
		
		if (size() == 1 )	// Se a lista possuir apenas um elemento
			sentinela_head = NULL;	// Aponta a cabeça para NULL
		
		if( sentinela_tail != NULL )	// Se o rabo não estiver apontando para NULL (se a lista possuir mais de um elemento)
			sentinela_tail->proximo = NULL;	// // O novo ultimo nó não tem mais ligação com o antigo ultimo nó


		delete _destruir;	// Deleta o elemento que era o último da lista

		qtd_elementos--;	// Total de elementos da lista diminui
	}

	/**
	* @brief Adiciona um elemento ao início da lista
	* @param elem Elemento a ser adicionado ao início da lista
	*/
	template < typename T>
	void myLista<T>::push_front( const T& elem )
	{
		myNode *new_node;

		//tenta alocar um novo nó
		try	{
			new_node = new myNode(elem, NULL, sentinela_head);	// Cria um novo nó dinamicamente com o elemento adicionado, com o próximo dele sendo o primeiro atual (apontado pela cabeça)
		}catch (std::bad_alloc& ba)		{
			cout << "bad_alloc caught: " << ba.what() << endl;
		}

		if ( empty() ) // Se for o primeiro nó da lista (sentinelas não contam)
			sentinela_tail = new_node;	// O nó criado agora é o primeiro da lista	
			
		else // Se já existir algum elemento na lista
			sentinela_head->anterior = new_node;	// O primeiro nó da lista agora tem um nó anterior: O nó criado

		sentinela_head = new_node;	// O nó criado é o novo primeiro nó da lista

		qtd_elementos++;	// Total de elementos da lista aumenta	
	}

	/**
	* @brief Remove um elemento do início lista, se está não estiver vazia
	* @retval true Se um elemento foi retirado
	* @retval false Se a lista for vazia
	*/
	template < typename T>
	void myLista<T>::pop_front()
	{
		if (empty())
			throw std::length_error ("[EXCEPTION] pop_back(): Não pode remover elementos de uma lista vazia");

		myNode *_destruir = sentinela_head;	// Atribui o endereço apontado pela cabeça a um ponteiro
		sentinela_head = sentinela_head->proximo;	// A cabeça agora aponta para o *segundo* nó (ou null, se tamanho da lista for 1)

		if (size() == 1 )	// Se a lista possuir apenas um elemento
			sentinela_tail = NULL;	// Aponta a cauda para NULL

		if( sentinela_head != NULL )	// Se a cabeça não estiver apontando para NULL (se a lista possuir mais de um elemento)
			sentinela_head->anterior = NULL;	// O novo primeiro nó não tem mais ligação com o antigo primeiro nó
		
		delete _destruir;	// Deleta o elemento que era o primeiro da lista

		qtd_elementos--;	// Total de elementos da lista diminui	
	}

	// ====================================================================================================
	// ========================================== OPERAÇÕES ===============================================
	// ====================================================================================================

	/**
	* @brief Destroi o nó apontado por um iterator
	* @param it iterator da lista que aponta qual nó será destruído
	*/
	template < typename T>
	void myLista<T>::erase( myLista<T>::iterator &it )
	{
		myNode *_pointer = (it.atual);	// _pointer aponta para o mesmo nó que o iterator it;
		myNode *_destruir;	// Ponteiro para o nó a ser destruído.
		
		it++;	// iterator avança;

		// Verificando posição do nó apontado pelo ponteiro na lista
		if(_pointer->anterior == NULL and _pointer->proximo == NULL)
		// H-> [val] <-T (Se só existe este nó na lista)
		{
			pop_front();
			_pointer = NULL;
		}
		else if(_pointer->anterior != NULL and _pointer->proximo == NULL)	// Já percorreu toda a lista
		// H-> [n_0]...[n_k-1][val] <-T (Se só existe nó anterior a este e não depois dele)
		{
			_pointer = _pointer->proximo;	// Avança o ponteiro para o fim da lista
			pop_back();
			//_pointer = NULL;
		}
		else if(_pointer->anterior == NULL and _pointer->proximo != NULL)
		// H-> [val][n_1]...[n_k] <-T Se só existe nó depois deste e não antes dele)
		{	
			//_pointer é igual a head
			_pointer = _pointer->proximo;	// Avança o ponteiro para o fim da lista
			pop_front();	// Destroi o elemento (supostamente no início da lista)

		}
		else if(_pointer->anterior != NULL and _pointer->proximo != NULL)
		// H-> [n_0]...[n_z][val][n_z+2]...[n_k] <-T (Se existe nó antes e depois deste)
		{
			// Inicialmente: [x]-[val]-[y],	onde "-" indica que estão conectados em ambos sentidos (anterior e proximo)
					
			_pointer->anterior->proximo = _pointer->proximo;	// Pega o nó anterior ao selecionado e o conecta com o próximo do atual
			// [x]->[z]  [x]<-[val]-[z]
					
			_pointer->proximo->anterior = _pointer->anterior;	// Pega o nó depois do selecionado e o conecta com o anterior do selecionado
			// [x]-[z] [x]<-[val]->[z]
					
			_destruir = _pointer;	// Atribui ao ponteiro destrutor qual o nó a ser destruído
			// _destruir -> [val]
					
			_pointer = _pointer->proximo; //	Avança o ponteiro em direção ao fim da lista
			// _pointer -> [val]
					
				delete _destruir; // Destrói o nó [val]

			qtd_elementos--; // Diminui o contador de elementos da lista
		}
	}

	/**
	* @brief Remove da listas, os nós cujos elementos sejam iguais a 'val'
	* @param val Valor buscado para ser removido
	*/
	template < typename T>
	void myLista<T>::remove(const T& val)
	{
		myNode * _pointer = sentinela_head;	// Cria ponteiro para o início da lista, a partir da sentinela da cabeça
		myNode * _destruir= NULL;	// Ponteiro para o nó a ser destruído

		while(_pointer != NULL)	// Enquanto o ponteiro não percorrer toda a lista
		{
			if(_pointer->elemento == val)	// Se achou valor
			{
				// Verificando posição do nó apontado pelo ponteiro na lista
				if(_pointer->anterior == NULL and _pointer->proximo == NULL)
				// H-> [val] <-T (Se só existe este nó na lista)
				{
					pop_front();
					_pointer = NULL;
				}
				else if(_pointer->anterior != NULL and _pointer->proximo == NULL)	// Já percorreu toda a lista
				// H-> [n_0]...[n_k-1][val] <-T (Se só existe nó anterior a este e não depois dele)
				{
					_pointer = _pointer->proximo;	// Avança o ponteiro para o fim da lista
					pop_back();
					//_pointer = NULL;
				}
				else if(_pointer->anterior == NULL and _pointer->proximo != NULL)
				// H-> [val][n_1]...[n_k] <-T Se só existe nó depois deste e não antes dele)
				{	
					//_pointer é igual a head
					_pointer = _pointer->proximo;	// Avança o ponteiro para o fim da lista
					pop_front();	// Destroi o elemento (supostamente no início da lista)

				}
				else if(_pointer->anterior != NULL and _pointer->proximo != NULL)
				// H-> [n_0]...[n_z][val][n_z+2]...[n_k] <-T (Se existe nó antes e depois deste)
				{
					// Inicialmente: [x]-[val]-[y],	onde "-" indica que estão conectados em ambos sentidos (anterior e proximo)
					
					_pointer->anterior->proximo = _pointer->proximo;	// Pega o nó anterior ao selecionado e o conecta com o próximo do atual
					// [x]->[z]  [x]<-[val]-[z]
					
					_pointer->proximo->anterior = _pointer->anterior;	// Pega o nó depois do selecionado e o conecta com o anterior do selecionado
					// [x]-[z] [x]<-[val]->[z]
					
					_destruir = _pointer;	// Atribui ao ponteiro destrutor qual o nó a ser destruído
					// _destruir -> [val]
					
					_pointer = _pointer->proximo; //	Avança o ponteiro em direção ao fim da lista
					// _pointer -> [val]
					
					delete _destruir; // Destrói o nó [val]

					qtd_elementos--; // Diminui o contador de elementos da lista
				}
			}
			else // Se não achar elemento
			{
				_pointer = _pointer->proximo;	// Avança o ponteiro;
			}
		}
	}

	/**
	* @brief Verifica se um elemento já existe na lista
	* @param elem Valor buscado para ser removido
	*/
	template < typename T>
	bool myLista<T>::exist(const T& elem)
	{
		myNode * _pointer = sentinela_head;	// Cria ponteiro para o início da lista, a partir da sentinela da cabeça

		while(_pointer != NULL)	// Percorre toda a lista
		{
			if(_pointer->elemento == elem) return true;	// Se encontrar o valor, retorna true
			_pointer = _pointer->proximo;	// Avança para o próximo nó em direção a cauda da lista
		}

		return false;	// Se não encontrar o valor, retorna falso
	}

	/**
	* @brief Tira da lista seus elementos repetidos
	* @param elem Valor buscado para ser removido
	*/
	template < typename T>
	void myLista<T>::unique()
	{
		myNode *slow = sentinela_head;	// Cria ponteiro para o início da lista
		myNode *fast ;	// Ponteiro que buscará pelos elementos apontados por 'slow'
		myNode *_destruir;	// Ponteiro que aponta para o nó a ser destruído

		while(slow != NULL)	// Percorre toda a lista
		{
			fast = slow->proximo;	// Aponta o 'fast' para o nó após 'slow';
			
			while( fast != NULL)	// Percorre toda a lista de pois de 'slow'
			{
				if(slow->elemento == fast->elemento)	// Se os nós apontados por fast e slow tiverem o mesmo elemento
				{				
					// Verificando posição do nó apontado por 'fast'
					if(fast->anterior != NULL and fast->proximo == NULL)	// Já percorreu toda a lista
					// H-> [n_0]...[n_k-1][nó] <-T (Se só existe nó antes a deste e não depois)
					{
						fast = fast->proximo;	// *Avança o ponteiro em direção ao fim da lista
						pop_back();
						//fast = NULL;
					}
					else if(fast->anterior != NULL and fast->proximo != NULL)
					// H-> [n_0]...[n_z][nó][n_z+2]...[n_k] <-T (Se existe nó antes e depois deste)
					{
						// Inicialmente: [x]-[nó]-[y],	onde "-" indica que estão conectados em ambos sentidos (anterior e proximo)
						
						fast->anterior->proximo = fast->proximo;	// Pega o nó anterior ao selecionado e o conecta com o próximo do atual
						// [x]->[z]  [x]<-[nó]-[z]
						
						fast->proximo->anterior = fast->anterior;	// Pega o nó depois do selecionado e o conecta com o anterior do selecionado
						// [x]-[z] [x]<-[nó]->[z]
						
						_destruir = fast;	// Atribui ao ponteiro destrutor qual o nó a ser destruído
						// _destruir -> [nó]
						
						fast = fast->proximo; //	*Avança o ponteiro em direção ao fim da lista
						// fast -> [nó]
						
						delete _destruir; // Destrói o nó [nó]

						qtd_elementos--; // Diminui o contador de elementos da lista
					}
				}
				else
				{
					fast = fast->proximo; //	*Avança o ponteiro em direção ao fim da lista
				}
			}
			slow = slow->proximo;	// Avança slow;
		}

		// *Tem que avançar o fast antes de destruir o nó para onde ele ta apontado

	}
}

#endif