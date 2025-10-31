#include <TFile.h>
#include <TTree.h>
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

void efficiency() {

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

	//mc weight
	TString MCWeight = "POTWeight * T2KWeight * ROOTinoWeight * Weight * ( (Weight > 0. && Weight < 30. && T2KWeight > 0. && T2KWeight < 30.)? T2KWeight:0.)";	

	//------------------------------//

	// mc
	vector<TString> file_names;
	file_names.push_back("/exp/uboone/data/users/apapadop/ncpi0/PreSelection_mcc9_10_NCpi0Overlay9_"+run+"_unified_10GeV.root");

	vector<TString> true_file_names;
	true_file_names.push_back("/exp/uboone/data/users/apapadop/ncpi0/PreTruthSelection_mcc9_10_NCpi0Overlay9_"+run+"_unified_10GeV.root");

	int nfiles = file_names.size();

	vector<TFile*> tfile; tfile.resize(nfiles);
	vector<TTree*> ttree; ttree.resize(nfiles);	
	
	vector<TFile*> true_tfile; true_tfile.resize(nfiles);		
	vector<TTree*> true_ttree; true_ttree.resize(nfiles);	

	//TString cuts = "(signal == 1 && wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta >= 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && two_shower_start_dist < 50 && reco_shower_opening_angle < 90 && wc_numu_score < 0.1 && wc_numu_score > -2. && dl_nTracks == 0 && (wc_shw_sp_n_20mev_showers == 2 || wc_shw_sp_n_20mev_showers == 3 && wc_shw_sp_n_br4_showers < 8) && (nspacepoints > 100 && nspacepoints < 400) )";	
	TString cuts = "(signal == 1)";		

	//------------------------------//

	// plots to loop over (reco events)

	vector<TString> plot_names; vector<TString> true_plot_names; vector<double> min; vector<double> max; vector<int> nbins; vector<TString> cut;

	plot_names.push_back("proton_truthMatch_ke"); true_plot_names.push_back("true_proton_ke"); min.push_back(0.); max.push_back(0.6); nbins.push_back(24); cut.push_back(cuts);
	plot_names.push_back("neutron_truthMatch_ke"); true_plot_names.push_back("true_neutron_ke"); min.push_back(0.); max.push_back(0.7); nbins.push_back(28); cut.push_back(cuts);	

	int nplots = plot_names.size();

	//------------------------------//

	vector< vector<TCanvas*> > can; can.resize(nfiles);
	vector< vector<TH1D*> > h; h.resize(nfiles);
	vector< vector<TH1D*> > true_h; true_h.resize(nfiles);	

	//------------------------------//
		
	// loop over the files 
	for (int ifile = 0; ifile < nfiles; ifile++) {

		tfile.at(ifile) = new TFile(file_names.at(ifile),"readonly");			
		true_tfile.at(ifile) = new TFile(true_file_names.at(ifile),"readonly");			

		ttree.at(ifile) = (TTree*)(tfile.at(ifile)->Get(ttree_name));	
		true_ttree.at(ifile) = (TTree*)(true_tfile.at(ifile)->Get(true_ttree_name));	
		
		true_h.at(ifile).resize(nplots);
		h.at(ifile).resize(nplots);	
		can.at(ifile).resize(nplots);

		//loop over the plots
		for (int iplot = 0; iplot < nplots; iplot++) {

			TString true_hname = "true_" + run + "_" + true_plot_names.at(iplot);
			true_h.at(ifile).at(iplot) = new TH1D(true_hname,";"+plot_names.at(iplot) + " [GeV]", nbins.at(iplot), min.at(iplot), max.at(iplot));	
			true_ttree.at(ifile)->Draw(true_plot_names.at(iplot) + ">>" + true_hname,"(1>0)*" + MCWeight,"goff");	

			TString hname = "reco_" + run + "_" + plot_names.at(iplot);
			h.at(ifile).at(iplot) = new TH1D(hname,";"+plot_names.at(iplot) + " [GeV]", nbins.at(iplot), min.at(iplot), max.at(iplot) );
			ttree.at(ifile)->Draw(plot_names.at(iplot) + ">>" + hname,"(" + cut.at(iplot) + ")*" + MCWeight,"goff");	
			
			TH1D* eff_h = (TH1D*)(h.at(ifile).at(iplot)->Clone());
			eff_h->Divide(true_h.at(ifile).at(iplot));
			eff_h->Scale(100.);

			TString canvas_name = "eff_canvas_" + plot_names.at(iplot);
			can.at(ifile).at(iplot) = new TCanvas(canvas_name,canvas_name,205,34,1024,768);		
			can.at(ifile).at(iplot)->cd();
			can.at(ifile).at(iplot)->SetTopMargin(0.18);
			can.at(ifile).at(iplot)->SetLeftMargin(0.13);
			can.at(ifile).at(iplot)->SetBottomMargin(0.1);		
			can.at(ifile).at(iplot)->Draw();					

			// ----------------- //				

			eff_h->GetXaxis()->SetTitleFont(FontStyle);
			eff_h->GetXaxis()->SetTitleSize(TextSize);	
			eff_h->GetXaxis()->CenterTitle();
			eff_h->GetXaxis()->SetLabelFont(FontStyle);
			eff_h->GetXaxis()->SetLabelSize(TextSize);
			eff_h->GetXaxis()->SetNdivisions(8);
			eff_h->GetXaxis()->SetLabelOffset(0.01);									
			
			eff_h->GetYaxis()->SetTitleFont(FontStyle);
			eff_h->GetYaxis()->SetTitleSize(TextSize);	
			eff_h->GetYaxis()->CenterTitle();
			eff_h->GetYaxis()->SetLabelFont(FontStyle);
			eff_h->GetYaxis()->SetLabelSize(TextSize);	
			eff_h->GetYaxis()->SetNdivisions(8);	
			eff_h->GetYaxis()->SetLabelOffset(0.01);	
			eff_h->GetYaxis()->SetTitle("Efficiency (%)");			

			eff_h->SetLineColor(kBlack);
			eff_h->SetMarkerStyle(20);
			eff_h->SetMarkerColor(kBlack);
			eff_h->SetMarkerSize(1.5);												

			eff_h->Draw("same ex0");
			can.at(ifile).at(iplot)->SaveAs(plot_path + canvas_name + "_" + run + ".pdf");
		
		} // end of the loop over the plots
	
	} // end of the loop over the files

	//------------------------------//

} // end of the program