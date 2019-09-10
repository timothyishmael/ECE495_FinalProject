// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $
// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
//
// Stack
//
template <typename T>
Stack <T>::Stack (void):
	stack_data_ (new Array<T>(5)),
	iterator (0)
{}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack):
	stack_data_ (new Array<T>(iterator)),
	iterator (stack.showIterator())
{
	for(size_t i=0;i<iterator;i++)
		stack_data_->set(i, stack.stack_data_->get(i));
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
	stack_data_->~Array();
}

//
// push
//

template <typename T>
void Stack <T>::push (T element)
{
  // COMMENT You should check the size first and resize if, then insert
  // the element. This approach is way more expensive since exceptions are
  // heavy and growing the stack is not an exceptional case, but an expected
  // case.
  // ANSWER This method has been reworked to directly check the size of stack_data_
  // and resize it if necessary, eliminaing the need for exceptions to be used by
  // this method
  
	if(iterator<stack_data_->size()){
		stack_data_->set(iterator, element);
	}
	else{
		stack_data_->resize((iterator+1)*2);
		stack_data_->set(iterator, element);
	}
	++iterator;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	stack_data_->data_ = rhs->data_;
	iterator = rhs.showIterator();
}

//
// clear
//
  
// COMMENT Just reset the variables instead popping each element, which
  // is expensive.
 // ANSWER This comment was for the clear() method, and due to changes
 // made, that method has been moved to Stack.inl
