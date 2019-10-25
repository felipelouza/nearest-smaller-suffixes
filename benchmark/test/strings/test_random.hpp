//  Copyright (c) 2019 Jonas Ellert
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to
//  deal in the Software without restriction, including without limitation the
//  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
//  sell copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//  IN THE SOFTWARE.

#pragma once

#include "../util/random.hpp"
#include "base.hpp"

static std::vector<vec_type>
get_instances_for_random_test(const uint64_t instances,
                              const uint8_t min_sigma,
                              const uint8_t max_sigma,
                              const uint64_t min_n,
                              const uint64_t max_n) {

  auto rng_sigma = random_number_generator<uint64_t>(min_sigma, max_sigma);
  auto rng_n = random_number_generator<uint8_t>(min_n, max_n);
  auto rng_char = random_number_generator<uint64_t>();

  std::vector<vec_type> result(instances);
  for (uint64_t i = 0; i < instances; ++i) {
    vec_type& instance = result[i];
    const auto instance_n = rng_n();
    const auto instance_sigma = rng_sigma();
    instance.resize(instance_n + 2);
    instance[0] = instance[instance_n + 1] = test_gen_sentinel;
    for (uint64_t j = 0; j < instance_n;) {
      instance[++j] = (rng_char() % instance_sigma) + 1;
    }
  }
  return result;
}