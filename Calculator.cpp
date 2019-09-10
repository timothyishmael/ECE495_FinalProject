#include"Calculator.h"
#include<string>
#include<stdexcept>
#include<sstream>
#include<iostream>

Calculator::Calculator(void)
{}

Calculator::~Calculator(void)
{}

Calculator::Calculator(Expr_Builder * builder):
	builder_ (builder)
{}

int Calculator::evaluate(const std::string & infix)
{
	if(this->parse_expr(infix))
		throw std::runtime_error("Bad expression!");
	expr = this->builder_->get_expression();
	if(expr->root_ == 0)
		throw std::runtime_error("No expression!");
	return expr_eval();
}

bool Calculator::parse_expr(const std::string & infix)
{
	std::istringstream input(infix);
	std::string token;
	this->builder_->start_expression();

	while(std::getline(input, token, ' ')){
		token_ = token.c_str();
		if(token_[0] <= '9' && token_[0] >= '0')	
			this->builder_->build_number(token);
		else if(token == "(")
			this->builder_->paren_left_builder(input);
		else if(token == ")")
			this->builder_->paren_right_builder(input);
		else if(token == "+")
			this->builder_->build_add_operator();
		else if(token == "-")
			this->builder_->build_sub_operator();
		else if(token == "*")
			this->builder_->build_mul_operator();
		else if(token == "/")
			this->builder_->build_div_operator();
		else if(token == "%")
			this->builder_->build_mod_operator();
		else
			this->builder_->build_variable(token_[0]);
	}

	int check = builder_->get_paren_count();
	builder_->reset_paren_count();
	if(check == 0)
		return 0;
	else if(check < 0)
		throw std::invalid_argument("No matching left parenthesis.");
	else
		throw std::invalid_argument("No matching right parenthesis.");
}

int Calculator::expr_eval(void)
{
	if(builder_->var_root_)
		builder_->var_root_->accept(var_visitor);
	expr->root_->accept(visitor);
	builder_->reset_var_root();
	delete expr;	
	return visitor.give_answer();
}
