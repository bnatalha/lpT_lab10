/**
* @file
* @brief Definição do namespace edb1
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 15/06/2017
* @date 20/06/17
*/

#ifndef NATALIA_H
#define NATALIA_H

#include "header.h"

/**
* @namespace edb1
* @brief Contem definições feitas pelo usuári de algoritmos de ordenação de TAD's estudados na disciplina de Estrutura de Dados.
*/
namespace edb1 
{
	// Algoritmos

	void mySwap( int &a, int &b);

	bool maiorque(int a, int b);
	bool menorque(int a, int b);

	void myBubbleSort (int *v, int ini, int fim);	// crescente
	
	void myInsertSort (int *v, int ini, int fim);	// crescente

	void mySelectionSort (int *v, int ini, int fim);	//
	
	int myQuickSortPartition(int *v, int ini, int fim);
	void myQuickSort (int *v, int ini, int fim);
	
	void mySplitSort (int *v, int ini, int fim);
	void myMergeSort (int *dir, int d_size, int *esq, int e_size, int *v, int fim);

	// TAD's

	/**
	* @class myPilha
	* @brief classe criada para simular a classe std::stack da STL do C++
	* @tparam T Tipo dos elementos da pilha
	*/
	template < typename T >
	class myPilha 
	{
		private:

			static const int capacidade = 2;	/**< Capacidade padrão de todas as pilhas */
			int tamanho;	/**< Quantitade de elementos na pilha */
			T *pilha = NULL;	/**< Arranjo que será alocado dinamicamente para guardar os elementos da pilha */

		public:

			/**
			* @brief Constroi um objeto myPilha sem passar atributos.
			*/
			myPilha()
				: tamanho(0), pilha(new T[capacidade])
			{} // EXTRA!: tratamento de exceção na alocação dinâmica ()

			/**
			* @brief Constroi um objeto myPilha  partir de uma pilha já definida pelo usuário
			* @param my_stack myPilha já existente que será sada pra construir a atual
			*/
			myPilha(const myPilha &my_stack)
				: tamanho(my_stack.tamanho), pilha(new T[capacidade])
			{
				for (int i = 0; i < capacidade; ++i)
				{
					this->pilha[i] = my_stack.pilha[i];	// Copia elementos da pilha passada por argumento para a pilha a ser criada
				}
				
			}

			/**
			* @brief Desaloca 'pilha' após chamar o destrutor de seus respectivos elementos
			*/
			~myPilha()
			{
				delete[] pilha;
			}

			// Metodos

			bool empty();	/**< Verifica se a pilha está vazia */
			int& size();	/**< Retorna uma referência para o tamanho da pilha */
			T& top();	/**< Retorna uma referência para elemento no topo da pilha */
			void push(const T& element);	/**< Acrescenta um elemento no topo da pilha, aumentando o tamanho da pilha */
			void pop();	/**< Remove o elemento do topo da pilha, diminuindo o tamanho da pilha */
	};

	/**
	* @class myLista
	* @brief Classe criada para simular a classe std::list da STL do C++, só que já ordenada 
	* (neste exemplo, na ordem decrescente)
	* @tparam T Tipo dos elementos da lista
	*/
	template < typename T >
	class myLista
	{
		private:

			/**
			* @struct myNode
			* @brief Estrutura que define um nó dá lista
			*/
			struct myNode
			{
				T elemento;	/**< Elemento que o nó guarda */
				myNode* anterior; /**< Ponteiro para o nó anterior (no sentido do início) da lista */
				myNode* proximo; /**< Ponteiro para o próximo nó (no sentido do fim) da lista */

				/**
				* @brief Construtor de myNode
				*/
				myNode(const T& data, myNode* prevNode = NULL, myNode* nextNode = NULL)
					:	elemento(data), anterior(prevNode), proximo(nextNode)
				{}

				/**
				* @brief Construtor de myNode
				*/
				myNode(T& data, myNode* prevNode = NULL, myNode* nextNode = NULL)
					:	elemento(data), anterior(prevNode), proximo(nextNode)
				{}
			};

			myNode *sentinela_head;	/**< Ponteiro para o nó do início (head) da lista */
			myNode *sentinela_tail;	/**< Ponteiro para o nó do fim (tail) da lista */
			int qtd_elementos;	/**< A quantidade de elementos armazenados na lista */

		public:

			/**
			* @class const_iterator
			* @brief iterator constante de myLista
			* @sa const no fim da assinatura (https://stackoverflow.com/questions/1549869/)
			*/
			class const_iterator
			{
				public:
					// Construtor
					const_iterator();

					// Acesso
					const T& operator*() const;

					// Movimentação
					const_iterator& operator++ ();	// pré-incrementação
					const_iterator operator++ (int);	// pós-incrementação
					const_iterator& operator-- ();	// pré-decrementação
					const_iterator operator-- (int);	// pós-decrementação

					// Comparação
					bool operator==( const const_iterator & it_direita ) const;
					bool operator!=( const const_iterator & it_direita ) const;

				protected:
					// Construtor
					const_iterator( myNode *ponteiro )
						: atual (ponteiro)
					{} 

					// Atributos
					myNode * atual;	/**< Ponteiro para um nó */

					// Permissão
					friend class myLista<T>;
			};

			/**
			* @class iterator
			* @brief iterator "modificável" de myLista
			* @sa const no fim da assinatura (https://stackoverflow.com/questions/1549869/)
			*/
			class iterator : public const_iterator
			{
				public:
					// Construtor
					iterator()
						: const_iterator()
					{}

					// Acesso ao conteudo do iterator
					const T& operator*() const;
					T& operator*();

					// Movimentação
					iterator& operator++ ();	// pré-incrementação
					iterator operator++ (int);	// pós-incrementação
					iterator& operator-- ();	// pré-decrementação
					iterator operator-- (int);	// pós-decrementação
						
					// Atribuição
					iterator & operator= ( const iterator& it_direita );

				protected:
					// Construtor
					iterator ( myNode *ponteiro)
						: const_iterator(ponteiro)
					{}

					// Permissão
					friend class myLista<T>;	
			};

			// Construtor
			myLista();
			myLista( const myLista & copy );
			// range
			myLista(const int& n, const T& val);	// Invalidado pela nova implementação dos metodos push (só entra algum elemento na lista caso ele ainda não exista nela)
			
			// Destrutor
			~myLista();

			// Iterator
			const_iterator begin() const;
			iterator begin();
			const_iterator end() const;
			iterator end();

			// Acesso a elementos
			T& front();
			T& back();
			
			// Capacidade
			int size();
			bool empty();

			// Modificadores
			//void push_sorted(const T& elem );
			void push_sorted( T elem );
			void push_back( const T& elem );	// bool se tiver como checar se pode ser alocado ou não
			bool pop_back();
			void push_front( const T& elem );
			bool pop_front();
			void clear();
			void erase( iterator &it );
			//insert()	iterator

			// Operações
			void remove(const T& val);
			void unique();
			// > Auxiliares dos modificadores
			bool exist(const T& elem);
			//sort();

			// Sobrecarga de operadores
			bool operator== ( myLista<T> l_direita);
			bool operator!= ( myLista<T> l_direita);
			myLista<T>& operator= (const myLista<T> copy);
			// PARA TESTE: sobrecarga operador <<
			//template <typename foo>
			//friend std::ostream& operator<< (std::ostream& out, const myLista<foo> copy);
	};

	/**
	* @class myFila
	* @brief Uma fila que usa um array circular alocado dinâmicamente
	* @tparam T Tipo dos elementos da fila
	*/
	template < typename T >
	class myFila 
	{
		private:

			static const int capacidade = 3;	/**< Capacidade padrão de todas as filas */
			//int tamanho;	/**< Quantitade de elementos na fila */
			int ini;	/**< Índice do elemento na frente da fila */
			int fim;	/**< Índice do elemento no fim da fila */
			T *fila = NULL;	/**< Arranjo que será alocado dinamicamente para guardar os elementos da fila */

		public:

			/**
			* @brief Constroi um objeto myFila sem passar atributos.
			*/
			myFila()
				: ini(-1), fim(-1), fila(new T[capacidade])
			{}

			/**
			* @brief Constroi um objeto myFila  partir de uma fila já definida pelo usuário
			* @param my_queue myFila já existente que será sada pra construir a atual
			*/
			myFila(const myFila &my_queue)
				: ini(my_queue.ini), fim(my_queue.fim), fila(new T[capacidade])
			{
				for (int i = 0; i < capacidade; ++i)
				{
					this->fila[i] = my_queue.fila[i];	// Copia elementos da fila passada por argumento para a fila a ser criada
				}
				
			}

			/**
			* @brief Desaloca 'fila' após chamar o destrutor de seus respectivos elementos
			*/
			~myFila()
			{
				delete[] fila;
			}

			// Metodos

			bool empty();	/**< Verifica se a fila está vazia */
			int size();	/**< Retorna uma referência para o tamanho da fila */
			T& front();	/**< Retorna uma referência para elemento na frente da fila */
			T& back();	/**< Retorna uma referência para elemento no fim da fila */
			void push(const T& element);	/**< Acrescenta um elemento na frente da fila, aumentando o tamanho da fila */
			void pop();	/**< Remove o elemento na frente da fila, diminuindo o tamanho da fila */
	};

	/**
	* @class myDeque
	* @brief Um deque que usa um array circular alocado dinâmicamente (sem iterator)
	* @tparam T Tipo dos elementos da lista
	*/
	template < typename T >
	class myDeque
	{
		private:
			int capacidade;	/**< Capacidade máxima do deque */
			int ini;	/**< Índice para o inicio do deque */
			int fim;	/**< Índice para o fim do deque */
			T* recipiente;	/**< Onde os elementos do deque serão guardados*/

			void my_reallocator();

		public:
			// Construtor
			myDeque();
			myDeque( myDeque & orig );
			// Destrutor
			~myDeque();
			// Acesso a elementos
			T& operator[] (int n);
			T& at (int n);
			T& front();
			T& back();
			// Capacidade
			int size();
			bool empty();
			// Modificadores
			void push_back( const T& elem );
			void pop_back();
			void push_front( const T& elem );
			void pop_front();
			void clear();
			// Sobrecarga de operadores
			bool operator== ( myDeque<T>& d_direita);
			myDeque<T>& operator= ( myDeque<T>& copy);
			// PARA TESTE: sobrecarga operador <<
			//template <typename foo>
			//friend std::ostream& operator<< (std::ostream& out, const myDeque<foo> copy);
	};

}

#include "myPilha.h"
#include "myLista.h"
#include "myFila.h"
#include "myDeque.h"

#endif