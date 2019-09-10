
#include <stdexcept>
//
template <typename T>
Array_Base <T>::Array_Base (void):
cur_size_ (0),
max_size_ (5),
data_ (new T[5])
{}

//
// Array_Base (size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length):
cur_size_ (length),
max_size_ (length),
data_ (new T[length])
{}

//
// Array_Base (size_t, T)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill):
cur_size_ (length),
max_size_ (length),
data_ (new T[length])
{
	for(int i=0;i<length;i++)
		data_[i] = fill;
}

//
// Array_Base (const Array_Base &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & array_base):
cur_size_ (array_base.cur_size_),
max_size_ (array_base.max_size_),
data_ (new T[max_size_])
{
	for(int i=0;i<cur_size_;i++)
		data_[i] = array_base.data_[i];
}

//
// ~Array
//
template <typename T>
Array_Base <T>::~Array_Base (void)
{
	delete [] data_;
}

//
// operator =
//
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base & rhs)
{
	max_size_ = rhs.max_size_;
	cur_size_ = rhs.cur_size_;
	for(int i=0; i<cur_size_; i++)
		data_[i] = rhs.data_[i];
	const Array_Base* temp5 = this;
	return *temp5;
}

//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	if(index >= cur_size_)
		throw std::out_of_range("out_of_range");
	else
		return data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	if(index >= cur_size_)
		throw std::out_of_range("out_of_range");
	else
		return data_[index];
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
	if(index >= this->cur_size_)
		throw std::out_of_range("out_of_range");
	else
		return this->data_[index];
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
	if(index >= cur_size_)
		throw std::out_of_range("out_of_range");
	else{
		data_[index] = value;
	}
}


//
// find (char)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
	int it;
	for(it=0; it<cur_size_; it++){
		if(data_[it] == value)
			break;
	}
	if(it == cur_size_)
		return -1;
	else{
		return it;
	}
}

//
// find (char, size_t) 
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
	int it;
	//if 'start' exceeds size of data_, send out_of_range excpetion
	if(start > cur_size_)
		throw std::out_of_range("out_of_range");
	else{					//if not, search data_ from start onward until 'ch' is found 
		for(it=start; it<cur_size_; it++){
			if(data_[it] == val)
				break;
		}
		if(it == cur_size_)		//if not found, return -1
			return -1;
		else{
			return it;
		}
	}
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
	if(&data_ == &rhs.data_)
		return true;
	for(int i=0; i<cur_size_; i++){		//go down both arrays to see if any element is different
		if(rhs.get(i) != data_[i])
			return false;		//if so, return false
	}
	return true;
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
	if(rhs.data_ == data_)
		return false;
	else
		return true;
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
	for(int i=0; i<cur_size_; i++)
		data_[i] = value;
}

template <typename T>
void Array_Base<T>::reverse (void)
{
	for(int i=0; i<(cur_size_/2); i++){		//go from start of data_ to middle
		temp2 = i-1;				//save array element and space-1
		temp1 = data_[i];
		data_[i] = data_[cur_size_-temp2];	//swap the element with its mirror across the midpoint
		data_[cur_size_-temp2] = temp1;
	}
}

template <typename T>
Array_Base<T> Array_Base<T>::slice (size_t begin) const
{
	size_t k;
	k = cur_size_-begin;
  	Array_Base <T> data2(k);
	for(int j=0; j<k; j++)
		data2.set(j, data_[j+begin]);
	data2.set_cur_size(k);
	return data2;
	
}

template <typename T>
Array_Base<T> Array_Base<T>::slice (size_t begin, size_t end) const
{
	size_t k;
	k = end - begin;
  	Array_Base <T> data2(k);
	for(int j=0; j<k; j++)
		data2.set(j, data_[j+begin]);
	data2.set_cur_size(k);
	return data2;
}
