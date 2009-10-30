/*
  This file is part of libecpp-module_name.
  libecpp-module_name is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  libecpp-mofule_name is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __INC_ECPP_ECPPPROJECT_HH__
#define __INC_ECPP_ECPPPROJECT_HH__

#include "../app/app.hh"
#include "../module/module.hh"
#include "../projectcontext/projectcontext.hh"

#include <map>

namespace ecpp
{

  class ECPPProject : public App {
  public:

    ECPPProject();

    virtual ~ECPPProject();

    void addModule(Module *module);

    virtual int main(ArgList &args);

    void usage();

  private:

    void parseOption(ArgList::iterator &arg);

    std::map<std::string,Module*> d_modules;

    ProjectContext d_context;

  };

  inline void ECPPProject::addModule(Module *module)
  {
    d_modules[module->name()] = module;
  }

};

#endif // __INC_ECPP_ECPPPROJECT_HH__
