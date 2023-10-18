#!/bin/bash
QUI=$PWD
LOGBOOK="/home/ihep_data/LogBook_Analysis/Logbook.log"
TIGER_EVT_RECON="/home/ihep_data/TIGER_Event_Reconstruction"
#DATA_RAW_TIGER="/home/ihep_data/data/raw_root"
#DATA_RAW_GRAAL="/home/ihep_data/data/raw_graal"
DATA_RAW_TIGER="/dati/Data_CGEM_IHEP_Integration_2019/raw_root"                                   
DATA_RAW_GRAAL="/dati/Data_CGEM_IHEP_Integration_2019/raw_graal"

start=`date +%s`
echo "-- RUN $1 --">>time_decode.log
echo "Run number:   $1" 
run_graal=$1

if [ $# -eq 0 ] 
then
    echo "You must set the proper run number";
    echo "Run the code as: ";
    echo "source WenGraal #raw_number";
    echo "i.e. source WenGraal 31";
    exit
fi
echo "------------------">>$LOGBOOK
echo "$1 --> $run_graal">>$LOGBOOK
echo "Start at">>$LOGBOOK
date "+%F-%T">>$LOGBOOK

#TIGER Event Reconstruction
cd $TIGER_EVT_RECON/TER_runner
source run_1.sh $1

#Trasfert to GRAAL
#$exe_ter -C $1
echo "TER Duration: $((($(date +%s)-$start))) seconds";
echo "TER Duration: $((($(date +%s)-$start))) seconds'>>time_decode.log";
#Run GRAAL
ts $exe_graal -mREA $run_graal
ts -d bash -c "cp $data/txt_graal/716392${1}.txt /dati/.carmensandiego/${1}/graal.txt; cp $data/pdf_graal/716392${1}.pdf /dati/.carmensandiego/${1}/graal.pdf; "

#Remove log
rm ihep_data/ts-out.* -rf

cd $QUI

