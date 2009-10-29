#include "ecppproject.ih"


#include "../createmod/createmod.hh"
#include "../initmod/initmod.hh"

ECPPProject::ECPPProject()
{
  addModule(new CreateMod(d_context));
  addModule(new InitMod(d_context));
}


ECPPProject::~ECPPProject()
{
  for (map<string,Module*>::iterator i = d_modules.begin();
       i != d_modules.end(); ++i)
    delete (*i).second;
}
