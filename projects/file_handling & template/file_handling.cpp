#include<iostream>
#include<fstream>

using namespace std;

int main() {
char name[50];

ofstream offile;
offile.open("pratham.txt");
cout<<"entere the value\n";
cin.getline(name, 50);
offile<<name;
offile.close();

ifstream iffile;
cout<<"Reading the data in the file";
iffile.open("pratham.txt");
iffile>>name;
cout<<name;
iffile.close();
return 0;
}   