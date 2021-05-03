#include <iostream>
#include <vector>
//#include "linkedlist.h" eliminado Linked-MaizoDiego
#include "type.h"
#include "myof.h"
using namespace std;

template <typename Iterator>
void recorrer1(Iterator begin, Iterator end, ostream &os)
{
	while (begin != end) 
  {
		os << *begin << endl;
		++begin;
	}
}

template <typename Iterator, typename OF>
void recorrer2(Iterator begin, Iterator end, OF &of)
{
	while (begin != end)
		of(*begin);
}

template <typename Iterator, typename OF, typename Extra>
void recorrer3(Iterator begin, Iterator end, OF &of, Extra &extra_param)
{
	while (begin != end)
		of(*begin, extra_param);
}

template <typename Container, typename Function>
void recorrer4(Container &container, Function &function)
{
  auto begin = container.begin();
	while (begin != container.end())
		function(*begin); //eliminado extra_param_MaizoDiego
}

template <typename Container>
void print(Container &container, ostream &os)
{
	auto begin = container.begin();
	while (begin != container.end())
		os << *begin << endl;
}

template <typename T> //creando template - Kevin De Lama
void incrementar(T &val) //int cambiado por T1 - Kevin De Lama
{
	val++;
}


int main()
{
	// cambio de int por T1 - Diego Panta
	vector<T1> vx;

  	// cambio de int por T1 - Diego Panta
	for (T1 i = 0; i < 10; i++)
		vx.push_back(i * i);

	// cambio de int por T1 - Diego Panta
	vector<T1>::iterator iter1 = vx.begin();
	for (; iter1 != vx.end(); iter1++)
		cout << *iter1 << endl;

	auto iter2 = vx.begin();
	for (; iter2 != vx.end(); iter2++)
		cout << *iter2 << endl;

	for (T1 &v : vx) //int cambiado a T1 - Kevin De Lama
		cout << v++ << endl;

	recorrer1(vx.begin(), vx.end(), cout);
  cout << "Check #1\n";
	recorrer1(vx.begin() + 2, vx.end() - 1, cout);
  cout << "Check #2\n";

	MyOF<T1> myof;
	recorrer2(vx.begin(), vx.end(), incrementar);
  cout << "Check #3\n";
	recorrer2(vx.begin(), vx.end(), myof);
  cout << "Check #4\n";

  // Aqui agregar una funcion lambda
  auto x=[](int &v){ cout << v <<endl; };//se volvio una variable a la lambda_MaizoDiego
  recorrer2(vx.begin(), vx.end(),x ); 
  cout << "Check #5\n";
  auto y=[](int &v){ v+= 5; };//se volvio una variable a la lambda_MaizoDiego
  recorrer2(vx.begin(), vx.end(), y); 
  cout << "Check #6\n";

  recorrer3(vx.begin(), vx.end(), myof, cout);
  cout << "Check #50\n";

  recorrer4(vx, incrementar);
  cout << "Check #60\n";
  auto z=[](int &v){ cout << v <<"\n"; };
  recorrer4(vx, z);
  cout << "Check #70\n";
	// Añadir return 0 - buena practica Diego Panta
	return 0;
}
