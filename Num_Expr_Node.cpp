#include"Num_Expr_Node.h"
#include<string>
#include<cstdlib>

Num_Expr_Node::Num_Expr_Node(void)
{}

Num_Expr_Node::Num_Expr_Node(std::string n):
	n_ (atoi(n.c_str()))
{}

Num_Expr_Node::~Num_Expr_Node(void)
{}

int Num_Expr_Node::eval(void)
{
	return n_;
}

void Num_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.visit_num_expr_node(this);
}

/*void Num_Expr_Node::install_value(Val_Expr_Node * box, Val_Expr_Node * root)
{
	box = this;
}*/
