#include"Unary_Expr_Node.h"

Unary_Expr_Node::Unary_Expr_Node(void)
{}

Unary_Expr_Node::~Unary_Expr_Node(void)
{}

int Unary_Expr_Node::eval(void)
{
	return this->child_->eval();
}

void Unary_Expr_Node::set_child(Expr_Node * node)
{
	child_ = node;
}

Expr_Node * Unary_Expr_Node::get_child(void) const
{
	return child_;
}

Expr_Node * Unary_Expr_Node::get_first_child(void) const
{
	return child_;
}
