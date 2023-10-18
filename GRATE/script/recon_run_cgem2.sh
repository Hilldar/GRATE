#!/bin/bash

:'
#Set GRAAL to boss mode
cp /home/ihep_data/GRAAL/src/common/constant.h_cgemboss /home/ihep_data/GRAAL/src/common/constant.h
$exe_graal -M
echo "Graal compiled"

#Reconstruct the runs
$exe_graal -R 337
sleep 1m
echo "Finish 337"
$exe_graal -R 338
sleep 1m
echo "Finish 338"
$exe_graal -R 339
sleep 1m
echo "Finish 339"
$exe_graal -R  340
sleep 1m
echo "Finish 340"
$exe_graal -R  341
sleep 1m
echo "Finish 341"
$exe_graal -R 342
sleep 1m
echo "Finish 342"
$exe_graal -R 343
sleep 1m
echo "Finish 343"
$exe_graal -R 351
sleep 1m
echo "Finish 351"
$exe_graal -R 368
sleep 1m
echo "Finish 368"
$exe_graal -R 370
sleep 1m
echo "Finish 370"
sleep 1m
$exe_graal -R 372
sleep 1m
echo "Finish 372"
$exe_graal -R 375
sleep 1m
echo "Finish 375"
$exe_graal -R 355
sleep 1m
echo "Finish 355"
#Set GRAAL to default mode
cp /home/ihep_data/GRAAL/src/common/constant.h_nocgemboss /home/ihep_data/GRAAL/src/common/constant.h
$exe_graal -M
mkdir -p data_for_china

#Copy the data to share
rm data_for_china/*
'
#Dataset HV STD - rate 10kHz
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392337.root data_for_china/cgem_run10.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392338.root data_for_china/cgem_run11.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392339.root data_for_china/cgem_run12.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392340.root data_for_china/cgem_run13.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392341.root data_for_china/cgem_run14.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392342.root data_for_china/cgem_run15.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392343.root data_for_china/cgem_run16.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392351.root data_for_china/cgem_run17.root
#Dataset HV high - rate 10 kHz
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392368.root data_for_china/cgem_run18.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392370.root data_for_china/cgem_run19.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392372.root data_for_china/cgem_run20.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392375.root data_for_china/cgem_run21.root 
#Datarun HV low - rate 10 kHz
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392355.root data_for_china/cgem_run22.root
