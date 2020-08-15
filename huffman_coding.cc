#include <string>
#include <vector>
#include <memory>
#include <queue>
#include <unordered_map>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::string;
using std::vector;
using std::shared_ptr;
using std::priority_queue;
using std::unordered_map;
using std::unique_ptr;
using std::make_unique;

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
        return lhs->aggregate_freq > rhs->aggregate_freq;
    }
};

void assignHuffmanCode(const shared_ptr<BinaryTree>& tree, const unique_ptr<string>& code, unordered_map<char, string>* huffman_encoding){
    if(tree){
        if(tree->s){
            (*huffman_encoding)[tree->s->c] = *code;
        } else{
            code->push_back('0');
            assignHuffmanCode(tree->left, code, huffman_encoding);
            code->back() = '1';
            assignHuffmanCode(tree->right, code, huffman_encoding);
            code->pop_back();
        }
    }

}

double HuffmanEncoding(vector<CharWithFrequency>* symbols) {
  priority_queue<shared_ptr<BinaryTree>, vector<shared_ptr<BinaryTree>>, FrequencyComparator> minpq;
  for(auto& s : *symbols){
      minpq.emplace(new BinaryTree{s.freq, &s, nullptr, nullptr});
  }
  while(minpq.size() > 1){
      auto left = minpq.top();
      minpq.pop();
      auto right = minpq.top();
      minpq.pop();
      minpq.emplace(new BinaryTree{left->aggregate_freq + right->aggregate_freq, nullptr, left, right});
  }
  unordered_map<char, string> huffman_encoding;
  assignHuffmanCode(minpq.top(), make_unique<string>(), &huffman_encoding);
  double avg = 0;
  for(const auto& s : *symbols){
      avg += huffman_encoding[s.c].size() * s.freq  / 100;
  }
  return avg;
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
