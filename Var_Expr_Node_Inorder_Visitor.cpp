#include"Var_Expr_Node_Inorder_Visitor.h"
#include"Num_Expr_Node.h"
#include"Var_Expr_Node.h"
#include"Add_Expr_Node.h"
#include"Sub_Expr_Node.h"
#include"Mul_Expr_Node.h"
#include"Div_Expr_Node.h"
#include"Mod_Expr_Node.h"
#include"Utility_Node.h"
#include<iostream>


Var_Expr_Node_Inorder_Visitor::Var_Expr_Node_Inorder_Visitor(void)
{}

Var_Expr_Node_Inorder_Visitor::~Var_Expr_Node_Inorder_Visitor(void)
{}

void Var_Expr_Node_Inorder_Visitor::visit_num_expr_node(Num_Expr_Node * num)
{}

void Var_Expr_Node_Inorder_Visitor::visit_var_expr_node(Var_Expr_Node * var)
{
	if(var->get_left())
		var->get_left()->accept(*this);
	var->set_variable();
	if(var->get_right())
		var->get_right()->accept(*this);
}

void Var_Expr_Node_Inorder_Visitor::visit_add_expr_node(const Add_Expr_Node * add)
{}

void Var_Expr_Node_Inorder_Visitor::visit_sub_expr_node(const Sub_Expr_Node * sub)
{}

void Var_Expr_Node_Inorder_Visitor::visit_mul_expr_node(const Mul_Expr_Node * mul)
{}

void Var_Expr_Node_Inorder_Visitor::visit_div_expr_node(const Div_Expr_Node * div)
{}

void Var_Expr_Node_Inorder_Visitor::visit_mod_expr_node(const Mod_Expr_Node * mod)
{}

void Var_Expr_Node_Inorder_Visitor::visit_utility_node(const Utility_Node * utl)
{}
