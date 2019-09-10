#include"Sub_Expr_Node.h"

Sub_Expr_Node::Sub_Expr_Node(void)
{
	this->rank_ = this->sub_rank_;
}

Sub_Expr_Node::~Sub_Expr_Node(void)
{}

int Sub_Expr_Node::solve(int num1, int num2) const
{
	return num1 - num2;
}

void Sub_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.visit_sub_expr_node(this);
}
