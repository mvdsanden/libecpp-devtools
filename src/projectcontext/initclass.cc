#include "projectcontext.ih"

void ProjectContext::initClass(Path const &path, std::string const &name)
{
  // Create the class config.
  Document *cl = new Document;

  // Create the root node.
  Node *root = dynamic_cast<Node*>(cl->create_root_node("ecpp-class"));

  // Set the name.
  root->add_child("name")->add_child_text(name);
  root->add_child("namespace")->add_child_text(ns());

  // Add some attributes.
  root->add_child("git")->set_attribute("use","false");
  root->add_child("svn")->set_attribute("use","false");

  // Write xml.
  cl->write_to_file_formatted(path.str());

  delete cl;

  list<Node*> cls = d_config->get_root_node()->get_children("classes");

  Node *cnode = 0;

  if (cls.empty()) {
    cnode = d_config->get_root_node()->add_child("classes");
  } else
    cnode = cls.front();

  Element *c = cnode->add_child("class");
  c->set_attribute("name",name);
  c->set_attribute("path",(path - Path::currentWorkingDirectory()).str());
}
