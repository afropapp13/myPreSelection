#ifndef mcc9_10_true_neutrino_selection_h
#define mcc9_10_true_neutrino_selection_h

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
#include "../../../generators/Tools.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace constants;

class mcc9_10_true_neutrino_selection {

private:
	TString fSample;
	TString fLabel;

public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
static constexpr Int_t kMaxweights = 4;   

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           selected;
   Int_t           run;
   Int_t           sub;
   Int_t           evt;
   UInt_t          trk_id;
   UInt_t          shr_id;
   UInt_t          trk2_id;
   UInt_t          shr2_id;
   UInt_t          trk3_id;
   UInt_t          shr3_id;
   Float_t         shr_energy_tot;
   Float_t         shr_energy;
   Float_t         shr_energy_second;
   Float_t         shr_energy_third;
   Float_t         shr_energy_tot_cali;
   Float_t         shr_energy_cali;
   Float_t         shr_energy_second_cali;
   Float_t         shr_energy_third_cali;
   Float_t         shr_theta;
   Float_t         shr_phi;
   Float_t         shr_pca_0;
   Float_t         shr_pca_1;
   Float_t         shr_pca_2;
   Float_t         shr_px;
   Float_t         shr_py;
   Float_t         shr_pz;
   Float_t         shr_openangle;
   Float_t         shr_tkfit_start_x;
   Float_t         shr_tkfit_start_y;
   Float_t         shr_tkfit_start_z;
   Float_t         shr_tkfit_theta;
   Float_t         shr_tkfit_phi;
   Float_t         shr_start_x;
   Float_t         shr_start_y;
   Float_t         shr_start_z;
   Float_t         shr_dedx_Y;
   Float_t         shr_dedx_V;
   Float_t         shr_dedx_U;
   Float_t         shr_dedx_Y_cali;
   Float_t         shr_dedx_V_cali;
   Float_t         shr_dedx_U_cali;
   Float_t         shr_tkfit_dedx_Y;
   Float_t         shr_tkfit_dedx_V;
   Float_t         shr_tkfit_dedx_U;
   Float_t         shr_tkfit_dedx_max;
   UInt_t          shr_tkfit_nhits_Y;
   UInt_t          shr_tkfit_nhits_V;
   UInt_t          shr_tkfit_nhits_U;
   Float_t         shr_llrpid_dedx_Y;
   Float_t         shr_llrpid_dedx_V;
   Float_t         shr_llrpid_dedx_U;
   Float_t         shr_llrpid_dedx;
   Float_t         shr_tkfit_dedx_Y_alt;
   Float_t         shr_tkfit_dedx_V_alt;
   Float_t         shr_tkfit_dedx_U_alt;
   UInt_t          shr_tkfit_nhits_Y_alt;
   UInt_t          shr_tkfit_nhits_V_alt;
   UInt_t          shr_tkfit_nhits_U_alt;
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
   UChar_t         ismerged;
   Float16_t       merge_bestdot;
   Float16_t       merge_bestdist;
   Float16_t       merge_vtx_x;
   Float16_t       merge_vtx_y;
   Float16_t       merge_vtx_z;
   UInt_t          merge_tk_ipfp;
   Float_t         shr_tkfit_2cm_dedx_Y;
   Float_t         shr_tkfit_2cm_dedx_V;
   Float_t         shr_tkfit_2cm_dedx_U;
   UInt_t          shr_tkfit_2cm_nhits_Y;
   UInt_t          shr_tkfit_2cm_nhits_V;
   UInt_t          shr_tkfit_2cm_nhits_U;
   Float_t         shr_tkfit_gap05_dedx_Y;
   Float_t         shr_tkfit_gap05_dedx_V;
   Float_t         shr_tkfit_gap05_dedx_U;
   UInt_t          shr_tkfit_gap05_nhits_Y;
   UInt_t          shr_tkfit_gap05_nhits_V;
   UInt_t          shr_tkfit_gap05_nhits_U;
   Float_t         shr_tkfit_gap10_dedx_Y;
   Float_t         shr_tkfit_gap10_dedx_V;
   Float_t         shr_tkfit_gap10_dedx_U;
   UInt_t          shr_tkfit_gap10_nhits_Y;
   UInt_t          shr_tkfit_gap10_nhits_V;
   UInt_t          shr_tkfit_gap10_nhits_U;
   Float_t         shr_chipr;
   Float_t         shr_chimu;
   Float_t         shr_bragg_p;
   Float_t         shr_bragg_mu;
   Float_t         shr_bragg_mip;
   Float_t         shr_bragg_kaon;
   Float_t         shr_bragg_pion;
   Float_t         tksh_distance;
   Float_t         tksh_angle;
   Float_t         shr_distance;
   Float_t         shr_score;
   Int_t           shr_bkt_pdg;
   Float_t         shr_bkt_purity;
   Float_t         shr_bkt_completeness;
   Float_t         shr_bkt_E;
   Float_t         trk_len;
   Float_t         trk_theta;
   Float_t         trk_phi;
   Float_t         trk_energy;
   Float_t         trk_energy_muon;
   Float_t         trk_energy_muon_mcs;
   Float_t         trk_energy_tot;
   Float_t         trk_energy_muon_tot;
   Float_t         trk_distance;
   Float_t         trk_score;
   Int_t           trk_bkt_pdg;
   Float_t         trk_bkt_purity;
   Float_t         trk_bkt_completeness;
   Float_t         trk_bkt_E;
   Float_t         trk_chipr_best;
   Float_t         trk_chipr_worst;
   Float_t         trk_chimu_best;
   Float_t         trk_chimu_worst;
   Float_t         trk_chipr;
   Float_t         trk_chimu;
   Float_t         trk_pida;
   Float_t         trk_bragg_p;
   Float_t         trk_bragg_mu;
   Float_t         trk_bragg_mip;
   Float_t         trk_bragg_kaon;
   Float_t         trk_bragg_pion;
   UInt_t          trk_hits_max;
   UInt_t          shr_hits_max;
   vector<int>     *all_shr_hits;
   vector<int>     *all_trk_hits;
   vector<float>   *all_shr_energies;
   vector<float>   *all_trk_energies;
   UInt_t          trk_hits_2nd;
   UInt_t          shr_hits_2nd;
   UInt_t          trk_hits_3rd;
   UInt_t          shr_hits_3rd;
   Float_t         trkshrhitdist0;
   Float_t         trkshrhitdist1;
   Float_t         trkshrhitdist2;
   Float_t         trk2shrhitdist0;
   Float_t         trk2shrhitdist1;
   Float_t         trk2shrhitdist2;
   Float_t         trk1trk2hitdist0;
   Float_t         trk1trk2hitdist1;
   Float_t         trk1trk2hitdist2;
   UInt_t          total_hits_y;
   Float_t         extra_energy_y;
   Float_t         trk_energy_hits_tot;
   UInt_t          subcluster;
   UInt_t          shrsubclusters0;
   UInt_t          shrsubclusters1;
   UInt_t          shrsubclusters2;
   Float16_t       shrclusfrac0;
   Float16_t       shrclusfrac1;
   Float16_t       shrclusfrac2;
   Float16_t       shrclusdir0;
   Float16_t       shrclusdir1;
   Float16_t       shrclusdir2;
   UInt_t          shr_hits_tot;
   UInt_t          shr_hits_y_tot;
   UInt_t          shr_hits_u_tot;
   UInt_t          shr_hits_v_tot;
   UInt_t          trk_hits_tot;
   UInt_t          trk_hits_y_tot;
   UInt_t          trk_hits_u_tot;
   UInt_t          trk_hits_v_tot;
   Float_t         _elecclusters_U_charge;
   Float_t         _elecclusters_V_charge;
   Float_t         _elecclusters_Y_charge;
   Int_t           _elecclusters_U_N;
   Int_t           _elecclusters_V_N;
   Int_t           _elecclusters_Y_N;
   UInt_t          n_tracks_contained;
   UInt_t          n_showers_contained;
   Float_t         matched_E;
   Float_t         hits_ratio;
   Float_t         contained_fraction;
   Float_t         sps_contained_fraction;
   Float_t         pt;
   Float_t         p;
   Float_t         pt_assume_muon;
   Float_t         p_assume_muon;
   Float_t         reco_e;
   Int_t           nblips_saved;
   vector<float>   *blip_x;
   vector<float>   *blip_y;
   vector<float>   *blip_z;
   vector<float>   *blip_size;
   vector<float>   *blip_energy;
   vector<float>   *blip_charge;
   vector<int>     *blip_nplanes;
   vector<float>   *blip_proxtrkdist;
   vector<int>     *blip_proxtrkid;
   vector<bool>    *blip_touchtrk;
   vector<int>     *blip_touchtrkid;
   vector<float>   *blip_badwirefrac;
   vector<int>     *blip_pl0_nwires;
   vector<int>     *blip_pl1_nwires;
   vector<int>     *blip_pl2_nwires;
   vector<bool>    *blip_pl0_bydeadwire;
   vector<bool>    *blip_pl1_bydeadwire;
   vector<bool>    *blip_pl2_bydeadwire;
   vector<int>     *blip_pl0_centerwire;
   vector<int>     *blip_pl1_centerwire;
   vector<int>     *blip_pl2_centerwire;
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
   Float16_t       shrPCA_1Cr;
   Float16_t       shrPCA_2Cr;
   Float16_t       shrPCA_3Cr;
   Float16_t       shrPCA_1Ce;
   Float16_t       shrPCA_2Ce;
   Float16_t       shrPCA_3Ce;
   Float16_t       shrPCA1CAS;
   Float16_t       shrPCA2CAS;
   Float16_t       shrPCA3CAS;
   Float16_t       shrPCA_1Cr2h;
   Float16_t       shrPCA_2Cr2h;
   Float16_t       shrPCA_3Cr2h;
   Float16_t       shrPCA_1Cr1h;
   Float16_t       shrPCA_2Cr1h;
   Float16_t       shrPCA_3Cr1h;
   Float16_t       shrMCSMom;
   Float16_t       shrMCSMom1h;
   Float16_t       shrMCSMom2h;
   Float16_t       shrPCALen;
   UInt_t          n_shrSpcPts;
   vector<float>   *PCAWin_1Cr_5cm;
   vector<float>   *PCAWin_2Cr_5cm;
   vector<float>   *PCAWin_3Cr_5cm;
   vector<float>   *PCAWin_dist_5cm;
   vector<int>     *PCAWin_npts_5cm;
   Float16_t       shrStart_5cm;
   Float16_t       shrStartMCS_5cm;
   Float16_t       shrMCSAS_5cm;
   Float16_t       shrPCA1CAS_5cm;
   Float16_t       shrPCA2CAS_5cm;
   Float16_t       shrPCA3CAS_5cm;
   Float16_t       shrPCA1CMed_5cm;
   vector<float>   *PCAWin_1Cr_2_5cm;
   vector<float>   *PCAWin_2Cr_2_5cm;
   vector<float>   *PCAWin_3Cr_2_5cm;
   vector<float>   *PCAWin_dist_2_5cm;
   vector<int>     *PCAWin_npts_2_5cm;
   Float16_t       shrStart_2_5cm;
   Float16_t       shrStartMCS_2_5cm;
   Float16_t       shrMCSAS_2_5cm;
   Float16_t       shrPCA1CAS_2_5cm;
   Float16_t       shrPCA2CAS_2_5cm;
   Float16_t       shrPCA3CAS_2_5cm;
   Float16_t       shrPCA1CMed_2_5cm;
   Float16_t       DeltaMed;
   Float16_t       DeltaMed1h;
   Float16_t       DeltaMed2h;
   Float16_t       DeltaRMS;
   Float16_t       DeltaRMS1h;
   Float16_t       DeltaRMS2h;
   Float16_t       CylFrac_1cm;
   Float16_t       CylFrac1h_1cm;
   Float16_t       CylFrac2h_1cm;
   Float16_t       CylFrac_2cm;
   Float16_t       CylFrac1h_2cm;
   Float16_t       CylFrac2h_2cm;
   Float16_t       CylFrac_3cm;
   Float16_t       CylFrac1h_3cm;
   Float16_t       CylFrac2h_3cm;
   Float16_t       CylFrac_4cm;
   Float16_t       CylFrac1h_4cm;
   Float16_t       CylFrac2h_4cm;
   Float16_t       CylFrac_5cm;
   Float16_t       CylFrac1h_5cm;
   Float16_t       CylFrac2h_5cm;
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
   Int_t           clung2mip;
   Int_t           clung2hip;
   Int_t           clung2shr;
   Int_t           clung2mcl;
   Int_t           clung2dfs;
   vector<int>     *pfng2semlabel;
   vector<float>   *pfng2mipfrac;
   vector<float>   *pfng2hipfrac;
   vector<float>   *pfng2shrfrac;
   vector<float>   *pfng2mclfrac;
   vector<float>   *pfng2dfsfrac;
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
   vector<float>   *shr_dedx_u_v;
   vector<float>   *shr_dedx_v_v;
   vector<float>   *shr_dedx_y_v;
   vector<float>   *shr_energy_u_v;
   vector<float>   *shr_energy_v_v;
   vector<float>   *shr_energy_y_v;
   vector<unsigned long> *shr_pfp_id_v;
   vector<float>   *shr_start_x_v;
   vector<float>   *shr_start_y_v;
   vector<float>   *shr_start_z_v;
   vector<float>   *shr_dist_v;
   vector<float>   *shr_start_U_v;
   vector<float>   *shr_start_V_v;
   vector<float>   *shr_px_v;
   vector<float>   *shr_py_v;
   vector<float>   *shr_pz_v;
   vector<float>   *shr_openangle_v;
   vector<float>   *shr_theta_v;
   vector<float>   *shr_phi_v;
   vector<float>   *shr_pitch_u_v;
   vector<float>   *shr_pitch_v_v;
   vector<float>   *shr_pitch_y_v;
   vector<int>     *shr_tkfit_nhits_v;
   vector<float>   *shr_tkfit_start_x_v;
   vector<float>   *shr_tkfit_start_y_v;
   vector<float>   *shr_tkfit_start_z_v;
   vector<float>   *shr_tkfit_start_U_v;
   vector<float>   *shr_tkfit_start_V_v;
   vector<float>   *shr_tkfit_theta_v;
   vector<float>   *shr_tkfit_phi_v;
   vector<float>   *shr_tkfit_pitch_u_v;
   vector<float>   *shr_tkfit_pitch_v_v;
   vector<float>   *shr_tkfit_pitch_y_v;
   vector<float>   *shr_tkfit_dedx_u_v;
   vector<float>   *shr_tkfit_dedx_v_v;
   vector<float>   *shr_tkfit_dedx_y_v;
   vector<float>   *shr_tkfit_gap10_dedx_u_v;
   vector<float>   *shr_tkfit_gap10_dedx_v_v;
   vector<float>   *shr_tkfit_gap10_dedx_y_v;
   vector<int>     *shr_tkfit_dedx_nhits_u_v;
   vector<int>     *shr_tkfit_dedx_nhits_v_v;
   vector<int>     *shr_tkfit_dedx_nhits_y_v;
   vector<float>   *shr_llr_pid_u_v;
   vector<float>   *shr_llr_pid_v_v;
   vector<float>   *shr_llr_pid_y_v;
   vector<float>   *shr_llr_pid_v;
   vector<float>   *shr_llr_pid_score_v;
   vector<float>   *shr_moliere_avg_v;
   vector<float>   *shr_moliere_rms_v;
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
   Float_t         bdt_nuNCpi0;
   Float_t         bdt_numuCCpi0;
   Float_t         bdt_numuCC;
   Float_t         bdt_ext;
   Float_t         bdt_cosmic;
   Float_t         bdt_global;
   Int_t           pass_antibdt_filter;
   Float_t         bdt_pi0_np;
   Float_t         bdt_nonpi0_np;
   Float_t         bdt_bkg_0p;
   Float_t         anglediff_Y;
   Float_t         anglediff_V;
   Float_t         anglediff_U;
   Float_t         trkpid;

  // List of branches
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
  TBranch        *b_shr_energy_tot;   //!
  TBranch        *b_shr_energy;   //!
  TBranch        *b_shr_energy_second;   //!
  TBranch        *b_shr_energy_third;   //!
  TBranch        *b_shr_energy_tot_cali;   //!
  TBranch        *b_shr_energy_cali;   //!
  TBranch        *b_shr_energy_second_cali;   //!
  TBranch        *b_shr_energy_third_cali;   //!
  TBranch        *b_shr_theta;   //!
  TBranch        *b_shr_phi;   //!
  TBranch        *b_shr_pca_0;   //!
  TBranch        *b_shr_pca_1;   //!
  TBranch        *b_shr_pca_2;   //!
  TBranch        *b_shr_px;   //!
  TBranch        *b_shr_py;   //!
  TBranch        *b_shr_pz;   //!
  TBranch        *b_shr_openangle;   //!
  TBranch        *b_shr_tkfit_start_x;   //!
  TBranch        *b_shr_tkfit_start_y;   //!
  TBranch        *b_shr_tkfit_start_z;   //!
  TBranch        *b_shr_tkfit_theta;   //!
  TBranch        *b_shr_tkfit_phi;   //!
  TBranch        *b_shr_start_x;   //!
  TBranch        *b_shr_start_y;   //!
  TBranch        *b_shr_start_z;   //!
  TBranch        *b_shr_dedx_Y;   //!
  TBranch        *b_shr_dedx_V;   //!
  TBranch        *b_shr_dedx_U;   //!
  TBranch        *b_shr_dedx_Y_cali;   //!
  TBranch        *b_shr_dedx_V_cali;   //!
  TBranch        *b_shr_dedx_U_cali;   //!
  TBranch        *b_shr_tkfit_dedx_Y;   //!
  TBranch        *b_shr_tkfit_dedx_V;   //!
  TBranch        *b_shr_tkfit_dedx_U;   //!
  TBranch        *b_shr_tkfit_dedx_max;   //!
  TBranch        *b_shr_tkfit_nhits_Y;   //!
  TBranch        *b_shr_tkfit_nhits_V;   //!
  TBranch        *b_shr_tkfit_nhits_U;   //!
  TBranch        *b_shr_llrpid_dedx_Y;   //!
  TBranch        *b_shr_llrpid_dedx_V;   //!
  TBranch        *b_shr_llrpid_dedx_U;   //!
  TBranch        *b_shr_llrpid_dedx;   //!
  TBranch        *b_shr_tkfit_dedx_Y_alt;   //!
  TBranch        *b_shr_tkfit_dedx_V_alt;   //!
  TBranch        *b_shr_tkfit_dedx_U_alt;   //!
  TBranch        *b_shr_tkfit_nhits_Y_alt;   //!
  TBranch        *b_shr_tkfit_nhits_V_alt;   //!
  TBranch        *b_shr_tkfit_nhits_U_alt;   //!
  TBranch        *b__trkfit;   //!
  TBranch        *b_shr_tkfit_npoints;   //!
  TBranch        *b_shr_tkfit_npointsvalid;   //!
  TBranch        *b_f;   //!
  TBranch        *b_ismerged;   //!
  TBranch        *b_merge_tk_ipfp;   //!
  TBranch        *b_shr_tkfit_2cm_dedx_Y;   //!
  TBranch        *b_shr_tkfit_2cm_dedx_V;   //!
  TBranch        *b_shr_tkfit_2cm_dedx_U;   //!
  TBranch        *b_shr_tkfit_2cm_nhits_Y;   //!
  TBranch        *b_shr_tkfit_2cm_nhits_V;   //!
  TBranch        *b_shr_tkfit_2cm_nhits_U;   //!
  TBranch        *b_shr_tkfit_gap05_dedx_Y;   //!
  TBranch        *b_shr_tkfit_gap05_dedx_V;   //!
  TBranch        *b_shr_tkfit_gap05_dedx_U;   //!
  TBranch        *b_shr_tkfit_gap05_nhits_Y;   //!
  TBranch        *b_shr_tkfit_gap05_nhits_V;   //!
  TBranch        *b_shr_tkfit_gap05_nhits_U;   //!
  TBranch        *b_shr_tkfit_gap10_dedx_Y;   //!
  TBranch        *b_shr_tkfit_gap10_dedx_V;   //!
  TBranch        *b_shr_tkfit_gap10_dedx_U;   //!
  TBranch        *b_shr_tkfit_gap10_nhits_Y;   //!
  TBranch        *b_shr_tkfit_gap10_nhits_V;   //!
  TBranch        *b_shr_tkfit_gap10_nhits_U;   //!
  TBranch        *b_shr_chipr;   //!
  TBranch        *b_shr_chimu;   //!
  TBranch        *b_shr_bragg_p;   //!
  TBranch        *b_shr_bragg_mu;   //!
  TBranch        *b_shr_bragg_mip;   //!
  TBranch        *b_shr_bragg_kaon;   //!
  TBranch        *b_shr_bragg_pion;   //!
  TBranch        *b_tksh_distance;   //!
  TBranch        *b_tksh_angle;   //!
  TBranch        *b_shr_distance;   //!
  TBranch        *b_shr_score;   //!
  TBranch        *b_shr_bkt_pdg;   //!
  TBranch        *b_shr_bkt_purity;   //!
  TBranch        *b_shr_bkt_completeness;   //!
  TBranch        *b_shr_bkt_E;   //!
  TBranch        *b_trk_len;   //!
  TBranch        *b_trk_theta;   //!
  TBranch        *b_trk_phi;   //!
  TBranch        *b_trk_energy;   //!
  TBranch        *b_trk_energy_muon;   //!
  TBranch        *b_trk_energy_muon_mcs;   //!
  TBranch        *b_trk_energy_tot;   //!
  TBranch        *b_trk_energy_muon_tot;   //!
  TBranch        *b_trk_distance;   //!
  TBranch        *b_trk_score;   //!
  TBranch        *b_trk_bkt_pdg;   //!
  TBranch        *b_trk_bkt_purity;   //!
  TBranch        *b_trk_bkt_completeness;   //!
  TBranch        *b_trk_bkt_E;   //!
  TBranch        *b_trk_chipr_best;   //!
  TBranch        *b_trk_chipr_worst;   //!
  TBranch        *b_trk_chimu_best;   //!
  TBranch        *b_trk_chimu_worst;   //!
  TBranch        *b_trk_chipr;   //!
  TBranch        *b_trk_chimu;   //!
  TBranch        *b_trk_pida;   //!
  TBranch        *b_trk_bragg_p;   //!
  TBranch        *b_trk_bragg_mu;   //!
  TBranch        *b_trk_bragg_mip;   //!
  TBranch        *b_trk_bragg_kaon;   //!
  TBranch        *b_trk_bragg_pion;   //!
  TBranch        *b_trk_hits_max;   //!
  TBranch        *b_shr_hits_max;   //!
  TBranch        *b_all_shr_hits;   //!
  TBranch        *b_all_trk_hits;   //!
  TBranch        *b_all_shr_energies;   //!
  TBranch        *b_all_trk_energies;   //!
  TBranch        *b_trk_hits_2nd;   //!
  TBranch        *b_shr_hits_2nd;   //!
  TBranch        *b_trk_hits_3rd;   //!
  TBranch        *b_shr_hits_3rd;   //!
  TBranch        *b_trkshrhitdist0;   //!
  TBranch        *b_trkshrhitdist1;   //!
  TBranch        *b_trkshrhitdist2;   //!
  TBranch        *b_trk2shrhitdist0;   //!
  TBranch        *b_trk2shrhitdist1;   //!
  TBranch        *b_trk2shrhitdist2;   //!
  TBranch        *b_trk1trk2hitdist0;   //!
  TBranch        *b_trk1trk2hitdist1;   //!
  TBranch        *b_trk1trk2hitdist2;   //!
  TBranch        *b_total_hits_y;   //!
  TBranch        *b_extra_energy_y;   //!
  TBranch        *b_trk_energy_hits_tot;   //!
  TBranch        *b_subcluster;   //!
  TBranch        *b_shrsubclusters0;   //!
  TBranch        *b_shrsubclusters1;   //!
  TBranch        *b_shrsubclusters2;   //!
  TBranch        *b_shr_hits_tot;   //!
  TBranch        *b_shr_hits_y_tot;   //!
  TBranch        *b_shr_hits_u_tot;   //!
  TBranch        *b_shr_hits_v_tot;   //!
  TBranch        *b_trk_hits_tot;   //!
  TBranch        *b_trk_hits_y_tot;   //!
  TBranch        *b_trk_hits_u_tot;   //!
  TBranch        *b_trk_hits_v_tot;   //!
  TBranch        *b_elecclusters_U_charge;   //!
  TBranch        *b_elecclusters_V_charge;   //!
  TBranch        *b_elecclusters_Y_charge;   //!
  TBranch        *b_elecclusters_U_N;   //!
  TBranch        *b_elecclusters_V_N;   //!
  TBranch        *b_elecclusters_Y_N;   //!
  TBranch        *b_n_tracks_contained;   //!
  TBranch        *b_n_showers_contained;   //!
  TBranch        *b_matched_E;   //!
  TBranch        *b_hits_ratio;   //!
  TBranch        *b_contained_fraction;   //!
  TBranch        *b_sps_contained_fraction;   //!
  TBranch        *b_pt;   //!
  TBranch        *b_p;   //!
  TBranch        *b_pt_assume_muon;   //!
  TBranch        *b_p_assume_muon;   //!
  TBranch        *b_reco_e;   //!
  TBranch        *b_nblips_saved;   //!
  TBranch        *b_blip_x;   //!
  TBranch        *b_blip_y;   //!
  TBranch        *b_blip_z;   //!
  TBranch        *b_blip_size;   //!
  TBranch        *b_blip_energy;   //!
  TBranch        *b_blip_charge;   //!
  TBranch        *b_blip_nplanes;   //!
  TBranch        *b_blip_proxtrkdist;   //!
  TBranch        *b_blip_proxtrkid;   //!
  TBranch        *b_blip_touchtrk;   //!
  TBranch        *b_blip_touchtrkid;   //!
  TBranch        *b_blip_badwirefrac;   //!
  TBranch        *b_blip_pl0_nwires;   //!
  TBranch        *b_blip_pl1_nwires;   //!
  TBranch        *b_blip_pl2_nwires;   //!
  TBranch        *b_blip_pl0_bydeadwire;   //!
  TBranch        *b_blip_pl1_bydeadwire;   //!
  TBranch        *b_blip_pl2_bydeadwire;   //!
  TBranch        *b_blip_pl0_centerwire;   //!
  TBranch        *b_blip_pl1_centerwire;   //!
  TBranch        *b_blip_pl2_centerwire;   //!
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
  TBranch        *b_clung2mip;   //!
  TBranch        *b_clung2hip;   //!
  TBranch        *b_clung2shr;   //!
  TBranch        *b_clung2mcl;   //!
  TBranch        *b_clung2dfs;   //!
  TBranch        *b_pfng2semlabel;   //!
  TBranch        *b_pfng2mipfrac;   //!
  TBranch        *b_pfng2hipfrac;   //!
  TBranch        *b_pfng2shrfrac;   //!
  TBranch        *b_pfng2mclfrac;   //!
  TBranch        *b_pfng2dfsfrac;   //!
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
  TBranch        *b_shr_dedx_u_v;   //!
  TBranch        *b_shr_dedx_v_v;   //!
  TBranch        *b_shr_dedx_y_v;   //!
  TBranch        *b_shr_energy_u_v;   //!
  TBranch        *b_shr_energy_v_v;   //!
  TBranch        *b_shr_energy_y_v;   //!
  TBranch        *b_shr_pfp_id_v;   //!
  TBranch        *b_shr_start_x_v;   //!
  TBranch        *b_shr_start_y_v;   //!
  TBranch        *b_shr_start_z_v;   //!
  TBranch        *b_shr_dist_v;   //!
  TBranch        *b_shr_start_U_v;   //!
  TBranch        *b_shr_start_V_v;   //!
  TBranch        *b_shr_px_v;   //!
  TBranch        *b_shr_py_v;   //!
  TBranch        *b_shr_pz_v;   //!
  TBranch        *b_shr_openangle_v;   //!
  TBranch        *b_shr_theta_v;   //!
  TBranch        *b_shr_phi_v;   //!
  TBranch        *b_shr_pitch_u_v;   //!
  TBranch        *b_shr_pitch_v_v;   //!
  TBranch        *b_shr_pitch_y_v;   //!
  TBranch        *b_shr_tkfit_nhits_v;   //!
  TBranch        *b_shr_tkfit_start_x_v;   //!
  TBranch        *b_shr_tkfit_start_y_v;   //!
  TBranch        *b_shr_tkfit_start_z_v;   //!
  TBranch        *b_shr_tkfit_start_U_v;   //!
  TBranch        *b_shr_tkfit_start_V_v;   //!
  TBranch        *b_shr_tkfit_theta_v;   //!
  TBranch        *b_shr_tkfit_phi_v;   //!
  TBranch        *b_shr_tkfit_pitch_u_v;   //!
  TBranch        *b_shr_tkfit_pitch_v_v;   //!
  TBranch        *b_shr_tkfit_pitch_y_v;   //!
  TBranch        *b_shr_tkfit_dedx_u_v;   //!
  TBranch        *b_shr_tkfit_dedx_v_v;   //!
  TBranch        *b_shr_tkfit_dedx_y_v;   //!
  TBranch        *b_shr_tkfit_gap10_dedx_u_v;   //!
  TBranch        *b_shr_tkfit_gap10_dedx_v_v;   //!
  TBranch        *b_shr_tkfit_gap10_dedx_y_v;   //!
  TBranch        *b_shr_tkfit_dedx_nhits_u_v;   //!
  TBranch        *b_shr_tkfit_dedx_nhits_v_v;   //!
  TBranch        *b_shr_tkfit_dedx_nhits_y_v;   //!
  TBranch        *b_shr_llr_pid_u_v;   //!
  TBranch        *b_shr_llr_pid_v_v;   //!
  TBranch        *b_shr_llr_pid_y_v;   //!
  TBranch        *b_shr_llr_pid_v;   //!
  TBranch        *b_shr_llr_pid_score_v;   //!
  TBranch        *b_shr_moliere_avg_v;   //!
  TBranch        *b_shr_moliere_rms_v;   //!
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
  TBranch        *b_bdt_nuNCpi0;   //!
  TBranch        *b_bdt_numuCCpi0;   //!
  TBranch        *b_bdt_numuCC;   //!
  TBranch        *b_bdt_ext;   //!
  TBranch        *b_bdt_cosmic;   //!
  TBranch        *b_bdt_global;   //!
  TBranch        *b_bdt_pi0_np;   //!
  TBranch        *b_bdt_nonpi0_np;   //!
  TBranch        *b_bdt_bkg_0p;   //!
  TBranch        *b_anglediff_Y;   //!
  TBranch        *b_anglediff_V;   //!
  TBranch        *b_anglediff_U;   //!
  TBranch        *b_trkpid;   //!

   mcc9_10_true_neutrino_selection(TString Label = "", TString Sample = "", TTree *tree=0);
   virtual ~mcc9_10_true_neutrino_selection();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

};

#endif

#ifdef mcc9_10_true_neutrino_selection_cxx
mcc9_10_true_neutrino_selection::mcc9_10_true_neutrino_selection(TString Label, TString Sample, TTree *tree) : fChain(0) {

	// if parameter tree is not specified (or zero), connect the file
	// used to generate this class and read the Tree.

	fLabel = Label;
	fSample = Sample;

	if (tree == 0) {

		TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(fSample);
      
		if (!f || !f->IsOpen()) {

			f = new TFile(fSample);

		}

		TDirectory * dir = (TDirectory*)f->Get(fSample+":/nuselection");
      		dir->GetObject("NeutrinoSelectionFilter",tree);

	}

	Init(tree);

}

mcc9_10_true_neutrino_selection::~mcc9_10_true_neutrino_selection()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t mcc9_10_true_neutrino_selection::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t mcc9_10_true_neutrino_selection::LoadTree(Long64_t entry)
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

void mcc9_10_true_neutrino_selection::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   all_shr_hits = 0;
   all_trk_hits = 0;
   all_shr_energies = 0;
   all_trk_energies = 0;
   blip_x = 0;
   blip_y = 0;
   blip_z = 0;
   blip_size = 0;
   blip_energy = 0;
   blip_charge = 0;
   blip_nplanes = 0;
   blip_proxtrkdist = 0;
   blip_proxtrkid = 0;
   blip_touchtrk = 0;
   blip_touchtrkid = 0;
   blip_badwirefrac = 0;
   blip_pl0_nwires = 0;
   blip_pl1_nwires = 0;
   blip_pl2_nwires = 0;
   blip_pl0_bydeadwire = 0;
   blip_pl1_bydeadwire = 0;
   blip_pl2_bydeadwire = 0;
   blip_pl0_centerwire = 0;
   blip_pl1_centerwire = 0;
   blip_pl2_centerwire = 0;
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
   PCAWin_1Cr_5cm = 0;
   PCAWin_2Cr_5cm = 0;
   PCAWin_3Cr_5cm = 0;
   PCAWin_dist_5cm = 0;
   PCAWin_npts_5cm = 0;
   PCAWin_1Cr_2_5cm = 0;
   PCAWin_2Cr_2_5cm = 0;
   PCAWin_3Cr_2_5cm = 0;
   PCAWin_dist_2_5cm = 0;
   PCAWin_npts_2_5cm = 0;
   pfng2semlabel = 0;
   pfng2mipfrac = 0;
   pfng2hipfrac = 0;
   pfng2shrfrac = 0;
   pfng2mclfrac = 0;
   pfng2dfsfrac = 0;
   shr_dedx_u_v = 0;
   shr_dedx_v_v = 0;
   shr_dedx_y_v = 0;
   shr_energy_u_v = 0;
   shr_energy_v_v = 0;
   shr_energy_y_v = 0;
   shr_pfp_id_v = 0;
   shr_start_x_v = 0;
   shr_start_y_v = 0;
   shr_start_z_v = 0;
   shr_dist_v = 0;
   shr_start_U_v = 0;
   shr_start_V_v = 0;
   shr_px_v = 0;
   shr_py_v = 0;
   shr_pz_v = 0;
   shr_openangle_v = 0;
   shr_theta_v = 0;
   shr_phi_v = 0;
   shr_pitch_u_v = 0;
   shr_pitch_v_v = 0;
   shr_pitch_y_v = 0;
   shr_tkfit_nhits_v = 0;
   shr_tkfit_start_x_v = 0;
   shr_tkfit_start_y_v = 0;
   shr_tkfit_start_z_v = 0;
   shr_tkfit_start_U_v = 0;
   shr_tkfit_start_V_v = 0;
   shr_tkfit_theta_v = 0;
   shr_tkfit_phi_v = 0;
   shr_tkfit_pitch_u_v = 0;
   shr_tkfit_pitch_v_v = 0;
   shr_tkfit_pitch_y_v = 0;
   shr_tkfit_dedx_u_v = 0;
   shr_tkfit_dedx_v_v = 0;
   shr_tkfit_dedx_y_v = 0;
   shr_tkfit_gap10_dedx_u_v = 0;
   shr_tkfit_gap10_dedx_v_v = 0;
   shr_tkfit_gap10_dedx_y_v = 0;
   shr_tkfit_dedx_nhits_u_v = 0;
   shr_tkfit_dedx_nhits_v_v = 0;
   shr_tkfit_dedx_nhits_y_v = 0;
   shr_llr_pid_u_v = 0;
   shr_llr_pid_v_v = 0;
   shr_llr_pid_y_v = 0;
   shr_llr_pid_v = 0;
   shr_llr_pid_score_v = 0;
   shr_moliere_avg_v = 0;
   shr_moliere_rms_v = 0;
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

   // Set branch addresses and branch pointers

   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   /*fChain->SetMakeClass(1);*/

   fChain->SetBranchAddress("selected", &selected, &b_selected);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("sub", &sub, &b_sub);
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
   fChain->SetBranchAddress("true_nu_vtx_t", &true_nu_vtx_t, &b_true_nu_vtx_t);
   fChain->SetBranchAddress("true_nu_vtx_x", &true_nu_vtx_x, &b_true_nu_vtx_x);
   fChain->SetBranchAddress("true_nu_vtx_y", &true_nu_vtx_y, &b_true_nu_vtx_y);
   fChain->SetBranchAddress("true_nu_vtx_z", &true_nu_vtx_z, &b_true_nu_vtx_z);
   fChain->SetBranchAddress("mc_pdg", &mc_pdg, &b_mc_pdg);
   fChain->SetBranchAddress("mc_E", &mc_E, &b_mc_E);
   fChain->SetBranchAddress("mc_vx", &mc_vx, &b_mc_vx);
   fChain->SetBranchAddress("mc_vy", &mc_vy, &b_mc_vy);
   fChain->SetBranchAddress("mc_vz", &mc_vz, &b_mc_vz);
   fChain->SetBranchAddress("mc_endx", &mc_endx, &b_mc_endx);
   fChain->SetBranchAddress("mc_endy", &mc_endy, &b_mc_endy);
   fChain->SetBranchAddress("mc_endz", &mc_endz, &b_mc_endz);
   fChain->SetBranchAddress("mc_px", &mc_px, &b_mc_px);
   fChain->SetBranchAddress("mc_py", &mc_py, &b_mc_py);
   fChain->SetBranchAddress("mc_pz", &mc_pz, &b_mc_pz);
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

   Notify();

}

Bool_t mcc9_10_true_neutrino_selection::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void mcc9_10_true_neutrino_selection::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t mcc9_10_true_neutrino_selection::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef mcc9_10_true_neutrino_selection_cxx
