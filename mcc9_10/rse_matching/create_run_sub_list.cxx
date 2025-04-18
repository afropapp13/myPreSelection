#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include <TFile.h>

using namespace std;

void create_run_sub_list() {

    //------------------------------------//

    // sample

    ofstream rse_list;

    rse_list.open("rse_run_sub_wcprocess.txt");
    TFile* f = TFile::Open("/exp/uboone/data/users/gardiner/MCC9.10_Test_Samples_v10_04_07_03_Run4b_pandora_standalone_reco2_BNB_beam_on_reco2_ana_goodruns.root", "readonly");
 
    //rse_list.open("rse_run_sub_standalone.txt");
    //TFile* f = TFile::Open("/exp/uboone/data/users/gardiner/MCC9.10_Test_Samples_v10_04_07_03_Run4b_pandora_standalone_reco2_BNB_beam_on_reco2_ana_goodruns.root", "readonly");
 

    TTree* t = (TTree*)(f->Get("nuselection/NeutrinoSelectionFilter"));

    int run, sub;
    int temp_run = 0, temp_sub = 0;
    TBranch  *b_run, *b_sub;

    t->SetBranchAddress("run", &run, &b_run);
    t->SetBranchAddress("sub", &sub, &b_sub);      

    int nentries = t->GetEntries();
    cout << "entries = " << nentries << endl;
    Long64_t nbytes = 0, nb = 0;  

    //------------------------------------//

    // loop over the sample entries

    for (int i = 0; i < nentries; i++ ) {

	    Long64_t i_entry = t->LoadTree(i);
	    nb = t->GetEntry(i);   
        nbytes += nb;

        //cout << "temp_run= " << temp_run <<  "run = " << run << endl;
        if (temp_run == run && temp_sub == sub) { continue; }

        rse_list << run;
        rse_list << " ";     
        rse_list << sub;       
        rse_list << "\n";      
        
        temp_run = run;
        temp_sub = sub;

    } // end of the loop over the mcc9_10 entries

    f->Close();

    //------------------------------------//       

}
