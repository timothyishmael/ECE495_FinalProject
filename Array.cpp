// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


#include <stdexcept>         // for std::out_of_bounds exception
#include<iostream>

//
// Array
//
template <typename T>
Array <T>::Array (void):
Array_Base<T>()
{}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
{
	this->cur_size_ = length;
	this->max_size_ = length;
	this->data_ = new T[length];
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if(new_size < this->cur_size_)
		this->cur_size_ = new_size;
	else {
		if(new_size < this->max_size_){
			this->cur_size_ = new_size;
		}
		else {
			Array <T> data2 = Array<T>(new_size);
			for(int i=0; i<this->cur_size_; i++){
				data2.set(i, this->data_[i]);

			}
      
			datatemp = this->data_;	//datatemp is a declared protected pointer in Array.h
      
			this->data_ = data2.giveData_();
			this->cur_size_ = data2.size();
			this->max_size_ = data2.max_size();
			delete [] datatemp;
			data2.data_ = 0;
		}
	}
}

template <typename T>
void Array <T>::shrink (void)
{
	if(this->max_size_ > this->cur_size_){
		Array <T> data2 = Array<T>(this->cur_size_);	//else, declare new array of current size
		for(int i=0; i<this->cur_size_; i++)		//fill it with the values of the current array
			data2.set(i, this->data_[i]);
		datatemp = this->data_;			//set pointer to current array to temp pointer
		this->max_size_ = data2.max_size();
		this->data_ = data2.giveData_();	//set new array pointer to old array pointer
		delete [] datatemp;
		data2.data_ = 0;
	}
}


