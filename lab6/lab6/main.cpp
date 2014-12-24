#include"header.h"

int main(void){
	matharray first;
	matharray second;
	ifstream fin("in.txt");
	fin >> first;
	ifstream fin1("in1.txt");
	fin1 >> second;
	cout << first << endl;
	cout << second;
	system("pause");
	
	return 0;
}