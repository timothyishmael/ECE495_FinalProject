#include"Div_Expr_Node.h"
#include<stdexcept>

Div_Expr_Node::Div_Expr_Node(void)
{
	this->rank_ = this->div_rank_;
}

Div_Expr_Node::~Div_Expr_Node(void)
{}

int Div_Expr_Node::solve(int num1, int num2) const
{
	if(num1 == 0)
		throw std::invalid_argument("Cannot divide by 0.");
	else
		return num1/num2;
}

void Div_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.visit_div_expr_node(this);
}
