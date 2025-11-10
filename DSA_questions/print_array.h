
// print_container.h
#pragma once

#include <iostream>

template <typename Container> void print_container(const Container &c) {
  for (const auto &elem : c) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}
