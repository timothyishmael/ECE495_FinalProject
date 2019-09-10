#include"Expr_Builder.h"

Expr_Builder::Expr_Builder(void):
	var_root_ (0),
	paren_count (0)
{}

Expr_Builder::~Expr_Builder(void)
{}

void Expr_Builder::reset_var_root(void)
{
	var_root_ = 0;
}

