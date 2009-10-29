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

#ifndef __INC_ECPP_PROJECTCONTEXT_HH__
#define __INC_ECPP_PROJECTCONTEXT_HH__

#include <libxml++/libxml++.h>

#include <ecpp/path/path.hh>

namespace ecpp
{

  class ProjectContext {
  public:

    ProjectContext();
    ~ProjectContext();

    /**
     *  Initialize a new project.
     *
     *  @param name the name of the project.
     *  @param ns the projects namespace.
     */
    void initNew(std::string const &name, std::string const &ns);

    /**
     *  @returns true if the project has been initialized (either by loading or by initNew()).
     */
    bool initialized() const;

    /**
     *  Save the project context.
     */
    void save();

    /**
     *  Load the project config.
     */
    void loadConfig();

  private:

    void findConfig();

    xmlpp::Document *d_config;

    Path d_projectPath;

    xmlpp::DomParser d_parser;

  };

  inline bool ProjectContext::initialized() const
  {
    return d_config && d_config->get_root_node();
  }

};

#endif // __INC_ECPP_PROJECTCONTEXT_HH__
