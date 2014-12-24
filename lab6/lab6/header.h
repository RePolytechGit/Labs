#pragma once
#include<vector>
#include<iostream>
#include <fstream>
using namespace std;

class matharray
{
public:
	matharray();

	matharray(const matharray& copy);

	matharray& operator=(const matharray& copy);

	friend istream&  operator >> (std::istream& input, matharray& uzi);

	friend ostream& operator<<(ostream& out, matharray& uzi);

	matharray& operator+(const matharray& copy)const;

	matharray& operator*(matharray& copy)const;

	void addelement(int el);

	void delelement(int el);

	bool prinadlej(int el);

	~matharray();

private:
	vector<int> arr;
};


