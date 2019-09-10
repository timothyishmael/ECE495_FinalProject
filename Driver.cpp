#include<iostream>
#include<string>
#include<stdexcept>
#include<limits>
#include<ios>
#include"Calculator.h"
#define MAX 1000

// COMMENT Good job!
// ANSWER Thanks. I believe I have the rest of the features implemented,
// and I rewrote my Binary and Unary files so they do not need to have
// the postorder visitor as a friend to function. This did require me to
// implement an additional function call to access the other Binary child,
// causing two functions in Unary that have the same implementation.
// Although it's probably a code smell, it was the best way I could think of,
// and I figured a code smell is better than a security risk.

int main(){
	Expr_Builder * builder_ = new Expr_Tree_Builder();
	std::string infix;
	Calculator director(builder_);
	int answer;
	while(true){
		std::cout<<"Please input an equation string, or type \"QUIT\" to exit.\n";
		getline(std::cin, infix);
		if(infix == "QUIT")
			break;
		else{
			try{
				int answer = director.evaluate(infix);
				std::cout << "The answer is " << answer << ".\n\n";
			}
			catch(const std::invalid_argument& e){
				std::cerr << "Invalid argument: " << e.what() << std::endl;
				continue;
			}
			catch(std::exception& e){
				std::cerr << e.what() << std::endl;
				continue;
			}
		}
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//	std::cin.clear();
	//	std::cin.ignore(MAX);
	}
	return 0;
}

