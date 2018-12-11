#define CATCH_CONFIG_MAIN
#define UNIT_TEST
#include "catch.hpp"
#include "introduction_to_algorithms/algos.hpp"

TEST_CASE("Merge sort", "[merge_sort]")
{
  int arr[6] = {3, 4, 2, 1, 5, 1};

  merge_sort(arr, 6);

  REQUIRE(arr[0] == 1);
  REQUIRE(arr[1] == 1);
  REQUIRE(arr[2] == 2);
  REQUIRE(arr[3] == 3);
  REQUIRE(arr[4] == 4);
  REQUIRE(arr[5] == 5);
}