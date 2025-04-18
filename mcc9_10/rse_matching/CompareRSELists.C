#include "TROOT.h"
#include "TH1.h"
#include "TFile.h"
#include "TMath.h"
#include "TStyle.h"
#include "TF1.h"
#include "TTree.h"
#include "TImage.h"
#include "TCanvas.h"
#include <iostream> 
#include <fstream>  
#include <stdlib.h>

using namespace std;

void CompareRSELists(){

  

  ofstream overlapping_rse_file;
  overlapping_rse_file.open("rse_list_overlap.txt");

   std::map<std::tuple<int, int, int>,  float> events;
   float num_overlapping = 0;
  
  ifstream file1;
  file1.open("rse_list_standalone.txt");

  std::string line;
  while(getline(file1, line)){ //read data from file object and put it into string.
    std::stringstream linestream(line);
    int r, s, e;
    float energy;
    linestream >> r >> s >> e >> energy;

    events[std::make_tuple(r, s, e)] = energy;
  }

  file1.close();


  ifstream file2;
  file2.open("rse_list_wcprocess.txt");

  //std::string line;
  while(getline(file2, line)){ //read data from file object and put it into string.
    std::stringstream linestream(line);
    int r, s, e;
    float energy;
    linestream >> r >> s >> e >> energy;

    auto it = events.find(std::make_tuple(r,s,e));
    if (it != events.end()) {
        num_overlapping++;
        overlapping_rse_file<<r<<" "<<s<<" "<<e<<" "<<"\n";
    }
  }

  file2.close();

    std::cout<<"Number of overlapping events: "<<num_overlapping<<"\n";

  
overlapping_rse_file.close();

}
