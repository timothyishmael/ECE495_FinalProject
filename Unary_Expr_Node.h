#ifndef UNARY_EXPR_NODE_H
#define UNARY_EXPR_NODE_H
#include"Ranked_Expr_Node.h"
#include"Expr_Node.h"

class Unary_Expr_Node : public Ranked_Expr_Node
{
	public:
		Unary_Expr_Node(void);
		virtual ~Unary_Expr_Node(void);
		virtual int eval(void);
		virtual void set_child(Expr_Node * node);
		Expr_Node * get_child(void) const;
		Expr_Node * get_first_child(void) const;
	protected:
		Expr_Node * child_;
};
#endif
