#ifndef SUB_EXPR_NODE_H
#define SUB_EXPR_NODE_H
#include"Binary_Expr_Node.h"
#include"Expr_Node_Visitor.h"

class Sub_Expr_Node : public Binary_Expr_Node
{
	public:
		Sub_Expr_Node(void);
		~Sub_Expr_Node(void);
		int solve(int num1, int num2) const;
		void accept(Expr_Node_Visitor & v);
};
#endif
