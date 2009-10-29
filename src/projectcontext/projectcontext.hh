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
     *  Initialize a new class.
     *
     */
    void initClass(Path const &path, std::string const &name);

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

    std::string name() const;

    std::string ns() const;

    /**
     *  @returns the project path.
     */
    Path const &projectPath() const;

    /**
     *  @returns the path to the class header template.
     */
    Path const &classHeaderTmpl() const;

    /**
     *  @returns the path to the internal header template.
     */
    Path const &internalHeaderTmpl() const;

    /**
     *  @returns the path to the member template.
     */
    Path const &memberTmpl() const;

    Path const &constructorTmpl() const;

    Path const &copyTmpl() const;

    Path const &destroyTmpl() const;

  private:

    void findConfig();

    Path findTmpl(std::string const &name);

    xmlpp::Document *d_config;

    xmlpp::DomParser d_parser;

    std::string d_projectName;

    std::string d_projectNS;

    Path d_projectPath;

    Path d_classHeaderTmpl;

    Path d_internalHeaderTmpl;

    Path d_memberTmpl;

    Path d_constructorTmpl;

    Path d_copyTmpl;

    Path d_destroyTmpl;

  };

  inline bool ProjectContext::initialized() const
  {
    return d_config && d_config->get_root_node();
  }

  inline std::string ProjectContext::ns() const
  {
    return d_projectNS;
  }

  inline std::string ProjectContext::name() const
  {
    return d_projectName;
  }

  inline Path const &ProjectContext::projectPath() const
  {
    return d_projectPath;
  }

  inline Path const &ProjectContext::classHeaderTmpl() const
  {
    return d_classHeaderTmpl;
  }

  inline Path const &ProjectContext::internalHeaderTmpl() const
  {
    return d_internalHeaderTmpl;
  }

  inline Path const &ProjectContext::memberTmpl() const
  {
    return d_memberTmpl;
  }

  inline Path const &ProjectContext::constructorTmpl() const
  {
    return d_constructorTmpl;
  }

  inline Path const &ProjectContext::copyTmpl() const
  {
    return d_copyTmpl;
  }

  inline Path const &ProjectContext::destroyTmpl() const
  {
    return d_destroyTmpl;
  }

};

#endif // __INC_ECPP_PROJECTCONTEXT_HH__
