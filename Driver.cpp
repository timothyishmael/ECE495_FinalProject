#include<iostream>
#include<string>
#include<stdexcept>
#include<limits>
#include<ios>
#include"Calculator.h"
#define MAX 1000

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
	}
	return 0;
}

