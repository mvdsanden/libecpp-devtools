#include "projectcontext.ih"

void ProjectContext::loadConfig()
{
  d_parser.parse_file((d_projectPath / Path(".ecpp/config")).str());

  if (!d_parser)
    throw runtime_error("error parding project config");

  // Need to think about what to deallocate!
  d_config = d_parser.get_document();

  d_projectName = d_config->get_root_node()->get_attribute_value("name");
  d_projectNS   = d_config->get_root_node()->get_attribute_value("namespace");

  if (d_projectName.empty())
    throw runtime_error("project has no name");

  if (d_projectNS.empty())
    throw runtime_error("project has no namespace");
}
