#include <cstdlib>
#include <exception>

#include <libhal-library/library.hpp>

int main()
{
}

namespace boost {
void throw_exception(std::exception const& e)
{
  std::abort();
}
}  // namespace boost
