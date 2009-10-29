#include "createmod.ih"

#include <ecpp/string/string.hh>
//#include <ecpp/string/splitter.hh>

int CreateMod::createClass(ArgList::iterator begin, ArgList::iterator end)
{
  if (!d_context.initialized())
    throw runtime_error("not in a project directory");

  for (ArgList::iterator i = begin; i != end; ++i) {

    // Parse options.
    if ((*i).length() > 2 && (*i).substr(0,2) == "--") {
      string option = (*i).substr(2,(*i).length()-2);

      if (option == "ns") {
	++i;
	//	ns = *i;
      } else {
	usage();
	throw runtime_error("unknown option");
      }

    } else {

      vector<string> split = String::split(*i,"::");

      // Check if higher classes exist.
      for (vector<string>::iterator j = split.begin();
	   j != split.end()-1; ++j)
	if (!classExists(*j))
	  throw runtime_error("class '"+(*j)+"' does not exist, please create it first");

      // check if it already exists.
      if (classExists(split.back()))
	throw runtime_error("class '"+(*i)+"' already exists");

      // Make the class.
      makeClass(split.back(),
		d_context.projectPath() / Path(String::combine(split,"/")),
		vector<string>(split.begin(),split.end()-1));

    }

  }

  if (!d_context.initialized()) {
    usage();
  }

  //  cout << "Initializing this directory as project '" << ns << "::" << name << "'." << endl;

  return 0;
}
