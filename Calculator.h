#ifndef CALCULATOR_H
#define CALCULATOR_H
#include"Expr_Tree_Builder.h"
#include"Expr_Node_Postorder_Visitor.h"
#include"Var_Expr_Node_Inorder_Visitor.h"
#include"Expr_Tree.h"
#include<string>
#include<sstream>

class Calculator
{
	public:
		Calculator(void);
		~Calculator(void);
		Calculator(Expr_Builder * builder);
		Expr_Node_Postorder_Visitor visitor;
		Var_Expr_Node_Inorder_Visitor var_visitor;
		int evaluate(const std::string & infix);
	private:
		bool parse_expr(const std::string & infix);
		int expr_eval(void);
		Expr_Builder * builder_;
		Expr_Tree * expr;
		const char * token_;
};

#endif
