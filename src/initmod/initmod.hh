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

#ifndef __INC_ECPP_INITMOD_HH__
#define __INC_ECPP_INITMOD_HH__

#include "../module/module.hh"
#include "../projectcontext/projectcontext.hh"

#include <string>

#include <ecpp/arglist/arglist.hh>

namespace ecpp
{

  class InitMod : public Module {
  public:

    InitMod(ProjectContext &context);

    virtual int main(ArgList::iterator begin, ArgList::iterator end);

    virtual std::string description();

    void usage();

  private:

    ProjectContext &d_context;

  };

};

#endif // __INC_ECPP_INITMOD_HH__
