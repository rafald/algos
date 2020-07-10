/*
* Algos library
*
* Copyright Rafal Dzbek 2017
*
*  Use, modification and distribution is subject to the
*  Boost Software License, Version 1.0. (See accompanying
*  file LICENSE_1_0.txt or copy at
*  http://www.boost.org/LICENSE_1_0.txt)
*
* Project home: https://
*/

#pragma once

template< typename T, size_t N >
inline size_t dim( T (&arr)[N] ) { return N; }


namespace std {
   template <class T > //TODO enable_if streamable: decltype( std::declval<std::ostream&>()<< std::declval<T>())
   std::ostream &
   operator<<(std::ostream & s, std::basic_string<T> const & str) {
      std::for_each(str.begin(), str.end(), [&](auto const & v){
         std::cout << v << ","; }
      );
      return s;
   }

// TODO std::to_string(std::basic_string<T>)
