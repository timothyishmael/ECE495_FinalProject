#ifndef NUM_EXPR_NODE_H
#define NUM_EXPR_NODE_H
#include"Expr_Node.h"
#include"Expr_Node_Visitor.h"
#include<string>

class Num_Expr_Node : public Expr_Node
{
	public:
		Num_Expr_Node(void);
		Num_Expr_Node(std::string n);
		~Num_Expr_Node(void);
		int eval(void);
		void accept(Expr_Node_Visitor & v);
		//void install_value(Val_Expr_Node * box, Val_Expr_Node * root);
	protected:
		int n_;
};
#endif
