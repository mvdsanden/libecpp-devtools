#include "ecppproject.ih"

#include "../createmod/createmod.hh"

ECPPProject::ECPPProject()
{
  addModule(new CreateMod);
}


ECPPProject::~ECPPProject()
{
  for (map<string,Module*>::iterator i = d_modules.begin();
       i != d_modules.end(); ++i)
    delete (*i).second;
}
