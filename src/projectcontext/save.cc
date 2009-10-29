#include "projectcontext.ih"

#include <iostream>

void ProjectContext::save()
{
  if (d_config && d_config->get_root_node()) {

    // The main project config dir.
    Path ecppDir = d_projectPath / Path(".ecpp");

    if (!ecppDir.exists())
      if (!ecppDir.make())
	throw runtime_error("error creating main ecpp config dir");

    if (!ecppDir.exists())
      throw runtime_error("error creating main ecpp config dir");

    Path ecppConfig = ecppDir / Path("config");

    cerr << "Writing to " << ecppConfig.str() << endl;

    // Write xml.
    d_config->write_to_file_formatted(ecppConfig.str());

  }
}
