#ifndef mcc9_10_neutrino_selection_h
#define mcc9_10_neutrino_selection_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "string"
#include "vector"

#include "../../../generators/constants.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace constants;

class mcc9_10_neutrino_selection {

private:
	TString fSample;
	TString fLabel;
   TFile* f_file;


public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   TTree* wc; // wc bdt
	TTree* wc_kine;	   
	TTree* wc_eval;  
	TTree* wc_pfeval;    
	TTree* wc_sp;
	TTree* gl_vtx;     
   TTree* dl; 

// Fixed size dimensions of array or collections stored in the TTree if any.
static constexpr Int_t kMaxweights = 4;   

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         interaction_time_abs;   
   Int_t           selected;
   Int_t           run;
   Int_t           sub;
   Int_t           evt;
   Float_t         trkfit;
   UInt_t          shr_tkfit_npoints;
   UInt_t          shr_tkfit_npointsvalid;
   Float16_t       shr_trkfitmedangle;
   Float16_t       shrmoliereavg;
   Float16_t       shrmoliererms;
   Float16_t       shr1shr2moliereavg;
   Float16_t       shr1shr2moliererms;
   Float16_t       shr1trk1moliereavg;
   Float16_t       shr1trk1moliererms;
   Float16_t       shr1trk2moliereavg;
   Float16_t       shr1trk2moliererms;
   Int_t           nblips_saved;
   vector<float>   *blip_x;
   vector<float>   *blip_y;
   vector<float>   *blip_z;
   vector<float>   *blip_dx;
   vector<float>   *blip_dw;   
   vector<float>   *blip_energy;
   vector<float>   *blip_charge;
   vector<int>     *blip_nplanes;
   vector<float>   *blip_proxtrkdist;
   vector<int>     *blip_proxtrkid;
   vector<bool>    *blip_touchtrk;
   vector<int>     *blip_touchtrkid;
   vector<int>     *blip_pl0_nwires;
   vector<int>     *blip_pl1_nwires;
   vector<int>     *blip_pl2_nwires;
   vector<bool>    *blip_pl0_bydeadwire;
   vector<bool>    *blip_pl1_bydeadwire;
   vector<bool>    *blip_pl2_bydeadwire;
   vector<int>     *blip_true_pdg;
   vector<int>     *blip_true_g4id;
   vector<float>   *blip_true_energy;
   Float_t         dvtx;
   Float_t         dtrk;
   Float_t         contained_sps_ratio;
   vector<double>  *dtrk_x_boundary;
   vector<double>  *dtrk_y_boundary;
   vector<double>  *dtrk_z_boundary;
   vector<double>  *dshr_x_boundary;
   vector<double>  *dshr_y_boundary;
   vector<double>  *dshr_z_boundary;
   vector<double>  *dvtx_x_boundary;
   vector<double>  *dvtx_y_boundary;
   vector<double>  *dvtx_z_boundary;
   vector<vector<double> > *dtrk_boundary;
   vector<vector<double> > *dvtx_boundary;
   vector<vector<double> > *dshr_boundary;
   vector<vector<double> > *dmc_boundary;
   Float_t         CosmicIP;
   Float_t         CosmicIPAll3D;
   Float_t         CosmicDirAll3D;
   Float_t         CosmicIPAll2DEnds;
   Float_t         CosmicDirAll2DEnds;
   Float_t         CosmicIPAll2DOvlp;
   Float_t         CosmicDirAll2DOvlp;
   Double_t        _closestNuCosmicDist;
   Float_t         leeweight;
   Float_t         true_pt;
   Float_t         true_pt_visible;
   Float_t         true_p;
   Float_t         true_p_visible;
   Float_t         true_e_visible;
   Float_t         _opfilter_pe_beam;
   Float_t         _opfilter_pe_veto;
   Int_t           nu_pdg;
   Int_t           ccnc;
   Int_t           nu_parent_pdg;
   Int_t           nu_hadron_pdg;
   Int_t           nu_decay_mode;
   Int_t           interaction;
   Float_t         nu_e;
   Float_t         nu_l;
   Float_t         nu_pt;
   Float_t         theta;
   Bool_t          isVtxInFiducial;
   Bool_t          truthFiducial;
   Float_t         true_nu_vtx_t;
   Float_t         true_nu_vtx_x;
   Float_t         true_nu_vtx_y;
   Float_t         true_nu_vtx_z;
   Float_t         true_nu_vtx_sce_x;
   Float_t         true_nu_vtx_sce_y;
   Float_t         true_nu_vtx_sce_z;
   Float_t         reco_nu_vtx_x;
   Float_t         reco_nu_vtx_y;
   Float_t         reco_nu_vtx_z;
   Float_t         reco_nu_vtx_sce_x;
   Float_t         reco_nu_vtx_sce_y;
   Float_t         reco_nu_vtx_sce_z;
   Int_t           nmuon;
   Float_t         muon_e;
   Float_t         muon_c;
   Float_t         muon_p;
   Int_t           nelec;
   Float_t         elec_e;
   Float_t         elec_c;
   Float_t         elec_p;
   Float_t         elec_vx;
   Float_t         elec_vy;
   Float_t         elec_vz;
   Float_t         elec_px;
   Float_t         elec_py;
   Float_t         elec_pz;
   Int_t           npi0;
   Float_t         pi0_e;
   Float_t         pi0_c;
   Float_t         pi0_p;
   Int_t           nneutron;
   Int_t           nproton;
   Float_t         proton_e;
   Float_t         proton_c;
   Float_t         proton_p;
   Int_t           npion;
   Float_t         pion_e;
   Float_t         pion_c;
   Float_t         pion_p;
   Int_t           neta;
   Float_t         eta_e;
   Int_t           nslice;
   Int_t           crtveto;
   Float_t         crthitpe;
   vector<int>     *pfp_slice_idx;
   Int_t           category;
   vector<int>     *backtracked_pdg;
   vector<float>   *backtracked_e;
   vector<int>     *backtracked_tid;
   vector<float>   *backtracked_purity;
   vector<float>   *backtracked_completeness;
   vector<float>   *backtracked_overlay_purity;
   vector<float>   *backtracked_px;
   vector<float>   *backtracked_py;
   vector<float>   *backtracked_pz;
   vector<float>   *backtracked_start_x;
   vector<float>   *backtracked_start_y;
   vector<float>   *backtracked_start_z;
   vector<float>   *backtracked_start_t;
   vector<float>   *backtracked_start_U;
   vector<float>   *backtracked_start_V;
   vector<float>   *backtracked_start_Y;
   vector<float>   *backtracked_sce_start_x;
   vector<float>   *backtracked_sce_start_y;
   vector<float>   *backtracked_sce_start_z;
   vector<float>   *backtracked_sce_start_U;
   vector<float>   *backtracked_sce_start_V;
   vector<float>   *backtracked_sce_start_Y;
   Float_t         lep_e;
   Int_t           pass;
   Int_t           swtrig;
   Int_t           evnhits;
   Int_t           slpdg;
   Int_t           slnhits;
   Int_t           n_pfps;
   Int_t           n_tracks;
   Int_t           n_showers;
   vector<unsigned int> *pfp_generation_v;
   vector<unsigned int> *pfp_trk_daughters_v;
   vector<unsigned int> *pfp_shr_daughters_v;
   vector<unsigned int> *pfp_n_descendents_v;
   vector<float>   *pfp_vtx_x_v;
   vector<float>   *pfp_vtx_y_v;
   vector<float>   *pfp_vtx_z_v;
   vector<float>   *trk_score_v;
   vector<int>     *pfpdg;
   vector<int>     *pfnhits;
   vector<int>     *pfnplanehits_U;
   vector<int>     *pfnplanehits_V;
   vector<int>     *pfnplanehits_Y;
   vector<int>     *pfpplanesubclusters_U;
   vector<int>     *pfpplanesubclusters_V;
   vector<int>     *pfpplanesubclusters_Y;
   vector<float>   *pfpplanesubhitfracmax_U;
   vector<float>   *pfpplanesubhitfracmax_V;
   vector<float>   *pfpplanesubhitfracmax_Y;
   UInt_t          hits_u;
   UInt_t          hits_v;
   UInt_t          hits_y;
   UInt_t          slice_id;
   vector<float>   *slice_topo_score_v;
   Float_t         topological_score;
   Float_t         slclustfrac;
   vector<int>     *mc_pdg;
   vector<float>   *mc_E;
   vector<unsigned int> *mc_n_elastic;
   vector<unsigned int> *mc_n_inelastic;
   vector<float>   *mc_vx;
   vector<float>   *mc_vy;
   vector<float>   *mc_vz;
   vector<float>   *mc_endx;
   vector<float>   *mc_endy;
   vector<float>   *mc_endz;
   vector<float>   *mc_px;
   vector<float>   *mc_py;
   vector<float>   *mc_pz;
   vector<float>   *mc_end_p;
   vector<int>     *mc_generator_pdg;
   vector<int>     *mc_generator_mother;
   vector<int>     *mc_generator_rescatter;
   vector<int>     *mc_generator_trackid;
   vector<int>     *mc_generator_statuscode;
   vector<float>   *mc_generator_E;
   vector<float>   *mc_generator_px;
   vector<float>   *mc_generator_py;
   vector<float>   *mc_generator_pz;
   vector<float>   *mc_completeness;
   vector<float>   *mc_purity;
   string          *endmuonprocess;
   Float_t         endmuonmichel;
   Int_t           filter_antibdt;
   Int_t           filter_ncpi0;
   Int_t           filter_pi0;
   Int_t           filter_ccinclusive;

   map<string,vector<double> > *weights;
   string          weights_first[kMaxweights];
   vector<double>  weights_second[kMaxweights];
   vector<unsigned short> *weightsFlux;
   vector<unsigned short> *weightsGenie;
   vector<unsigned short> *weightsReint;
   Float_t         weightSpline;
   Float_t         weightTune;
   Float_t         weightSplineTimesTune;
   Double_t        knobRPAup;
   Double_t        knobRPAdn;
   Double_t        knobCCMECup;
   Double_t        knobCCMECdn;
   Double_t        knobAxFFCCQEup;
   Double_t        knobAxFFCCQEdn;
   Double_t        knobVecFFCCQEup;
   Double_t        knobVecFFCCQEdn;
   Double_t        knobDecayAngMECup;
   Double_t        knobDecayAngMECdn;
   Double_t        knobThetaDelta2Npiup;
   Double_t        knobThetaDelta2Npidn;
   Double_t        knobThetaDelta2NRadup;
   Double_t        knobThetaDelta2NRaddn;
   Double_t        knobNormCCCOHup;
   Double_t        knobNormCCCOHdn;
   Double_t        knobNormNCCOHup;
   Double_t        knobNormNCCOHdn;
   Double_t        knobxsr_scc_Fv3up;
   Double_t        knobxsr_scc_Fv3dn;
   Double_t        knobxsr_scc_Fa3up;
   Double_t        knobxsr_scc_Fa3dn;
   Double_t        RootinoFix;
   Float_t         flash_pe_flash_matching;
   vector<float>   *flash_pe_flash_matching_v;
   vector<float>   *slice_pe_flash_matching_v;
   Float_t         flash_time_flash_matching;
   Float_t         flash_y_flash_matching;
   Float_t         flash_z_flash_matching;
   Float_t         flash_timewidth_flash_matching;
   Float_t         flash_ywidth_flash_matching;
   Float_t         flash_zwidth_flash_matching;
   Float_t         nu_flashmatch_score;
   Float_t         nu_centerX;
   Float_t         nu_centerY;
   Float_t         nu_centerZ;
   Float_t         nu_totalCharge;
   Float_t         best_cosmic_flashmatch_score;
   Float_t         best_obviouscosmic_flashmatch_score;
   vector<float>   *cosmic_flashmatch_score_v;
   vector<float>   *cosmic_topological_score_v;
   vector<float>   *cosmic_centerX_v;
   vector<float>   *cosmic_centerY_v;
   vector<float>   *cosmic_centerZ_v;
   vector<float>   *cosmic_totalCharge_v;
   vector<int>     *cosmic_nhits_v;
   vector<int>     *cosmic_nunhits_v;
   vector<int>     *cosmic_isclear_v;
   Int_t           slice_orig_pass_id;
   Float_t         slice_orig_topo_score;
   Float_t         mcf_nu_e;
   Float_t         mcf_lep_e;
   Int_t           mcf_actvol;
   Int_t           mcf_nmm;
   Int_t           mcf_nmp;
   Int_t           mcf_nem;
   Int_t           mcf_nep;
   Int_t           mcf_np0;
   Int_t           mcf_npp;
   Int_t           mcf_npm;
   Float_t         mcf_mcshr_elec_etot;
   Int_t           mcf_pass_ccpi0;
   Int_t           mcf_pass_ncpi0;
   Int_t           mcf_pass_ccnopi;
   Int_t           mcf_pass_ncnopi;
   Int_t           mcf_pass_cccpi;
   Int_t           mcf_pass_nccpi;
   vector<float>   *X_SpcPts_v;
   vector<float>   *Y_SpcPts_v;
   vector<float>   *Z_SpcPts_v;
   UInt_t          shr_id_MCStool;
   UInt_t          shr_hits_max_MCStool;
   UInt_t          n_showers_contained_MCStool;
   vector<float>   *trkshrscore_v;
   Float_t         NeutrinoEnergy0;
   Float_t         NeutrinoEnergy1;
   Float_t         NeutrinoEnergy2;
   Float_t         SliceCaloEnergy0;
   Float_t         SliceCaloEnergy1;
   Float_t         SliceCaloEnergy2;
   Int_t           slcng2mip;
   Int_t           slcng2hip;
   Int_t           slcng2shr;
   Int_t           slcng2mcl;
   Int_t           slcng2dfs;
   Int_t           slcng2bkg;
   Int_t           clung2mip;
   Int_t           clung2hip;
   Int_t           clung2shr;
   Int_t           clung2mcl;
   Int_t           clung2dfs;
   Int_t           clung2bkg;
   vector<int>     *pfng2semlabel;
   vector<float>   *pfng2mipfrac;
   vector<float>   *pfng2hipfrac;
   vector<float>   *pfng2shrfrac;
   vector<float>   *pfng2mclfrac;
   vector<float>   *pfng2dfsfrac;
   vector<float>   *pfng2bkgfrac;
   vector<float>   *pfng2mipavrg;
   vector<float>   *pfng2hipavrg;
   vector<float>   *pfng2shravrg;
   vector<float>   *pfng2mclavrg;
   vector<float>   *pfng2dfsavrg;
   vector<float>   *pfng2bkgavrg;
   Float_t         pi0_mcgamma0_e;
   Float_t         pi0_mcgamma0_px;
   Float_t         pi0_mcgamma0_py;
   Float_t         pi0_mcgamma0_pz;
   Float_t         pi0_mcrcdot0;
   Float_t         pi0_mcrce0;
   Float_t         pi0_mcgamma1_e;
   Float_t         pi0_mcgamma1_px;
   Float_t         pi0_mcgamma1_py;
   Float_t         pi0_mcgamma1_pz;
   Float_t         pi0_mcrcdot1;
   Float_t         pi0_mcrce1;
   Int_t           pi0_nshower;
   Int_t           pi0_ntrack;
   Int_t           pi0_ngamma;
   Float_t         pi0_radlen1;
   Float_t         pi0_radlen2;
   Float_t         pi0_dot1;
   Float_t         pi0_dot2;
   Float_t         pi0_energy1_Y;
   Float_t         pi0_energy2_Y;
   Float_t         pi0_dir1_x;
   Float_t         pi0_dir1_y;
   Float_t         pi0_dir1_z;
   Float_t         pi0_dir2_x;
   Float_t         pi0_dir2_y;
   Float_t         pi0_dir2_z;
   Float_t         pi0_dedx1_Y;
   Float_t         pi0_dedx2_Y;
   Float_t         pi0_dedx1_fit_Y;
   Float_t         pi0_dedx2_fit_Y;
   Float_t         pi0_energy1_V;
   Float_t         pi0_energy2_V;
   Float_t         pi0_dedx1_V;
   Float_t         pi0_dedx2_V;
   Float_t         pi0_dedx1_fit_V;
   Float_t         pi0_dedx2_fit_V;
   Float_t         pi0_energy1_U;
   Float_t         pi0_energy2_U;
   Float_t         pi0_dedx1_U;
   Float_t         pi0_dedx2_U;
   Float_t         pi0_dedx1_fit_U;
   Float_t         pi0_dedx2_fit_U;
   Float_t         pi0_shrscore1;
   Float_t         pi0_shrscore2;
   Float_t         pi0_gammadot;
   Float_t         pi0_mass_Y;
   Float_t         pi0_mass_V;
   Float_t         pi0_mass_U;
   Float_t         pi0_rc_vtx_x;
   Float_t         pi0_rc_vtx_y;
   Float_t         pi0_rc_vtx_z;
   Int_t           pi0truth_gamma_parent;
   Float_t         pi0truth_elec_edep;
   Float_t         pi0truth_elec_etot;
   Float_t         pi0truth_elec_dist;
   Int_t           pi0truth_elec_parent;
   Int_t           pi0truth_gamma1_tid;
   Float_t         pi0truth_gamma1_edep;
   Float_t         pi0truth_gamma1_etot;
   Float_t         pi0truth_gamma1_dist;
   Float_t         pi0truth_gamma1_elec1;
   Float_t         pi0truth_gamma1_elec2;
   Float_t         pi0truth_gamma1_xpos;
   Float_t         pi0truth_gamma1_ypos;
   Float_t         pi0truth_gamma1_zpos;
   Int_t           pi0truth_gamma2_tid;
   Float_t         pi0truth_gamma2_edep;
   Float_t         pi0truth_gamma2_etot;
   Float_t         pi0truth_gamma2_dist;
   Float_t         pi0truth_gamma2_elec1;
   Float_t         pi0truth_gamma2_elec2;
   Float_t         pi0truth_gamma2_xpos;
   Float_t         pi0truth_gamma2_ypos;
   Float_t         pi0truth_gamma2_zpos;
   Float_t         pi0truth_gammadot;
   Int_t           pi0truth_run;
   Int_t           pi0truth_sub;
   Int_t           pi0truth_evt;
   Int_t           nflag_pl1;
   Int_t           nnoise_pl1;
   Int_t           nslhits_pl1;
   Int_t           nslnoise_pl1;
   Int_t           nhits_pl1;
   Float_t         frac_slnoise_pl1;
   Float_t         secondshower_U_charge;
   Int_t           secondshower_U_nhit;
   Float_t         secondshower_U_vtxdist;
   Float_t         secondshower_U_eigenratio;
   Float_t         secondshower_U_dot;
   Float_t         secondshower_U_dir;
   Float_t         secondshower_V_charge;
   Int_t           secondshower_V_nhit;
   Float_t         secondshower_V_vtxdist;
   Float_t         secondshower_V_eigenratio;
   Float_t         secondshower_V_dot;
   Float_t         secondshower_V_dir;
   Float_t         secondshower_Y_charge;
   Int_t           secondshower_Y_nhit;
   Float_t         secondshower_Y_vtxdist;
   Float_t         secondshower_Y_eigenratio;
   Float_t         secondshower_Y_dot;
   Float_t         secondshower_Y_dir;
   Int_t           origevnunhits;
   Int_t           origevnunhits2;
   Int_t           origevlepnhits;
   Int_t           origevpronhits;
   Int_t           origevpi1nhits;
   Int_t           origevpi0nhits;
   Int_t           origevneunhits;
   Int_t           origevgamnhits;
   Int_t           origevothnhits;
   Int_t           evnunhits;
   Int_t           evlepnhits;
   Int_t           evpronhits;
   Int_t           evpi1nhits;
   Int_t           evpi0nhits;
   Int_t           evneunhits;
   Int_t           evgamnhits;
   Int_t           evothnhits;
   Int_t           slnunhits;
   Int_t           sllepnhits;
   Int_t           slpronhits;
   Int_t           slpi1nhits;
   Int_t           slpi0nhits;
   Int_t           slneunhits;
   Int_t           slgamnhits;
   Int_t           slothnhits;
   vector<int>     *pfnunhits;
   vector<int>     *pflepnhits;
   vector<int>     *pfpronhits;
   vector<int>     *pfpi1nhits;
   vector<int>     *pfpi0nhits;
   vector<int>     *pfneunhits;
   vector<int>     *pfgamnhits;
   vector<int>     *pfothnhits;
   Float_t         nu_completeness_from_pfp;
   Float_t         nu_purity_from_pfp;
   vector<float>   *trk_bragg_p_v;
   vector<float>   *trk_bragg_mu_v;
   vector<float>   *trk_bragg_pion_v;
   vector<float>   *trk_bragg_mip_v;
   vector<float>   *trk_bragg_p_alt_dir_v;
   vector<float>   *trk_bragg_mu_alt_dir_v;
   vector<float>   *trk_bragg_pion_alt_dir_v;
   vector<bool>    *trk_bragg_p_fwd_preferred_v;
   vector<bool>    *trk_bragg_mu_fwd_preferred_v;
   vector<bool>    *trk_bragg_pion_fwd_preferred_v;
   vector<float>   *trk_pida_v;
   vector<float>   *trk_pid_chipr_v;
   vector<float>   *trk_pid_chipi_v;
   vector<float>   *trk_pid_chika_v;
   vector<float>   *trk_pid_chimu_v;
   vector<float>   *trk_bragg_p_u_v;
   vector<float>   *trk_bragg_mu_u_v;
   vector<float>   *trk_bragg_pion_u_v;
   vector<float>   *trk_bragg_mip_u_v;
   vector<float>   *trk_bragg_p_alt_dir_u_v;
   vector<float>   *trk_bragg_mu_alt_dir_u_v;
   vector<float>   *trk_bragg_pion_alt_dir_u_v;
   vector<bool>    *trk_bragg_p_fwd_preferred_u_v;
   vector<bool>    *trk_bragg_mu_fwd_preferred_u_v;
   vector<bool>    *trk_bragg_pion_fwd_preferred_u_v;
   vector<float>   *trk_pida_u_v;
   vector<float>   *trk_pid_chipr_u_v;
   vector<float>   *trk_pid_chipi_u_v;
   vector<float>   *trk_pid_chika_u_v;
   vector<float>   *trk_pid_chimu_u_v;
   vector<float>   *trk_bragg_p_v_v;
   vector<float>   *trk_bragg_mu_v_v;
   vector<float>   *trk_bragg_pion_v_v;
   vector<float>   *trk_bragg_mip_v_v;
   vector<float>   *trk_bragg_p_alt_dir_v_v;
   vector<float>   *trk_bragg_mu_alt_dir_v_v;
   vector<float>   *trk_bragg_pion_alt_dir_v_v;
   vector<bool>    *trk_bragg_p_fwd_preferred_v_v;
   vector<bool>    *trk_bragg_mu_fwd_preferred_v_v;
   vector<bool>    *trk_bragg_pion_fwd_preferred_v_v;
   vector<float>   *trk_pida_v_v;
   vector<float>   *trk_pid_chipr_v_v;
   vector<float>   *trk_pid_chipi_v_v;
   vector<float>   *trk_pid_chika_v_v;
   vector<float>   *trk_pid_chimu_v_v;
   vector<unsigned long> *trk_pfp_id_v;
   vector<float>   *trk_dir_x_v;
   vector<float>   *trk_dir_y_v;
   vector<float>   *trk_dir_z_v;
   vector<float>   *trk_start_x_v;
   vector<float>   *trk_start_y_v;
   vector<float>   *trk_start_z_v;
   vector<float>   *trk_sce_start_x_v;
   vector<float>   *trk_sce_start_y_v;
   vector<float>   *trk_sce_start_z_v;
   vector<float>   *trk_end_x_v;
   vector<float>   *trk_end_y_v;
   vector<float>   *trk_end_z_v;
   vector<float>   *trk_sce_end_x_v;
   vector<float>   *trk_sce_end_y_v;
   vector<float>   *trk_sce_end_z_v;
   vector<float>   *trk_distance_v;
   vector<float>   *trk_theta_v;
   vector<float>   *trk_phi_v;
   vector<float>   *trk_len_v;
   vector<float>   *trk_mcs_muon_mom_v;
   vector<float>   *trk_range_muon_mom_v;
   vector<float>   *trk_energy_proton_v;
   vector<float>   *trk_energy_muon_v;
   vector<float>   *trk_calo_energy_u_v;
   vector<float>   *trk_calo_energy_v_v;
   vector<float>   *trk_calo_energy_y_v;
   vector<float>   *trk_llr_pid_u_v;
   vector<float>   *trk_llr_pid_v_v;
   vector<float>   *trk_llr_pid_y_v;
   vector<float>   *trk_llr_pid_v;
   vector<float>   *trk_llr_pid_score_v;
   vector<float>   *trk_trunk_dEdx_u_v;
   vector<float>   *trk_trunk_dEdx_v_v;
   vector<float>   *trk_trunk_dEdx_y_v;
   vector<float>   *trk_trunk_rr_dEdx_u_v;
   vector<float>   *trk_trunk_rr_dEdx_v_v;
   vector<float>   *trk_trunk_rr_dEdx_y_v;
   vector<int>     *trk_nhits_u_v;
   vector<int>     *trk_nhits_v_v;
   vector<int>     *trk_nhits_y_v;
   vector<float>   *trk_avg_deflection_mean_v;
   vector<float>   *trk_avg_deflection_stdev_v;
   vector<float>   *trk_avg_deflection_separation_mean_v;
   vector<int>     *trk_end_spacepoints_v;
   Float_t         shr_score;   

   Float_t         shw_sp_n_good_showers;
   Float_t         shw_sp_n_20mev_showers;
   Float_t         shw_sp_n_br1_showers;
   Float_t         shw_sp_n_br2_showers;
   Float_t         shw_sp_n_br3_showers;
   Float_t         shw_sp_n_br4_showers;
   Float_t         shw_sp_n_20br1_showers;     
  	Float_t         single_photon_numu_score;
	Float_t         single_photon_other_score;
	Float_t         single_photon_ncpi0_score;
	Float_t         single_photon_nue_score;
	int reco_Ntrack;
	int truth_Ntrack;	
	int truth_NprimPio;	   
   Bool_t truth_isCC;     
   Float_t         truth_vtxX;
   Float_t         truth_vtxY;
   Float_t         truth_vtxZ;   
	Int_t truth_pdg[1500];  //[truth_Ntrack]
	Int_t truth_id[1500];   //[truth_Ntrack]	
    Float_t truth_startMomentum[1500][4];   //[truth_Ntrack]	
	float numu_score;	
	float nc_pio_score;	
	float numu_cc_flag;   
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
   Int_t reco_larpid_proccess[129];   //[reco_Ntrack]   
	vector<int> *kine_particle_type; // reco pdg
	vector<float> *kine_energy_particle; // KE in MeV
	Int_t reco_mother[500];   //[reco_Ntrack]
	Float_t reco_startMomentum[500][4];   //[reco_Ntrack]
	Float_t reco_startXYZT[500][4];   //[reco_Ntrack]
	Float_t reco_endXYZT[500][4];   //[reco_Ntrack]
	Int_t reco_pdg[500];   //[reco_Ntrack]
	Int_t reco_id[500];   //[reco_Ntrack]
   Int_t 		      reco_truthMatch_pdg[500];	         //[reco_Ntrack]
   Int_t 		      reco_truthMatch_id[500];           //[reco_Ntrack]	
	vector<double>  *Trec_spacepoints_x;
	vector<double>  *Trec_spacepoints_y;
	vector<double>  *Trec_spacepoints_z;
	vector<double>  *Trec_spacepoints_q;
	vector<double>  *Trec_spacepoints_cluster_id;
	vector<double>  *Trec_spacepoints_real_cluster_id;
	vector<double>  *Trec_spacepoints_sub_cluster_id;
	vector<double>  *Treccharge_spacepoints_x;
	vector<double>  *Treccharge_spacepoints_y;
	vector<double>  *Treccharge_spacepoints_z;
	vector<double>  *Treccharge_spacepoints_q;
	vector<double>  *Treccharge_spacepoints_cluster_id;
	vector<double>  *Treccharge_spacepoints_real_cluster_id;
	vector<double>  *Treccharge_spacepoints_sub_cluster_id;
	vector<double>  *Trecchargeblob_spacepoints_x;
	vector<double>  *Trecchargeblob_spacepoints_y;
	vector<double>  *Trecchargeblob_spacepoints_z;
	vector<double>  *Trecchargeblob_spacepoints_q;
	vector<double>  *Trecchargeblob_spacepoints_cluster_id;
	vector<double>  *Trecchargeblob_spacepoints_real_cluster_id;
	vector<double>  *Trecchargeblob_spacepoints_sub_cluster_id;	 

   // glee
	int  trackstub_num_candidates;	   
	vector<double>  *trackstub_candidate_veto_score;   
   Double_t        reco_vertex_x;
   Double_t        reco_vertex_y;
   Double_t        reco_vertex_z;  
   Int_t           sss_num_candidates;   
   Int_t           reco_asso_showers;
   Int_t           reco_asso_tracks;       

   // dl lantern
   Int_t           foundVertex;
   Float_t         vtxX;
   Float_t         vtxY;
   Float_t         vtxZ;
   Float_t         vtxScore;   
   Int_t           nTracks;
   Int_t           trackIsSecondary[25];   //[nTracks]
   Int_t           nShowers;
   Int_t           showerIsSecondary[25];   //[nShowers]

   Float_t         n_veto_all_score;
   Float_t         n_veto_nonprim_score;
   Float_t         n_veto_score;   

   // List of branches 
   TBranch        *b_interaction_time_abs;   //!   
   TBranch        *b_selected;   //!
   TBranch        *b_run;   //!
   TBranch        *b_sub;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_trk_pfp_id;   //!
   TBranch        *b_shr_pfp_id;   //!
   TBranch        *b_trk2_pfp_id;   //!
   TBranch        *b_shr2_pfp_id;   //!
   TBranch        *b_trk3_pfp_id;   //!
   TBranch        *b_shr3_pfp_id;   //!
   TBranch        *b_nblips_saved;   //!
   TBranch        *b_blip_x;   //!
   TBranch        *b_blip_y;   //!
   TBranch        *b_blip_z;   //!
   TBranch        *b_blip_dx;   //!
   TBranch        *b_blip_dw;   //!   
   TBranch        *b_blip_energy;   //!
   TBranch        *b_blip_charge;   //!
   TBranch        *b_blip_nplanes;   //!
   TBranch        *b_blip_proxtrkdist;   //!
   TBranch        *b_blip_proxtrkid;   //!
   TBranch        *b_blip_touchtrk;   //!
   TBranch        *b_blip_touchtrkid;   //!
   TBranch        *b_blip_pl0_nwires;   //!
   TBranch        *b_blip_pl1_nwires;   //!
   TBranch        *b_blip_pl2_nwires;   //!
   TBranch        *b_blip_pl0_bydeadwire;   //!
   TBranch        *b_blip_pl1_bydeadwire;   //!
   TBranch        *b_blip_pl2_bydeadwire;   //!
   TBranch        *b_blip_true_pdg;   //!
   TBranch        *b_blip_true_g4id;   //!
   TBranch        *b_blip_true_energy;   //!
   TBranch        *b_dvtx;   //!
   TBranch        *b_dtrk;   //!
   TBranch        *b_contained_sps_ratio;   //!
   TBranch        *b_dtrk_x_boundary;   //!
   TBranch        *b_dtrk_y_boundary;   //!
   TBranch        *b_dtrk_z_boundary;   //!
   TBranch        *b_dshr_x_boundary;   //!
   TBranch        *b_dshr_y_boundary;   //!
   TBranch        *b_dshr_z_boundary;   //!
   TBranch        *b_dvtx_x_boundary;   //!
   TBranch        *b_dvtx_y_boundary;   //!
   TBranch        *b_dvtx_z_boundary;   //!
   TBranch        *b_dtrk_boundary;   //!
   TBranch        *b_dvtx_boundary;   //!
   TBranch        *b_dshr_boundary;   //!
   TBranch        *b_dmc_boundary;   //!
   TBranch        *b_CosmicIP;   //!
   TBranch        *b_CosmicIPAll3D;   //!
   TBranch        *b_CosmicDirAll3D;   //!
   TBranch        *b_CosmicIPAll2DEnds;   //!
   TBranch        *b_CosmicDirAll2DEnds;   //!
   TBranch        *b_CosmicIPAll2DOvlp;   //!
   TBranch        *b_CosmicDirAll2DOvlp;   //!
   TBranch        *b__closestNuCosmicDist;   //!
   TBranch        *b_leeweight;   //!
   TBranch        *b_true_pt;   //!
   TBranch        *b_true_pt_visible;   //!
   TBranch        *b_true_p;   //!
   TBranch        *b_true_p_visible;   //!
   TBranch        *b_true_e_visible;   //!
   TBranch        *b_opfilter_pe_beam;   //!
   TBranch        *b_opfilter_pe_veto;   //!
   TBranch        *b_nu_pdg;   //!
   TBranch        *b_ccnc;   //!
   TBranch        *b_nu_parent_pdg;   //!
   TBranch        *b_nu_hadron_pdg;   //!
   TBranch        *b_nu_decay_mode;   //!
   TBranch        *b_interaction;   //!
   TBranch        *b_nu_e;   //!
   TBranch        *b_nu_l;   //!
   TBranch        *b_nu_pt;   //!
   TBranch        *b_theta;   //!
   TBranch        *b_isVtxInFiducial;   //!
   TBranch        *b_truthFiducial;   //!
   TBranch        *b_true_nu_vtx_t;   //!
   TBranch        *b_true_nu_vtx_x;   //!
   TBranch        *b_true_nu_vtx_y;   //!
   TBranch        *b_true_nu_vtx_z;   //!
   TBranch        *b_true_nu_vtx_sce_x;   //!
   TBranch        *b_true_nu_vtx_sce_y;   //!
   TBranch        *b_true_nu_vtx_sce_z;   //!
   TBranch        *b_reco_nu_vtx_x;   //!
   TBranch        *b_reco_nu_vtx_y;   //!
   TBranch        *b_reco_nu_vtx_z;   //!
   TBranch        *b_reco_nu_vtx_sce_x;   //!
   TBranch        *b_reco_nu_vtx_sce_y;   //!
   TBranch        *b_reco_nu_vtx_sce_z;   //!
   TBranch        *b_nmuon;   //!
   TBranch        *b_muon_e;   //!
   TBranch        *b_muon_c;   //!
   TBranch        *b_muon_p;   //!
   TBranch        *b_nelec;   //!
   TBranch        *b_elec_e;   //!
   TBranch        *b_elec_c;   //!
   TBranch        *b_elec_p;   //!
   TBranch        *b_elec_vx;   //!
   TBranch        *b_elec_vy;   //!
   TBranch        *b_elec_vz;   //!
   TBranch        *b_elec_px;   //!
   TBranch        *b_elec_py;   //!
   TBranch        *b_elec_pz;   //!
   TBranch        *b_npi0;   //!
   TBranch        *b_pi0_e;   //!
   TBranch        *b_pi0_c;   //!
   TBranch        *b_pi0_p;   //!
   TBranch        *b_nneutron;   //!
   TBranch        *b_nproton;   //!
   TBranch        *b_proton_e;   //!
   TBranch        *b_proton_c;   //!
   TBranch        *b_proton_p;   //!
   TBranch        *b_npion;   //!
   TBranch        *b_pion_e;   //!
   TBranch        *b_pion_c;   //!
   TBranch        *b_pion_p;   //!
   TBranch        *b_neta;   //!
   TBranch        *b_eta_e;   //!
   TBranch        *b_nslice;   //!
   TBranch        *b_crtveto;   //!
   TBranch        *b_crthitpe;   //!
   TBranch        *b_pfp_slice_idx;   //!
   TBranch        *b_category;   //!
   TBranch        *b_backtracked_pdg;   //!
   TBranch        *b_backtracked_e;   //!
   TBranch        *b_backtracked_tid;   //!
   TBranch        *b_backtracked_purity;   //!
   TBranch        *b_backtracked_completeness;   //!
   TBranch        *b_backtracked_overlay_purity;   //!
   TBranch        *b_backtracked_px;   //!
   TBranch        *b_backtracked_py;   //!
   TBranch        *b_backtracked_pz;   //!
   TBranch        *b_backtracked_start_x;   //!
   TBranch        *b_backtracked_start_y;   //!
   TBranch        *b_backtracked_start_z;   //!
   TBranch        *b_backtracked_start_t;   //!
   TBranch        *b_backtracked_start_U;   //!
   TBranch        *b_backtracked_start_V;   //!
   TBranch        *b_backtracked_start_Y;   //!
   TBranch        *b_backtracked_sce_start_x;   //!
   TBranch        *b_backtracked_sce_start_y;   //!
   TBranch        *b_backtracked_sce_start_z;   //!
   TBranch        *b_backtracked_sce_start_U;   //!
   TBranch        *b_backtracked_sce_start_V;   //!
   TBranch        *b_backtracked_sce_start_Y;   //!
   TBranch        *b_lep_e;   //!
   TBranch        *b_pass;   //!
   TBranch        *b_swtrig;   //!
   TBranch        *b_evnhits;   //!
   TBranch        *b_slpdg;   //!
   TBranch        *b_slnhits;   //!
   TBranch        *b_n_pfps;   //!
   TBranch        *b_n_tracks;   //!
   TBranch        *b_n_showers;   //!
   TBranch        *b_pfp_generation_v;   //!
   TBranch        *b_pfp_trk_daughters_v;   //!
   TBranch        *b_pfp_shr_daughters_v;   //!
   TBranch        *b_pfp_n_descendents_v;   //!
   TBranch        *b_pfp_vtx_x_v;   //!
   TBranch        *b_pfp_vtx_y_v;   //!
   TBranch        *b_pfp_vtx_z_v;   //!
   TBranch        *b_trk_score_v;   //!
   TBranch        *b_pfpdg;   //!
   TBranch        *b_pfnhits;   //!
   TBranch        *b_pfnplanehits_U;   //!
   TBranch        *b_pfnplanehits_V;   //!
   TBranch        *b_pfnplanehits_Y;   //!
   TBranch        *b_pfpplanesubclusters_U;   //!
   TBranch        *b_pfpplanesubclusters_V;   //!
   TBranch        *b_pfpplanesubclusters_Y;   //!
   TBranch        *b_pfpplanesubhitfracmax_U;   //!
   TBranch        *b_pfpplanesubhitfracmax_V;   //!
   TBranch        *b_pfpplanesubhitfracmax_Y;   //!
   TBranch        *b_hits_u;   //!
   TBranch        *b_hits_v;   //!
   TBranch        *b_hits_y;   //!
   TBranch        *b_slice_id;   //!
   TBranch        *b_slice_topo_score_v;   //!
   TBranch        *b_topological_score;   //!
   TBranch        *b_slclustfrac;   //!
   TBranch        *b_mc_pdg;   //!
   TBranch        *b_mc_E;   //!
   TBranch        *b_mc_n_elastic;   //!
   TBranch        *b_mc_n_inelastic;   //!
   TBranch        *b_mc_vx;   //!
   TBranch        *b_mc_vy;   //!
   TBranch        *b_mc_vz;   //!
   TBranch        *b_mc_endx;   //!
   TBranch        *b_mc_endy;   //!
   TBranch        *b_mc_endz;   //!
   TBranch        *b_mc_px;   //!
   TBranch        *b_mc_py;   //!
   TBranch        *b_mc_pz;   //!
   TBranch        *b_mc_end_p;   //!
   TBranch        *b_mc_generator_pdg;   //!
   TBranch        *b_mc_generator_mother;   //!
   TBranch        *b_mc_generator_rescatter;   //!
   TBranch        *b_mc_generator_trackid;   //!
   TBranch        *b_mc_generator_statuscode;   //!
   TBranch        *b_mc_generator_E;   //!
   TBranch        *b_mc_generator_px;   //!
   TBranch        *b_mc_generator_py;   //!
   TBranch        *b_mc_generator_pz;   //!
   TBranch        *b_mc_completeness;   //!
   TBranch        *b_mc_purity;   //!
   TBranch        *b_endmuonprocess;   //!
   TBranch        *b_endmuonmichel;   //!
   TBranch        *b_filter_antibdt;   //!
   TBranch        *b_filter_ncpi0;   //!
   TBranch        *b_filter_pi0;   //!
   TBranch        *b_filter_ccinclusive;   //!
   TBranch        *b_weights;   //!
   TBranch        *b_weights_first;   //!
   TBranch        *b_weights_second;   //!
   TBranch        *b_weightsFlux;   //!
   TBranch        *b_weightsGenie;   //!
   TBranch        *b_weightsReint;   //!
   TBranch        *b_weightSpline;   //!
   TBranch        *b_weightTune;   //!
   TBranch        *b_weightSplineTimesTune;   //!
   TBranch        *b_knobRPAup;   //!
   TBranch        *b_knobRPAdn;   //!
   TBranch        *b_knobCCMECup;   //!
   TBranch        *b_knobCCMECdn;   //!
   TBranch        *b_knobAxFFCCQEup;   //!
   TBranch        *b_knobAxFFCCQEdn;   //!
   TBranch        *b_knobVecFFCCQEup;   //!
   TBranch        *b_knobVecFFCCQEdn;   //!
   TBranch        *b_knobDecayAngMECup;   //!
   TBranch        *b_knobDecayAngMECdn;   //!
   TBranch        *b_knobThetaDelta2Npiup;   //!
   TBranch        *b_knobThetaDelta2Npidn;   //!
   TBranch        *b_knobThetaDelta2NRadup;   //!
   TBranch        *b_knobThetaDelta2NRaddn;   //!
   TBranch        *b_knobNormCCCOHup;   //!
   TBranch        *b_knobNormCCCOHdn;   //!
   TBranch        *b_knobNormNCCOHup;   //!
   TBranch        *b_knobNormNCCOHdn;   //!
   TBranch        *b_knobxsr_scc_Fv3up;   //!
   TBranch        *b_knobxsr_scc_Fv3dn;   //!
   TBranch        *b_knobxsr_scc_Fa3up;   //!
   TBranch        *b_knobxsr_scc_Fa3dn;   //!
   TBranch        *b_RootinoFix;   //!
   TBranch        *b_flash_pe_flash_matching;   //!
   TBranch        *b_flash_pe_flash_matching_v;   //!
   TBranch        *b_slice_pe_flash_matching_v;   //!
   TBranch        *b_flash_time_flash_matching;   //!
   TBranch        *b_flash_y_flash_matching;   //!
   TBranch        *b_flash_z_flash_matching;   //!
   TBranch        *b_flash_timewidth_flash_matching;   //!
   TBranch        *b_flash_ywidth_flash_matching;   //!
   TBranch        *b_flash_zwidth_flash_matching;   //!
   TBranch        *b_nu_flashmatch_score;   //!
   TBranch        *b_nu_centerX;   //!
   TBranch        *b_nu_centerY;   //!
   TBranch        *b_nu_centerZ;   //!
   TBranch        *b_nu_totalCharge;   //!
   TBranch        *b_best_cosmic_flashmatch_score;   //!
   TBranch        *b_best_obviouscosmic_flashmatch_score;   //!
   TBranch        *b_cosmic_flashmatch_score_v;   //!
   TBranch        *b_cosmic_topological_score_v;   //!
   TBranch        *b_cosmic_centerX_v;   //!
   TBranch        *b_cosmic_centerY_v;   //!
   TBranch        *b_cosmic_centerZ_v;   //!
   TBranch        *b_cosmic_totalCharge_v;   //!
   TBranch        *b_cosmic_nhits_v;   //!
   TBranch        *b_cosmic_nunhits_v;   //!
   TBranch        *b_cosmic_isclear_v;   //!
   TBranch        *b_slice_orig_pass_id;   //!
   TBranch        *b_slice_orig_topo_score;   //!
   TBranch        *b_mcf_nu_e;   //!
   TBranch        *b_mcf_lep_e;   //!
   TBranch        *b_mcf_actvol;   //!
   TBranch        *b_mcf_nmm;   //!
   TBranch        *b_mcf_nmp;   //!
   TBranch        *b_mcf_nem;   //!
   TBranch        *b_mcf_nep;   //!
   TBranch        *b_mcf_np0;   //!
   TBranch        *b_mcf_npp;   //!
   TBranch        *b_mcf_npm;   //!
   TBranch        *b_mcf_mcshr_elec_etot;   //!
   TBranch        *b_mcf_pass_ccpi0;   //!
   TBranch        *b_mcf_pass_ncpi0;   //!
   TBranch        *b_mcf_pass_ccnopi;   //!
   TBranch        *b_mcf_pass_ncnopi;   //!
   TBranch        *b_mcf_pass_cccpi;   //!
   TBranch        *b_mcf_pass_nccpi;   //!
   TBranch        *b_X_SpcPts_v;   //!
   TBranch        *b_Y_SpcPts_v;   //!
   TBranch        *b_Z_SpcPts_v;   //!
   TBranch        *b_shr_hits_max_MCStool;   //!
   TBranch        *b_n_showers_contained_MCStool;   //!
   TBranch        *b_trkshrscore_v;   //!
   TBranch        *b_n_shrSpcPts;   //!
   TBranch        *b_PCAWin_1Cr_5cm;   //!
   TBranch        *b_PCAWin_2Cr_5cm;   //!
   TBranch        *b_PCAWin_3Cr_5cm;   //!
   TBranch        *b_PCAWin_dist_5cm;   //!
   TBranch        *b_PCAWin_npts_5cm;   //!
   TBranch        *b_PCAWin_1Cr_2_5cm;   //!
   TBranch        *b_PCAWin_2Cr_2_5cm;   //!
   TBranch        *b_PCAWin_3Cr_2_5cm;   //!
   TBranch        *b_PCAWin_dist_2_5cm;   //!
   TBranch        *b_PCAWin_npts_2_5cm;   //!
   TBranch        *b_NeutrinoEnergy0;   //!
   TBranch        *b_NeutrinoEnergy1;   //!
   TBranch        *b_NeutrinoEnergy2;   //!
   TBranch        *b_SliceCaloEnergy0;   //!
   TBranch        *b_SliceCaloEnergy1;   //!
   TBranch        *b_SliceCaloEnergy2;   //!
   TBranch        *b_slcng2mip;   //!
   TBranch        *b_slcng2hip;   //!
   TBranch        *b_slcng2shr;   //!
   TBranch        *b_slcng2mcl;   //!
   TBranch        *b_slcng2dfs;   //!
   TBranch        *b_slcng2bkg;   //!
   TBranch        *b_clung2mip;   //!
   TBranch        *b_clung2hip;   //!
   TBranch        *b_clung2shr;   //!
   TBranch        *b_clung2mcl;   //!
   TBranch        *b_clung2dfs;   //!
   TBranch        *b_clung2bkg;   //!
   TBranch        *b_pfng2semlabel;   //!
   TBranch        *b_pfng2mipfrac;   //!
   TBranch        *b_pfng2hipfrac;   //!
   TBranch        *b_pfng2shrfrac;   //!
   TBranch        *b_pfng2mclfrac;   //!
   TBranch        *b_pfng2dfsfrac;   //!
   TBranch        *b_pfng2bkgfrac;   //!
   TBranch        *b_pfng2mipavrg;   //!
   TBranch        *b_pfng2hipavrg;   //!
   TBranch        *b_pfng2shravrg;   //!
   TBranch        *b_pfng2mclavrg;   //!
   TBranch        *b_pfng2dfsavrg;   //!
   TBranch        *b_pfng2bkgavrg;   //!
   TBranch        *b_pi0_mcgamma0_e;   //!
   TBranch        *b_pi0_mcgamma0_px;   //!
   TBranch        *b_pi0_mcgamma0_py;   //!
   TBranch        *b_pi0_mcgamma0_pz;   //!
   TBranch        *b_pi0_mcrcdot0;   //!
   TBranch        *b_pi0_mcrce0;   //!
   TBranch        *b_pi0_mcgamma1_e;   //!
   TBranch        *b_pi0_mcgamma1_px;   //!
   TBranch        *b_pi0_mcgamma1_py;   //!
   TBranch        *b_pi0_mcgamma1_pz;   //!
   TBranch        *b_pi0_mcrcdot1;   //!
   TBranch        *b_pi0_mcrce1;   //!
   TBranch        *b_pi0_nshower;   //!
   TBranch        *b_pi0_ntrack;   //!
   TBranch        *b_pi0_ngamma;   //!
   TBranch        *b_pi0_radlen1;   //!
   TBranch        *b_pi0_radlen2;   //!
   TBranch        *b_pi0_dot1;   //!
   TBranch        *b_pi0_dot2;   //!
   TBranch        *b_pi0_energy1_Y;   //!
   TBranch        *b_pi0_energy2_Y;   //!
   TBranch        *b_pi0_dir1_x;   //!
   TBranch        *b_pi0_dir1_y;   //!
   TBranch        *b_pi0_dir1_z;   //!
   TBranch        *b_pi0_dir2_x;   //!
   TBranch        *b_pi0_dir2_y;   //!
   TBranch        *b_pi0_dir2_z;   //!
   TBranch        *b_pi0_dedx1_Y;   //!
   TBranch        *b_pi0_dedx2_Y;   //!
   TBranch        *b_pi0_dedx1_fit_Y;   //!
   TBranch        *b_pi0_dedx2_fit_Y;   //!
   TBranch        *b_pi0_energy1_V;   //!
   TBranch        *b_pi0_energy2_V;   //!
   TBranch        *b_pi0_dedx1_V;   //!
   TBranch        *b_pi0_dedx2_V;   //!
   TBranch        *b_pi0_dedx1_fit_V;   //!
   TBranch        *b_pi0_dedx2_fit_V;   //!
   TBranch        *b_pi0_energy1_U;   //!
   TBranch        *b_pi0_energy2_U;   //!
   TBranch        *b_pi0_dedx1_U;   //!
   TBranch        *b_pi0_dedx2_U;   //!
   TBranch        *b_pi0_dedx1_fit_U;   //!
   TBranch        *b_pi0_dedx2_fit_U;   //!
   TBranch        *b_pi0_shrscore1;   //!
   TBranch        *b_pi0_shrscore2;   //!
   TBranch        *b_pi0_gammadot;   //!
   TBranch        *b_pi0_mass_Y;   //!
   TBranch        *b_pi0_mass_V;   //!
   TBranch        *b_pi0_mass_U;   //!
   TBranch        *b_pi0_rc_vtx_x;   //!
   TBranch        *b_pi0_rc_vtx_y;   //!
   TBranch        *b_pi0_rc_vtx_z;   //!
   TBranch        *b_pi0truth_gamma_parent;   //!
   TBranch        *b_pi0truth_elec_edep;   //!
   TBranch        *b_pi0truth_elec_etot;   //!
   TBranch        *b_pi0truth_elec_dist;   //!
   TBranch        *b_pi0truth_elec_parent;   //!
   TBranch        *b_pi0truth_gamma1_tid;   //!
   TBranch        *b_pi0truth_gamma1_edep;   //!
   TBranch        *b_pi0truth_gamma1_etot;   //!
   TBranch        *b_pi0truth_gamma1_dist;   //!
   TBranch        *b_pi0truth_gamma1_elec1;   //!
   TBranch        *b_pi0truth_gamma1_elec2;   //!
   TBranch        *b_pi0truth_gamma1_xpos;   //!
   TBranch        *b_pi0truth_gamma1_ypos;   //!
   TBranch        *b_pi0truth_gamma1_zpos;   //!
   TBranch        *b_pi0truth_gamma2_tid;   //!
   TBranch        *b_pi0truth_gamma2_edep;   //!
   TBranch        *b_pi0truth_gamma2_etot;   //!
   TBranch        *b_pi0truth_gamma2_dist;   //!
   TBranch        *b_pi0truth_gamma2_elec1;   //!
   TBranch        *b_pi0truth_gamma2_elec2;   //!
   TBranch        *b_pi0truth_gamma2_xpos;   //!
   TBranch        *b_pi0truth_gamma2_ypos;   //!
   TBranch        *b_pi0truth_gamma2_zpos;   //!
   TBranch        *b_pi0truth_gammadot;   //!
   TBranch        *b_pi0truth_run;   //!
   TBranch        *b_pi0truth_sub;   //!
   TBranch        *b_pi0truth_evt;   //!
   TBranch        *b_nflag_pl1;   //!
   TBranch        *b_nnoise_pl1;   //!
   TBranch        *b_nslhits_pl1;   //!
   TBranch        *b_nslnoise_pl1;   //!
   TBranch        *b_nhits_pl1;   //!
   TBranch        *b_frac_slnoise_pl1;   //!
   TBranch        *b_secondshower_U_charge;   //!
   TBranch        *b_secondshower_U_nhit;   //!
   TBranch        *b_secondshower_U_vtxdist;   //!
   TBranch        *b_secondshower_U_eigenratio;   //!
   TBranch        *b_secondshower_U_dot;   //!
   TBranch        *b_secondshower_U_dir;   //!
   TBranch        *b_secondshower_V_charge;   //!
   TBranch        *b_secondshower_V_nhit;   //!
   TBranch        *b_secondshower_V_vtxdist;   //!
   TBranch        *b_secondshower_V_eigenratio;   //!
   TBranch        *b_secondshower_V_dot;   //!
   TBranch        *b_secondshower_V_dir;   //!
   TBranch        *b_secondshower_Y_charge;   //!
   TBranch        *b_secondshower_Y_nhit;   //!
   TBranch        *b_secondshower_Y_vtxdist;   //!
   TBranch        *b_secondshower_Y_eigenratio;   //!
   TBranch        *b_secondshower_Y_dot;   //!
   TBranch        *b_secondshower_Y_dir;   //!
   TBranch        *b_origevnunhits;   //!
   TBranch        *b_origevnunhits2;   //!
   TBranch        *b_origevlepnhits;   //!
   TBranch        *b_origevpronhits;   //!
   TBranch        *b_origevpi1nhits;   //!
   TBranch        *b_origevpi0nhits;   //!
   TBranch        *b_origevneunhits;   //!
   TBranch        *b_origevgamnhits;   //!
   TBranch        *b_origevothnhits;   //!
   TBranch        *b_evnunhits;   //!
   TBranch        *b_evlepnhits;   //!
   TBranch        *b_evpronhits;   //!
   TBranch        *b_evpi1nhits;   //!
   TBranch        *b_evpi0nhits;   //!
   TBranch        *b_evneunhits;   //!
   TBranch        *b_evgamnhits;   //!
   TBranch        *b_evothnhits;   //!
   TBranch        *b_slnunhits;   //!
   TBranch        *b_sllepnhits;   //!
   TBranch        *b_slpronhits;   //!
   TBranch        *b_slpi1nhits;   //!
   TBranch        *b_slpi0nhits;   //!
   TBranch        *b_slneunhits;   //!
   TBranch        *b_slgamnhits;   //!
   TBranch        *b_slothnhits;   //!
   TBranch        *b_pfnunhits;   //!
   TBranch        *b_pflepnhits;   //!
   TBranch        *b_pfpronhits;   //!
   TBranch        *b_pfpi1nhits;   //!
   TBranch        *b_pfpi0nhits;   //!
   TBranch        *b_pfneunhits;   //!
   TBranch        *b_pfgamnhits;   //!
   TBranch        *b_pfothnhits;   //!
   TBranch        *b_nu_completeness_from_pfp;   //!
   TBranch        *b_nu_purity_from_pfp;   //!
   TBranch        *b_trk_bragg_p_v;   //!
   TBranch        *b_trk_bragg_mu_v;   //!
   TBranch        *b_trk_bragg_pion_v;   //!
   TBranch        *b_trk_bragg_mip_v;   //!
   TBranch        *b_trk_bragg_p_alt_dir_v;   //!
   TBranch        *b_trk_bragg_mu_alt_dir_v;   //!
   TBranch        *b_trk_bragg_pion_alt_dir_v;   //!
   TBranch        *b_trk_bragg_p_fwd_preferred_v;   //!
   TBranch        *b_trk_bragg_mu_fwd_preferred_v;   //!
   TBranch        *b_trk_bragg_pion_fwd_preferred_v;   //!
   TBranch        *b_trk_pida_v;   //!
   TBranch        *b_trk_pid_chipr_v;   //!
   TBranch        *b_trk_pid_chipi_v;   //!
   TBranch        *b_trk_pid_chika_v;   //!
   TBranch        *b_trk_pid_chimu_v;   //!
   TBranch        *b_trk_bragg_p_u_v;   //!
   TBranch        *b_trk_bragg_mu_u_v;   //!
   TBranch        *b_trk_bragg_pion_u_v;   //!
   TBranch        *b_trk_bragg_mip_u_v;   //!
   TBranch        *b_trk_bragg_p_alt_dir_u_v;   //!
   TBranch        *b_trk_bragg_mu_alt_dir_u_v;   //!
   TBranch        *b_trk_bragg_pion_alt_dir_u_v;   //!
   TBranch        *b_trk_bragg_p_fwd_preferred_u_v;   //!
   TBranch        *b_trk_bragg_mu_fwd_preferred_u_v;   //!
   TBranch        *b_trk_bragg_pion_fwd_preferred_u_v;   //!
   TBranch        *b_trk_pida_u_v;   //!
   TBranch        *b_trk_pid_chipr_u_v;   //!
   TBranch        *b_trk_pid_chipi_u_v;   //!
   TBranch        *b_trk_pid_chika_u_v;   //!
   TBranch        *b_trk_pid_chimu_u_v;   //!
   TBranch        *b_trk_bragg_p_v_v;   //!
   TBranch        *b_trk_bragg_mu_v_v;   //!
   TBranch        *b_trk_bragg_pion_v_v;   //!
   TBranch        *b_trk_bragg_mip_v_v;   //!
   TBranch        *b_trk_bragg_p_alt_dir_v_v;   //!
   TBranch        *b_trk_bragg_mu_alt_dir_v_v;   //!
   TBranch        *b_trk_bragg_pion_alt_dir_v_v;   //!
   TBranch        *b_trk_bragg_p_fwd_preferred_v_v;   //!
   TBranch        *b_trk_bragg_mu_fwd_preferred_v_v;   //!
   TBranch        *b_trk_bragg_pion_fwd_preferred_v_v;   //!
   TBranch        *b_trk_pida_v_v;   //!
   TBranch        *b_trk_pid_chipr_v_v;   //!
   TBranch        *b_trk_pid_chipi_v_v;   //!
   TBranch        *b_trk_pid_chika_v_v;   //!
   TBranch        *b_trk_pid_chimu_v_v;   //!
   TBranch        *b_trk_pfp_id_v;   //!
   TBranch        *b_trk_dir_x_v;   //!
   TBranch        *b_trk_dir_y_v;   //!
   TBranch        *b_trk_dir_z_v;   //!
   TBranch        *b_trk_start_x_v;   //!
   TBranch        *b_trk_start_y_v;   //!
   TBranch        *b_trk_start_z_v;   //!
   TBranch        *b_trk_sce_start_x_v;   //!
   TBranch        *b_trk_sce_start_y_v;   //!
   TBranch        *b_trk_sce_start_z_v;   //!
   TBranch        *b_trk_end_x_v;   //!
   TBranch        *b_trk_end_y_v;   //!
   TBranch        *b_trk_end_z_v;   //!
   TBranch        *b_trk_sce_end_x_v;   //!
   TBranch        *b_trk_sce_end_y_v;   //!
   TBranch        *b_trk_sce_end_z_v;   //!
   TBranch        *b_trk_distance_v;   //!
   TBranch        *b_trk_theta_v;   //!
   TBranch        *b_trk_phi_v;   //!
   TBranch        *b_trk_len_v;   //!
   TBranch        *b_trk_mcs_muon_mom_v;   //!
   TBranch        *b_trk_range_muon_mom_v;   //!
   TBranch        *b_trk_energy_proton_v;   //!
   TBranch        *b_trk_energy_muon_v;   //!
   TBranch        *b_trk_calo_energy_u_v;   //!
   TBranch        *b_trk_calo_energy_v_v;   //!
   TBranch        *b_trk_calo_energy_y_v;   //!
   TBranch        *b_trk_llr_pid_u_v;   //!
   TBranch        *b_trk_llr_pid_v_v;   //!
   TBranch        *b_trk_llr_pid_y_v;   //!
   TBranch        *b_trk_llr_pid_v;   //!
   TBranch        *b_trk_llr_pid_score_v;   //!
   TBranch        *b_trk_trunk_dEdx_u_v;   //!
   TBranch        *b_trk_trunk_dEdx_v_v;   //!
   TBranch        *b_trk_trunk_dEdx_y_v;   //!
   TBranch        *b_trk_trunk_rr_dEdx_u_v;   //!
   TBranch        *b_trk_trunk_rr_dEdx_v_v;   //!
   TBranch        *b_trk_trunk_rr_dEdx_y_v;   //!
   TBranch        *b_trk_nhits_u_v;   //!
   TBranch        *b_trk_nhits_v_v;   //!
   TBranch        *b_trk_nhits_y_v;   //!
   TBranch        *b_trk_avg_deflection_mean_v;   //!
   TBranch        *b_trk_avg_deflection_stdev_v;   //!
   TBranch        *b_trk_avg_deflection_separation_mean_v;   //!
   TBranch        *b_trk_end_spacepoints_v;   //!
	TBranch*  b_single_photon_numu_score;   //!
	TBranch* b_single_photon_other_score;   //!
	TBranch* b_single_photon_ncpi0_score;   //!
	TBranch* b_single_photon_nue_score;   //!
	TBranch* b_reco_Ntrack;
	TBranch* b_numu_cc_flag;   
	TBranch* b_truth_Ntrack;
	TBranch* b_truth_NprimPio;
	TBranch* b_truth_isCC;
	TBranch* b_truth_vtxX;
	TBranch* b_truth_vtxY;
	TBranch* b_truth_vtxZ;               
	TBranch* b_truth_pdg;
	TBranch* b_truth_id;	
   TBranch* b_truth_startMomentum;   //!		
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
   TBranch* b_reco_larpid_proccess;   //!   
	TBranch* b_kine_particle_type;
	TBranch* b_kine_energy_particle;
	TBranch* b_reco_mother;
	TBranch* b_reco_startMomentum;
	TBranch* b_reco_startXYZT;
	TBranch* b_reco_endXYZT;
	TBranch* b_reco_pdg;
	TBranch* b_reco_id;
	TBranch	       *b_reco_truthMatch_pdg;
	TBranch        *b_reco_truthMatch_id;	
	TBranch        *b_Trec_spacepoints_x;   //!
	TBranch        *b_Trec_spacepoints_y;   //!
	TBranch        *b_Trec_spacepoints_z;   //!
	TBranch        *b_Trec_spacepoints_q;   //!
	TBranch        *b_Trec_spacepoints_cluster_id;   //!
	TBranch        *b_Trec_spacepoints_real_cluster_id;   //!
	TBranch        *b_Trec_spacepoints_sub_cluster_id;   //!
	TBranch        *b_Treccharge_spacepoints_x;   //!
	TBranch        *b_Treccharge_spacepoints_y;   //!
	TBranch        *b_Treccharge_spacepoints_z;   //!
	TBranch        *b_Treccharge_spacepoints_q;   //!
	TBranch        *b_Treccharge_spacepoints_cluster_id;   //!
	TBranch        *b_Treccharge_spacepoints_real_cluster_id;   //!
	TBranch        *b_Treccharge_spacepoints_sub_cluster_id;   //!
	TBranch        *b_Trecchargeblob_spacepoints_x;   //!
	TBranch        *b_Trecchargeblob_spacepoints_y;   //!
	TBranch        *b_Trecchargeblob_spacepoints_z;   //!
	TBranch        *b_Trecchargeblob_spacepoints_q;   //!
	TBranch        *b_Trecchargeblob_spacepoints_cluster_id;   //!
	TBranch        *b_Trecchargeblob_spacepoints_real_cluster_id;   //!
	TBranch        *b_Trecchargeblob_spacepoints_sub_cluster_id;   //!	 
   TBranch        *b_shr_score;   //!   
   TBranch        *b_n_veto_all_score;   //!
   TBranch        *b_n_veto_nonprim_score;   //!
   TBranch        *b_n_veto_score;   //!   

   TBranch        *b_shw_sp_n_good_showers;   //!
   TBranch        *b_shw_sp_n_20mev_showers;   //!
   TBranch        *b_shw_sp_n_br1_showers;   //!
   TBranch        *b_shw_sp_n_br2_showers;   //!
   TBranch        *b_shw_sp_n_br3_showers;   //!
   TBranch        *b_shw_sp_n_br4_showers;   //!
   TBranch        *b_shw_sp_n_20br1_showers;   //!   

   // dl lantern
   TBranch        *b_foundVertex;   //!
   TBranch        *b_vtxX;   //!
   TBranch        *b_vtxY;   //!
   TBranch        *b_vtxZ;   //!
   TBranch        *b_vtxScore;   //!   
   TBranch        *b_nTracks;   //!
   TBranch        *b_trackIsSecondary;   //!   
   TBranch        *b_nShowers;   //!
   TBranch        *b_showerIsSecondary;   //!
      
   // glee
   TBranch        *b_trackstub_candidate_veto_score;   //!	   
   TBranch        *b_trackstub_num_candidates;  
   TBranch        *b_reco_vertex_x;   //!
   TBranch        *b_reco_vertex_y;   //!
   TBranch        *b_reco_vertex_z;   //!    
   TBranch        *b_sss_num_candidates;   //!   
   TBranch        *b_reco_asso_showers;   //!
   TBranch        *b_reco_asso_tracks;   //!      

   mcc9_10_neutrino_selection(TString Label = "", TString Sample = "", TTree *tree=0);
   virtual ~mcc9_10_neutrino_selection();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef mcc9_10_neutrino_selection_cxx
mcc9_10_neutrino_selection::mcc9_10_neutrino_selection(TString Label, TString Sample, TTree *tree) : fChain(0) {

	// if parameter tree is not specified (or zero), connect the file
	// used to generate this class and read the Tree.

	fLabel = Label;
	fSample = Sample;

   TFile* f = nullptr;

	if (tree == 0) {

		f = (TFile*)gROOT->GetListOfFiles()->FindObject(fSample);
      
		if (!f || !f->IsOpen()) {

			f = new TFile(fSample);

		}

		TDirectory * dir = (TDirectory*)f->Get(fSample+":/nuselection");
      dir->GetObject("NeutrinoSelectionFilter",tree);

	}

	Init(tree);
   f_file = f;

   wc = (TTree*)(f_file->Get("wcpselection/T_BDTvars"));
   wc_kine = (TTree*)(f_file->Get("wcpselection/T_KINEvars"));   
	wc_eval = (TTree*)(f_file->Get("wcpselection/T_eval"));  
	wc_pfeval = (TTree*)(f_file->Get("wcpselection/T_PFeval"));    
	wc_sp = (TTree*)(f_file->Get("wcpselection/T_spacepoints"));
 	gl_vtx = (TTree*)(f_file->Get("singlephotonana/vertex_tree"));
 	dl = (TTree*)(f_file->Get("lantern/EventTree"));        

}

mcc9_10_neutrino_selection::~mcc9_10_neutrino_selection()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t mcc9_10_neutrino_selection::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t mcc9_10_neutrino_selection::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void mcc9_10_neutrino_selection::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   blip_x = 0;
   blip_y = 0;
   blip_z = 0;
   blip_dx = 0;
   blip_dw = 0;   
   blip_energy = 0;
   blip_charge = 0;
   blip_nplanes = 0;
   blip_proxtrkdist = 0;
   blip_proxtrkid = 0;
   blip_touchtrk = 0;
   blip_touchtrkid = 0;
   blip_pl0_nwires = 0;
   blip_pl1_nwires = 0;
   blip_pl2_nwires = 0;
   blip_pl0_bydeadwire = 0;
   blip_pl1_bydeadwire = 0;
   blip_pl2_bydeadwire = 0;
   blip_true_pdg = 0;
   blip_true_g4id = 0;
   blip_true_energy = 0;
   dtrk_x_boundary = 0;
   dtrk_y_boundary = 0;
   dtrk_z_boundary = 0;
   dshr_x_boundary = 0;
   dshr_y_boundary = 0;
   dshr_z_boundary = 0;
   dvtx_x_boundary = 0;
   dvtx_y_boundary = 0;
   dvtx_z_boundary = 0;
   dtrk_boundary = 0;
   dvtx_boundary = 0;
   dshr_boundary = 0;
   dmc_boundary = 0;
   pfp_slice_idx = 0;
   backtracked_pdg = 0;
   backtracked_e = 0;
   backtracked_tid = 0;
   backtracked_purity = 0;
   backtracked_completeness = 0;
   backtracked_overlay_purity = 0;
   backtracked_px = 0;
   backtracked_py = 0;
   backtracked_pz = 0;
   backtracked_start_x = 0;
   backtracked_start_y = 0;
   backtracked_start_z = 0;
   backtracked_start_t = 0;
   backtracked_start_U = 0;
   backtracked_start_V = 0;
   backtracked_start_Y = 0;
   backtracked_sce_start_x = 0;
   backtracked_sce_start_y = 0;
   backtracked_sce_start_z = 0;
   backtracked_sce_start_U = 0;
   backtracked_sce_start_V = 0;
   backtracked_sce_start_Y = 0;
   pfp_generation_v = 0;
   pfp_trk_daughters_v = 0;
   pfp_shr_daughters_v = 0;
   pfp_n_descendents_v = 0;
   pfp_vtx_x_v = 0;
   pfp_vtx_y_v = 0;
   pfp_vtx_z_v = 0;
   trk_score_v = 0;
   pfpdg = 0;
   pfnhits = 0;
   pfnplanehits_U = 0;
   pfnplanehits_V = 0;
   pfnplanehits_Y = 0;
   pfpplanesubclusters_U = 0;
   pfpplanesubclusters_V = 0;
   pfpplanesubclusters_Y = 0;
   pfpplanesubhitfracmax_U = 0;
   pfpplanesubhitfracmax_V = 0;
   pfpplanesubhitfracmax_Y = 0;
   slice_topo_score_v = 0;
   mc_pdg = 0;
   mc_E = 0;
   mc_n_elastic = 0;
   mc_n_inelastic = 0;
   mc_vx = 0;
   mc_vy = 0;
   mc_vz = 0;
   mc_endx = 0;
   mc_endy = 0;
   mc_endz = 0;
   mc_px = 0;
   mc_py = 0;
   mc_pz = 0;
   mc_end_p = 0;
   mc_generator_pdg = 0;
   mc_generator_mother = 0;
   mc_generator_rescatter = 0;
   mc_generator_trackid = 0;
   mc_generator_statuscode = 0;
   mc_generator_E = 0;
   mc_generator_px = 0;
   mc_generator_py = 0;
   mc_generator_pz = 0;
   mc_completeness = 0;
   mc_purity = 0;
   endmuonprocess = 0;
   weightsFlux = 0;
   weightsGenie = 0;
   weightsReint = 0;
   flash_pe_flash_matching_v = 0;
   slice_pe_flash_matching_v = 0;
   cosmic_flashmatch_score_v = 0;
   cosmic_topological_score_v = 0;
   cosmic_centerX_v = 0;
   cosmic_centerY_v = 0;
   cosmic_centerZ_v = 0;
   cosmic_totalCharge_v = 0;
   cosmic_nhits_v = 0;
   cosmic_nunhits_v = 0;
   cosmic_isclear_v = 0;
   X_SpcPts_v = 0;
   Y_SpcPts_v = 0;
   Z_SpcPts_v = 0;
   trkshrscore_v = 0;
   pfng2semlabel = 0;
   pfng2mipfrac = 0;
   pfng2hipfrac = 0;
   pfng2shrfrac = 0;
   pfng2mclfrac = 0;
   pfng2dfsfrac = 0;
   pfng2bkgfrac = 0;
   pfng2mipavrg = 0;
   pfng2hipavrg = 0;
   pfng2shravrg = 0;
   pfng2mclavrg = 0;
   pfng2dfsavrg = 0;
   pfng2bkgavrg = 0;
   pfnunhits = 0;
   pflepnhits = 0;
   pfpronhits = 0;
   pfpi1nhits = 0;
   pfpi0nhits = 0;
   pfneunhits = 0;
   pfgamnhits = 0;
   pfothnhits = 0;
   trk_bragg_p_v = 0;
   trk_bragg_mu_v = 0;
   trk_bragg_pion_v = 0;
   trk_bragg_mip_v = 0;
   trk_bragg_p_alt_dir_v = 0;
   trk_bragg_mu_alt_dir_v = 0;
   trk_bragg_pion_alt_dir_v = 0;
   trk_bragg_p_fwd_preferred_v = 0;
   trk_bragg_mu_fwd_preferred_v = 0;
   trk_bragg_pion_fwd_preferred_v = 0;
   trk_pida_v = 0;
   trk_pid_chipr_v = 0;
   trk_pid_chipi_v = 0;
   trk_pid_chika_v = 0;
   trk_pid_chimu_v = 0;
   trk_bragg_p_u_v = 0;
   trk_bragg_mu_u_v = 0;
   trk_bragg_pion_u_v = 0;
   trk_bragg_mip_u_v = 0;
   trk_bragg_p_alt_dir_u_v = 0;
   trk_bragg_mu_alt_dir_u_v = 0;
   trk_bragg_pion_alt_dir_u_v = 0;
   trk_bragg_p_fwd_preferred_u_v = 0;
   trk_bragg_mu_fwd_preferred_u_v = 0;
   trk_bragg_pion_fwd_preferred_u_v = 0;
   trk_pida_u_v = 0;
   trk_pid_chipr_u_v = 0;
   trk_pid_chipi_u_v = 0;
   trk_pid_chika_u_v = 0;
   trk_pid_chimu_u_v = 0;
   trk_bragg_p_v_v = 0;
   trk_bragg_mu_v_v = 0;
   trk_bragg_pion_v_v = 0;
   trk_bragg_mip_v_v = 0;
   trk_bragg_p_alt_dir_v_v = 0;
   trk_bragg_mu_alt_dir_v_v = 0;
   trk_bragg_pion_alt_dir_v_v = 0;
   trk_bragg_p_fwd_preferred_v_v = 0;
   trk_bragg_mu_fwd_preferred_v_v = 0;
   trk_bragg_pion_fwd_preferred_v_v = 0;
   trk_pida_v_v = 0;
   trk_pid_chipr_v_v = 0;
   trk_pid_chipi_v_v = 0;
   trk_pid_chika_v_v = 0;
   trk_pid_chimu_v_v = 0;
   trk_pfp_id_v = 0;
   trk_dir_x_v = 0;
   trk_dir_y_v = 0;
   trk_dir_z_v = 0;
   trk_start_x_v = 0;
   trk_start_y_v = 0;
   trk_start_z_v = 0;
   trk_sce_start_x_v = 0;
   trk_sce_start_y_v = 0;
   trk_sce_start_z_v = 0;
   trk_end_x_v = 0;
   trk_end_y_v = 0;
   trk_end_z_v = 0;
   trk_sce_end_x_v = 0;
   trk_sce_end_y_v = 0;
   trk_sce_end_z_v = 0;
   trk_distance_v = 0;
   trk_theta_v = 0;
   trk_phi_v = 0;
   trk_len_v = 0;
   trk_mcs_muon_mom_v = 0;
   trk_range_muon_mom_v = 0;
   trk_energy_proton_v = 0;
   trk_energy_muon_v = 0;
   trk_calo_energy_u_v = 0;
   trk_calo_energy_v_v = 0;
   trk_calo_energy_y_v = 0;
   trk_llr_pid_u_v = 0;
   trk_llr_pid_v_v = 0;
   trk_llr_pid_y_v = 0;
   trk_llr_pid_v = 0;
   trk_llr_pid_score_v = 0;
   trk_trunk_dEdx_u_v = 0;
   trk_trunk_dEdx_v_v = 0;
   trk_trunk_dEdx_y_v = 0;
   trk_trunk_rr_dEdx_u_v = 0;
   trk_trunk_rr_dEdx_v_v = 0;
   trk_trunk_rr_dEdx_y_v = 0;
   trk_nhits_u_v = 0;
   trk_nhits_v_v = 0;
   trk_nhits_y_v = 0;
   trk_avg_deflection_mean_v = 0;
   trk_avg_deflection_stdev_v = 0;
   trk_avg_deflection_separation_mean_v = 0;
   trk_end_spacepoints_v = 0;
	kine_particle_type = 0;
	kine_energy_particle = 0;	
	Trec_spacepoints_x = 0;
	Trec_spacepoints_y = 0;
	Trec_spacepoints_z = 0;
	Trec_spacepoints_q = 0;
	Trec_spacepoints_cluster_id = 0;
	Trec_spacepoints_real_cluster_id = 0;
	Trec_spacepoints_sub_cluster_id = 0;
	Treccharge_spacepoints_x = 0;
	Treccharge_spacepoints_y = 0;
	Treccharge_spacepoints_z = 0;
	Treccharge_spacepoints_q = 0;
	Treccharge_spacepoints_cluster_id = 0;
	Treccharge_spacepoints_real_cluster_id = 0;
	Treccharge_spacepoints_sub_cluster_id = 0;
	Trecchargeblob_spacepoints_x = 0;
	Trecchargeblob_spacepoints_y = 0;
	Trecchargeblob_spacepoints_z = 0;
	Trecchargeblob_spacepoints_q = 0;
	Trecchargeblob_spacepoints_cluster_id = 0;
	Trecchargeblob_spacepoints_real_cluster_id = 0;
	Trecchargeblob_spacepoints_sub_cluster_id = 0;	  
   
   // glee
   trackstub_candidate_veto_score = 0;   

   // Set branch addresses and branch pointers

   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   /*fChain->SetMakeClass(1);*/

   fChain->SetBranchAddress("interaction_time_abs", &interaction_time_abs, &b_interaction_time_abs);
   fChain->SetBranchAddress("selected", &selected, &b_selected);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("sub", &sub, &b_sub);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("nblips_saved", &nblips_saved, &b_nblips_saved);
   fChain->SetBranchAddress("blip_x", &blip_x, &b_blip_x);
   fChain->SetBranchAddress("blip_y", &blip_y, &b_blip_y);
   fChain->SetBranchAddress("blip_z", &blip_z, &b_blip_z);
   fChain->SetBranchAddress("blip_dx", &blip_dx, &b_blip_dx);
   fChain->SetBranchAddress("blip_dw", &blip_dw, &b_blip_dw);   
   fChain->SetBranchAddress("blip_energy", &blip_energy, &b_blip_energy);
   fChain->SetBranchAddress("blip_charge", &blip_charge, &b_blip_charge);
   fChain->SetBranchAddress("blip_nplanes", &blip_nplanes, &b_blip_nplanes);
   fChain->SetBranchAddress("blip_proxtrkdist", &blip_proxtrkdist, &b_blip_proxtrkdist);
   fChain->SetBranchAddress("blip_proxtrkid", &blip_proxtrkid, &b_blip_proxtrkid);
   fChain->SetBranchAddress("blip_touchtrk", &blip_touchtrk, &b_blip_touchtrk);
   fChain->SetBranchAddress("blip_touchtrkid", &blip_touchtrkid, &b_blip_touchtrkid);
   fChain->SetBranchAddress("blip_pl0_nwires", &blip_pl0_nwires, &b_blip_pl0_nwires);
   fChain->SetBranchAddress("blip_pl1_nwires", &blip_pl1_nwires, &b_blip_pl1_nwires);
   fChain->SetBranchAddress("blip_pl2_nwires", &blip_pl2_nwires, &b_blip_pl2_nwires);
   fChain->SetBranchAddress("blip_pl0_bydeadwire", &blip_pl0_bydeadwire, &b_blip_pl0_bydeadwire);
   fChain->SetBranchAddress("blip_pl1_bydeadwire", &blip_pl1_bydeadwire, &b_blip_pl1_bydeadwire);
   fChain->SetBranchAddress("blip_pl2_bydeadwire", &blip_pl2_bydeadwire, &b_blip_pl2_bydeadwire);
   fChain->SetBranchAddress("blip_true_pdg", &blip_true_pdg, &b_blip_true_pdg);
   fChain->SetBranchAddress("blip_true_g4id", &blip_true_g4id, &b_blip_true_g4id);
   fChain->SetBranchAddress("blip_true_energy", &blip_true_energy, &b_blip_true_energy);
   fChain->SetBranchAddress("dvtx", &dvtx, &b_dvtx);
   fChain->SetBranchAddress("dtrk", &dtrk, &b_dtrk);
   fChain->SetBranchAddress("contained_sps_ratio", &contained_sps_ratio, &b_contained_sps_ratio);
   fChain->SetBranchAddress("dtrk_x_boundary", &dtrk_x_boundary, &b_dtrk_x_boundary);
   fChain->SetBranchAddress("dtrk_y_boundary", &dtrk_y_boundary, &b_dtrk_y_boundary);
   fChain->SetBranchAddress("dtrk_z_boundary", &dtrk_z_boundary, &b_dtrk_z_boundary);
   fChain->SetBranchAddress("dshr_x_boundary", &dshr_x_boundary, &b_dshr_x_boundary);
   fChain->SetBranchAddress("dshr_y_boundary", &dshr_y_boundary, &b_dshr_y_boundary);
   fChain->SetBranchAddress("dshr_z_boundary", &dshr_z_boundary, &b_dshr_z_boundary);
   fChain->SetBranchAddress("dvtx_x_boundary", &dvtx_x_boundary, &b_dvtx_x_boundary);
   fChain->SetBranchAddress("dvtx_y_boundary", &dvtx_y_boundary, &b_dvtx_y_boundary);
   fChain->SetBranchAddress("dvtx_z_boundary", &dvtx_z_boundary, &b_dvtx_z_boundary);
   fChain->SetBranchAddress("dtrk_boundary", &dtrk_boundary, &b_dtrk_boundary);
   fChain->SetBranchAddress("dvtx_boundary", &dvtx_boundary, &b_dvtx_boundary);
   fChain->SetBranchAddress("dshr_boundary", &dshr_boundary, &b_dshr_boundary);
   fChain->SetBranchAddress("dmc_boundary", &dmc_boundary, &b_dmc_boundary);
   fChain->SetBranchAddress("CosmicIP", &CosmicIP, &b_CosmicIP);
   fChain->SetBranchAddress("CosmicIPAll3D", &CosmicIPAll3D, &b_CosmicIPAll3D);
   fChain->SetBranchAddress("CosmicDirAll3D", &CosmicDirAll3D, &b_CosmicDirAll3D);
   fChain->SetBranchAddress("CosmicIPAll2DEnds", &CosmicIPAll2DEnds, &b_CosmicIPAll2DEnds);
   fChain->SetBranchAddress("CosmicDirAll2DEnds", &CosmicDirAll2DEnds, &b_CosmicDirAll2DEnds);
   fChain->SetBranchAddress("CosmicIPAll2DOvlp", &CosmicIPAll2DOvlp, &b_CosmicIPAll2DOvlp);
   fChain->SetBranchAddress("CosmicDirAll2DOvlp", &CosmicDirAll2DOvlp, &b_CosmicDirAll2DOvlp);
   fChain->SetBranchAddress("_closestNuCosmicDist", &_closestNuCosmicDist, &b__closestNuCosmicDist);
   fChain->SetBranchAddress("leeweight", &leeweight, &b_leeweight);
   fChain->SetBranchAddress("true_pt", &true_pt, &b_true_pt);
   fChain->SetBranchAddress("true_pt_visible", &true_pt_visible, &b_true_pt_visible);
   fChain->SetBranchAddress("true_p", &true_p, &b_true_p);
   fChain->SetBranchAddress("true_p_visible", &true_p_visible, &b_true_p_visible);
   fChain->SetBranchAddress("true_e_visible", &true_e_visible, &b_true_e_visible);
   fChain->SetBranchAddress("_opfilter_pe_beam", &_opfilter_pe_beam, &b_opfilter_pe_beam);
   fChain->SetBranchAddress("_opfilter_pe_veto", &_opfilter_pe_veto, &b_opfilter_pe_veto);
   fChain->SetBranchAddress("nu_pdg", &nu_pdg, &b_nu_pdg);
   fChain->SetBranchAddress("ccnc", &ccnc, &b_ccnc);
   fChain->SetBranchAddress("nu_parent_pdg", &nu_parent_pdg, &b_nu_parent_pdg);
   fChain->SetBranchAddress("nu_hadron_pdg", &nu_hadron_pdg, &b_nu_hadron_pdg);
   fChain->SetBranchAddress("nu_decay_mode", &nu_decay_mode, &b_nu_decay_mode);
   fChain->SetBranchAddress("interaction", &interaction, &b_interaction);
   fChain->SetBranchAddress("nu_e", &nu_e, &b_nu_e);
   fChain->SetBranchAddress("nu_l", &nu_l, &b_nu_l);
   fChain->SetBranchAddress("nu_pt", &nu_pt, &b_nu_pt);
   fChain->SetBranchAddress("theta", &theta, &b_theta);
   fChain->SetBranchAddress("isVtxInFiducial", &isVtxInFiducial, &b_isVtxInFiducial);
   fChain->SetBranchAddress("truthFiducial", &truthFiducial, &b_truthFiducial);
   fChain->SetBranchAddress("true_nu_vtx_t", &true_nu_vtx_t, &b_true_nu_vtx_t);
   fChain->SetBranchAddress("true_nu_vtx_x", &true_nu_vtx_x, &b_true_nu_vtx_x);
   fChain->SetBranchAddress("true_nu_vtx_y", &true_nu_vtx_y, &b_true_nu_vtx_y);
   fChain->SetBranchAddress("true_nu_vtx_z", &true_nu_vtx_z, &b_true_nu_vtx_z);
   fChain->SetBranchAddress("true_nu_vtx_sce_x", &true_nu_vtx_sce_x, &b_true_nu_vtx_sce_x);
   fChain->SetBranchAddress("true_nu_vtx_sce_y", &true_nu_vtx_sce_y, &b_true_nu_vtx_sce_y);
   fChain->SetBranchAddress("true_nu_vtx_sce_z", &true_nu_vtx_sce_z, &b_true_nu_vtx_sce_z);
   fChain->SetBranchAddress("reco_nu_vtx_x", &reco_nu_vtx_x, &b_reco_nu_vtx_x);
   fChain->SetBranchAddress("reco_nu_vtx_y", &reco_nu_vtx_y, &b_reco_nu_vtx_y);
   fChain->SetBranchAddress("reco_nu_vtx_z", &reco_nu_vtx_z, &b_reco_nu_vtx_z);
   fChain->SetBranchAddress("reco_nu_vtx_sce_x", &reco_nu_vtx_sce_x, &b_reco_nu_vtx_sce_x);
   fChain->SetBranchAddress("reco_nu_vtx_sce_y", &reco_nu_vtx_sce_y, &b_reco_nu_vtx_sce_y);
   fChain->SetBranchAddress("reco_nu_vtx_sce_z", &reco_nu_vtx_sce_z, &b_reco_nu_vtx_sce_z);
   fChain->SetBranchAddress("nmuon", &nmuon, &b_nmuon);
   fChain->SetBranchAddress("muon_e", &muon_e, &b_muon_e);
   fChain->SetBranchAddress("muon_c", &muon_c, &b_muon_c);
   fChain->SetBranchAddress("muon_p", &muon_p, &b_muon_p);
   fChain->SetBranchAddress("nelec", &nelec, &b_nelec);
   fChain->SetBranchAddress("elec_e", &elec_e, &b_elec_e);
   fChain->SetBranchAddress("elec_c", &elec_c, &b_elec_c);
   fChain->SetBranchAddress("elec_p", &elec_p, &b_elec_p);
   fChain->SetBranchAddress("elec_vx", &elec_vx, &b_elec_vx);
   fChain->SetBranchAddress("elec_vy", &elec_vy, &b_elec_vy);
   fChain->SetBranchAddress("elec_vz", &elec_vz, &b_elec_vz);
   fChain->SetBranchAddress("elec_px", &elec_px, &b_elec_px);
   fChain->SetBranchAddress("elec_py", &elec_py, &b_elec_py);
   fChain->SetBranchAddress("elec_pz", &elec_pz, &b_elec_pz);
   fChain->SetBranchAddress("npi0", &npi0, &b_npi0);
   fChain->SetBranchAddress("pi0_e", &pi0_e, &b_pi0_e);
   fChain->SetBranchAddress("pi0_c", &pi0_c, &b_pi0_c);
   fChain->SetBranchAddress("pi0_p", &pi0_p, &b_pi0_p);
   fChain->SetBranchAddress("nneutron", &nneutron, &b_nneutron);
   fChain->SetBranchAddress("nproton", &nproton, &b_nproton);
   fChain->SetBranchAddress("proton_e", &proton_e, &b_proton_e);
   fChain->SetBranchAddress("proton_c", &proton_c, &b_proton_c);
   fChain->SetBranchAddress("proton_p", &proton_p, &b_proton_p);
   fChain->SetBranchAddress("npion", &npion, &b_npion);
   fChain->SetBranchAddress("pion_e", &pion_e, &b_pion_e);
   fChain->SetBranchAddress("pion_c", &pion_c, &b_pion_c);
   fChain->SetBranchAddress("pion_p", &pion_p, &b_pion_p);
   fChain->SetBranchAddress("neta", &neta, &b_neta);
   fChain->SetBranchAddress("eta_e", &eta_e, &b_eta_e);
   fChain->SetBranchAddress("nslice", &nslice, &b_nslice);
   fChain->SetBranchAddress("crtveto", &crtveto, &b_crtveto);
   fChain->SetBranchAddress("crthitpe", &crthitpe, &b_crthitpe);
   fChain->SetBranchAddress("pfp_slice_idx", &pfp_slice_idx, &b_pfp_slice_idx);
   fChain->SetBranchAddress("category", &category, &b_category);
   fChain->SetBranchAddress("backtracked_pdg", &backtracked_pdg, &b_backtracked_pdg);
   fChain->SetBranchAddress("backtracked_e", &backtracked_e, &b_backtracked_e);
   fChain->SetBranchAddress("backtracked_tid", &backtracked_tid, &b_backtracked_tid);
   fChain->SetBranchAddress("backtracked_purity", &backtracked_purity, &b_backtracked_purity);
   fChain->SetBranchAddress("backtracked_completeness", &backtracked_completeness, &b_backtracked_completeness);
   fChain->SetBranchAddress("backtracked_overlay_purity", &backtracked_overlay_purity, &b_backtracked_overlay_purity);
   fChain->SetBranchAddress("backtracked_px", &backtracked_px, &b_backtracked_px);
   fChain->SetBranchAddress("backtracked_py", &backtracked_py, &b_backtracked_py);
   fChain->SetBranchAddress("backtracked_pz", &backtracked_pz, &b_backtracked_pz);
   fChain->SetBranchAddress("backtracked_start_x", &backtracked_start_x, &b_backtracked_start_x);
   fChain->SetBranchAddress("backtracked_start_y", &backtracked_start_y, &b_backtracked_start_y);
   fChain->SetBranchAddress("backtracked_start_z", &backtracked_start_z, &b_backtracked_start_z);
   fChain->SetBranchAddress("backtracked_start_t", &backtracked_start_t, &b_backtracked_start_t);
   fChain->SetBranchAddress("backtracked_start_U", &backtracked_start_U, &b_backtracked_start_U);
   fChain->SetBranchAddress("backtracked_start_V", &backtracked_start_V, &b_backtracked_start_V);
   fChain->SetBranchAddress("backtracked_start_Y", &backtracked_start_Y, &b_backtracked_start_Y);
   fChain->SetBranchAddress("backtracked_sce_start_x", &backtracked_sce_start_x, &b_backtracked_sce_start_x);
   fChain->SetBranchAddress("backtracked_sce_start_y", &backtracked_sce_start_y, &b_backtracked_sce_start_y);
   fChain->SetBranchAddress("backtracked_sce_start_z", &backtracked_sce_start_z, &b_backtracked_sce_start_z);
   fChain->SetBranchAddress("backtracked_sce_start_U", &backtracked_sce_start_U, &b_backtracked_sce_start_U);
   fChain->SetBranchAddress("backtracked_sce_start_V", &backtracked_sce_start_V, &b_backtracked_sce_start_V);
   fChain->SetBranchAddress("backtracked_sce_start_Y", &backtracked_sce_start_Y, &b_backtracked_sce_start_Y);
   fChain->SetBranchAddress("lep_e", &lep_e, &b_lep_e);
   fChain->SetBranchAddress("pass", &pass, &b_pass);
   fChain->SetBranchAddress("swtrig", &swtrig, &b_swtrig);
   fChain->SetBranchAddress("evnhits", &evnhits, &b_evnhits);
   fChain->SetBranchAddress("slpdg", &slpdg, &b_slpdg);
   fChain->SetBranchAddress("slnhits", &slnhits, &b_slnhits);
   fChain->SetBranchAddress("n_pfps", &n_pfps, &b_n_pfps);
   fChain->SetBranchAddress("n_tracks", &n_tracks, &b_n_tracks);
   fChain->SetBranchAddress("n_showers", &n_showers, &b_n_showers);
   fChain->SetBranchAddress("pfp_generation_v", &pfp_generation_v, &b_pfp_generation_v);
   fChain->SetBranchAddress("pfp_trk_daughters_v", &pfp_trk_daughters_v, &b_pfp_trk_daughters_v);
   fChain->SetBranchAddress("pfp_shr_daughters_v", &pfp_shr_daughters_v, &b_pfp_shr_daughters_v);
   fChain->SetBranchAddress("pfp_n_descendents_v", &pfp_n_descendents_v, &b_pfp_n_descendents_v);
   fChain->SetBranchAddress("pfp_vtx_x_v", &pfp_vtx_x_v, &b_pfp_vtx_x_v);
   fChain->SetBranchAddress("pfp_vtx_y_v", &pfp_vtx_y_v, &b_pfp_vtx_y_v);
   fChain->SetBranchAddress("pfp_vtx_z_v", &pfp_vtx_z_v, &b_pfp_vtx_z_v);
   fChain->SetBranchAddress("trk_score_v", &trk_score_v, &b_trk_score_v);
   fChain->SetBranchAddress("pfpdg", &pfpdg, &b_pfpdg);
   fChain->SetBranchAddress("pfnhits", &pfnhits, &b_pfnhits);
   fChain->SetBranchAddress("pfnplanehits_U", &pfnplanehits_U, &b_pfnplanehits_U);
   fChain->SetBranchAddress("pfnplanehits_V", &pfnplanehits_V, &b_pfnplanehits_V);
   fChain->SetBranchAddress("pfnplanehits_Y", &pfnplanehits_Y, &b_pfnplanehits_Y);
   fChain->SetBranchAddress("pfpplanesubclusters_U", &pfpplanesubclusters_U, &b_pfpplanesubclusters_U);
   fChain->SetBranchAddress("pfpplanesubclusters_V", &pfpplanesubclusters_V, &b_pfpplanesubclusters_V);
   fChain->SetBranchAddress("pfpplanesubclusters_Y", &pfpplanesubclusters_Y, &b_pfpplanesubclusters_Y);
   fChain->SetBranchAddress("pfpplanesubhitfracmax_U", &pfpplanesubhitfracmax_U, &b_pfpplanesubhitfracmax_U);
   fChain->SetBranchAddress("pfpplanesubhitfracmax_V", &pfpplanesubhitfracmax_V, &b_pfpplanesubhitfracmax_V);
   fChain->SetBranchAddress("pfpplanesubhitfracmax_Y", &pfpplanesubhitfracmax_Y, &b_pfpplanesubhitfracmax_Y);
   fChain->SetBranchAddress("hits_u", &hits_u, &b_hits_u);
   fChain->SetBranchAddress("hits_v", &hits_v, &b_hits_v);
   fChain->SetBranchAddress("hits_y", &hits_y, &b_hits_y);
   fChain->SetBranchAddress("slice_id", &slice_id, &b_slice_id);
   fChain->SetBranchAddress("slice_topo_score_v", &slice_topo_score_v, &b_slice_topo_score_v);
   fChain->SetBranchAddress("topological_score", &topological_score, &b_topological_score);
   fChain->SetBranchAddress("slclustfrac", &slclustfrac, &b_slclustfrac);
   fChain->SetBranchAddress("mc_pdg", &mc_pdg, &b_mc_pdg);
   fChain->SetBranchAddress("mc_E", &mc_E, &b_mc_E);
   fChain->SetBranchAddress("mc_n_elastic", &mc_n_elastic, &b_mc_n_elastic);
   fChain->SetBranchAddress("mc_n_inelastic", &mc_n_inelastic, &b_mc_n_inelastic);
   fChain->SetBranchAddress("mc_vx", &mc_vx, &b_mc_vx);
   fChain->SetBranchAddress("mc_vy", &mc_vy, &b_mc_vy);
   fChain->SetBranchAddress("mc_vz", &mc_vz, &b_mc_vz);
   fChain->SetBranchAddress("mc_endx", &mc_endx, &b_mc_endx);
   fChain->SetBranchAddress("mc_endy", &mc_endy, &b_mc_endy);
   fChain->SetBranchAddress("mc_endz", &mc_endz, &b_mc_endz);
   fChain->SetBranchAddress("mc_px", &mc_px, &b_mc_px);
   fChain->SetBranchAddress("mc_py", &mc_py, &b_mc_py);
   fChain->SetBranchAddress("mc_pz", &mc_pz, &b_mc_pz);
   fChain->SetBranchAddress("mc_end_p", &mc_end_p, &b_mc_end_p);
   fChain->SetBranchAddress("mc_generator_pdg", &mc_generator_pdg, &b_mc_generator_pdg);
   fChain->SetBranchAddress("mc_generator_mother", &mc_generator_mother, &b_mc_generator_mother);
   fChain->SetBranchAddress("mc_generator_rescatter", &mc_generator_rescatter, &b_mc_generator_rescatter);
   fChain->SetBranchAddress("mc_generator_trackid", &mc_generator_trackid, &b_mc_generator_trackid);
   fChain->SetBranchAddress("mc_generator_statuscode", &mc_generator_statuscode, &b_mc_generator_statuscode);
   fChain->SetBranchAddress("mc_generator_E", &mc_generator_E, &b_mc_generator_E);
   fChain->SetBranchAddress("mc_generator_px", &mc_generator_px, &b_mc_generator_px);
   fChain->SetBranchAddress("mc_generator_py", &mc_generator_py, &b_mc_generator_py);
   fChain->SetBranchAddress("mc_generator_pz", &mc_generator_pz, &b_mc_generator_pz);
   fChain->SetBranchAddress("mc_completeness", &mc_completeness, &b_mc_completeness);
   fChain->SetBranchAddress("mc_purity", &mc_purity, &b_mc_purity);
   fChain->SetBranchAddress("endmuonprocess", &endmuonprocess, &b_endmuonprocess);
   fChain->SetBranchAddress("endmuonmichel", &endmuonmichel, &b_endmuonmichel);
   fChain->SetBranchAddress("filter_antibdt", &filter_antibdt, &b_filter_antibdt);
   fChain->SetBranchAddress("filter_ncpi0", &filter_ncpi0, &b_filter_ncpi0);
   fChain->SetBranchAddress("filter_pi0", &filter_pi0, &b_filter_pi0);
   fChain->SetBranchAddress("filter_ccinclusive", &filter_ccinclusive, &b_filter_ccinclusive);
   fChain->SetBranchAddress("flash_pe_flash_matching", &flash_pe_flash_matching, &b_flash_pe_flash_matching);
   fChain->SetBranchAddress("flash_pe_flash_matching_v", &flash_pe_flash_matching_v, &b_flash_pe_flash_matching_v);
   fChain->SetBranchAddress("slice_pe_flash_matching_v", &slice_pe_flash_matching_v, &b_slice_pe_flash_matching_v);
   fChain->SetBranchAddress("flash_time_flash_matching", &flash_time_flash_matching, &b_flash_time_flash_matching);
   fChain->SetBranchAddress("flash_y_flash_matching", &flash_y_flash_matching, &b_flash_y_flash_matching);
   fChain->SetBranchAddress("flash_z_flash_matching", &flash_z_flash_matching, &b_flash_z_flash_matching);
   fChain->SetBranchAddress("flash_timewidth_flash_matching", &flash_timewidth_flash_matching, &b_flash_timewidth_flash_matching);
   fChain->SetBranchAddress("flash_ywidth_flash_matching", &flash_ywidth_flash_matching, &b_flash_ywidth_flash_matching);
   fChain->SetBranchAddress("flash_zwidth_flash_matching", &flash_zwidth_flash_matching, &b_flash_zwidth_flash_matching);
   fChain->SetBranchAddress("nu_flashmatch_score", &nu_flashmatch_score, &b_nu_flashmatch_score);
   fChain->SetBranchAddress("nu_centerX", &nu_centerX, &b_nu_centerX);
   fChain->SetBranchAddress("nu_centerY", &nu_centerY, &b_nu_centerY);
   fChain->SetBranchAddress("nu_centerZ", &nu_centerZ, &b_nu_centerZ);
   fChain->SetBranchAddress("nu_totalCharge", &nu_totalCharge, &b_nu_totalCharge);
   fChain->SetBranchAddress("best_cosmic_flashmatch_score", &best_cosmic_flashmatch_score, &b_best_cosmic_flashmatch_score);
   fChain->SetBranchAddress("best_obviouscosmic_flashmatch_score", &best_obviouscosmic_flashmatch_score, &b_best_obviouscosmic_flashmatch_score);
   fChain->SetBranchAddress("cosmic_flashmatch_score_v", &cosmic_flashmatch_score_v, &b_cosmic_flashmatch_score_v);
   fChain->SetBranchAddress("cosmic_topological_score_v", &cosmic_topological_score_v, &b_cosmic_topological_score_v);
   fChain->SetBranchAddress("cosmic_centerX_v", &cosmic_centerX_v, &b_cosmic_centerX_v);
   fChain->SetBranchAddress("cosmic_centerY_v", &cosmic_centerY_v, &b_cosmic_centerY_v);
   fChain->SetBranchAddress("cosmic_centerZ_v", &cosmic_centerZ_v, &b_cosmic_centerZ_v);
   fChain->SetBranchAddress("cosmic_totalCharge_v", &cosmic_totalCharge_v, &b_cosmic_totalCharge_v);
   fChain->SetBranchAddress("cosmic_nhits_v", &cosmic_nhits_v, &b_cosmic_nhits_v);
   fChain->SetBranchAddress("cosmic_nunhits_v", &cosmic_nunhits_v, &b_cosmic_nunhits_v);
   fChain->SetBranchAddress("cosmic_isclear_v", &cosmic_isclear_v, &b_cosmic_isclear_v);
   fChain->SetBranchAddress("slice_orig_pass_id", &slice_orig_pass_id, &b_slice_orig_pass_id);
   fChain->SetBranchAddress("slice_orig_topo_score", &slice_orig_topo_score, &b_slice_orig_topo_score);
   fChain->SetBranchAddress("mcf_nu_e", &mcf_nu_e, &b_mcf_nu_e);
   fChain->SetBranchAddress("mcf_lep_e", &mcf_lep_e, &b_mcf_lep_e);
   fChain->SetBranchAddress("mcf_actvol", &mcf_actvol, &b_mcf_actvol);
   fChain->SetBranchAddress("mcf_nmm", &mcf_nmm, &b_mcf_nmm);
   fChain->SetBranchAddress("mcf_nmp", &mcf_nmp, &b_mcf_nmp);
   fChain->SetBranchAddress("mcf_nem", &mcf_nem, &b_mcf_nem);
   fChain->SetBranchAddress("mcf_nep", &mcf_nep, &b_mcf_nep);
   fChain->SetBranchAddress("mcf_np0", &mcf_np0, &b_mcf_np0);
   fChain->SetBranchAddress("mcf_npp", &mcf_npp, &b_mcf_npp);
   fChain->SetBranchAddress("mcf_npm", &mcf_npm, &b_mcf_npm);
   fChain->SetBranchAddress("mcf_mcshr_elec_etot", &mcf_mcshr_elec_etot, &b_mcf_mcshr_elec_etot);
   fChain->SetBranchAddress("mcf_pass_ccpi0", &mcf_pass_ccpi0, &b_mcf_pass_ccpi0);
   fChain->SetBranchAddress("mcf_pass_ncpi0", &mcf_pass_ncpi0, &b_mcf_pass_ncpi0);
   fChain->SetBranchAddress("mcf_pass_ccnopi", &mcf_pass_ccnopi, &b_mcf_pass_ccnopi);
   fChain->SetBranchAddress("mcf_pass_ncnopi", &mcf_pass_ncnopi, &b_mcf_pass_ncnopi);
   fChain->SetBranchAddress("mcf_pass_cccpi", &mcf_pass_cccpi, &b_mcf_pass_cccpi);
   fChain->SetBranchAddress("mcf_pass_nccpi", &mcf_pass_nccpi, &b_mcf_pass_nccpi);
   fChain->SetBranchAddress("X_SpcPts_v", &X_SpcPts_v, &b_X_SpcPts_v);
   fChain->SetBranchAddress("Y_SpcPts_v", &Y_SpcPts_v, &b_Y_SpcPts_v);
   fChain->SetBranchAddress("Z_SpcPts_v", &Z_SpcPts_v, &b_Z_SpcPts_v);
   fChain->SetBranchAddress("shr_id_MCStool", &shr_id_MCStool, &b_shr_pfp_id);
   fChain->SetBranchAddress("shr_hits_max_MCStool", &shr_hits_max_MCStool, &b_shr_hits_max_MCStool);
   fChain->SetBranchAddress("n_showers_contained_MCStool", &n_showers_contained_MCStool, &b_n_showers_contained_MCStool);
   fChain->SetBranchAddress("trkshrscore_v", &trkshrscore_v, &b_trkshrscore_v);
   fChain->SetBranchAddress("NeutrinoEnergy0", &NeutrinoEnergy0, &b_NeutrinoEnergy0);
   fChain->SetBranchAddress("NeutrinoEnergy1", &NeutrinoEnergy1, &b_NeutrinoEnergy1);
   fChain->SetBranchAddress("NeutrinoEnergy2", &NeutrinoEnergy2, &b_NeutrinoEnergy2);
   fChain->SetBranchAddress("SliceCaloEnergy0", &SliceCaloEnergy0, &b_SliceCaloEnergy0);
   fChain->SetBranchAddress("SliceCaloEnergy1", &SliceCaloEnergy1, &b_SliceCaloEnergy1);
   fChain->SetBranchAddress("SliceCaloEnergy2", &SliceCaloEnergy2, &b_SliceCaloEnergy2);
   fChain->SetBranchAddress("slcng2mip", &slcng2mip, &b_slcng2mip);
   fChain->SetBranchAddress("slcng2hip", &slcng2hip, &b_slcng2hip);
   fChain->SetBranchAddress("slcng2shr", &slcng2shr, &b_slcng2shr);
   fChain->SetBranchAddress("slcng2mcl", &slcng2mcl, &b_slcng2mcl);
   fChain->SetBranchAddress("slcng2dfs", &slcng2dfs, &b_slcng2dfs);
   fChain->SetBranchAddress("slcng2bkg", &slcng2bkg, &b_slcng2bkg);
   fChain->SetBranchAddress("clung2mip", &clung2mip, &b_clung2mip);
   fChain->SetBranchAddress("clung2hip", &clung2hip, &b_clung2hip);
   fChain->SetBranchAddress("clung2shr", &clung2shr, &b_clung2shr);
   fChain->SetBranchAddress("clung2mcl", &clung2mcl, &b_clung2mcl);
   fChain->SetBranchAddress("clung2dfs", &clung2dfs, &b_clung2dfs);
   fChain->SetBranchAddress("clung2bkg", &clung2bkg, &b_clung2bkg);
   fChain->SetBranchAddress("pfng2semlabel", &pfng2semlabel, &b_pfng2semlabel);
   fChain->SetBranchAddress("pfng2mipfrac", &pfng2mipfrac, &b_pfng2mipfrac);
   fChain->SetBranchAddress("pfng2hipfrac", &pfng2hipfrac, &b_pfng2hipfrac);
   fChain->SetBranchAddress("pfng2shrfrac", &pfng2shrfrac, &b_pfng2shrfrac);
   fChain->SetBranchAddress("pfng2mclfrac", &pfng2mclfrac, &b_pfng2mclfrac);
   fChain->SetBranchAddress("pfng2dfsfrac", &pfng2dfsfrac, &b_pfng2dfsfrac);
   fChain->SetBranchAddress("pfng2bkgfrac", &pfng2bkgfrac, &b_pfng2bkgfrac);
   fChain->SetBranchAddress("pfng2mipavrg", &pfng2mipavrg, &b_pfng2mipavrg);
   fChain->SetBranchAddress("pfng2hipavrg", &pfng2hipavrg, &b_pfng2hipavrg);
   fChain->SetBranchAddress("pfng2shravrg", &pfng2shravrg, &b_pfng2shravrg);
   fChain->SetBranchAddress("pfng2mclavrg", &pfng2mclavrg, &b_pfng2mclavrg);
   fChain->SetBranchAddress("pfng2dfsavrg", &pfng2dfsavrg, &b_pfng2dfsavrg);
   fChain->SetBranchAddress("pfng2bkgavrg", &pfng2bkgavrg, &b_pfng2bkgavrg);
   fChain->SetBranchAddress("pi0_mcgamma0_e", &pi0_mcgamma0_e, &b_pi0_mcgamma0_e);
   fChain->SetBranchAddress("pi0_mcgamma0_px", &pi0_mcgamma0_px, &b_pi0_mcgamma0_px);
   fChain->SetBranchAddress("pi0_mcgamma0_py", &pi0_mcgamma0_py, &b_pi0_mcgamma0_py);
   fChain->SetBranchAddress("pi0_mcgamma0_pz", &pi0_mcgamma0_pz, &b_pi0_mcgamma0_pz);
   fChain->SetBranchAddress("pi0_mcrcdot0", &pi0_mcrcdot0, &b_pi0_mcrcdot0);
   fChain->SetBranchAddress("pi0_mcrce0", &pi0_mcrce0, &b_pi0_mcrce0);
   fChain->SetBranchAddress("pi0_mcgamma1_e", &pi0_mcgamma1_e, &b_pi0_mcgamma1_e);
   fChain->SetBranchAddress("pi0_mcgamma1_px", &pi0_mcgamma1_px, &b_pi0_mcgamma1_px);
   fChain->SetBranchAddress("pi0_mcgamma1_py", &pi0_mcgamma1_py, &b_pi0_mcgamma1_py);
   fChain->SetBranchAddress("pi0_mcgamma1_pz", &pi0_mcgamma1_pz, &b_pi0_mcgamma1_pz);
   fChain->SetBranchAddress("pi0_mcrcdot1", &pi0_mcrcdot1, &b_pi0_mcrcdot1);
   fChain->SetBranchAddress("pi0_mcrce1", &pi0_mcrce1, &b_pi0_mcrce1);
   fChain->SetBranchAddress("pi0_nshower", &pi0_nshower, &b_pi0_nshower);
   fChain->SetBranchAddress("pi0_ntrack", &pi0_ntrack, &b_pi0_ntrack);
   fChain->SetBranchAddress("pi0_ngamma", &pi0_ngamma, &b_pi0_ngamma);
   fChain->SetBranchAddress("pi0_radlen1", &pi0_radlen1, &b_pi0_radlen1);
   fChain->SetBranchAddress("pi0_radlen2", &pi0_radlen2, &b_pi0_radlen2);
   fChain->SetBranchAddress("pi0_dot1", &pi0_dot1, &b_pi0_dot1);
   fChain->SetBranchAddress("pi0_dot2", &pi0_dot2, &b_pi0_dot2);
   fChain->SetBranchAddress("pi0_energy1_Y", &pi0_energy1_Y, &b_pi0_energy1_Y);
   fChain->SetBranchAddress("pi0_energy2_Y", &pi0_energy2_Y, &b_pi0_energy2_Y);
   fChain->SetBranchAddress("pi0_dir1_x", &pi0_dir1_x, &b_pi0_dir1_x);
   fChain->SetBranchAddress("pi0_dir1_y", &pi0_dir1_y, &b_pi0_dir1_y);
   fChain->SetBranchAddress("pi0_dir1_z", &pi0_dir1_z, &b_pi0_dir1_z);
   fChain->SetBranchAddress("pi0_dir2_x", &pi0_dir2_x, &b_pi0_dir2_x);
   fChain->SetBranchAddress("pi0_dir2_y", &pi0_dir2_y, &b_pi0_dir2_y);
   fChain->SetBranchAddress("pi0_dir2_z", &pi0_dir2_z, &b_pi0_dir2_z);
   fChain->SetBranchAddress("pi0_dedx1_Y", &pi0_dedx1_Y, &b_pi0_dedx1_Y);
   fChain->SetBranchAddress("pi0_dedx2_Y", &pi0_dedx2_Y, &b_pi0_dedx2_Y);
   fChain->SetBranchAddress("pi0_dedx1_fit_Y", &pi0_dedx1_fit_Y, &b_pi0_dedx1_fit_Y);
   fChain->SetBranchAddress("pi0_dedx2_fit_Y", &pi0_dedx2_fit_Y, &b_pi0_dedx2_fit_Y);
   fChain->SetBranchAddress("pi0_energy1_V", &pi0_energy1_V, &b_pi0_energy1_V);
   fChain->SetBranchAddress("pi0_energy2_V", &pi0_energy2_V, &b_pi0_energy2_V);
   fChain->SetBranchAddress("pi0_dedx1_V", &pi0_dedx1_V, &b_pi0_dedx1_V);
   fChain->SetBranchAddress("pi0_dedx2_V", &pi0_dedx2_V, &b_pi0_dedx2_V);
   fChain->SetBranchAddress("pi0_dedx1_fit_V", &pi0_dedx1_fit_V, &b_pi0_dedx1_fit_V);
   fChain->SetBranchAddress("pi0_dedx2_fit_V", &pi0_dedx2_fit_V, &b_pi0_dedx2_fit_V);
   fChain->SetBranchAddress("pi0_energy1_U", &pi0_energy1_U, &b_pi0_energy1_U);
   fChain->SetBranchAddress("pi0_energy2_U", &pi0_energy2_U, &b_pi0_energy2_U);
   fChain->SetBranchAddress("pi0_dedx1_U", &pi0_dedx1_U, &b_pi0_dedx1_U);
   fChain->SetBranchAddress("pi0_dedx2_U", &pi0_dedx2_U, &b_pi0_dedx2_U);
   fChain->SetBranchAddress("pi0_dedx1_fit_U", &pi0_dedx1_fit_U, &b_pi0_dedx1_fit_U);
   fChain->SetBranchAddress("pi0_dedx2_fit_U", &pi0_dedx2_fit_U, &b_pi0_dedx2_fit_U);
   fChain->SetBranchAddress("pi0_shrscore1", &pi0_shrscore1, &b_pi0_shrscore1);
   fChain->SetBranchAddress("pi0_shrscore2", &pi0_shrscore2, &b_pi0_shrscore2);
   fChain->SetBranchAddress("pi0_gammadot", &pi0_gammadot, &b_pi0_gammadot);
   fChain->SetBranchAddress("pi0_mass_Y", &pi0_mass_Y, &b_pi0_mass_Y);
   fChain->SetBranchAddress("pi0_mass_V", &pi0_mass_V, &b_pi0_mass_V);
   fChain->SetBranchAddress("pi0_mass_U", &pi0_mass_U, &b_pi0_mass_U);
   fChain->SetBranchAddress("pi0_rc_vtx_x", &pi0_rc_vtx_x, &b_pi0_rc_vtx_x);
   fChain->SetBranchAddress("pi0_rc_vtx_y", &pi0_rc_vtx_y, &b_pi0_rc_vtx_y);
   fChain->SetBranchAddress("pi0_rc_vtx_z", &pi0_rc_vtx_z, &b_pi0_rc_vtx_z);
   fChain->SetBranchAddress("pi0truth_gamma_parent", &pi0truth_gamma_parent, &b_pi0truth_gamma_parent);
   fChain->SetBranchAddress("pi0truth_elec_edep", &pi0truth_elec_edep, &b_pi0truth_elec_edep);
   fChain->SetBranchAddress("pi0truth_elec_etot", &pi0truth_elec_etot, &b_pi0truth_elec_etot);
   fChain->SetBranchAddress("pi0truth_elec_dist", &pi0truth_elec_dist, &b_pi0truth_elec_dist);
   fChain->SetBranchAddress("pi0truth_elec_parent", &pi0truth_elec_parent, &b_pi0truth_elec_parent);
   fChain->SetBranchAddress("pi0truth_gamma1_tid", &pi0truth_gamma1_tid, &b_pi0truth_gamma1_tid);
   fChain->SetBranchAddress("pi0truth_gamma1_edep", &pi0truth_gamma1_edep, &b_pi0truth_gamma1_edep);
   fChain->SetBranchAddress("pi0truth_gamma1_etot", &pi0truth_gamma1_etot, &b_pi0truth_gamma1_etot);
   fChain->SetBranchAddress("pi0truth_gamma1_dist", &pi0truth_gamma1_dist, &b_pi0truth_gamma1_dist);
   fChain->SetBranchAddress("pi0truth_gamma1_elec1", &pi0truth_gamma1_elec1, &b_pi0truth_gamma1_elec1);
   fChain->SetBranchAddress("pi0truth_gamma1_elec2", &pi0truth_gamma1_elec2, &b_pi0truth_gamma1_elec2);
   fChain->SetBranchAddress("pi0truth_gamma1_xpos", &pi0truth_gamma1_xpos, &b_pi0truth_gamma1_xpos);
   fChain->SetBranchAddress("pi0truth_gamma1_ypos", &pi0truth_gamma1_ypos, &b_pi0truth_gamma1_ypos);
   fChain->SetBranchAddress("pi0truth_gamma1_zpos", &pi0truth_gamma1_zpos, &b_pi0truth_gamma1_zpos);
   fChain->SetBranchAddress("pi0truth_gamma2_tid", &pi0truth_gamma2_tid, &b_pi0truth_gamma2_tid);
   fChain->SetBranchAddress("pi0truth_gamma2_edep", &pi0truth_gamma2_edep, &b_pi0truth_gamma2_edep);
   fChain->SetBranchAddress("pi0truth_gamma2_etot", &pi0truth_gamma2_etot, &b_pi0truth_gamma2_etot);
   fChain->SetBranchAddress("pi0truth_gamma2_dist", &pi0truth_gamma2_dist, &b_pi0truth_gamma2_dist);
   fChain->SetBranchAddress("pi0truth_gamma2_elec1", &pi0truth_gamma2_elec1, &b_pi0truth_gamma2_elec1);
   fChain->SetBranchAddress("pi0truth_gamma2_elec2", &pi0truth_gamma2_elec2, &b_pi0truth_gamma2_elec2);
   fChain->SetBranchAddress("pi0truth_gamma2_xpos", &pi0truth_gamma2_xpos, &b_pi0truth_gamma2_xpos);
   fChain->SetBranchAddress("pi0truth_gamma2_ypos", &pi0truth_gamma2_ypos, &b_pi0truth_gamma2_ypos);
   fChain->SetBranchAddress("pi0truth_gamma2_zpos", &pi0truth_gamma2_zpos, &b_pi0truth_gamma2_zpos);
   fChain->SetBranchAddress("pi0truth_gammadot", &pi0truth_gammadot, &b_pi0truth_gammadot);
   fChain->SetBranchAddress("pi0truth_run", &pi0truth_run, &b_pi0truth_run);
   fChain->SetBranchAddress("pi0truth_sub", &pi0truth_sub, &b_pi0truth_sub);
   fChain->SetBranchAddress("pi0truth_evt", &pi0truth_evt, &b_pi0truth_evt);
   fChain->SetBranchAddress("nflag_pl1", &nflag_pl1, &b_nflag_pl1);
   fChain->SetBranchAddress("nnoise_pl1", &nnoise_pl1, &b_nnoise_pl1);
   fChain->SetBranchAddress("nslhits_pl1", &nslhits_pl1, &b_nslhits_pl1);
   fChain->SetBranchAddress("nslnoise_pl1", &nslnoise_pl1, &b_nslnoise_pl1);
   fChain->SetBranchAddress("nhits_pl1", &nhits_pl1, &b_nhits_pl1);
   fChain->SetBranchAddress("frac_slnoise_pl1", &frac_slnoise_pl1, &b_frac_slnoise_pl1);
   fChain->SetBranchAddress("secondshower_U_charge", &secondshower_U_charge, &b_secondshower_U_charge);
   fChain->SetBranchAddress("secondshower_U_nhit", &secondshower_U_nhit, &b_secondshower_U_nhit);
   fChain->SetBranchAddress("secondshower_U_vtxdist", &secondshower_U_vtxdist, &b_secondshower_U_vtxdist);
   fChain->SetBranchAddress("secondshower_U_eigenratio", &secondshower_U_eigenratio, &b_secondshower_U_eigenratio);
   fChain->SetBranchAddress("secondshower_U_dot", &secondshower_U_dot, &b_secondshower_U_dot);
   fChain->SetBranchAddress("secondshower_U_dir", &secondshower_U_dir, &b_secondshower_U_dir);
   fChain->SetBranchAddress("secondshower_V_charge", &secondshower_V_charge, &b_secondshower_V_charge);
   fChain->SetBranchAddress("secondshower_V_nhit", &secondshower_V_nhit, &b_secondshower_V_nhit);
   fChain->SetBranchAddress("secondshower_V_vtxdist", &secondshower_V_vtxdist, &b_secondshower_V_vtxdist);
   fChain->SetBranchAddress("secondshower_V_eigenratio", &secondshower_V_eigenratio, &b_secondshower_V_eigenratio);
   fChain->SetBranchAddress("secondshower_V_dot", &secondshower_V_dot, &b_secondshower_V_dot);
   fChain->SetBranchAddress("secondshower_V_dir", &secondshower_V_dir, &b_secondshower_V_dir);
   fChain->SetBranchAddress("secondshower_Y_charge", &secondshower_Y_charge, &b_secondshower_Y_charge);
   fChain->SetBranchAddress("secondshower_Y_nhit", &secondshower_Y_nhit, &b_secondshower_Y_nhit);
   fChain->SetBranchAddress("secondshower_Y_vtxdist", &secondshower_Y_vtxdist, &b_secondshower_Y_vtxdist);
   fChain->SetBranchAddress("secondshower_Y_eigenratio", &secondshower_Y_eigenratio, &b_secondshower_Y_eigenratio);
   fChain->SetBranchAddress("secondshower_Y_dot", &secondshower_Y_dot, &b_secondshower_Y_dot);
   fChain->SetBranchAddress("secondshower_Y_dir", &secondshower_Y_dir, &b_secondshower_Y_dir);
   fChain->SetBranchAddress("origevnunhits", &origevnunhits, &b_origevnunhits);
   fChain->SetBranchAddress("origevnunhits2", &origevnunhits2, &b_origevnunhits2);
   fChain->SetBranchAddress("origevlepnhits", &origevlepnhits, &b_origevlepnhits);
   fChain->SetBranchAddress("origevpronhits", &origevpronhits, &b_origevpronhits);
   fChain->SetBranchAddress("origevpi1nhits", &origevpi1nhits, &b_origevpi1nhits);
   fChain->SetBranchAddress("origevpi0nhits", &origevpi0nhits, &b_origevpi0nhits);
   fChain->SetBranchAddress("origevneunhits", &origevneunhits, &b_origevneunhits);
   fChain->SetBranchAddress("origevgamnhits", &origevgamnhits, &b_origevgamnhits);
   fChain->SetBranchAddress("origevothnhits", &origevothnhits, &b_origevothnhits);
   fChain->SetBranchAddress("evnunhits", &evnunhits, &b_evnunhits);
   fChain->SetBranchAddress("evlepnhits", &evlepnhits, &b_evlepnhits);
   fChain->SetBranchAddress("evpronhits", &evpronhits, &b_evpronhits);
   fChain->SetBranchAddress("evpi1nhits", &evpi1nhits, &b_evpi1nhits);
   fChain->SetBranchAddress("evpi0nhits", &evpi0nhits, &b_evpi0nhits);
   fChain->SetBranchAddress("evneunhits", &evneunhits, &b_evneunhits);
   fChain->SetBranchAddress("evgamnhits", &evgamnhits, &b_evgamnhits);
   fChain->SetBranchAddress("evothnhits", &evothnhits, &b_evothnhits);
   fChain->SetBranchAddress("slnunhits", &slnunhits, &b_slnunhits);
   fChain->SetBranchAddress("sllepnhits", &sllepnhits, &b_sllepnhits);
   fChain->SetBranchAddress("slpronhits", &slpronhits, &b_slpronhits);
   fChain->SetBranchAddress("slpi1nhits", &slpi1nhits, &b_slpi1nhits);
   fChain->SetBranchAddress("slpi0nhits", &slpi0nhits, &b_slpi0nhits);
   fChain->SetBranchAddress("slneunhits", &slneunhits, &b_slneunhits);
   fChain->SetBranchAddress("slgamnhits", &slgamnhits, &b_slgamnhits);
   fChain->SetBranchAddress("slothnhits", &slothnhits, &b_slothnhits);
   fChain->SetBranchAddress("pfnunhits", &pfnunhits, &b_pfnunhits);
   fChain->SetBranchAddress("pflepnhits", &pflepnhits, &b_pflepnhits);
   fChain->SetBranchAddress("pfpronhits", &pfpronhits, &b_pfpronhits);
   fChain->SetBranchAddress("pfpi1nhits", &pfpi1nhits, &b_pfpi1nhits);
   fChain->SetBranchAddress("pfpi0nhits", &pfpi0nhits, &b_pfpi0nhits);
   fChain->SetBranchAddress("pfneunhits", &pfneunhits, &b_pfneunhits);
   fChain->SetBranchAddress("pfgamnhits", &pfgamnhits, &b_pfgamnhits);
   fChain->SetBranchAddress("pfothnhits", &pfothnhits, &b_pfothnhits);
   fChain->SetBranchAddress("nu_completeness_from_pfp", &nu_completeness_from_pfp, &b_nu_completeness_from_pfp);
   fChain->SetBranchAddress("nu_purity_from_pfp", &nu_purity_from_pfp, &b_nu_purity_from_pfp);
   fChain->SetBranchAddress("trk_bragg_p_v", &trk_bragg_p_v, &b_trk_bragg_p_v);
   fChain->SetBranchAddress("trk_bragg_mu_v", &trk_bragg_mu_v, &b_trk_bragg_mu_v);
   fChain->SetBranchAddress("trk_bragg_pion_v", &trk_bragg_pion_v, &b_trk_bragg_pion_v);
   fChain->SetBranchAddress("trk_bragg_mip_v", &trk_bragg_mip_v, &b_trk_bragg_mip_v);
   fChain->SetBranchAddress("trk_bragg_p_alt_dir_v", &trk_bragg_p_alt_dir_v, &b_trk_bragg_p_alt_dir_v);
   fChain->SetBranchAddress("trk_bragg_mu_alt_dir_v", &trk_bragg_mu_alt_dir_v, &b_trk_bragg_mu_alt_dir_v);
   fChain->SetBranchAddress("trk_bragg_pion_alt_dir_v", &trk_bragg_pion_alt_dir_v, &b_trk_bragg_pion_alt_dir_v);
   fChain->SetBranchAddress("trk_bragg_p_fwd_preferred_v", &trk_bragg_p_fwd_preferred_v, &b_trk_bragg_p_fwd_preferred_v);
   fChain->SetBranchAddress("trk_bragg_mu_fwd_preferred_v", &trk_bragg_mu_fwd_preferred_v, &b_trk_bragg_mu_fwd_preferred_v);
   fChain->SetBranchAddress("trk_bragg_pion_fwd_preferred_v", &trk_bragg_pion_fwd_preferred_v, &b_trk_bragg_pion_fwd_preferred_v);
   fChain->SetBranchAddress("trk_pida_v", &trk_pida_v, &b_trk_pida_v);
   fChain->SetBranchAddress("trk_pid_chipr_v", &trk_pid_chipr_v, &b_trk_pid_chipr_v);
   fChain->SetBranchAddress("trk_pid_chipi_v", &trk_pid_chipi_v, &b_trk_pid_chipi_v);
   fChain->SetBranchAddress("trk_pid_chika_v", &trk_pid_chika_v, &b_trk_pid_chika_v);
   fChain->SetBranchAddress("trk_pid_chimu_v", &trk_pid_chimu_v, &b_trk_pid_chimu_v);
   fChain->SetBranchAddress("trk_bragg_p_u_v", &trk_bragg_p_u_v, &b_trk_bragg_p_u_v);
   fChain->SetBranchAddress("trk_bragg_mu_u_v", &trk_bragg_mu_u_v, &b_trk_bragg_mu_u_v);
   fChain->SetBranchAddress("trk_bragg_pion_u_v", &trk_bragg_pion_u_v, &b_trk_bragg_pion_u_v);
   fChain->SetBranchAddress("trk_bragg_mip_u_v", &trk_bragg_mip_u_v, &b_trk_bragg_mip_u_v);
   fChain->SetBranchAddress("trk_bragg_p_alt_dir_u_v", &trk_bragg_p_alt_dir_u_v, &b_trk_bragg_p_alt_dir_u_v);
   fChain->SetBranchAddress("trk_bragg_mu_alt_dir_u_v", &trk_bragg_mu_alt_dir_u_v, &b_trk_bragg_mu_alt_dir_u_v);
   fChain->SetBranchAddress("trk_bragg_pion_alt_dir_u_v", &trk_bragg_pion_alt_dir_u_v, &b_trk_bragg_pion_alt_dir_u_v);
   fChain->SetBranchAddress("trk_bragg_p_fwd_preferred_u_v", &trk_bragg_p_fwd_preferred_u_v, &b_trk_bragg_p_fwd_preferred_u_v);
   fChain->SetBranchAddress("trk_bragg_mu_fwd_preferred_u_v", &trk_bragg_mu_fwd_preferred_u_v, &b_trk_bragg_mu_fwd_preferred_u_v);
   fChain->SetBranchAddress("trk_bragg_pion_fwd_preferred_u_v", &trk_bragg_pion_fwd_preferred_u_v, &b_trk_bragg_pion_fwd_preferred_u_v);
   fChain->SetBranchAddress("trk_pida_u_v", &trk_pida_u_v, &b_trk_pida_u_v);
   fChain->SetBranchAddress("trk_pid_chipr_u_v", &trk_pid_chipr_u_v, &b_trk_pid_chipr_u_v);
   fChain->SetBranchAddress("trk_pid_chipi_u_v", &trk_pid_chipi_u_v, &b_trk_pid_chipi_u_v);
   fChain->SetBranchAddress("trk_pid_chika_u_v", &trk_pid_chika_u_v, &b_trk_pid_chika_u_v);
   fChain->SetBranchAddress("trk_pid_chimu_u_v", &trk_pid_chimu_u_v, &b_trk_pid_chimu_u_v);
   fChain->SetBranchAddress("trk_bragg_p_v_v", &trk_bragg_p_v_v, &b_trk_bragg_p_v_v);
   fChain->SetBranchAddress("trk_bragg_mu_v_v", &trk_bragg_mu_v_v, &b_trk_bragg_mu_v_v);
   fChain->SetBranchAddress("trk_bragg_pion_v_v", &trk_bragg_pion_v_v, &b_trk_bragg_pion_v_v);
   fChain->SetBranchAddress("trk_bragg_mip_v_v", &trk_bragg_mip_v_v, &b_trk_bragg_mip_v_v);
   fChain->SetBranchAddress("trk_bragg_p_alt_dir_v_v", &trk_bragg_p_alt_dir_v_v, &b_trk_bragg_p_alt_dir_v_v);
   fChain->SetBranchAddress("trk_bragg_mu_alt_dir_v_v", &trk_bragg_mu_alt_dir_v_v, &b_trk_bragg_mu_alt_dir_v_v);
   fChain->SetBranchAddress("trk_bragg_pion_alt_dir_v_v", &trk_bragg_pion_alt_dir_v_v, &b_trk_bragg_pion_alt_dir_v_v);
   fChain->SetBranchAddress("trk_bragg_p_fwd_preferred_v_v", &trk_bragg_p_fwd_preferred_v_v, &b_trk_bragg_p_fwd_preferred_v_v);
   fChain->SetBranchAddress("trk_bragg_mu_fwd_preferred_v_v", &trk_bragg_mu_fwd_preferred_v_v, &b_trk_bragg_mu_fwd_preferred_v_v);
   fChain->SetBranchAddress("trk_bragg_pion_fwd_preferred_v_v", &trk_bragg_pion_fwd_preferred_v_v, &b_trk_bragg_pion_fwd_preferred_v_v);
   fChain->SetBranchAddress("trk_pida_v_v", &trk_pida_v_v, &b_trk_pida_v_v);
   fChain->SetBranchAddress("trk_pid_chipr_v_v", &trk_pid_chipr_v_v, &b_trk_pid_chipr_v_v);
   fChain->SetBranchAddress("trk_pid_chipi_v_v", &trk_pid_chipi_v_v, &b_trk_pid_chipi_v_v);
   fChain->SetBranchAddress("trk_pid_chika_v_v", &trk_pid_chika_v_v, &b_trk_pid_chika_v_v);
   fChain->SetBranchAddress("trk_pid_chimu_v_v", &trk_pid_chimu_v_v, &b_trk_pid_chimu_v_v);
   fChain->SetBranchAddress("trk_pfp_id_v", &trk_pfp_id_v, &b_trk_pfp_id_v);
   fChain->SetBranchAddress("trk_dir_x_v", &trk_dir_x_v, &b_trk_dir_x_v);
   fChain->SetBranchAddress("trk_dir_y_v", &trk_dir_y_v, &b_trk_dir_y_v);
   fChain->SetBranchAddress("trk_dir_z_v", &trk_dir_z_v, &b_trk_dir_z_v);
   fChain->SetBranchAddress("trk_start_x_v", &trk_start_x_v, &b_trk_start_x_v);
   fChain->SetBranchAddress("trk_start_y_v", &trk_start_y_v, &b_trk_start_y_v);
   fChain->SetBranchAddress("trk_start_z_v", &trk_start_z_v, &b_trk_start_z_v);
   fChain->SetBranchAddress("trk_sce_start_x_v", &trk_sce_start_x_v, &b_trk_sce_start_x_v);
   fChain->SetBranchAddress("trk_sce_start_y_v", &trk_sce_start_y_v, &b_trk_sce_start_y_v);
   fChain->SetBranchAddress("trk_sce_start_z_v", &trk_sce_start_z_v, &b_trk_sce_start_z_v);
   fChain->SetBranchAddress("trk_end_x_v", &trk_end_x_v, &b_trk_end_x_v);
   fChain->SetBranchAddress("trk_end_y_v", &trk_end_y_v, &b_trk_end_y_v);
   fChain->SetBranchAddress("trk_end_z_v", &trk_end_z_v, &b_trk_end_z_v);
   fChain->SetBranchAddress("trk_sce_end_x_v", &trk_sce_end_x_v, &b_trk_sce_end_x_v);
   fChain->SetBranchAddress("trk_sce_end_y_v", &trk_sce_end_y_v, &b_trk_sce_end_y_v);
   fChain->SetBranchAddress("trk_sce_end_z_v", &trk_sce_end_z_v, &b_trk_sce_end_z_v);
   fChain->SetBranchAddress("trk_distance_v", &trk_distance_v, &b_trk_distance_v);
   fChain->SetBranchAddress("trk_theta_v", &trk_theta_v, &b_trk_theta_v);
   fChain->SetBranchAddress("trk_phi_v", &trk_phi_v, &b_trk_phi_v);
   fChain->SetBranchAddress("trk_len_v", &trk_len_v, &b_trk_len_v);
   fChain->SetBranchAddress("trk_mcs_muon_mom_v", &trk_mcs_muon_mom_v, &b_trk_mcs_muon_mom_v);
   fChain->SetBranchAddress("trk_range_muon_mom_v", &trk_range_muon_mom_v, &b_trk_range_muon_mom_v);
   fChain->SetBranchAddress("trk_energy_proton_v", &trk_energy_proton_v, &b_trk_energy_proton_v);
   fChain->SetBranchAddress("trk_energy_muon_v", &trk_energy_muon_v, &b_trk_energy_muon_v);
   fChain->SetBranchAddress("trk_calo_energy_u_v", &trk_calo_energy_u_v, &b_trk_calo_energy_u_v);
   fChain->SetBranchAddress("trk_calo_energy_v_v", &trk_calo_energy_v_v, &b_trk_calo_energy_v_v);
   fChain->SetBranchAddress("trk_calo_energy_y_v", &trk_calo_energy_y_v, &b_trk_calo_energy_y_v);
   fChain->SetBranchAddress("trk_llr_pid_u_v", &trk_llr_pid_u_v, &b_trk_llr_pid_u_v);
   fChain->SetBranchAddress("trk_llr_pid_v_v", &trk_llr_pid_v_v, &b_trk_llr_pid_v_v);
   fChain->SetBranchAddress("trk_llr_pid_y_v", &trk_llr_pid_y_v, &b_trk_llr_pid_y_v);
   fChain->SetBranchAddress("trk_llr_pid_v", &trk_llr_pid_v, &b_trk_llr_pid_v);
   fChain->SetBranchAddress("trk_llr_pid_score_v", &trk_llr_pid_score_v, &b_trk_llr_pid_score_v);
   fChain->SetBranchAddress("trk_trunk_dEdx_u_v", &trk_trunk_dEdx_u_v, &b_trk_trunk_dEdx_u_v);
   fChain->SetBranchAddress("trk_trunk_dEdx_v_v", &trk_trunk_dEdx_v_v, &b_trk_trunk_dEdx_v_v);
   fChain->SetBranchAddress("trk_trunk_dEdx_y_v", &trk_trunk_dEdx_y_v, &b_trk_trunk_dEdx_y_v);
   fChain->SetBranchAddress("trk_trunk_rr_dEdx_u_v", &trk_trunk_rr_dEdx_u_v, &b_trk_trunk_rr_dEdx_u_v);
   fChain->SetBranchAddress("trk_trunk_rr_dEdx_v_v", &trk_trunk_rr_dEdx_v_v, &b_trk_trunk_rr_dEdx_v_v);
   fChain->SetBranchAddress("trk_trunk_rr_dEdx_y_v", &trk_trunk_rr_dEdx_y_v, &b_trk_trunk_rr_dEdx_y_v);
   fChain->SetBranchAddress("trk_nhits_u_v", &trk_nhits_u_v, &b_trk_nhits_u_v);
   fChain->SetBranchAddress("trk_nhits_v_v", &trk_nhits_v_v, &b_trk_nhits_v_v);
   fChain->SetBranchAddress("trk_nhits_y_v", &trk_nhits_y_v, &b_trk_nhits_y_v);
   fChain->SetBranchAddress("trk_avg_deflection_mean_v", &trk_avg_deflection_mean_v, &b_trk_avg_deflection_mean_v);
   fChain->SetBranchAddress("trk_avg_deflection_stdev_v", &trk_avg_deflection_stdev_v, &b_trk_avg_deflection_stdev_v);
   fChain->SetBranchAddress("trk_avg_deflection_separation_mean_v", &trk_avg_deflection_separation_mean_v, &b_trk_avg_deflection_separation_mean_v);
   fChain->SetBranchAddress("trk_end_spacepoints_v", &trk_end_spacepoints_v, &b_trk_end_spacepoints_v);
   fChain->SetBranchAddress("shr_score", &shr_score, &b_shr_score);

   Notify();

}

Bool_t mcc9_10_neutrino_selection::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void mcc9_10_neutrino_selection::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t mcc9_10_neutrino_selection::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef mcc9_10_neutrino_selection_cxx