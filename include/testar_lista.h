/**
* @file
* @brief Testes com myPilha.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 18/06/2017
* @date 20/06/17
*/

#ifndef TESTAR_LISTA_H
#define TESTAR_LISTA_H

#include "natalia.h"

/**
* @brief Realiza testes com objetoss da classe myPilha
*/
void testar_lista()
{

	edb1::myLista<int> aaa;
	edb1::myLista<int> bbb;
	edb1::myLista<int> ccc;
	edb1::myLista<int> ddd;

	// preenchendo listas
	for (int i = 0; i <= 10; ++i)
	{
		aaa.push_back(i);
		if(i != 0 )ddd.push_back(i);
		else ddd.push_back(34);
		if(i%2 == 0) bbb.push_back(i);
	}
	
	ccc = aaa;

	cout << "Criando eee de aaa...";
	edb1::myLista<int> eee(aaa);

	// imprimindo listas
	cout << "aaa: [ ";
	for (auto &e : aaa)
		cout << e << " ";
	cout << "]" << endl;
	cout << "bbb: [ ";
	for (auto &e : bbb)
		cout << e << " ";
	cout << "]" << endl;
	cout << "ccc: [ ";
	for (auto &e : ccc)
		cout << e << " ";
	cout << "]" << endl;
	cout << "ddd: [ ";
	for (auto &e : ddd)
		cout << e << " ";
	cout << "]" << endl;
	cout << "eee: [ ";
	for (auto &e : eee)
		cout << e << " ";
	cout << "]" << endl;

	// comparando listas
	cout << "aaa e bbb" << (aaa == bbb?" ":" não ") << "são iguais" << endl;
	cout << "aaa e ccc" << (aaa == ccc?" ":" não ") << "são iguais" << endl;
	cout << "aaa e ddd" << (aaa == ddd?" ":" não ") << "são iguais" << endl;	
	cout << "aaa e eee" << (aaa == eee?" ":" não ") << "são iguais" << endl;	
}


#endif