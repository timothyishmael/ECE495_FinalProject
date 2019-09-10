#ifndef EXPR_TREE_H
#define EXPR_TREE_H
#include"Ranked_Expr_Node.h"

class Expr_Tree
{
	public:
		Expr_Tree(void);
		~Expr_Tree(void);
		int eval(void);
		Ranked_Expr_Node * root_;
};

#endif
