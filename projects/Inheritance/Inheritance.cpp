#include <iostream>
using namespace std;
class a;
class b;
class c;
class d;


class a
{
public:
    a()
    {
        cout << "Hello, Good Mornig\n";
    }
};

class b : public a
{
public:
    b()
    {
        cout << "It's pratham\n\n";
    }
};

class c : public a
{
public:
    c()
    {
        cout << "Today is day 3 of 100 days of code";
    }
};

class d : public b, public c
{
public:
    d()
    {
        cout << " and i am writing program for hibrid inheretance using constructor";
    }
};
int main()
{
    d done;
    return 0;
}