/**
* @file
* @brief Implementação de myDeque do namespace edb1
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 18/06/2017
* @date 20/06/17
* @sa std::deque (http://www.cplusplus.com/reference/deque/deque/)
* @sa https://stackoverflow.com/questions/6292332/what-really-is-a-deque-in-stl
* @sa http://en.cppreference.com/w/cpp/container/deque
* @sa https://www.codeproject.com/Articles/5425/An-In-Depth-Study-of-the-STL-Deque-Container
*/

#ifndef MYDEQUE_H
#define MYDEQUE_H

#include "natalia.h"

namespace edb1
{
	// Implementação do Dequeue

	/**
	* @brief Realoca o container do deque para o dobro de sua capacidade total
	*/
	template <typename T>
	void myDeque<T>::my_reallocator()
	{
		bool is_empty = empty();	// guarda se o deuque está vazio ou não

		T* new_recipiente;	// ponteiro para o novo recipiente;

		// tenta alocar o dobro da capacidade do deque atual
		try{
			new_recipiente = new T[capacidade*2];	// cria um novo recipiente com o dobro de capacidade
		}catch (std::bad_alloc& ba)		{
			cout << "bad_alloc caught: " << ba.what() << endl;
		}
		
		int new_fim = 0;
		for (int i = ini; new_fim < size(); new_fim++)	// atribui ao novo bloco de memoria informações do atual
		{
			new_recipiente[new_fim] = recipiente[i];
			//cout << recipiente[i] << " ";
			i = ((i+1) % capacidade);
		}

		// fixa indices 
		ini = ( is_empty? -1 : 0 );
		fim = ( is_empty? -1 : new_fim-1 );

		delete[] recipiente;	// Deleta bloco de memoria apontado por 'recipiente' (antigo)
		recipiente = new_recipiente;	// aponta 'recipiente' para o bloco de memoria criado
		capacidade = capacidade*2;	// dobra 'capacidade'
	}

	// =================================================================================================
	// =========================================== Construtores ========================================
	// =================================================================================================

	/**
	* @brief Constrói um objeto myDeque vazio
	*/
	template <typename T>
	myDeque<T>::myDeque()	: capacidade(20), ini(-1), fim(-1)
	{
		// tenta alocar o Deque.
		try{
			recipiente = new T[capacidade];
		}catch (std::bad_alloc& ba)		{
			cout << "bad_alloc caught: " << ba.what() << endl;
		}

	}

	/**
	* @brief Constrói um objeto myDeque a partir de outro já existente (cópia)
	* @param objeto myDeque que será usado como referência para ser copiado
	*/
	template <typename T>
	myDeque<T>::myDeque( myDeque & orig )	: capacidade(orig.capacidade)
	//myDeque<T>::myDeque( myDeque & orig )	: capacidade(orig.capacidade), ini(orig.ini), fim(orig.fim)
	{
		// tenta alocar o Deque com a capacidade do deque 'orig'.
		try{
			recipiente = new T[orig.capacidade];		
		}catch (std::bad_alloc& ba)		{
			cout << "bad_alloc caught: " << ba.what() << endl;
		}

		// copia os elementos de orig para este deque
		for(int i = 0; i < orig.size(); i++) recipiente[i] = orig.at(i);
		
		ini = (orig.empty()? -1 : 0);
		fim = (orig.empty()? -1 : orig.size()-1);
	}

	// =========================================== Destrutor ========================================
	
	/**
	* @brief Destrói um objeto myDeque, destruindo sua 'recipiente'
	*/
	template <typename T>
	myDeque<T>::~myDeque()
	{
		delete[] recipiente;
	}

	// =================================================================================================
	// =========================================== Acesso ==============================================
	// =================================================================================================

	/**
	* @return Referência para o elemento na posição 'n' do container 'recipiente'
	*/
	template <typename T>
	T& myDeque<T>::operator[] (int n)
	{
		if(empty())	// Se deque estiver vazio
			throw std::out_of_range ("[EXCEPTION] operator[]: Não há elementos no deque");

		return recipiente[ (ini + n )% capacidade ];
	}

	/**
	* @brief diferença desse pro [] é a esceção caso 'n' seja maior ou igual ao tamanho do deque
	* @return Referência para o elemento na posição 'n' no deque, se existir.
	*
	*/
	template <typename T>
	T& myDeque<T>::at(int n)
	{
		if(empty())	// Se deque estiver vazio
			throw std::out_of_range ("[EXCEPTION] operator[]: Não há elementos no deque");
		if(n >= size())	// Se a posição requisitada for maior do que o tamanho do deque
			throw std::out_of_range ("[EXCEPTION] operator[]: posição requisitada > tamanho do deque");

		return recipiente[ (ini + n )% capacidade ];
	}

	/**
	* @return Referência para o elemento no início da recipiente, se existir.
	*/
	template <typename T>
	T& myDeque<T>::front()
	{
		if(empty())	// Se deque estiver vazio, chamar exceção
			throw std::out_of_range ("[EXCEPTION] front(): Não há elementos no deque");

		return recipiente[ini];
	}

	/**
	* @return Referência para o elemento no fim da recipiente,  se existir.
	*/
	template <typename T >
	T& myDeque<T>::back()
	{
		if (empty())	// Se deque estiver vazio, chamar exceção
			throw std::out_of_range ("[EXCEPTION] back(): Não há elementos na recipiente");
		
		return recipiente[fim];
	}

	// =================================================================================================
	// ======================================== Capacidade =============================================
	// =================================================================================================


	/**
	* @retval true A deque está vazio
	* @retval false A deque \b não está vazio
	*/
	template <typename T >
	bool myDeque<T>::empty()
	{
		return (size() == 0);
	}

	/**
	* @return Referência para o tamanho da deque
	*/
	template <typename T >
	int myDeque<T>::size()
	{		
		if (ini == -1) return 0;
		else if(ini == fim ) return 1;
		else if(ini < fim) return ((fim-ini)+1);
		//else if (ini > fim)
		return ( (fim + (capacidade - ini) )+ 1);
	}

	// =================================================================================================
	// ======================================= Modificadores ===========================================
	// =================================================================================================

	/**
	* @brief Acrescenta um elemento no final do Deque
	* @param element Elemento do tipo T a ser acrescentado ao deque
	*/
	template <typename T>
	void myDeque<T>::push_back( const T& elem )
	{	
		if(size() == capacidade)	
			my_reallocator();	// Realocar o tamanho do container do Deque quando atingir a capacidade maxima inicial
		
		if (empty())	// se for o primeiro elemento a entrar na 'recipiente'
			ini++;	// coloca 'ini' para apontar

		fim = (fim+1)%capacidade;	// avança indice 'fim'
		recipiente[fim] = elem;	// Acrescenta elemento e depois aumenta o tamanho da 'recipiente'
	}
	/**
	* @brief Remove o elemento no fim do Deque
	*/
	template <typename T>
	void myDeque<T>::pop_back()
	{
		if (empty())
			throw std::length_error ("[EXCEPTION] pop_back(): Não pode remover elementos de um deque vazio");
		

		recipiente[fim].~T();	// destrói elemento do fim

		if (size() == 1)	// se só existir um elemento no 'recipiente' antes do pop()
		{
			ini = -1;	// fixa índices para fora da 'recipiente'
			fim = -1;
		}
		else
			fim = ((fim-1) < 0? (capacidade + (fim-1)) : (fim-1)) %capacidade;	// retrocede indice 'fim'
		
	}

	/**
	* @brief Acrescenta um elemento no início do Deque
	* @param element Elemento do tipo T a ser acrescentado ao deque
	*/
	template <typename T>
	void myDeque<T>::push_front( const T& elem )
	{	
		if(size() == capacidade)
			my_reallocator();	// Realocar o tamanho do container do Deque quando atingir a capacidade maxima inicial
			
		if (empty())	// se for o primeiro elemento a entrar na 'recipiente'
			fim++;	// coloca 'fim' para apontar

		ini = ((ini-1) < 0? (capacidade + (ini-1)) : (ini-1))  %capacidade;	// retrocede indice 'ini'
		
		recipiente[ini] = elem;	// Acrescenta elemento e depois aumenta o tamanho da 'recipiente'
	}

	/**
	* @brief Remove o elemento no início do Deque
	*/
	template <typename T>
	void myDeque<T>::pop_front()
	{
		if (empty())
			throw std::length_error ("[EXCEPTION] pop_front(): Não pode remover elementos de um deque vazio");
		

		recipiente[ini].~T();	// destrói elemento do ini

		if (size() == 1)	// se só existir um elemento no 'recipiente' antes do pop()
		{
			ini = -1;	// fixa índices para fora da 'recipiente'
			fim = -1;
		}
		else
			ini = (ini+1)%capacidade;	// avança indice 'ini'
		
	}

	/**
	* @brief Remove todos os elementos do Deque
	*/
	template <typename T>
	void myDeque<T>::clear()
	{
		while (empty() == false) pop_back();

	}


	// =================================================================================================
	// ================================== Sobrecarga de operadores =====================================
	// =================================================================================================

	/**
	* @brief Sobrecarga do operador '=='
	* @param orig Objeto myDeque que será comparado
	* @return 'true' se forem iguais, 'false' caso contrário
	*/
	template <typename T>
	bool myDeque<T>::operator== ( myDeque<T>& d_direita)
	{
		if(size() == d_direita.size())
		{
			// cria indices para comparação
			int i = ini, dir_i = d_direita.ini;

			// checa cada elemento das listas, se estão na mesma ordem.
			for(auto count = 0; count < size(); count++ )
			{
				if( recipiente[i] != d_direita.recipiente[dir_i] ) return false;	// achou elementos diferentes
				
				// incrementa indices
				i = (i+1)%capacidade;
				dir_i = (dir_i+1)%d_direita.capacidade;
			}
			return true;	// não achou nenhum elemento diferente
		}
		return false;	// tamanhos diferentes
	}

	/**
	* @brief Sobrecarga do operador '='
	* @param orig Objeto myDeque a ser copiado
	*/
	template <typename T>
	myDeque<T>& myDeque<T>::operator= (myDeque<T>& orig)
	{
		if( not(*this == orig) ) // Se os deques não forem iguais
		{
			clear();	// Se o Deque não estiver vazio, o torna vazio

			delete[] recipiente;	// Deleta bloco de memoria apontado por 'recipiente'

			// tenta alocar o Deque com a capacidade do deque 'orig'.
			try{
				recipiente = new T[orig.capacidade];		
			}catch (std::bad_alloc& ba)		{
				cout << "bad_alloc caught: " << ba.what() << endl;
			}

			// copia os elementos de orig para este deque
			for(int i = 0; i < orig.size(); i++) recipiente[i] = orig.at(i);
			
			ini = (orig.empty()? -1 : 0);
			fim = (orig.empty()? -1 : orig.size()-1);
		}

		return *this;
	}
}

#endif