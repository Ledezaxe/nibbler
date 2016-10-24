#include <dlfcn.h>
#include <cstddef>

#include "../includes/libraryHandler.hpp"

libraryHandler::libraryHandler(const char *path)
{
  this->handle = dlopen(path, RTLD_GLOBAL | RTLD_LAZY);
  if (this->handle == NULL)
    throw dlerror();
}

libraryHandler::libraryHandler(const libraryHandler &to_copy)
  : handle(to_copy.getHandle())
{}

libraryHandler::~libraryHandler()
{
  if (dlclose(this->handle) != 0)
    throw dlerror();
}

libraryHandler libraryHandler::operator=(const libraryHandler &to_copy)
{
  this->handle = to_copy.getHandle();
  return (*this);
}

void	*libraryHandler::getHandle() const
{
  return (this->handle);
}
