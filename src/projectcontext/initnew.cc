#include "projectcontext.ih"

void ProjectContext::initNew(std::string const &name, std::string const &ns)
{
  // Get the project path.
  d_projectPath = Path::currentWorkingDirectory();

  // Create the root node.
  Node *root = dynamic_cast<Node*>(d_config.create_root_node("ecpp-project"));

  // Set the name.
  root->add_child("name")->add_child_text(name);
  root->add_child("namespace")->add_child_text(ns);

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
