#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int mode = 0;
  while (mode < 1 || mode > 9) {
    std::cout << "\n"
                 "1 - 1 KiB. - 1 Kibibyte - 1024 bytes\n"
                 "2 - new std::string[1]. - 16 byte???\n"
                 "3 - new int[1]. - 4 byte\n"
                 "4 - new char[1]. - 1 byte\n"
                 "5 - new long[1]. - 4 byte\n"
                 "6 - new int. - 4 byte\n"
                 "7 - new int[268435456] - 1 Gibibyte - 1073741824 bytes\n"
                 "8 - 1 KiB loop\n"
                 "9 - 1 GiB loop\n";
    std::cin >> mode;
    std::cin.clear();
    std::cin.ignore();
    switch (mode) {
      case 1: {
        mode = 0;
        int *kib = new int[256];
        continue;
      }
      case 2: {
        mode = 0;
        std::string *adr = new std::string[1];
        continue;
      }

      case 3: {
        mode = 0;
        int *adr = new int[1];
        continue;
      }

      case 4: {
        mode = 0;
        char *adr = new char[1];
        continue;
      }

      case 5: {
        mode = 0;
        long *adr = new long[1];
        continue;
      }

      case 6: {
        mode = 0;
        int *t5 = new int;
        continue;
      }

      case 7: {
        mode = 0;
        int *gib = new int[268435456];
        continue;
      }

      case 8: {
        mode = 0;
        while (true) {
          try {
            int *kib = new int[256];
          } catch (std::bad_alloc e) {
            std::cerr << e.what() << std::endl;
          }
        }
      }

      case 9: {
        mode = 0;
        while (true) {
          try {
            int *gib = new int[268435456];
          } catch (std::bad_alloc e) {
            std::cerr << e.what() << std::endl;
          }
        }
      }
      default: {
        continue;
      }
    }
  }
}

// 2147483647 == 0x7fffffff, Max size of new int in x64?'