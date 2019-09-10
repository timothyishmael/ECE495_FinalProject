#include"Var_Expr_Node.h"
#include<iostream>
#include<cstdlib>
#include<string>

Var_Expr_Node::Var_Expr_Node(void):
	right_ (0),
	left_ (0)
{}

Var_Expr_Node::Var_Expr_Node(char c):
	Num_Expr_Node(),
	name_ (c),
	right_ (0),
	left_ (0)
{
	id = name_;
	if(id-96 > 0)
		id = (id-97)*2+1;
	else
		id = (id-65)*2;
}

Var_Expr_Node::~Var_Expr_Node(void)
{}

int Var_Expr_Node::eval(void)
{
	return this->n_;
}

void Var_Expr_Node::set_variable(void)
{
	std::cout << "Please enter number for variable " << name_ << std::endl;
	std::string temp1;
	getline(std::cin, temp1);
	unit = temp1.c_str();
	//const char * unit = input_;
	if(unit[0] <= 57 && unit[0] >= 48)
		this->n_ = atoi(unit);
	else{
		name_ = unit[0];
		set_variable();
	}
}

void Var_Expr_Node::set_value(int value)
{
	this->n_ = value;
}

int Var_Expr_Node::get_id(void) const
{
	return id;
}

void Var_Expr_Node::set_right(Var_Expr_Node * node)
{
	right_ = node;
}

void Var_Expr_Node::set_left(Var_Expr_Node * node)
{
	left_ = node;
}

Var_Expr_Node * Var_Expr_Node::get_right(void) const
{
	return right_;
}

Var_Expr_Node * Var_Expr_Node::get_left(void) const
{
	return left_;
}

char Var_Expr_Node::get_name_(void) const
{
	return this->name_;
}

void Var_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.visit_var_expr_node(this);
}

bool Var_Expr_Node::compare_id(const Var_Expr_Node * target)
{
	if(id > target->get_id())
		return true;
	return false;
}

int Var_Expr_Node::get_value(void) const
{
	return value;
}

