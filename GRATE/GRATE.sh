#!/bin/sh
#
# Examlple of using options in scripts
#
QUI=$PWD
NROC=14
NSUB=2000
MAXJOB=50

#if [ $# -eq 0 ]
#then
#    echo "Missing options!"
#    echo "(run $0 -h for help)"
#    echo ""
#    exit 0
#fi
run_number_no_opt=$1
run_number_opt=$2
echo $run_number
while getopts "heDAESLQ" OPTION; do
    case $OPTION in

	e)
	    echo " Hello world !"
	    exit 0
	    ;;

	h)
	    echo "Usage:"
	    echo ""
	    echo "   -e     to execute echo \"hello world\""
	    echo "   -h     help (this output)"
	    echo "   -D     Decode the RUN"
	    echo "   -A     Calibrate the RUN"
	    echo "   -E     Event creation of the RUN"
	    echo "   -S     SubRUN reconstruction w/ GRAAL"
	    echo "   -L     Create file for LUT and the LUT"
	    echo "   -Q     QAQC from TER and GRAAL to Carmen"
	    echo "   "
	    echo "   Run it as:"
	    echo "   GRATE Run_Number"
	    echo "   i.e. GRATE 102"
	    exit 0
	    ;;

	D)
	    echo " Decode the RUN"
	    ts -S $MAXJOB
	    for isub in $(seq 0 $NSUB);
	    do
		ts -n bash -c "$exe_ter -D $run_number_opt $isub"
		ts -n bash -c "$exe_ter -V $run_number_opt $isub"
	    done
	    echo "Terminated decoding"
	    exit 0
	    ;;
	A)
	    echo " Calibrate the RUN"
            ts -S $MAXJOB
            for isub in $(seq 0 $NSUB);
            do
                ts -n bash -c "$exe_ter -A $run_number_opt $isub"
            done
            echo "Terminated calibration"
	    exit 0
            ;;
        E)
            echo " Event reconstruction of the RUN"
            ts -S $MAXJOB
            for isub in $(seq 0 $NSUB);
            do
                ts -n bash -c "$exe_ter -E $run_number_opt $isub"
            done
            echo "Terminated event reconstruction"
	    exit 0
	    ;;
	S)
	    echo " SubRUN reconstruction with GRAAL"
	    for isub in {0..2000}; 
	    do 
		if [ -f "/home/ihep_data/data/raw_root/${run_number_opt}/Sub_RUN_event_${isub}.root" ]; 
		then 
		    echo "Found"; 
		    cp /home/ihep_data/data/raw_root/${run_number_opt}/Sub_RUN_event_${isub}.root /home/ihep_data/data/raw_graal/subrun/run716392${run_number_opt}_${isub}.root;
		fi;
		if [ -f "/home/ihep_data/data/raw_root/${run_number_opt}/Sub_RUN_event_${isub}.root" ]; 
		then 
		    ts $exe_graal -REA ${run_number_opt} ${isub};
		fi; 
	    done;
	    exit 0
	    ;;
	L)
	    if [ -f "/home/ihep_data/data/raw_dat/RUN_${run_number_opt}/CONF_run_${run_number_opt}.pkl" ];
	    then 
		rm -f /home/ihep_data/TIGER_Event_Reconstruction/export/conf_files/CONF_run_*.pkl
		cp /home/ihep_data/data/raw_dat/RUN_${run_number_opt}/CONF_run_${run_number_opt}.pkl /home/ihep_data/TIGER_Event_Reconstruction/export/conf_files/. ;
		cd /home/ihep_data/TIGER_Event_Reconstruction/export/conf_files
		python3 picke_converter.py
		mv CONF_run_${run_number_opt}_2.pkl CONF_run_${run_number_opt}.pkl
		cd ..
		python3 baseline_exraction.py ${run_number_opt}
		cd $QUI
	    fi;
	    cd $GRATE
	    make
	    ./bin/LUT ${run_number_opt}
	    exit 0
	    ;;
	Q)
	    source $QAQC_code/QAQC.sh $run_number_opt
	    exit 0
	    ;;
    esac
done

#Purger
cd /home/ihep_data/data/raw_dat
python purger.py
cd -
#
if [ -z $run_number_no_opt ]; then echo "Use the command 'GRATE Run_Number'"; exit; fi
if [    $run_number_no_opt ]; then cd; bash -c "source $GRATE/WenGraal.sh ${run_number_no_opt}"; cd $QUI; exit; fi
#if [    $run_number_no_opt ]; then cd; bash -c "$exe_grate -D ${run_number_no_opt}"; bash -c "$exe_grate -A ${run_number_no_opt}"; bash -c "$exe_grate -E ${run_number_no_opt}"; cd $QUI; exit; fi

