#ifndef VAR_EXPR_NODE_INORDER_VISITOR_H
#define VAR_EXPR_NODE_INORDER_VISITOR_H
#include"Expr_Node_Visitor.h"

class Var_Expr_Node_Inorder_Visitor : public Expr_Node_Visitor
{
	public:
		Var_Expr_Node_Inorder_Visitor(void);
		~Var_Expr_Node_Inorder_Visitor(void);
		void visit_num_expr_node(Num_Expr_Node * num);
		void visit_var_expr_node(Var_Expr_Node * var);
		void visit_add_expr_node(const Add_Expr_Node * add);
		void visit_sub_expr_node(const Sub_Expr_Node * sub);
		void visit_mul_expr_node(const Mul_Expr_Node * mul);
		void visit_div_expr_node(const Div_Expr_Node * div);
		void visit_mod_expr_node(const Mod_Expr_Node * mod);
		void visit_utility_node(const Utility_Node * utl);
};
#endif
