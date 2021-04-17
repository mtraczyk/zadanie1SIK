#include "file_system_functionalities.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

bool checkWhetherGivenPathExists(std::string const &path) {
  return std::filesystem::exists(path);
}

bool checkWhetherAccessToAPathIsAcquired(std::string const &path) {
  namespace fs = std::filesystem;
  fs::perms p = fs::status(path).permissions();

  return (p & fs::perms::others_read) != fs::perms::none;
}

void getResourcesFromAFile(std::string const &path,
                           std::unordered_map<std::string, std::pair<std::string, std::string>> &resourcesMap) {
  std::fstream fs(path, std::fstream::in);

  if (!fs.is_open()) {
    exit(EXIT_FAILURE);
  }

  char delimiter = 9; // ASCII for tab
  std::string line, part;
  std::stringstream ss;
  std::vector<std::string> lineParts;

  while (std::getline(fs, line)) {
    ss.clear();
    lineParts.clear();
    ss >> line;

    while (std::getline(ss, part, delimiter)) {
      lineParts.push_back(part);
    }

    if (resourcesMap.find(lineParts[0]) == resourcesMap.end()) {
      resourcesMap[lineParts[0]] = {lineParts[1], lineParts[2]};
    }
  }

  fs.close();
}