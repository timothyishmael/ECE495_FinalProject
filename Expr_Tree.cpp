#include"Expr_Tree.h"

Expr_Tree::Expr_Tree(void):
	root_ (0)
{}

Expr_Tree::~Expr_Tree(void)
{}

int Expr_Tree::eval(void)
{
	return this->root_->eval();
}
