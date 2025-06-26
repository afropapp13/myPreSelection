{

	//pnfsToXRootD /pnfs/persistent/path/to/your/file

	vector<TString> WhichSampleArray; vector<TString> SamplePath; 

	// ---------------------------------------------------------------------------------- //
	// ---------------------------------------------------------------------------------- //

	WhichSampleArray.push_back("mcc9_10_BeamOn9_Run4b_unified"); SamplePath.push_back("/exp/uboone/data/users/eyandel/combined_reco/mcc910_test/processed_checkout_root_files/SURPRISE_Test_Samples_v10_04_07_05_Run4b_hyper_unified_reco2_BNB_beam_on_may8_reco2_hist_goodruns_62280934_snapshot.root");
	WhichSampleArray.push_back("mcc9_10_ExtBNB9_Run4b_unified"); SamplePath.push_back("/exp/uboone/data/users/eyandel/combined_reco/mcc910_test/processed_checkout_root_files/SURPRISE_Test_Samples_v10_04_07_05_Run4b_hyper_unified_reco2_BNB_beam_off_may8_reco2_hist_goodruns_62280841_snapshot.root");		
	WhichSampleArray.push_back("mcc9_10_OverlayDirt9_Run4b_unified"); SamplePath.push_back("/exp/uboone/data/users/eyandel/combined_reco/mcc910_test/processed_checkout_root_files/SURPRISE_Test_Samples_v10_04_07_05_Run4b_hyper_unified_reco2_BNB_dirt_may8_reco2_hist_62280564_snapshot.root");		
	WhichSampleArray.push_back("mcc9_10_Overlay9_Run4b_unified"); SamplePath.push_back("/exp/uboone/data/users/eyandel/combined_reco/mcc910_test/processed_checkout_root_files/SURPRISE_Test_Samples_v10_04_07_05_Run4b_hyper_unified_reco2_BNB_nu_overlay_may8_reco2_hist_62280499_snapshot.root");
	//WhichSampleArray.push_back("mcc9_10_Overlay9_Run4b_unified"); SamplePath.push_back("/exp/uboone/data/users/eyandel/combined_reco/mcc910_test/processed_checkout_root_files/SURPRISE_Test_Samples_v10_04_07_05_Run4b_super_unified_reco2_BNB_nu_NC_pi0_overlay_reco2_hist.root");		
	
	// ---------------------------------------------------------------------------------- //
	// ---------------------------------------------------------------------------------- //

	gROOT->ProcessLine(".L ../../../generators/Tools.cxx+");
	gROOT->ProcessLine(".L mcc9_10_neutrino_selection.cxx+");

	for (int i = 0;i < (int)(WhichSampleArray.size()); i++) {

			gROOT->ProcessLine("mcc9_10_neutrino_selection(\""+WhichSampleArray[i]+"\",\""+SamplePath[i]+"\").Loop()");

	}

	gROOT->ProcessLine(".q");

};