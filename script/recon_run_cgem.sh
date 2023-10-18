#!/bin/bash
#Set GRAAL to boss mode
cp /home/ihep_data/GRAAL/src/common/constant.h_cgemboss /home/ihep_data/GRAAL/src/common/constant.h
$exe_graal -M
echo "Graal compiled"
#Reconstruct the runs
#for i in {337,338,339,340,341,342,343,351,368,370,372,375,355,376,377,378,387,380,383,384,385,395,396,397,400};
#for i in {405,406,409,410,411,412,418,419,420,421,422}
#for i in {423,424,425,426,427,428,429,431,432}
for i in {435,436,438,441,445}
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
:'
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
#Dataset HV high - rate 5 kHz
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392376.root data_for_china/cgem_run23.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392377.root data_for_china/cgem_run24.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392378.root data_for_china/cgem_run25.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392387.root data_for_china/cgem_run26.root
#Dataset no gain - random trigger
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392380.root data_for_china/cgem_run27.root
#cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392383.root data_for_china/cgem_run28.root
#cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392384.root data_for_china/cgem_run29.root
#cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392385.root data_for_china/cgem_run30.root
#Dataset Hv high - flat threshold
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392395.root data_for_china/cgem_run31.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392396.root data_for_china/cgem_run32.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392397.root data_for_china/cgem_run33.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392400.root data_for_china/cgem_run34.root
#Dataset High Induction - rate 8 kHz
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392405.root data_for_china/cgem_run35.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392406.root data_for_china/cgem_run36.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392409.root data_for_china/cgem_run37.root
#Dataset HV STD - rate 8 kHz - before 410 and after 411 412 gas bottle change
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392410.root data_for_china/cgem_run38.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392411.root data_for_china/cgem_run39.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392412.root data_for_china/cgem_run40.root
#Dataset HV STD - rate 8 KHz - increasing holes after summer 2020
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392418.root data_for_china/cgem_run41.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392419.root data_for_china/cgem_run42.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392420.root data_for_china/cgem_run43.root
#Dataset HV off - rate 8 kHz - noise 
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392421.root data_for_china/cgem_run44.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392422.root data_for_china/cgem_run45.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392423.root data_for_china/cgem_run46.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392424.root data_for_china/cgem_run47.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392426.root data_for_china/cgem_run48.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392428.root data_for_china/cgem_run49.root
#Dataset HV std - rate 8 kHz
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392425.root data_for_china/cgem_run50.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392427.root data_for_china/cgem_run51.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392429.root data_for_china/cgem_run52.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392431.root data_for_china/cgem_run53.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392432.root data_for_china/cgem_run54.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392433.root data_for_china/cgem_run55.root
'
#Dataset HV trans 2kv/cm - rate 8 kHz 
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392435.root data_for_china/cgem_run56.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392436.root data_for_china/cgem_run57.root
#Dataset HV std - rate 8 kHz
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392438.root data_for_china/cgem_run58.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392441.root data_for_china/cgem_run59.root
cp /dati/Data_CGEM_IHEP_Integration_2019/rec_graal/rec_run716392445.root data_for_china/cgem_run60.root
