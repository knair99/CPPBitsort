#include <iostream>
#include <stdexcept>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <bitset>

using std::cout;        using std::cin;     using std::endl;        
using std::vector;      using std::size_t;  using std::bitset;

//Generate phone numbers
void generate_array(vector<long>& v){
    for(int i = 0; i < 9999999; i++){
       v.push_back(5120000000 + i); 
    }
    return;
}

//Shuffle up the phone numbers
void shuffle_array(vector<long>& v){
    srand(time(NULL));
    long range = 9999999;
    for(long int i = 0; i < v.size(); ++i){    
        long index1 =  (rand() * range) / RAND_MAX;
        long index2 =  (rand() * range) / RAND_MAX;
        long temp = v[index1];
        v[index1] = v[index2];
        v[index2] = temp;
    }
    return;
}

//Helper to print out numbers
void display_array(vector<long>& v){
    vector<long>::iterator i = v.begin();
    for(; i != v.end(); ++i){
        cout << *i << endl;
    }
}

//Sort the array using a bitvector
void sort_array(vector<long>& v){
    bitset<9999999UL>& bitvector = *(new bitset<9999999UL>());
    for(vector<long>::iterator i = v.begin(); i != v.end(); ++i){
        bitvector.set((*i- 5120000000), true);
    }

    v.clear();
    for(long i = 0; i < bitvector.size(); i++){
        if(bitvector.test(i)){
            v.push_back(5120000000 + i);
        }
    }
}

int main(int argc, char *argv[]){
    
    vector<long> v;
    generate_array(v);
    shuffle_array(v);
    sort_array(v);
    //display_array(v);
    return 0;    
}
