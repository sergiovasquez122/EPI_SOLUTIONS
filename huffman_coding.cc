#include <string>
#include <vector>
#include <memory>
#include <queue>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::string;
using std::vector;
using std::shared_ptr;
using std::priority_queue;

namespace huffman {

struct CharWithFrequency {
  char c;
  double freq;
};

struct BinaryTree{
    double aggregate_freq;
    CharWithFrequency* s;
    shared_ptr<BinaryTree> left, right;
};

struct FrequencyComparator{
    bool operator()(const shared_ptr<BinaryTree>& lhs, const shared_ptr<BinaryTree>& rhs){
        return lhs->aggregate_freq < rhs->aggregate_freq;
    }
};

double HuffmanEncoding(vector<CharWithFrequency>* symbols) {
  priority_queue<shared_ptr<BinaryTree>, vector<shared_ptr<BinaryTree>>, FrequencyComparator> minpq;
  while(minpq.size() > 1){
      auto left = minpq.top();
      minpq.pop();
      auto right = minpq.top();
      minpq.pop();
      minpq.emplace(new BinaryTree{left->aggregate_freq + right->aggregate_freq, nullptr, left, right});
  }

  return 0.0;
}

}  // namespace huffman
namespace test_framework {
template <>
struct SerializationTrait<huffman::CharWithFrequency>
    : UserSerTrait<huffman::CharWithFrequency, std::string, double> {
  static huffman::CharWithFrequency FromTuple(
      const std::tuple<std::string, double>& values) {
    if (std::get<0>(values).size() != 1) {
      throw std::runtime_error(
          "CharWithFrequency parser: string length is not 1");
    }
    return huffman::CharWithFrequency{std::get<0>(values)[0],
                                      std::get<1>(values)};
  }
};
}  // namespace test_framework

double HuffmanEncodingWrapper(vector<huffman::CharWithFrequency> symbols) {
  return huffman::HuffmanEncoding(&symbols);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"symbols"};
  return GenericTestMain(args, "huffman_coding.cc", "huffman_coding.tsv",
                         &HuffmanEncodingWrapper, DefaultComparator{},
                         param_names);
}
