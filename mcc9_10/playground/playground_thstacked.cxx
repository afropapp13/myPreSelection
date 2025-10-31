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

#include "../../../../generators/constants.h"
#include "../../../../generators/helper_functions.cxx"

using namespace constants;

void playground_thstacked() {

	//------------------------------//

	TH1D::SetDefaultSumw2();
	TH2D::SetDefaultSumw2();
	gStyle->SetOptStat(0);

	const int FontStyle = 132;
	const double TextSize = 0.04;

	TString run = "Combined";
	//TString run = "Run4b";	

	//------------------------------//
	
	TString ttree_name = "myPreSelection";

	//mc weight
	TString MCWeight = "POTWeight * T2KWeight * ROOTinoWeight * Weight * ( (Weight > 0. && Weight < 30. && T2KWeight > 0. && T2KWeight < 30.)? T2KWeight:0.)";	

	//------------------------------//

	// mc
	vector<TString> file_names;
	vector<TString> file_labels;
	file_names.push_back("/exp/uboone/data/users/apapadop/ncpi0//PreSelection_mcc9_10_NCpi0Overlay9_"+run+"_unified.root"); file_labels.push_back("new");

	int nfiles = file_names.size();

	vector<TFile*> tfile; tfile.resize(nfiles);
	vector<TTree*> ttree; ttree.resize(nfiles);

	TString cuts = "(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta >= 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && two_shower_start_dist < 50 && reco_shower_opening_angle < 90 && wc_numu_score < 0.1 && wc_numu_score > -2. && dl_nTracks == 0 && (wc_shw_sp_n_20mev_showers == 2 || wc_shw_sp_n_20mev_showers == 3 && wc_shw_sp_n_br4_showers < 8) && (nspacepoints > 100 && nspacepoints < 400) && n_blip_pd_vtx_25cm_g1_anticone < 2 && gl_vertex_contained == 1 && truth_contains_neutron == 0 && truth_contains_proton == 0)";		

	//------------------------------//

	// plots to loop over	

	vector<TString> plot_names; vector<double> min; vector<double> max; vector<int> nbins; vector<TString> cut;  vector<TString> cut_name;


	//plot_names.push_back("reco_pi0_costheta"); min.push_back(0.85); max.push_back(1); nbins.push_back(10); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");	
	//plot_names.push_back("truth_contains_proton"); min.push_back(-0.5); max.push_back(1.5); nbins.push_back(2); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");	

	plot_names.push_back("Blip_true_pdg"); min.push_back(0.); max.push_back(15.); nbins.push_back(15); cut.push_back(cuts + " && Blip_true_g4id > 0"); cut_name.push_back("no_wc_npiontracks");	
	//plot_names.push_back("wc_n_veto_nonprim_score"); min.push_back(-5.); max.push_back(5.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");
	//plot_names.push_back("wc_n_veto_all_score"); min.push_back(-5.); max.push_back(5.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");	
	//plot_names.push_back("wc_n_veto_score"); min.push_back(-5.); max.push_back(5.); nbins.push_back(20); cut.push_back(cuts); cut_name.push_back("no_wc_npiontracks");		

	int nplots = plot_names.size();

	//------------------------------//

	// vector of vectors

	vector< vector<THStack*> > stack; stack.resize(nfiles);
	vector< vector<TLegend*> > leg; leg.resize(nfiles);
	vector< vector<TCanvas*> > can; can.resize(nfiles);
	vector< vector< vector<TH1D*> > > h; h.resize(nfiles);

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
		ttree.at(ifile) = (TTree*)(tfile.at(ifile)->Get(ttree_name));	

		stack.at(ifile).resize(nplots);
		can.at(ifile).resize(nplots);		
		leg.at(ifile).resize(nplots);
		h.at(ifile).resize(nplots);
		
		//loop over the plots
		for (int iplot = 0; iplot < nplots; iplot++) {

			TString stack_name = "stack_" + plot_names.at(iplot) + "_" + file_labels.at(ifile);
			stack.at(ifile).at(iplot) = new THStack(stack_name,stack_name);

			TString canvas_name = "canvas_" + plot_names.at(iplot) + "_" + file_labels.at(ifile);
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
			
			h.at(ifile).at(iplot).resize(ntopo);				
			
			// loop over the topo categories
			for (int itopo = 0; itopo < ntopo; itopo++) {	

				TString hname = topo.at(itopo) + "_" + plot_names.at(iplot) + "_" + file_labels.at(ifile);
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

			// pot
			stack.at(ifile).at(iplot)->GetHistogram()->GetYaxis()->SetTitle( run + " events [" + pot_sci_notation(run + "_unified", 2) + " POT]");			

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

			leg.at(ifile).at(iplot)->Draw();		
			can.at(ifile).at(iplot)->SaveAs(plot_path + canvas_name + "_" + cut_name.at(iplot) + "_" + run + ".pdf");
		
		} // end of the loop over the plots
	
	} // end of the loop over the files

	//------------------------------//

} // end of the program