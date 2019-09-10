#include"Expr_Tree_Builder.h"
#include<sstream>
#include<string>
#include<iostream>
#include<stdexcept>

Expr_Tree_Builder::Expr_Tree_Builder(void):
	Expr_Builder(),
	grounding_node_ (new Utility_Node()),
	stored_num (0),
	last_ (0),
	paren_check (false)
{}

Expr_Tree_Builder::~Expr_Tree_Builder(void)
{
	delete grounding_node_;
}

void Expr_Tree_Builder::start_expression(void)
{
	//makes a new tree and sets the root as the first element of the root stack
	this->tree_ = new Expr_Tree();
	root_stack_.push(this->tree_->root_);
}

void Expr_Tree_Builder::build_number(std::string s)
{
	Num_Expr_Node * node = new Num_Expr_Node(s);
	stored_num = node;
}

void Expr_Tree_Builder::build_variable(char c)
{
	Var_Expr_Node * node = new Var_Expr_Node(c);
	stored_num = node;
	install_variable(node);
}

void Expr_Tree_Builder::build_add_operator(void)
{
	Ranked_Expr_Node * node = new Add_Expr_Node();
	install_operation(node);
}

void Expr_Tree_Builder::build_sub_operator(void)
{
	Ranked_Expr_Node * node = new Sub_Expr_Node();
	install_operation(node);
}

void Expr_Tree_Builder::build_mul_operator(void)
{
	Ranked_Expr_Node * node = new Mul_Expr_Node();
	install_operation(node);
}

void Expr_Tree_Builder::build_div_operator(void)
{
	Ranked_Expr_Node * node = new Div_Expr_Node();
	install_operation(node);
}

void Expr_Tree_Builder::build_mod_operator(void)
{
	Ranked_Expr_Node * node = new Mod_Expr_Node();
	install_operation(node);
}

//called after the creation of each Raked_Expr_Node
void Expr_Tree_Builder::install_operation(Ranked_Expr_Node * node)
{
	//if the current root has no root
	if(root_stack_.top() == 0){
		//make the stored number a child of the current node
		node->set_child(stored_num);
		//make the current node the new root of the tree
		root_stack_.pop();
		root_stack_.push(node);
		grounding_node_->set_child(root_stack_.top());
		last_root_stack_.push(grounding_node_);
	}
	//if the current node is of a higher rank than the tree root
	else if(root_stack_.top()->get_rank() < node->get_rank()){
		//make the stored number a child of the current node
		node->set_child(stored_num);
		//make the current node a child of the current root
		root_stack_.top()->set_child(node);
		if(root_stack_.top()->get_rank() == node->get_rank())
			root_stack_.push(node);	
	}
	//if the current node is of an equal or lower rank than the current root
	else{
		//make the stored number a child of the last node processed
		last_->set_child(stored_num);
		//pop the current root off the stack and make it a child of the current node
		node->set_child(root_stack_.pop());
		last_root_stack_.top()->set_child(node);
		//make the current node the new current root
		root_stack_.push(node);
	}
	last_ = node;
}

//called after the creation of each variable node, begins placing it in the var_root_ binary tree
void Expr_Tree_Builder::install_variable(Var_Expr_Node * node)
{
	if(var_root_ == 0)
		var_root_ = node;
	else if(node->compare_id(var_root_))
		install_right_variable(node, var_root_->get_right(), var_root_);
	else
		install_left_variable(node, var_root_->get_left(), var_root_);
}
void Expr_Tree_Builder::install_right_variable(Var_Expr_Node * node, Var_Expr_Node * right_child, Var_Expr_Node * root)
{
	if(right_child == 0)
		root->set_right(node);
	else if(node->compare_id(right_child))
		install_right_variable(node, right_child->get_right(), right_child);
	else
		install_left_variable(node, right_child->get_left(), right_child);
}
void Expr_Tree_Builder::install_left_variable(Var_Expr_Node * node, Var_Expr_Node * left_child, Var_Expr_Node * root)
{
	if(left_child == 0)
		root->set_left(node);
	else if(node->compare_id(left_child))
		install_right_variable(node, left_child->get_right(), left_child);
	else
		install_left_variable(node, left_child->get_left(), left_child);
}


Expr_Tree * Expr_Tree_Builder::get_expression(void)
{
	//make the stored number a child of the last node processed
	last_->set_child(stored_num);
	//pop the current root off the stack and set it to the root of the tree
	this->tree_->root_ = root_stack_.pop();
	return this->tree_;
}

int Expr_Tree_Builder::get_paren_count(void) const
{
	return paren_count;
}

void Expr_Tree_Builder::reset_paren_count(void)
{
	paren_count = 0;
}

//start of the left parenthesis builder
void Expr_Tree_Builder::paren_build_add(void)
{
	Ranked_Expr_Node * node = new Add_Expr_Node();
	paren_process(node);
}
void Expr_Tree_Builder::paren_build_sub(void)
{
	Ranked_Expr_Node * node = new Sub_Expr_Node();
	paren_process(node);
}
void Expr_Tree_Builder::paren_build_mul(void)
{
	Ranked_Expr_Node * node = new Mul_Expr_Node();
	paren_process(node);
}
void Expr_Tree_Builder::paren_build_div(void)
{
	Ranked_Expr_Node * node = new Div_Expr_Node();
	paren_process(node);
}
void Expr_Tree_Builder::paren_build_mod(void)
{
	Ranked_Expr_Node * node = new Mod_Expr_Node();
	paren_process(node);
}
void Expr_Tree_Builder::paren_process(Ranked_Expr_Node * node)
{
	//if the current root has no root
	if(root_stack_.top() == 0){
		//make the stored number a child of the current node
		node->set_child(stored_num);
		//make the current node the new root of the tree
		root_stack_.pop();
		root_stack_.push(node);
		grounding_node_->set_child(root_stack_.top());
		last_root_stack_.push(grounding_node_);
		paren_check = true;
		last_ = node;
	}
	else{
		//make the stored number a child of the current node
		node->set_child(stored_num);
		//make the current node a child of the last node
		last_root_stack_.push(last_);
		last_->set_child(node);
		//set current node to last node
		last_ = node;
		//make current node the new root of the tree
		root_stack_.push(node);
	}
}

//director (sub-contractor?) of the left parenthesis builder
void Expr_Tree_Builder::paren_left_builder(std::istringstream & input)
{
	//intake current stringstream and parse it
	++paren_count;
	std::string token;
	std::getline(input, token, ' ');
	if(token == "(")
		paren_left_builder(input);
	else if(token == ")"){
		paren_count = 0;
		throw std::invalid_argument("Empty parenthesis.");
	}
	else{
		//first token guarenteed to be a number/variable
		const char * token_ = token.c_str();
		if(token_[0] <= '9' && token_[0] >= '0')
			build_number(token);
		else
			build_variable(token_[0]);
		//second token guarenteed to be an operator
		std::getline(input, token, ' ');
		if(token == "+")
			paren_build_add();
		else if(token == "-")
			paren_build_sub();
		else if(token == "*")
			paren_build_mul();
		else if(token == "/")
			paren_build_div();
		else if(token == "%")
			paren_build_mod();
	}
}

//start of the right parenthesis builder
void Expr_Tree_Builder::paren_right_build_add(void)
{
	Ranked_Expr_Node * node = new Add_Expr_Node();
	paren_right_process(node);
}
void Expr_Tree_Builder::paren_right_build_sub(void)
{
	Ranked_Expr_Node * node = new Sub_Expr_Node();
	paren_right_process(node);
}
void Expr_Tree_Builder::paren_right_build_mul(void)
{
	Ranked_Expr_Node * node = new Mul_Expr_Node();
	paren_right_process(node);
}
void Expr_Tree_Builder::paren_right_build_div(void)
{
	Ranked_Expr_Node * node = new Div_Expr_Node();
	paren_right_process(node);
}
void Expr_Tree_Builder::paren_right_build_mod(void)
{
	Ranked_Expr_Node * node = new Mod_Expr_Node();
	paren_right_process(node);
}
void Expr_Tree_Builder::paren_right_process(Ranked_Expr_Node * node)
{
	if(root_stack_.top()->get_rank() < node->get_rank())
	{
		node->set_child(root_stack_.top()->get_child());
		root_stack_.top()->set_child(node);
		last_ = node;
	}
	else
	{
		node->set_child(root_stack_.pop());
		root_stack_.push(node);
		last_ = node;
		last_root_stack_.top()->set_child(node);
	}
}

//director of right parenthesis builder
void Expr_Tree_Builder::paren_right_builder(std::istringstream & input)
{
	//remake the previous root the new root of the tree
	if(paren_check == false){
		root_stack_.pop();
		last_root_stack_.pop();
		last_->set_child(stored_num);
		--paren_count;
		std::string token;
		std::getline(input, token, ' ');
		if(token == "+")
			paren_right_build_add();
		else if(token == "-")
			paren_right_build_sub();
		else if(token == "*")
			paren_right_build_mul();
		else if(token == "/")
			paren_right_build_div();
		else if(token == "%")
			paren_right_build_mod();
		else if(token == ")")
			paren_right_builder(input);
	}
	else{
		last_->set_child(stored_num);
		--paren_count;
	}
}


