#ifndef __MYOF_H__//Agregado el ifndef MaizoDiego
#define __MYOF_H__//Agregado el define MaizoDiego

using namespace std; // Se agrego el using name MaizoDiego

//cerrar template Diego Panta
template <typename T>
class MyOF
{
public:
    void operator()(T &v)
    { v++;  }

    template <typename Extra>
    void operator()(T &v, Extra &os)
    { os << v++ << endl;  }
};

#endif //Agregado el endif MaizoDiego