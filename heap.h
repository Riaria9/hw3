#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;


private:
  /// Add whatever helper functions and data members you need below
  int m_;
  PComparator c_;
  std::vector<T> vec_;
  void heapify(int idx);



};

// Add implementation of member functions here

//constructor to set the functor and 
template<typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
  :m_=m, c_=c {}



template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return vec_.empty();
}

template <typename T, typename PComparator>
T const & Heap<T, PComparator>::top() const
{
  return vec_[0];
}

template<typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return vec_.size();
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error();
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vec_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empty"));
  }
  int idx = 0;
  idx[idx] = data.back();
  idx.pop_back;
  heapify(0);


}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx)
{
  std::size_t x = m*idx_ + 1;//x contains the currently smallest/biggest val
  if((m*idx_ + 1) >= vec_.size()){ //check if leaf node
    return;
  }
  for(int i = 1; i<= m_; i++){//find the smallest/greatest child node
    if(m*idx_ + i + 1 < vec_.size()){//since itsnt leaf node, it must has 1 child. check next child node exist
      if(c_(vec_[x],vec_[m*idx_ + i + 1])){x = m*idx_ + i;}
      else{x = m*idx_ + i + 1;}
    }
    else{
      break;
    }
  }
  if(c(vec_[x]), vec_[idx]){ // if x is even greater/smaller than its parent, then swap
		std::swap(vec_[idx],vec_[b_child]);
		MaxHeap<T>::heapify(x);
	}

}

#endif

