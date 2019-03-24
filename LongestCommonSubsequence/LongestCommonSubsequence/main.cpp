#include <iostream>
#include "lcs_algorithms.h"

void TestLCS(std::string &a, std::string &b, const std::string &expected) {
  std::cout << "\n" << a << " <--> " << b << "\n";
  const std::string subseq = "unavailable implementation";
  //const std::string subseq = lcs::LCS(a, b);
  int subseq_size = lcs::LCS(a, b);
  std::cout << "have longest common subsequence \"" << subseq << "\" of size: " << subseq_size
            << ", expected: " << expected.size() << "\n"
            << ((expected.size() == subseq_size) ? "[OK]" : "[FAILED]") << std::endl;
}

int main() {
  std::cout << "Testing solution to 'Longest Common Subsequence' problem." << std::endl;
  
  std::string a("AGGTAB");
  std::string b("GXTXAYB");
  TestLCS(a, b, "GTAB");

  a = {"JATAXGPDMYLDXUKDNFTPRRUMBMEMLROWRHWOQNTCLGHLCRORZHGSBAECPLPCCDYVNXMDMFHAOPLQ"};
  b = {"IZKHIQBJTIMITDKXIKSXJECWMKWABHSL"};
  TestLCS(a, b, "BBBBBBBBBBBB");

  a = {"LRBBMQBHCDARZOWKKYHIDDQSCDXRJMOWFRXSJYBLDBEFSARCBYNECDYGGXXPKLORELLNMPAPQFWKHOPKMCO"};
  b = {"QHNWNKUEWHSQMGBBUQCLJJIVSWMDKQTBXIXMVTRRBLJPTNSNFWZQFJMAFADRRWSOFSBCNUVQHFFBSAQXWPQCA"};
  TestLCS(a, b, "2-----------------------5");

  system("pause");
  return 0;
}