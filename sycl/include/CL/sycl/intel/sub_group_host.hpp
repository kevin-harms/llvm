//==- sub_group_host.hpp --- SYCL sub-group for host device  ---------------==//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#pragma once

#include <CL/sycl/access/access.hpp>
#include <CL/sycl/id.hpp>
#include <CL/sycl/intel/functional.hpp>
#include <CL/sycl/range.hpp>
#include <CL/sycl/types.hpp>
#ifndef __SYCL_DEVICE_ONLY__

__SYCL_INLINE_NAMESPACE(cl) {
namespace sycl {
template <typename T, access::address_space Space> class multi_ptr;
namespace intel {
struct sub_group {
  /* --- common interface members --- */

  id<1> get_local_id() const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }
  range<1> get_local_range() const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  range<1> get_max_local_range() const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  id<1> get_group_id() const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  size_t get_group_range() const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  size_t get_uniform_group_range() const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  /* --- vote / ballot functions --- */

  bool any(bool predicate) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  bool all(bool predicate) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  /* --- collectives --- */

  template <typename T> T broadcast(T x, id<1> local_id) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  template <typename T, class BinaryOperation>
  T reduce(T x, BinaryOperation op) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  template <typename T, class BinaryOperation>
  T reduce(T x, T init, BinaryOperation op) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  template <typename T, class BinaryOperation>
  T exclusive_scan(T x, BinaryOperation op) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  template <typename T, class BinaryOperation>
  T exclusive_scan(T x, T init, BinaryOperation op) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  template <typename T, class BinaryOperation>
  T inclusive_scan(T x, BinaryOperation op) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  template <typename T, class BinaryOperation>
  T inclusive_scan(T x, BinaryOperation op, T init) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  /* --- one - input shuffles --- */
  /* indices in [0 , sub - group size ) */

  template <typename T> T shuffle(T x, id<1> local_id) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  template <typename T> T shuffle_down(T x, uint32_t delta) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }
  template <typename T> T shuffle_up(T x, uint32_t delta) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  template <typename T> T shuffle_xor(T x, id<1> value) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  /* --- two - input shuffles --- */
  /* indices in [0 , 2* sub - group size ) */
  template <typename T> T shuffle(T x, T y, id<1> local_id) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }
  template <typename T>
  T shuffle_down(T current, T next, uint32_t delta) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }
  template <typename T>
  T shuffle_up(T previous, T current, uint32_t delta) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  /* --- sub - group load / stores --- */
  /* these can map to SIMD or block read / write hardware where available */
  template <typename T, access::address_space Space>
  T load(const multi_ptr<T, Space> src) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  template <int N, typename T, access::address_space Space>
  vec<T, N> load(const multi_ptr<T, Space> src) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  template <typename T, access::address_space Space>
  void store(multi_ptr<T, Space> dst, T &x) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  template <int N, typename T, access::address_space Space>
  void store(multi_ptr<T, Space> dst, const vec<T, N> &x) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

  /* --- synchronization functions --- */
  void barrier(access::fence_space accessSpace =
                   access::fence_space::global_and_local) const {
    throw runtime_error("Subgroups are not supported on host device. ");
  }

protected:
  template <int dimensions> friend class cl::sycl::nd_item;
  sub_group() {
    throw runtime_error("Subgroups are not supported on host device. ");
  }
};
} // namespace intel
} // namespace sycl
} // __SYCL_INLINE_NAMESPACE(cl)
#endif
