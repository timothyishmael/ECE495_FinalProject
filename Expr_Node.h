#ifndef EXPR_NODE_H
#define EXPR_NODE_H
#include"Expr_Node_Visitor.h"

class Expr_Node
{
	public:
		Expr_Node(void);
		virtual ~Expr_Node(void);
		virtual void accept(Expr_Node_Visitor & v) = 0;
		virtual int eval(void) = 0;
};
#endif
