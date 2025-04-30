{

	//pnfsToXRootD /pnfs/persistent/path/to/your/file

	vector<TString> WhichSampleArray; vector<TString> SamplePath; 

	// ---------------------------------------------------------------------------------- //
	// ---------------------------------------------------------------------------------- //

	WhichSampleArray.push_back("mcc9_10_BeamOn9_Run4b_unified"); SamplePath.push_back("/exp/uboone/data/users/apapadop/pelee_tuples_mcc9_10_slimmed/wc_processed_rse_matched.root");
	WhichSampleArray.push_back("mcc9_10_ExtBNB9_Run4b_unified"); SamplePath.push_back("/exp/uboone/data/users/eyandel/combined_reco/mcc910_test/processed_checkout_root_files/MCC9.10_Test_Samples_v10_04_07_03_Run4b_super_unified_reco2_BNB_beam_off_reco2_hist.root");	
	WhichSampleArray.push_back("mcc9_10_Overlay9_Run4b_unified"); SamplePath.push_back("/exp/uboone/data/users/eyandel/combined_reco/mcc910_test/processed_checkout_root_files/MCC9.10_Test_Samples_v10_04_07_04_Run4b_super_unified_reco2_BNB_nu_overlay_reco2_hist_flagbugfix.root");	
	WhichSampleArray.push_back("mcc9_10_OverlayDirt9_Run4b_unified"); SamplePath.push_back("/exp/uboone/data/users/fgao/mini_retreat_2025/MCC9.10_Test_Samples_v10_04_07_04_Run4b_super_unified_reco2_BNB_dirt_reco2_hist.root");		
	
	// ---------------------------------------------------------------------------------- //
	// ---------------------------------------------------------------------------------- //

	gROOT->ProcessLine(".L ../../../generators/Tools.cxx+");
	gROOT->ProcessLine(".L mcc9_10_neutrino_selection.cxx+");

	for (int i = 0;i < (int)(WhichSampleArray.size()); i++) {

			gROOT->ProcessLine("mcc9_10_neutrino_selection(\""+WhichSampleArray[i]+"\",\""+SamplePath[i]+"\").Loop()");

	}

	gROOT->ProcessLine(".q");

};
