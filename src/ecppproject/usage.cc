#include "ecppproject.ih"

#include <iostream>

void ECPPProject::usage()
{

  cout << "Use: [";

  for (map<string,Module*>::iterator i = d_modules.begin();
       i != d_modules.end(); ++i)
    cout << (i != d_modules.begin()?"|":"") << (*i).first;

  cout << "] ..." << endl;


  cout << endl;

  for (map<string,Module*>::iterator i = d_modules.begin();
       i != d_modules.end(); ++i)
    cout << (*i).first << "\t-\t" << (*i).second->description() << endl << endl;

}
