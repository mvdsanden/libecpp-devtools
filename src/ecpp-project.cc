#include <iostream>

#include "ecppproject/ecppproject.hh"


using namespace std;
using namespace ecpp;


int main(int argc, char *argv[])
{
  ArgList args(argc,argv);

  ECPPProject app;

  return app.main(args);
}
