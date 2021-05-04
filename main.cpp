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


void incrementar(T1 &val) //int cambiado por T1 - Kevin De Lama
{
	val++;
}


int main()
{
	vector<T1> vx;

	for (T1 i = 0; i < 10; i++)
		vx.push_back(i * i); //0.0, 1.1, 2.2, 3.3
  cout<<"Iterador inicializado"<<endl;

	vector<T1>::iterator iter1 = vx.begin();
	for (; iter1 != vx.end(); iter1++)
		cout << *iter1 << endl;
  cout<<"Final del for 1 - iter 1"<<endl;

	auto iter2 = vx.begin();
	for (; iter2 != vx.end(); iter2++)
		cout << *iter2 << endl;
  cout<<"Final del for 2 - iter 2"<<endl;
  
  cout<<"---------"<<endl;
	for (T1 &v : vx) 
		cout << v++ << endl;
  cout<<"final del for 3 - T1 &v"<<endl;

	recorrer1(vx.begin(), vx.end(), cout);
  cout << "Check #1\n";
	recorrer1(vx.begin() + 2, vx.end() - 1, cout);
  cout << "Check #2\n";

	MyOF<T1> myof;
  cout<<"kevin"<<endl;

	
  recorrer2(vx.begin(), vx.end(), incrementar);
  cout << "Check #3\n";

	recorrer2(vx.begin(), vx.end(), myof);
  cout << "Check #4\n"; 

  auto x=[](int &v){ cout << v <<endl; };
  recorrer2(vx.begin(), vx.end(),x ); 
  cout << "Check #5\n";

  auto y=[](int &v){ v+= 5; };
  recorrer2(vx.begin(), vx.end(), y); 
  cout << "Check #6\n";

  recorrer3(vx.begin(), vx.end(), myof, cout);
  cout << "Check #50\n";

  recorrer4(vx, incrementar);
  cout << "Check #60\n";

  auto z=[](int &v){ cout << v <<"\n"; };
  recorrer4(vx, z);
  cout << "Check #70\n";

	return 0;
}
