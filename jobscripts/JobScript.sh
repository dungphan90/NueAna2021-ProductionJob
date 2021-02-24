#! /bin/env bash

cd $_CONDOR_SCRATCH_DIR
echo "MY CONDOR SCRATCH = ${_CONDOR_SCRATCH_DIR}"
PNFS=/pnfs/minos/persistent/users/dphan/NueAna2021
CVF=/cvmfs/fermilab.opensciencegrid.org
CVM=/cvmfs/minos.opensciencegrid.org/minos

source $CVF/products/common/etc/setups.sh
export MINOS_SETUP_DIR=$CVM/minossoft/setup
SETUPMINOS=$MINOS_SETUP_DIR/setup_minossoft_FNALU.sh
echo "source $SETUPMINOS"
source $SETUPMINOS

cd $_CONDOR_SCRATCH_DIR

ifdh cp -D ${PNFS}/nue-official-testrel.02232021.tar $_CONDOR_SCRATCH_DIR
tar xvf nue-official-testrel.02232021.tar 
cd nue-official-testrel
srt_setup -a

cd production-job-nofc
ProcNum=$((1+$PROCESS))
parval=`head -n+"${ProcNum}" GridFiles/$1 | tail -1`
echo ${parval}

# Performing combo fit
# loon -b -q $SRT_PRIVATE_CONTEXT/NueAna/macros/LoadLibs.C "DoContour2DSterileGridRP11RP12RP13DATA_LogScale.C(${parval})"

# Performing nue-only fit
loon -b -q $SRT_PRIVATE_CONTEXT/NueAna/macros/LoadLibs.C "DoContour2DSterileGridRP11RP12RP13DATA_LogScale.C(${parval}, 0)"

ifdh cp -D *.root ${PNFS}/FitResults

