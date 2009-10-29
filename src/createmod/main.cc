#include "createmod.ih"

#include <stdexcept>

int CreateMod::main(ArgList::iterator begin, ArgList::iterator end)
{

  if (begin == end) {
    usage();
    throw runtime_error("usage");
  }

  if (*begin == "class")
    return createClass(begin+1,end);
  else if (*begin == "subclass")
    return createSubClass(begin+1,end);
  else if (*begin == "member")
    return createMember(begin+1,end);
  else {
    usage();
    throw runtime_error("usage");
  }

}
