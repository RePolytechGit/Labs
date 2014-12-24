#include "header.h"


matharray::matharray()
{
	arr.resize(0);
}

matharray::matharray(const matharray& copy){
	arr.resize(copy.arr.size());
	for (int i = 0; i < arr.size(); i++)
		arr[i] = copy.arr[i];
}

matharray& matharray::operator=(const matharray& copy){
	if (&copy == this)
		return *this;
	else
	{
		arr.resize(copy.arr.size());
		for (int i = 0; i < arr.size(); i++)
			arr[i] = copy.arr[i];
	}
	return *this;
}

istream&  operator >> (std::istream& input, matharray& uzi){
	int i;
	while (input >> i)
	{
		uzi.addelement(i);
	}
	return input;
}

ostream& operator<<(ostream& out, matharray& uzi){
	for (int i = 0; i < uzi.arr.size(); i++)
		out << uzi.arr[i] << " ";

	return out;
}

matharray& matharray::operator+(const matharray& copy)const{
	matharray supp;
	supp = copy;
	for (int i = 0; i < arr.size(); i++)
		supp.addelement(arr[i]);
	return supp;
}

matharray& matharray::operator*(matharray& copy)const{
	matharray supp;
	for (int i = 0; i < arr.size(); i++)
	if (copy.prinadlej(arr[i]))
		supp.arr.push_back(arr[i]);
	return supp;
}

int find(const vector<int>& mass, int a){
	for (int i = 0; i < mass.size(); i++)
	if (mass[i] == a)
		return i;
	return -1;
}

void matharray::addelement(int el){

	if (find(arr, el) == -1)
		arr.push_back(el);

}

void matharray::delelement(int el){
	int a = find(arr, el);
	if (a != -1)
		arr.erase(arr.begin() + a, arr.begin() + a + 1);
}

bool matharray::prinadlej(int el){
	if (find(arr, el) != -1)
		return true;
	else
		return false;
}

matharray::~matharray()
{
	arr.clear();
}
