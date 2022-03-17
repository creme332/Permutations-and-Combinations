#include <set>
#include <iostream>
#include <map>
 #include <iostream>
#include <string>

std::set<std::string> all; //store all permutations of operators
std::set<char> ChooseFrom; //used for perm2() only


//	Given n elements (duplicates allowed), find all possible arrangements.
void PermutationWithoutRepetition(std::string current, int k, std::multimap <char, bool> Letters) {
	if (current.length() == k) {all.insert(current); return;}

	for (auto &i: Letters) { 
		if (i.second == 1) { //if i.first has not been used yet
			i.second = 0; 
			PermutationWithoutRepetition(current + i.first, k, Letters);
			i.second = 1; //reset to initial state
		}
	}
}

//Given n unique elements, choose r elements with repetition and arrange.

void PermutationWithRepetition(int k, std::string current) {
	if (k == 0){all.insert(current); return;}
	for (auto j: ChooseFrom) {PermutationWithRepetition(k - 1, current + j);}
}

int main() {
	std::multimap <char, bool> Letters; //n elements to be arranged
	std::string input;
	int k;
	int option=1;
	std::cout<<"Enter string  : ";
	std::cin>>input;
	std::cout<<"Enter value of k : ";
	std::cin>>k;
	std::cout<<"Choose an option for permutations :\n";
	std::cout<<"(1) Without repetition (a given element cannot be used more than once)\n";
	std::cout<<"(2) With repetition (a given element can be used multiple times)\n";
	std::cin>>option;
	if(option==1){
		for (auto c : input) {Letters.insert({c,1});}
		PermutationWithoutRepetition("", k, Letters);
	}else{
		for (auto c : input) {ChooseFrom.insert(c);}
		PermutationWithRepetition(k,"");
	}
	//output
	int count = 0;
	std:: string output ="{";
	for (auto i : all) { count++; output += i+", "; }
	output=output.substr(0,output.length()-2);
	output+="}";	
	std::cout<<output<<"\n";
	std::cout << "Number of arrangements : "<< count << "\n";
	system("pause");
}
