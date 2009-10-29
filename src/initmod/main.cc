#include "initmod.ih"

#include <ecpp/string/string.hh>

int InitMod::main(ArgList::iterator begin, ArgList::iterator end)
{

  string ns = "";
  string name = "";

  for (ArgList::iterator i = begin; i != end; ++i) {

    // Parse options.
    if ((*i).length() > 2 && (*i).substr(0,2) == "--") {
      string option = (*i).substr(2,(*i).length()-2);

      if (option == "ns") {
	++i;
	ns = *i;
      } else {
	usage();
	throw runtime_error("unknown option");
      }

    } else {

      if (d_context.initialized()) {
	usage();
	throw runtime_error("Extra argument given");
      }

      vector<string> id = String::split(*i,"::");

      if (id.size() == 2) {
	ns = id[0];
	name = id[1];
      } else if (id.size() == 1) {
	name = id[0];
      } else {
	usage();
	throw runtime_error("nested namespaces are not supported");
      }

      if (name.empty()) {
	usage();
	throw runtime_error("no or empty project name given");
      }

      if (ns.empty()) {
	usage();
	throw runtime_error("no or empty project namespace given");
      }

      // initialize the project.
      d_context.initNew(name,ns);

    }

  }

  if (!d_context.initialized()) {
    usage();
  }

  cout << "Initializing this directory as project '" << ns << "::" << name << "'." << endl;

  return 0;
}
