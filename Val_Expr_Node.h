#ifndef VAL_EXPR_NODE_H
#define VAL_EXPR_NODE_H
#include"Expr_Node.h"

class Val_Expr_Node : public Expr_Node
{
	public:
		Val_Expr_Node(void);
		virtual ~Val_Expr_Node(void);
		virtual install_node(Val_Expr_Node * box, Val_Expr_Node * root) = 0;
	protected:
		int n_;
		
}
#endif
