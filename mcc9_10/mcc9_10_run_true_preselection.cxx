{

	//pnfsToXRootD /pnfs/persistent/path/to/your/file

	vector<TString> WhichSampleArray; vector<TString> SamplePath; 

	// ---------------------------------------------------------------------------------- //
	// ---------------------------------------------------------------------------------- //

	/*WhichSampleArray.push_back("mcc9_10_Overlay9_Run4b_standalone"); SamplePath.push_back("/pnfs/uboone/scratch/users/rcross/hadd/MCC9.10_Test_Samples_v10_04_07_04_Run4b_pandora_standalone_reco2_BNB_nu_overlay_reco2_ana.root");	
	WhichSampleArray.push_back("mcc9_10_OverlayDirt9_Run4b_standalone"); SamplePath.push_back("/exp/uboone/data/users/gardiner/MCC9.10_Test_Samples_v10_04_07_04_Run4b_pandora_standalone_reco2_BNB_dirt_reco2_ana.root");	
*/
	WhichSampleArray.push_back("mcc9_10_Overlay9_Run4b_unified"); SamplePath.push_back("/exp/uboone/data/users/eyandel/combined_reco/mcc910_test/processed_checkout_root_files/SURPRISE_Test_Samples_v10_04_07_05_Run4b_hyper_unified_reco2_BNB_nu_overlay_may8_reco2_hist_62280499_snapshot.root");	
	WhichSampleArray.push_back("mcc9_10_OverlayDirt9_Run4b_unified"); SamplePath.push_back("/exp/uboone/data/users/eyandel/combined_reco/mcc910_test/processed_checkout_root_files/SURPRISE_Test_Samples_v10_04_07_05_Run4b_hyper_unified_reco2_BNB_dirt_may8_reco2_hist_62280564_snapshot.root");		
	
	// ---------------------------------------------------------------------------------- //
	// ---------------------------------------------------------------------------------- //

	gROOT->ProcessLine(".L ../../myClasses/Tools.cxx+");
	gROOT->ProcessLine(".L ../../myClasses/STV_Tools.cxx+");	

	gROOT->ProcessLine(".L mcc9_10_true_neutrino_selection.cxx+");

	for (int i = 0;i < (int)(WhichSampleArray.size()); i++) {

		if (string(WhichSampleArray[i]).find("Overlay9") != std::string::npos)
		  { gROOT->ProcessLine("mcc9_10_true_neutrino_selection(\""+WhichSampleArray[i]+"\",\""+SamplePath[i]+"\").Loop()"); }

	}

	gROOT->ProcessLine(".q");

};
