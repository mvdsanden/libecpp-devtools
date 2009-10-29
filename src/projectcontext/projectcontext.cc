#include "projectcontext.ih"

ProjectContext::ProjectContext()
  : d_config(0),
    d_projectPath("/tmp")
{
  findConfig();
}

ProjectContext::~ProjectContext()
{
  save();
}

