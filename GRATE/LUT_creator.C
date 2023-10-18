#include <iostream>
#include "TString.h"
#include "TTree.h"
#include "TFile.h"
using namespace std;
//General variables
const int INIT_FEB =  0; //16;
const int MAX_FEB  = 44; //55;  
const int N_FEB = MAX_FEB-INIT_FEB;
const int N_TIGER = 2*N_FEB;
const int N_CHIP = 2;
const int N_CHANNEL   = 64;
const int N_ROC = 14;
const int N_SW_FEB = 8;
const bool no_planar = true;
//Mapping variables
int mx[N_FEB][N_CHIP][N_CHANNEL];
int mv[N_FEB][N_CHIP][N_CHANNEL];
//Calibration QDC variables
float cons[N_ROC][N_SW_FEB][N_CHANNEL];
float mslope[N_ROC][N_SW_FEB][N_CHANNEL];
float mqmax[N_ROC][N_SW_FEB][N_CHANNEL];
//TIGER Threhsold in digits
float mvth1_dig[N_ROC][N_SW_FEB][N_CHANNEL];
float mvth2_dig[N_ROC][N_SW_FEB][N_CHANNEL];
//TIGER Baseline in digits
float mbase_t [N_ROC][N_SW_FEB][N_CHANNEL];
float mbase_e [N_ROC][N_SW_FEB][N_CHANNEL];
//TIGER Threshold in fC
float mth_t_fC[N_ROC][N_SW_FEB][N_CHANNEL];
float mth_e_fC[N_ROC][N_SW_FEB][N_CHANNEL];
//Data Threshold fC
float mthr_fC[N_FEB][N_CHIP][N_CHANNEL];
//Noise
float mnoise_Hz[N_FEB][N_CHIP][N_CHANNEL];
float mnoise_Q[N_FEB][N_CHIP][N_CHANNEL];
//Signal
float msignal_meanQ[N_FEB][N_CHIP][N_CHANNEL];
float msignal_maxQ[N_FEB][N_CHIP][N_CHANNEL];
float msignal_Hz[N_FEB][N_CHIP][N_CHANNEL];
float msignal_t0[N_FEB][N_CHIP][N_CHANNEL];
float msignal_tF[N_FEB][N_CHIP][N_CHANNEL];
float msignal_dt[N_FEB][N_CHIP][N_CHANNEL];
float msignal_t0_tiger[N_FEB][N_CHIP][N_CHANNEL];
float msignal_tF_tiger[N_FEB][N_CHIP][N_CHANNEL];
float msignal_dt_tiger[N_FEB][N_CHIP][N_CHANNEL];
int   msignal_quality[N_FEB][N_CHIP][N_CHANNEL];
//Output file/tree/variables
TString ofile_name;
TTree   *otree;
TTree   *ootree;
TFile   *ofile;
int     t_layer,t_roc,t_sw_feb,t_feb,t_chip,t_ch,t_strip_x,t_strip_v,t_strip_xx,t_strip_vv, t_sheet, t_quality, t_side;
float   t_calib_QDC_slope, t_calib_QDC_const, t_calib_QDC_saturation;
float   t_vth1_mV, t_vth2_mV, t_base_e, t_base_t, t_thr_e_fC, t_thr_t_fC, t_thr_fC, t_noise_Hz, t_noise_Q;
float   t_signal_Q, t_signal_maxQ, t_signal_rate, t_signal_tstart, t_signal_tstop, t_signal_tsigma, t_signal_tstartFEB, t_signal_tstopFEB, t_signal_tsigmaFEB;
TString file_name1,file_name2;
//TO DEFINE EACH LUT 
//TO DEFINE EACH LUT 
//TO DEFINE EACH LUT 
bool NO_time_reference = true;
int lut_number;
TString file_name3,file_name4,file_name5,file_name6;
int t_First_RUN,t_Last_RUN;

int t_Integration_time =    6;
int t_Energy_mode      =    1;
int t_HV_L1_G3         =  275;
int t_HV_L2_G3         =  275;
int t_HV_L3_G3         =    0;
int t_HV_L1_G2         =  275;
int t_HV_L2_G2         =  275;
int t_HV_L3_G2         =    0;
int t_HV_L1_G1         =  280;
int t_HV_L2_G1         =  280;
int t_HV_L3_G1         =    0;
int t_HV_L1_In         = 1000;
int t_HV_L2_In         = 1000;
int t_HV_L3_In         =    0;
int t_HV_L1_T2         =  600;
int t_HV_L2_T2         =  600;
int t_HV_L3_T2         =    0;
int t_HV_L1_T1         =  600;
int t_HV_L2_T1         =  600;
int t_HV_L3_T1         =    0;
int t_HV_L1_Dr         =  750;
int t_HV_L2_Dr         =  750;
int t_HV_L3_Dr         =    0;
//
//
//Init file/tree
TFile *file1,*file2,*file3,*file4,*file5,*file6;
TTree *tree1,*tree2,*tree3,*tree4,*tree5,*tree6;

void custom_setting(int run){
  const int N = 10;
  int low_gain [N]={355,  0,  0,  0,  0,  0,  0,  0,0,0};
  int no_gain  [N]={380,421,422,423,424,426,428,  0,0,0};
  int high_gain[N]={368,370,372,375,395,396,397,400,0,0};
  int high_ind [N]={405,406,409,  0,  0,  0,  0,  0,0,0};
  for(int i=0;i<N;i++){
    if(run == low_gain[i]) {
      t_HV_L1_G3=t_HV_L2_G3=t_HV_L1_G2=t_HV_L2_G2=t_HV_L1_G1=t_HV_L2_G1=200;
    }
    if(run == no_gain[i]) {
      t_HV_L1_G3=t_HV_L2_G3=t_HV_L1_G2=t_HV_L2_G2=t_HV_L1_G1=t_HV_L2_G1=0;
      t_HV_L1_In=t_HV_L2_In=t_HV_L1_T2=t_HV_L2_T2=t_HV_L1_T1=t_HV_L2_T1=t_HV_L1_Dr=t_HV_L2_Dr=0;
    }
    if(run == high_gain[i]) {
      t_HV_L1_G3=t_HV_L2_G3=t_HV_L1_G2=t_HV_L2_G2=280;
      t_HV_L1_G1=t_HV_L2_G1=285;
    }
    if(run == high_ind[i]) {
      t_HV_L1_In=t_HV_L2_In=1200;
    }
  }
}



int Set_Layer(int feb){
  if(feb>-1 && feb<16) return 0;
  else if(feb>15 && feb<44) return 1;
  else return -1;
}

int Set_Sheet(int feb, int lay){
  int sheet=0;
  if(lay==1){
    if( (feb>22 && feb<30) || (feb>36 && feb<45) ) sheet = 1;
  }
  return sheet;
}


int Set_strip_boss(int strip, int layer, int view, int sheet){
  int strippo=strip;
  if(strippo==-1) return strippo;
  if(layer==1 && sheet==1 && view==0) strippo-=630;
  if(layer==1 && sheet==1 && view==1) strippo-=1077;
  return strippo;
}


int Set_Side(int feb){
int side=0;
int east[22]={8,9,10,11,12,13,14,15,30,31,32,33,34,35,36,37,38,39,40,41,42,43};
int west[22]={0,1,2 ,3 ,4 ,5 ,6 ,7 ,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
for(int i=0;i<22;i++){
if(feb==east[i]) {side=-1; return side;}
if(feb==west[i]) {side= 1; return side;}
}
return side;
}

bool Check_File(TString name, TTree *tree, TFile *file){
  bool b1(0),b2(0),b3(0);
  b1=file->IsOpen();
  b2=(bool)tree;
  if(b2) b3=tree->IsFolder();
  if(b1*b2*b3) {
    cout<<"Init file "<<name<<endl;
    return true;
  }
  else {
    cout<<"ERROR in file "<<name<<b1<<b2<<b3<<endl;
    return false;
  }
}

void Define_Output(){
  TString ofile_name=Form("/home/ihep_data/data/LUT/CGEM_cosmic_look_up_table_%d.root",lut_number);
  ofile = new TFile(ofile_name,"RECREATE");
  otree = new TTree("tree","tree");
  otree->Branch("ROC",&t_roc,"ROC/I");
  otree->Branch("SW_FEB",&t_sw_feb,"SW_FEB/I");
  otree->Branch("FEB",&t_feb,"FEB/I");
  otree->Branch("chip",&t_chip,"chip/I");
  otree->Branch("channel",&t_ch,"channel/I");
  otree->Branch("layer",&t_layer,"layer/I");
  otree->Branch("side",&t_side,"side/I");
  otree->Branch("sheet",&t_sheet,"sheet/I");
  otree->Branch("strip_x_graal",&t_strip_x,"strip_x_graal/I");
  otree->Branch("strip_v_graal",&t_strip_v,"strip_v_graal/I");
  otree->Branch("strip_x_boss",&t_strip_xx,"strip_x_boss/I");
  otree->Branch("strip_v_boss",&t_strip_vv,"strip_v_boss/I");
  otree->Branch("calib_QDC_slope",&t_calib_QDC_slope,"calib_QDC_slope/F");
  otree->Branch("calib_QDC_const",&t_calib_QDC_const,"calib_QDC_const/F");
  otree->Branch("calib_QDC_saturation",&t_calib_QDC_saturation,"calib_QDC_saturation/F");
  otree->Branch("baseline_T_mV",&t_base_t,"baseline_T_mV/F");
  otree->Branch("baseline_E_mV",&t_base_e,"baseline_E_mV/F");
  otree->Branch("v_thr_T_mV",&t_vth1_mV,"v_thr_T_mV/F");
  otree->Branch("v_thr_E_mV",&t_vth2_mV,"v_thr_E_mV/F");
  otree->Branch("thr_T_fC",&t_thr_t_fC,"thr_T_fC/F");
  otree->Branch("thr_E_fC",&t_thr_e_fC,"thr_E_fC/F");
  otree->Branch("thr_fC",&t_thr_fC,"thr_fC/F");
  otree->Branch("noise_rate_Hz",&t_noise_Hz,"noise_rate_Hz/F");
  otree->Branch("noise_meanQ_fC",&t_noise_Q,"noise_meanQ_fC/F");
  otree->Branch("signal_meanQ_fC",&t_signal_Q,"signal_meanQ_fC/F");
  otree->Branch("signal_maxQ_fC",&t_signal_maxQ,"signal_maxQ_fC/F");
  otree->Branch("signal_rate_Hz",&t_signal_rate,"signal_rate_Hz/F");
  otree->Branch("signal_startTime_ns",&t_signal_tstart,"signal_startTime_ns/F");
  otree->Branch("signal_stopTime_ns",&t_signal_tstop,"signal_stopTime_ns/F");
  otree->Branch("signal_sigmaTime_ns",&t_signal_tsigma,"signal_sigmaTime_ns/F");
  otree->Branch("signal_FEBstartTime_ns",&t_signal_tstartFEB,"signal_FEBstartTime_ns/F");
  otree->Branch("signal_FEBstopTime_ns",&t_signal_tstopFEB,"signal_FEBstopTime_ns/F");
  otree->Branch("signal_FEBsigmaTime_ns",&t_signal_tsigmaFEB,"signal_FEBsigmaTime_ns/F");
  otree->Branch("quality",&t_quality,"quality/I");

  ootree = new TTree("general","general");
  ootree->Branch("First_RUN"       ,&t_First_RUN       ,"First_RUN/I");
  ootree->Branch("Last_RUN"        ,&t_Last_RUN        ,"Last_RUN/I");
  ootree->Branch("Integration_time",&t_Integration_time,"Integration_time/I");
  ootree->Branch("Energy_mode"     ,&t_Energy_mode     ,"Energy_mode/I");
  ootree->Branch("HV_L1_G3"        ,&t_HV_L1_G3        ,"HV_L1_G3/I");
  ootree->Branch("HV_L2_G3"        ,&t_HV_L2_G3        ,"HV_L2_G3/I");
  ootree->Branch("HV_L3_G3"        ,&t_HV_L3_G3        ,"HV_L3_G3/I");
  ootree->Branch("HV_L1_G2"        ,&t_HV_L1_G2        ,"HV_L1_G2/I");
  ootree->Branch("HV_L2_G2"        ,&t_HV_L2_G2        ,"HV_L2_G2/I");
  ootree->Branch("HV_L3_G2"        ,&t_HV_L3_G2        ,"HV_L3_G2/I");
  ootree->Branch("HV_L1_G1"        ,&t_HV_L1_G1        ,"HV_L1_G1/I");
  ootree->Branch("HV_L2_G1"        ,&t_HV_L2_G1        ,"HV_L2_G1/I");
  ootree->Branch("HV_L3_G1"        ,&t_HV_L3_G1        ,"HV_L3_G1/I");
  ootree->Branch("HV_L1_In"        ,&t_HV_L1_In        ,"HV_L1_In/I");
  ootree->Branch("HV_L2_In"        ,&t_HV_L2_In        ,"HV_L2_In/I");
  ootree->Branch("HV_L3_In"        ,&t_HV_L3_In        ,"HV_L3_In/I");
  ootree->Branch("HV_L1_T2"        ,&t_HV_L1_T2        ,"HV_L1_T2/I");
  ootree->Branch("HV_L2_T2"        ,&t_HV_L2_T2        ,"HV_L2_T2/I");
  ootree->Branch("HV_L3_T2"        ,&t_HV_L3_T2        ,"HV_L3_T2/I");
  ootree->Branch("HV_L1_T1"        ,&t_HV_L1_T1        ,"HV_L1_T1/I");
  ootree->Branch("HV_L2_T1"        ,&t_HV_L2_T1        ,"HV_L2_T1/I");
  ootree->Branch("HV_L3_T1"        ,&t_HV_L3_T1        ,"HV_L3_T1/I");
  ootree->Branch("HV_L1_Dr"        ,&t_HV_L1_Dr        ,"HV_L1_Dr/I");
  ootree->Branch("HV_L2_Dr"        ,&t_HV_L2_Dr        ,"HV_L2_Dr/I");
  ootree->Branch("HV_L3_Dr"        ,&t_HV_L3_Dr        ,"HV_L3_Dr/I");


  return;
}

bool init(int run){
  bool is_init=true;
  //Initialize
  NO_time_reference = true;
  lut_number=run;
  file_name1="/home/ihep_data/TIGER_Event_Reconstruction/mapping_and_calibration_file/mapping_CGEMBOSS_2.0.root"; //Mapping                                         
  file_name2="/home/ihep_data/TIGER_Event_Reconstruction/mapping_and_calibration_file/QDCcalib_CGEMBOSS_2.0.root"; //Calibration QDC   
  file_name3=Form("/home/ihep_data/TIGER_Event_Reconstruction/export/thr_run_%i.root",lut_number); //threshold mV and baseline
  file_name4=Form("/home/ihep_data/data/raw_daq/extracted_noise_thr_%i.root",lut_number); //Threshold fC 
  file_name5="";//"timeref3_tigerwalk2channel2_run17.root"; //time-reference                                                                                        
  file_name6="";//"CGEM_cosmic_look_up_table_from_17_timeref_channel.root"; //previous time calib file                                                              
  t_First_RUN        =   lut_number;
  t_Last_RUN         =   lut_number;
  //Init file/tree
  file1 = new TFile(file_name1);
  tree1 = (TTree*)file1->Get("tree");
  file2 = new TFile(file_name2);
  tree2 = (TTree*)file2->Get("tree");
  file3 = new TFile(file_name3);
  tree3 = (TTree*)file3->Get("tree");
  file4 = new TFile(file_name4);
  tree4 = (TTree*)file4->Get("tree");
  file5 = new TFile(file_name5);
  tree5 = (TTree*)file5->Get("tree");
  file6 = new TFile(file_name6);
  tree6 = (TTree*)file6->Get("tree");

  //Output
  Define_Output();
  //Check the files
  is_init*=Check_File(file_name1, tree1, file1);
  is_init*=Check_File(file_name2, tree2, file2);
  is_init*=Check_File(file_name3, tree3, file3);
  is_init*=Check_File(file_name4, tree4, file4);
  if (!NO_time_reference)is_init*=Check_File(file_name5, tree4, file5);
  if (!NO_time_reference)is_init*=Check_File(file_name6, tree4, file6);
  custom_setting(run);
  return is_init;
}

void Read_Mapping(){
  int channel_id, pos_x, pos_v, chip_id, FEB_label_id;
  tree1->SetBranchAddress("channel_id", &channel_id);
  tree1->SetBranchAddress("pos_x", &pos_x);
  tree1->SetBranchAddress("pos_v", &pos_v);
  tree1->SetBranchAddress("chip_id", &chip_id);
  tree1->SetBranchAddress("FEB_label", &FEB_label_id);
  memset(mx, -1, sizeof(mx));
  memset(mv, -1, sizeof(mv));
  for (int i = 0; i < tree1->GetEntries(); i++) {
    tree1->GetEntry(i);
    if(pos_x*pos_v<=0 && (mx[FEB_label_id][chip_id-1][channel_id])==-1 && mv[FEB_label_id][chip_id-1][channel_id]==-1 ){ 
      mx[FEB_label_id][chip_id-1][channel_id] = pos_x;
      mv[FEB_label_id][chip_id-1][channel_id] = pos_v;
    }
  }
  return;
}

void Read_Calibration_QDC(){
  int channel_id, gemroc_id, SW_FEB_id;
  float constant, slope, qmax;
  tree2->SetBranchAddress("channel_id", &channel_id);
  tree2->SetBranchAddress("gemroc_id" , &gemroc_id);
  tree2->SetBranchAddress("SW_FEB_id" , &SW_FEB_id);
  tree2->SetBranchAddress("constant"  , &constant);
  tree2->SetBranchAddress("slope"     , &slope);
  tree2->SetBranchAddress("qmax"      , &qmax);
  memset(cons  , -1, sizeof(cons));
  memset(mslope, -1, sizeof(mslope));
  memset(mqmax , -1, sizeof(mqmax));
  for (int i = 0; i < tree2->GetEntries(); i++) {
    tree2->GetEntry(i);
    if(gemroc_id<0||SW_FEB_id<-1) continue;
    cons  [gemroc_id][SW_FEB_id][channel_id] = constant;
    mslope[gemroc_id][SW_FEB_id][channel_id] = slope;
    mqmax [gemroc_id][SW_FEB_id][channel_id] = qmax;
  }
  return;
}

void Read_Thr_mV(){
  int gemroc_id, software_feb_id, channel_id, baseline_e, baseline_t, vth1_dig, vth2_dig;
  float thr_e_fC, thr_t_fC;
  tree3->SetBranchAddress("gemroc_id", &gemroc_id);
  tree3->SetBranchAddress("software_feb_id", &software_feb_id);
  tree3->SetBranchAddress("channel_id",&channel_id);
  tree3->SetBranchAddress("vth1",&vth1_dig);
  tree3->SetBranchAddress("vth2",&vth2_dig);
  tree3->SetBranchAddress("baseline_e",&baseline_e);
  tree3->SetBranchAddress("baseline_t",&baseline_t);
  tree3->SetBranchAddress("thr_e_fC",&thr_e_fC);
  tree3->SetBranchAddress("thr_t_fC",&thr_t_fC);
  memset(mvth1_dig, -1, sizeof(mvth1_dig));
  memset(mvth2_dig, -1, sizeof(mvth2_dig));
  memset(mbase_t , -1, sizeof(mbase_t ));
  memset(mbase_e , -1, sizeof(mbase_e ));
  memset(mth_t_fC, -1, sizeof(mth_t_fC));
  memset(mth_e_fC, -1, sizeof(mth_e_fC));
  for (int i = 0; i < tree3->GetEntries(); i++) {
    tree3->GetEntry(i);
    mvth1_dig[gemroc_id][software_feb_id][channel_id]=vth1_dig;
    mvth2_dig[gemroc_id][software_feb_id][channel_id]=vth2_dig;
    mbase_t [gemroc_id][software_feb_id][channel_id]=baseline_t;
    mbase_e [gemroc_id][software_feb_id][channel_id]=baseline_e;
    mth_t_fC[gemroc_id][software_feb_id][channel_id]=thr_t_fC;
    mth_e_fC[gemroc_id][software_feb_id][channel_id]=thr_e_fC;
  }
  return;
}

void Read_Thr_fC(){ //read the extracted noise/signal ter -X
  int channel_id, chip_id, FEB_label_id;
  double thr_fC, noise_Hz, noise_Q;
  double sig_maxQ, sig_meanQ, sig_rate;
  double sig_t0, sig_tF, sig_tsigma;
  double sig_t0F, sig_tFF, sig_tsigmaF;
  int sig_qaqc;
  tree4->SetBranchAddress("channel", &channel_id);
  tree4->SetBranchAddress("chip", &chip_id);
  tree4->SetBranchAddress("FEB", &FEB_label_id);  
  tree4->SetBranchAddress("threshold_fC", &thr_fC);
  tree4->SetBranchAddress("noise_rate_Hz", &noise_Hz);
  tree4->SetBranchAddress("noise_meanQ_fC", &noise_Q);
  tree4->SetBranchAddress("signal_meanQ_fC", &sig_meanQ);
  tree4->SetBranchAddress("signal_maxQ_fC", &sig_maxQ);
  tree4->SetBranchAddress("signal_rate_Hz", &sig_rate);
  tree4->SetBranchAddress("time_start2_ns", &sig_t0);
  tree4->SetBranchAddress("time_stop2_ns", &sig_tF);
  tree4->SetBranchAddress("time_sigma2_ns", &sig_tsigma);
  tree4->SetBranchAddress("time_start2tiger_ns", &sig_t0F);
  tree4->SetBranchAddress("time_stop2tiger_ns", &sig_tFF);
  tree4->SetBranchAddress("time_sigma2tiger_ns", &sig_tsigmaF);
  tree4->SetBranchAddress("channel_quality", &sig_qaqc);
  memset(mthr_fC, -1, sizeof(mthr_fC));
  memset(mnoise_Hz, -1, sizeof(mnoise_Hz));
  memset(mnoise_Q, -1, sizeof(mnoise_Q));
  memset(msignal_meanQ, -1, sizeof(msignal_meanQ));
  memset(msignal_maxQ, -1, sizeof(msignal_maxQ));
  memset(msignal_Hz, -1, sizeof(msignal_Hz));
  memset(msignal_t0, -1, sizeof(msignal_t0));
  memset(msignal_tF, -1, sizeof(msignal_tF));
  memset(msignal_dt, -1, sizeof(msignal_dt));
  memset(msignal_t0_tiger, -1, sizeof(msignal_t0_tiger));
  memset(msignal_tF_tiger, -1, sizeof(msignal_tF_tiger));
  memset(msignal_dt_tiger, -1, sizeof(msignal_dt_tiger));
  memset(msignal_quality, -1, sizeof(msignal_quality));
  for (int i = 0; i < tree4->GetEntries(); i++) {
    tree4->GetEntry(i);
    mthr_fC[FEB_label_id][chip_id-1][channel_id] = thr_fC;
    mnoise_Hz[FEB_label_id][chip_id-1][channel_id] = noise_Hz;
    mnoise_Q[FEB_label_id][chip_id-1][channel_id] = noise_Q;
    msignal_meanQ[FEB_label_id][chip_id-1][channel_id] = sig_meanQ;
    msignal_maxQ[FEB_label_id][chip_id-1][channel_id] = sig_maxQ;
    msignal_Hz[FEB_label_id][chip_id-1][channel_id] = sig_rate;
    //msignal_t0[FEB_label_id][chip_id-1][channel_id] = sig_t0;
    //msignal_tF[FEB_label_id][chip_id-1][channel_id] = sig_tF;
    //msignal_dt[FEB_label_id][chip_id-1][channel_id] = sig_tsigma;
    //msignal_t0_tiger[FEB_label_id][chip_id-1][channel_id] = sig_t0F;
    //msignal_tF_tiger[FEB_label_id][chip_id-1][channel_id] = 0;//sig_tFF;
    //msignal_dt_tiger[FEB_label_id][chip_id-1][channel_id] = 0;//sig_tsigmaF;
    msignal_quality[FEB_label_id][chip_id-1][channel_id] = sig_qaqc;
  }
  return;  
}

void Read_Previous_Time_Calibration(){
  int feb_id,chip_id, channel_id;
  float timeref_tiger, timeref_channel;
  tree6->SetBranchAddress("FEB"       , &feb_id);
  tree6->SetBranchAddress("channel"   , &channel_id);
  tree6->SetBranchAddress("chip"      , &chip_id);
  tree6->SetBranchAddress("signal_FEBstartTime_ns", &timeref_tiger);
  tree6->SetBranchAddress("signal_startTime_ns", &timeref_channel);
  for (int i = 0; i < tree6->GetEntries(); i++) {
    tree6->GetEntry(i);
    msignal_t0_tiger[feb_id][chip_id][channel_id] = timeref_tiger;
    msignal_t0[feb_id][chip_id][channel_id] = timeref_channel;
  }
  return;
}

void Read_Time_Reference(){
  double timeref_tiger,timeref_channel,err_time_tiger,err_time_channel,chi21,chi22;
  int nentries1,max1,nentries2,max2,feb_id,chip_id, channel_id;
  tree5->SetBranchAddress("feb"       , &feb_id);
  tree5->SetBranchAddress("channel"   , &channel_id);
  tree5->SetBranchAddress("chip"      , &chip_id);
  tree5->SetBranchAddress("nentries_tiger"  , &nentries1);
  tree5->SetBranchAddress("maxhisto_tiger"  , &max1);
  tree5->SetBranchAddress("nentries_channel"  , &nentries2);
  tree5->SetBranchAddress("maxhisto_channel"  , &max2);
  tree5->SetBranchAddress("chi2_tiger", &chi21);
  tree5->SetBranchAddress("chi2_channel", &chi22);
  tree5->SetBranchAddress("timeref_tiger", &timeref_tiger);
  tree5->SetBranchAddress("timeref_channel", &timeref_channel);
  tree5->SetBranchAddress("err_time_tiger", &err_time_tiger);
  tree5->SetBranchAddress("err_time_channel", &err_time_channel);
  for (int i = 0; i < tree5->GetEntries(); i++) {
    tree5->GetEntry(i);
    if(nentries1 > 250 && max1 > 30) msignal_t0_tiger[feb_id][chip_id][channel_id] += timeref_tiger;
    else msignal_t0_tiger[feb_id][chip_id][channel_id] += 0;
    if(chi22<100 && err_time_tiger<5 && err_time_channel<10 && err_time_channel!=0 && abs(timeref_tiger-timeref_channel)<25) msignal_t0[feb_id][chip_id][channel_id] +=(timeref_channel-timeref_tiger);
    else msignal_t0[feb_id][chip_id][channel_id] += 0;
  }
  return;
}




int Set_Bad_channel(int roc, int sw_feb, int ch, int quality){
  int bad_tail_L2[22][3]={
    10, 7, 0,
    10, 7, 3,
    10, 7, 4,
    10, 7, 11,
    10, 7, 12,
    10, 7, 14,
    10, 7, 15,
    10, 7, 16,
    10, 7, 19,
    10, 7, 20,
    10, 7, 22,
    10, 7, 23,
    10, 7, 26,
    10, 7, 28,
    10, 7, 49,
    10, 7, 50,
    10, 7, 51,
    10, 7, 52,
    10, 7, 55,
    10, 7, 56,
    10, 7, 59,
    10, 7, 60
  };
  for(int i=0;i<22;i++){
    if(roc==bad_tail_L2[i][0] && sw_feb==bad_tail_L2[i][1] && ch==bad_tail_L2[i][2]){
      quality=5;
    } 
  }
  //int noisy_channel[3][1]={
  //5, 6, 26
  //};
  //for(int i=0;i<1;i++){
  //if(roc==noisy_channel[0][i] && sw_feb==noisy_channel[1][i] && ch==noisy_channel[2][i]) return 2;
  //}
  return quality;
}

void Write_Output(){
  for(int iFEB=INIT_FEB;iFEB<MAX_FEB;iFEB++){
    for(int ichip=1; ichip<=N_CHIP;ichip++){
      for(int ich=0; ich<N_CHANNEL;ich++){
	if(iFEB>43 && no_planar) continue;
	t_roc=iFEB/4;
	t_feb=iFEB;
	t_chip=ichip-1;
	t_sw_feb=iFEB*2+t_chip-8*t_roc;
	t_ch=ich;
	t_layer=Set_Layer(t_feb);
	t_side=Set_Side(t_feb);
	t_strip_x=mx[t_feb][t_chip][t_ch];
	t_strip_v=mv[t_feb][t_chip][t_ch];
	t_sheet=Set_Sheet(t_feb,t_layer);
	t_strip_xx=Set_strip_boss(t_strip_x,t_layer,0,t_sheet);
	t_strip_vv=Set_strip_boss(t_strip_v,t_layer,1,t_sheet);
	t_thr_fC=mthr_fC[t_feb][t_chip][t_ch];
	t_noise_Hz=mnoise_Hz[t_feb][t_chip][t_ch];
	t_noise_Hz=mnoise_Hz[t_feb][t_chip][t_ch];
	t_noise_Q=mnoise_Q[t_feb][t_chip][t_ch];
	t_signal_Q=msignal_meanQ[t_feb][t_chip][t_ch];
	t_signal_maxQ=msignal_maxQ[t_feb][t_chip][t_ch];
	t_signal_rate=msignal_Hz[t_feb][t_chip][t_ch];
	if(!NO_time_reference)t_signal_tstart=msignal_t0[t_feb][t_chip][t_ch];
	else t_signal_tstart=0;
	if(!NO_time_reference)t_signal_tstop=msignal_tF[t_feb][t_chip][t_ch];
	else t_signal_tstop=0;
	if(!NO_time_reference)t_signal_tsigma=msignal_dt[t_feb][t_chip][t_ch];
	else t_signal_tsigma=0;
	if(!NO_time_reference)t_signal_tstartFEB=msignal_t0_tiger[t_feb][t_chip][t_ch];
	else t_signal_tstartFEB=0;
	if(!NO_time_reference)t_signal_tstopFEB=msignal_tF_tiger[t_feb][t_chip][t_ch];
	else t_signal_tstopFEB=0;
	if(!NO_time_reference)t_signal_tsigmaFEB=msignal_dt_tiger[t_feb][t_chip][t_ch];
	else t_signal_tsigmaFEB=0;
	t_quality=msignal_quality[t_feb][t_chip][t_ch];
	t_calib_QDC_slope=mslope[t_roc][t_sw_feb][t_ch];
	t_calib_QDC_const=cons  [t_roc][t_sw_feb][t_ch];
	t_calib_QDC_saturation=(-16-t_calib_QDC_const)/t_calib_QDC_slope;

	t_vth1_mV=5.25 * (mbase_t[t_roc][t_sw_feb][t_ch] - mvth1_dig [t_roc][t_sw_feb][t_ch]);
	t_vth2_mV=5.25 * (mbase_e[t_roc][t_sw_feb][t_ch] - mvth2_dig [t_roc][t_sw_feb][t_ch]);

	t_base_e= 0;//5.25 * mbase_e   [t_roc][t_sw_feb][t_ch];
	t_base_t= 0;//5.25 * mbase_t   [t_roc][t_sw_feb][t_ch];
	//t_vth1_mV=mvth1_mV [t_roc][t_sw_feb][t_ch];
	//t_vth2_mV=mvth2_mV [t_roc][t_sw_feb][t_ch];
	//t_base_e=mbase_e   [t_roc][t_sw_feb][t_ch];
	//t_base_t=mbase_t   [t_roc][t_sw_feb][t_ch];
	t_thr_e_fC=mth_e_fC[t_roc][t_sw_feb][t_ch];
	t_thr_t_fC=mth_t_fC[t_roc][t_sw_feb][t_ch];
	t_quality=Set_Bad_channel(t_roc,t_sw_feb,t_ch,t_quality);
	otree->Fill();
      }
    }
  }
  ootree->Fill();
  ofile->Write();
  ofile->Close();
  return;
}
int main(int argc, const char* argv[]){
  int run = atoi(argv[1]);
  cout<<"Ciao"<<endl;
  if(init(run)){
    Read_Mapping();
    Read_Calibration_QDC();
    Read_Thr_mV();
    Read_Thr_fC();
    if(!NO_time_reference) Read_Previous_Time_Calibration();
    if(!NO_time_reference) Read_Time_Reference();
    Write_Output();
    return 1;
  }
  else return 0;
}
