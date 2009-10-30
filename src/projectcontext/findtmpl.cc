#include "projectcontext.ih"

Path ProjectContext::findTmpl(string const &name)
{
  Path header(name + ".tmpl");

  Path tmpl = d_projectPath / Path(".ecpp") / header;

  if (tmpl.exists())
    return tmpl;

  tmpl = Path::home() / Path(".ecpp") / header;

  if (tmpl.exists())
    return tmpl;

  tmpl = Path("/usr/local/share/libecpp/templates") / header;

  if (tmpl.exists())
    return tmpl;

  throw runtime_error("template '"+name+"' not found");
}
