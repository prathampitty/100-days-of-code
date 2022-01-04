#include<iostream>
#include<fstream>

using namespace std;

int main(){
string st1 ="Hello my name is pratham";
string st2;
ofstream out("sample60.txt"); 
out << "Good morning \n" + st1;
out.close();

ifstream in ("sample60.txt");
// in >>st2;
getline(in, st2);
cout << st1<<endl;
cout << st2<<endl;

getline(in, st2);
cout << st2 << endl;

return 0;
}