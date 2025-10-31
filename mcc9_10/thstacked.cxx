#include <TFile.h>
#include <TTree.h>
#include <TDirectory.h>
#include <TChain.h>
#include <TGaxis.h>
#include <TROOT.h>
#include <TString.h>

using namespace std;

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>

#include "../../../generators/constants.h"
#include "../../../generators/helper_functions.cxx"

using namespace constants;

void thstacked() {

	//------------------------------//

	TH1D::SetDefaultSumw2();
	TH2D::SetDefaultSumw2();
	gStyle->SetOptStat(0);

	const int FontStyle = 132;
	const double TextSize = 0.04;

	TString run = "Run4b";

	//------------------------------//
	
	TString ttree_name = "myPreSelection";
	TString true_ttree_name = "myPreTruthSelection";	

	//dirt weight
	TString DirtWeight = "POTWeight * T2KWeight * ROOTinoWeight * Weight * ( (Weight > 0. && Weight < 30. && T2KWeight > 0. && T2KWeight < 30.)? T2KWeight:0.)";

	// extbnb weight
	TString extbnb_weight = "POTWeight";

	//mc weight
	TString MCWeight = "POTWeight * T2KWeight * ROOTinoWeight * Weight * ( (Weight > 0. && Weight < 30. && T2KWeight > 0. && T2KWeight < 30.)? T2KWeight:0.)";	

	//------------------------------//

	// data bnb files
	vector<TString> bnb_file_names;
	bnb_file_names.push_back("/exp/uboone/data/users/apapadop/ncpi0/PreSelection_mcc9_10_BeamOn9_"+run+"_unified.root");

	// extbnb files
	vector<TString> extbnb_file_names;
	extbnb_file_names.push_back("/exp/uboone/data/users/apapadop/ncpi0/PreSelection_mcc9_10_ExtBNB9_"+run+"_unified.root");
	
	// dirt files
	vector<TString> dirt_file_names;
	dirt_file_names.push_back("/exp/uboone/data/users/apapadop/ncpi0/PreSelection_mcc9_10_OverlayDirt9_"+run+"_unified.root");

	// mc
	vector<TString> file_names;
	file_names.push_back("/exp/uboone/data/users/apapadop/ncpi0/PreSelection_mcc9_10_Overlay9_"+run+"_unified.root");

	vector<TString> true_file_names;
	true_file_names.push_back("/exp/uboone/data/users/apapadop/ncpi0/PreTruthSelection_mcc9_10_Overlay9_"+run+"_unified.root");

	int nfiles = file_names.size();

	vector<TFile*> tfile; tfile.resize(nfiles);
	vector<TTree*> ttree; ttree.resize(nfiles);

	vector<TFile*> bnb_tfile; bnb_tfile.resize(nfiles);
	vector<TTree*> bnb_ttree; bnb_ttree.resize(nfiles);	

	vector<TFile*> extbnb_tfile; extbnb_tfile.resize(nfiles);
	vector<TTree*> extbnb_ttree; extbnb_ttree.resize(nfiles);	

	vector<TFile*> dirt_tfile; dirt_tfile.resize(nfiles);
	vector<TTree*> dirt_ttree; dirt_ttree.resize(nfiles);		
	
	vector<TFile*> true_tfile; true_tfile.resize(nfiles);		
	vector<TTree*> true_ttree; true_ttree.resize(nfiles);	

	//TString cuts = "(sum_reco_g1_blip_e_100cm < 8 && n_blip_pd_vtx_100cm_g1_anticone < 6 && wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta >= 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && two_shower_start_dist < 50 && reco_shower_opening_angle < 90 && wc_numu_score < 0.1 && wc_numu_score > -2. && dl_nTracks == 0 && (wc_shw_sp_n_20mev_showers == 2 || wc_shw_sp_n_20mev_showers == 3 && wc_shw_sp_n_br4_showers < 8) && (nspacepoints > 100 && nspacepoints < 400) && n_blip_pd_vtx_25cm_g1_anticone < 2 && gl_vertex_contained == 1)";
	TString cuts = "(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta >= 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && two_shower_start_dist < 50 && reco_shower_opening_angle < 90 && wc_numu_score < 0.1 && wc_numu_score > -2. && dl_nTracks == 0 && (wc_shw_sp_n_20mev_showers == 2 || wc_shw_sp_n_20mev_showers == 3 && wc_shw_sp_n_br4_showers < 8) && (nspacepoints > 100 && nspacepoints < 400) && n_blip_pd_vtx_25cm_g1_anticone < 2 && gl_vertex_contained == 1)";			
	//TString cuts = "(1>0)";			


	//------------------------------//

	// plots to loop over	

	vector<TString> plot_names; vector<double> min; vector<double> max; vector<int> nbins; vector<TString> cut;  vector<TString> cut_name;
	//plot_names.push_back("wc_kine_pio_energy_1"); min.push_back(-1); max.push_back(1000.); nbins.push_back(20); cut.push_back("(1>0)");	cut_name.push_back("nocuts");
	//plot_names.push_back("wc_kine_pio_energy_1"); min.push_back(-1); max.push_back(1000.); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0)");	cut_name.push_back("g1_non_zero_energy");
	//plot_names.push_back("wc_kine_pio_energy_2"); min.push_back(-1); max.push_back(1000.); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0)");	cut_name.push_back("g1_non_zero_energy");
	//plot_names.push_back("wc_kine_pio_energy_2"); min.push_back(-1); max.push_back(1000.); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0)");	cut_name.push_back("g2_non_zero_energy");
	//plot_names.push_back("wc_match_isFC"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0)");	cut_name.push_back("g2_non_zero_energy");
	//plot_names.push_back("wc_match_isFC"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1)"); cut_name.push_back("contained");
	//plot_names.push_back("wc_nc_pio_score"); min.push_back(-1.5); max.push_back(6.5); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && reco_pi0_costheta > 0.85)"); cut_name.push_back("contained");
	//plot_names.push_back("pd_reco_track_count"); min.push_back(-0.5); max.push_back(5.5); nbins.push_back(6); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && reco_pi0_costheta > 0.85 && wc_nc_pio_score >1.816)"); cut_name.push_back("ncpio_cut");
	//plot_names.push_back("reco_pi0_costheta"); min.push_back(0.85); max.push_back(1.); nbins.push_back(10); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && reco_pi0_costheta > 0.85 && wc_nc_pio_score >1.816)"); cut_name.push_back("no_pd_tracks");

	//plot_names.push_back("wc_primary_proton_counter"); min.push_back(-0.5); max.push_back(2.5); nbins.push_back(3); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && reco_pi0_costheta > 0.85 && wc_nc_pio_score > 1.816 && pd_reco_track_count == 0)"); cut_name.push_back("pd_reco_track_count");
	//plot_names.push_back("wc_secondary_proton_counter"); min.push_back(-0.5); max.push_back(2.5); nbins.push_back(3); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0 && wc_nc_pio_score > 1.816)"); cut_name.push_back("no_primary_protons");											
	//plot_names.push_back("wc_primary_muon_counter"); min.push_back(-0.5); max.push_back(4.5); nbins.push_back(5); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_nc_pio_score > 1.816)"); cut_name.push_back("no_primary_secondary_protons");
	//plot_names.push_back("wc_secondary_muon_counter"); min.push_back(-0.5); max.push_back(4.5); nbins.push_back(5); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_nc_pio_score > 1.816)"); cut_name.push_back("no_primary_muons");
	//plot_names.push_back("wc_primary_charged_pion_counter"); min.push_back(-0.5); max.push_back(4.5); nbins.push_back(5); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_nc_pio_score > 1.816)"); cut_name.push_back("no_primary_secondary_muons");
	//plot_names.push_back("wc_secondary_charged_pion_counter"); min.push_back(-0.5); max.push_back(4.5); nbins.push_back(5); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_nc_pio_score > 1.816)"); cut_name.push_back("no_primary_charged_pions");
	//plot_names.push_back("wc_primary_neutron_counter"); min.push_back(-0.5); max.push_back(4.5); nbins.push_back(5); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter == 0 && wc_nc_pio_score > 1.816)"); cut_name.push_back("no_primary_secondary_charged_pions");
	//plot_names.push_back("wc_secondary_neutron_counter"); min.push_back(-0.5); max.push_back(4.5); nbins.push_back(5); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nc_pio_score > 1.816)"); cut_name.push_back("no_primary_neutrons");
	//plot_names.push_back("wc_nprotontracks"); min.push_back(-0.5); max.push_back(4.5); nbins.push_back(5); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nc_pio_score > 1.816)"); cut_name.push_back("no_primary_neutrons");
	//plot_names.push_back("wc_nmuontracks"); min.push_back(-0.5); max.push_back(4.5); nbins.push_back(5); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nc_pio_score > 1.816)"); cut_name.push_back("no_wc_nprotontracks");
	//plot_names.push_back("wc_npiontracks"); min.push_back(-0.5); max.push_back(4.5); nbins.push_back(5); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nc_pio_score > 1.816)"); cut_name.push_back("no_wc_nmuontracks");	
	
	//plot_names.push_back("wc_nshowers"); min.push_back(0.5); max.push_back(9.5); nbins.push_back(9); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nc_pio_score > 1.816)"); cut_name.push_back("no_wc_nmuontracks");
	//plot_names.push_back("wc_nshowers"); min.push_back(0.5); max.push_back(9.5); nbins.push_back(9); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && wc_nc_pio_score > 1.816)"); cut_name.push_back("low_wc_nshowers");
	//plot_names.push_back("pd_reco_shower_count"); min.push_back(0.5); max.push_back(4.5); nbins.push_back(4); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && wc_nc_pio_score > 1.816)"); cut_name.push_back("low_wc_nshowers");	
	//plot_names.push_back("pd_reco_shower_count"); min.push_back(0.5); max.push_back(9.5); nbins.push_back(9); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && wc_nc_pio_score > 1.816)"); cut_name.push_back("low_pd_nshowers");			
	
	//plot_names.push_back("Vertex_X"); min.push_back(0.); max.push_back(FVx); nbins.push_back(26); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("Vertex_Y"); min.push_back(-FVy/2.); max.push_back(FVy/2.); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("Vertex_Z"); min.push_back(0.); max.push_back(FVz); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("g1_start_x"); min.push_back(0.); max.push_back(FVx); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("g2_start_x"); min.push_back(0.); max.push_back(FVx); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");									
	//plot_names.push_back("g1_start_y"); min.push_back(-FVy/2.); max.push_back(FVy/2.); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("g2_start_y"); min.push_back(-FVy/2.); max.push_back(FVy/2.); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");	
	//plot_names.push_back("g1_start_z"); min.push_back(0.); max.push_back(FVz); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("g2_start_z"); min.push_back(0.); max.push_back(FVz); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");	
	//plot_names.push_back("g1_end_x"); min.push_back(0.); max.push_back(FVx); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("g2_end_x"); min.push_back(0.); max.push_back(FVx); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("g1_end_y"); min.push_back(-FVy/2.); max.push_back(FVy/2.); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("g2_end_y"); min.push_back(-FVy/2.); max.push_back(FVy/2.); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");	
	//plot_names.push_back("g1_end_z"); min.push_back(0.); max.push_back(FVz); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("wc_vertex_contained"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("wc_vertex_contained"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && wc_vertex_contained == 1)"); cut_name.push_back("wc_vertex_contained");	
	//plot_names.push_back("pd_vertex_contained"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && wc_vertex_contained == 1)"); cut_name.push_back("wc_vertex_contained");
	//plot_names.push_back("g1_start_contained"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && wc_vertex_contained == 1 && pd_vertex_contained == 1)"); cut_name.push_back("pd_vertex_contained");
	//plot_names.push_back("g2_start_contained"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && wc_vertex_contained == 1 && pd_vertex_contained == 1 && g1_start_contained == 1)"); cut_name.push_back("g1_start_contained");
	//plot_names.push_back("g1_end_contained"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && wc_vertex_contained == 1 && pd_vertex_contained == 1 && g1_start_contained == 1 && g2_start_contained == 1)"); cut_name.push_back("g2_start_contained");
	//plot_names.push_back("g2_end_contained"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && wc_vertex_contained == 1 && pd_vertex_contained == 1 && g1_start_contained == 1 && g2_start_contained == 1 && g1_end_contained == 1)"); cut_name.push_back("g1_end_contained");
	//plot_names.push_back("wc_nc_pio_score"); min.push_back(-1.5); max.push_back(6.5); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && wc_vertex_contained == 1 && pd_vertex_contained == 1 && g1_start_contained == 1 && g2_start_contained == 1 && g1_end_contained == 1 && g2_end_contained == 1)"); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("wc_nc_pio_score"); min.push_back(-1.5); max.push_back(6.5); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && wc_vertex_contained == 1 && pd_vertex_contained == 1 && g1_start_contained == 1 && g2_start_contained == 1 && g1_end_contained == 1 && g2_end_contained == 1 && wc_nc_pio_score > 1.816)"); cut_name.push_back("wc_nc_pio_score");		

	//plot_names.push_back("two_shower_start_dist"); min.push_back(0.); max.push_back(150); nbins.push_back(15); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3)"); cut_name.push_back("no_wc_npiontracks");	
	//plot_names.push_back("reco_shower_opening_angle"); min.push_back(ArrayNBinstwo_shower_angle[0]); max.push_back(ArrayNBinstwo_shower_angle[NBinstwo_shower_angle]); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && two_shower_start_dist < 50)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("reco_pi0_costheta"); min.push_back(0.85); max.push_back(1.); nbins.push_back(10); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && two_shower_start_dist < 50 && reco_shower_opening_angle < 90)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("reco_pi0_p"); min.push_back(0.); max.push_back(1.); nbins.push_back(10); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && two_shower_start_dist < 50 && reco_shower_opening_angle < 90)"); cut_name.push_back("no_wc_npiontracks");		
	//plot_names.push_back("wc_secondary_neutron_counter"); min.push_back(-0.5); max.push_back(4.5); nbins.push_back(5); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && two_shower_start_dist < 50 && reco_shower_opening_angle < 90)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("wc_nshowers_0MeV"); min.push_back(0.5); max.push_back(12.5); nbins.push_back(11); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && two_shower_start_dist < 50 && reco_shower_opening_angle < 90)"); cut_name.push_back("no_wc_npiontracks");	
	//plot_names.push_back("wc_nshowers"); min.push_back(0.5); max.push_back(5.5); nbins.push_back(5); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && two_shower_start_dist < 50 && reco_shower_opening_angle < 90)"); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("reco_pi0_costheta"); min.push_back(0.85); max.push_back(1.); nbins.push_back(10); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	plot_names.push_back("reco_pi0_p"); min.push_back(0.); max.push_back(1.); nbins.push_back(10); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");	
	//plot_names.push_back("pd_shr_score"); min.push_back(-1); max.push_back(2.); nbins.push_back(10); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("wc_numu_score"); min.push_back(-2.5); max.push_back(1.); nbins.push_back(35); cut.push_back(cuts);	cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("wc_single_photon_numu_score"); min.push_back(-2.); max.push_back(3.); nbins.push_back(20); cut.push_back(cuts);cut_name.push_back("no_wc_npiontracks");		
	//plot_names.push_back("wc_numu_cc_flag"); min.push_back(0.5); max.push_back(1.5); nbins.push_back(1); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("reco_deltapt"); min.push_back(0.); max.push_back(.4); nbins.push_back(10); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("n_blip_pd_vtx_100cm"); min.push_back(0.); max.push_back(40.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("n_blip_pd_vtx_25cm"); min.push_back(-0.5); max.push_back(10.5); nbins.push_back(11); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("n_blip_pd_vtx_50cm"); min.push_back(-0.5); max.push_back(15.5); nbins.push_back(16); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");		
	//plot_names.push_back("flipped_showers"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");			
	//plot_names.push_back("wc_kine_pio_energy_1"); min.push_back(0.); max.push_back(1000.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("wc_kine_pio_energy_2"); min.push_back(0.); max.push_back(1000.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");	

	//plot_names.push_back("wc_nshowers_20MeV"); min.push_back(0.5); max.push_back(12.5); nbins.push_back(12); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("wc_shw_sp_n_good_showers"); min.push_back(0.5); max.push_back(3.5); nbins.push_back(3.); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("wc_shw_sp_n_20mev_showers"); min.push_back(0.5); max.push_back(4.5); nbins.push_back(4); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("wc_shw_sp_n_br1_showers"); min.push_back(0.5); max.push_back(11.5); nbins.push_back(11); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("wc_shw_sp_n_br2_showers"); min.push_back(0.5); max.push_back(11.5); nbins.push_back(11); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("wc_shw_sp_n_br3_showers"); min.push_back(0.5); max.push_back(6.5); nbins.push_back(6); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("wc_shw_sp_n_br4_showers"); min.push_back(-0.5); max.push_back(9.5); nbins.push_back(10); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("wc_shw_sp_n_20br1_showers"); min.push_back(0.5); max.push_back(5.5); nbins.push_back(5); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");						

	//plot_names.push_back("dl_nTracks"); min.push_back(-0.5); max.push_back(5.5); nbins.push_back(6); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("dl_foundVertex"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("dl_vtxScore"); min.push_back(0.); max.push_back(1.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");		
	//plot_names.push_back("dl_nSecShowers"); min.push_back(-0.5); max.push_back(5.5); nbins.push_back(6); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");						

	//plot_names.push_back("wc_single_photon_numu_score"); min.push_back(-1.4); max.push_back(2.5); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("two_shower_start_dist");
	//plot_names.push_back("wc_single_photon_nue_score"); min.push_back(-2.); max.push_back(2.5); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("two_shower_start_dist");		
	//plot_names.push_back("wc_single_photon_ncpi0_score"); min.push_back(-4.); max.push_back(1.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("wc_nc_pio_score");
	//plot_names.push_back("wc_single_photon_other_score"); min.push_back(-1.5); max.push_back(3.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("wc_nc_pio_score");
	//plot_names.push_back("wc_numu_score"); min.push_back(-2.5); max.push_back(.5); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("wc_nc_pio_score");	

	//plot_names.push_back("wc_numu_score"); min.push_back(-2.5); max.push_back(1.); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && wc_vertex_contained == 1 && pd_vertex_contained == 1 && g1_start_contained == 1 && g2_start_contained == 1 && g1_end_contained == 1 && g2_end_contained == 1 && wc_nc_pio_score > 1.816)"); cut_name.push_back("wc_nc_pio_score");	
	//plot_names.push_back("wc_kine_pio_flag"); min.push_back(-0.5); max.push_back(3.5); nbins.push_back(4); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && wc_vertex_contained == 1 && pd_vertex_contained == 1 && g1_start_contained == 1 && g2_start_contained == 1 && g1_end_contained == 1 && g2_end_contained == 1)"); cut_name.push_back("g2_end_contained");	
	//plot_names.push_back("reco_pi0_p"); min.push_back(0.); max.push_back(1.); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && wc_vertex_contained == 1 && pd_vertex_contained == 1 && g1_start_contained == 1 && g2_start_contained == 1 && g1_end_contained == 1 && g2_end_contained == 1)"); cut_name.push_back("g2_end_contained");		
	//plot_names.push_back("reco_g1_p"); min.push_back(0.); max.push_back(1.5); nbins.push_back(20); cut.push_back("(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta > 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && wc_vertex_contained == 1 && pd_vertex_contained == 1 && g1_start_contained == 1 && g2_start_contained == 1 && g1_end_contained == 1 && g2_end_contained == 1)"); cut_name.push_back("");	
	//plot_names.push_back("reco_g1_costheta"); min.push_back(0.); max.push_back(1.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("reco_g2_costheta"); min.push_back(-1.); max.push_back(1.); nbins.push_back(20); cut.push_back("()"); cut_name.push_back("");
	//plot_names.push_back("reco_g2_p"); min.push_back(0.); max.push_back(1.5); nbins.push_back(20); cut.push_back("()"); cut_name.push_back("");	
	//plot_names.push_back("nspacepoints"); min.push_back(50.); max.push_back(450.); nbins.push_back(8); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("trecchargeblob_spacepoints_x"); min.push_back(-0.5); max.push_back(209.5); nbins.push_back(10); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("trecchargeblob_spacepoints_q"); min.push_back(-0.5); max.push_back(20009.5); nbins.push_back(10); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("wc_larpid_process"); min.push_back(-0.5); max.push_back(2.5); nbins.push_back(3); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("true_neutron_ke"); min.push_back(0.); max.push_back(.5); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("true_neutron_ke"); min.push_back(0.); max.push_back(.1); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");	
	//plot_names.push_back("true_proton_ke"); min.push_back(0.); max.push_back(.05); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");						
	//plot_names.push_back("reco_pi0_costheta"); min.push_back(-1); max.push_back(1); nbins.push_back(1); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("true_sum_proton_ke"); min.push_back(0.); max.push_back(.1); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");	
	//plot_names.push_back("true_sum_neutron_ke"); min.push_back(0.); max.push_back(.5); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");		
	//plot_names.push_back("sp_q_median"); min.push_back(1000.); max.push_back(3000); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("neutron_q_median"); min.push_back(0.); max.push_back(8000); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("photon_q_median"); min.push_back(0.); max.push_back(4500); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("gl_trackstub_num_candidates"); min.push_back(-0.5); max.push_back(9.5); nbins.push_back(10); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("gl_trackstub_candidate_veto_score"); min.push_back(-0.5); max.push_back(109.5); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");	
	//plot_names.push_back("Blip_energy"); min.push_back(0.); max.push_back(12.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	
	//plot_names.push_back("n_blip_pd_vtx_25cm_g1_anticone"); min.push_back(-0.5); max.push_back(4.5); nbins.push_back(5); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("n_blip_pd_vtx_50cm_g1_anticone"); min.push_back(-0.5); max.push_back(9.5); nbins.push_back(10); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("n_blip_pd_vtx_100cm_g1_anticone"); min.push_back(-0.5); max.push_back(19.5); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");

	//plot_names.push_back("n_blip_pd_vtx_25cm_g2_anticone"); min.push_back(-0.5); max.push_back(5.5); nbins.push_back(6); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("n_blip_pd_vtx_50cm_g2_anticone"); min.push_back(-0.5); max.push_back(14.5); nbins.push_back(15); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("n_blip_pd_vtx_100cm_g2_anticone"); min.push_back(-0.5); max.push_back(29.5); nbins.push_back(15); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	
	//plot_names.push_back("pd_slcng2mip"); min.push_back(0.); max.push_back(20); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_slcng2hip"); min.push_back(0.); max.push_back(100.); nbins.push_back(15); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_slcng2shr"); min.push_back(-0.5); max.push_back(1600.5); nbins.push_back(15); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_slcng2mcl"); min.push_back(-0.5); max.push_back(20.5); nbins.push_back(15); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_slcng2dfs"); min.push_back(0.); max.push_back(200.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_slcng2bkg"); min.push_back(0.); max.push_back(200.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_clung2mip"); min.push_back(0.); max.push_back(40.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_clung2hip"); min.push_back(0.); max.push_back(40.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_clung2shr"); min.push_back(-0.5); max.push_back(1000.5); nbins.push_back(15); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_clung2mcl"); min.push_back(0.); max.push_back(40.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_clung2dfs"); min.push_back(0.); max.push_back(100.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_clung2bkg"); min.push_back(0); max.push_back(50); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_pfng2semlabel"); min.push_back(0.); max.push_back(20.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_pfng2mipfrac"); min.push_back(0.); max.push_back(2.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_pfng2hipfrac"); min.push_back(0.); max.push_back(10.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_pfng2shrfrac"); min.push_back(0.5); max.push_back(1.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_pfng2mclfrac"); min.push_back(0.); max.push_back(1.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_pfng2dfsfrac"); min.push_back(0.); max.push_back(0.2); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_pfng2bkgfrac"); min.push_back(0.); max.push_back(1.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_pfng2mipavrg"); min.push_back(0.); max.push_back(.1); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_pfng2hipavrg"); min.push_back(0.); max.push_back(1.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_pfng2shravrg"); min.push_back(0.); max.push_back(1.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_pfng2mclavrg"); min.push_back(0.); max.push_back(1.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_pfng2dfsavrg"); min.push_back(0.); max.push_back(0.2); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_pfng2bkgavrg"); min.push_back(0.); max.push_back(1.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");		

	//plot_names.push_back("gl_vertex_contained"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("dl_vertex_contained"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	
	//plot_names.push_back("pd_wc_vtx_dist"); min.push_back(0.); max.push_back(50.); nbins.push_back(25); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("pd_gl_vtx_dist"); min.push_back(0.); max.push_back(15.); nbins.push_back(25); cut.push_back(cuts); cut_name.push_back("g2_end_contained");		
	//plot_names.push_back("pd_dl_vtx_dist"); min.push_back(0.); max.push_back(50.); nbins.push_back(25); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("wc_gl_vtx_dist"); min.push_back(0.); max.push_back(50.); nbins.push_back(25); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("wc_dl_vtx_dist"); min.push_back(0.); max.push_back(50.); nbins.push_back(25); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("gl_dl_vtx_dist"); min.push_back(0.); max.push_back(50.); nbins.push_back(25); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	
	//plot_names.push_back("sum_reco_g1_blip_e_25cm"); min.push_back(0.6); max.push_back(4.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("sum_reco_g1_blip_e_50cm"); min.push_back(0.6); max.push_back(50.); nbins.push_back(25); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("sum_reco_g1_blip_e_100cm"); min.push_back(0.6); max.push_back(50.); nbins.push_back(25); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	
	//plot_names.push_back("sum_reco_g2_blip_e_25cm"); min.push_back(0.6); max.push_back(10.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("sum_reco_g2_blip_e_50cm"); min.push_back(0.6); max.push_back(50.); nbins.push_back(25); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("sum_reco_g2_blip_e_100cm"); min.push_back(0.6); max.push_back(50.); nbins.push_back(25); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	
	//plot_names.push_back("gl_sss_num_candidates"); min.push_back(-0.5); max.push_back(9.5); nbins.push_back(10); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("gl_reco_asso_tracks"); min.push_back(-0.5); max.push_back(9.5); nbins.push_back(10); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("gl_reco_asso_showers"); min.push_back(-0.5); max.push_back(2.5); nbins.push_back(3); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	
	//plot_names.push_back("Blip_g1_cos_alpha"); min.push_back(-1); max.push_back(1); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("Blip_g2_cos_alpha"); min.push_back(-1); max.push_back(1); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("Blip_vt_cos_alpha"); min.push_back(-1); max.push_back(1); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("g2_end_contained");	
	
	//plot_names.push_back("reco_contains_proton"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("reco_contains_neutron"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back(cuts); cut_name.push_back("g2_end_contained");		
	//plot_names.push_back("Blip_proxtrkdist"); min.push_back(0.); max.push_back(300.); nbins.push_back(30); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("Good_blip_proxtrkdist"); min.push_back(10.); max.push_back(150.); nbins.push_back(28); cut.push_back(cuts); cut_name.push_back("g2_end_contained");	
	//plot_names.push_back("Blip_nplanes"); min.push_back(-0.5); max.push_back(3.5); nbins.push_back(4); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("Blip_touchtrk"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("Blip_pl2_bydeadwire"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("Blip_pl1_bydeadwire"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("Blip_pl0_bydeadwire"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("Blip_x"); min.push_back(-100); max.push_back(350.); nbins.push_back(25); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	//plot_names.push_back("Blip_y"); min.push_back(-250); max.push_back(250); nbins.push_back(25); cut.push_back(cuts); cut_name.push_back("g2_end_contained");	
	//plot_names.push_back("Blip_z"); min.push_back(-50.); max.push_back(1250); nbins.push_back(53); cut.push_back(cuts); cut_name.push_back("g2_end_contained");
	
	//plot_names.push_back("reco_g1_length_z"); min.push_back(0.); max.push_back(200.); nbins.push_back(25); cut.push_back(cuts); cut_name.push_back("g2_end_contained");


	int nplots = plot_names.size();

	//------------------------------//

	// vector of vectors

	vector< vector<THStack*> > stack; stack.resize(nfiles);
	vector< vector<TLegend*> > leg; leg.resize(nfiles);
	vector< vector<TCanvas*> > can; can.resize(nfiles);
	vector< vector< vector<TH1D*> > > h; h.resize(nfiles);
	vector<TH1D*> true_h; true_h.resize(nfiles); // one per file bc we will use the same var		

	//------------------------------//

	// signal & bkg categories

	vector<TString> topo; 
	topo.push_back("signal");
	topo.push_back("bkg_1n_0p_1pi0_X");
	topo.push_back("bkg_Nn_0p_1pi0_X");	
	topo.push_back("bkg_0pi0_X");
	topo.push_back("bkg_Mpi0_X");
	topo.push_back("bkg_bwds_1pi0_X");
	topo.push_back("bkg_1p_0n_1pi0_X");
	topo.push_back("bkg_Np_0n_1pi0_X");
	topo.push_back("bkg_1pi0_Npipm_X");
	topo.push_back("bkg_1pi0_Np_Nn_0pipm_X");
	topo.push_back("bkg_1pi0_Np_Nn_Npipm_X");
	topo.push_back("bkg_1pi0_Nmh_X");
	topo.push_back("bkg_1pi0_Nl_X");
	topo.push_back("bkg_other");	
	int ntopo = topo.size();	

	//------------------------------//	

	int colors[14] = {
		kMagenta,   
		kGreen+2,		
		kOrange+7,      
		kBlue+1,   
		kBlack,   
		kCyan+1,  
		kRed+1,   
		kViolet+1,
		kSpring+4,
		kTeal+2,  
		kAzure+1,  
		kPink+5,      // 12
		kGray+2,      // 13
		kYellow+1     // 14
	};

	const int NColors = 14;
	int coffeeColors[NColors];

	// RGB values scaled from [0–255] to [0–1]
	double red[NColors] = {
		59/255.,  87/255., 119/255., 160/255., 199/255., 224/255., 242/255.,
		210/255., 168/255., 126/255., 94/255., 68/255., 47/255., 35/255.
	};

	double green[NColors] = {
		41/255.,  58/255.,  79/255., 112/255., 157/255., 191/255., 225/255.,
		191/255., 145/255., 103/255., 74/255., 51/255., 35/255., 25/255.
	};

	double blue[NColors] = {
		33/255.,  45/255.,  58/255.,  78/255., 117/255., 165/255., 207/255.,
		178/255., 119/255., 73/255.,  53/255., 38/255.,  28/255., 20/255.
	};

	// Create TColor entries and store their indices
	for (int i = 0; i < NColors; ++i) {
		coffeeColors[i] = TColor::GetFreeColorIndex();
		new TColor(coffeeColors[i], red[i], green[i], blue[i]);
	}

	//------------------------------//
		
	// loop over the files 
	for (int ifile = 0; ifile < nfiles; ifile++) {

		tfile.at(ifile) = new TFile(file_names.at(ifile),"readonly");
		bnb_tfile.at(ifile) = new TFile(bnb_file_names.at(ifile),"readonly");
		extbnb_tfile.at(ifile) = new TFile(extbnb_file_names.at(ifile),"readonly");	
		dirt_tfile.at(ifile) = new TFile(dirt_file_names.at(ifile),"readonly");				
		true_tfile.at(ifile) = new TFile(true_file_names.at(ifile),"readonly");		

		if (!tfile.at(ifile) || tfile.at(ifile)->IsZombie()) {
			std::cerr << "Error: could not open file " << file_names.at(ifile) << std::endl;
			continue;
		}		

		bnb_ttree.at(ifile) = (TTree*)(bnb_tfile.at(ifile)->Get(ttree_name));				
		ttree.at(ifile) = (TTree*)(tfile.at(ifile)->Get(ttree_name));	
		extbnb_ttree.at(ifile) = (TTree*)(extbnb_tfile.at(ifile)->Get(ttree_name));	
		dirt_ttree.at(ifile) = (TTree*)(dirt_tfile.at(ifile)->Get(ttree_name));					
		true_ttree.at(ifile) = (TTree*)(true_tfile.at(ifile)->Get(true_ttree_name));		

		stack.at(ifile).resize(nplots);
		can.at(ifile).resize(nplots);		
		leg.at(ifile).resize(nplots);
		h.at(ifile).resize(nplots);
		
		TString true_hname = "true";
		true_h.at(ifile) = new TH1D(true_hname,";", 20, -1., 1.);	
		true_ttree.at(ifile)->Draw("pi0_MCParticle_CosTheta>>" + true_hname,"(1>0)*" + MCWeight,"goff");				

		//loop over the plots
		for (int iplot = 0; iplot < nplots; iplot++) {

			TString stack_name = "stack_" + plot_names.at(iplot);
			stack.at(ifile).at(iplot) = new THStack(stack_name,stack_name);

			TString canvas_name = "canvas_" + plot_names.at(iplot);
			can.at(ifile).at(iplot) = new TCanvas(canvas_name,canvas_name,205,34,1024,768);		
			can.at(ifile).at(iplot)->cd();
			can.at(ifile).at(iplot)->SetTopMargin(0.18);
			can.at(ifile).at(iplot)->SetLeftMargin(0.13);
			can.at(ifile).at(iplot)->SetBottomMargin(0.1);		
			can.at(ifile).at(iplot)->Draw();
			
			leg.at(ifile).at(iplot) = new TLegend(0.01,0.825,0.97,0.99);
			leg.at(ifile).at(iplot)->SetBorderSize(0);
			leg.at(ifile).at(iplot)->SetNColumns(3);
			leg.at(ifile).at(iplot)->SetTextSize(0.026);	
			leg.at(ifile).at(iplot)->SetTextFont(FontStyle);
			leg.at(ifile).at(iplot)->SetMargin(0.11);	

			// +1 for the extbnb
			// +2 for the dirt			
			// +3 for the bnb
			h.at(ifile).at(iplot).resize(ntopo+3);			
			
			// loop over the topo categories
			for (int itopo = 0; itopo < ntopo; itopo++) {	

				TString hname = topo.at(itopo) + "_" + plot_names.at(iplot);
				h.at(ifile).at(iplot).at(itopo) = new TH1D(hname,";" + plot_names.at(iplot), nbins.at(iplot), min.at(iplot), max.at(iplot) );
				ttree.at(ifile)->Draw(plot_names.at(iplot) + ">>" + hname,"(" + cut.at(iplot) + " && " + topo.at(itopo) + ")*" + MCWeight,"goff");
				
				h.at(ifile).at(iplot).at(itopo)->SetTitle("");
				
				if (itopo == 0 || itopo == 1 || itopo == 2) {

					h.at(ifile).at(iplot).at(itopo)->SetLineColor(colors[itopo]);
					h.at(ifile).at(iplot).at(itopo)->SetFillColor(colors[itopo]);					

				} else {
				
					int color = coffeeColors[(itopo-3) % NColors];
					h.at(ifile).at(iplot).at(itopo)->SetLineColor(color);
					h.at(ifile).at(iplot).at(itopo)->SetFillColor(color);
					
				}						

				stack.at(ifile).at(iplot)->Add(h.at(ifile).at(iplot).at(itopo),"hist");		


			} // end of the loop over the topo categories

			TH1D* nocosmic_hstack = (TH1D*)(stack.at(ifile).at(iplot)->GetStack()->Last() );	
			TH1D* nocosmic_clone = (TH1D*)nocosmic_hstack->Clone("nocosmic_clone");		

			// ----------------- //

			// ext bnb

			TString extbnb_hname = "extbnb_" + plot_names.at(iplot);
			h.at(ifile).at(iplot).at(ntopo) = new TH1D(extbnb_hname,";" + plot_names.at(iplot), nbins.at(iplot), min.at(iplot), max.at(iplot) );
			extbnb_ttree.at(ifile)->Draw(plot_names.at(iplot) + ">>" + extbnb_hname,"(" + cut.at(iplot) + ")*" + extbnb_weight,"goff");
			h.at(ifile).at(iplot).at(ntopo)->SetTitle("");
			h.at(ifile).at(iplot).at(ntopo)->SetLineColor(kGray);
			h.at(ifile).at(iplot).at(ntopo)->SetFillColor(kGray);
			h.at(ifile).at(iplot).at(ntopo)->SetFillStyle(3004);								
			stack.at(ifile).at(iplot)->Add(h.at(ifile).at(iplot).at(ntopo),"hist");		

			// ----------------- //

			// dirt

			TString dirt_hname = "dirt_" + plot_names.at(iplot);
			h.at(ifile).at(iplot).at(ntopo+1) = new TH1D(dirt_hname,";" + plot_names.at(iplot), nbins.at(iplot), min.at(iplot), max.at(iplot) );
			dirt_ttree.at(ifile)->Draw(plot_names.at(iplot) + ">>" + dirt_hname,"(" + cut.at(iplot) + ")*" + DirtWeight,"goff");
			h.at(ifile).at(iplot).at(ntopo+1)->SetTitle("");
			h.at(ifile).at(iplot).at(ntopo+1)->SetLineColor(kRed+2);
			h.at(ifile).at(iplot).at(ntopo+1)->SetFillColor(kRed+2);
			stack.at(ifile).at(iplot)->Add(h.at(ifile).at(iplot).at(ntopo+1),"hist");		

			// ----------------- //

			// bnb

			TString bnb_hname = "bnb_" + plot_names.at(iplot);
			h.at(ifile).at(iplot).at(ntopo+2) = new TH1D(bnb_hname,";" + plot_names.at(iplot), nbins.at(iplot), min.at(iplot), max.at(iplot) );
			bnb_ttree.at(ifile)->Draw(plot_names.at(iplot) + ">>" + bnb_hname,"(" + cut.at(iplot) + ")","goff");
			h.at(ifile).at(iplot).at(ntopo+2)->SetTitle("");
			h.at(ifile).at(iplot).at(ntopo+2)->SetLineColor(kBlack);
			h.at(ifile).at(iplot).at(ntopo+2)->SetMarkerColor(kBlack);
			h.at(ifile).at(iplot).at(ntopo+2)->SetMarkerStyle(20);								

			// ----------------- //			

			int nhists = stack.at(ifile).at(iplot)->GetNhists();

			stack.at(ifile).at(iplot)->SetTitle("");			
			stack.at(ifile).at(iplot)->Draw("");

			stack.at(ifile).at(iplot)->GetHistogram()->GetXaxis()->SetTitle(plot_names.at(iplot));			

			stack.at(ifile).at(iplot)->GetHistogram()->GetXaxis()->SetTitleFont(FontStyle);
			stack.at(ifile).at(iplot)->GetHistogram()->GetXaxis()->SetTitleSize(TextSize);	
			stack.at(ifile).at(iplot)->GetHistogram()->GetXaxis()->CenterTitle();
			stack.at(ifile).at(iplot)->GetHistogram()->GetXaxis()->SetLabelFont(FontStyle);
			stack.at(ifile).at(iplot)->GetHistogram()->GetXaxis()->SetLabelSize(TextSize);
			stack.at(ifile).at(iplot)->GetHistogram()->GetXaxis()->SetNdivisions(8);
			stack.at(ifile).at(iplot)->GetHistogram()->GetXaxis()->SetLabelOffset(0.01);									
			
			stack.at(ifile).at(iplot)->GetHistogram()->GetYaxis()->SetTitleFont(FontStyle);
			stack.at(ifile).at(iplot)->GetHistogram()->GetYaxis()->SetTitleSize(TextSize);	
			stack.at(ifile).at(iplot)->GetHistogram()->GetYaxis()->CenterTitle();
			stack.at(ifile).at(iplot)->GetHistogram()->GetYaxis()->SetLabelFont(FontStyle);
			stack.at(ifile).at(iplot)->GetHistogram()->GetYaxis()->SetLabelSize(TextSize);	
			stack.at(ifile).at(iplot)->GetHistogram()->GetYaxis()->SetNdivisions(8);	
			stack.at(ifile).at(iplot)->GetHistogram()->GetYaxis()->SetLabelOffset(0.01);	

			//double max = 1.1* TMath::Max(stack.at(ifile).at(iplot)->GetHistogram()->GetMaximum(), h.at(ifile).at(iplot).at(ntopo+2)->GetMaximum());
			//stack.at(ifile).at(iplot)->GetHistogram()->SetMaximum(max);

			// pot
			stack.at(ifile).at(iplot)->GetHistogram()->GetYaxis()->SetTitle( run + " events [" + pot_sci_notation(run + "_unified", 2) + " POT]");			
			
			// data
			h.at(ifile).at(iplot).at(ntopo+2)->Draw("same ex0");

			//max
			double max = TMath::Max(h.at(ifile).at(iplot).at(ntopo+2)->GetMaximum(), stack.at(ifile).at(iplot)->GetHistogram()->GetMaximum() );
			stack.at(ifile).at(iplot)->SetMinimum(0.);
			stack.at(ifile).at(iplot)->SetMaximum(1.3*max);				
			gPad->Modified();
			gPad->Update();		

			TH1D* hstack = (TH1D*)(stack.at(ifile).at(iplot)->GetStack()->Last() );

			// loop over the mc topo categories			
			for (int itopo = 0; itopo < ntopo; itopo++) {	

				TString evt = to_string_with_precision(h.at(ifile).at(iplot).at(itopo)->Integral(),2.);				
				TString frac = to_string_with_precision(h.at(ifile).at(iplot).at(itopo)->Integral() / hstack->Integral() * 100.,1.);
				leg.at(ifile).at(iplot)->AddEntry(h.at(ifile).at(iplot).at(itopo), topo.at(itopo) + " (" + frac +"%) [" + evt + "]","f");				

			} // end of the loop over the topo categories	

			// ----------------- //

			// total mc legend

			TString mc_evt = to_string_with_precision(nocosmic_clone->Integral(),2.);				
			TString mc_frac = to_string_with_precision(nocosmic_clone->Integral() / hstack->Integral() * 100.,1.);
			leg.at(ifile).at(iplot)->AddEntry(nocosmic_clone, "total mc (" + mc_frac +"%) [" + mc_evt + "]","");	
						
			// ----------------- //

			// ext bnb legend

			TString extbnb_evt = to_string_with_precision(h.at(ifile).at(iplot).at(ntopo)->Integral(),2.);				
			TString extbnb_frac = to_string_with_precision(h.at(ifile).at(iplot).at(ntopo)->Integral() / hstack->Integral() * 100.,1.);
			leg.at(ifile).at(iplot)->AddEntry(h.at(ifile).at(iplot).at(ntopo), "cosmics (" + extbnb_frac +"%) [" + extbnb_evt + "]","f");
			
			// ----------------- //

			// dirt legend

			TString dirt_evt = to_string_with_precision(h.at(ifile).at(iplot).at(ntopo+1)->Integral(),2.);				
			TString dirt_frac = to_string_with_precision(h.at(ifile).at(iplot).at(ntopo+1)->Integral() / hstack->Integral() * 100.,1.);
			leg.at(ifile).at(iplot)->AddEntry(h.at(ifile).at(iplot).at(ntopo+1), "dirt (" + dirt_frac +"%) [" + dirt_evt + "]","f");			
			
			// ----------------- //

			// bnb legend

			TString bnb_evt = to_string_with_precision(h.at(ifile).at(iplot).at(ntopo+2)->Integral(),2.);				
			leg.at(ifile).at(iplot)->AddEntry(h.at(ifile).at(iplot).at(ntopo+2), "BNB data [" + bnb_evt + "]","p");				
			
			// ----------------- //			

			leg.at(ifile).at(iplot)->Draw();

			TH1D* reco_h = new TH1D("h_reco_"+plot_names.at(iplot),";" + plot_names.at(iplot), 1, -1, 1 );
			ttree.at(ifile)->Draw("reco_pi0_costheta >> h_reco_"+plot_names.at(iplot),"(" + cut.at(iplot) + " && signal == 1)*" + MCWeight,"goff");			
			
			TLatex *efftext = new TLatex();
			efftext->SetTextFont(FontStyle);
			efftext->SetTextSize(TextSize);
//			TString eff = to_string_with_precision(h.at(ifile).at(iplot).at(0)->Integral() / true_h.at(0)->Integral() * 100.,1.);	
			TString eff = to_string_with_precision(reco_h->Integral() / true_h.at(0)->Integral() * 100.,1.);			
			TString eff_latex_text = "eff = " + eff + "%";			
			efftext->DrawLatexNDC(0.75, 0.75,eff_latex_text);			

			can.at(ifile).at(iplot)->SaveAs(plot_path + canvas_name + "_" + cut_name.at(iplot) + "_" + run + ".pdf");

		
		} // end of the loop over the plots
	
	} // end of the loop over the files

	//------------------------------//

} // end of the program