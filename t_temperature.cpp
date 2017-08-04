#include <iostream>
#include <sstream>
#include <fstream>

#include <stdexcept> // runtime_error
#include <cstring> // strerror

float get_temperature() {

  std::ifstream file("/sys/class/thermal/thermal_zone0/temp");

  if (file.fail()) {
    throw std::runtime_error(strerror(errno));
  }

  std::stringstream ss;
  ss << file.rdbuf();
  float f;
  ss >> f;

  return f / 1000.;
}

int main() {

  std::cout << get_temperature() << "\n";

  return EXIT_SUCCESS;
}
