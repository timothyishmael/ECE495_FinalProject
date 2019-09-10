#ifndef EXPR_BUILDER_H
#define EXPR_BUILDER_H
#include"Expr_Tree.h"
#include"Add_Expr_Node.h"
#include"Sub_Expr_Node.h"
#include"Mul_Expr_Node.h"
#include"Div_Expr_Node.h"
#include"Mod_Expr_Node.h"
#include"Num_Expr_Node.h"
#include"Var_Expr_Node.h"
#include"Utility_Node.h"
#include<sstream>
#include<string>

class Expr_Builder
{
	public:
		Expr_Builder(void);
		~Expr_Builder(void);
		virtual void start_expression(void) = 0;
		virtual void build_number(std::string s) = 0;
		virtual void build_variable(char c) = 0;
		virtual void build_add_operator(void) = 0;
		virtual void build_sub_operator(void) = 0;
		virtual void build_mul_operator(void) = 0;
		virtual void build_div_operator(void) = 0;
		virtual void build_mod_operator(void) = 0;
		virtual void paren_left_builder(std::istringstream & input) = 0;
		virtual void paren_right_builder(std::istringstream & input) = 0;
		virtual Expr_Tree * get_expression(void) = 0;
		Var_Expr_Node * var_root_;
		void reset_var_root(void);
		virtual int get_paren_count(void) const = 0;
		virtual void reset_paren_count(void) = 0;
	protected:
		int paren_count;
};
#endif
