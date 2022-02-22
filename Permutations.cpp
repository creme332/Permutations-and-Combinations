#include <set>
#include <iostream>
#include <map>
 #include <iostream>
#include <string>

std::set<std::string> all; //store all permutations of operators
std::set<char> ChooseFrom = {'a','b','c'}; //used for perm2() only


//	Given n elements (duplicates allowed), find all possible arrangements.
void perm1(std::string current, std::multimap <char, bool> Letters) {
	if (current.length() == Letters.size()) {all.insert(current); return;}

	for (auto &i: Letters) { 
		if (i.second == 1) { //if i.first has not been used yet
			i.second = 0; 
			perm1(current + i.first, Letters);
			i.second = 1; //reset to initial state
		}
	}
}

//Given n unique elements, choose r elements (duplicates allowed), and arrange.

void perm2(int r, std::string current) {
	if (r == 0){all.insert(current); return;}
		
	for (auto j: ChooseFrom) {perm2(r - 1, current + j);}
}

int main() {
	std::multimap <char, bool> Letters; //n elements to be arranged

	//for perm1()
	//std::string m;
	//std::cout << "Enter string : ";
	//std::cin >> m;
	//for (auto c : m) {Letters.insert({c,1});}
	//perm1("", Letters);

	//for perm2()
	perm2(2,"");

	//output
	int count = 0;
	for (auto i : all) { count++;std::cout << i << "\n"; }
	std::cout << "Number of arrangements : "<< count << "\n";
	system("pause");
}
