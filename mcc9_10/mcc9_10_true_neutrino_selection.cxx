#define mcc9_10_true_neutrino_selection_cxx
#include "mcc9_10_true_neutrino_selection.h"
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TString.h>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "../../../generators/constants.h"
#include "../../../generators/Tools.h"

using namespace std;
using namespace constants;

//--------------------//

void mcc9_10_true_neutrino_selection::Loop() {

	//--------------------//

	TH1D::SetDefaultSumw2();

	//--------------------//

	// Output Files

	TString FileName = preselection_file_path + "/PreTruthSelection_"+fLabel+".root";
	TFile* OutputFile = new TFile(FileName,"recreate");
	std::cout << std::endl << "File " << FileName << " to be created"<< std::endl << std::endl;

	//--------------------//

	if (fChain == 0) return;
	Long64_t nentries = fChain->GetEntriesFast();
	Long64_t nbytes = 0, nb = 0;

	//--------------------//

	// TTree declaration

	TTree* tree = new TTree("myPreTruthSelection","myPreTruthSelection");

	//--------------------//

	double Weight;
	double T2KWeight;
	double ROOTinoWeight;
	double POTWeight;

	int Run;
	int SubRun;
	int Event;
	TString run_period;

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

	//--------------------//	

	std::vector<unsigned short> fluxes;
	std::vector<unsigned short> reinteractions;

	//--------------------//

	double True_Ev;
	double True_Vx;
	double True_Vy;
	double True_Vz;

	int signal;
	int NCcoh;
	int NCres;
	
	//--------------------//

	std::vector<int> pi0_MCParticle_Mode;
	std::vector<double> pi0_MCParticle_Mom;
	std::vector<double> pi0_MCParticle_Phi;
	std::vector<double> pi0_MCParticle_CosTheta;
	std::vector<double> pi0_MCParticle_StartX;
	std::vector<double> pi0_MCParticle_StartY;
	std::vector<double> pi0_MCParticle_StartZ;
	std::vector<int> pi0_MCParticle_StartContainment;
	std::vector<double> pi0_MCParticle_EndX;
	std::vector<double> pi0_MCParticle_EndY;
	std::vector<double> pi0_MCParticle_EndZ;
	std::vector<int> pi0_MCParticle_EndContainment;
	std::vector<int> pi0_MCParticle_Pdg;

	//--------------------//

	tree->Branch("Weight",&Weight);
	tree->Branch("T2KWeight",&T2KWeight);
	tree->Branch("ROOTinoWeight",&ROOTinoWeight);	
	tree->Branch("POTWeight",&POTWeight);	

	tree->Branch("Run",&Run);
	tree->Branch("SubRun",&SubRun);
	tree->Branch("Event",&Event);	
	tree->Branch("run_period",&run_period);
	
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

	//--------------------//

	tree->Branch("True_Ev",&True_Ev);
	tree->Branch("True_Vx",&True_Vx);
	tree->Branch("True_Vy",&True_Vy);
	tree->Branch("True_Vz",&True_Vz);

	tree->Branch("signal",&signal);
	tree->Branch("NCcoh",&NCcoh);
	tree->Branch("NCres",&NCres);
	
	//--------------------//
		
	tree->Branch("pi0_MCParticle_Mode",&pi0_MCParticle_Mode);
	tree->Branch("pi0_MCParticle_Mom",&pi0_MCParticle_Mom);
	tree->Branch("pi0_MCParticle_Phi",&pi0_MCParticle_Phi);
	tree->Branch("pi0_MCParticle_CosTheta",&pi0_MCParticle_CosTheta);
	tree->Branch("pi0_MCParticle_StartX",&pi0_MCParticle_StartX);
	tree->Branch("pi0_MCParticle_StartY",&pi0_MCParticle_StartY);
	tree->Branch("pi0_MCParticle_StartZ",&pi0_MCParticle_StartZ);
	tree->Branch("pi0_MCParticle_StartContainment",&pi0_MCParticle_StartContainment);
	tree->Branch("pi0_MCParticle_EndX",&pi0_MCParticle_EndX);
	tree->Branch("pi0_MCParticle_EndY",&pi0_MCParticle_EndY);
	tree->Branch("pi0_MCParticle_EndZ",&pi0_MCParticle_EndZ);
	tree->Branch("pi0_MCParticle_EndContainment",&pi0_MCParticle_EndContainment);
	tree->Branch("pi0_MCParticle_Pdg",&pi0_MCParticle_Pdg);
		
	//--------------------//

	// Counters

	int TotalCounter = 0;

	// POT Counting

	double POTCount = -99.;

	if (string(fLabel).find("Overlay") != std::string::npos) {

		TString PathToPOTFile = preselection_file_path + "/PreSelection_"+fLabel+"_POT.root";

		TFile* POTFile = TFile::Open(PathToPOTFile,"readonly");
		TH1D* POTCountHist = (TH1D*)(POTFile->Get("POTCountHist"));
		POTCount = POTCountHist->GetBinContent(1);
		POTFile->Close();
	
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

	//--------------------//

	Tools tools;

	//--------------------//

	for (Long64_t jentry=0; jentry<nentries;jentry++) {

		//--------------------//

		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
      	nb = fChain->GetEntry(jentry);   nbytes += nb;

		TotalCounter++;

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

		pi0_MCParticle_Mode.clear();
		pi0_MCParticle_Mom.clear();
		pi0_MCParticle_Phi.clear();
		pi0_MCParticle_CosTheta.clear();
		pi0_MCParticle_StartX.clear();
		pi0_MCParticle_StartY.clear();
		pi0_MCParticle_StartZ.clear();
		pi0_MCParticle_StartContainment.clear();
		pi0_MCParticle_EndX.clear();
		pi0_MCParticle_EndY.clear();
		pi0_MCParticle_EndZ.clear();
		pi0_MCParticle_EndContainment.clear();
		pi0_MCParticle_Pdg.clear();		

		//--------------------//

		Run = run;
		SubRun = sub;
		Event = evt;		

		True_Ev = nu_e;
		True_Vx = true_nu_vtx_x;
		True_Vy = true_nu_vtx_y;
		True_Vz = true_nu_vtx_z;

		TVector3 TrueNu_Vertex(True_Vx,True_Vy,True_Vz);
		bool TrueNu_Vertex_Containment = tools.inFVVector(TrueNu_Vertex);
		if (TrueNu_Vertex_Containment == 0) { continue; }

		//--------------------//

		int NMCParticles = mc_pdg->size();
		
		//--------------------//		

		int fsignal = 0;
		int fNCcoh = 0;
		int fNCres = 0;

		int proton_tagging = 0, ChargedPionTagging = 0, pi0_tagging = 0;
		int heavy_meason_tagging = 0, SigmaTagging = 0, LambdaTagging = 0;
		int PhotonTagging = 0, LeptonTagging = 0 , cluster_tagging = 0;
		int neutron_tagging = 0;

		std::vector<int> Pi0ID; Pi0ID.clear();				

		// Loop over the MCParticles and determine the populations

		for (int i_mc = 0; i_mc < NMCParticles; i_mc++) {

			// MC truth information for the final-state primary particles

			// NC events, only muon neutrinos

			if (ccnc == 1  && nu_pdg == NuMuPdg) {

				TVector3 MCParticle(mc_px->at(i_mc),mc_py->at(i_mc),mc_pz->at(i_mc));
				double MCParticleMomentum = MCParticle.Mag();
				int MCParticlePdg = mc_pdg->at(i_mc);

				if (MCParticlePdg == ProtonPdg ) {

					double E = TMath::Sqrt( TMath::Power(MCParticleMomentum,2.) + TMath::Power(ProtonMass_GeV,2.) );
					double ke = E - ProtonMass_GeV;

					// proton kinetic energy threshold
					if ( ke > proton_ke_thres ) {

						proton_tagging ++;

					}

				}

				else if ( fabs(MCParticlePdg) == AbsChargedPionPdg )  {

					ChargedPionTagging ++;

				}

				else if ( fabs(MCParticlePdg) == NeutralPionPdg)  {

					pi0_tagging ++;
					Pi0ID.push_back(i_mc);

				}

				else if ( fabs(MCParticlePdg) == KaonPdg || fabs(MCParticlePdg) == NeutralKaonPdg 
				    || fabs(MCParticlePdg) == NeutralKaonLongPdg || fabs(MCParticlePdg) == NeutralKaonShortPdg 
					|| fabs(MCParticlePdg) == rho_pdg || fabs(MCParticlePdg) == charged_rho_pdg 
					|| fabs(MCParticlePdg) == d0_pdg || fabs(MCParticlePdg) == dp_pdg || fabs(MCParticlePdg) == dm_pdg
					|| fabs(MCParticlePdg) == eta_pdg || fabs(MCParticlePdg) == omega_pdg  
					|| fabs(MCParticlePdg) == xi_pdg || fabs(MCParticlePdg) == xi0_pdg)  {

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
					   || fabs(MCParticlePdg) == ArgonPdg || fabs(MCParticlePdg) == neutron_pair 
					   || fabs(MCParticlePdg) == proton_pair) {

					// ignore 

				}

				else if ( fabs(MCParticlePdg) == NuMuPdg || fabs(MCParticlePdg) == nue_pdg) {

					// ignore since neutral current numu interactions
					if (fabs(MCParticlePdg) == nue_pdg)cout << "MCParticlePdg = " << MCParticlePdg << endl;

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

		//--------------------//

		// NCCOH-like Signal events	

		if (
			pi0_tagging == 1 && proton_tagging == 0 && ChargedPionTagging == 0 && 
		    heavy_meason_tagging == 0 && LambdaTagging == 0 && SigmaTagging == 0 &&
		    PhotonTagging == 0 && LeptonTagging == 0 && cluster_tagging == 0 && neutron_tagging == 0
		) {
			
			fsignal = 1; 
			
			//--------------------//

			double pi0_MCParticlePx = mc_px->at(Pi0ID.at(0));
			double pi0_MCParticlePy = mc_py->at(Pi0ID.at(0));
			double pi0_MCParticlePz = mc_pz->at(Pi0ID.at(0));
			
			double pi0_MCParticleStartX = mc_vx->at(Pi0ID.at(0));
			double pi0_MCParticleStartY = mc_vy->at(Pi0ID.at(0));
			double pi0_MCParticleStartZ = mc_vz->at(Pi0ID.at(0));

			double pi0_MCParticleEndX = mc_endx->at(Pi0ID.at(0));
			double pi0_MCParticleEndY = mc_endy->at(Pi0ID.at(0));
			double pi0_MCParticleEndZ = mc_endz->at(Pi0ID.at(0));	

			TVector3 pi0_TVector3TrueStart(pi0_MCParticleStartX,pi0_MCParticleStartY,pi0_MCParticleStartZ);
			TVector3 pi0_TVector3TrueEnd(pi0_MCParticleEndX,pi0_MCParticleEndY,pi0_MCParticleEndZ);
			TVector3 pi0_TVector3True(pi0_MCParticlePx,pi0_MCParticlePy,pi0_MCParticlePz);

			bool pi0_TrueStartContainment = tools.inFVVector(pi0_TVector3TrueStart);
			bool pi0_TrueEndContainment = tools.inFVVector(pi0_TVector3TrueEnd);

			double pi0_TrueTheta = pi0_TVector3True.Theta();
			double pi0_TrueTheta_Deg = pi0_TrueTheta * 180./TMath::Pi();
			double pi0_TruePhi = pi0_TVector3True.Phi();
			double pi0_TruePhi_Deg = pi0_TruePhi * 180./TMath::Pi();
			double pi0_TrueCosTheta = pi0_TVector3True.CosTheta();
			double pi0_TrueMomentum_GeV = pi0_TVector3True.Mag(); // GeV
			double pi0_TrueE_GeV = TMath::Sqrt( TMath::Power(pi0_TrueMomentum_GeV,2.) + TMath::Power(MuonMass_GeV,2.) ); // GeV		
			
			if (pi0_TrueCosTheta < pi0_costheta_thres) { continue; }
			
			pi0_MCParticle_Mode.push_back(interaction);
			pi0_MCParticle_Mom.push_back(pi0_TrueMomentum_GeV);
			pi0_MCParticle_Phi.push_back(pi0_TruePhi_Deg);
			pi0_MCParticle_CosTheta.push_back(pi0_TrueCosTheta);
			pi0_MCParticle_StartX.push_back(pi0_TVector3TrueStart.X());
			pi0_MCParticle_StartY.push_back(pi0_TVector3TrueStart.Y());
			pi0_MCParticle_StartZ.push_back(pi0_TVector3TrueStart.Z());
			pi0_MCParticle_StartContainment.push_back(pi0_TrueStartContainment);
			pi0_MCParticle_EndX.push_back(pi0_TVector3TrueEnd.X());
			pi0_MCParticle_EndY.push_back(pi0_TVector3TrueEnd.Y());
			pi0_MCParticle_EndZ.push_back(pi0_TVector3TrueEnd.Z());
			pi0_MCParticle_EndContainment.push_back(pi0_TrueEndContainment);
			pi0_MCParticle_Pdg.push_back(mc_pdg->at(Pi0ID.at(0)));						
			
		}

		//--------------------//
		
		signal = fsignal;				

		// Storing only true signal events

		if (signal == 0) { continue; }
		tree->Fill();

	}

	//--------------------//

	OutputFile->cd();
	OutputFile->Write();
	OutputFile->Close();
	std::cout << std::endl << "File " << FileName << " has been created"<< std::endl << std::endl;

	//--------------------//

} // End of the program
