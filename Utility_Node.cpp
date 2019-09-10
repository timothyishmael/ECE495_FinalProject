#include"Utility_Node.h"

Utility_Node::Utility_Node(void)
{}

Utility_Node::~Utility_Node(void)
{}

int Utility_Node::eval(void)
{
	return this->child_->eval();
}

void Utility_Node::set_child(Expr_Node * node)
{
	this->child_ = node;
}

void Utility_Node::accept(Expr_Node_Visitor & v)
{
	v.visit_utility_node(this);
}
