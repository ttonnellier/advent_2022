#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ostream>
#include <vector>

template <class T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& values)
{
    stream << "[ ";
    std::copy(std::begin(values), std::end(values), std::ostream_iterator<T>(stream, " "));
    stream << ']';
    return stream;
}

template <typename T>
static std::vector<size_t> partial_sort_indexes(const std::vector<T>& v, const int N)
{
    std::vector<size_t> idx(v.size());
    std::iota(idx.begin(), idx.end(), 0);

    std::partial_sort(idx.begin(), idx.begin() + N, idx.end(), [&v](size_t i1, size_t i2) { return v[i1] > v[i2]; });

    return idx;
}
int main(int argc, char *argv[])
{
  std::ifstream is("day1.txt");

  std::string i;
  std::vector<double> v{0};
  while (getline(is, i))
    if (i == "")
      v.push_back(0);
    else
      v.back() += std::stod(i);

  auto it = std::max_element(v.begin(), v.end());
  std::cout << "Part1: " << *it << std::endl;

  auto indices = partial_sort_indexes(v, 3);
  std::cout << "Part2: " << v[indices[0]] + v[indices[1]]+ v[indices[2]] << std::endl;


  return 0;
}
