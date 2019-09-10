#ifndef MOD_EXPR_NODE_H
#define MOD_EXPR_NODE_H
#include"Binary_Expr_Node.h"
#include"Expr_Node_Visitor.h"

class Mod_Expr_Node : public Binary_Expr_Node
{
	public:
		Mod_Expr_Node(void);
		~Mod_Expr_Node(void);
		int solve(int num1, int num2) const;
		void accept(Expr_Node_Visitor & v);
};
#endif
