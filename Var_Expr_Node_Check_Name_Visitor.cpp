#include"Var_Expr_Node_Check_Name_Visitor.h"
#include"Var_Expr_Node.h"
#include<iostream>


Var_Expr_Node_Check_Name_Visitor::Var_Expr_Node_Check_Name_Visitor(char variable):
	name_ (variable),
	value_found (false)
{
	std::cout << "Visitor created to find " << name_ << std::endl;
}

Var_Expr_Node_Check_Name_Visitor::~Var_Expr_Node_Check_Name_Visitor(void)
{}

void Var_Expr_Node_Check_Name_Visitor::visit_var_expr_node(Var_Expr_Node * var)
{
	std::cout << "Value looking.\n";
	if(var->get_left())
		var->get_left()->accept(*this);
	std::cout << "Evaluating variable " << var->get_name_() << std::endl;
	if(var->get_name_() == this->name_){
		value_found = true;
		std::cout << "Value found.\n";
		this->value_ = var->get_value();
		std::cout << "Value is " << value_ << std::endl;
	}
	if(var->get_right())
		var->get_right()->accept(*this);
}

void Var_Expr_Node_Check_Name_Visitor::set_name_(char input)
{
	this->name_ = input;
}

void Var_Expr_Node_Check_Name_Visitor::set_value_(int input)
{
	this->value_ = input;
}

char Var_Expr_Node_Check_Name_Visitor::get_name_(void) const
{
	return this->name_;
}

int Var_Expr_Node_Check_Name_Visitor::get_value_(void) const
{
	return this->value_;
}

bool Var_Expr_Node_Check_Name_Visitor::get_value_found(void) const
{
	return value_found;
}

void Var_Expr_Node_Check_Name_Visitor::reset(void)
{
	this->value_found = false;
}
