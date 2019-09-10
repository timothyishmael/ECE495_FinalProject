#ifndef ARRAY_ITERATOR
#define ARRAY_ITERATOR

#include"Array.h"

template <typename T>
class Array_Iterator
{
	public:
<<<<<<< HEAD
		Array_Iterator(const Array & a);
=======
		Array_Iterator(const Array<T> & a);
>>>>>>> cfdf2e52dbfe798d5e53a1f60f0f76785ef71056
		~Array_Iterator(void);

		bool is_done(void);
		void advance(void);
		T & operator * (void);
		T * operator -> (void);
	
	private:
		Array<T> & a_;
		size_t curr_;
};

#include"Array_Iterator.cpp"
#endif
