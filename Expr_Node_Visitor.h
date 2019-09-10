#ifndef EXPR_NODE_VISITOR_H
#define EXPR_NODE_VISITOR_H
#include"Stack.h"

class Add_Expr_Node;
class Sub_Expr_Node;
class Mul_Expr_Node;
class Div_Expr_Node;
class Mod_Expr_Node;
class Num_Expr_Node;
class Var_Expr_Node;
class Utility_Node;

class Expr_Node_Visitor
{
	public:
		Expr_Node_Visitor(void);
		virtual ~Expr_Node_Visitor(void);
		virtual void visit_num_expr_node(Num_Expr_Node * num) = 0;
		virtual void visit_var_expr_node(Var_Expr_Node * var) = 0;
		virtual void visit_add_expr_node(const Add_Expr_Node * add) = 0;
		virtual void visit_sub_expr_node(const Sub_Expr_Node * sub) = 0;
		virtual void visit_mul_expr_node(const Mul_Expr_Node * mul) = 0;
		virtual void visit_div_expr_node(const Div_Expr_Node * div) = 0;
		virtual void visit_mod_expr_node(const Mod_Expr_Node * mod) = 0;
		virtual void visit_utility_node(const Utility_Node * utl) = 0;
		int give_answer(void);

	protected:
		Stack<int> stack;
		int n1, n2;
};
#endif
