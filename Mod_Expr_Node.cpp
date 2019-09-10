#include"Mod_Expr_Node.h"
#include<stdexcept>

Mod_Expr_Node::Mod_Expr_Node(void)
{
	this->rank_ = this->mod_rank_;
}

Mod_Expr_Node::~Mod_Expr_Node(void)
{}

int Mod_Expr_Node::solve(int num1, int num2) const
{
	if(num2 == 0)
		throw std::invalid_argument("Cannot divide by 0.");
	else
		return num1%num2;
}

void Mod_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.visit_mod_expr_node(this);
}
