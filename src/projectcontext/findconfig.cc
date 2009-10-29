#include "projectcontext.ih"

void ProjectContext::findConfig()
{
  // Get current path.
  Path cur = Path::currentWorkingDirectory();

  Path up = cur;

  // Look 5 deep.
  for (size_t i = 0; i < 5; ++i) {

    Path ecpp = up / Path(".ecpp");

    if (ecpp.exists()) {
      d_projectPath = up;
      loadConfig();
      break;
    }

    up = up.up();
  }
}
