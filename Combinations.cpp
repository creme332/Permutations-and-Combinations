#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

std::set <std::string> all; //stores all possible combinations
//a set is used because it will get rid of duplicates
std::vector<char> ChooseFrom; //n elements from which r elements will be selected
//vector+sort is used instead of a set because a set does not allow n th element to be accessed by indexing.

void comb(int r, int i, std::string current) {
	/*
	Given n unique elements, choose r elements.
	The same element cannot be chosen more than once.
	Eg : Given {A,B,C} and r = 2,
	all = {AB, AC, BC}
	*/
	if (r == 0) {
		all.insert(current);
		return;
	}
	for (int j = i;j < ChooseFrom.size();j++) {
		comb(r - 1, j + 1, current + ChooseFrom[j]);
	}
}

void comb1(int r, int i, std::string current) { 
	/*
	Given n unique elements, choose r elements.
	The same element can be chosen more than once.
	Eg : Given {A,B,C} and r = 2, 
	all = {AA, AB, AC, BB, BC, CC}

	Can be used instead of stars and bars : 
	The number of solutions to the equation A + B + C = 5,
	where A, B, C are non-negative integers, is the number of elements in all.
	*/
	if (r == 0) {
		all.insert(current);
		return;
	}
	for (int j = i;j < ChooseFrom.size();j++) {
		comb1(r - 1, j, current + ChooseFrom[j]);
	}
}

void comb2(int r, int i, std::string current) {
	/*Given n elements, some of which are not unique, choose r elements.
	The same unique element cannot be chosen more than once.
	Eg : Given {A, A, B, C} and r = 2,
	all = AA, AB, AC, BA, BB, BC, CA,CB, CC 
	
	Eg : Given {A, A, B, C} and r = 3,
	all = AAB, AAC, ABC 
	
	*/
	if (r == 0) {
		all.insert(current);
		return;
	}
	for (int j = i;j < ChooseFrom.size();j++) {
		comb(r - 1, j + 1, current + ChooseFrom[j]);
	}
}

int main() {
	 int r; // number of elements to be selected
	std::string m = "";

	std::cout << "Enter string : ";
	std::cin >> m;
	std::cout << "Enter value of r : ";
	std::cin >> r;

	for (auto i : m) {ChooseFrom.push_back(i);}
	
	sort(ChooseFrom.begin(), ChooseFrom.end()); //ChooseFrom MUST be sorted for comb2 to work

	std::cout << "Choose number to :" << "\n";
	std::cout << "(1) : Input string has ONLY unique elements. Choose r elements WITHOUT repetition (each object CANNOT be selected more than once)" << "\n";
	std::cout << "(2) : Input string has ONLY unique elements. Choose r elements WITH repetition (each object can be selected more than once)" << "\n";
	std::cout << "(3) : Input string has duplicate elements. Choose r elements (each object CANNOT be selected more than once)"<< "\n";
	
	
	int ans;
	std::cin >> ans;
	switch (ans){
	case 1: comb(r, 0, "");break;
	case 2: comb1(r, 0, "");break;
	case 3: comb2(r, 0, "");break;
	}

	int count = 0;
	for (auto i : all) { count++;std::cout << i << "\n"; }
	std::cout << "Number of selections : "<< count << "\n";
}
