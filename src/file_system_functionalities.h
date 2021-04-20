#ifndef FILE_SYSTEM_FUNCTIONALITIES_H
#define FILE_SYSTEM_FUNCTIONALITIES_H

#include <iostream>
#include <unordered_map>
#include <vector>

bool checkWhetherGivenPathExists(std::string const &);
bool checkWhetherAccessToAPathIsAcquired(std::string const &);
void getResourcesFromAFile(std::string const &, std::unordered_map<std::string, std::pair<std::string, std::string>> &);
bool getApplicationOctetStreamRepresentationOfAFile(std::string const &, std::vector<uint8_t> &);
bool isDirectory(std::string const &);
bool isFileContainedWithinGivenDirectory(std::string const &, std::string const &);
void convertToAbsolutePath(std::string &) noexcept;

#endif /* FILE_SYSTEM_FUNCTIONALITIES_H */
