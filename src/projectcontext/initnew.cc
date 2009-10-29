#include "projectcontext.ih"

void ProjectContext::initNew(std::string const &name, std::string const &ns)
{
  if (d_config)
    throw runtime_error("already inside a project");

  // Note: we should delete this, but not if it comes from the parser...
  d_config = new Document;

  // Get the project path.
  d_projectPath = Path::currentWorkingDirectory();

  // Create the root node.
  Element *root = d_config->create_root_node("ecpp-project");

  // Set the name.
  root->set_attribute("name",name);
  root->set_attribute("namespace",ns);

  // The namespace
  Node *nss = root->add_child("namespaces");

  // Add the base namespace.
  nss->add_child("ns")->set_attribute("name",ns);

  // The dependencies
  Node *deps = root->add_child("dependencies");

  // Add some attributes.
  root->add_child("git")->set_attribute("use","false");
  root->add_child("svn")->set_attribute("use","false");

}
