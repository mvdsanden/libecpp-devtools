#include "createmod.ih"

#include <fstream>

#include <ecpp/string/string.hh>

void CreateMod::makeTmplFile(Path const &tmpl,
			     Path const &dest,
			     map<string,string> const &substs)
{

  if (!tmpl.exists())
    throw runtime_error("template file  '"+tmpl.str()+"' does not exist");

  ifstream templ(tmpl.str().c_str());

  if (!templ)
    throw runtime_error("error opening template file '"+tmpl.str()+"'");

  if (dest.exists())
    throw runtime_error("file already exists");

  ofstream destination(dest.str().c_str());

  while (templ && destination) {

    string line;

    getline(templ,line);

    destination << String::substitute(line,substs) << endl;

  }

}
