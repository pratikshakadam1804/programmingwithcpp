#include<iostream>
using namespace std;
  
class vehicle {
public:
    virtual void print()    {
        cout << "print vehicle class\n";
    }   
};
class fourwheeler : public vehicle {
public:
    void print()  {
        cout << "print fourwheeler class\n";
    }
};
 int main(){
    vehicle *ptr1,*ptr2;
    ptr1 = new vehicle;
    ptr2 = new fourwheeler;
     // Virtual function, binded at runtime
    ptr1->print();
     // Non-virtual function, binded at compile time
    ptr2->print();
     return 0;
}