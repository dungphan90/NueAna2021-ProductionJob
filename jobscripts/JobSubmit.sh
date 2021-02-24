#!/usr/bin/bash

commonFolder=/pnfs/minos/persistent/users/dphan/NueAna2021

paramList=$1
numberOfPoints=`cat GridFiles/${paramList} | wc -l`

jobOptions="-G minos -N ${numberOfPoints} --resource-provides=usage_model=DEDICATED,OPPORTUNISTIC --role=Analysis --expected-lifetime=12h --memory=2GB --disk=2GB"

jobsub_submit ${jobOptions} -l '+SingularityImage=\"/cvmfs/singularity.opensciencegrid.org/fermilab/fnal-wn-sl6:latest\"' --append_condor_requirements='(TARGET.HAS_SINGULARITY=?=true)' file://${commonFolder}/JobScript.sh ${paramList}


