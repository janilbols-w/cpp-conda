#include <iostream>

#include "absl/container/flat_hash_map.h"
#include "nlohmann/json.hpp"
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"

using json = nlohmann::json;

int main(int argc, char* argv[]) {
  std::cout << "xtensor\n";
  xt::xarray<double> arr1{{1.0, 2.0, 3.0}, {2.0, 5.0, 7.0}, {2.0, 5.0, 7.0}};
  xt::xarray<double> arr2{5.0, 6.0, 7.0};
  xt::xarray<double> res = xt::view(arr1, 1) + arr2;
  std::cout << res << "\n";

  std::cout << "absl::flat_hash_map\n";
  absl::flat_hash_map<int, std::string> map1 = {
      {1, "abcde"},
      {2, "efghi"},
      {4, "vwxyz"},
  };
  for (const auto& entry : map1) {
    std::cout << entry.first << ": " << entry.second << "\n";
  }

  std::cout << "'Echo' function from library1\n";
  // std::cout << echo(5) << '\n';

  json j = {
      {"pi", 3.141},
      {"happy", true},
      {"name", "Niels"},
      {"nothing", nullptr},
      {"answer", {{"everything", 42}}},
      {"list", {1, 0, 2}},
      {"object",
       {
           {"currency", "USD"},
           {"value", 42.99},
       }},
  };
  std::cout << "JSON:\n" << j.dump(2) << '\n';

  return 0;
}
