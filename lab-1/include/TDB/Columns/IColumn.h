#pragma once

#include <cstddef>

#include "TDB/Core/Field.h"

namespace TDB {

class IColumn {
public:
  virtual void insert(const Field &x) = 0;

  virtual std::size_t size() const = 0;

  virtual void clear() = 0;

  virtual ~IColumn(){};
};

} // namespace TDB