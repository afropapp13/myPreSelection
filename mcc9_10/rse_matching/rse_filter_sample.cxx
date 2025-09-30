#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include <TFile.h>

using namespace std;

//---------------------------//

vector<string> split (string s, string delimiter) {

    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;
  
    while ( (pos_end = s.find (delimiter, pos_start)) != string::npos ) {
  
      token = s.substr (pos_start, pos_end - pos_start);
      pos_start = pos_end + delim_len;
      res.push_back (token);
  
    }
  
    res.push_back (s.substr (pos_start));
    return res;
  
  }
  
  //----------------------------------------//

void rse_filter_sample() {


    //------------------------------------//

    // sample in

    //TFile* f = TFile::Open("/exp/uboone/data/users/eyandel/combined_reco/mcc910_test/processed_checkout_root_files/MCC9.10_Test_Samples_v10_04_07_03_Run4b_super_unified_reco2_BNB_beam_on_reco2_hist.root", "readonly");
    //TString path_slimmed = "/exp/uboone/data/users/apapadop/pelee_tuples_mcc9_10_slimmed/wc_processed_rse_matched.root";

    TFile* f = TFile::Open("/exp/uboone/data/users/gardiner/MCC9.10_Test_Samples_v10_04_07_03_Run4b_pandora_standalone_reco2_BNB_beam_on_reco2_ana_goodruns.root", "readonly");
    TString path_slimmed = "/exp/uboone/data/users/apapadop/pelee_tuples_mcc9_10_slimmed/standalone_rse_matched.root";    
 
    TTree* t = (TTree*)(f->Get("nuselection/NeutrinoSelectionFilter"));
    //TTree* t_bdt = (TTree*)(f->Get("wcpselection/T_BDTvars"));
    //TTree* t_kine = (TTree*)(f->Get("wcpselection/T_KINEvars")); 

    int run, sub, evt;
    TBranch  *b_run, *b_sub, *b_evt;

    t->SetBranchAddress("run", &run);
    t->SetBranchAddress("sub", &sub);
    t->SetBranchAddress("evt", &evt);    

    int nentries = t->GetEntries();
    //int nentries = 1000;
    cout << "file entries = " << nentries << endl;
    Long64_t nbytes = 0, nb = 0;  

    //Long64_t bdt_nbytes = 0, bdt_nb = 0; 
    //Long64_t kine_nbytes = 0, kine_nb = 0; 

    //------------------------------------//

    TFile* f_slimmed = TFile::Open(path_slimmed,"recreate");    

    TDirectory* d_slimmed = f_slimmed->mkdir("nuselection");
    d_slimmed->cd();
    TTree* t_slimmed = t->CloneTree(0);  
    
    ///TDirectory* d_wc_slimmed = f_slimmed->mkdir("wcpselection");
    //d_wc_slimmed->cd();
    //TTree* t_bdt_slimmed = t_bdt->CloneTree(0);  
    //TTree* t_kine_slimmed = t_kine->CloneTree(0);          

    //------------------------------------//   

    // loop over the input entries

   for (int i = 0; i < nentries; i++ ) {

	    Long64_t i_entry = t->LoadTree(i);
	    nb = t->GetEntry(i);   
            nbytes += nb;

	    //Long64_t bdt_i_entry = t_bdt->LoadTree(i);
	    //bdt_nb = t_bdt->GetEntry(i);   
            //bdt_nbytes += bdt_nb;
        
	    //Long64_t kine_i_entry = t_kine->LoadTree(i);
	    //kine_nb = t_kine->GetEntry(i);   
            //kine_nbytes += kine_nb;        

        if (i%1000 == 0) {
            
            std::cout << "file entry: " << i/1000 << " k " << std::setprecision(3) << double(i)/nentries*100. << " %" << std::endl;

        }

        ifstream input("rse_list_overlap.txt"); 
        string line;
        while ( std::getline(input, line) ) {

            vector<string> words = split (line," "); // run,sub,evt, nu_e
           
            if ( words[0] == std::to_string(run) && words[1] == std::to_string(sub) && words[2] == std::to_string(evt)) {

                //std::cout << "Found match: " << run << " " << sub << " " << evt << std::endl;
                //f_slimmed->cd();
                //d_slimmed->cd();
                t_slimmed->Fill();

                //d_wc_slimmed->cd();
                //t_bdt_slimmed->Fill();                
                //t_kine_slimmed->Fill(); 

                continue;

            }

        }

        input.close();

    } // end of the loop over the file entries

    //------------------------------------//  

    //f_slimmed->cd();
    t_slimmed->Print();
    f_slimmed->Write();
    cout << path_slimmed << " created" << endl;
    cout << "TTree entries = " << t_slimmed->GetEntries() << endl;
    f_slimmed->Close();

    f->Close();

}
