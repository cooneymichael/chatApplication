#ifndef CONF_PARSER
#define CONF_PARSER

#include <iostream>
#include <fstream>

class ConfParser{
public:
  ConfParser(std::string file){
    confFile.open(file, std::ifstream::in);
  }

  char* readLine(){
    confFile.getline(line, 256);
    return line;
  }

private:
  std::ifstream confFile;
  char line[256];

};

#endif
