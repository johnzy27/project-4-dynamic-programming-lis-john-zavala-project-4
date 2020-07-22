///////////////////////////////////////////////////////////////////////////////
// subsequence.hpp
//
// Dynamic programming algorithm for solving the longest increasing 
// subsequence problem.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <algorithm>
#include <cassert>
#include <random>
#include <string>
#include <sstream>
#include <vector>
#include "timer.hpp"


using namespace std;
using sequence = std::vector<int>;

// Convert a sequence into a human-readable string useful for pretty-printing
// or debugging.
std::string sequence_to_string(const sequence& seq) {
  std::stringstream ss;
  ss << "[";
  bool first = true;
  for (auto& x : seq) {
    if (!first) {
      ss << ", ";
    }
    ss << x;
    first = false;
  }
  ss << "]";
  return ss.str();
}

// Generate a pseudorandom sequence of the given size, using the given
// seed, where all elements are in the range [0, max_element]. max_element
// must be non-negative.
sequence random_sequence(size_t size, unsigned seed, int max_element) {

    assert(max_element >= 0);

    sequence result;

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dist(0, max_element);

    for (size_t i = 0; i < size; ++i) {
        result.push_back(dist(gen));
    }

    return result;
}

bool is_increasing(const sequence& A) 
{
    //boolean variable.
    bool increasingOrder = true;
    for (size_t i = 1; i < A.size(); ++i)

  {
      // TODO
      // write the test to check if A[i-1] and A[i] are
      // in increasing order
      // if not, you need to write what needs to be done

      //checking if A[i-1] is greater than or equal to A[i]
      // if condition to see if A[i-1] is greater than or equal to A[i]
      if (A[i-1] >= A[i])
      {
          //setting increasing order = to false
          increasingOrder = false;
      }

  }
    //returning increasing Order
  return increasingOrder;
}

sequence longest_increasing_end_to_beginning(const sequence& A) {


    //setting my timer 
    Timer timer;
  const size_t n = A.size();
  cout << "Size of N = " << n << endl;



  // populate the array H with 0 values
  std::vector<size_t> H(n, 0);

  // calculate the values of array H
  // note that i has to be declared signed, to avoid an infinite loop, since
  // the loop condition is i >= 0
  for (signed int i = n-2;  i>= 0; i--) {
    for (size_t j = i+1; j < n ; j++) {
        // TODO
        // write the statements that compute the value of
        // H[i] based on conditions that involve A[i], A[j]
        // and H[j]
        //checking if A[I] is less than A[J] and if H[i] <= H[J]
        if (A[i] < A[j] and H[i] <= H[j])
        {
            //if condition met setting H[i] = to H[j] + 1
            H[i] = H[j] + 1;

        }


    }
  }

  // calculate in max the length of the longest subsequence
    // by adding 1 to the maximum value in H
  auto max = *std::max_element(H.begin(), H.end()) + 1;

  // allocate space for the subsequence R
  std::vector<int> R(max);

  // add elements to R by whose H's values are in decreasing order,
    // starting with max-1
  // store in index the H values sought

    size_t index = max-1, j = 0;
    for (size_t i = 0; i < n; ++i) {
      if (H[i] == index) 
      {
          // TODO
          // write the statements to add A[i] to the sequene R by
          // storing it into R[j], decrement index and increment j
         
          //setting R[j] = to A[i]
          R[j] = A[i];
          //incrementing j
          j = j + 1;
          //incrementing index
          index = index - 1;
          
      }
    }

    //timer variable for time elapsed
    double elapsed = timer.elapsed();

    //outputing how long it took
    cout << "Elapsed time in seconds: " << elapsed << endl;




  return sequence(R.begin(), R.begin() + max);
}
