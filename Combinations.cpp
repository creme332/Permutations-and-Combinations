#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

std::set <std::string> all; //stores all possible combinations
//a set is used because it will get rid of duplicates
std::vector<char> ChooseFrom; //n elements from which r elements will be selected
//vector+sort is used instead of a set because a set does not allow n th element to be accessed by indexing.

void CombinationNoRepetition(int r, int i, std::string current) {
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
		CombinationNoRepetition(r - 1, j + 1, current + ChooseFrom[j]);
	}
}

void CombinationRepetition(int r, int i, std::string current) { 
	//i : offset for ChooseFrom
	/*
	Given n unique elements, choose r elements.
	The same element can be chosen more than once.
	Eg : Given {A,B,C} and r = 2, 
	all = {AA, AB, AC, BB, BC, CC}
	*/
	if (r == 0) {
		all.insert(current);
		return;
	}
	for (int j = i;j < ChooseFrom.size();j++) {
		CombinationRepetition(r - 1, j, current + ChooseFrom[j]);
	}
}

void CombinationNoRepetition_RepeatedInput(int r, int i, std::string current) {
	/*Given n elements, some of which are not unique, choose r elements.
	The same unique element cannot be chosen more than once.	
	Eg : Given {A, A, B, C} and r = 3,
	all = AAB, AAC, ABC 
	
	*/
	if (r == 0) {
		all.insert(current);
		return;
	}
	for (int j = i;j < ChooseFrom.size();j++) {
		CombinationNoRepetition_RepeatedInput(r - 1, j + 1, current + ChooseFrom[j]);
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

	std::cout << "Choose an option :" << "\n";
	std::cout << "(1) : Input string has ONLY unique elements. Choose r elements WITHOUT repetition (each element CANNOT be selected more than once)" << "\n";
	std::cout << "(2) : Input string has ONLY unique elements. Choose r elements WITH repetition (each element can be selected more than once)" << "\n";
	std::cout << "(3) : Input string has duplicate elements. Choose r elements (each element CANNOT be selected more than once)"<< "\n";
	
	
	int ans;
	std::cin >> ans;
	switch (ans){
	case 1: CombinationNoRepetition(r, 0, "");break;
	case 2: CombinationRepetition(r, 0, "");break;
	case 3: CombinationNoRepetition_RepeatedInput(r, 0, "");break;
	}

	int count = 0;
	std:: string output ="{";
	for (auto i : all) { count++; output += i+", "; }
	output=output.substr(0,output.length()-2);
	output+="}";
	std::cout<<output<<"\n";
	std::cout << "Number of selections : "<< count << "\n\n";
}
