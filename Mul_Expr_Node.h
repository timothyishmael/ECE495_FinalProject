#ifndef MUL_EXPR_NODE_H
#define MUL_EXPR_NODE_H
#include"Binary_Expr_Node.h"
#include"Expr_Node_Visitor.h"

class Mul_Expr_Node : public Binary_Expr_Node
{
	public:
		Mul_Expr_Node(void);
		~Mul_Expr_Node(void);
		int solve(int num1, int num2) const;
		void accept(Expr_Node_Visitor & v);
};
#endif
