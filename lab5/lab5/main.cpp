#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void print(string line, ofstream &fout)
{
	fout << line << endl;
}

string trim(string line)
{
	size_t strBegin_sp = line.find_first_not_of(' ');
	line.erase(0, strBegin_sp);
	size_t strBegin_tb = line.find_first_not_of('\t');
	line.erase(0, strBegin_tb);
	return line;
}

string tabulation(int &tab_counter)
{
	string spaces="";
	for (int i = 0; i < tab_counter; i++)
		spaces = spaces + "    ";
	return spaces;
}

void processing(string line, ofstream &fout, int check, ifstream &fin, int &tab_counter)
{
	if ((line == "\n") || (line == ""))
		return;
	string newline = "";
	line = trim(line);
	int i = 0;
	while (i<line.size())
	{
		
		if (line.at(i) == '{')
		{
		newline = line.substr(i + 1, line.
			size() - i);
		line = line.insert(i, " ");
		line.erase(i+2, line.size() - i);
		check++;
		line = tabulation(tab_counter) + line;
		i += (tab_counter * 4)+1;
		print(line, fout);
		tab_counter++;
		processing(newline, fout, 0, fin, tab_counter);
		}
		if (line.at(i) == '}')
		{
			check++;
			tab_counter--;
			line = tabulation(tab_counter) + line;
			i += tab_counter * 4;
			print(line, fout);
		}
		
		if (line.at(i) == ',')
		{
			check++;
			line = line.insert(i + 1, " ");	
			i += tab_counter * 4;
		}
		if (line.at(i) == ';')
		{
			check++;
			newline = line.substr(i + 1, line.size() - i);
			line.erase(i + 1, line.size() - i);
			line = tabulation(tab_counter) + line;
			print(line, fout);
			processing(newline, fout, 0, fin, tab_counter);
			i += tab_counter * 4;
		}
		if ((line.at(i) == '/') && (line.at(i+1) == '/'))
		{
			

			line = tabulation(tab_counter) + line;
			print(line, fout);
			i += tab_counter * 4;
			return;

		}
		if ((line.at(i) == '/') && (line.at(i + 1) == '*'))
		{
			check++;
			line = tabulation(tab_counter) + line;
			print(line, fout);
			while ((line.at(i) != '*') && (line.at(i + 1) != '\\'))
			{

				i++;
				if (i == line.size())
				{
					line = tabulation(tab_counter) + line;
					print(line, fout);
					getline(fin, line);
					i = 0;
				}
			}
			i += tab_counter * 4;

		}
		i++;
	}
	// Вывод строки, если изменения не понадобились.
	if (check == 0)
	{
		line = tabulation(tab_counter) + line;
		print(line, fout);
	}
}

void scan(ifstream &fin, ofstream &fout)
{
	int tab_counter = 0;
	int check=0;
	string line = "";
	while (!fin.eof())
	{
		getline(fin, line);
		processing(line, fout, check, fin, tab_counter);
	}
}





int main()
{
	string in;
	string out;
	string default_in = "in.cpp";
	setlocale(LC_ALL, "rus");
	cout << "Укажите расположение входного файла: ";
	getline(cin, in);
	cout << "Укажите расположение выходного файла: ";
	getline(cin, out);
	if (out == "")
		out = "out.cpp";
	ofstream fout(out);
	ifstream fin(in);
	if (fin.is_open())
	{
		scan(fin, fout);
		fin.close();
		
	}
	else
	{
		ifstream d_fin(default_in);
		scan(d_fin, fout);
		d_fin.close();
		
	}
	system("pause");
	return 0;
}