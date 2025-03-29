{

	//pnfsToXRootD /pnfs/persistent/path/to/your/file

	vector<TString> WhichSampleArray; vector<TString> SamplePath; 

	// ---------------------------------------------------------------------------------- //
	// ---------------------------------------------------------------------------------- //

	//WhichSampleArray.push_back("mcc9_10_Overlay9_Run1"); SamplePath.push_back("/exp/uboone/app/users/eyandel/combined_reco/tests/combine_reco_ana_hist.root");
	//WhichSampleArray.push_back("mcc9_10_Overlay9_Run1"); SamplePath.push_back("/exp/uboone/data/users/eyandel/combined_reco/mcc910_test/checkout_bnb_overlay_test_85files_noweights.root");
	WhichSampleArray.push_back("mcc9_10_Overlay9_Run4b"); SamplePath.push_back("/exp/uboone/data/users/eyandel/combined_reco/mcc910_test/checkout_bnb_overlay_test_500files_weights.root");
	WhichSampleArray.push_back("mcc9_10_Overlay9_Run4b_noweights"); SamplePath.push_back("/pnfs/uboone/persistent/users/apapadop/mcc9_10/mcc9_10_pelee_ntuple.root");
	
	// ---------------------------------------------------------------------------------- //
	// ---------------------------------------------------------------------------------- //

	gROOT->ProcessLine(".L ../../myClasses/Tools.cxx+");
	gROOT->ProcessLine(".L ../../myClasses/STV_Tools.cxx+");	

	gROOT->ProcessLine(".L mcc9_10_neutrino_selection.cxx+");

	for (int i = 0;i < (int)(WhichSampleArray.size()); i++) {

			gROOT->ProcessLine("mcc9_10_neutrino_selection(\""+WhichSampleArray[i]+"\",\""+SamplePath[i]+"\").Loop()");

	}

	gROOT->ProcessLine(".q");

};
