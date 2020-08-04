#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int merge(vector<int>& a, int lo, int mid, int hi, vector<int>& aux){
    int i = lo, j = mid + 1;
    for(int k = lo;k <= hi; k++)
        aux[k] = a[k];

    int inversions = 0;
    for(int k = lo;k <= hi; k++){
        if(i > mid) a[k] = aux[j++];
        else if(j > hi) a[k] = aux[i++];
        else if(aux[i] <= aux[j]) a[k] = aux[i++];
        else{
            inversions += mid - i + 1;
            a[k] = aux[j++];
        }
    }
    return inversions;
}

int sort(vector<int>& A, int lo, int hi, vector<int>& aux){
    if(hi <= lo) return 0;
    int mid = lo + (hi - lo) / 2;
    int left_inversions = sort(A, lo, mid, aux);
    int right_inversions = sort(A, mid + 1, hi, aux);
    return merge(A, lo, mid,hi, aux) + left_inversions + right_inversions;
}



int CountInversions(vector<int> A) {
  vector<int> aux(A.size(), 0);
  return sort(A, 0, A.size() - 1,aux);
}


int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "count_inversions.cc", "count_inversions.tsv",
                         &CountInversions, DefaultComparator{}, param_names);
}
