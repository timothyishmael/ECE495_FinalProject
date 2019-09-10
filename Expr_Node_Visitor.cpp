#include"Expr_Node_Visitor.h"
#include"Num_Expr_Node.h"
#include"Add_Expr_Node.h"
#include"Sub_Expr_Node.h"
#include"Mul_Expr_Node.h"
#include"Div_Expr_Node.h"
#include"Mod_Expr_Node.h"
#include"Utility_Node.h"


Expr_Node_Visitor::Expr_Node_Visitor(void)
{}

Expr_Node_Visitor::~Expr_Node_Visitor(void)
{}

int Expr_Node_Visitor::give_answer(void)
{
	return stack.pop();
}
