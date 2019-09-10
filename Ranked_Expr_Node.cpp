#include"Ranked_Expr_Node.h"

Ranked_Expr_Node::Ranked_Expr_Node(void):
	Expr_Node(),
	add_rank_ (1),
	sub_rank_ (1),
	div_rank_ (2),
	mul_rank_ (2),
	mod_rank_ (2)
{}

Ranked_Expr_Node::Ranked_Expr_Node(int input):
	rank_ (input),
	add_rank_ (1),
	sub_rank_ (1),
	div_rank_ (2),
	mul_rank_ (2),
	mod_rank_ (2)
{}

Ranked_Expr_Node::~Ranked_Expr_Node(void)
{}

int Ranked_Expr_Node::get_rank(void) const
{
	return rank_;
}
