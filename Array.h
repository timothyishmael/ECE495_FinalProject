// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include"Array_Base.h"
template <typename T>
class Array_Iterator;

template <typename T>
class Array_Iterator;

template <typename T>
class Array : public Array_Base <T>
{
public:

  /// Default constructor.
  Array (void);

  Array (size_t length);

  /// Destructor.
  ~Array (void);

  //void set(size_t index, T value);

  /**
   * Set a new size for the array. If \a new_size is less than the current
   * size, then the array is truncated. If \a new_size if greater then the
   * current size, then the array is made larger and the new elements are
   * not initialized to anything. If \a new_size is the same as the current
   * size, then nothing happens.
   *
   * The array's original contents are preserved regardless of whether the 
   * array's size is either increased or decreased.
   *
   * @param[in]       new_size              New size of the array
   */
  void resize (size_t new_size);

  /// Shrink the array to reclaim unused space.
  void shrink ();

  friend Array_Iterator<T>;
  
protected:

  T * datatemp;
  T * giveData_(void);

};

#include "Array.inl"
#include "Array.cpp"

#endif   // !defined _ARRAY_H_
