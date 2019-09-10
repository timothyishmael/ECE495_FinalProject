#ifndef VAR_EXPR_NODE_CHECK_NAME_VISITOR_H
#define VAR_EXPR_NODE_CHECK_NAME_VISITOR_H

class Var_Expr_Node;

class Var_Expr_Node_Check_Name_Visitor
{
	public:
		Var_Expr_Node_Check_Name_Visitor(char variable);
		~Var_Expr_Node_Check_Name_Visitor(void);
		void visit_var_expr_node(Var_Expr_Node * var);
		void set_name_(char input);
		void set_value_(int input);
		char get_name_(void) const;
		int get_value_(void) const;
		bool get_value_found(void) const;
		void reset(void);
	private:
		char name_;
		int value_;
		bool value_found;
};
#endif

