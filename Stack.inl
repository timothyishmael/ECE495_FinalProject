// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.
#include<exception>
//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return iterator;
}

//
// pop
//
template <typename T>
inline
T Stack <T>::pop (void)
{
	if(iterator == 0)
		throw empty_exception();
	else{
		--iterator;
		return stack_data_->get(iterator);
	}
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	if(iterator == 0)
		throw empty_exception();
	else
		return stack_data_->get(iterator-1);
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	if(iterator == 0)
		return true;
	else
		return false;
}

template <typename T>
inline
void Stack <T>::clear (void)
{
  // COMMENT Just reset the variables instead popping each element, which
  // is expensive.
  // Answer To clear the stack, iterator has been reset, as this is the
  // element that all the rest of the stack methods key off of
	iterator = 0;
}

template <typename T>
inline
size_t Stack <T>::showIterator(void) const
{
	return iterator;
}

template <typename T>
inline
T Stack <T>::get(size_t index) const
{
	return stack_data_->get(index);
}

template <typename T>
inline
const size_t * Stack <T>::showMe (void) const
{
	return &iterator;
}
