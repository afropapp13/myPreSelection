#!/bin/bash

export TERM=screen

#source /grid/fermiapp/products/uboone/setup_uboone_mcc9.sh
source /cvmfs/uboone.opensciencegrid.org/products/setup_uboone_mcc9.sh
setup uboonecode v10_04_04 -q e26:prof
#setup scipy v1_1_0 -q e17:p2714b:prof
#unsetup mrb
#setup mrb -o
#source localProducts_larsoft_v08_05_00_17_e17_prof/setup
#mrbsetenv
#export ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:$GENIE_INC/GENIE

#kx509
htgettoken -a htvaultprod.fnal.gov -i uboone
#httokensh -a htvaultprod.fnal.gov -i uboone -- /bin/bash
#voms-proxy-init -noregen -rfc -voms 'fermilab:/fermilab/sbnd/Role=Analysis'