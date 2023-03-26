#include <cstdlib>
#include <exception>

#include <libhal-__device__/__device__.hpp>

int main()
{
}

namespace boost {
void throw_exception(std::exception const& e)
{
  std::abort();
}
}  // namespace boost
