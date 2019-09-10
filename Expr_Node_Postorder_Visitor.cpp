#include"Expr_Node_Postorder_Visitor.h"
#include"Num_Expr_Node.h"
#include"Var_Expr_Node.h"
#include"Add_Expr_Node.h"
#include"Sub_Expr_Node.h"
#include"Mul_Expr_Node.h"
#include"Div_Expr_Node.h"
#include"Mod_Expr_Node.h"
#include"Utility_Node.h"

Expr_Node_Postorder_Visitor::Expr_Node_Postorder_Visitor(void)
{}

Expr_Node_Postorder_Visitor::~Expr_Node_Postorder_Visitor(void)
{}

void Expr_Node_Postorder_Visitor::visit_num_expr_node(Num_Expr_Node * num)
{
	stack.push(num->eval());
	delete num;
}

void Expr_Node_Postorder_Visitor::visit_var_expr_node(Var_Expr_Node * var)
{
	stack.push(var->eval());
	delete var;
}

void Expr_Node_Postorder_Visitor::visit_add_expr_node(const Add_Expr_Node * add)
{
	add->get_first_child()->accept(*this);
	add->get_child()->accept(*this);
	n1 = stack.pop();
	n2 = stack.pop();
	int sum = add->solve(n1, n2);
	stack.push(sum);
	delete add;
}

void Expr_Node_Postorder_Visitor::visit_sub_expr_node(const Sub_Expr_Node * sub)
{
	sub->get_first_child()->accept(*this);
	sub->get_child()->accept(*this);
	n2 = stack.pop();
	n1 = stack.pop();
	stack.push(sub->solve(n1, n2));
	delete sub;
}

void Expr_Node_Postorder_Visitor::visit_mul_expr_node(const Mul_Expr_Node * mul)
{
	mul->get_first_child()->accept(*this);
	mul->get_child()->accept(*this);
	n1 = stack.pop();
	n2 = stack.pop();
	stack.push(mul->solve(n1, n2));
	delete mul;
}

void Expr_Node_Postorder_Visitor::visit_div_expr_node(const Div_Expr_Node * div)
{
	div->get_first_child()->accept(*this);
	div->get_child()->accept(*this);
	n2 = stack.pop();
	n1 = stack.pop();
	stack.push(div->solve(n1, n2));
	delete div;
}

void Expr_Node_Postorder_Visitor::visit_mod_expr_node(const Mod_Expr_Node * mod)
{
	mod->get_first_child()->accept(*this);
	mod->get_child()->accept(*this);
	n2 = stack.pop();
	n1 = stack.pop();
	stack.push(mod->solve(n1, n2));
	delete mod;
}

void Expr_Node_Postorder_Visitor::visit_utility_node(const Utility_Node * utl)
{
	utl->get_child()->accept(*this);
	delete utl;
}
