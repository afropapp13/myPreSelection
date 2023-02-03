
###########################################

# CCQE Preselection

root -l PeLEE_script_CCQEPreSelection.C

hadd -f /pnfs/uboone/persistent/users/apapadop/mySamples/v08_00_00_52/CCQEPeLEETuples/CCQEPreSelection_BeamOn9_Combined_v08_00_00_52.root /pnfs/uboone/persistent/users/apapadop/mySamples/v08_00_00_52/CCQEPeLEETuples/CCQEPreSelection_BeamOn9_Run{1,2,3}_v08_00_00_52.root

hadd -f /pnfs/uboone/persistent/users/apapadop/mySamples/v08_00_00_52/CCQEPeLEETuples/CCQEPreSelection_ExtBNB9_Combined_v08_00_00_52.root /pnfs/uboone/persistent/users/apapadop/mySamples/v08_00_00_52/CCQEPeLEETuples/CCQEPreSelection_ExtBNB9_Run{1,2,3}_v08_00_00_52.root

hadd -f /pnfs/uboone/persistent/users/apapadop/mySamples/v08_00_00_52/CCQEPeLEETuples/CCQEPreSelection_Overlay9_Combined_v08_00_00_52.root /pnfs/uboone/persistent/users/apapadop/mySamples/v08_00_00_52/CCQEPeLEETuples/CCQEPreSelection_Overlay9_Run{1,2,3}_v08_00_00_52.root

hadd -f /pnfs/uboone/persistent/users/apapadop/mySamples/v08_00_00_52/CCQEPeLEETuples/CCQEPreSelection_OverlayDirt9_Combined_v08_00_00_52.root /pnfs/uboone/persistent/users/apapadop/mySamples/v08_00_00_52/CCQEPeLEETuples/CCQEPreSelection_OverlayDirt9_Run{1,2,3}_v08_00_00_52.root

hadd -f /pnfs/uboone/persistent/users/apapadop/mySamples/v08_00_00_52/CCQEPeLEETuples/CCQEPreTruthSelection_Overlay9_Combined_v08_00_00_52.root /pnfs/uboone/persistent/users/apapadop/mySamples/v08_00_00_52/CCQEPeLEETuples/CCQEPreTruthSelection_Overlay9_Run{1,2,3}_v08_00_00_52.root

root -l PeLEE_script_DetVar_CCQEPreSelection.C

# NuWro Fake Data

root -l PeLEE_script_FakeData_CCQEPreSelection.C

hadd -f /uboone/data/users/apapadop/PeLEETuples/CCQEPreSelection_Overlay9NuWro_Combined_v08_00_00_52.root /uboone/data/users/apapadop/PeLEETuples/PreSelection_Overlay9NuWro_Run{1,2,3}_v08_00_00_52.root

hadd -f /uboone/data/users/apapadop/PeLEETuples/CCQEPreTruthSelection_Overlay9NuWro_Combined_v08_00_00_52.root /uboone/data/users/apapadop/PeLEETuples/CCQEPreTruthSelection_Overlay9NuWro_Run{1,2,3}_v08_00_00_52.root

hadd -f /uboone/data/users/apapadop/PeLEETuples/CCQEPreSelection_Overlay9NuWro_Combined_v08_00_00_52_POT.root /uboone/data/users/apapadop/PeLEETuples/CCQEPreSelection_Overlay9NuWro_Run{1,2,3}_v08_00_00_52_POT.root
