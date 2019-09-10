#include"Binary_Expr_Node.h"
#include"Expr_Node.h"

Binary_Expr_Node::Binary_Expr_Node(void):
	right_ (0),
	left_ (0)
{}

Binary_Expr_Node::Binary_Expr_Node(Binary_Expr_Node * root):
	left_ (root->get_child()),
	right_ (root->get_child())
{}

Binary_Expr_Node::~Binary_Expr_Node(void)
{}

int Binary_Expr_Node::eval(void)
{
	int n1 = left_->eval();
	int n2 = right_->eval();
	return solve(n1, n2);
}

Expr_Node * Binary_Expr_Node::get_child(void) const
{
	if(left_ == 0)
		return left_;
	else
		return right_;
}

void Binary_Expr_Node::set_child(Expr_Node * node)
{
	if(left_ == 0)
		left_ = node;
	else
		right_ = node;
}

Expr_Node * Binary_Expr_Node::get_first_child(void) const
{
	return left_;
}


