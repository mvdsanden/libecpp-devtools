#include "createmod.ih"

bool CreateMod::classExists(std::string const &name)
{
  return (d_context.projectPath() / Path(name)).exists();
}
