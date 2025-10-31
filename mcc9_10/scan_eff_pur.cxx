#include <TFile.h>
#include <TTree.h>
#include <TGraph.h>
#include <TDirectory.h>
#include <TChain.h>
#include <TGaxis.h>
#include <TROOT.h>
#include <TString.h>
#include <TLegendEntry.h>
#include <TLine.h>

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

void scan_eff_pur() {

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

	// mc files
	TString file_names = "/exp/uboone/data/users/apapadop/ncpi0/PreSelection_mcc9_10_Overlay9_"+run+"_unified.root";
	TString true_file_names = "/exp/uboone/data/users/apapadop/ncpi0/PreTruthSelection_mcc9_10_Overlay9_"+run+"_unified.root";

	TFile* tfile = new TFile(file_names,"readonly");			
	TFile* true_tfile = new TFile(true_file_names,"readonly");			

	TTree* ttree = (TTree*)(tfile->Get(ttree_name));				
	TTree* true_ttree = (TTree*)(true_tfile->Get(true_ttree_name));		

	//------------------------------//

	TString cuts = "wc_kine_pio_energy_1>0 && wc_kine_pio_energy_2>0 && wc_match_isFC == 1 && pd_reco_track_count == 0 && reco_pi0_costheta >= 0.85 && wc_primary_proton_counter == 0  && wc_secondary_proton_counter == 0 && wc_primary_muon_counter == 0 && wc_secondary_muon_counter == 0 && wc_primary_charged_pion_counter == 0 && wc_secondary_charged_pion_counter ==0 && wc_primary_neutron_counter == 0 && wc_nprotontracks == 0 && wc_nmuontracks == 0 && wc_nshowers < 5 && pd_reco_shower_count < 3 && two_shower_start_dist < 50 && reco_shower_opening_angle < 90 && wc_numu_score < 0.1 && wc_numu_score > -2. && dl_nTracks == 0 && (wc_shw_sp_n_20mev_showers == 2 || wc_shw_sp_n_20mev_showers == 3 && wc_shw_sp_n_br4_showers < 8) && (nspacepoints > 100 && nspacepoints < 400) && n_blip_pd_vtx_25cm_g1_anticone < 2 && gl_vertex_contained == 1";			

	//------------------------------//

	// cuts to loop over	

	TString x_cut = "sum_reco_g1_blip_e_100cm"; double x_min = 0.; double x_max = 30.; double x_step = 1.; int x_steps = (x_max - x_min)/x_step-1;
	TString y_cut = "n_blip_pd_vtx_100cm_g1_anticone"; double y_min = 0.; double y_max = 15.; double y_step = 1.; int y_steps = (y_max - y_min)/y_step-1;

	//------------------------------//

	// TLegend

	TLegend* leg = new TLegend(0.1,0.91,0.6,0.98);
	leg->SetBorderSize(0);
	leg->SetNColumns(3);
	leg->SetTextSize(TextSize);	
	leg->SetTextFont(FontStyle);
	leg->SetMargin(0.11);	

	//------------------------------//	

	TString canvas_name = "eff_pur_canvas";
	TCanvas* can = new TCanvas(canvas_name,canvas_name,205,34,1024,768);		
	can->cd();
	can->SetTopMargin(0.1);
	can->SetLeftMargin(0.1);
	can->SetRightMargin(0.1);	
	can->SetBottomMargin(0.1);		
	can->Draw();

	//------------------------------//	

	vector< vector<TH1D*> > h; h.resize(x_steps);
	vector< vector<TH1D*> > h_sig; h_sig.resize(x_steps);	

	//------------------------------//		

	TH1D* true_h = new TH1D("true",";", 1, -1., 1.);	
	true_ttree->Draw("pi0_MCParticle_CosTheta>>true","(1>0)*" + MCWeight,"goff");		

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

	// arrays for TGraph

	vector<double> pur_times_eff_ar;	
	vector<double> pur_ar;
	vector<double> eff_ar;	
	vector<double> x_arr;

	// start the counter for the indices corresponding to the 2D grid
	int counter = 0;

	int golden_index = 0;
	double golden_eff_times_pur = 0;
	double golden_eff = 0;
	double golden_pur = 0;
	TString golden_x_str = "";
	TString golden_y_str = "";	

	//------------------------------//	
				
	//loop over the x cut steps
	for (int ix = 0; ix < x_steps; ix++) {

		h.at(ix).resize(y_steps);
		h_sig.at(ix).resize(y_steps);		

		double x_cut_point = x_max - ix * x_step;
		TString x_str = to_string_with_precision(x_cut_point,0);

		//loop over the y cut steps
		for (int iy = 0; iy < y_steps; iy++) {	

			counter++;
			
			double y_cut_point = y_max - iy * y_step;	
			TString y_str = to_string_with_precision(y_cut_point,0);					

			TString h_name = "reco_"+TString(std::to_string(ix)) + "_" + TString(std::to_string(iy));
			h.at(ix).at(iy) = new TH1D(h_name,";", 1, -1., 1.);	
			ttree->Draw("reco_pi0_costheta>>" + h_name,"(" + cuts + " && " + x_cut + " < " + x_str + " && " + y_cut + " < "+ y_str + ")*" + MCWeight,"goff");
			
			TString h_sig_name = "reco_sig_"+TString(std::to_string(ix)) + "_" + TString(std::to_string(iy));			
			h_sig.at(ix).at(iy) = new TH1D(h_sig_name,";", 1, -1., 1.);	
			ttree->Draw("reco_pi0_costheta>>" + h_sig_name,"(signal == 1 && " + cuts + " && " + x_cut + " < " + x_str + " && " + y_cut + " < "+ y_str + ")*" + MCWeight,"goff");	
			
			x_arr.push_back(counter);

			double purity = h_sig.at(ix).at(iy)->Integral() / h.at(ix).at(iy)->Integral() * 100.;
			double efficiency = h_sig.at(ix).at(iy)->Integral() / true_h->Integral() * 100.; 
			double pur_times_eff = purity * efficiency/100.;

			pur_ar.push_back(purity);
			eff_ar.push_back(efficiency);
			pur_times_eff_ar.push_back(pur_times_eff);			

			if (pur_times_eff > golden_eff_times_pur) {

				golden_index = counter;
				golden_eff_times_pur = pur_times_eff;
				golden_eff = efficiency;
				golden_pur = purity;
				golden_x_str = x_str;
				golden_y_str = y_str;					

			}

		}  // end of the loop over the y cut steps

	} // end of the loop over the x cut steps	

	//------------------------------//
	
	TGraph* gr_pur = new TGraph(x_arr.size(), x_arr.data(), pur_ar.data());
	TGraph* gr_eff = new TGraph(x_arr.size(), x_arr.data(), eff_ar.data());
	TGraph* gr_pur_times_eff = new TGraph(x_arr.size(), x_arr.data(), pur_times_eff_ar.data());		

	//------------------------------//

	can->cd();

	gr_pur->GetXaxis()->SetTitle("index");
	gr_pur->GetXaxis()->CenterTitle();		
	gr_pur->GetXaxis()->SetNdivisions(8);	
	gr_pur->GetXaxis()->SetTitleFont(FontStyle);
	gr_pur->GetXaxis()->SetTitleSize(TextSize);	

	gr_pur->GetYaxis()->SetNdivisions(8);	
	gr_pur->GetYaxis()->SetTitleFont(FontStyle);
	gr_pur->GetYaxis()->SetTitleSize(TextSize);
	gr_pur->GetYaxis()->SetRangeUser(0.,100.);			

	gr_pur->SetMarkerColor(kOrange+7);	
	gr_pur->SetTitle("");
	gr_pur->SetMarkerSize(1.5);	
	gr_pur->SetMarkerStyle(8);			
	gr_pur->Draw("ap");
	TLegendEntry* lpur = leg->AddEntry(gr_pur,"purity","p");
	lpur->SetTextColor(kOrange+7);

	//------------------------------//	

	gr_eff->SetMarkerColor(kAzure+7);	
	gr_eff->SetMarkerSize(1.5);	
	gr_eff->SetMarkerStyle(22);		
	gr_eff->SetTitle("");	
	gr_eff->Draw("p same");
	TLegendEntry* leff = leg->AddEntry(gr_eff,"efficiency","p");
	leff->SetTextColor(kAzure+7);

	//------------------------------//	

	gr_pur_times_eff->SetMarkerSize(1.5);	
	gr_pur_times_eff->SetMarkerStyle(21);		
	gr_pur_times_eff->SetMarkerColor(kGreen+2);	
	gr_pur_times_eff->SetTitle("");	
	gr_pur_times_eff->Draw("p same");
	TLegendEntry* lpur_times_eff = leg->AddEntry(gr_pur_times_eff,"purity x efficiency","p");
	lpur_times_eff->SetTextColor(kGreen+2);

	//------------------------------//		

	// Update pad so ROOT knows the coordinates
	gPad->Update();

	cout << "golden_index = " << golden_index << endl;

	TLine* l = new TLine(golden_index,0,golden_index,100);
	l->SetLineColor(kMagenta);
	l->SetLineWidth(3);	
	l->Draw("same");

	//------------------------------//		

	leg->Draw();

	//------------------------------//		

	TString str_eff = "golden efficiency = " + to_string_with_precision(golden_eff,1) + "%";
	TLatex* latex_eff = new TLatex();
	latex_eff->SetTextFont(FontStyle);
	latex_eff->SetTextSize(TextSize);	
	latex_eff->DrawLatexNDC(0.45,0.83, str_eff);
	
	TString str_pur = "golden purity = " + to_string_with_precision(golden_pur,1) + "%";
	TLatex* latex_pur = new TLatex();
	latex_pur->SetTextFont(FontStyle);
	latex_pur->SetTextSize(TextSize);	
	latex_pur->DrawLatexNDC(0.45,0.78, str_pur);	

	TString str_x_str = "golden " + x_cut + " = " + golden_x_str + " MeV";
	TLatex* latex_x_str = new TLatex();
	latex_x_str->SetTextFont(FontStyle);
	latex_x_str->SetTextSize(TextSize);	
	latex_x_str->DrawLatexNDC(0.45,0.73, str_x_str);	
	
	TString str_y_str = "golden " + y_cut + " = " + golden_y_str + " blips";
	TLatex* latex_y_str = new TLatex();
	latex_y_str->SetTextFont(FontStyle);
	latex_y_str->SetTextSize(TextSize);	
	latex_y_str->DrawLatexNDC(0.45,0.68, str_y_str);		

	//------------------------------//		

	can->SaveAs(plot_path + canvas_name + ".pdf");	

	//------------------------------//	

} // end of the program