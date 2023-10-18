#!/bin/bash
#Set GRAAL to boss mode
cp /home/ihep_data/GRAAL/src/common/constant.h_cgemboss /home/ihep_data/GRAAL/src/common/constant.h
$exe_graal -M
echo "Graal compiled"
for i in {01,9999}
do
    echo $i;
    #$exe_grate $i
    $exe_graal -R $i
    echo "Finish $i"
done;

#Set GRAAL to default mode
cp /home/ihep_data/GRAAL/src/common/constant.h_nocgemboss /home/ihep_data/GRAAL/src/common/constant.h
$exe_graal -M
mkdir -p data_for_china
#Copy the data to share
#rm data_for_china/*
#Planar TB 202106 Tiger
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392001.root data_for_china/cgem_run100.root
