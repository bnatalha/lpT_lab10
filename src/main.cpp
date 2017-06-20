/**
* @file
* @brief Onde fica a função principal.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 13/06/2017
* @date 20/06/17
*/

#include "header.h"
#include "natalia.h"
#include "testar_ordenacao.h"
#include "testar_lista.h"
#include "testar_fila.h"
#include "testar_pilha.h"
#include "testar_deque.h"

bool proceder(const char* testname)
{
	char answer = 'x';
	cout << "Proceder com teste de "<< testname <<"? ";
	do
	{
		if( answer != 'y' and answer != 'n' ) cout << "Digite 'y' para sim e 'n' para não. >>";
		cin >> answer;
	}while (answer != 'y' and answer != 'n' );
	
	if(answer == 'y') return true;
	else return false;
}

/**
* @brief Realiza testes com os objetos/algoritmos do namespace edb1
*/
int main(int argc, char const *argv[])
{
	
	cout << "Iniciando testes da biblioteca..." << endl;
	
	cout << "Testando TADS:" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	if( proceder("myLista") )
	{
		cout << "================ myLista =================" << endl;
		testar_lista();
		cout << "=======================================fim" << endl;
	}
	if( proceder("myPilha") )
	{
		cout << "================ myPilha =================" << endl;
		testar_pilha();
		cout << "=======================================fim" << endl;
	}
	if( proceder("myFila") )
	{
		cout << "================ myFila ==================" << endl;
		testar_fila();
		cout << "=======================================fim" << endl;
	}
	if( proceder("myDeque") )
	{
		cout << "================ myDeque =================" << endl;
		testar_deque();
		cout << "=======================================fim" << endl;
	}
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------FIM-------------------------------------" << endl << endl;

	if( proceder("algoritmos de ordenação") )
	{
		cout << "Testando algoritmos de ordenação:" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		testar_ordenacao();
	}
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------FIM-------------------------------------" << endl << endl;
	
	cout << "Saindo do programa de testes..." << endl;
	return 0;
}