#include<iostream>
using namespace std;
const float pi = 3.14;
// static float pi = 3.14;

class overloading{
    int x,y;
    public : float area(float r){
        // pi= 1;
        return pi *r *r;
    }
    float area(float  b ,float  h){
        return 0.5 *b*h;
    }
    void getdata(int X , int Y){
         x=X;
         y=Y;
    }
    void display(){
        cout<<endl<<x<<endl<<y<<endl;
    }
    void operator-()
    { // Unary Operators Overloading in C++
        x=-x;
        y=-y;
    }
};
int main() {
    overloading o1;
    float Area_of_Circle = o1.area(7);// area of circle before function overloading
    cout<<Area_of_Circle<<endl;
    float Area_of_Triangle = o1.area(2,4); // area of triange after the function overloading over area funciotn 
    cout<<Area_of_Triangle<<endl;
    o1.getdata(2,4); // taking the input for - sign operator
    o1.display(); // displays the data before operator overloading invoke 
    o1.operator-();//overloading the - operator 
    o1.display(); // displays the data after operator overloading 

return 0;
}