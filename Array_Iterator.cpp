
template <typename T>
Array_Iterator <T>::Array_Iterator(Array<T> & a):
	a_ (a),
	curr_ (0)
{}

template <typename T>
Array_Iterator <T>::~Array_Iterator(void)
{}

template <typename T>
bool Array_Iterator <T>::is_done(void)
{
<<<<<<< HEAD
	return (curr_ >= this->a_.cur_size_);
=======
	return curr_ >= this->a.data_[curr_];
>>>>>>> cfdf2e52dbfe798d5e53a1f60f0f76785ef71056
}

template <typename T>
void Array_Iterator <T>::advance(void)
{
	++curr_;
}

template <typename T>
T & Array_Iterator <T>::operator * (void)
{
	return this->a.data_[curr_];
}

template <typename T>
T * Array_Iterator <T>::operator -> (void)
{
	return &this->a.data_[curr_];
}
