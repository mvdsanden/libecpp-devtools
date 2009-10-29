#include "projectcontext.ih"

void ProjectContext::loadConfig()
{
  d_parser.parse_file((d_projectPath / Path(".ecpp/config")).str());

  if (!d_parser)
    throw runtime_error("error parding project config");

  d_config = d_parser.get_document();
}
