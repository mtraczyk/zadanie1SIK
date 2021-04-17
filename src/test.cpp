#include "gtest/gtest.h"
#include "parsing_functionalities.h"
#include <iostream>

namespace HTTPRequestPatterns2 {
  using std::regex;

  regex requestLineGET("(GET)\\s/[a-zA-Z0-9.-/]*\\s(HTTP/1.1)");
  regex requestLineHEAD("(HEAD)\\s/[a-zA-Z0-9.-/]*\\s(HTTP/1.1)");
  regex headerConnectionClose("(Connection):(\\s)*(close)(\\s)*");
  regex contentLength("(Content-Length):(\\s)*(0)(\\s)*");
}

TEST (SquareTest /*test suite name*/, PosZeroNeg /*test name*/) {
  HTTPRequestParser a;
  std::string request = "HEAD /hello/nic.txt HTTP/1.1\r\nConnection:     close      \r\nContent-Length:   0\r\n\r\nGET /hello/nic2.txt HTTP/1.1\r\nContent-Length:   0\r\n\r\n";
  a.parsePartOfARequest(request);

  std::cout << ":)" << std::endl;

  while (a.isALineParsed()) {
    a.parsePartOfARequest("");
    if (a.getFullyParsedRequest().first) {
      std::cout << a.hasAnErrorOccurred() << std::endl;
      std::cout << a.getFullyParsedRequest().first << " " << std::get<0>(a.getFullyParsedRequest().second) << " "
                << std::get<1>(a.getFullyParsedRequest().second) << " " << std::get<2>(a.getFullyParsedRequest().second)
                << std::endl;
      a.cleanAfterParsingWholeRequest();
      a.parsePartOfARequest("");
    }
  }

  std::vector<std::string> strings;
  std::istringstream f("denmark;sweden;india;us");
  std::string s;
  while (std::getline(f, s, ';')) {
    std::cout << s << std::endl;
    strings.push_back(s);
  }
}

/*

 class myTestFixture: public ::testing::test {
    public:
         myTestFixture( ) {
             // initialization;
             // can also be done in SetUp()
         }

    void SetUp( ) {
         // initialization or some code to run before each test
    }

    void TearDown( ) {
         // code to run after each test;
         // can be used instead of a destructor,
         // but exceptions can be handled in this function only
     }

    ~myTestFixture( )  {
         //resources cleanup, no exceptions allowed
    }

     // shared user data
};

TEST_F( myTestFixture, TestName) {}

*/