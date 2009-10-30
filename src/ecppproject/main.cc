#include "ecppproject.ih"

int ECPPProject::main(ArgList &args)
{
  if (args.empty())
    usage();

  ArgList::iterator arg = args.begin() + 1;

  while (arg != args.end()) {
    map<string,Module*>::iterator i = d_modules.find(*arg);

    if (i != d_modules.end())
      return (*i).second->main(++arg,args.end());

    parseOption(arg);
  }

  return 0;
}
