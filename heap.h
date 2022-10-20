#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T>>
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
  void down_trickle(int index);
  void up_trickle(int index);
  
  std::vector<T> vec;
  int mary;
  PComparator pc;
};

// Add implementation of member functions here
// Constructor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : mary(m), pc(c) {}

// Deconstructor
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  //push into the heap
  vec.push_back(item);
  //fix the heap
  up_trickle(size()-1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(vec.empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vec[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(vec.empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empty");
  }
  //remove the root
  vec[0] = vec.back();
  vec.pop_back();
  //fix the heap
  down_trickle(0);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  if (size() == 0) return true;
  return false;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return vec.size();
}

//trickle down
template <typename T, typename PComparator>
void Heap<T,PComparator>::down_trickle(int index) {
  int curr = index;

  std::vector<int> children;
  for (int i = 0; i < mary; i++) {
    int temp = index*2+i+1;
  }

  for (int i = 0; i < mary; i++) {
    if (children[i] < size() && vec[children[i]] > vec[curr]) curr = children[i];
  }
  
  if (curr != index) {
    std::swap(vec[index], vec[curr]);
    down_trickle(curr);
  }
}

//trickle up
template <typename T, typename PComparator>
void Heap<T,PComparator>::up_trickle(int index) {
  if (vec[(index-1)/mary] < vec[index]) {
    std::swap(vec[index], vec[(index-1)/mary]);
    up_trickle((index-1)/mary);
  }
}

#endif

