/*************************************************************************
	>    File Name: test.cpp
	>       Author: huangjinqiang
	>        Email: ligelaige@gmail.com
	> Created Time: Wed 12 Nov 2014 11:50:17 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

struct record{
	string name;
	int id;
};

const string filepath = "/etc/passwd";

auto split(const string &s, const char delim = ' ')
{
	stringstream ss(s);
	string item;
	vector<string> elems;

	while(getline(ss, item, delim) != NULL)
	{
		elems.push_back(item);
	}
	return  elems;
}

auto readfile(const string &file)
{
	ifstream infile(file);

	string line;
	vector<record> vars;

	while (getline(infile, line) != NULL)
	{
		auto var = split(line, ':');
		//cout << var[0] << " " << var[2] << endl;

		vars.push_back(record{var[0], stoi(var[2])});
	}

	return vars;
}

auto find_id(const vector<record> &people, const string &name)
{
	auto match_name = [&name](const record& r) -> bool {
		return r.name == name;
	};

	auto ii = find_if(people.begin(), people.end(), match_name);

	return ii == people.end() ? -1 : ii->id;
}

int main(void)
{
	vector<record> emplyee = {
			{"johnny", 1},
			{"mark", 2},
			{"bill", 3}
	};

	cout << find_id(emplyee, "bill") << endl;
	cout << find_id(emplyee, "john") << endl;

	decltype(emplyee) users = readfile(filepath);

	cout << "mysql uid = " << find_id(users, "mysql") << endl;
	cout << "johnny uid = " << find_id(users, "johnny") << endl;
	cout << "bill uid = " << find_id(users, "bill") << endl;
	cout << "john uid = " << find_id(users, "john") << endl;

	return 0;
}
