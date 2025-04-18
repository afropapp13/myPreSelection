root -b create_rse_list.cxx
root -b CompareRSELists.C
root -b rse_filter_sample.cxx

# pot counting # needs python 2

/exp/uboone/app/users/zarko/getDataInfo.py -v3 --run-subrun-list rse_run_sub_standalone.txt
/exp/uboone/app/users/zarko/getDataInfo.py -v3 --run-subrun-list rse_run_sub_wcprocessed.txt