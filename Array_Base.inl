//I pledge that I have neither given no received help on this assignment

//
// size
//
template <typename T>
inline
size_t Array_Base <T>::size (void) const
{
	return cur_size_;
}

//
// max_size
//
template <typename T>
inline
size_t Array_Base <T>::max_size (void) const
{
	return max_size_;
}

template <typename T>
inline
void Array_Base <T>::set_cur_size (size_t value)
{
	cur_size_ = value;
}
