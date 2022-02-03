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

#include "../../Secondary_Code/myFunctions.cpp"

#include "ubana/myClasses/Constants.h"

using namespace Constants;

void QuickRun4aComparisons() {

	//------------------------------//

	TH1D::SetDefaultSumw2();
	TH2D::SetDefaultSumw2();
	gStyle->SetOptStat(0);

	const int FontStyle = 132;
	const double TextSize = 0.06;			

	//------------------------------//

	// Which BeamOn samples do we want to overlay?
	// Push them back in the array

	std::vector<TString> BeamOnNames; std::vector<TString> BeamOnLabels; 
	std::vector<int> BeamOnColors; std::vector<double> BeamOnPOT;

	BeamOnNames.push_back("/pnfs/uboone/persistent/users/davidc/searchingfornues/v08_00_00_43/0928/prodgenie_bnb_nu_uboone_overlay_mcc9.1_v08_00_00_26_filter_run1_reco2_reco2.root"); 
	BeamOnLabels.push_back("Run 1");
	BeamOnColors.push_back(kBlack);	
	BeamOnPOT.push_back(Fulltor860_wcut_Run1);

	BeamOnNames.push_back("/uboone/data/users/apapadop/searchingfornues/run4a_neutrinoselection_filt_numu_ALL.root");
	BeamOnLabels.push_back("Run 4a");	
	BeamOnColors.push_back(kBlue+1);
	BeamOnPOT.push_back(Fulltor860_wcut_Run4a);	

	//------------------------------//		

	const int NSamples = BeamOnNames.size();

	std::vector<TFile*> BeamOnFiles; BeamOnFiles.resize(NSamples);

	//------------------------------//

	// TTree names & pointers

	TString EventTTreeName = "nuselection/NeutrinoSelectionFilter";
	std::vector<TTree*> EventTTree; EventTTree.resize(NSamples);

	//------------------------------//

	// Plots to include

	std::vector<TString> PlotNames; std::vector< double> Min; std::vector<double> Max;  std::vector<int> NBins;

	PlotNames.push_back("selected"); Min.push_back(-0.5); Max.push_back(1.5); NBins.push_back(2);
	PlotNames.push_back("n_tracks"); Min.push_back(-0.5); Max.push_back(5.5); NBins.push_back(6);	
	PlotNames.push_back("n_showers"); Min.push_back(-0.5); Max.push_back(5.5); NBins.push_back(6);
	PlotNames.push_back("reco_nu_vtx_sce_x"); Min.push_back(-20); Max.push_back(270); NBins.push_back(100);
	PlotNames.push_back("reco_nu_vtx_sce_y"); Min.push_back(-150); Max.push_back(150); NBins.push_back(100);	
	PlotNames.push_back("reco_nu_vtx_sce_z"); Min.push_back(-100); Max.push_back(1100); NBins.push_back(100);
	PlotNames.push_back("hits_u"); Min.push_back(0); Max.push_back(1000); NBins.push_back(100);
	PlotNames.push_back("hits_v"); Min.push_back(0); Max.push_back(1000); NBins.push_back(100);
	PlotNames.push_back("hits_y"); Min.push_back(0); Max.push_back(1000); NBins.push_back(100);	
	PlotNames.push_back("topological_score"); Min.push_back(0); Max.push_back(1); NBins.push_back(100);				

	const int NPlots = PlotNames.size();

	//------------------------------//	

	// Loop over the samples to open the files and the TTree

	for (int iSample = 0; iSample < NSamples; iSample++) {

		BeamOnFiles[iSample] = new TFile(BeamOnNames[iSample],"readonly");
		EventTTree[iSample] = (TTree*)( BeamOnFiles[iSample]->Get(EventTTreeName) );

	} // End of the loop over the samples

	//------------------------------//

	// Loop over the plots to be compared

	for (int iPlot = 0; iPlot < NPlots; iPlot++) {

		TString CanvasName = "Canvas_" + PlotNames[iPlot];
		TCanvas* PlotCanvas = new TCanvas(CanvasName,CanvasName,205,34,1024,768);
		PlotCanvas->cd();
		PlotCanvas->SetTopMargin(0.12);
		PlotCanvas->SetLeftMargin(0.15);
		PlotCanvas->SetBottomMargin(0.15);		
		PlotCanvas->Draw();	

		TLegend* leg = new TLegend(0.25,0.91,0.99,0.995);
		leg->SetBorderSize(0);
		leg->SetNColumns(3);
		leg->SetTextSize(TextSize-0.01);	
		leg->SetTextFont(FontStyle);						

		// Loop over the samples to open the files and to get the corresponding plot

		std::vector<TH1D*> Histos; Histos.resize(NSamples);
		std::vector<TString> HistosName; HistosName.resize(NSamples);		

		for (int iSample = 0; iSample < NSamples; iSample++) {	

			HistosName[iSample] = PlotNames[iPlot] + "_" + TString( ToString(iSample) );
			Histos[iSample] = new TH1D(HistosName[iSample],";" + PlotNames[iPlot],NBins[iPlot],Min[iPlot],Max[iPlot]);
			EventTTree[iSample]->Draw(PlotNames[iPlot] + ">>" + HistosName[iSample],"","goff");

			Histos[iSample]->SetLineWidth(4);
			Histos[iSample]->SetLineColor( BeamOnColors.at(iSample) );	

			Histos[iSample]->GetXaxis()->SetTitleFont(FontStyle);
			Histos[iSample]->GetXaxis()->SetLabelFont(FontStyle);
			Histos[iSample]->GetXaxis()->SetNdivisions(8);
			Histos[iSample]->GetXaxis()->SetLabelSize(TextSize);
			Histos[iSample]->GetXaxis()->SetTitleSize(TextSize);	
			Histos[iSample]->GetXaxis()->SetTitleOffset(1.1);					
			Histos[iSample]->GetXaxis()->CenterTitle();						

			Histos[iSample]->GetYaxis()->SetTitleFont(FontStyle);
			Histos[iSample]->GetYaxis()->SetLabelFont(FontStyle);
			Histos[iSample]->GetYaxis()->SetNdivisions(6);
			Histos[iSample]->GetYaxis()->SetLabelSize(TextSize);
			Histos[iSample]->GetYaxis()->SetTitle("# Events / " + TString( ToString(BeamOnPOT[0]) ) );
			Histos[iSample]->GetYaxis()->SetTitleSize(TextSize);
			Histos[iSample]->GetYaxis()->SetTitleOffset(1.3);
			Histos[iSample]->GetYaxis()->SetTickSize(0);
			Histos[iSample]->GetYaxis()->CenterTitle();	

			double SF = BeamOnPOT[0] / BeamOnPOT[iSample];
//			double SF = 1. / Histos[iSample]->GetEntries();
			Histos[iSample]->Scale(SF);

			double imax = Histos[iSample]->GetMaximum();
			Histos[iSample]->GetYaxis()->SetRangeUser(0.,1.05*imax);

			Histos[iSample]->Draw("hist same");	

			TLegendEntry* legEntry = leg->AddEntry(Histos[iSample],BeamOnLabels[iSample] + ", " +TString( ToString(BeamOnPOT[iSample]) ),"l");
			legEntry->SetTextColor( BeamOnColors.at(iSample) );

		} // End of the loop over the samples grabing the plots	

		leg->Draw();

		PlotCanvas->SaveAs(PlotPath+"Run4a_Validation_"+PlotNames[iPlot]+".pdf");
		delete PlotCanvas;

	} // End of the loop over the plots

	//------------------------------//

} // End of the program