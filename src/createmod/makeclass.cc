#include "createmod.ih"

#include <ecpp/string/string.hh>

void CreateMod::makeClass(std::string const &name, Path path, vector<string> const &ns)
{

  if (!path.make())
    throw runtime_error("error making path '"+path.str()+"'");

  if (!path.exists())
    throw runtime_error("error making path '"+path.str()+"'");

  // The class config filepath.
  Path clConfig = path / Path(".ecpp_class");

  if (clConfig.exists())
    throw runtime_error("error class config already exists");

  d_context.initClass(clConfig,name);

  vector<string> nss(ns.begin(),ns.end());
  nss.insert(nss.begin(),d_context.ns());

  // Create a substitution map.
  map<string,string> substs;
  substs["@incguard"]  = "__INC_" + String::upper(String::combine(nss,"_")) + "_" + String::upper(name) + "_HH__";
  substs["@classname"] = name;
  substs["@filebase"]  = String::lower(name);
  substs["@header"]    = "/* no header yet defined */"; //d_context.fileHeader();
  substs["@ns"]        = d_context.ns();

  // Create the class header.
  makeTmplFile(d_context.classHeaderTmpl(),
	       path / Path(String::lower(name)+".hh"),
	       substs);

  // Create the internal header.
  makeTmplFile(d_context.internalHeaderTmpl(),
	       path / Path(String::lower(name)+".ih"),
	       substs);

  // Create the constructor.
  makeTmplFile(d_context.constructorTmpl(),
	       path / Path(String::lower(name)+".cc"),
	       substs);

  // Create the copy member.
  makeTmplFile(d_context.copyTmpl(),
	       path / Path("copy.cc"),
	       substs);

  // Create the destroy member.
  makeTmplFile(d_context.destroyTmpl(),
	       path / Path("destroy.cc"),
	       substs);



}
