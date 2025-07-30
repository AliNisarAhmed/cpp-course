#include "rapidcsv.h"
#include <algorithm>
#include <cmath>
#include <format>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>

int main() {
  rapidcsv::Document titanic{"titanic.csv", rapidcsv::LabelParams{},
                             rapidcsv::SeparatorParams{},
                             rapidcsv::ConverterParams{true}};

  auto survived{titanic.GetColumn<int>("survived")};
  auto sex{titanic.GetColumn<std::string>("sex")};
  auto age{titanic.GetColumn<double>("age")};
  auto pclass{titanic.GetColumn<int>("pclass")};

  std::cout << std::format("First five rows:\n{:<10}{:<8}{:<6}{}\n", "survived",
                           "sex", "age", "class");
  for (size_t i{0}; i < 5; ++i) {
    std::cout << std::format("{:<10}{:<8}{:<6.1f}{}\n", survived.at(i),
                             sex.at(i), age.at(i), pclass.at(i));
  }
  std::cout << std::format("\nLast five rows:\n{:<10}{:<8}{:<6}{}\n",
                           "survived", "sex", "age", "class");
  const auto count{titanic.GetRowCount()};
  for (size_t i{count - 5}; i < count; ++i) {
    std::cout << std::format("{:<10}{:<8}{:<6.1f}{}\n", survived.at(i),
                             sex.at(i), age.at(i), pclass.at(i));
  }

  // creates a "stream" pipeline
  auto removeNaN{
      age | std::views::filter([](const auto &x) { return !std::isnan(x); })};

  // initializes cleanAge from the begin of removeNaN pipeline to the end of the
  // pipeline
  std::vector<double> cleanAge{std::begin(removeNaN), std::end(removeNaN)};

  std::sort(std::begin(cleanAge), std::end(cleanAge));
  size_t size{cleanAge.size()};

  double median{};
  if (size % 2 == 0) {
    median = (cleanAge.at(size / 2 - 1) + cleanAge.at(size / 2)) / 2;
  } else {
    median = cleanAge.at(size / 2);
  }

  std::cout << "\nDescriptive stats for the age column:\n"
            << std::format("Passengers with age data:{}\n", size)
            << std::format("Avg age: {:.2f}\n",
                           std::accumulate(std::begin(cleanAge),
                                           std ::end(cleanAge), 0.0) /
                               size)
            << std::format("Min Age: {:.2f}\n", cleanAge.front())
            << std::format("Max Age: {:.2f}\n", cleanAge.back())
            << std::format("Median age: {:.2f}\n", median);

  auto countClass{[](const auto &column, const int classNumber) {
    return std::ranges::count_if(
        column, [classNumber](int x) { return classNumber == x; });
  }};

  constexpr int firstClass{1};
  constexpr int secondClass{2};
  constexpr int thirdClass{3};
  const auto firstCount{countClass(pclass, firstClass)};
  const auto secondCount{countClass(pclass, secondClass)};
  const auto thirdCount{countClass(pclass, thirdClass)};

  std::cout << "\nPassenger counts by class:\n"
            << std::format("1st: {}\n2nd: {}\n3rd: {}\n\n", firstCount,
                           secondCount, thirdCount);

  const auto survivorCount{
      std::ranges::count_if(survived, [](auto x) { return x; })};
  std::cout << std::format("Survived count: {}\nDied cound: {}\n",
                           survivorCount, survived.size() - survivorCount);
  std::cout << std::format("Percent who survived: {:.2f}%\n\n",
                           100.0 * survivorCount / survived.size());

  int survivingMales{0};
  int survivingFemales{0};
  int surviving1st{0};
  int surviving2nd{0};
  int surviving3rd{0};

  for (size_t i{0}; i < survived.size(); ++i) {
    if (survived.at(i)) {
      sex.at(i) == "female" ? ++survivingFemales : ++survivingMales;

      if (firstClass == pclass.at(i)) {
        ++surviving1st;
      } else if (secondClass == pclass.at(i)) {
        ++surviving2nd;
      } else {
        ++surviving3rd;
      }
    }
  }
  std::cout << std::format("Female survivor: {:.2f}%\n",
                           100.0 * survivingFemales / survivorCount)
            << std::format("Male survivor: {:.2f}\n",
                           100.0 * survivingMales / survivorCount)
            << std::format("1st class survivor: {:.2f}\n",
                           100.0 * surviving1st / survivorCount)
            << std::format("2nd class survivor: {:.2f}\n",
                           100.0 * surviving2nd / survivorCount)
            << std::format("3rd class survivor: {:.2f}\n",
                           100.0 * surviving3rd / survivorCount);
}
