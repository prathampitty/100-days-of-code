#include<iostream>
using namespace std;

template<class t, class u>
class a{
    t p ;
    u q ;
    public :
    a(t z) { cout<<z;
    cout<<"\nconstructor called"<<endl;}
};

int main() {
    a<char, char >('g');
    a<int, float>(565);
    return 0;
}