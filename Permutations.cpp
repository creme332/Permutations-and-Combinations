#include <set>
#include <iostream>
#include <map>
 
//	Given n elements (duplicates allowed), find all possible arrangements.

std::set <std::string> all; 

void perm(std::string current, std::multimap <char, bool> ChooseFrom) {
	if (current.length() == ChooseFrom.size()) {
		all.insert(current);
		return;
	}

	for (auto &i: ChooseFrom) { 
		if (i.second == 1) {
			i.second = 0; 
			perm(current + i.first, ChooseFrom);
			i.second = 1; //reset to initial state
		}
	}
}



int main() {
	std::multimap <char, bool> ChooseFrom; //n elements to be arranged

	std::string m;
	std::cout << "Enter string : ";
	std::cin >> m;
	for (auto c : m) {ChooseFrom.insert({c,1});}

	perm("", ChooseFrom);

	//output
	int count = 0;
	for (auto i : all) { count++;std::cout << i << "\n"; }
	std::cout << "Number of arrangements : "<< count << "\n";
	system("pause");
}
