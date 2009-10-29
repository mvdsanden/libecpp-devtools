#include "projectcontext.ih"

ProjectContext::ProjectContext()
  : d_config(0),
    d_projectPath("/tmp"),
    d_classHeaderTmpl("/tmp"),
    d_internalHeaderTmpl("/tmp"),
    d_memberTmpl("/tmp"),
    d_constructorTmpl("/tmp"),
    d_copyTmpl("/tmp"),
    d_destroyTmpl("/tmp")
{
  findConfig();

  if (initialized()) {
    d_classHeaderTmpl    = findTmpl("header");
    d_internalHeaderTmpl = findTmpl("internal");
    d_memberTmpl         = findTmpl("member");
    d_constructorTmpl    = findTmpl("constructor");
    d_copyTmpl           = findTmpl("copy");
    d_destroyTmpl        = findTmpl("destroy");
  }
}

ProjectContext::~ProjectContext()
{
  save();
}

