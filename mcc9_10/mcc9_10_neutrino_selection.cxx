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

using namespace std;
using namespace constants;

//--------------------//

void mcc9_10_neutrino_selection::Loop() {

	//--------------------//

	TH1D::SetDefaultSumw2();
	TH2D::SetDefaultSumw2();

	//--------------------//

	// Output Files

	TString FileName = preselection_file_path + "/PreSelection_"+fLabel+".root";
	TFile* OutputFile = new TFile(FileName,"recreate");
	std::cout << std::endl << "File " << FileName << " to be created"<< std::endl << std::endl;

	//--------------------//

	if (fChain == 0) return;

	Long64_t nentries = fChain->GetEntriesFast();
	cout << "file entries = " << nentries << endl;
	Long64_t nbytes = 0, nb = 0;

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

	//--------------------//

	std::vector<float> Vertex_X;
	std::vector<float> Vertex_Y;
	std::vector<float> Vertex_Z;

	//--------------------//

	// pi0

	std::vector<double> reco_shower_opening_angle;
	std::vector<double> reco_alpha;

	std::vector<double> reco_pi0_p_gammas;
	std::vector<double> reco_pi0_p;
	std::vector<double> reco_pi0_phi; // rad
	std::vector<double> reco_pi0_costheta;
	std::vector<double> reco_pi0_invmass;	

	//--------------------//

	// leading gamma (g1)

	std::vector<double> reco_g1_p;
	std::vector<double> reco_g1_phi; // rad
	std::vector<double> reco_g1_costheta;

	//--------------------//

	// secondary gamma (g2)	

	std::vector<double> reco_g2_p;
	std::vector<double> reco_g2_phi; // rad
	std::vector<double> reco_g2_costheta;
	
	//--------------------//

	// Blip info

	Int_t           nBlips_saved;
	vector<float>   Blip_x;
	vector<float>   Blip_y;
	vector<float>   Blip_z;
	vector<float>   Blip_energy;
	vector<float>   Blip_charge;
	vector<int>     Blip_nplanes;
	vector<float>   Blip_proxtrkdist;
	vector<int>     Blip_proxtrkid;
	vector<bool>    Blip_touchtrk;
	vector<int>     Blip_touchtrkid;
	vector<int>     Blip_pl0_nwires;
	vector<int>     Blip_pl1_nwires;
	vector<int>     Blip_pl2_nwires;
	vector<bool>    Blip_pl0_bydeadwire;
	vector<bool>    Blip_pl1_bydeadwire;
	vector<bool>    Blip_pl2_bydeadwire;
	vector<int>     Blip_true_g4id;
	vector<float>   Blip_true_energy;

	//--------------------//

	// Pandora info

	vector<unsigned int> pd_generation_v;
	vector<float> pd_trk_score_v;
	vector<float> pd_trk_llr_pid_score_v;

	int pd_reco_track_count;
	int pd_reco_shower_count;

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
	tree->Branch("wc_kine_particle_type",&wc_kine_particle_type);
	tree->Branch("wc_kine_energy_particle",&wc_kine_energy_particle);

	tree->Branch("Run",&Run);
	tree->Branch("SubRun",&SubRun);
	tree->Branch("Event",&Event);	
	tree->Branch("run_period",&run_period);

	tree->Branch("signal",&signal);
	tree->Branch("nc",&nc);
	tree->Branch("numu",&numu);
	tree->Branch("qe",&qe);
	tree->Branch("mec",&mec);
	tree->Branch("res",&res);
	tree->Branch("dis",&dis);
	tree->Branch("coh",&coh);
	tree->Branch("other",&other);
	
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
		
	//--------------------//

	// wc pfparticles

	std::vector<int> wc_reco_mother;
	std::vector< std::vector<float> > wc_reco_p;
	std::vector< std::vector<float> > wc_reco_start;
	std::vector< std::vector<float> > wc_reco_end;
	std::vector<int> wc_reco_pdg;
	std::vector<int> wc_reco_id;

	tree->Branch("wc_reco_mother",&wc_reco_mother);
	tree->Branch("wc_reco_p",&wc_reco_p);
	tree->Branch("wc_reco_start",&wc_reco_start);
	tree->Branch("wc_reco_end",&wc_reco_end);
	tree->Branch("wc_reco_pdg",&wc_reco_pdg);
	tree->Branch("wc_reco_id",&wc_reco_id);	

	//--------------------//

	//pi0

	tree->Branch("reco_alpha",&reco_alpha);	
	tree->Branch("reco_shower_opening_angle",&reco_shower_opening_angle);	
	tree->Branch("reco_pi0_p_gammas",&reco_pi0_p_gammas);
	tree->Branch("reco_pi0_p",&reco_pi0_p);	
	tree->Branch("reco_pi0_phi",&reco_pi0_phi);
	tree->Branch("reco_pi0_costheta",&reco_pi0_costheta);
	tree->Branch("reco_pi0_invmass",&reco_pi0_invmass);		

	//--------------------//

	// leading gamma (g1)

	tree->Branch("reco_g1_p",&reco_g1_p);	
	tree->Branch("reco_g1_phi",&reco_g1_phi);
	tree->Branch("reco_g1_costheta",&reco_g1_costheta);	

	//--------------------//

	// secondary gamma (g2)	

	tree->Branch("reco_g2_p",&reco_g2_p);	
	tree->Branch("reco_g2_phi",&reco_g2_phi);
	tree->Branch("reco_g2_costheta",&reco_g2_costheta);	

	//--------------------//

	// Blip info

	tree->Branch("nBlips_saved",&nBlips_saved);
	tree->Branch("Blip_x",&Blip_x);
	tree->Branch("Blip_y",&Blip_y);
	tree->Branch("Blip_z",&Blip_z);
	tree->Branch("Blip_energy",&Blip_energy);
	tree->Branch("Blip_charge",&Blip_charge);
	tree->Branch("Blip_nplanes",&Blip_nplanes);
	tree->Branch("Blip_proxtrkdist",&Blip_proxtrkdist);
	tree->Branch("Blip_proxtrkid",&Blip_proxtrkid);
	tree->Branch("Blip_touchtrk",&Blip_touchtrk);
	tree->Branch("Blip_touchtrkid",&Blip_touchtrkid);
	tree->Branch("Blip_pl0_nwires",&Blip_pl0_nwires);
	tree->Branch("Blip_pl1_nwires",&Blip_pl1_nwires);
	tree->Branch("Blip_pl2_nwires",&Blip_pl2_nwires);
	tree->Branch("Blip_pl0_bydeadwire",&Blip_pl0_bydeadwire);
	tree->Branch("Blip_pl1_bydeadwire",&Blip_pl1_bydeadwire);
	tree->Branch("Blip_pl2_bydeadwire",&Blip_pl2_bydeadwire);
	tree->Branch("Blip_true_g4id",&Blip_true_g4id);	
	tree->Branch("Blip_true_energy",&Blip_true_energy);

	//--------------------//

	// Pandora info

	tree->Branch("pd_generation_v",&pd_generation_v);
	tree->Branch("pd_trk_score_v",&pd_trk_score_v);
	tree->Branch("pd_trk_llr_pid_score_v",&pd_trk_llr_pid_score_v);
	tree->Branch("pd_reco_track_count",&pd_reco_track_count);
	tree->Branch("pd_reco_shower_count",&pd_reco_shower_count);

	//--------------------//

	Tools tools;

	//--------------------//

	// Counters

	int SelectedEvents = 0;

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

	//--------------------//

	// WC Generic neutrino selection

	Float_t         single_photon_numu_score;
	Float_t         single_photon_other_score;
	Float_t         single_photon_ncpi0_score;
	Float_t         single_photon_nue_score;
	int reco_Ntrack;
	float numu_score;	
	float nc_pio_score;	
	float kine_pio_vtx_dis;
	float kine_pio_energy_1;	
	float kine_pio_theta_1;	
	float kine_pio_phi_1;	
	float kine_pio_energy_2;
	float kine_pio_theta_2;
	float kine_pio_phi_2;	
	float kine_pio_angle;		
	bool match_isFC;
	int kine_pio_flag;	
	float reco_nuvtxX;
	float reco_nuvtxY;
	float reco_nuvtxZ;
	vector<int> *kine_particle_type; // reco pdg
	vector<float> *kine_energy_particle; // KE in MeV
	Int_t reco_mother[500];   //[reco_Ntrack]
	Float_t reco_startMomentum[500][4];   //[reco_Ntrack]
	Float_t reco_startXYZT[500][4];   //[reco_Ntrack]
	Float_t reco_endXYZT[500][4];   //[reco_Ntrack]
	Int_t reco_pdg[500];   //[reco_Ntrack]
	Int_t reco_id[500];   //[reco_Ntrack]

	kine_particle_type = 0;
	kine_energy_particle = 0;	

	TBranch        *b_single_photon_numu_score;   //!
	TBranch        *b_single_photon_other_score;   //!
	TBranch        *b_single_photon_ncpi0_score;   //!
	TBranch        *b_single_photon_nue_score;   //!
	TBranch* b_reco_Ntrack;
	TBranch* b_numu_score;
	TBranch* b_nc_pio_score;
	TBranch* b_kine_pio_vtx_dis;
	TBranch* b_kine_pio_energy_1;
	TBranch* b_kine_pio_theta_1;
	TBranch* b_kine_pio_phi_1;
	TBranch* b_kine_pio_energy_2;
	TBranch* b_kine_pio_theta_2;
	TBranch* b_kine_pio_phi_2;
	TBranch* b_kine_pio_angle;
	TBranch* b_match_isFC;
	TBranch* b_kine_pio_flag;
	TBranch* b_reco_nuvtxX;
	TBranch* b_reco_nuvtxY;
	TBranch* b_reco_nuvtxZ;
	TBranch* b_kine_particle_type;
	TBranch* b_kine_energy_particle;
	TBranch* b_reco_mother;
	TBranch* b_reco_startMomentum;
	TBranch* b_reco_startXYZT;
	TBranch* b_reco_endXYZT;
	TBranch* b_reco_pdg;
	TBranch* b_reco_id;

	Long64_t wc_nbytes = 0, wc_nb = 0;  
	TTree* wc = nullptr;

	Long64_t wc_kine_nbytes = 0, wc_kine_nb = 0;  	
	TTree* wc_kine = nullptr;	

	Long64_t wc_eval_nbytes = 0, wc_eval_nb = 0;  	
	TTree* wc_eval = nullptr;	

	Long64_t wc_pfeval_nbytes = 0, wc_pfeval_nb = 0;  	
	TTree* wc_pfeval = nullptr;	

	if (fSample.Contains("unified")) {

		wc = (TTree*)(f_file->Get("wcpselection/T_BDTvars"));
		wc->SetBranchAddress("nc_pio_score", &nc_pio_score, &b_nc_pio_score);
		wc->SetBranchAddress("numu_score", &numu_score, &b_numu_score);
		wc->SetBranchAddress("single_photon_numu_score", &single_photon_numu_score, &b_single_photon_numu_score);
		wc->SetBranchAddress("single_photon_other_score", &single_photon_other_score, &b_single_photon_other_score);
		wc->SetBranchAddress("single_photon_ncpi0_score", &single_photon_ncpi0_score, &b_single_photon_ncpi0_score);
		wc->SetBranchAddress("single_photon_nue_score", &single_photon_nue_score, &b_single_photon_nue_score);

		wc_kine = (TTree*)(f_file->Get("wcpselection/T_KINEvars"));
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
		
		wc_eval = (TTree*)(f_file->Get("wcpselection/T_eval"));
		wc_eval->SetBranchAddress("match_isFC", &match_isFC, &b_match_isFC);	
		
		wc_pfeval = (TTree*)(f_file->Get("wcpselection/T_PFeval"));
		wc_pfeval->SetBranchAddress("reco_nuvtxX", &reco_nuvtxX, &b_reco_nuvtxX);	
		wc_pfeval->SetBranchAddress("reco_nuvtxY", &reco_nuvtxY, &b_reco_nuvtxY);	
		wc_pfeval->SetBranchAddress("reco_nuvtxZ", &reco_nuvtxZ, &b_reco_nuvtxZ);	

		wc_pfeval->SetBranchAddress("reco_Ntrack", &reco_Ntrack, &b_reco_Ntrack);
		wc_pfeval->SetBranchAddress("reco_mother", &reco_mother, &b_reco_mother);	
		wc_pfeval->SetBranchAddress("reco_startMomentum", &reco_startMomentum, &b_reco_startMomentum);	
		wc_pfeval->SetBranchAddress("reco_startXYZT", &reco_startXYZT, &b_reco_startXYZT);	
		wc_pfeval->SetBranchAddress("reco_endXYZT", &reco_endXYZT, &b_reco_endXYZT);	
		wc_pfeval->SetBranchAddress("reco_pdg", &reco_pdg, &b_reco_pdg);
		wc_pfeval->SetBranchAddress("reco_id", &reco_id, &b_reco_id);

	}

	//--------------------//

	for (Long64_t jentry=0; jentry<nentries;jentry++) {

		//--------------------//
      
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
      	nb = fChain->GetEntry(jentry);   nbytes += nb;

		if (fSample.Contains("unified")) {

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
		
		}		

		//--------------------//

		if (jentry%1000 == 0) std::cout << jentry/1000 << " k " << std::setprecision(3) << double(jentry)/nentries*100. << " %"<< std::endl;

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

		// Loop over the candidate track pairs

		Vertex_X.clear();
		Vertex_Y.clear();
		Vertex_Z.clear();

		//--------------------//

		// pi0

		reco_alpha.clear();
		reco_shower_opening_angle.clear();
		reco_pi0_p_gammas.clear();	
		reco_pi0_p.clear();	
		reco_pi0_phi.clear();
		reco_pi0_costheta.clear();	
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
		
		//--------------------//

		// Blips

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
		Blip_true_g4id.clear();
		Blip_true_energy.clear();		

		//--------------------//

		// WC vectors

		wc_kine_particle_type.clear();
		wc_kine_energy_particle.clear();
		wc_reco_pdg.clear();
		wc_reco_id.clear();
		wc_reco_mother.clear();
		wc_reco_p.clear();
		wc_reco_start.clear();
		wc_reco_end.clear();

		//--------------------//

		// Pandora info

		pd_generation_v.clear();
		pd_trk_score_v.clear();
		pd_trk_llr_pid_score_v.clear();

		//--------------------//

		// Requirement for two well-reconstructed and fully contained photons

		if (kine_pio_energy_1 <= 0) { continue; }
		if (kine_pio_energy_2 <= 0) { continue; }
		if (match_isFC != 1) { continue; }

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

		//if (!tools.inFVVector(VertexLocation) ) { continue; }

		Vertex_X.push_back(reco_nuvtxX);
		Vertex_Y.push_back(reco_nuvtxY);
		Vertex_Z.push_back(reco_nuvtxZ);

		MCParticle_Mode = interaction;

		//--------------------//

		// Candidate leading gamma (g1)

		// if data, scale energy by 0.95
		double Egamma1 = kine_pio_energy_1;
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
		double Egamma2 = kine_pio_energy_2;
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
		
		if ( pio.CosTheta() <  pi0_costheta_thres) { continue; }

		//--------------------//

		// WC primary and non-primary pfparticles

		wc_reco_p.resize(reco_Ntrack);
		wc_reco_start.resize(reco_Ntrack);
		wc_reco_end.resize(reco_Ntrack);

		for (int i = 0; i < reco_Ntrack; i++) {

			wc_reco_mother.push_back(reco_mother[i]);
			wc_reco_pdg.push_back(reco_pdg[i]);
			wc_reco_id.push_back(reco_id[i]);

			for (int j = 0; j < 4; j++) {

				wc_reco_p.at(i).push_back( reco_startMomentum[i][j] ); // GeV
				wc_reco_start.at(i).push_back( reco_startXYZT[i][j] ); // cm
				wc_reco_end.at(i).push_back( reco_endXYZT[i][j] ); // cm

			}

		}

		//--------------------//

		// True neutrino vertex

		if (string(fLabel).find("Overlay") != std::string::npos) {

			True_Ev = nu_e;
			True_Vx = true_nu_vtx_x;
			True_Vy = true_nu_vtx_y;
			True_Vz = true_nu_vtx_z;

		} else {

			True_Ev = CosmicPID;
			True_Vx = CosmicPID;
			True_Vy = CosmicPID;
			True_Vz = CosmicPID;

		}

		//----------------------------------------//
		
		TVector3 TrueNu_Vertex(True_Vx,True_Vy,True_Vz);
		bool TrueNu_Vertex_Containment = tools.inFVVector(TrueNu_Vertex);
		
		//----------------------------------------//

		// Now truth level loop 

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

		int ProtonTagging = 0, ChargedPionTagging = 0, Pi0Tagging = 0;
		int heavy_meason_tagging = 0, SigmaTagging = 0, LambdaTagging = 0;
		int PhotonTagging = 0, LeptonTagging = 0 , cluster_tagging = 0;
		int neutron_tagging = 0;

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

			for (int i_mc = 0; i_mc < NMCParticles; i_mc++) {

				// MC truth information for the final-state primary particles

				// NC events, any neutrino flavor	

				if (ccnc == 1) {

					TVector3 MCParticle(mc_px->at(i_mc),mc_py->at(i_mc),mc_pz->at(i_mc));
					double MCParticleMomentum = MCParticle.Mag();
					int MCParticlePdg = mc_pdg->at(i_mc);

					if (MCParticlePdg == ProtonPdg ) {

						double E = TMath::Sqrt( TMath::Power(MCParticleMomentum,2.) + TMath::Power(ProtonMass_GeV,2.) );
						double ke = E - ProtonMass_GeV;

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
						|| fabs(MCParticlePdg) == eta_pdg || fabs(MCParticlePdg) == omega_pdg)  {

						heavy_meason_tagging ++;
			
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

					else if ( fabs(MCParticlePdg) == hydrogen_cluster_pdg || fabs(MCParticlePdg) == nucleon_pair
						|| fabs(MCParticlePdg) == ArgonPdg || fabs(MCParticlePdg) == neutron_pair || fabs(MCParticlePdg) == proton_pair) {

						// Ignore neutrons, numus, nues

					}

					else if ( fabs(MCParticlePdg) == NuMuPdg || fabs(MCParticlePdg) == nue_pdg) {

						// Ignore numus, nues

					}

					else if (MCParticlePdg == NeutronPdg ) {

						double E = TMath::Sqrt( TMath::Power(MCParticleMomentum,2.) + TMath::Power(NeutronMass_GeV,2.) );
						double ke = E - NeutronMass_GeV;

						// proton kinetic energy threshold
						if ( ke > neutron_ke_thres ) {

							neutron_tagging ++;

						}

					}

					else { cout << "post fsi pdg " << MCParticlePdg << endl; }
				
				} // End of the demand stable final state particles and primary interactions

			} // end of the loop over the MCParticles

		}

		//--------------------//

		// NCCOh-like Signal events	

		if (
			Pi0Tagging == 1 && ProtonTagging == 0 && ChargedPionTagging == 0 && 
		   heavy_meason_tagging == 0 && LambdaTagging == 0 && SigmaTagging == 0 &&
		   PhotonTagging == 0 && LeptonTagging == 0 && cluster_tagging == 0 && neutron_tagging == 0
		) {

			fsignal = 1;
 
			TVector3 MCParticle(mc_px->at( Pi0ID.at(0) ),mc_py->at( Pi0ID.at(0) ), mc_pz->at( Pi0ID.at(0) ));
			double pi0_TrueCosTheta = MCParticle.CosTheta(); 
			 if (pi0_TrueCosTheta < pi0_costheta_thres) { fsignal = 0; }

		}

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
		Blip_true_g4id = *blip_true_g4id;
		Blip_true_energy = *blip_true_energy;	

		//--------------------//

		//Pandora info
		
		pd_trk_score_v = *trk_score_v;
		pd_generation_v = *pfp_generation_v;
		pd_trk_llr_pid_score_v = *trk_llr_pid_score_v;

		int reco_shower_count = 0;
		int reco_track_count = 0;

		for ( int p = 0; p < n_pfps; ++p ) {

			// Only check direct neutrino daughters (generation == 2)

 			unsigned int generation = pfp_generation_v->at( p );
			if ( generation != 2u ) continue;

			float tscore = trk_score_v->at( p );
			if ( tscore <= TRACK_SCORE_CUT ) { ++reco_shower_count; }
			else { ++reco_track_count; }
  
		}

		pd_reco_track_count = reco_track_count;
		pd_reco_shower_count = reco_shower_count;

		if (pd_reco_track_count > 0) { continue; }
		//if (pd_reco_shower_count < 1) { continue; }

		//--------------------//

		tree->Fill();

		//--------------------//

	}

	//--------------------//

	OutputFile->cd();
	OutputFile->Write();
	OutputFile->Close();
	std::cout << std::endl << "File " << FileName << " has been created"<< std::endl << std::endl;
	cout << "pot scale = " << POTScale << endl;

	//--------------------//

} // End of the program