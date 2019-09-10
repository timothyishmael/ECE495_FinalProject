#include"Add_Expr_Node.h"

Add_Expr_Node::Add_Expr_Node()
{
	this->rank_ = this->add_rank_;
}

Add_Expr_Node::~Add_Expr_Node(void)
{}

int Add_Expr_Node::solve(int num1, int num2) const
{
	return num1 + num2;
}

void Add_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.visit_add_expr_node(this);
}
