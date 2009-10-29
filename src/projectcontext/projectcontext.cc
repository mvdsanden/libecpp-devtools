#include "projectcontext.ih"

ProjectContext::ProjectContext()
  : d_projectPath("/tmp")
{
}

ProjectContext::~ProjectContext()
{
  save();
}

