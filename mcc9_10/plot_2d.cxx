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

void plot_2d() {

	//------------------------------//

	TH1D::SetDefaultSumw2();
	TH2D::SetDefaultSumw2();
	gStyle->SetOptStat(0);
	gStyle->SetPalette(kSunset);    // warm reds and oranges	

	const int FontStyle = 132;
	const double TextSize = 0.04;

	TString run = "Run4b";
	//TString run = "Combined";	

	//------------------------------//
	
	TString ttree_name = "myPreSelection";

	//mc weight
	// TString MCWeight = "POTWeight * T2KWeight * ROOTinoWeight * Weight * ( (Weight > 0. && Weight < 30. && T2KWeight > 0. && T2KWeight < 30.)? T2KWeight:0.)";	
	TString MCWeight = "1.";		

	//------------------------------//

	// mc
	vector<TString> file_names;
	file_names.push_back("/exp/uboone/data/users/apapadop/ncpi0/PreSelection_mcc9_10_NCpi0Overlay9_"+run+"_unified.root");
	//file_names.push_back("/exp/uboone/data/users/apapadop/ncpi0/PreSelection_mcc9_10_ExtBNB9_"+run+"_unified.root");	

	int nfiles = file_names.size();

	vector<TFile*> tfile; tfile.resize(nfiles);
	vector<TTree*> ttree; ttree.resize(nfiles);	

	TString cuts = "(wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta >= 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && two_shower_start_dist < 50 && reco_shower_opening_angle < 90 && wc_numu_score < 0.1 && wc_numu_score > -2. && dl_nTracks == 0 && (wc_shw_sp_n_20mev_showers == 2 || wc_shw_sp_n_20mev_showers == 3 && wc_shw_sp_n_br4_showers < 8) && (nspacepoints > 100 && nspacepoints < 400) && n_blip_pd_vtx_25cm_g1_anticone < 2 && gl_vertex_contained == 1)";

	//------------------------------//

	vector<TString> cut;	
	vector<TString> x_axis; vector<double> x_min; vector<double> x_max; vector<int> x_nbins;
	vector<TString> y_axis; vector<double> y_min; vector<double> y_max; vector<int> y_nbins;	

	// cut.push_back(cuts);	
	// x_axis.push_back("true_sum_neutron_ke"); x_min.push_back(0.); x_max.push_back(0.1); x_nbins.push_back(10);
	// y_axis.push_back("n_blip_pd_vtx_100cm_g1_anticone"); y_min.push_back(-0.5); y_max.push_back(9.5); y_nbins.push_back(10);	

	// cut.push_back(cuts);	
	// x_axis.push_back("sum_reco_g1_blip_e_25cm"); x_min.push_back(0.); x_max.push_back(30); x_nbins.push_back(15);
	// y_axis.push_back("n_blip_pd_vtx_25cm_g1_anticone"); y_min.push_back(-0.5); y_max.push_back(2.5); y_nbins.push_back(3);	
	
	// cut.push_back(cuts);	
	// x_axis.push_back("sum_reco_g1_blip_e_50cm"); x_min.push_back(0.); x_max.push_back(30); x_nbins.push_back(15);
	// y_axis.push_back("n_blip_pd_vtx_50cm_g1_anticone"); y_min.push_back(-0.5); y_max.push_back(9.5); y_nbins.push_back(10);	
	
	// cut.push_back(cuts);	
	// x_axis.push_back("sum_reco_g1_blip_e_100cm"); x_min.push_back(0.); x_max.push_back(40); x_nbins.push_back(20);
	// y_axis.push_back("n_blip_pd_vtx_100cm_g1_anticone"); y_min.push_back(-0.5); y_max.push_back(14.5); y_nbins.push_back(15);
	
	// cut.push_back(cuts);	
	// x_axis.push_back("sum_reco_g2_blip_e_100cm"); x_min.push_back(0.); x_max.push_back(40); x_nbins.push_back(20);
	// y_axis.push_back("n_blip_pd_vtx_100cm_g2_anticone"); y_min.push_back(-0.5); y_max.push_back(14.5); y_nbins.push_back(15);	

	// cut.push_back(cuts);	
	// x_axis.push_back("truth_contains_neutron"); x_min.push_back(-0.5); x_max.push_back(1.5); x_nbins.push_back(2);
	// y_axis.push_back("reco_contains_neutron"); y_min.push_back(-0.5); y_max.push_back(1.5); y_nbins.push_back(2);	

	// cut.push_back(cuts);	
	// x_axis.push_back("truth_contains_proton"); x_min.push_back(-0.5); x_max.push_back(1.5); x_nbins.push_back(2);
	// y_axis.push_back("reco_contains_proton"); y_min.push_back(-0.5); y_max.push_back(1.5); y_nbins.push_back(2);		

	cut.push_back(cuts);	
	x_axis.push_back("truth_contains_proton_or_neutron"); x_min.push_back(-0.5); x_max.push_back(1.5); x_nbins.push_back(2);
	y_axis.push_back("reco_contains_proton_or_neutron"); y_min.push_back(-0.5); y_max.push_back(1.5); y_nbins.push_back(2);		

	// cut.push_back(cuts);	
	// x_axis.push_back("Blip_true_energy"); x_min.push_back(0.); x_max.push_back(10); x_nbins.push_back(20);
	// y_axis.push_back("Blip_energy"); y_min.push_back(0.); y_max.push_back(10); y_nbins.push_back(20);		

	int nplots = x_axis.size();

	//------------------------------//

	vector< vector<TCanvas*> > can; can.resize(nfiles);
	vector< vector<TH2D*> > h; h.resize(nfiles);

	//------------------------------//
		
	// loop over the files 
	for (int ifile = 0; ifile < nfiles; ifile++) {

		tfile.at(ifile) = new TFile(file_names.at(ifile),"readonly");			
		ttree.at(ifile) = (TTree*)(tfile.at(ifile)->Get(ttree_name));	
		h.at(ifile).resize(nplots);	
		can.at(ifile).resize(nplots);

		//loop over the plots
		for (int iplot = 0; iplot < nplots; iplot++) {

			TString hname = "reco_" + run + "_" + x_axis.at(iplot)+ "_" + y_axis.at(iplot);
			h.at(ifile).at(iplot) = new TH2D(hname,";"+x_axis.at(iplot) + ";" + y_axis.at(iplot), x_nbins.at(iplot), x_min.at(iplot), x_max.at(iplot), y_nbins.at(iplot), y_min.at(iplot), y_max.at(iplot) );
			ttree.at(ifile)->Draw(y_axis.at(iplot) + ":" + x_axis.at(iplot) + ">>" + hname,"(" + cut.at(iplot) + ")*" + MCWeight,"goff");	

			TString canvas_name = "2d_" + x_axis.at(iplot) + "_" + y_axis.at(iplot);
			can.at(ifile).at(iplot) = new TCanvas(canvas_name,canvas_name,205,34,1024,768);		
			can.at(ifile).at(iplot)->cd();
			can.at(ifile).at(iplot)->SetTopMargin(0.1);
			can.at(ifile).at(iplot)->SetLeftMargin(0.1);
			can.at(ifile).at(iplot)->SetBottomMargin(0.1);		
			can.at(ifile).at(iplot)->Draw();
			
			h.at(ifile).at(iplot)->Draw("coltz");

			if ( x_axis.at(iplot) == "truth_contains_neutron" || 
			     x_axis.at(iplot) == "truth_contains_proton" ||
			     x_axis.at(iplot) == "truth_contains_proton_or_neutron"				 
				) {

				normalize_columns(h.at(ifile).at(iplot));
				//normalize_rows(h.at(ifile).at(iplot));				
				h.at(ifile).at(iplot)->Draw("coltz text");

			}

			// ----------------- //				

			h.at(ifile).at(iplot)->GetXaxis()->SetTitleFont(FontStyle);
			h.at(ifile).at(iplot)->GetXaxis()->SetTitleSize(TextSize);	
			h.at(ifile).at(iplot)->GetXaxis()->CenterTitle();
			h.at(ifile).at(iplot)->GetXaxis()->SetLabelFont(FontStyle);
			h.at(ifile).at(iplot)->GetXaxis()->SetLabelSize(TextSize);
			h.at(ifile).at(iplot)->GetXaxis()->SetNdivisions(8);
			h.at(ifile).at(iplot)->GetXaxis()->SetLabelOffset(0.01);									
			
			h.at(ifile).at(iplot)->GetYaxis()->SetTitleFont(FontStyle);
			h.at(ifile).at(iplot)->GetYaxis()->SetTitleSize(TextSize);	
			h.at(ifile).at(iplot)->GetYaxis()->CenterTitle();
			h.at(ifile).at(iplot)->GetYaxis()->SetLabelFont(FontStyle);
			h.at(ifile).at(iplot)->GetYaxis()->SetLabelSize(TextSize);	
			h.at(ifile).at(iplot)->GetYaxis()->SetNdivisions(8);	
			h.at(ifile).at(iplot)->GetYaxis()->SetLabelOffset(0.01);	

			h.at(ifile).at(iplot)->GetZaxis()->SetLabelFont(FontStyle);
			h.at(ifile).at(iplot)->GetZaxis()->SetLabelSize(TextSize);														

			can.at(ifile).at(iplot)->SaveAs(plot_path + canvas_name + "_" + run + ".pdf");
		
		} // end of the loop over the plots
	
	} // end of the loop over the files

	//------------------------------//

} // end of the program