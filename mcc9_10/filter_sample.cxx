#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include <TFile.h>

using namespace std;

void filter_sample() {


    //------------------------------------//

    // mcc9.10 sample

    TFile* f_mcc9_10 = TFile::Open("/exp/uboone/data/users/eyandel/combined_reco/mcc910_test/checkout_bnb_data_run4b_v10_04_07_01_2000files.root", "readonly");
    TTree* t_mcc9_10 = (TTree*)(f_mcc9_10->Get("nuselection/NeutrinoSelectionFilter"));

    int mcc9_10_run, mcc9_10_sub, mcc9_10_evt;
    TBranch  *b_mcc9_10_run, *b_mcc9_10_sub, *b_mcc9_10_evt;

    t_mcc9_10->SetBranchAddress("run", &mcc9_10_run, &b_mcc9_10_run);
    t_mcc9_10->SetBranchAddress("sub", &mcc9_10_sub, &b_mcc9_10_sub);
    t_mcc9_10->SetBranchAddress("evt", &mcc9_10_evt, &b_mcc9_10_evt);    

    int mcc9_10_nentries = t_mcc9_10->GetEntries();
    //int mcc9_10_nentries = 100;
    cout << "mcc9_10 entries = " << mcc9_10_nentries << endl;
    Long64_t mcc9_10_nbytes = 0, mcc9_10_nb = 0;

    //------------------------------------//

    // mcc9 sample

    TFile* f_mcc9 = TFile::Open("/pnfs/uboone/persistent/users/cthorpe/PELEE_2023/run4b/run4b_bnb_beamon_crtremerging_pandora_reco2_run4b_ana.root", "readonly");    
    TTree* t_mcc9 = (TTree*)(f_mcc9->Get("nuselection/NeutrinoSelectionFilter"));

    int mcc9_run, mcc9_sub, mcc9_evt;
    TBranch  *b_mcc9_run, *b_mcc9_sub, *b_mcc9_evt;

    t_mcc9->SetBranchAddress("run", &mcc9_run, &b_mcc9_run);
    t_mcc9->SetBranchAddress("sub", &mcc9_sub, &b_mcc9_sub);
    t_mcc9->SetBranchAddress("evt", &mcc9_evt, &b_mcc9_evt); 

    int mcc9_nentries = t_mcc9->GetEntries();
    //int mcc9_nentries = 100;
    cout << "mcc9 entries = " << mcc9_nentries << endl;
    Long64_t mcc9_nbytes = 0, mcc9_nb = 0;    

    //------------------------------------//

    // mcc9 slimmed sample to be created    

    TString s_mcc9_slimmed = "/exp/uboone/data/users/apapadop/pelee_tuples_mcc9_10_slimmed/mcc9_slimmed.root";
    TFile* f_mcc9_slimmed = TFile::Open(s_mcc9_slimmed,"recreate");    
    TDirectory* d_mcc_9_slimmed = f_mcc9_slimmed->mkdir("nuselection");
    TTree* t_mcc9_slimmed = t_mcc9->CloneTree(0);
    Long64_t mcc9_slimmed_nbytes = 0, mcc9_slimmed_nb = 0;    

    //------------------------------------//

    // loop over the mcc9_10 entries

    for (int i_mcc9_10 = 0; i_mcc9_10 < mcc9_10_nentries; i_mcc9_10++ ) {

	    Long64_t i_mcc9_10_entry = t_mcc9_10->LoadTree(i_mcc9_10);
	    mcc9_10_nb = t_mcc9_10->GetEntry(i_mcc9_10);   
        mcc9_10_nbytes += mcc9_10_nb;
        //if (i_mcc9_10%1000 == 0) {
            
            //std::cout << "mcc9_10: " << i_mcc9_10/1000 << " k " << std::setprecision(3) << double(i_mcc9_10)/mcc9_10_nentries*100. << " %" << std::endl;

        //}

        // loop over the mcc9 entries

        for (int i_mcc9 = 0; i_mcc9 < mcc9_nentries; i_mcc9++ ) {

            Long64_t i_mcc9_entry = t_mcc9->LoadTree(i_mcc9);
            mcc9_nb = t_mcc9->GetEntry(i_mcc9);   
            mcc9_nbytes += mcc9_nb;
            if (i_mcc9%100000 == 0 && i_mcc9_10%1000 == 0) {
                
                std::cout << "mcc9_10: " << i_mcc9_10/1000 << " k " << std::setprecision(3) << double(i_mcc9_10)/mcc9_10_nentries*100. << " %" << std::endl;
                std::cout << "mcc9: " << i_mcc9/1000 << " k " << std::setprecision(3) << double(i_mcc9)/mcc9_nentries*100. << " %" << std::endl << endl;
    
            }            

            // make sure that the rub, sub, evt numbers are the same
            if ( mcc9_run == mcc9_10_run && mcc9_sub == mcc9_10_sub && mcc9_evt == mcc9_10_evt) {

                cout << "shared event i_mcc9 = " << i_mcc9 << " i_mcc9_10 = " << i_mcc9_10 << endl;
                f_mcc9_slimmed->cd();
                d_mcc_9_slimmed->cd();
                t_mcc9_slimmed->Fill(); 

            }

        } // end of the loop over the mcc9 entries            

    } // end of the loop over the mcc9_10 entries

    double mcc9_slimmed_nentries = t_mcc9_slimmed->GetEntries();
    cout << "mcc9_slimmed_nentries = " << mcc9_slimmed_nentries << endl;
    cout << s_mcc9_slimmed << endl;

    int mcc9_slimmed_run, mcc9_slimmed_sub, mcc9_slimmed_evt;
    TBranch  *b_mcc9_slimmed_run, *b_mcc9_slimmed_sub, *b_mcc9_slimmed_evt;

    t_mcc9_slimmed->SetBranchAddress("run", &mcc9_slimmed_run, &b_mcc9_slimmed_run);
    t_mcc9_slimmed->SetBranchAddress("sub", &mcc9_slimmed_sub, &b_mcc9_slimmed_sub);
    t_mcc9_slimmed->SetBranchAddress("evt", &mcc9_slimmed_evt, &b_mcc9_slimmed_evt);     

    //------------------------------------//   

    // Now go the other way around
    // Verify that the slimmed mcc9 file
    // and the new mcc9.10 files
    // have the exact same events
    // Thus we create a slimmed mcc9.10 file

    // mcc9.10 slimmed sample to be created    

    TString s_mcc9_10_slimmed = "/exp/uboone/data/users/apapadop/pelee_tuples_mcc9_10_slimmed/mcc9_10_slimmed.root";
    TFile* f_mcc9_10_slimmed = TFile::Open(s_mcc9_10_slimmed, "recreate");    
    TDirectory* d_mcc_9_10_slimmed = f_mcc9_10_slimmed->mkdir("nuselection");
    TTree* t_mcc9_10_slimmed = t_mcc9_10->CloneTree(0);

    // loop over the slimmed mcc9 entries

    for (int i_mcc9_slimmed = 0; i_mcc9_slimmed < mcc9_slimmed_nentries; i_mcc9_slimmed++ ) {

	    Long64_t i_mcc9_slimmed_entry = t_mcc9_slimmed->LoadTree(i_mcc9_slimmed);
	    mcc9_slimmed_nb = t_mcc9_slimmed->GetEntry(i_mcc9_slimmed);   
        mcc9_slimmed_nbytes += mcc9_slimmed_nb;
        //if (i_mcc9_slimmed%1000 == 0) {
            
            //std::cout << "mcc9_slimmed: " << i_mcc9_slimmed/1000 << " k " << std::setprecision(3) << double(i_mcc9_slimmed)slimmed_nentries*100. << " %" << std::endl;

        //}

        // loop over the mcc9.10 entries

        for (int i_mcc9_10 = 0; i_mcc9_10 < mcc9_10_nentries; i_mcc9_10++ ) {

            Long64_t i_mcc9_10_entry = t_mcc9_10->LoadTree(i_mcc9_10);
            mcc9_10_nb = t_mcc9_10->GetEntry(i_mcc9_10);   
            mcc9_10_nbytes += mcc9_10_nb;
            if (i_mcc9_10%100000 == 0) {
                
                std::cout << "mcc9_slimmed: " << i_mcc9_slimmed/1000 << " k " << std::setprecision(3) << double(i_mcc9_slimmed)/mcc9_slimmed_nentries*100. << " %" << std::endl << endl; 
                std::cout << "mcc9_10: " << i_mcc9_10/1000 << " k " << std::setprecision(3) << double(i_mcc9_10)/mcc9_10_nentries*100. << " %" << std::endl;
    
            }            

            // make sure that the rub, sub, evt numbers are the same
            if ( mcc9_slimmed_run == mcc9_10_run && mcc9_slimmed_sub == mcc9_10_sub && mcc9_slimmed_evt == mcc9_10_evt) {

                cout << "shared event i_mcc9_10 = " << i_mcc9_10 << " i_mcc9_slimmed = " << i_mcc9_slimmed << endl;
                f_mcc9_10_slimmed->cd();
                d_mcc_9_10_slimmed->cd();
                t_mcc9_10_slimmed->Fill(); 

            }

        } // end of the loop over the mcc9 entries            

    } // end of the loop over the mcc9_10 entries

    double mcc9_10_slimmed_nentries = t_mcc9_10_slimmed->GetEntries();
    cout << "mcc9_10_slimmed_nentries = " << mcc9_10_slimmed_nentries << endl;
    cout << s_mcc9_10_slimmed << endl;    

    f_mcc9_slimmed->Close();
    f_mcc9_10_slimmed->Close();    

    //------------------------------------//       

}
