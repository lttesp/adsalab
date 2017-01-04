#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void FindSetCombination(vector<set<int>>& input, set<int>& target, vector<set<int>>& output)
{
    set<int> full;
    for(auto it: input){ 
        full.insert(it.begin(), it.end());
    }

    if(!includes(full.begin(), full.end(), target.begin(), target.end())){ 
        return;
    }

    for(int i = input.size() - 1; i > 0; --i){
        vector<bool> vec(input.size(), false);
        fill(vec.begin() + i, vec.end(), true);
        set<int> comb;

        do{
            for(int j = 0; j < vec.size(); ++j){
                if(vec[j]){
                    comb.insert(input[j].begin(),input[j].end());
                }
            }

            if(includes(comb.begin(), comb.end(), target.begin(), target.end())){
                for(int j = 0; j < vec.size(); ++j){
                    if(vec[j]){
                        output.push_back(input[j]);
                    }
                }
                return;
            }
            comb.clear();

        }while(next_permutation(vec.begin(), vec.end()));
    }
}

int main(int argc, char* argv[])
{
    int A[] = {1,2,3}; 
    int B[] = {2,5,8}; 
    int C[] = {1,4,5};
    int D[] = {3,5,8}; 
    int T[] = {3,4,8};

    set<int> s1(A, A + sizeof(A)/sizeof(int));
    set<int> s2(B, B + sizeof(B)/sizeof(int));
    set<int> s3(C, C + sizeof(C)/sizeof(int));
    set<int> s4(D, D + sizeof(D)/sizeof(int));
    set<int> t(T, T + sizeof(T)/sizeof(int));
    cout << "array to find " << endl;
    copy(t.begin(), t.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<set<int>> input, output;
    input.push_back(s1);
    input.push_back(s2);
    input.push_back(s3);
    input.push_back(s4);

    cout << "set of arrays " << endl;
    for(auto it: input){
        copy(it.begin(), it.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    FindSetCombination(input, t, output);

    cout << "output " << endl;
    for(auto it: output){
        copy(it.begin(), it.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
