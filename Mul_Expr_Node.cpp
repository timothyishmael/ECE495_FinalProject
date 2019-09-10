#include"Mul_Expr_Node.h"

Mul_Expr_Node::Mul_Expr_Node(void)
{
	this->rank_ = this->mul_rank_;
}

Mul_Expr_Node::~Mul_Expr_Node(void)
{}

int Mul_Expr_Node::solve(int num1, int num2) const
{
	return num1 * num2;
}

void Mul_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.visit_mul_expr_node(this);
}
