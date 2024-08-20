#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <chrono>
#include <cmath>
#include "include/lyndon_array.hpp"

using namespace std;
using namespace chrono;
using timer = chrono::high_resolution_clock;

int main(int argc, char** argv) {
  
  if(argc<2) return 0;

  char *c_file = NULL;
  c_file=argv[1];

  fstream File;
  File.open(c_file, ios::in);

  char sentinel = 0;

  string line, in;
  in += sentinel;

  if(File.is_open()){
    while(getline(File, line)) in += line;
    in += sentinel;
  }
  //cout<<in<<endl;
  File.close();

/*
  // need sentinel characters!
  std::string in("!amtrakairbusmississippi!");

  std::cout << "Input:  " << in << std::endl;
*/  
  std::vector<unsigned int> out (in.size());
  
  auto start = high_resolution_clock::now();
  lyndon_array(in.data(), out.data(), in.size());
  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<milliseconds>(stop - start);

  cout << in.size()/pow(2,20) << " MB\n";
  cout << "Time taken by function: " << duration.count()/1000.0 << " seconds" << endl;

  /*
  std::cout << "\nLyndon: "; 
  for(auto v : out.first) std::cout << v << " ";
  std::cout << std::endl;
  */

  return 0;  
}
