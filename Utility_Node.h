#ifndef UTILITY_NODE_H
#define UTILITY_NODE_H
#include"Unary_Expr_Node.h"
#include"Expr_Node_Visitor.h"

class Utility_Node : public Unary_Expr_Node
{
	public:
		Utility_Node(void);
		~Utility_Node(void);
		int eval(void);
		void set_child(Expr_Node * node);
		void accept(Expr_Node_Visitor & v);
	private:
		friend class Expr_Node_Postorder_Visitor;
};
#endif
