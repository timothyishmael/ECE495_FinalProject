#ifndef RANKED_EXPR_NODE_H
#define RANKED_EXPR_NODE_H
#include"Expr_Node.h"
#include"Stack.h"

class Ranked_Expr_Node : public Expr_Node
{
	public:
		Ranked_Expr_Node(void);
		Ranked_Expr_Node(int);
		virtual ~Ranked_Expr_Node(void);
		virtual void set_child(Expr_Node * node) = 0;
		virtual Expr_Node * get_child(void) const = 0;
		virtual Expr_Node * get_first_child(void) const = 0;
		virtual int eval(void) = 0;
		int get_rank(void) const;
	protected:
		int rank_;
		const int add_rank_, sub_rank_, div_rank_, mul_rank_, mod_rank_;
};

#endif
