#include <cassert>
#include <iostream>
#include <array>

#include "algos/lower_bound.h"

template <class T, int N>
int
asize(T (&)[N]) { return N; }

int
main() {
  int data[]={1, 5, 7, 7, 7, 9, 9, 11, 22, 44, 666, 1000,};
  auto idx = [&](auto it) { return it - data; };
  assert( idx(lower_bound(data, data+asize(data), 9)) == 5 );
  assert( idx(lower_bound(data, data+asize(data), 8)) == 5 );
  assert( idx(lower_bound(data, data+asize(data), 7)) == 2 );
  assert( idx(lower_bound(data, data+asize(data), 6)) == 2 );
  assert( idx(lower_bound(data, data+asize(data), 5)) == 1 );
  assert( idx(lower_bound(data, data+asize(data), 1)) == 0 );
  assert( idx(lower_bound(data, data+asize(data), 0)) == 0 );
  return 0;
}
