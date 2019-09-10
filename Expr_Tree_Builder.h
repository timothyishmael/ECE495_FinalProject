#ifndef EXPR_TREE_BUILDER_H
#define EXPR_TREE_BUILDER_H
#include"Expr_Builder.h"
#include"Ranked_Expr_Node.h"
#include"Var_Expr_Node.h"
#include"Expr_Node.h"
#include"Stack.h"
#include<sstream>
#include<string>

class Expr_Tree_Builder : public Expr_Builder
{
	public:
		Expr_Tree_Builder(void);
		~Expr_Tree_Builder(void);
		void start_expression(void);
		void build_number(std::string s);
		void build_variable(char c);
		void build_add_operator(void);
		void build_sub_operator(void);
		void build_mul_operator(void);
		void build_div_operator(void);
		void build_mod_operator(void);
		void paren_left_builder(std::istringstream & input);
		void paren_right_builder(std::istringstream & input);
		Expr_Tree * get_expression(void);
		int get_paren_count(void) const;
		void reset_paren_count(void);
	private:
		void install_operation(Ranked_Expr_Node * node);
		void install_variable(Var_Expr_Node * node);
		void install_right_variable(Var_Expr_Node * node, Var_Expr_Node * child, Var_Expr_Node * root);
		void install_left_variable(Var_Expr_Node * node, Var_Expr_Node * child, Var_Expr_Node * root);
		Expr_Tree * tree_;
		Ranked_Expr_Node * last_;
		Num_Expr_Node * stored_num;
		Ranked_Expr_Node * grounding_node_;
		Stack<Ranked_Expr_Node*> last_root_stack_;
		Stack<Ranked_Expr_Node*> root_stack_;
		bool paren_check;
		void paren_build_add(void);
		void paren_build_sub(void);
		void paren_build_mul(void);
		void paren_build_div(void);
		void paren_build_mod(void);
		void paren_process(Ranked_Expr_Node * node);
		void paren_right_build_add(void);
		void paren_right_build_sub(void);
		void paren_right_build_mul(void);
		void paren_right_build_div(void);
		void paren_right_build_mod(void);
		void paren_right_process(Ranked_Expr_Node * node);

};

#endif
