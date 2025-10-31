#define mcc9_10_neutrino_selection_cxx
#include "mcc9_10_neutrino_selection.h"
#include <TH1.h>
#include <TH2.h>
#include <TStyle.h>
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TString.h>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "../../../generators/Tools.h"
#include "../../../generators/helper_functions.cxx"

using namespace std;
using namespace constants;

//--------------------//

void mcc9_10_neutrino_selection::Loop() {

	//--------------------//

	TH1D::SetDefaultSumw2();
	TH2D::SetDefaultSumw2();

	//--------------------//

	// output files

	TString FileName = preselection_file_path + "/PreSelection_"+fLabel+".root";
	TFile* OutputFile = new TFile(FileName,"recreate");
	std::cout << std::endl << "File " << FileName << " to be created"<< std::endl << std::endl;

	//--------------------//

	if (fChain == 0) return;

	Long64_t nentries = fChain->GetEntriesFast();
	cout << "file entries = " << nentries << endl;
	Long64_t nbytes = 0, nb = 0;
	Long64_t wc_nbytes = 0, wc_nb = 0;  
	Long64_t gl_vtx_nbytes = 0, gl_vtx_nb = 0;
	Long64_t dl_nbytes = 0, dl_nb = 0;		
	Long64_t wc_kine_nbytes = 0, wc_kine_nb = 0;	  	
	Long64_t wc_eval_nbytes = 0, wc_eval_nb = 0;  		
	Long64_t wc_pfeval_nbytes = 0, wc_pfeval_nb = 0;  		
	Long64_t wc_sp_nbytes = 0, wc_sp_nb = 0; 	

	//--------------------//

	// TTree

	TTree* tree = new TTree("myPreSelection","myPreSelection");

	//--------------------//

	double Weight;
	double T2KWeight;
	double ROOTinoWeight;
	double POTWeight;

	float wc_single_photon_numu_score;
	float wc_single_photon_other_score;
	float wc_single_photon_ncpi0_score;
	float wc_single_photon_nue_score;
	float wc_numu_score;
	float wc_nc_pio_score;
	float wc_kine_pio_vtx_dis;
	float wc_kine_pio_energy_1;
	float wc_kine_pio_theta_1;
	float wc_kine_pio_phi_1;
	float wc_kine_pio_energy_2;
	float wc_kine_pio_theta_2;
	float wc_kine_pio_phi_2;
	bool wc_match_isFC;
	int wc_kine_pio_flag;
	float wc_numu_cc_flag;	

    // wc ntuple truth-matching variables

	vector<double> neutron_truthMatch_p;
	vector<double> proton_truthMatch_p;	
	vector<double> neutron_truthMatch_ke;
	vector<double> proton_truthMatch_ke;			

	int g1_truthMatch_pdg;
	double g1_truthMatch_p;
	double g1_truthMatch_px;
	double g1_truthMatch_py;
	double g1_truthMatch_pz;
	double g1_truthMatch_costheta;
	double g1_truthMatch_phi; // rad		
	
	int g2_truthMatch_pdg;
	double g2_truthMatch_p;
	double g2_truthMatch_px;
	double g2_truthMatch_py;
	double g2_truthMatch_pz;
	double g2_truthMatch_costheta;
	double g2_truthMatch_phi; // rad		

	int nspacepoints;
	vector<double>  trecchargeblob_spacepoints_x;
	vector<double>  trecchargeblob_spacepoints_y;
	vector<double>  trecchargeblob_spacepoints_z;
	vector<double>  trecchargeblob_spacepoints_q;
	vector<double>  trecchargeblob_spacepoints_real_cluster_id;	
	double sp_q_median;
	vector<double> photon_q_median;		
	vector<double> neutron_q_median;			

	vector<int> wc_kine_particle_type;
	vector<float> wc_kine_energy_particle;

	int Run;
	int SubRun;
	int Event;
	TString run_period;

	int signal;
	int nc;
	int numu;
	int qe;
	int mec;
	int res;
	int dis;
	int coh;
	int other;
	int nupdg;	

	double true_sum_neutron_ke;
	std::vector<double> true_neutron_ke;
	double true_sum_proton_ke;		
	std::vector<double> true_proton_ke;	

	// X = any other particle
	// M >= 2
	// N >= 1
	int bkg_0pi0_X;
	int bkg_Mpi0_X;
	int bkg_bwds_1pi0_X;		
	int bkg_1n_0p_1pi0_X;	
	int bkg_Nn_0p_1pi0_X;
	int bkg_1p_0n_1pi0_X;	
	int bkg_Np_0n_1pi0_X;	
	int bkg_1pi0_Npipm_X;	
	int bkg_1pi0_Np_Nn_0pipm_X;
	int bkg_1pi0_Np_Nn_Npipm_X;		
	int bkg_1pi0_Nmh_X; // m = mesons (mostly etas), h = heavy particles (Sigmas, Lambdas)	
	int bkg_1pi0_Nl_X; // l = lepton		
	int bkg_other;	

	bool truth_contains_neutron;
	bool reco_contains_neutron;	
	bool truth_contains_proton;
	bool reco_contains_proton;
	bool truth_contains_proton_or_neutron;
	bool reco_contains_proton_or_neutron;			

	std::vector<unsigned short> All_UBGenie;
	std::vector<double> AxFFCCQEshape_UBGenie;
	std::vector<double> DecayAngMEC_UBGenie;
	std::vector<double> NormCCCOH_UBGenie;
	std::vector<double> NormNCCOH_UBGenie;
	std::vector<double> RPA_CCQE_UBGenie;
	std::vector<double> ThetaDelta2NRad_UBGenie;
	std::vector<double> Theta_Delta2Npi_UBGenie;
	std::vector<double> VecFFCCQEshape_UBGenie;
	std::vector<double> XSecShape_CCMEC_UBGenie;

	std::vector<unsigned short> fluxes;
	std::vector<unsigned short> reinteractions;
	
	int MCParticle_Mode;

	double True_Ev;
	double True_Vx;
	double True_Vy;
	double True_Vz;

	int wc_primary_proton_counter = 0;
	int wc_primary_muon_counter = 0;
	int wc_primary_charged_pion_counter = 0;
	int wc_primary_electron_counter = 0;
	int wc_primary_photon_counter = 0;
	int wc_primary_neutron_counter = 0;
	int wc_primary_neutral_pion_counter = 0;

	int wc_secondary_proton_counter = 0;
	int wc_secondary_muon_counter = 0;
	int wc_secondary_charged_pion_counter = 0;
	int wc_secondary_electron_counter = 0;
	int wc_secondary_photon_counter = 0;
	int wc_secondary_neutron_counter = 0;
	int wc_secondary_neutral_pion_counter = 0;	

	int wc_nshowers = 0;
	int wc_nshowers_0MeV = 0;
	int wc_nshowers_20MeV = 0;		
	int wc_nmuontracks = 0;
	int wc_nprotontracks = 0;
	int wc_npiontracks = 0;

	float wc_shw_sp_n_good_showers;
	float wc_shw_sp_n_20mev_showers;
	float wc_shw_sp_n_br1_showers;
	float wc_shw_sp_n_br2_showers;
	float wc_shw_sp_n_br3_showers;
	float wc_shw_sp_n_br4_showers;
	float wc_shw_sp_n_20br1_showers;	

	//--------------------//

	float ns_time;
	int slice_id;
	float orig_nuscore;
	float NuScore;
	float FlashScore; 
	float fCosmicIPAll3D;
	float fCosmicDirAll3D;
	int fcrtveto;
	float fcrthitpe;
	float pd_shr_score;

	int wc_reco_g1_id;
	int wc_reco_g2_id;	

	//--------------------//

	// wc reco info

	std::vector<int> wc_reco_larpid_process;	
	std::vector<int> wc_reco_mother;
	std::vector< std::vector<float> > wc_reco_p;
	std::vector< std::vector<float> > wc_reco_start;
	std::vector< std::vector<float> > wc_reco_end;
	std::vector<int> wc_reco_pdg;
	std::vector<int> wc_reco_id;	

	int wc_temp_g1_id;
	int wc_temp_g2_id;			

	//--------------------//

	// wc vertex

	std::vector<float> Vertex_X;
	std::vector<float> Vertex_Y;
	std::vector<float> Vertex_Z;
	int wc_vertex_contained;

	//--------------------//

	// pandora vertex

	std::vector<float> pd_vertex_x;
	std::vector<float> pd_vertex_y;
	std::vector<float> pd_vertex_z;	
	int pd_vertex_contained;

	//--------------------//

	// pandora nugraph
	
   Int_t           pd_slcng2mip;
   Int_t           pd_slcng2hip;
   Int_t           pd_slcng2shr;
   Int_t           pd_slcng2mcl;
   Int_t           pd_slcng2dfs;
   Int_t           pd_slcng2bkg;
   Int_t           pd_clung2mip;
   Int_t           pd_clung2hip;
   Int_t           pd_clung2shr;
   Int_t           pd_clung2mcl;
   Int_t           pd_clung2dfs;
   Int_t           pd_clung2bkg;
   vector<int>     pd_pfng2semlabel;
   vector<float>   pd_pfng2mipfrac;
   vector<float>   pd_pfng2hipfrac;
   vector<float>   pd_pfng2shrfrac;
   vector<float>   pd_pfng2mclfrac;
   vector<float>   pd_pfng2dfsfrac;
   vector<float>   pd_pfng2bkgfrac;
   vector<float>   pd_pfng2mipavrg;
   vector<float>   pd_pfng2hipavrg;
   vector<float>   pd_pfng2shravrg;
   vector<float>   pd_pfng2mclavrg;
   vector<float>   pd_pfng2dfsavrg;
   vector<float>   pd_pfng2bkgavrg;	

	//--------------------//

	// pi0

	std::vector<double> reco_shower_opening_angle;
	std::vector<double> reco_alpha;

	std::vector<double> reco_pi0_p_gammas;
	std::vector<double> reco_pi0_p;
	std::vector<double> reco_pi0_phi; // rad
	std::vector<double> reco_pi0_costheta;
	std::vector<double> reco_cm_costheta;
	std::vector<double> reco_deltapt;		
	std::vector<double> reco_pi0_invmass;	

	//--------------------//

	// leading gamma (g1)

	std::vector<double> reco_g1_p;
	std::vector<double> reco_g1_phi; // rad
	std::vector<double> reco_g1_costheta;
	double reco_g1_length;
	double reco_g1_length_x;
	double reco_g1_length_y;
	double reco_g1_length_z;			

	double g1_start_x;
	double g1_start_y;
	double g1_start_z;	
	int g1_start_contained;
	
	double g1_end_x;
	double g1_end_y;
	double g1_end_z;	
	int g1_end_contained;

	//--------------------//

	// secondary gamma (g2)	

	std::vector<double> reco_g2_p;
	std::vector<double> reco_g2_phi; // rad
	std::vector<double> reco_g2_costheta;
	double reco_g2_length;
	double reco_g2_length_x;
	double reco_g2_length_y;
	double reco_g2_length_z;			

	double g2_start_x;
	double g2_start_y;
	double g2_start_z;	
	int g2_start_contained;

	double g2_end_x;
	double g2_end_y;
	double g2_end_z;
	int g2_end_contained;	

	double two_shower_start_dist;
	double two_shower_end_dist;	
	bool flipped_showers;
	
	//--------------------//

	// Blip info

	Int_t           ngood_blips;	
	Int_t           nBlips_saved;
	vector<float>   Blip_g1_cos_alpha;
	vector<float>   Blip_g2_cos_alpha;
	vector<float>   Blip_vt_cos_alpha;		
	vector<float>   Good_blip_ds;
	vector<float>   Blip_dx;
	vector<float>   Blip_dw;	
	vector<float>   Blip_x;
	vector<float>   Blip_y;
	vector<float>   Blip_z;
	vector<float>   Blip_energy;
	vector<float>   Good_blip_energy;	
	vector<float>   Blip_charge;
	vector<int>     Blip_nplanes;
	vector<float>   Blip_proxtrkdist;
	vector<float>   Good_blip_proxtrkdist;	
	vector<int>     Blip_proxtrkid;
	vector<bool>    Blip_touchtrk;
	vector<int>     Blip_touchtrkid;
	vector<int>     Blip_pl0_nwires;
	vector<int>     Blip_pl1_nwires;
	vector<int>     Blip_pl2_nwires;
	vector<bool>    Blip_pl0_bydeadwire;
	vector<bool>    Blip_pl1_bydeadwire;
	vector<bool>    Blip_pl2_bydeadwire;
	vector<int>     Blip_true_pdg;
	vector<int>     Blip_true_g4id;
	vector<float>   Blip_true_energy;
	int n_blip_pd_vtx_25cm;
	int n_blip_pd_vtx_50cm;	
	int n_blip_pd_vtx_100cm;
	int n_blip_pd_vtx_25cm_g1_anticone;
	int n_blip_pd_vtx_50cm_g1_anticone;	
	int n_blip_pd_vtx_100cm_g1_anticone;
	int n_blip_pd_vtx_25cm_g1_cone;
	int n_blip_pd_vtx_50cm_g1_cone;	
	int n_blip_pd_vtx_100cm_g1_cone;
	int n_blip_pd_vtx_25cm_g2_anticone;
	int n_blip_pd_vtx_50cm_g2_anticone;	
	int n_blip_pd_vtx_100cm_g2_anticone;
	int n_blip_pd_vtx_25cm_g2_cone;
	int n_blip_pd_vtx_50cm_g2_cone;	
	int n_blip_pd_vtx_100cm_g2_cone;
	double sum_reco_g1_blip_e_25cm;
	double sum_reco_g2_blip_e_25cm;
	double sum_reco_g1_blip_e_50cm;
	double sum_reco_g2_blip_e_50cm;	
	double sum_reco_g1_blip_e_100cm;
	double sum_reco_g2_blip_e_100cm;				

	//--------------------//

	// Pandora info

	vector<unsigned int> pd_generation_v;
	vector<float> pd_trk_score_v;
	vector<float> pd_trk_llr_pid_score_v;

	int pd_reco_track_count;
	int pd_reco_shower_count;

	int pd_reco_secondary_track_count;
	int pd_reco_secondary_shower_count;	

	//--------------------//

	// glee

	vector<double>  gl_trackstub_candidate_veto_score;	
	int gl_trackstub_num_candidates;
	Double_t        gl_reco_vertex_x;
	Double_t        gl_reco_vertex_y;
	Double_t        gl_reco_vertex_z;
	bool gl_vertex_contained;	
   	Int_t gl_sss_num_candidates;
   	Int_t gl_reco_asso_showers;
   	Int_t gl_reco_asso_tracks;			

	//--------------------//

	// dl lantern

	int dl_foundVertex;
	float dl_vtxX;
	float dl_vtxY;
	float dl_vtxZ;
	float dl_vtxScore;  
	int dl_nTracks;
	int dl_nSecTracks; 
	int dl_nShowers;
	int dl_nSecShowers;		
	bool dl_vertex_contained;

	//--------------------//

	// distance between different reco vertices

	double pd_wc_vtx_dist;
	double pd_gl_vtx_dist;	
	double pd_dl_vtx_dist;
	double wc_gl_vtx_dist;
	double wc_dl_vtx_dist;	
	double gl_dl_vtx_dist;	

	//--------------------//

	tree->Branch("Weight",&Weight);
	tree->Branch("T2KWeight",&T2KWeight);
	tree->Branch("ROOTinoWeight",&ROOTinoWeight);	
	tree->Branch("POTWeight",&POTWeight);	

	tree->Branch("wc_single_photon_numu_score",&wc_single_photon_numu_score);
	tree->Branch("wc_single_photon_other_score",&wc_single_photon_other_score);
	tree->Branch("wc_single_photon_ncpi0_score",&wc_single_photon_ncpi0_score);
	tree->Branch("wc_single_photon_nue_score",&wc_single_photon_nue_score);

	tree->Branch("wc_numu_score",&wc_numu_score);
	tree->Branch("wc_nc_pio_score",&wc_nc_pio_score);
	tree->Branch("wc_kine_pio_vtx_dis",&wc_kine_pio_vtx_dis);
	tree->Branch("wc_kine_pio_energy_1",&wc_kine_pio_energy_1);
	tree->Branch("wc_kine_pio_theta_1",&wc_kine_pio_theta_1);
	tree->Branch("wc_kine_pio_phi_1",&wc_kine_pio_phi_1);
	tree->Branch("wc_kine_pio_energy_2",&wc_kine_pio_energy_2);
	tree->Branch("wc_kine_pio_theta_2",&wc_kine_pio_theta_2);
	tree->Branch("wc_kine_pio_phi_2",&wc_kine_pio_phi_2);
	tree->Branch("wc_match_isFC",&wc_match_isFC);
	tree->Branch("wc_kine_pio_flag",&wc_kine_pio_flag);
	tree->Branch("wc_numu_cc_flag",&wc_numu_cc_flag);	
	tree->Branch("wc_kine_particle_type",&wc_kine_particle_type);
	tree->Branch("wc_kine_energy_particle",&wc_kine_energy_particle);

	tree->Branch("nspacepoints",&nspacepoints);
	tree->Branch("trecchargeblob_spacepoints_x",&trecchargeblob_spacepoints_x);	
	tree->Branch("trecchargeblob_spacepoints_y",&trecchargeblob_spacepoints_y);	
	tree->Branch("trecchargeblob_spacepoints_z",&trecchargeblob_spacepoints_z);	
	tree->Branch("trecchargeblob_spacepoints_q",&trecchargeblob_spacepoints_q);	
	tree->Branch("trecchargeblob_spacepoints_real_cluster_id",&trecchargeblob_spacepoints_real_cluster_id);
	tree->Branch("sp_q_median",&sp_q_median);
	tree->Branch("photon_q_median",&photon_q_median);
	tree->Branch("neutron_q_median",&neutron_q_median);							

	tree->Branch("Run",&Run);
	tree->Branch("SubRun",&SubRun);
	tree->Branch("Event",&Event);	
	tree->Branch("run_period",&run_period);
	tree->Branch("nupdg",&nupdg);	

	tree->Branch("signal",&signal);
	tree->Branch("nc",&nc);
	tree->Branch("numu",&numu);
	tree->Branch("qe",&qe);
	tree->Branch("mec",&mec);
	tree->Branch("res",&res);
	tree->Branch("dis",&dis);
	tree->Branch("coh",&coh);
	tree->Branch("other",&other);

	tree->Branch("bkg_0pi0_X",&bkg_0pi0_X);
	tree->Branch("bkg_Mpi0_X",&bkg_Mpi0_X);
	tree->Branch("bkg_bwds_1pi0_X",&bkg_bwds_1pi0_X);
	tree->Branch("bkg_1n_0p_1pi0_X",&bkg_1n_0p_1pi0_X);			
	tree->Branch("bkg_Nn_0p_1pi0_X",&bkg_Nn_0p_1pi0_X);
	tree->Branch("bkg_1p_0n_1pi0_X",&bkg_1p_0n_1pi0_X);
	tree->Branch("bkg_Np_0n_1pi0_X",&bkg_Np_0n_1pi0_X);
	tree->Branch("bkg_1pi0_Npipm_X",&bkg_1pi0_Npipm_X);
	tree->Branch("bkg_1pi0_Np_Nn_0pipm_X",&bkg_1pi0_Np_Nn_0pipm_X);
	tree->Branch("bkg_1pi0_Np_Nn_Npipm_X",&bkg_1pi0_Np_Nn_Npipm_X);	
	tree->Branch("bkg_1pi0_Nmh_X",&bkg_1pi0_Nmh_X);
	tree->Branch("bkg_1pi0_Nl_X",&bkg_1pi0_Nl_X);
	tree->Branch("bkg_other",&bkg_other);

	tree->Branch("truth_contains_neutron",&truth_contains_neutron);
	tree->Branch("reco_contains_neutron",&reco_contains_neutron);
	tree->Branch("truth_contains_proton",&truth_contains_proton);
	tree->Branch("reco_contains_proton",&reco_contains_proton);
	tree->Branch("truth_contains_proton_or_neutron",&truth_contains_proton_or_neutron);
	tree->Branch("reco_contains_proton_or_neutron",&reco_contains_proton_or_neutron);	

	tree->Branch("true_sum_neutron_ke",&true_sum_neutron_ke);	
	tree->Branch("true_neutron_ke",&true_neutron_ke);
	tree->Branch("true_sum_proton_ke",&true_sum_proton_ke);
	tree->Branch("true_proton_ke",&true_proton_ke);		
	
	tree->Branch("All_UBGenie", &All_UBGenie);
	tree->Branch("AxFFCCQEshape_UBGenie", &AxFFCCQEshape_UBGenie);
	tree->Branch("DecayAngMEC_UBGenie", &DecayAngMEC_UBGenie);
	tree->Branch("NormCCCOH_UBGenie", &NormCCCOH_UBGenie);
	tree->Branch("NormNCCOH_UBGenie", &NormNCCOH_UBGenie);
	tree->Branch("RPA_CCQE_UBGenie", &RPA_CCQE_UBGenie);
	tree->Branch("ThetaDelta2NRad_UBGenie", &ThetaDelta2NRad_UBGenie);
	tree->Branch("Theta_Delta2Npi_UBGenie", &Theta_Delta2Npi_UBGenie);
	tree->Branch("VecFFCCQEshape_UBGenie", &VecFFCCQEshape_UBGenie);
	tree->Branch("XSecShape_CCMEC_UBGenie", &XSecShape_CCMEC_UBGenie);

	//--------------------//	

	tree->Branch("fluxes", &fluxes);
	tree->Branch("reinteractions", &reinteractions);
	tree->Branch("MCParticle_Mode",&MCParticle_Mode);

	tree->Branch("True_Ev",&True_Ev);
	tree->Branch("True_Vx",&True_Vx);
	tree->Branch("True_Vy",&True_Vy);
	tree->Branch("True_Vz",&True_Vz);

	//--------------------//

	tree->Branch("ns_time",&ns_time);
	tree->Branch("NuScore",&NuScore);
	tree->Branch("orig_nuscore",&orig_nuscore);
	tree->Branch("slice_id",&slice_id);		
	tree->Branch("FlashScore",&FlashScore);
	tree->Branch("CosmicIPAll3D",&fCosmicIPAll3D);
	tree->Branch("CosmicDirAll3D",&fCosmicDirAll3D);
	tree->Branch("crtveto",&fcrtveto);
	tree->Branch("crthitpe",&fcrthitpe);

	//--------------------//

	tree->Branch("Vertex_X",&Vertex_X);
	tree->Branch("Vertex_Y",&Vertex_Y);
	tree->Branch("Vertex_Z",&Vertex_Z);
	tree->Branch("wc_vertex_contained",&wc_vertex_contained);

	//--------------------//

	tree->Branch("pd_vertex_x",&pd_vertex_x);
	tree->Branch("pd_vertex_y",&pd_vertex_y);
	tree->Branch("pd_vertex_z",&pd_vertex_z);
	tree->Branch("pd_vertex_contained",&pd_vertex_contained);

	tree->Branch("pd_slcng2mip", &pd_slcng2mip);
	tree->Branch("pd_slcng2hip", &pd_slcng2hip);
	tree->Branch("pd_slcng2shr", &pd_slcng2shr);
	tree->Branch("pd_slcng2mcl", &pd_slcng2mcl);
	tree->Branch("pd_slcng2dfs", &pd_slcng2dfs);
	tree->Branch("pd_slcng2bkg", &pd_slcng2bkg);
	tree->Branch("pd_clung2mip", &pd_clung2mip);
	tree->Branch("pd_clung2hip", &pd_clung2hip);
	tree->Branch("pd_clung2shr", &clung2shr);
	tree->Branch("pd_clung2mcl", &pd_clung2mcl);
	tree->Branch("pd_clung2dfs", &pd_clung2dfs);
	tree->Branch("pd_clung2bkg", &pd_clung2bkg);
	tree->Branch("pd_pfng2semlabel", &pd_pfng2semlabel);
	tree->Branch("pd_pfng2mipfrac", &pd_pfng2mipfrac);
	tree->Branch("pd_pfng2hipfrac", &pd_pfng2hipfrac);
	tree->Branch("pd_pfng2shrfrac", &pd_pfng2shrfrac);
	tree->Branch("pd_pfng2mclfrac", &pd_pfng2mclfrac);
	tree->Branch("pd_pfng2dfsfrac", &pd_pfng2dfsfrac);
	tree->Branch("pd_pfng2bkgfrac", &pd_pfng2bkgfrac);
	tree->Branch("pd_pfng2mipavrg", &pd_pfng2mipavrg);
	tree->Branch("pd_pfng2hipavrg", &pd_pfng2hipavrg);
	tree->Branch("pd_pfng2shravrg", &pd_pfng2shravrg);
	tree->Branch("pd_pfng2mclavrg", &pd_pfng2mclavrg);
	tree->Branch("pd_pfng2dfsavrg", &pd_pfng2dfsavrg);
	tree->Branch("pd_pfng2bkgavrg", &pd_pfng2bkgavrg);	
		
	//--------------------//

	// wc pfparticles

	tree->Branch("wc_reco_g1_id",&wc_reco_g1_id);
	tree->Branch("wc_reco_g2_id",&wc_reco_g2_id);	
	tree->Branch("wc_larpid_process",&wc_reco_larpid_process);
	tree->Branch("wc_reco_mother",&wc_reco_mother);
	tree->Branch("wc_reco_p",&wc_reco_p);
	tree->Branch("wc_reco_start",&wc_reco_start);
	tree->Branch("wc_reco_end",&wc_reco_end);
	tree->Branch("wc_reco_pdg",&wc_reco_pdg);
	tree->Branch("wc_reco_id",&wc_reco_id);
	
	tree->Branch("wc_temp_g1_id",&wc_temp_g1_id);	
	tree->Branch("wc_temp_g2_id",&wc_temp_g2_id);					

	//--------------------//

	//pi0

	tree->Branch("reco_alpha",&reco_alpha);	
	tree->Branch("reco_shower_opening_angle",&reco_shower_opening_angle);	
	tree->Branch("reco_pi0_p_gammas",&reco_pi0_p_gammas);
	tree->Branch("reco_pi0_p",&reco_pi0_p);	
	tree->Branch("reco_pi0_phi",&reco_pi0_phi);
	tree->Branch("reco_pi0_costheta",&reco_pi0_costheta);
	tree->Branch("reco_cm_costheta",&reco_cm_costheta);
	tree->Branch("reco_deltapt",&reco_deltapt);		
	tree->Branch("reco_pi0_invmass",&reco_pi0_invmass);		

	//--------------------//

	// leading gamma (g1)

	tree->Branch("reco_g1_p",&reco_g1_p);	
	tree->Branch("reco_g1_phi",&reco_g1_phi);
	tree->Branch("reco_g1_costheta",&reco_g1_costheta);
	tree->Branch("reco_g1_length",&reco_g1_length);
	tree->Branch("reco_g1_length_x",&reco_g1_length_x);
	tree->Branch("reco_g1_length_y",&reco_g1_length_y);
	tree->Branch("reco_g1_length_z",&reco_g1_length_z);				
	tree->Branch("g1_start_x",&g1_start_x);
	tree->Branch("g1_start_y",&g1_start_y);			
	tree->Branch("g1_start_z",&g1_start_z);
	tree->Branch("g1_start_contained",&g1_start_contained);
	tree->Branch("g1_end_x",&g1_end_x);
	tree->Branch("g1_end_y",&g1_end_y);			
	tree->Branch("g1_end_z",&g1_end_z);	
	tree->Branch("g1_end_contained",&g1_end_contained);

	//--------------------//

	// secondary gamma (g2)	

	tree->Branch("reco_g2_p",&reco_g2_p);	
	tree->Branch("reco_g2_phi",&reco_g2_phi);
	tree->Branch("reco_g2_costheta",&reco_g2_costheta);
	tree->Branch("reco_g2_length",&reco_g2_length);	
	tree->Branch("reco_g2_length_x",&reco_g2_length_x);	
	tree->Branch("reco_g2_length_y",&reco_g2_length_y);
	tree->Branch("reco_g2_length_z",&reco_g2_length_z);				
	tree->Branch("g2_start_x",&g2_start_x);
	tree->Branch("g2_start_y",&g2_start_y);			
	tree->Branch("g2_start_z",&g2_start_z);
	tree->Branch("g2_start_contained",&g2_start_contained);
	tree->Branch("g2_end_x",&g2_end_x);
	tree->Branch("g2_end_y",&g2_end_y);			
	tree->Branch("g2_end_z",&g2_end_z);	
	tree->Branch("g2_end_contained",&g2_end_contained);

	tree->Branch("two_shower_start_dist",&two_shower_start_dist);
	tree->Branch("two_shower_end_dist",&two_shower_end_dist);	
	tree->Branch("flipped_showers",&flipped_showers);		
	
	//--------------------//

	tree->Branch("neutron_truthMatch_p",&neutron_truthMatch_p);
	tree->Branch("proton_truthMatch_p",&proton_truthMatch_p);	
	tree->Branch("neutron_truthMatch_ke",&neutron_truthMatch_ke);
	tree->Branch("proton_truthMatch_ke",&proton_truthMatch_ke);		

	tree->Branch("g1_truthMatch_pdg",&g1_truthMatch_pdg);
	tree->Branch("g1_truthMatch_p",&g1_truthMatch_p);
	tree->Branch("g1_truthMatch_px",&g1_truthMatch_px);
	tree->Branch("g1_truthMatch_py",&g1_truthMatch_py);
	tree->Branch("g1_truthMatch_pz",&g1_truthMatch_pz);
	tree->Branch("g1_truthMatch_costheta",&g1_truthMatch_costheta);
	tree->Branch("g1_truthMatch_phi",&g1_truthMatch_phi);					
	
	tree->Branch("g2_truthMatch_pdg",&g2_truthMatch_pdg);
	tree->Branch("g2_truthMatch_p",&g2_truthMatch_p);
	tree->Branch("g2_truthMatch_px",&g2_truthMatch_px);
	tree->Branch("g2_truthMatch_py",&g2_truthMatch_py);
	tree->Branch("g2_truthMatch_pz",&g2_truthMatch_pz);
	tree->Branch("g2_truthMatch_costheta",&g2_truthMatch_costheta);
	tree->Branch("g2_truthMatch_phi",&g2_truthMatch_phi);
	
	tree->Branch("wc_primary_proton_counter",&wc_primary_proton_counter);
	tree->Branch("wc_primary_muon_counter",&wc_primary_muon_counter);
	tree->Branch("wc_primary_charged_pion_counter",&wc_primary_charged_pion_counter);
	tree->Branch("wc_primary_electron_counter",&wc_primary_electron_counter);
	tree->Branch("wc_primary_photon_counter",&wc_primary_photon_counter);
	tree->Branch("wc_primary_neutron_counter",&wc_primary_neutron_counter);
	tree->Branch("wc_primary_neutral_pion_counter",&wc_primary_neutral_pion_counter);

	tree->Branch("wc_secondary_proton_counter",&wc_secondary_proton_counter);
	tree->Branch("wc_secondary_muon_counter",&wc_secondary_muon_counter);
	tree->Branch("wc_secondary_charged_pion_counter",&wc_secondary_charged_pion_counter);
	tree->Branch("wc_secondary_electron_counter",&wc_secondary_electron_counter);
	tree->Branch("wc_secondary_photon_counter",&wc_secondary_photon_counter);
	tree->Branch("wc_secondary_neutron_counter",&wc_secondary_neutron_counter);
	tree->Branch("wc_secondary_neutral_pion_counter",&wc_secondary_neutral_pion_counter);	
	
	tree->Branch("wc_nshowers",&wc_nshowers);
	tree->Branch("wc_nshowers_0MeV",&wc_nshowers_0MeV);	
	tree->Branch("wc_nshowers_20MeV",&wc_nshowers_20MeV);		
	tree->Branch("wc_nmuontracks",&wc_nmuontracks);
	tree->Branch("wc_nprotontracks",&wc_nprotontracks);
	tree->Branch("wc_npiontracks",&wc_npiontracks);

	tree->Branch("wc_shw_sp_n_good_showers",&wc_shw_sp_n_good_showers);	
	tree->Branch("wc_shw_sp_n_20mev_showers",&wc_shw_sp_n_20mev_showers);
	tree->Branch("wc_shw_sp_n_br1_showers",&wc_shw_sp_n_br1_showers);
	tree->Branch("wc_shw_sp_n_br2_showers",&wc_shw_sp_n_br2_showers);
	tree->Branch("wc_shw_sp_n_br3_showers",&wc_shw_sp_n_br3_showers);
	tree->Branch("wc_shw_sp_n_br4_showers",&wc_shw_sp_n_br4_showers);
	tree->Branch("wc_shw_sp_n_20br1_showers",&wc_shw_sp_n_20br1_showers);

	//--------------------//

	// Blip info

	tree->Branch("ngood_blips",&ngood_blips);	
	tree->Branch("nBlips_saved",&nBlips_saved);
	tree->Branch("Blip_g1_cos_alpha",&Blip_g1_cos_alpha);
	tree->Branch("Blip_g2_cos_alpha",&Blip_g2_cos_alpha);
	tree->Branch("Blip_vt_cos_alpha",&Blip_vt_cos_alpha);		
	tree->Branch("Good_blip_ds",&Good_blip_ds);
	tree->Branch("Blip_dx",&Blip_dx);
	tree->Branch("Blip_dw",&Blip_dw);	
	tree->Branch("Blip_x",&Blip_x);
	tree->Branch("Blip_y",&Blip_y);
	tree->Branch("Blip_z",&Blip_z);
	tree->Branch("Blip_energy",&Blip_energy);
	tree->Branch("Good_blip_energy",&Good_blip_energy);	
	tree->Branch("Blip_charge",&Blip_charge);
	tree->Branch("Blip_nplanes",&Blip_nplanes);
	tree->Branch("Blip_proxtrkdist",&Blip_proxtrkdist);
	tree->Branch("Good_blip_proxtrkdist",&Good_blip_proxtrkdist);	
	tree->Branch("Blip_proxtrkid",&Blip_proxtrkid);
	tree->Branch("Blip_touchtrk",&Blip_touchtrk);
	tree->Branch("Blip_touchtrkid",&Blip_touchtrkid);
	tree->Branch("Blip_pl0_nwires",&Blip_pl0_nwires);
	tree->Branch("Blip_pl1_nwires",&Blip_pl1_nwires);
	tree->Branch("Blip_pl2_nwires",&Blip_pl2_nwires);
	tree->Branch("Blip_pl0_bydeadwire",&Blip_pl0_bydeadwire);
	tree->Branch("Blip_pl1_bydeadwire",&Blip_pl1_bydeadwire);
	tree->Branch("Blip_pl2_bydeadwire",&Blip_pl2_bydeadwire);
	tree->Branch("Blip_true_pdg",&Blip_true_pdg);
	tree->Branch("Blip_true_g4id",&Blip_true_g4id);	
	tree->Branch("Blip_true_energy",&Blip_true_energy);
	tree->Branch("n_blip_pd_vtx_25cm",&n_blip_pd_vtx_25cm);
	tree->Branch("n_blip_pd_vtx_50cm",&n_blip_pd_vtx_50cm);
	tree->Branch("n_blip_pd_vtx_100cm",&n_blip_pd_vtx_100cm);	
	tree->Branch("n_blip_pd_vtx_25cm_g1_anticone",&n_blip_pd_vtx_25cm_g1_anticone);
	tree->Branch("n_blip_pd_vtx_50cm_g1_anticone",&n_blip_pd_vtx_50cm_g1_anticone);
	tree->Branch("n_blip_pd_vtx_100cm_g1_anticone",&n_blip_pd_vtx_100cm_g1_anticone);	
	tree->Branch("n_blip_pd_vtx_25cm_g1_cone",&n_blip_pd_vtx_25cm_g1_cone);
	tree->Branch("n_blip_pd_vtx_50cm_g1_cone",&n_blip_pd_vtx_50cm_g1_cone);
	tree->Branch("n_blip_pd_vtx_100cm_g1_cone",&n_blip_pd_vtx_100cm_g1_cone);
	tree->Branch("n_blip_pd_vtx_25cm_g2_anticone",&n_blip_pd_vtx_25cm_g2_anticone);
	tree->Branch("n_blip_pd_vtx_50cm_g2_anticone",&n_blip_pd_vtx_50cm_g2_anticone);
	tree->Branch("n_blip_pd_vtx_100cm_g2_anticone",&n_blip_pd_vtx_100cm_g2_anticone);	
	tree->Branch("n_blip_pd_vtx_25cm_g2_cone",&n_blip_pd_vtx_25cm_g2_cone);
	tree->Branch("n_blip_pd_vtx_50cm_g2_cone",&n_blip_pd_vtx_50cm_g2_cone);
	tree->Branch("n_blip_pd_vtx_100cm_g2_cone",&n_blip_pd_vtx_100cm_g2_cone);
	tree->Branch("sum_reco_g1_blip_e_25cm",&sum_reco_g1_blip_e_25cm);	
	tree->Branch("sum_reco_g2_blip_e_25cm",&sum_reco_g2_blip_e_25cm);	
	tree->Branch("sum_reco_g1_blip_e_50cm",&sum_reco_g1_blip_e_50cm);	
	tree->Branch("sum_reco_g2_blip_e_50cm",&sum_reco_g2_blip_e_50cm);	
	tree->Branch("sum_reco_g1_blip_e_100cm",&sum_reco_g1_blip_e_100cm);	
	tree->Branch("sum_reco_g2_blip_e_100cm",&sum_reco_g2_blip_e_100cm);							

	//--------------------//

	// Pandora info

	tree->Branch("pd_generation_v",&pd_generation_v);
	tree->Branch("pd_trk_score_v",&pd_trk_score_v);
	tree->Branch("pd_shr_score",&pd_shr_score);	
	tree->Branch("pd_trk_llr_pid_score_v",&pd_trk_llr_pid_score_v);
	tree->Branch("pd_reco_track_count",&pd_reco_track_count);
	tree->Branch("pd_reco_shower_count",&pd_reco_shower_count);
	tree->Branch("pd_reco_secondary_track_count",&pd_reco_secondary_track_count);
	tree->Branch("pd_reco_secondary_shower_count",&pd_reco_secondary_shower_count);	

	//--------------------//

	// glee

	tree->Branch("gl_trackstub_candidate_veto_score",&gl_trackstub_candidate_veto_score);	
	tree->Branch("gl_trackstub_num_candidates",&gl_trackstub_num_candidates);
	tree->Branch("gl_reco_vertex_x",&gl_reco_vertex_x);
	tree->Branch("gl_reco_vertex_y",&gl_reco_vertex_y);
	tree->Branch("gl_reco_vertex_z",&gl_reco_vertex_z);	
	tree->Branch("gl_vertex_contained",&gl_vertex_contained);
	tree->Branch("gl_sss_num_candidates",&gl_sss_num_candidates);
	tree->Branch("gl_reco_asso_showers",&gl_reco_asso_showers);
	tree->Branch("gl_reco_asso_tracks",&gl_reco_asso_tracks);							

	//--------------------//

	// dl lantern

	tree->Branch("dl_foundVertex",&dl_foundVertex);
	tree->Branch("dl_vtxX",&dl_vtxX);
	tree->Branch("dl_vtxY",&dl_vtxY);
	tree->Branch("dl_vtxZ",&dl_vtxZ);
	tree->Branch("dl_vtxScore",&dl_vtxScore);
	tree->Branch("dl_nTracks",&dl_nTracks);
	tree->Branch("dl_nSecTracks",&dl_nSecTracks);
	tree->Branch("dl_nShowers",&dl_nShowers);
	tree->Branch("dl_nSecShowers",&dl_nSecShowers);	
	tree->Branch("dl_vertex_contained",&dl_vertex_contained);			
	
	//--------------------//

	// distance between different reco vertices

	tree->Branch("pd_wc_vtx_dist",&pd_wc_vtx_dist);
	tree->Branch("pd_gl_vtx_dist",&pd_gl_vtx_dist);
	tree->Branch("pd_dl_vtx_dist",&pd_dl_vtx_dist);
	tree->Branch("wc_gl_vtx_dist",&wc_gl_vtx_dist);
	tree->Branch("wc_dl_vtx_dist",&wc_dl_vtx_dist);
	tree->Branch("gl_dl_vtx_dist",&gl_dl_vtx_dist);		

	//--------------------//

	// playground

	double wc_n_veto_nonprim_score; 
	double wc_n_veto_all_score;
	double wc_n_veto_score;	

	tree->Branch("wc_n_veto_nonprim_score",&wc_n_veto_nonprim_score);
	tree->Branch("wc_n_veto_all_score",&wc_n_veto_all_score);
	tree->Branch("wc_n_veto_score",&wc_n_veto_score);			

	//--------------------//

	Tools tools;

	//--------------------//

	// Counters

	int candidate_events = 0;
	int counter_signal = 0;	

	int counter_bkg_0pi0_X = 0;
	int counter_bkg_Mpi0_X = 0;
	int counter_bkg_bwds_1pi0_X = 0;		
	int counter_bkg_1n_0p_1pi0_X = 0;	
	int counter_bkg_Nn_0p_1pi0_X = 0;
	int counter_bkg_1p_0n_1pi0_X = 0;	
	int counter_bkg_Np_0n_1pi0_X = 0;		
	int counter_bkg_1pi0_Npipm_X = 0;
	int counter_bkg_1pi0_Np_Nn_0pipm_X = 0;
	int counter_bkg_1pi0_Np_Nn_Npipm_X = 0;	
	int counter_bkg_1pi0_Nmh_X = 0;
	int counter_bkg_1pi0_Nl_X = 0;
	int counter_bkg_other = 0;						

	//--------------------//

	// POT Counting

	double POTCount = -99.;

	if (string(fLabel).find("Overlay") != std::string::npos) {

		TString PathToPOTFile = preselection_file_path +"/PreSelection_"+fLabel+"_POT.root";		

		TFile* POTFile = TFile::Open(PathToPOTFile,"readonly");
		TH1D* POTCountHist = (TH1D*)(POTFile->Get("POTCountHist"));
		POTCount = POTCountHist->GetBinContent(1);
		POTFile->Close();

		fChain->SetBranchAddress("weightsFlux", &weightsFlux, &b_weightsFlux);
		fChain->SetBranchAddress("weightsGenie", &weightsGenie, &b_weightsGenie);
		fChain->SetBranchAddress("weightsReint", &weightsReint, &b_weightsReint);
		fChain->SetBranchAddress("weightSpline", &weightSpline, &b_weightSpline);
		fChain->SetBranchAddress("weightTune", &weightTune, &b_weightTune);
		fChain->SetBranchAddress("weightSplineTimesTune", &weightSplineTimesTune, &b_weightSplineTimesTune);
		fChain->SetBranchAddress("knobRPAup", &knobRPAup, &b_knobRPAup);
		fChain->SetBranchAddress("knobRPAdn", &knobRPAdn, &b_knobRPAdn);
		fChain->SetBranchAddress("knobCCMECup", &knobCCMECup, &b_knobCCMECup);
		fChain->SetBranchAddress("knobCCMECdn", &knobCCMECdn, &b_knobCCMECdn);
		fChain->SetBranchAddress("knobAxFFCCQEup", &knobAxFFCCQEup, &b_knobAxFFCCQEup);
		fChain->SetBranchAddress("knobAxFFCCQEdn", &knobAxFFCCQEdn, &b_knobAxFFCCQEdn);
		fChain->SetBranchAddress("knobVecFFCCQEup", &knobVecFFCCQEup, &b_knobVecFFCCQEup);
		fChain->SetBranchAddress("knobVecFFCCQEdn", &knobVecFFCCQEdn, &b_knobVecFFCCQEdn);
		fChain->SetBranchAddress("knobDecayAngMECup", &knobDecayAngMECup, &b_knobDecayAngMECup);
		fChain->SetBranchAddress("knobDecayAngMECdn", &knobDecayAngMECdn, &b_knobDecayAngMECdn);
		fChain->SetBranchAddress("knobThetaDelta2Npiup", &knobThetaDelta2Npiup, &b_knobThetaDelta2Npiup);
		fChain->SetBranchAddress("knobThetaDelta2Npidn", &knobThetaDelta2Npidn, &b_knobThetaDelta2Npidn);
		fChain->SetBranchAddress("knobThetaDelta2NRadup", &knobThetaDelta2NRadup, &b_knobThetaDelta2NRadup);
		fChain->SetBranchAddress("knobThetaDelta2NRaddn", &knobThetaDelta2NRaddn, &b_knobThetaDelta2NRaddn);
		fChain->SetBranchAddress("knobNormCCCOHup", &knobNormCCCOHup, &b_knobNormCCCOHup);
		fChain->SetBranchAddress("knobNormCCCOHdn", &knobNormCCCOHdn, &b_knobNormCCCOHdn);
		fChain->SetBranchAddress("knobNormNCCOHup", &knobNormNCCOHup, &b_knobNormNCCOHup);
		fChain->SetBranchAddress("knobNormNCCOHdn", &knobNormNCCOHdn, &b_knobNormNCCOHdn);
		fChain->SetBranchAddress("knobxsr_scc_Fv3up", &knobxsr_scc_Fv3up, &b_knobxsr_scc_Fv3up);
		fChain->SetBranchAddress("knobxsr_scc_Fv3dn", &knobxsr_scc_Fv3dn, &b_knobxsr_scc_Fv3dn);
		fChain->SetBranchAddress("knobxsr_scc_Fa3up", &knobxsr_scc_Fa3up, &b_knobxsr_scc_Fa3up);
		fChain->SetBranchAddress("knobxsr_scc_Fa3dn", &knobxsr_scc_Fa3dn, &b_knobxsr_scc_Fa3dn);
		fChain->SetBranchAddress("RootinoFix", &RootinoFix, &b_RootinoFix);
	
	}

	//--------------------//

	// POT Scaling

	double POTScale = 1.;

	double tor860_wcut = 1;
	double E1DCNT_wcut = 1.;
	double EXT = 1.;

	if (string(fLabel).find("Run1") != std::string::npos) {

		tor860_wcut = Fulltor860_wcut_Run1;
		E1DCNT_wcut = FullE1DCNT_wcut_Run1;
		EXT = FullEXT_Run1;
		run_period = "Run1";	
	}
	
	if (string(fLabel).find("Run1A_open_trigger") != std::string::npos) {

		tor860_wcut = Fulltor860_wcut_Run1A_open_trigger;
		E1DCNT_wcut = FullE1DCNT_wcut_Run1A_open_trigger;
		EXT = FullEXT_Run1A_open_trigger;
		run_period = "Run1A_open_trigger";	
	}

	if (string(fLabel).find("Run1B_open_trigger") != std::string::npos) {

		tor860_wcut = Fulltor860_wcut_Run1B_open_trigger;
		E1DCNT_wcut = FullE1DCNT_wcut_Run1B_open_trigger;
		EXT = FullEXT_Run1B_open_trigger;
		run_period = "Run1B_open_trigger";	
	}
	
	if (string(fLabel).find("Run2") != std::string::npos) {

		tor860_wcut = Fulltor860_wcut_Run2;
		E1DCNT_wcut = FullE1DCNT_wcut_Run2;
		EXT = FullEXT_Run2;
		run_period = "Run2";	
	
	}
	
	if (string(fLabel).find("Run3") != std::string::npos) {

		tor860_wcut = Fulltor860_wcut_Run3;
		E1DCNT_wcut = FullE1DCNT_wcut_Run3;
		EXT = FullEXT_Run3;
		run_period = "Run3";	

	}
	
	if (string(fLabel).find("Run4") != std::string::npos) {

		tor860_wcut = Fulltor860_wcut_Run4;
		E1DCNT_wcut = FullE1DCNT_wcut_Run4;
		EXT = FullEXT_Run4;
		run_period = "Run4";	

	}			
	
	if (string(fLabel).find("Run4a") != std::string::npos) {

		tor860_wcut = Fulltor860_wcut_Run4a;
		E1DCNT_wcut = FullE1DCNT_wcut_Run4a;
		EXT = FullEXT_Run4a;
		run_period = "Run4a";	

	}

	if (string(fLabel).find("Run4b") != std::string::npos) {

		tor860_wcut = Fulltor860_wcut_Run4b;
		E1DCNT_wcut = FullE1DCNT_wcut_Run4b;
		EXT = FullEXT_Run4b;
		run_period = "Run4b";	

	}	
	
	if (string(fLabel).find("Run4b_standalone") != std::string::npos) {

		tor860_wcut = Fulltor860_wcut_mcc9_10_Run4b_standalone;
		E1DCNT_wcut = FullE1DCNT_wcut_mcc9_10_Run4b_standalone;
		EXT = FullEXT_mcc9_10_Run4b_standalone;
		run_period = "mcc9_10_Run4b_standalone";	

	}	
	
	if (string(fLabel).find("Run4b_unified") != std::string::npos) {

		tor860_wcut = Fulltor860_wcut_mcc9_10_Run4b_unified;
		E1DCNT_wcut = FullE1DCNT_wcut_mcc9_10_Run4b_unified;
		EXT = FullEXT_mcc9_10_Run4b_unified;
		run_period = "mcc9_10_Run4b_unified";	

	}		

	if (string(fLabel).find("Run4c") != std::string::npos) {

		tor860_wcut = Fulltor860_wcut_Run4c;
		E1DCNT_wcut = FullE1DCNT_wcut_Run4c;
		EXT = FullEXT_Run4c;
		run_period = "Run4c";	

	}			

	if (string(fLabel).find("Run4d") != std::string::npos) {

		tor860_wcut = Fulltor860_wcut_Run4d;
		E1DCNT_wcut = FullE1DCNT_wcut_Run4d;
		EXT = FullEXT_Run4d;
		run_period = "Run4d";	

	}			

	if (string(fLabel).find("Run5") != std::string::npos) {

		tor860_wcut = Fulltor860_wcut_Run5;
		E1DCNT_wcut = FullE1DCNT_wcut_Run5;
		EXT = FullEXT_Run5;
		run_period = "Run5";	

	}	

	if (string(fLabel).find("ExtBNB9") != std::string::npos) { POTScale = E1DCNT_wcut / EXT; }

	if (string(fLabel).find("Overlay") != std::string::npos) { POTScale = tor860_wcut / POTCount; }	

	POTWeight = POTScale;	
	ROOTinoWeight = 1.;

	wc->SetBranchAddress("nc_pio_score", &nc_pio_score, &b_nc_pio_score);
	wc->SetBranchAddress("numu_score", &numu_score, &b_numu_score);
	wc->SetBranchAddress("numu_cc_flag", &numu_cc_flag, &b_numu_cc_flag);	
	wc->SetBranchAddress("single_photon_numu_score", &single_photon_numu_score, &b_single_photon_numu_score);
	wc->SetBranchAddress("single_photon_other_score", &single_photon_other_score, &b_single_photon_other_score);
	wc->SetBranchAddress("single_photon_ncpi0_score", &single_photon_ncpi0_score, &b_single_photon_ncpi0_score);
	wc->SetBranchAddress("single_photon_nue_score", &single_photon_nue_score, &b_single_photon_nue_score);
	wc->SetBranchAddress("shw_sp_n_good_showers", &shw_sp_n_good_showers, &b_shw_sp_n_good_showers);
	wc->SetBranchAddress("shw_sp_n_20mev_showers", &shw_sp_n_20mev_showers, &b_shw_sp_n_20mev_showers);
	wc->SetBranchAddress("shw_sp_n_br1_showers", &shw_sp_n_br1_showers, &b_shw_sp_n_br1_showers);
	wc->SetBranchAddress("shw_sp_n_br2_showers", &shw_sp_n_br2_showers, &b_shw_sp_n_br2_showers);
	wc->SetBranchAddress("shw_sp_n_br3_showers", &shw_sp_n_br3_showers, &b_shw_sp_n_br3_showers);
	wc->SetBranchAddress("shw_sp_n_br4_showers", &shw_sp_n_br4_showers, &b_shw_sp_n_br4_showers);
	wc->SetBranchAddress("shw_sp_n_20br1_showers", &shw_sp_n_20br1_showers, &b_shw_sp_n_20br1_showers);	

	if (fLabel.Contains("ben_neutron_bdt")) {

		wc->SetBranchAddress("n_veto_all_score", &n_veto_all_score, &b_n_veto_all_score);
		wc->SetBranchAddress("n_veto_nonprim_score", &n_veto_nonprim_score, &b_n_veto_nonprim_score);
		wc->SetBranchAddress("n_veto_score", &n_veto_score, &b_n_veto_score);
		
	}

	wc_kine->SetBranchAddress("kine_pio_flag", &kine_pio_flag, &b_kine_pio_flag);	
	wc_kine->SetBranchAddress("kine_pio_vtx_dis", &kine_pio_vtx_dis, &b_kine_pio_vtx_dis);
	wc_kine->SetBranchAddress("kine_pio_energy_1", &kine_pio_energy_1, &b_kine_pio_energy_1);
	wc_kine->SetBranchAddress("kine_pio_theta_1", &kine_pio_theta_1, &b_kine_pio_theta_1);
	wc_kine->SetBranchAddress("kine_pio_phi_1", &kine_pio_phi_1, &b_kine_pio_phi_1);
	wc_kine->SetBranchAddress("kine_pio_energy_2", &kine_pio_energy_2, &b_kine_pio_energy_2);	
	wc_kine->SetBranchAddress("kine_pio_theta_2", &kine_pio_theta_2, &b_kine_pio_theta_2);
	wc_kine->SetBranchAddress("kine_pio_phi_2", &kine_pio_phi_2, &b_kine_pio_phi_2);
	wc_kine->SetBranchAddress("kine_pio_angle", &kine_pio_angle, &b_kine_pio_angle);
	wc_kine->SetBranchAddress("kine_particle_type", &kine_particle_type, &b_kine_particle_type);
	wc_kine->SetBranchAddress("kine_energy_particle", &kine_energy_particle, &b_kine_energy_particle);
		
	wc_eval->SetBranchAddress("match_isFC", &match_isFC, &b_match_isFC);	
		
	wc_pfeval->SetBranchAddress("reco_nuvtxX", &reco_nuvtxX, &b_reco_nuvtxX);	
	wc_pfeval->SetBranchAddress("reco_nuvtxY", &reco_nuvtxY, &b_reco_nuvtxY);	
	wc_pfeval->SetBranchAddress("reco_nuvtxZ", &reco_nuvtxZ, &b_reco_nuvtxZ);	
	wc_pfeval->SetBranchAddress("reco_larpid_proccess", reco_larpid_proccess, &b_reco_larpid_proccess);	

	if (string(fLabel).find("Overlay") != std::string::npos) {

		wc_pfeval->SetBranchAddress("truth_Ntrack", &truth_Ntrack, &b_truth_Ntrack);	
		wc_pfeval->SetBranchAddress("truth_NprimPio", &truth_NprimPio, &b_truth_NprimPio);		
		wc_pfeval->SetBranchAddress("truth_isCC", &truth_isCC, &b_truth_isCC);	
		wc_pfeval->SetBranchAddress("truth_vtxX", &truth_vtxX, &b_truth_vtxX);
		wc_pfeval->SetBranchAddress("truth_vtxY", &truth_vtxY, &b_truth_vtxY);
		wc_pfeval->SetBranchAddress("truth_vtxZ", &truth_vtxZ, &b_truth_vtxZ);								
		wc_pfeval->SetBranchAddress("truth_id", &truth_id, &b_truth_id);		
		wc_pfeval->SetBranchAddress("truth_pdg", &truth_pdg, &b_truth_pdg);
		wc_pfeval->SetBranchAddress("truth_startMomentum", truth_startMomentum, &b_truth_startMomentum);	
		wc_pfeval->SetBranchAddress("reco_truthMatch_pdg", &reco_truthMatch_pdg, &b_reco_truthMatch_pdg);
		wc_pfeval->SetBranchAddress("reco_truthMatch_id", &reco_truthMatch_id, &b_reco_truthMatch_id);	

	}

	wc_pfeval->SetBranchAddress("reco_Ntrack", &reco_Ntrack, &b_reco_Ntrack);	
	wc_pfeval->SetBranchAddress("reco_mother", &reco_mother, &b_reco_mother);	
	wc_pfeval->SetBranchAddress("reco_startMomentum", &reco_startMomentum, &b_reco_startMomentum);	
	wc_pfeval->SetBranchAddress("reco_startXYZT", &reco_startXYZT, &b_reco_startXYZT);	
	wc_pfeval->SetBranchAddress("reco_endXYZT", &reco_endXYZT, &b_reco_endXYZT);	
	wc_pfeval->SetBranchAddress("reco_pdg", &reco_pdg, &b_reco_pdg);
	wc_pfeval->SetBranchAddress("reco_id", &reco_id, &b_reco_id);
	
	wc_sp->SetBranchAddress("Trec_spacepoints_x", &Trec_spacepoints_x, &b_Trec_spacepoints_x);
	wc_sp->SetBranchAddress("Trec_spacepoints_y", &Trec_spacepoints_y, &b_Trec_spacepoints_y);
	wc_sp->SetBranchAddress("Trec_spacepoints_z", &Trec_spacepoints_z, &b_Trec_spacepoints_z);
	wc_sp->SetBranchAddress("Trec_spacepoints_q", &Trec_spacepoints_q, &b_Trec_spacepoints_q);
	wc_sp->SetBranchAddress("Trec_spacepoints_cluster_id", &Trec_spacepoints_cluster_id, &b_Trec_spacepoints_cluster_id);
	wc_sp->SetBranchAddress("Trec_spacepoints_real_cluster_id", &Trec_spacepoints_real_cluster_id, &b_Trec_spacepoints_real_cluster_id);
	wc_sp->SetBranchAddress("Trec_spacepoints_sub_cluster_id", &Trec_spacepoints_sub_cluster_id, &b_Trec_spacepoints_sub_cluster_id);
	wc_sp->SetBranchAddress("Treccharge_spacepoints_x", &Treccharge_spacepoints_x, &b_Treccharge_spacepoints_x);
	wc_sp->SetBranchAddress("Treccharge_spacepoints_y", &Treccharge_spacepoints_y, &b_Treccharge_spacepoints_y);
	wc_sp->SetBranchAddress("Treccharge_spacepoints_z", &Treccharge_spacepoints_z, &b_Treccharge_spacepoints_z);
	wc_sp->SetBranchAddress("Treccharge_spacepoints_q", &Treccharge_spacepoints_q, &b_Treccharge_spacepoints_q);
	wc_sp->SetBranchAddress("Treccharge_spacepoints_cluster_id", &Treccharge_spacepoints_cluster_id, &b_Treccharge_spacepoints_cluster_id);
	wc_sp->SetBranchAddress("Treccharge_spacepoints_real_cluster_id", &Treccharge_spacepoints_real_cluster_id, &b_Treccharge_spacepoints_real_cluster_id);
	wc_sp->SetBranchAddress("Treccharge_spacepoints_sub_cluster_id", &Treccharge_spacepoints_sub_cluster_id, &b_Treccharge_spacepoints_sub_cluster_id);
	wc_sp->SetBranchAddress("Trecchargeblob_spacepoints_x", &Trecchargeblob_spacepoints_x, &b_Trecchargeblob_spacepoints_x);
	wc_sp->SetBranchAddress("Trecchargeblob_spacepoints_y", &Trecchargeblob_spacepoints_y, &b_Trecchargeblob_spacepoints_y);
	wc_sp->SetBranchAddress("Trecchargeblob_spacepoints_z", &Trecchargeblob_spacepoints_z, &b_Trecchargeblob_spacepoints_z);
	wc_sp->SetBranchAddress("Trecchargeblob_spacepoints_q", &Trecchargeblob_spacepoints_q, &b_Trecchargeblob_spacepoints_q);
	wc_sp->SetBranchAddress("Trecchargeblob_spacepoints_cluster_id", &Trecchargeblob_spacepoints_cluster_id, &b_Trecchargeblob_spacepoints_cluster_id);
	wc_sp->SetBranchAddress("Trecchargeblob_spacepoints_real_cluster_id", &Trecchargeblob_spacepoints_real_cluster_id, &b_Trecchargeblob_spacepoints_real_cluster_id);
	wc_sp->SetBranchAddress("Trecchargeblob_spacepoints_sub_cluster_id", &Trecchargeblob_spacepoints_sub_cluster_id, &b_Trecchargeblob_spacepoints_sub_cluster_id);			

	//--------------------//

	//glee ttree

	gl_vtx->SetBranchAddress("trackstub_candidate_veto_score", &trackstub_candidate_veto_score, &b_trackstub_candidate_veto_score);
	gl_vtx->SetBranchAddress("trackstub_num_candidates", &trackstub_num_candidates, &b_trackstub_num_candidates);
	gl_vtx->SetBranchAddress("reco_vertex_x", &reco_vertex_x, &b_reco_vertex_x);
	gl_vtx->SetBranchAddress("reco_vertex_y", &reco_vertex_y, &b_reco_vertex_y);
	gl_vtx->SetBranchAddress("reco_vertex_z", &reco_vertex_z, &b_reco_vertex_z);
   	gl_vtx->SetBranchAddress("sss_num_candidates", &sss_num_candidates, &b_sss_num_candidates);	
   	gl_vtx->SetBranchAddress("reco_asso_showers", &reco_asso_showers, &b_reco_asso_showers);
   	gl_vtx->SetBranchAddress("reco_asso_tracks", &reco_asso_tracks, &b_reco_asso_tracks);		

	//--------------------//

	// dl lantern

	dl->SetBranchAddress("foundVertex", &foundVertex, &b_foundVertex);
	dl->SetBranchAddress("vtxX", &vtxX, &b_vtxX);
	dl->SetBranchAddress("vtxY", &vtxY, &b_vtxY);
	dl->SetBranchAddress("vtxZ", &vtxZ, &b_vtxZ);
	dl->SetBranchAddress("vtxScore", &vtxScore, &b_vtxScore);	
	dl->SetBranchAddress("nTracks", &nTracks, &b_nTracks);
	dl->SetBranchAddress("trackIsSecondary", trackIsSecondary, &b_trackIsSecondary);
	dl->SetBranchAddress("nShowers", &nShowers, &b_nShowers);
	dl->SetBranchAddress("showerIsSecondary", showerIsSecondary, &b_showerIsSecondary);		

	//--------------------//			

	for (Long64_t jentry=0; jentry<nentries;jentry++) {

		//--------------------//
      
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
      	nb = fChain->GetEntry(jentry);   nbytes += nb;

		Long64_t wc_i_entry = wc->LoadTree(jentry);
		wc_nb = wc->GetEntry(jentry);   
		wc_nbytes += wc_nb;	

		Long64_t wc_kine_i_entry = wc_kine->LoadTree(jentry);
		wc_kine_nb = wc_kine->GetEntry(jentry);   
		wc_kine_nbytes += wc_kine_nb;	
			
		Long64_t wc_eval_i_entry = wc_eval->LoadTree(jentry);
		wc_eval_nb = wc_eval->GetEntry(jentry);   
		wc_eval_nbytes += wc_eval_nb;	

		Long64_t wc_pfeval_i_entry = wc_pfeval->LoadTree(jentry);
		wc_pfeval_nb = wc_pfeval->GetEntry(jentry);   
		wc_pfeval_nbytes += wc_pfeval_nb;
		
		Long64_t wc_sp_i_entry = wc_sp->LoadTree(jentry);
		wc_sp_nb = wc_sp->GetEntry(jentry);   
		wc_sp_nbytes += wc_sp_nb;		

		Long64_t gl_vtx_i_entry = gl_vtx->LoadTree(jentry);
		gl_vtx_nb = gl_vtx->GetEntry(jentry);   
		gl_vtx_nbytes += gl_vtx_nb;
		
		Long64_t dl_i_entry = dl->LoadTree(jentry);
		dl_nb = dl->GetEntry(jentry);   
		dl_nbytes += dl_nb;		

		//--------------------//			

		if (string(fLabel).find("nonNCpi0Overlay") != std::string::npos) {		

			if (truth_NprimPio == 1 && truth_isCC == 0 && tools.inAV(truth_vtxX,truth_vtxY,truth_vtxZ) ) { continue; }

		}

		//--------------------//			

		if (jentry%1000 == 0) std::cout << jentry/1000 << " k " << std::setprecision(3) << double(jentry)/nentries*100. << " %"<< std::endl;

		//--------------------//

		//Truth level loop for MC

		// MCParticle Loop
		
		int fsignal = 0;
		int fnc = 0;
		int fnumu = 0;
		int fqe = 0;
		int fmec = 0;
		int fres = 0;
		int fdis = 0;
		int fcoh = 0;	
		int fother = 0;	
		
		int fbkg_0pi0_X = 0;
		int fbkg_Mpi0_X = 0;
		int fbkg_bwds_1pi0_X = 0;		
		int fbkg_1n_0p_1pi0_X = 0;
		int fbkg_Nn_0p_1pi0_X = 0;
		int fbkg_1p_0n_1pi0_X = 0;
		int fbkg_Np_0n_1pi0_X = 0;
		int fbkg_1pi0_Npipm_X = 0;
		int fbkg_1pi0_Np_Nn_0pipm_X = 0;
		int fbkg_1pi0_Np_Nn_Npipm_X = 0;		
		int fbkg_1pi0_Nmh_X = 0; // m = mesons (mostly etas), h = heavy particles (Sigmas, Lambdas)	
		int fbkg_1pi0_Nl_X = 0; // l = lepton		
		int fbkg_other = 0;

		int ProtonTagging = 0, ChargedPionTagging = 0, Pi0Tagging = 0;
		int heavy_meson_tagging = 0, SigmaTagging = 0, LambdaTagging = 0;
		int PhotonTagging = 0, LeptonTagging = 0 , cluster_tagging = 0;
		int neutron_tagging = 0;
		true_neutron_ke.clear();	
		true_proton_ke.clear();				

		std::vector<int> Pi0ID; Pi0ID.clear();		
		int NMCParticles = mc_pdg->size();
		
		if (string(fLabel).find("Overlay") != std::string::npos) {

			if (ccnc == 1) { fnc = 1; }
			if (nu_pdg == 14) { fnumu = 1; }

			if (interaction == 0) { fqe = 1; }	
			else if (interaction == 10) { fmec = 1; }	
			else if (interaction == 1) { fres = 1; }	
			else if (interaction == 2) { fdis = 1; }	
			else if (interaction == 3 ) { fcoh = 1; }	
			else { fother = 1; }		

			// Loop over the MCParticles and determine the populations

			double temp_true_sum_neutron_ke = 0.;
			double temp_true_sum_proton_ke = 0.;			

			for (int i_mc = 0; i_mc < NMCParticles; i_mc++) {

				// MC truth information for the final-state primary particles

				// NC events, all neutrino flavors

				if (ccnc == 1) {

					TVector3 MCParticle(mc_px->at(i_mc),mc_py->at(i_mc),mc_pz->at(i_mc));
					double MCParticleMomentum = MCParticle.Mag();
					int MCParticlePdg = mc_pdg->at(i_mc);

					if (MCParticlePdg == ProtonPdg ) {

						double E = TMath::Sqrt( TMath::Power(MCParticleMomentum,2.) + TMath::Power(ProtonMass_GeV,2.) );
						double ke = E - ProtonMass_GeV;
						true_proton_ke.push_back(ke);
						temp_true_sum_proton_ke += ke;						

						// proton kinetic energy threshold
						if ( ke > proton_ke_thres ) {

							ProtonTagging ++;

						}

					}

					else if ( fabs(MCParticlePdg) == AbsChargedPionPdg )  {

						ChargedPionTagging ++;

					}

					else if ( fabs(MCParticlePdg) == NeutralPionPdg)  {

						Pi0Tagging ++;
						Pi0ID.push_back(i_mc);

					}

					else if ( fabs(MCParticlePdg) == KaonPdg || fabs(MCParticlePdg) == NeutralKaonPdg 
					    || fabs(MCParticlePdg) == NeutralKaonLongPdg || fabs(MCParticlePdg) == NeutralKaonShortPdg 
						|| fabs(MCParticlePdg) == rho_pdg || fabs(MCParticlePdg) == charged_rho_pdg 
						|| fabs(MCParticlePdg) == d0_pdg || fabs(MCParticlePdg) == dp_pdg || fabs(MCParticlePdg) == dm_pdg
						|| fabs(MCParticlePdg) == eta_pdg || fabs(MCParticlePdg) == omega_pdg 
						|| fabs(MCParticlePdg) == xi_pdg || fabs(MCParticlePdg) == xi0_pdg)  {

						heavy_meson_tagging ++;
			
					}	
					
					else if ( fabs(MCParticlePdg) == SigmaPlusPdg || fabs(MCParticlePdg) == SigmaMinusPdg || fabs(MCParticlePdg) == NeutralSigmaPdg)  {

						SigmaTagging ++;
			
					}		
					
					else if ( fabs(MCParticlePdg) == LambdaPdg)  {

						LambdaTagging ++;
			
					}
					
					else if ( fabs(MCParticlePdg) == PhotonPdg)  {

						PhotonTagging ++;
			
					}
					
					else if ( fabs(MCParticlePdg) == ElectronPdg || fabs(MCParticlePdg) == MuonPdg)  {

						LeptonTagging ++;
			
					}		
					
					else if ( fabs(MCParticlePdg) > 1000000000)  {

						//cluster_tagging ++;
			
					}					

					else if ( fabs(MCParticlePdg) == hydrogen_cluster_pdg || fabs(MCParticlePdg) == nucleon_pair
						|| fabs(MCParticlePdg) == ArgonPdg || fabs(MCParticlePdg) == neutron_pair || fabs(MCParticlePdg) == proton_pair) {

						// Ignore nucleon pairs, numus, nues

					}

					else if ( fabs(MCParticlePdg) == NuMuPdg || fabs(MCParticlePdg) == nue_pdg) {

						// Ignore numus, nues

					}

					else if (MCParticlePdg == NeutronPdg ) {

						double E = TMath::Sqrt( TMath::Power(MCParticleMomentum,2.) + TMath::Power(NeutronMass_GeV,2.) );
						double ke = E - NeutronMass_GeV;
						true_neutron_ke.push_back(ke);
						temp_true_sum_neutron_ke += ke;

						// proton kinetic energy threshold
						if ( ke > neutron_ke_thres ) {

							neutron_tagging ++;

						}

					}

					else { cout << "post fsi pdg " << MCParticlePdg << endl; }
				
				} // End of the demand stable final state particles and primary interactions

			} // end of the loop over the MCParticles

			true_sum_neutron_ke = temp_true_sum_neutron_ke;			
			true_sum_proton_ke = temp_true_sum_proton_ke;

		}

		//--------------------//

		// NCCOh-like Signal events	(still truth level)

		if (
			Pi0Tagging == 1 && ProtonTagging == 0 && ChargedPionTagging == 0 && 
		   heavy_meson_tagging == 0 && LambdaTagging == 0 && SigmaTagging == 0 &&
		   PhotonTagging == 0 && LeptonTagging == 0 && cluster_tagging == 0 && neutron_tagging == 0
		) {

			fsignal = 1;
 
			TVector3 MCParticle(mc_px->at( Pi0ID.at(0) ),mc_py->at( Pi0ID.at(0) ), mc_pz->at( Pi0ID.at(0) ));
			double pi0_TrueCosTheta = MCParticle.CosTheta(); 
			if (pi0_TrueCosTheta < pi0_costheta_thres) { 
				
				fsignal = 0; 
				fbkg_bwds_1pi0_X = 1;
			
			}

		}

		else if (Pi0Tagging == 0) { fbkg_0pi0_X = 1; }

		else if (Pi0Tagging > 1) { fbkg_Mpi0_X = 1; }	
		
		else if (Pi0Tagging == 1 && neutron_tagging == 1 && ProtonTagging == 0) { fbkg_1n_0p_1pi0_X = 1; }	
		
		else if (Pi0Tagging == 1 && neutron_tagging > 1 && ProtonTagging == 0) { fbkg_Nn_0p_1pi0_X = 1; }
		
		else if (Pi0Tagging == 1 && ProtonTagging == 1 && neutron_tagging == 0) { fbkg_1p_0n_1pi0_X = 1; }
		
		else if (Pi0Tagging == 1 && ProtonTagging > 1 && neutron_tagging == 0) { fbkg_Np_0n_1pi0_X = 1; }	

		else if (Pi0Tagging == 1 && ProtonTagging > 0 && neutron_tagging > 0 && ChargedPionTagging == 0) { fbkg_1pi0_Np_Nn_0pipm_X = 1; }	
		
		else if (Pi0Tagging == 1 && ProtonTagging > 0 && neutron_tagging > 0 && ChargedPionTagging > 0) { fbkg_1pi0_Np_Nn_Npipm_X = 1; }			

		else if (Pi0Tagging == 1 && ChargedPionTagging > 0 && ProtonTagging == 0 && neutron_tagging == 0) { fbkg_1pi0_Npipm_X = 1; }	
		
		else if (Pi0Tagging == 1 && (heavy_meson_tagging + LambdaTagging + SigmaTagging + cluster_tagging)  > 0 && ProtonTagging == 0 && neutron_tagging == 0) { fbkg_1pi0_Nmh_X = 1; }			
		
		else if (Pi0Tagging == 1 && LeptonTagging > 0 && ProtonTagging == 0 && neutron_tagging == 0) { fbkg_1pi0_Nl_X = 1; }	

		else { 
			
			fbkg_other = 1; 			

		   	cout << " Pi0Tagging = " << Pi0Tagging;
			cout << " ProtonTagging = " << ProtonTagging;
			cout << " neutron_tagging = " << neutron_tagging;			
			cout << " ChargedPionTagging = " << ChargedPionTagging;
			cout << " heavy_meson_tagging = " << heavy_meson_tagging;	
			cout << " cluster_tagging = " << cluster_tagging;
			cout << " LeptonTagging = " << LeptonTagging;
			cout << " PhotonTagging = " << PhotonTagging;
			cout << " SigmaTagging = " << SigmaTagging;	
			cout << " LambdaTagging = " << LambdaTagging << endl;																		
		
		}

		if (neutron_tagging > 0) { truth_contains_neutron = 1; }
		else { truth_contains_neutron = 0; }

		if (ProtonTagging > 0) { truth_contains_proton = 1; }
		else { truth_contains_proton = 0; }		

		if (neutron_tagging > 0 || ProtonTagging > 0) { truth_contains_proton_or_neutron = 1; }
		else { truth_contains_proton_or_neutron = 0; }		

		//--------------------//

		// Weights for systematics

		if (string(fLabel).find("Overlay") != std::string::npos) {

			Weight = weightSpline;
			T2KWeight = weightTune;
			ROOTinoWeight = 1.;

			reinteractions = *weightsReint;
			fluxes = *weightsFlux;
			All_UBGenie = *weightsGenie;
			AxFFCCQEshape_UBGenie = {knobAxFFCCQEup, knobAxFFCCQEdn};
			DecayAngMEC_UBGenie = {knobDecayAngMECup, knobDecayAngMECdn};
			NormCCCOH_UBGenie = {knobNormCCCOHup,knobNormCCCOHdn};
			NormNCCOH_UBGenie = {knobNormNCCOHup,knobNormNCCOHdn};
			RPA_CCQE_UBGenie = {knobRPAup,knobRPAdn};
			ThetaDelta2NRad_UBGenie = {knobThetaDelta2NRadup,knobThetaDelta2NRaddn};
			Theta_Delta2Npi_UBGenie = {knobThetaDelta2Npiup,knobThetaDelta2Npidn};
			VecFFCCQEshape_UBGenie = {knobVecFFCCQEup,knobVecFFCCQEdn};
			XSecShape_CCMEC_UBGenie = {knobCCMECup,knobCCMECdn};
			ROOTinoWeight = RootinoFix;

		} else {

			// For BeamOn, everything will be 1
			// For BeamOff, the POTScale should be different based on the triggers
			// For MC, we need the POTCount for each one of the samples

			Weight = 1.;
			T2KWeight = 1.;
			ROOTinoWeight = 1.;

		}

		//--------------------//

		// Now getting to the reco part

		// wc vertex

		Vertex_X.clear();
		Vertex_Y.clear();
		Vertex_Z.clear();

		// pandora vertex

		pd_vertex_x.clear();
		pd_vertex_y.clear();
		pd_vertex_z.clear();		

		//--------------------//

		// pi0

		reco_alpha.clear();
		reco_shower_opening_angle.clear();
		reco_pi0_p_gammas.clear();	
		reco_pi0_p.clear();	
		reco_pi0_phi.clear();
		reco_pi0_costheta.clear();
		reco_cm_costheta.clear();	
		reco_deltapt.clear();					
		reco_pi0_invmass.clear();			

		//--------------------//

		// leading gamma (g1)

		reco_g1_p.clear();	
		reco_g1_phi.clear();
		reco_g1_costheta.clear();
		
		//--------------------//

		// secondary gamma (g2)

		reco_g2_p.clear();	
		reco_g2_phi.clear();
		reco_g2_costheta.clear();

		proton_truthMatch_p.clear();
		neutron_truthMatch_p.clear();	
		proton_truthMatch_ke.clear();
		neutron_truthMatch_ke.clear();				
		
		//--------------------//

		// Blips

		Blip_g1_cos_alpha.clear();
		Blip_g2_cos_alpha.clear();
		Blip_vt_cos_alpha.clear();						
		Good_blip_ds.clear();
		Blip_dx.clear();
		Blip_dw.clear();		
		Blip_x.clear();
		Blip_y.clear();
		Blip_z.clear();
		Blip_energy.clear();
		Blip_charge.clear();
		Blip_nplanes.clear();
		Blip_proxtrkdist.clear();
		Blip_proxtrkid.clear();
		Blip_touchtrk.clear();
		Blip_touchtrkid.clear();
		Blip_pl0_nwires.clear();
		Blip_pl1_nwires.clear();
		Blip_pl2_nwires.clear();
		Blip_pl0_bydeadwire.clear();
		Blip_pl1_bydeadwire.clear();
		Blip_pl2_bydeadwire.clear();
		Blip_true_pdg.clear();
		Blip_true_g4id.clear();
		Blip_true_energy.clear();	
		
		//----------------------------------------//	
		
		// wc spacepoints

		trecchargeblob_spacepoints_x.clear();
		trecchargeblob_spacepoints_y.clear();
		trecchargeblob_spacepoints_z.clear();
		trecchargeblob_spacepoints_q.clear();
		trecchargeblob_spacepoints_real_cluster_id.clear();			
		photon_q_median.clear();
		neutron_q_median.clear();		

		//--------------------//

		// WC vectors

		wc_kine_particle_type.clear();
		wc_kine_energy_particle.clear();
		wc_reco_pdg.clear();
		wc_reco_id.clear();
		wc_reco_larpid_process.clear();
		wc_reco_mother.clear();
		wc_reco_p.clear();
		wc_reco_start.clear();
		wc_reco_end.clear();

		//--------------------//

		// pandora info

		pd_generation_v.clear();
		pd_trk_score_v.clear();
		pd_trk_llr_pid_score_v.clear();

		//--------------------//

		// pandora nugraph	
		
		pd_pfng2semlabel.clear();
		pd_pfng2mipfrac.clear();
		pd_pfng2hipfrac.clear();
		pd_pfng2shrfrac.clear();
		pd_pfng2mclfrac.clear();
		pd_pfng2dfsfrac.clear();
		pd_pfng2bkgfrac.clear();
		pd_pfng2mipavrg.clear();
		pd_pfng2hipavrg.clear();
		pd_pfng2shravrg.clear();
		pd_pfng2mclavrg.clear();
		pd_pfng2dfsavrg.clear();
		pd_pfng2bkgavrg.clear();		

		//--------------------//

		// glee

		gl_trackstub_candidate_veto_score.clear();

		//--------------------//

		// Requirement for two well-reconstructed
		// and fully contained objects associated
		// with neutrino vertex

		// Ben's NCpi0 selection

		if (kine_pio_energy_1 <= 0) { continue; }
		if (kine_pio_energy_2 <= 0) { continue; }
		if (match_isFC != 1) { continue; }
		if (nc_pio_score < 1.816) { continue; }

		wc_kine_pio_energy_1 = kine_pio_energy_1;
		wc_kine_pio_energy_2 = kine_pio_energy_2;
		wc_match_isFC = match_isFC;		

		//--------------------//

		Run = run;
		SubRun = sub;
		Event = evt;

		ns_time = interaction_time_abs;
		slice_id = slice_orig_pass_id; // whether the event passes the mcc9 slicing
		NuScore = topological_score; // new Pandora / NuGraph score
		orig_nuscore = slice_orig_topo_score; // old Pandora score		
		FlashScore = nu_flashmatch_score;
		fCosmicIPAll3D = CosmicIPAll3D;
		fCosmicDirAll3D = CosmicDirAll3D;
		fcrtveto = crtveto;
		fcrthitpe = crthitpe;

		wc_kine_pio_flag = kine_pio_flag;
		wc_numu_score = numu_score;
		wc_numu_cc_flag = numu_cc_flag;		
		wc_nc_pio_score = nc_pio_score;
		wc_kine_pio_vtx_dis = kine_pio_vtx_dis;
		wc_kine_pio_energy_1 = kine_pio_energy_1;	
		wc_kine_pio_theta_1 = kine_pio_theta_1;
		wc_kine_pio_phi_1 = kine_pio_phi_1;	
		wc_kine_pio_energy_2 = kine_pio_energy_2;	
		wc_kine_pio_theta_2 = kine_pio_theta_2;	
		wc_kine_pio_phi_2 = kine_pio_phi_2;
		wc_match_isFC = match_isFC;	
		
		wc_single_photon_numu_score = single_photon_numu_score;
		wc_single_photon_other_score = single_photon_other_score;
		wc_single_photon_ncpi0_score = single_photon_ncpi0_score;
		wc_single_photon_nue_score = single_photon_nue_score;

		//--------------------//

		// WC reconstructed Vertex

		TVector3 VertexLocation(reco_nuvtxX,reco_nuvtxY,reco_nuvtxZ);
		wc_vertex_contained = tools.inFVVector(VertexLocation);

		Vertex_X.push_back(reco_nuvtxX);
		Vertex_Y.push_back(reco_nuvtxY);
		Vertex_Z.push_back(reco_nuvtxZ);

		// pd reco vertex

		TVector3 pd_VertexLocation(reco_nu_vtx_sce_x,reco_nu_vtx_sce_y,reco_nu_vtx_sce_z);
		pd_vertex_contained = tools.inFVVector(pd_VertexLocation);		

		pd_vertex_x.push_back(reco_nu_vtx_sce_x);
		pd_vertex_y.push_back(reco_nu_vtx_sce_y);
		pd_vertex_z.push_back(reco_nu_vtx_sce_z);		

		MCParticle_Mode = interaction;

		//--------------------//

		// Candidate leading gamma (g1)

		// if data, scale energy by 0.95
		double Egamma1 = kine_pio_energy_1; // MeV
		if ( !(string(fLabel).find("Overlay") != std::string::npos) ) {

			Egamma1 = 0.95*kine_pio_energy_1;

		}

		TLorentzVector g1(Egamma1*TMath::Sin(kine_pio_theta_1/180.*3.1415926)*TMath::Cos(kine_pio_phi_1/180.*3.1415926),\
						  Egamma1*TMath::Sin(kine_pio_theta_1/180.*3.1415926)*TMath::Sin(kine_pio_phi_1/180.*3.1415926),\
						  Egamma1*TMath::Cos(kine_pio_theta_1/180.*3.1415926), Egamma1);

		reco_g1_p.push_back(g1.Rho()/1e3);	// GeV		
		reco_g1_phi.push_back(g1.Phi()); // rad
		reco_g1_costheta.push_back(g1.CosTheta());		

		//--------------------//

		// Candidate secondary gamma (g2)

		// if data, scale energy by 0.95
		double Egamma2 = kine_pio_energy_2; // MeV
		if ( !(string(fLabel).find("Overlay") != std::string::npos) ) {
		
			Egamma2 = 0.95*kine_pio_energy_2;
		
		}

		TLorentzVector g2(Egamma2*TMath::Sin(kine_pio_theta_2/180.*3.1415926)*TMath::Cos(kine_pio_phi_2/180.*3.1415926),\
						  Egamma2*TMath::Sin(kine_pio_theta_2/180.*3.1415926)*TMath::Sin(kine_pio_phi_2/180.*3.1415926),\
						  Egamma2*TMath::Cos(kine_pio_theta_2/180.*3.1415926), Egamma2);

		reco_g2_p.push_back(g2.Rho()/1e3); // GeV			
		reco_g2_phi.push_back(g2.Phi()); // rad
		reco_g2_costheta.push_back(g2.CosTheta());		

		//--------------------//

		// Candidate pi0

		reco_shower_opening_angle.push_back(kine_pio_angle);
		double alpha = TMath::Abs(Egamma1-Egamma2) / (Egamma1 + Egamma2);
		reco_alpha.push_back( alpha );

		double pio_p = pi0_mass_gev * TMath::Sqrt( 2./(1-alpha*alpha) / (1-cos(kine_pio_angle/180.*3.1415926)) -1);
		reco_pi0_p.push_back(pio_p); // GeV
		
		TLorentzVector pio = g1 + g2;
		reco_pi0_phi.push_back(pio.Phi()); // rad
		reco_pi0_costheta.push_back(pio.CosTheta());
		reco_pi0_invmass.push_back(pio.Mag()/1e3); // GeV
		reco_pi0_p_gammas.push_back(pio.Rho()/1e3);	//GeV

		double cos_theta_cm = (Egamma1*0.001-Egamma2*0.001)/TMath::Abs(pio.Rho()/1e3);
		reco_cm_costheta.push_back(cos_theta_cm);	
		reco_deltapt.push_back(pio.Pt()/1e3); // GeV

		//--------------------//

		// WC primary and non-primary pfparticles

		wc_reco_p.resize(reco_Ntrack);
		wc_reco_start.resize(reco_Ntrack);
		wc_reco_end.resize(reco_Ntrack);

		int temp_g1_id = -1;
		int temp_g2_id = -1;		

		for (int i = 0; i < reco_Ntrack; i++) {

			wc_reco_larpid_process.push_back(reco_larpid_proccess[i]);			
			wc_reco_mother.push_back(reco_mother[i]);
			wc_reco_pdg.push_back(reco_pdg[i]);
			wc_reco_id.push_back(reco_id[i]);

			for (int j = 0; j < 4; j++) {

				wc_reco_p.at(i).push_back( reco_startMomentum[i][j] ); // GeV
				wc_reco_start.at(i).push_back( reco_startXYZT[i][j] ); // cm
				wc_reco_end.at(i).push_back( reco_endXYZT[i][j] ); // cm

			}

			// do the pfeval-to-gamma matching
			// only primaries and photons

			if (reco_pdg[i] == 11) {

				if ( TMath::Abs(kine_pio_energy_1*0.001 - reco_startMomentum[i][3])/(kine_pio_energy_1*0.001) < 0.02 ) { 
					
					temp_g1_id = i; 
					wc_reco_g1_id = i; 				
				
				}

				if ( TMath::Abs(kine_pio_energy_2*0.001 - reco_startMomentum[i][3])/(kine_pio_energy_2*0.001) < 0.02 ) { 
					
					temp_g2_id = i; 
					wc_reco_g2_id = i; 				
				
				}	
			
			}

		}		

		// make sure that the pfeval-to-gamma matching is done correctly
		if (temp_g1_id == -1) { continue; }
		if (temp_g2_id == -1) { continue; }

		wc_temp_g1_id = temp_g1_id;
		wc_temp_g2_id = temp_g2_id;		

		g1_start_x = reco_startXYZT[temp_g1_id][0];
		g1_start_y = reco_startXYZT[temp_g1_id][1];
		g1_start_z = reco_startXYZT[temp_g1_id][2];
		
		g1_end_x = reco_endXYZT[temp_g1_id][0];
		g1_end_y = reco_endXYZT[temp_g1_id][1];
		g1_end_z = reco_endXYZT[temp_g1_id][2];		
		
		g2_start_x = reco_startXYZT[temp_g2_id][0];
		g2_start_y = reco_startXYZT[temp_g2_id][1];
		g2_start_z = reco_startXYZT[temp_g2_id][2];	

		g2_end_x = reco_endXYZT[temp_g2_id][0];
		g2_end_y = reco_endXYZT[temp_g2_id][1];
		g2_end_z = reco_endXYZT[temp_g2_id][2];		
		
		TVector3 g1_start(g1_start_x,g1_start_y,g1_start_z);
		TVector3 g2_start(g2_start_x,g2_start_y,g2_start_z);	
		TVector3 g1_end(g1_end_x,g1_end_y,g1_end_z);
		TVector3 g2_end(g2_end_x,g2_end_y,g2_end_z);
		
		g1_start_contained = tools.inFVVector(g1_start);
		g2_start_contained = tools.inFVVector(g2_start);
		g1_end_contained = tools.inFVVector(g1_end);
		g2_end_contained = tools.inFVVector(g2_end);

		two_shower_start_dist = (g1_start - g2_start).Mag();
		two_shower_end_dist = (g1_end - g2_end).Mag();
		flipped_showers = (two_shower_start_dist > two_shower_end_dist)?1:0;			

		TVector3 g1_length = (g1_end-g1_start);
		reco_g1_length = g1_length.Mag();
		reco_g1_length_x = TMath::Abs(g1_length.X());
		reco_g1_length_y = TMath::Abs(g1_length.Y());	
		reco_g1_length_z = TMath::Abs(g1_length.Z());				

		TVector3 g2_length = (g2_end-g2_start);		
		reco_g2_length = g2_length.Mag();	
		reco_g2_length_x = TMath::Abs(g2_length.X());
		reco_g2_length_y = TMath::Abs(g2_length.Y());	
		reco_g2_length_z = TMath::Abs(g2_length.Z());		

		//--------------------//

		wc_kine_particle_type = *kine_particle_type;
		wc_kine_energy_particle = *kine_energy_particle;	

		//--------------------//

		// True neutrino vertex

		if (string(fLabel).find("Overlay") != std::string::npos) {

			True_Ev = nu_e;
			True_Vx = true_nu_vtx_x;
			True_Vy = true_nu_vtx_y;
			True_Vz = true_nu_vtx_z;
			nupdg = nu_pdg;

		} else {

			True_Ev = CosmicPID;
			True_Vx = CosmicPID;
			True_Vy = CosmicPID;
			True_Vz = CosmicPID;
			nupdg = CosmicPID;

		}

		//----------------------------------------//
		
		TVector3 TrueNu_Vertex(True_Vx,True_Vy,True_Vz);
		bool TrueNu_Vertex_Containment = tools.inFVVector(TrueNu_Vertex);
	
		//----------------------------------------//		

		bkg_0pi0_X = fbkg_0pi0_X;
		bkg_Mpi0_X = fbkg_Mpi0_X;
		bkg_bwds_1pi0_X = fbkg_bwds_1pi0_X;		
		bkg_1n_0p_1pi0_X = fbkg_1n_0p_1pi0_X;
		bkg_Nn_0p_1pi0_X = fbkg_Nn_0p_1pi0_X;
		bkg_1p_0n_1pi0_X = fbkg_1p_0n_1pi0_X;
		bkg_Np_0n_1pi0_X = fbkg_Np_0n_1pi0_X;
		bkg_1pi0_Npipm_X = fbkg_1pi0_Npipm_X;
		bkg_1pi0_Np_Nn_0pipm_X = fbkg_1pi0_Np_Nn_0pipm_X;
		bkg_1pi0_Np_Nn_Npipm_X = fbkg_1pi0_Np_Nn_Npipm_X;		
		bkg_1pi0_Nmh_X = fbkg_1pi0_Nmh_X;
		bkg_1pi0_Nl_X = fbkg_1pi0_Nl_X;		
		bkg_other = fbkg_other;		

		signal = fsignal;
		nc = fnc;
		numu = fnumu;

		qe = fqe; // 0
		mec = fmec; // 10
		res = fres; // 1
		dis = fdis; // 2
		coh = fcoh; // 6

		//----------------------------------------//		

		// Blips

		nBlips_saved = nblips_saved;
		Blip_dx = *blip_dx;
		Blip_dw = *blip_dw;		
		Blip_x = *blip_x;
		Blip_y = *blip_y ;
		Blip_z = *blip_z;
		Blip_energy = *blip_energy;
		Blip_charge = *blip_charge;
		Blip_nplanes = *blip_nplanes;
		Blip_proxtrkdist = *blip_proxtrkdist;
		Blip_proxtrkid = *blip_proxtrkid;
		Blip_touchtrk = *blip_touchtrk;
		Blip_touchtrkid = *blip_touchtrkid;
		Blip_pl0_nwires = *blip_pl0_nwires;
		Blip_pl1_nwires = *blip_pl1_nwires;
		Blip_pl2_nwires = *blip_pl2_nwires;
		Blip_pl0_bydeadwire = *blip_pl0_bydeadwire;
		Blip_pl1_bydeadwire = *blip_pl1_bydeadwire;
		Blip_pl2_bydeadwire = *blip_pl2_bydeadwire;
		Blip_true_pdg = *blip_true_pdg;
		Blip_true_g4id = *blip_true_g4id;
		Blip_true_energy = *blip_true_energy;	

		int counter_blip_pd_vtx_25cm = 0;
		int counter_blip_pd_vtx_50cm = 0;	
		int counter_blip_pd_vtx_100cm = 0;	

		int counter_blip_pd_vtx_25cm_g1_anticone = 0;
		int counter_blip_pd_vtx_50cm_g1_anticone = 0;	
		int counter_blip_pd_vtx_100cm_g1_anticone = 0;	
		int counter_blip_pd_vtx_25cm_g1_cone = 0;
		int counter_blip_pd_vtx_50cm_g1_cone = 0;	
		int counter_blip_pd_vtx_100cm_g1_cone = 0;
		
		int counter_blip_pd_vtx_25cm_g2_anticone = 0;
		int counter_blip_pd_vtx_50cm_g2_anticone = 0;	
		int counter_blip_pd_vtx_100cm_g2_anticone = 0;	
		int counter_blip_pd_vtx_25cm_g2_cone = 0;
		int counter_blip_pd_vtx_50cm_g2_cone = 0;	
		int counter_blip_pd_vtx_100cm_g2_cone = 0;		

		double temp_sum_blip_e_25cm_g1_anticone = 0;
		double temp_sum_blip_e_25cm_g2_anticone = 0;
		double temp_sum_blip_e_50cm_g1_anticone = 0;
		double temp_sum_blip_e_50cm_g2_anticone = 0;
		double temp_sum_blip_e_100cm_g1_anticone = 0;
		double temp_sum_blip_e_100cm_g2_anticone = 0;	
		
		int good_reco_blips = 0;
		int temp_proton_blips = 0;

		for (int ib = 0; ib < (int)(blip_x->size()); ib++) {

			// ensure good blip quality
			if ( 
				blip_nplanes->at(ib) > 1 && // 2 & 3 matched-planes (3D-blips)
				blip_touchtrk->at(ib) == 0 && // no blips touching tracks
				blip_pl2_bydeadwire->at(ib) == 0 && // no blips by dead wires in collection plane (pl2)
				blip_proxtrkdist->at(ib) > 10 && //distance to closest track > 10 [cm] // mitigate cosmic induced blips
				blip_energy->at(ib) > 0.6 // reco blip energy [MeVee]
		
			) {

				TVector3 blip(blip_x->at(ib), blip_y->at(ib), blip_z->at(ib));

				// requirement for blip containment
				if ( tools.inFVVector(blip) ) { 

					Good_blip_energy.push_back(blip_energy->at(ib));
					Good_blip_proxtrkdist.push_back(blip_proxtrkdist->at(ib));	
					
					float ds = TMath::Sqrt( TMath::Power(blip_dx->at(ib),2) + TMath::Power(blip_dw->at(ib),2) );
					Good_blip_ds.push_back(ds);

					TVector3 pd_vertex_blip_vec = blip - pd_VertexLocation;
					double dist = pd_vertex_blip_vec.Mag();
					double g1_blip_dist = (blip - g1_start).Mag();
					double g2_blip_dist = (blip - g2_start).Mag();								

					double temp_blip_energy = blip_energy->at(ib);
					good_reco_blips++;

					double g1_cosalpha = cos_alpha(g1_start,g1.Vect(),blip);
					double g2_cosalpha = cos_alpha(g2_start,g2.Vect(),blip);
					double vt_cosalpha = cos_alpha(pd_VertexLocation,pd_VertexLocation,blip);				

					Blip_g1_cos_alpha.push_back(g1_cosalpha);
					Blip_g2_cos_alpha.push_back(g2_cosalpha);
					Blip_vt_cos_alpha.push_back(vt_cosalpha);								

					// distances in cm
					if (dist < 25) { counter_blip_pd_vtx_25cm++; }
					if (dist < 50) { counter_blip_pd_vtx_50cm++; }			
					if (dist < 100) { counter_blip_pd_vtx_100cm++; }

					// electron-like blips
					if ( IsWithinSphereOutsideConic(g1_start,g1.Vect(),blip,25) ) { 
						
						counter_blip_pd_vtx_25cm_g1_anticone++; 
						temp_sum_blip_e_25cm_g1_anticone += temp_blip_energy; 
					
					}

					if ( !IsWithinSphereOutsideConic(g1_start,g1.Vect(),blip,25) ) { counter_blip_pd_vtx_25cm_g1_cone++; }	

					if ( IsWithinSphereOutsideConic(g1_start,g1.Vect(),blip,50) ) { 
						
						counter_blip_pd_vtx_50cm_g1_anticone++; 
						temp_sum_blip_e_50cm_g1_anticone += temp_blip_energy;					
					
					}

					if ( !IsWithinSphereOutsideConic(g1_start,g1.Vect(),blip,50) ) { counter_blip_pd_vtx_50cm_g1_cone++; }

					if ( IsWithinSphereOutsideConic(g1_start,g1.Vect(),blip,100) ) { 
						
						counter_blip_pd_vtx_100cm_g1_anticone++; 
						temp_sum_blip_e_100cm_g1_anticone += temp_blip_energy;					
					
					}

					if ( !IsWithinSphereOutsideConic(g1_start,g1.Vect(),blip,100) ) { counter_blip_pd_vtx_100cm_g1_cone++; }		
					
					if ( IsWithinSphereOutsideConic(g2_start,g2.Vect(),blip,25) ) { 
						
						counter_blip_pd_vtx_25cm_g2_anticone++; 
						temp_sum_blip_e_25cm_g2_anticone += temp_blip_energy;					
					
					}

					if ( !IsWithinSphereOutsideConic(g2_start,g2.Vect(),blip,25) ) { counter_blip_pd_vtx_25cm_g2_cone++; }	

					if ( IsWithinSphereOutsideConic(g2_start,g2.Vect(),blip,50) ) { 
						
						counter_blip_pd_vtx_50cm_g2_anticone++; 
						temp_sum_blip_e_50cm_g2_anticone += temp_blip_energy;					
					
					}

					if ( !IsWithinSphereOutsideConic(g2_start,g2.Vect(),blip,50) ) { counter_blip_pd_vtx_50cm_g2_cone++; }	

					if ( IsWithinSphereOutsideConic(g2_start,g2.Vect(),blip,100) ) { 
						
						counter_blip_pd_vtx_100cm_g2_anticone++; 
						temp_sum_blip_e_100cm_g2_anticone += temp_blip_energy;					
					
					}

					if ( !IsWithinSphereOutsideConic(g2_start,g2.Vect(),blip,100) ) { counter_blip_pd_vtx_100cm_g2_cone++; }	
					
					// proton-like blips
					if ( 
						IsBackTrackedBlip(g1_blip_dist,g1_cosalpha) || 
						IsBackTrackedBlip(g2_blip_dist,g2_cosalpha) ||
						IsBackTrackedBlip(dist,vt_cosalpha)
					) {

						temp_proton_blips++;
					}

				} // ensure good blip quality

			} // end of blip containment

		}

		ngood_blips = good_reco_blips;
		
		n_blip_pd_vtx_25cm = counter_blip_pd_vtx_25cm;
		n_blip_pd_vtx_50cm = counter_blip_pd_vtx_50cm;	
		n_blip_pd_vtx_100cm = counter_blip_pd_vtx_100cm;

		n_blip_pd_vtx_25cm_g1_anticone = counter_blip_pd_vtx_25cm_g1_anticone;
		n_blip_pd_vtx_50cm_g1_anticone = counter_blip_pd_vtx_50cm_g1_anticone;	
		n_blip_pd_vtx_100cm_g1_anticone = counter_blip_pd_vtx_100cm_g1_anticone;
		n_blip_pd_vtx_25cm_g1_cone = counter_blip_pd_vtx_25cm_g1_cone;
		n_blip_pd_vtx_50cm_g1_cone = counter_blip_pd_vtx_50cm_g1_cone;	
		n_blip_pd_vtx_100cm_g1_cone = counter_blip_pd_vtx_100cm_g1_cone;	
		
		n_blip_pd_vtx_25cm_g2_anticone = counter_blip_pd_vtx_25cm_g2_anticone;
		n_blip_pd_vtx_50cm_g2_anticone = counter_blip_pd_vtx_50cm_g2_anticone;	
		n_blip_pd_vtx_100cm_g2_anticone = counter_blip_pd_vtx_100cm_g2_anticone;
		n_blip_pd_vtx_25cm_g2_cone = counter_blip_pd_vtx_25cm_g2_cone;
		n_blip_pd_vtx_50cm_g2_cone = counter_blip_pd_vtx_50cm_g2_cone;	
		n_blip_pd_vtx_100cm_g2_cone = counter_blip_pd_vtx_100cm_g2_cone;	

		sum_reco_g1_blip_e_25cm = temp_sum_blip_e_25cm_g1_anticone;
		sum_reco_g1_blip_e_50cm = temp_sum_blip_e_50cm_g1_anticone;
		sum_reco_g1_blip_e_100cm = temp_sum_blip_e_100cm_g1_anticone;
		
		sum_reco_g2_blip_e_25cm = temp_sum_blip_e_25cm_g2_anticone;
		sum_reco_g2_blip_e_50cm = temp_sum_blip_e_50cm_g2_anticone;
		sum_reco_g2_blip_e_100cm = temp_sum_blip_e_100cm_g2_anticone;	
		
		// based on Diego's study
		// https://microboone-docdb.fnal.gov/cgi-bin/sso/RetrieveFile?docid=45208&filename=Oxford_CM%20_BlipBased_0pNp_0nNn_classification_1gInc_events%2BProbing_1g0p_excess_wBlips_v3.pdf&version=2
		if (
			(n_blip_pd_vtx_100cm_g1_anticone > 10 || sum_reco_g1_blip_e_100cm > 8) || 
			(n_blip_pd_vtx_100cm_g2_anticone > 10 || sum_reco_g2_blip_e_100cm > 8) ) 
		{ reco_contains_neutron = 1; }
		else { reco_contains_neutron = 0; }

		if (temp_proton_blips != 0) { reco_contains_proton = 1; }
		else { reco_contains_proton = 0; }

		if (reco_contains_neutron == 1 || reco_contains_proton == 1) { reco_contains_proton_or_neutron = 1; }
		else { reco_contains_proton_or_neutron = 0; }

		//----------------------------------------//	
		
		// wc spacepoints

		nspacepoints = Trecchargeblob_spacepoints_x->size();
		trecchargeblob_spacepoints_x = *Trecchargeblob_spacepoints_x;
		trecchargeblob_spacepoints_y = *Trecchargeblob_spacepoints_y;
		trecchargeblob_spacepoints_z = *Trecchargeblob_spacepoints_z;
		trecchargeblob_spacepoints_q = *Trecchargeblob_spacepoints_q;
		trecchargeblob_spacepoints_real_cluster_id = *Trecchargeblob_spacepoints_real_cluster_id;			
		sp_q_median = get_median_vector(trecchargeblob_spacepoints_q);		

		//--------------------//

		// Loop over primary pfparticles
		// Reject those events with protons above kinetic energy threshold
		// The proton threshold can be located under NCpi0/generators/constants.h 

		int primary_proton_counter = 0;
		int primary_muon_counter = 0;
		int primary_charged_pion_counter = 0;
		int primary_electron_counter = 0;
		int primary_photon_counter = 0;
		int primary_neutron_counter = 0;
		int primary_neutral_pion_counter = 0;

		int secondary_proton_counter = 0;
		int secondary_muon_counter = 0;
		int secondary_charged_pion_counter = 0;
		int secondary_electron_counter = 0;
		int secondary_photon_counter = 0;
		int secondary_neutron_counter = 0;
		int secondary_neutral_pion_counter = 0;

		int pfps = reco_Ntrack;

		for (int ipfp = 0; ipfp < pfps; ipfp++ ) {

			// only primaries (mother = 0) 
			if (reco_mother[ipfp] == 0) {

				TVector3 v_mom(reco_startMomentum[ipfp][0], reco_startMomentum[ipfp][1], reco_startMomentum[ipfp][2]); 
				double mom = v_mom.Mag();

				// Only proton candidates
				if (reco_pdg[ipfp] == ProtonPdg) {

					double e = TMath::Sqrt( mom*mom + ProtonMass_GeV * ProtonMass_GeV);
					double ke = e - ProtonMass_GeV;
					if (ke > proton_ke_thres) { primary_proton_counter++; }

				} // end of the primary protons

				// Only muon candidates
				else if (reco_pdg[ipfp] == MuonPdg) {

					if (mom > 0.) { primary_muon_counter++; }
					
				} // end of the primary muons

				// Only charged pion candidates
				else if (reco_pdg[ipfp] == AbsChargedPionPdg) {

					if (mom > 0.) { primary_charged_pion_counter++; }
					
				} // end of the primary charged pions

				// Only neutral pion candidates
				else if (reco_pdg[ipfp] == NeutralPionPdg) {

					if (mom > 0.) { primary_neutral_pion_counter++; }
					
				} // end of the primary neutral pions

				// Only electron candidates
				else if (reco_pdg[ipfp] == ElectronPdg) {

					if (mom > 0.07) { primary_electron_counter++; }
										
				} // end of the primary charged pions

				// Only photon candidates
				else if (reco_pdg[ipfp] == PhotonPdg) {

					if (mom > 0.07) { primary_photon_counter++; }
										
				} // end of the primary photons

				// Only neutron candidates
				else if (reco_pdg[ipfp] == NeutronPdg) {

					double e = TMath::Sqrt( mom*mom + NeutronMass_GeV * NeutronMass_GeV);
					double ke = e - NeutronMass_GeV;						
					//cout << "neutron mom = " << mom << " ke = " << ke << " bkg_1n_0p_1pi0_X = " << bkg_1n_0p_1pi0_X << endl;
					//if (mom > 0.) { primary_neutron_counter++; }
					if (ke > 0.01) { primary_neutron_counter++; }						
										
				} // end of the primary neutrons

				else { 
						
					cout << "primary non proton/muon/charged pion/electron candidate with pdg = " << reco_pdg[ipfp] << " run = " << Run << "  subrun = " << SubRun << " event = " << Event << endl; 
					
				}

			} else {

				// secondary particles (mother != 0)
				int mother = reco_mother[ipfp];

				// loop over the secondary particles
				for (int ipfp_s = 0; ipfp_s < pfps; ipfp_s++ ) {

					if ( mother == reco_id[ipfp_s] ) {

						int secondary_pdg = reco_pdg[ipfp_s]; 

						//secondary protons
						if ( TMath::Abs(secondary_pdg) == ProtonPdg) {

							TVector3 v_mom(reco_startMomentum[ipfp_s][0], reco_startMomentum[ipfp_s][1], reco_startMomentum[ipfp_s][2]); 
							double mom = v_mom.Mag();
							double e = TMath::Sqrt( mom*mom + ProtonMass_GeV * ProtonMass_GeV);
							double ke = e - ProtonMass_GeV;

							if (ke > proton_ke_thres) { secondary_proton_counter++; }

						}

						//secondary charged pions
						else if ( TMath::Abs(secondary_pdg) == AbsChargedPionPdg) {

							secondary_charged_pion_counter++;
							
						}

						//secondary neutral pions
						else if ( TMath::Abs(secondary_pdg) == NeutralPionPdg) {

							secondary_neutral_pion_counter++;
							
						}

						//secondary muons
						else if ( TMath::Abs(secondary_pdg) == MuonPdg) {

							secondary_muon_counter++;
							
						}

						//secondary electrons
						else if ( TMath::Abs(secondary_pdg) == ElectronPdg) {

							secondary_electron_counter++;
							
						}

						//secondary photons
						else if ( TMath::Abs(secondary_pdg) == PhotonPdg) {

							secondary_photon_counter++;

							vector<double> temp_photon_sp_q;																		

							// store the relevant spacepoints for the candidate proton
							int nsps = trecchargeblob_spacepoints_x.size();								
							for (int isp = 0; isp < nsps; isp++) {

								if (trecchargeblob_spacepoints_real_cluster_id.at(isp) == wc_reco_id.at(ipfp)) { 
									
									temp_photon_sp_q.push_back(trecchargeblob_spacepoints_q.at(isp));

								}

							}	
							
							photon_q_median.push_back( get_median_vector(temp_photon_sp_q) );
							
						}

						//secondary neutrons
						else if ( TMath::Abs(secondary_pdg) == NeutronPdg) {

							secondary_neutron_counter++;

							vector<double> temp_neutron_sp_q;																		

							// store the relevant spacepoints for the candidate proton
							int nsps = trecchargeblob_spacepoints_x.size();
							for (int isp = 0; isp < nsps; isp++) {

								if (trecchargeblob_spacepoints_real_cluster_id.at(isp) == wc_reco_id.at(ipfp)) { 
									
									temp_neutron_sp_q.push_back(trecchargeblob_spacepoints_q.at(isp));

								}

							}
							
							neutron_q_median.push_back( get_median_vector(temp_neutron_sp_q) );					
							
						}

						else { 
						
							cout << "secondary non proton/muon/charged pion/electron candidate with pdg = " << reco_pdg[ipfp_s] << " run = " << Run << "  subrun = " << SubRun << " event = " << Event << endl; 
							
						}

					} // end of grabbing the correct secondary particle

				} // end of the loop over the secondary particles

			}

		}

		wc_primary_proton_counter = primary_proton_counter;
		wc_primary_muon_counter = primary_muon_counter;
		wc_primary_charged_pion_counter = primary_charged_pion_counter;
		wc_primary_electron_counter = primary_electron_counter;
		wc_primary_photon_counter = primary_photon_counter;
		wc_primary_neutron_counter = primary_neutron_counter;
		wc_primary_neutral_pion_counter = primary_neutral_pion_counter;

		wc_secondary_proton_counter = secondary_proton_counter;
		wc_secondary_muon_counter = secondary_muon_counter;
		wc_secondary_charged_pion_counter = secondary_charged_pion_counter;
		wc_secondary_electron_counter = secondary_electron_counter;
		wc_secondary_photon_counter = secondary_photon_counter;
		wc_secondary_neutron_counter = secondary_neutron_counter;
		wc_secondary_neutral_pion_counter = secondary_neutral_pion_counter;		

		//--------------------//

		// Reject events that do not have two showers

		int nshowers = 0;
		int nshowers_0MeV = 0;
		int nshowers_20MeV = 0;				
		int nmuontracks = 0;
		int nprotontracks = 0;
		int npiontracks = 0;

		for(int i=0; i < (int)kine_energy_particle->size(); i++) {

			int pdgcode = kine_particle_type->at(i);

			if( TMath::Abs(pdgcode) == ElectronPdg && kine_energy_particle->at(i) > 10) { // KE in MeV
					
				nshowers++;

			}

			if( TMath::Abs(pdgcode) == ElectronPdg && kine_energy_particle->at(i) > 0) { // KE in MeV
					
				nshowers_0MeV++;

			}	
			
			if( TMath::Abs(pdgcode) == ElectronPdg && kine_energy_particle->at(i) > 0) { // KE in MeV
					
				nshowers_20MeV++;

			}				

			else if( TMath::Abs(pdgcode) == ProtonPdg && kine_energy_particle->at(i) > 10) { // KE in MeV
					
				nprotontracks++;

			}			
				
			else if( TMath::Abs(pdgcode) == MuonPdg && kine_energy_particle->at(i) > 10) { // KE in MeV
					
				nmuontracks++;

			}	
				
			else if( TMath::Abs(pdgcode) == AbsChargedPionPdg && kine_energy_particle->at(i) > 10) { // KE in MeV
					
				npiontracks++;

			}	

		}		

		wc_nshowers_0MeV = nshowers_0MeV;	
		wc_nshowers_20MeV = nshowers_20MeV;				
		wc_nshowers = nshowers;
		wc_nmuontracks = nmuontracks;
		wc_nprotontracks = nprotontracks;
		wc_npiontracks = npiontracks;	
		
		wc_shw_sp_n_good_showers = shw_sp_n_good_showers;
		wc_shw_sp_n_20mev_showers = shw_sp_n_20mev_showers;
		wc_shw_sp_n_br1_showers = shw_sp_n_br1_showers;
		wc_shw_sp_n_br2_showers = shw_sp_n_br2_showers;
		wc_shw_sp_n_br3_showers = shw_sp_n_br3_showers;
		wc_shw_sp_n_br4_showers = shw_sp_n_br4_showers;
		wc_shw_sp_n_20br1_showers = shw_sp_n_20br1_showers;		

		//--------------------//

		//Pandora info
		
		pd_trk_score_v = *trk_score_v;
		pd_generation_v = *pfp_generation_v;
		pd_trk_llr_pid_score_v = *trk_llr_pid_score_v;
		pd_shr_score = shr_score;

		int reco_shower_count = 0;
		int reco_track_count = 0;

		int reco_secondary_shower_count = 0;
		int reco_secondary_track_count = 0;		

		for ( int p = 0; p < n_pfps; ++p ) {

			// check direct neutrino daughters (generation == 2)
			// and secondary particles 

 			unsigned int generation = pfp_generation_v->at( p );

			if ( generation == 2u ) {

				float tscore = trk_score_v->at( p );
				if ( tscore <= TRACK_SCORE_CUT ) { ++reco_shower_count; }
				else { ++reco_track_count; }
  
			}

			if ( generation == 3u ) {

				float sec_tscore = trk_score_v->at( p );
				if ( sec_tscore <= TRACK_SCORE_CUT ) { ++reco_secondary_shower_count; }
				else { ++reco_secondary_track_count; }
  
			}			


		}

		pd_reco_track_count = reco_track_count;
		pd_reco_shower_count = reco_shower_count;

		pd_reco_secondary_track_count = reco_secondary_track_count;
		pd_reco_secondary_shower_count = reco_secondary_shower_count;		

		if (pd_reco_track_count > 0) { continue; }
		if ( pio.CosTheta() <  pi0_costheta_thres) { continue; }		

		candidate_events++;

		if (signal) { counter_signal++; }	

		else if (bkg_0pi0_X) { counter_bkg_0pi0_X++; }
		else if (bkg_Mpi0_X) { counter_bkg_Mpi0_X++; }
		else if (bkg_bwds_1pi0_X) { counter_bkg_bwds_1pi0_X++; }		
		else if (bkg_1n_0p_1pi0_X) { counter_bkg_1n_0p_1pi0_X++; }	
		else if (bkg_Nn_0p_1pi0_X) { counter_bkg_Nn_0p_1pi0_X++; }
		else if (bkg_1p_0n_1pi0_X) { counter_bkg_1p_0n_1pi0_X++; }	
		else if (bkg_Np_0n_1pi0_X) { counter_bkg_Np_0n_1pi0_X++; }	
		else if (bkg_1pi0_Npipm_X) { counter_bkg_1pi0_Npipm_X++; }	
		else if (bkg_1pi0_Np_Nn_0pipm_X) { counter_bkg_1pi0_Np_Nn_0pipm_X++; }
		else if (bkg_1pi0_Np_Nn_Npipm_X) { counter_bkg_1pi0_Np_Nn_Npipm_X++; }			
		else if (bkg_1pi0_Nmh_X) { counter_bkg_1pi0_Nmh_X++; }	
		else if (bkg_1pi0_Nl_X) { counter_bkg_1pi0_Nl_X++; }										
		else { counter_bkg_other++; }	

		//--------------------//
		
		// pandora nugraph

		pd_slcng2mip = slcng2mip;
		pd_slcng2hip = slcng2hip;
		pd_slcng2shr = slcng2shr;
		pd_slcng2mcl = slcng2mcl;
		pd_slcng2dfs = slcng2dfs;
		pd_slcng2bkg = slcng2bkg;
		pd_clung2mip = clung2mip;
		pd_clung2hip = clung2hip;
		pd_clung2shr = clung2shr;
		pd_clung2mcl = clung2mcl;
		pd_clung2dfs = clung2dfs;
		pd_clung2bkg = clung2bkg;
		pd_pfng2semlabel = *pfng2semlabel;
		pd_pfng2mipfrac = *pfng2mipfrac;
		pd_pfng2hipfrac = *pfng2hipfrac;
		pd_pfng2shrfrac = *pfng2shrfrac;
		pd_pfng2mclfrac = *pfng2mclfrac;
		pd_pfng2dfsfrac = *pfng2dfsfrac;
		pd_pfng2bkgfrac = *pfng2bkgfrac;
		pd_pfng2mipavrg = *pfng2mipavrg;
		pd_pfng2hipavrg = *pfng2hipavrg;
		pd_pfng2shravrg = *pfng2shravrg;
		pd_pfng2mclavrg = *pfng2mclavrg;
		pd_pfng2dfsavrg = *pfng2dfsavrg;
		pd_pfng2bkgavrg = *pfng2bkgavrg;			

		//--------------------//

		// glee

		gl_trackstub_candidate_veto_score = *trackstub_candidate_veto_score;	
		gl_trackstub_num_candidates = trackstub_num_candidates;
		gl_reco_vertex_x = reco_vertex_x;
		gl_reco_vertex_y = reco_vertex_y;
		gl_reco_vertex_z = reco_vertex_z;	
		
		TVector3 gl_vertex(reco_vertex_x, reco_vertex_y, reco_vertex_z);
		gl_vertex_contained = tools.inFVVector(gl_vertex);
		gl_sss_num_candidates = sss_num_candidates;
		gl_reco_asso_showers = reco_asso_showers;
		gl_reco_asso_tracks = reco_asso_tracks;				

		//--------------------//

		// wc backtracking only for mc

		if (string(fLabel).find("Overlay") != std::string::npos) {

			// loop over the reco objects
			for (int i = 0; i < reco_Ntrack; i++) {

				int id = reco_truthMatch_id[i];
				int truthMatch_id = -1;				

				// two photon candidates
				if ( i == wc_reco_g1_id || i == wc_reco_g2_id ) {

					// loop over the truth objects
					// for the two photons
					for (int t = 0; t < truth_Ntrack; t++) {

						if (truth_id[t] == id) {

							truthMatch_id = t;
							break;

						}
						
					} // end of the truth loop

					if ( i == wc_reco_g1_id ) {

						g1_truthMatch_pdg = truth_pdg[truthMatch_id];
						g1_truthMatch_p = truth_startMomentum[truthMatch_id][3];

						TVector3 g1_truthMatch_v(truth_startMomentum[truthMatch_id][0], truth_startMomentum[truthMatch_id][1], truth_startMomentum[truthMatch_id][2]);
						g1_truthMatch_px = g1_truthMatch_v.X();
						g1_truthMatch_py = g1_truthMatch_v.Y();
						g1_truthMatch_pz = g1_truthMatch_v.Z();
						g1_truthMatch_costheta = g1_truthMatch_v.CosTheta();
						g1_truthMatch_phi = g1_truthMatch_v.Phi(); // rad	

					}

					if ( i == wc_reco_g2_id ) {

						g2_truthMatch_pdg = truth_pdg[truthMatch_id];
						g2_truthMatch_p = truth_startMomentum[truthMatch_id][3];

						TVector3 g2_truthMatch_v(truth_startMomentum[truthMatch_id][0], truth_startMomentum[truthMatch_id][1], truth_startMomentum[truthMatch_id][2]);
						g2_truthMatch_px = g2_truthMatch_v.X();
						g2_truthMatch_py = g2_truthMatch_v.Y();
						g2_truthMatch_pz = g2_truthMatch_v.Z();
						g2_truthMatch_costheta = g2_truthMatch_v.CosTheta();
						g2_truthMatch_phi = g2_truthMatch_v.Phi(); // rad	

					}
					
				} // end of two-photon candidate case	
			
				else {

					// non-photon particles
					for (int t = 0; t < truth_Ntrack; t++) {

						// proton backtracking
						if (truth_id[t] == id && truth_pdg[t] == ProtonPdg) {

							double p = truth_startMomentum[t][3];
							double ke = TMath::Sqrt( TMath::Power(ProtonMass_GeV,2.) + TMath::Power(p,2.) ) - ProtonMass_GeV;

							proton_truthMatch_p.push_back(p);
							proton_truthMatch_ke.push_back(ke);							
							
							break;

						}

						// neutron backtracking
						if (truth_id[t] == id && truth_pdg[t] == NeutronPdg) {

							double p = truth_startMomentum[t][3];
							double ke = TMath::Sqrt( TMath::Power(NeutronMass_GeV,2.) + TMath::Power(p,2.) ) - NeutronMass_GeV;

							neutron_truthMatch_p.push_back(truth_startMomentum[t][3]);
							neutron_truthMatch_ke.push_back(ke);

							break;

						}					
							
					} // end of the truth loop

				}

			}				
				
		} // end of backtracking 

		//--------------------//
		
		// dl lantern

		int counter_dl_secondary_tracks = 0;
		int counter_dl_secondary_showers = 0;		

		for (int idl = 0; idl < nTracks; idl++) {

			if (trackIsSecondary[idl] == 1) { counter_dl_secondary_tracks++; }

		}

		for (int idl = 0; idl < nShowers; idl++) {

			if (showerIsSecondary[idl] == 1) { counter_dl_secondary_showers++; }

		}		

		dl_foundVertex = foundVertex;
		dl_vtxX = vtxX;
		dl_vtxY = vtxY;
		dl_vtxZ = vtxZ;
		dl_vtxScore = vtxScore; 
		dl_nTracks = nTracks;
		dl_nShowers = nShowers;		 
		dl_nSecTracks = counter_dl_secondary_tracks;
		dl_nSecShowers = counter_dl_secondary_showers;

		TVector3 dl_vertex(vtxX, vtxY, vtxZ);
		dl_vertex_contained = tools.inFVVector(dl_vertex);

		//--------------------//

		// distance between different reco vertices

		pd_wc_vtx_dist = (pd_VertexLocation - VertexLocation).Mag();
		pd_gl_vtx_dist = (pd_VertexLocation - gl_vertex).Mag();
		pd_dl_vtx_dist = (pd_VertexLocation - dl_vertex).Mag();
		wc_gl_vtx_dist = (VertexLocation - gl_vertex).Mag();
		wc_dl_vtx_dist = (VertexLocation - dl_vertex).Mag();
		gl_dl_vtx_dist = (gl_vertex - dl_vertex).Mag();	

		//--------------------//
		
		// playground

		if (fLabel.Contains("ben_neutron_bdt")) {
		
			wc_n_veto_nonprim_score = n_veto_nonprim_score; 
			wc_n_veto_all_score = n_veto_all_score;
			wc_n_veto_score = n_veto_score;					

		}

		//--------------------//

		// Finally fill the TTree
		tree->Fill();

		//--------------------//

	}

	//--------------------//

	OutputFile->cd();
	OutputFile->Write();
	OutputFile->Close();
	std::cout << std::endl << "File " << FileName << " has been created"<< std::endl << std::endl;
	cout << "pot scale = " << POTScale << endl << endl;

	//--------------------//

	cout << "candidate events = " << candidate_events << endl;

	if (string(fLabel).find("Overlay") != std::string::npos) {

		cout << "signal events = " << counter_signal << " (" << to_string_with_precision( double(counter_signal)/double(candidate_events)*100.,1.) << "%)" << endl;
		cout << "bkg_bwds_1pi0_X = " << counter_bkg_bwds_1pi0_X << " (" << to_string_with_precision( double(counter_bkg_bwds_1pi0_X)/double(candidate_events)*100.,1.) << "%)" << endl;

		cout << "bkg_0pi0_X = " << counter_bkg_0pi0_X << " (" << to_string_with_precision( double(counter_bkg_0pi0_X)/double(candidate_events)*100.,1.) << "%)" << endl;
		cout << "bkg_Mpi0_X = " << counter_bkg_Mpi0_X << " (" << to_string_with_precision( double(counter_bkg_Mpi0_X)/double(candidate_events)*100.,1.) << "%)" << endl;
		cout << "bkg_1n_0p_1pi0_X = " << counter_bkg_1n_0p_1pi0_X << " (" << to_string_with_precision( double(counter_bkg_1n_0p_1pi0_X)/double(candidate_events)*100.,1.) << "%)" << endl;
		cout << "bkg_Nn_0p_1pi0_X = " << counter_bkg_Nn_0p_1pi0_X << " (" << to_string_with_precision( double(counter_bkg_Nn_0p_1pi0_X)/double(candidate_events)*100.,1.) << "%)" << endl;
		cout << "bkg_1p_0n_1pi0_X = " << counter_bkg_1p_0n_1pi0_X << " (" << to_string_with_precision( double(counter_bkg_1p_0n_1pi0_X)/double(candidate_events)*100.,1.) << "%)" << endl;
		cout << "bkg_Np_0n_1pi0_X = " << counter_bkg_Np_0n_1pi0_X << " (" << to_string_with_precision( double(counter_bkg_Np_0n_1pi0_X)/double(candidate_events)*100.,1.) << "%)" << endl;
		cout << "bkg_1pi0_Npipm_X = " << counter_bkg_1pi0_Npipm_X << " (" << to_string_with_precision( double(counter_bkg_1pi0_Npipm_X)/double(candidate_events)*100.,1.) << "%)" << endl;
		cout << "bkg_1pi0_Np_Nn_0pipm_X = " << counter_bkg_1pi0_Np_Nn_0pipm_X << " (" << to_string_with_precision( double(counter_bkg_1pi0_Np_Nn_0pipm_X)/double(candidate_events)*100.,1.) << "%)" << endl;
		cout << "bkg_1pi0_Np_Nn_Npipm_X = " << counter_bkg_1pi0_Np_Nn_Npipm_X << " (" << to_string_with_precision( double(counter_bkg_1pi0_Np_Nn_Npipm_X)/double(candidate_events)*100.,1.) << "%)" << endl;		
		cout << "bkg_1pi0_Nmh_X = " << counter_bkg_1pi0_Nmh_X << " (" << to_string_with_precision( double(counter_bkg_1pi0_Nmh_X)/double(candidate_events)*100.,1.) << "%)" << endl;
		cout << "bkg_bkg_1pi0_Nl_X = " << counter_bkg_1pi0_Nl_X << " (" << to_string_with_precision( double(counter_bkg_1pi0_Nl_X)/double(candidate_events)*100.,1.) << "%)" << endl;								
		cout << "bkg_other = " << counter_bkg_other << " (" << to_string_with_precision( double(counter_bkg_other)/double(candidate_events)*100.,1.) << "%)" << endl;							 	

	}

	//--------------------//

} // End of the program