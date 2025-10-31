#include <TFile.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <THStack.h>
#include <TString.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TLine.h>
#include <TLatex.h>

#include <iostream>
#include <vector>

void quick_plotting() {

    gStyle->SetOptStat(0);

    TFile* old  = new TFile("/exp/uboone/data/users/eyandel/combined_reco/mcc910_test/processed_checkout_root_files/SURPRISE_Test_Samples_v10_04_07_05_Run4b_hyper_unified_reco2_BNB_nu_overlay_may8_reco2_hist_62280499_snapshot.root","readonly");
    TFile* newf = new TFile("/pnfs/uboone/scratch/users/bbogart/SURPRISE/checkout_MCC9.10_Run4b_v10_04_07_09_BNB_nu_overlay_surprise_reco2_hist.root","readonly");

    //TString var = "kine_pio_energy_1", dir = "wcpselection/T_KINEvars";; int nbins = 20; double min = 0., max = 500.;
    //TString var = "kine_pio_energy_2", dir = "wcpselection/T_KINEvars";; int nbins = 20; double min = 0., max = 500.;
    TString var = "match_isFC", dir = "wcpselection/T_eval";; int nbins = 2; double min = -0.5, max = 1.5;        

    TH1D* h_old = new TH1D("h_old",";"+var,nbins,min,max);
    TH1D* h_new = new TH1D("h_new",";"+var,nbins,min,max);    

    TTree* newt = (TTree*)(newf->Get(dir));    
    TTree* oldt = (TTree*)(old->Get(dir)); 

    newt->Draw(var+">>h_new");                               
    oldt->Draw(var+">>h_old");

    h_new->Scale(1./h_new->Integral());
    h_old->Scale(1./h_old->Integral());
    
    h_new->SetLineColor(kOrange+7);
    h_old->SetLineColor(kGreen+2);

    TCanvas* c = new TCanvas();

    h_old->Draw();
    h_new->Draw("same"); 

    TLegend* leg = new TLegend(0.1,0.9,0.3,0.98);
    leg->AddEntry(h_new,"new","l");
    leg->AddEntry(h_old,"old","l");
    leg->SetNColumns(2);    
    leg->Draw();

    c->SaveAs(var+".pdf");



}