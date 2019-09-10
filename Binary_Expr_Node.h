#ifndef BINARY_EXPR_NODE_H
#define BINARY_EXPR_NODE_H
#include"Ranked_Expr_Node.h"
#include"Expr_Node_Visitor.h"
#include"Expr_Node_Postorder_Visitor.h"
#include"Stack.h"

class Binary_Expr_Node : public Ranked_Expr_Node
{
	public:
		Binary_Expr_Node(void);
		Binary_Expr_Node(Binary_Expr_Node * current_root);
		virtual ~Binary_Expr_Node(void);
		virtual int eval(void);
		Expr_Node * get_child(void) const;
		void set_child(Expr_Node * node);
		Expr_Node * get_first_child(void) const;
	protected:
		virtual int solve(int n1, int n2) const = 0;
		Expr_Node * right_;
		Expr_Node * left_;
};
#endif
