{

	//pnfsToXRootD /pnfs/persistent/path/to/your/file

	vector<TString> WhichSampleArray; vector<TString> SamplePath; 

	// ---------------------------------------------------------------------------------- //
	// ---------------------------------------------------------------------------------- //

	// 4a	
	WhichSampleArray.push_back("mcc9_10_NCpi0Overlay9_Run4a_unified"); SamplePath.push_back("/pnfs/uboone/persistent/users/uboonepro/surprise/run4a_full_samples/wc_processed/BNB/checkout_MCC9.10_Run4a4c4d5_v10_04_07_13_BNB_nu_overlay_surprise_reco2_hist_4a.root");	
	WhichSampleArray.push_back("mcc9_10_nonNCpi0Overlay9_Run4a_unified"); SamplePath.push_back("/pnfs/uboone/persistent/users/uboonepro/surprise/run4a_full_samples/wc_processed/BNB/checkout_MCC9.10_Run4a4c4d5_v10_04_07_13_BNB_nu_overlay_surprise_reco2_hist_4a.root");
	WhichSampleArray.push_back("mcc9_10_OverlayDirt9_Run4a_unified"); SamplePath.push_back("/pnfs/uboone/persistent/users/uboonepro/surprise/run4a_full_samples/wc_processed/BNB/checkout_MCC9.10_Run4a4c4d5_v10_04_07_13_BNB_dirt_overlay_surprise_reco2_hist_4a.root");
	
	// 4b
	WhichSampleArray.push_back("mcc9_10_NCpi0Overlay9_Run4b_unified"); SamplePath.push_back("/exp/uboone/data/uboonepro/MCC9.10/wc_processed/BNB/MCC9.10_Run4b_v10_04_07_09_BNB_NC_pi0_overlay_surprise_reco2_hist.root");	
	WhichSampleArray.push_back("mcc9_10_nonNCpi0Overlay9_Run4b_unified"); SamplePath.push_back("/exp/uboone/data/uboonepro/MCC9.10/wc_processed/BNB/MCC9.10_Run4b_v10_04_07_09_BNB_nu_overlay_surprise_reco2_hist.root");
	WhichSampleArray.push_back("mcc9_10_OverlayDirt9_Run4b_unified"); SamplePath.push_back("/exp/uboone/data/uboonepro/MCC9.10/wc_processed/BNB/MCC9.10_Run4b_v10_04_07_09_BNB_dirt_surpise_reco2_hist.root");	
	
	// 4c
	WhichSampleArray.push_back("mcc9_10_NCpi0Overlay9_Run4c_unified"); SamplePath.push_back("/exp/uboone/data/uboonepro/MCC9.10/run4c_full_samples/wc_processed/BNB/checkout_MCC9.10_Run4c4d5_v10_04_07_13_BNB_NCpi0_overlay_surprise_reco2_hist_4c.root");	
	WhichSampleArray.push_back("mcc9_10_nonNCpi0Overlay9_Run4c_unified"); SamplePath.push_back("/pnfs/uboone/persistent/users/uboonepro/surprise/run4c_full_samples/wc_processed/BNB/checkout_MCC9.10_Run4a4c4d5_v10_04_07_13_BNB_nu_overlay_surprise_reco2_hist_4c.root");
	WhichSampleArray.push_back("mcc9_10_OverlayDirt9_Run4c_unified"); SamplePath.push_back("/pnfs/uboone/persistent/users/uboonepro/surprise/run4c_full_samples/wc_processed/BNB/checkout_MCC9.10_Run4a4c4d5_v10_04_07_13_BNB_dirt_overlay_surprise_reco2_hist_4c.root");	

	// 4d
	WhichSampleArray.push_back("mcc9_10_NCpi0Overlay9_Run4d_unified"); SamplePath.push_back("/exp/uboone/data/uboonepro/MCC9.10/run4d_full_samples/wc_processed/BNB/checkout_MCC9.10_Run4c4d5_v10_04_07_13_BNB_NCpi0_overlay_surprise_reco2_hist_4d.root");	
	WhichSampleArray.push_back("mcc9_10_nonNCpi0Overlay9_Run4d_unified"); SamplePath.push_back("/pnfs/uboone/persistent/users/uboonepro/surprise/run4d_full_samples/wc_processed/BNB/checkout_MCC9.10_Run4a4c4d5_v10_04_07_13_BNB_nu_overlay_surprise_reco2_hist_4d.root");
	WhichSampleArray.push_back("mcc9_10_OverlayDirt9_Run4d_unified"); SamplePath.push_back("/pnfs/uboone/persistent/users/uboonepro/surprise/run4d_full_samples/wc_processed/BNB/checkout_MCC9.10_Run4a4c4d5_v10_04_07_13_BNB_dirt_overlay_surprise_reco2_hist_4d.root");		

	// 5
	WhichSampleArray.push_back("mcc9_10_NCpi0Overlay9_Run5_unified"); SamplePath.push_back("/exp/uboone/data/uboonepro/MCC9.10/run5_full_samples/wc_processed/BNB/checkout_MCC9.10_Run4c4d5_v10_04_07_13_BNB_NCpi0_overlay_surprise_reco2_hist_5.root");	
	WhichSampleArray.push_back("mcc9_10_nonNCpi0Overlay9_Run5_unified"); SamplePath.push_back("/pnfs/uboone/persistent/users/uboonepro/surprise/run5_full_samples/wc_processed/BNB/checkout_MCC9.10_Run4a4c4d5_v10_04_07_13_BNB_nu_overlay_surprise_reco2_hist_5.root");
	WhichSampleArray.push_back("mcc9_10_OverlayDirt9_Run5_unified"); SamplePath.push_back("/pnfs/uboone/persistent/users/uboonepro/surprise/run5_full_samples/wc_processed/BNB/checkout_MCC9.10_Run4a4c4d5_v10_04_07_13_BNB_dirt_overlay_surprise_reco2_hist_5.root");	
	
	// ---------------------------------------------------------------------------------- //
	// ---------------------------------------------------------------------------------- //

	gROOT->ProcessLine(".L ../calculate_pot.cxx+");

	for (int i = 0;i < (int)(WhichSampleArray.size()); i++) {

			if (string(WhichSampleArray[i]).find("Overlay") != std::string::npos)
			  { gROOT->ProcessLine("calculate_pot(\""+WhichSampleArray[i]+"\",\""+SamplePath[i]+"\")"); }

	}

        gROOT->ProcessLine(".q");

};
