#ifndef VAR_EXPR_NODE_H
#define VAR_EXPR_NODE_H
#include"Num_Expr_Node.h"
#include"Expr_Node_Visitor.h"
#include<string>

class Var_Expr_Node : public Num_Expr_Node
{
	public:
		Var_Expr_Node();
		Var_Expr_Node(char c);
		~Var_Expr_Node(void);
		int eval(void);
		void set_variable(void);
		void set_value(int);
		int get_id(void) const;
		void set_right(Var_Expr_Node * node);
		void set_left(Var_Expr_Node * node);
		Var_Expr_Node * get_right(void) const;
		Var_Expr_Node * get_left(void) const;
		char get_name_(void) const;
		void accept(Expr_Node_Visitor & v);
		bool compare_id(const Var_Expr_Node * target);
		int get_value(void) const;
		
	private:
		Var_Expr_Node * right_;
		Var_Expr_Node * left_;
		int value;
		int id;
		char name_;
		const char * unit;
		
};
#endif
