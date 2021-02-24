void DoContour2DSterileGridRP11RP12RP13DATA_LogScale(double dmsq41  = 0.01,
                                                     double ssqth14 = 0.01,
                                                     double ssqth24 = 0.01,
                                                     bool performComboFit = true) {
  // Reco E
  Int_t nr = 6; Double_t r[7] = {6., 7., 8., 9., 10., 11., 12.};
  // PID
  Int_t np = 2; Double_t p[3] = {0.7, 0.8, 1.0};
  // Background components
  Int_t nt = 600; Double_t t[601]; for (int i = 0; i < 601; i++) t[i] = 0.1 * i;

  Extrapolate2D *E1 = new Extrapolate2D();
  E1->SetRecoBins(nr, r);
  E1->SetPIDBins(np, p);
  E1->SetTrueBins(nt, t);
  E1->SetFarPOT(2.96697e20);  // R11 alone (from AnaNue-F)
  E1->SetPID("E50S491");
  E1->SetFNforBeamNue();
  E1->SetRunPeriod(1);
  E1->SetNDDataFile("inputs/BeamDecompose/HOOHE_2pid_E50S491_Std_R11R12R13.root");
  E1->SetFNFile("inputs/ExtrapolationFiles/ExtrapFile_SSPID_E50S491_RP11.root");
  E1->SetXSecFile("inputs/XSecFile/xsec_minos_modbyrs4_v3_5_0_mk.root");
  E1->SetMREFile("inputs/MRE/MRE_Correction_MINOS_AfterSSPIDCut_r4_00_ND_20190728.root");
  //E1->SetPrintResult();
  E1->SetOscMethod(3);
  E1->GetPrediction();

  Extrapolate2D *E2 = new Extrapolate2D();
  E2->SetRecoBins(nr, r);
  E2->SetPIDBins(np, p);
  E2->SetTrueBins(nt, t);
  E2->SetFarPOT(2.80296e20);  // R12 alone (from AnaNue-F)
  E2->SetPID("E50S491");
  E2->SetFNforBeamNue();
  E2->SetRunPeriod(2);
  E2->SetNDDataFile("inputs/BeamDecompose/HOOHE_2pid_E50S491_Std_R11R12R13.root");
  E2->SetFNFile("inputs/ExtrapolationFiles/ExtrapFile_SSPID_E50S491_RP12.root");
  E2->SetXSecFile("inputs/XSecFile/xsec_minos_modbyrs4_v3_5_0_mk.root");
  E2->SetMREFile("inputs/MRE/MRE_Correction_MINOS_AfterSSPIDCut_r4_00_ND_20190728.root");
  //E2->SetPrintResult();
  E2->SetOscMethod(3);
  E2->GetPrediction();

  Extrapolate2D *E3 = new Extrapolate2D();
  E3->SetRecoBins(nr, r);
  E3->SetPIDBins(np, p);
  E3->SetTrueBins(nt, t);
  E3->SetFarPOT(3.88486e+20);
  E3->SetPID("E50S491");
  E3->SetFNforBeamNue();
  E3->SetRunPeriod(3);
  E3->SetNDDataFile("inputs/BeamDecompose/HOOHE_2pid_E50S491_Std_R11R12R13.root");
  E3->SetFNFile("inputs/ExtrapolationFiles/ExtrapFile_SSPID_E50S491_RP13.root");
  E3->SetXSecFile("inputs/XSecFile/xsec_minos_modbyrs4_v3_5_0_mk.root");
  E3->SetMREFile("inputs/MRE/MRE_Correction_MINOS_AfterSSPIDCut_r4_00_ND_20190728.root");
  //E3->SetPrintResult();
  E3->SetOscMethod(3);
  E3->GetPrediction();

  ErrorCalc *E = new ErrorCalc();
  E->SetNDDataFile("inputs/BeamDecompose/HOOHE_2pid_E50S491_Std_R11R12R13.root");  // Currently
  E->AddExtrap(E1);
  E->AddExtrap(E2);
  E->AddExtrap(E3);
  E->SetSysFileDir("inputs/Systematics/");
  E->AddFNExtrapSyst("Abs E-scale", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma", "Minus1Sigma", "Nominal", "AbsEScale", 2, true);
  E->AddFNExtrapSyst("EMvsHad", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma", "Minus1Sigma", "Nominal", "EMvsHad", 2, true);
  E->AddFNExtrapSyst("Had1 (Baryon $x_f$)", "Hadup1", "Hadup1", "Hadup1", "Hadup1", "Nominal", "had1", 2, true);
  E->AddFNExtrapSyst("Had2 ($\\pi^{0}$ sel.)", "Hadup2", "Hadup2", "Nominal", "Nominal", "Nominal", "had2", 2, true);
  E->AddFNExtrapSyst("Had3 (mult. corr.)", "Hadup3", "Hadup3", "Hadup3", "Hadup3", "Nominal", "had3", 2, true);
  E->AddFNExtrapSyst("Had4 (imp. amb.)", "Hadup4", "Hadup4", "Hadup4", "Hadup4", "Nominal", "had4", 2, true);
  E->AddFNExtrapSyst("Had5 ($p_T$ squz)", "Hadup5", "Hadup5", "Hadup5", "Hadup5", "Nominal", "had5", 2, true);
  E->AddFNExtrapSyst("Had6 (iso. 2-body dec.)", "Hadup6", "Hadup6", "Hadup6", "Hadup6", "Nominal", "had6", 2, true);
  E->AddFNExtrapSyst("Had10", "Hadup10", "Hadup10", "Nominal", "Nominal", "Nominal", "had10", 2, true);
  E->AddFNExtrapSyst("Hadron Mult.", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma", "Minus1Sigma", "Nominal", "HadMult", 2, true);
  E->AddFNExtrapSyst("KNO", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma", "Minus1Sigma", "Nominal", "KNO", 0, true);
  E->AddFNExtrapSyst("MAQE", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma", "Minus1Sigma", "Nominal", "MAQE", 0, true);
  E->AddFNExtrapSyst("MARES", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma", "Minus1Sigma", "Nominal", "MARES", 0, true);
  E->AddFNExtrapSyst("Rel E-scale (F $\\pm 1\\sigma$)", "Plus1Sigma", "Nominal", "Minus1Sigma", "Nominal", "Nominal", "RelEScale", 0, true);
  E->AddFNExtrapSyst("Rel E-scale (N $\\pm 1\\sigma$)", "Nominal", "Plus1Sigma", "Nominal", "Minus1Sigma", "Nominal", "RelEScale", 0, true);
  E->AddFNExtrapSyst("$\\nu_{\\tau}$ xsec", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma", "Minus1Sigma", "Nominal", "TauXSec", 2, true);
  E->AddFNExtrapSyst("$\\nu_{\\mu}$ MAQE", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma", "Minus1Sigma", "Nominal", "CCMAQE", 1, true);
  E->AddFNExtrapSyst("$\\nu_{\\mu}$ MARES", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma", "Minus1Sigma", "Nominal", "CCMARES", 1, true);
  E->AddFNExtrapSyst("$\\nu_{\\mu}$ KNO", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma", "Minus1Sigma", "Nominal", "CCKNO", 1, true);
  E->AddFNExtrapSyst("CCEnergyShift", "plus10pct", "plus10pct", "minus10pct", "minus10pct", "normal", "CCEnergyShift", 1, true);
  E->AddFNExtrapSyst("CCSigNC", "plus50pct", "plus50pct", "minus50pct", "minus50pct", "normal", "CCSigNC", 1, true);
  // Constant errors
  E->AddSpecialFNSyst("TauNorm", 0.024, "NULL", "NULL", 2);
  E->AddSpecialFNSyst("NueNorm", 0.024, "NULL", "NULL", 3);
  E->AddSpecialFNSyst("Norm", 0.02, "NULL", "NULL", 1);
  E->AddCovarianceMatrix("MRE", "inputs/MRE/MRE_ErrMatrix_20190728_r4_00.root", "syst_mre", 3);
  E->AddCovarianceMatrix("MRCC2", "inputs/MRCC/MRCC_ErrMatrix_2PIDbins_SSPID_09062020.root",  "syst_mrcc",  2);  // NuTauCC
  E->AddCovarianceMatrix("MRCC4", "inputs/MRCC/MRCC_ErrMatrix_2PIDbins_SSPID_09062020.root",  "syst_mrcc",  4);  // NumuCC and NC
  // Initialize the Errors
  E->CalculateSystErrorMatrix();
  
  double th12 = 0.5873;
  double dm21 = 7.53e-5;

  E1->SetOscPar(OscPar::kTh12, th12);
  E1->SetOscPar(OscPar::kDeltaM12, dm21);
  E1->SetOscPar(OscPar::kTh23, 0);
  E1->SetOscPar(OscPar::kDeltaM23, 0);
  E1->SetOscPar(OscPar::kTh13, 0);
  E1->SetOscPar(OscPar::kDelta, 0);
  E1->SetOscPar(OscPar::kDelta14, 0);
  E1->SetOscPar(OscPar::kDelta24, 0);
  E1->SetOscPar(OscPar::kTh34, 0);
  E1->SetOscPar(OscPar::kDm41, 0);
  E1->OscillatePrediction();

  E2->SetOscPar(OscPar::kTh12, th12);
  E2->SetOscPar(OscPar::kDeltaM12, dm21);
  E2->SetOscPar(OscPar::kTh23, 0);
  E2->SetOscPar(OscPar::kDeltaM23, 0);
  E2->SetOscPar(OscPar::kTh13, 0);
  E2->SetOscPar(OscPar::kDelta, 0);
  E2->SetOscPar(OscPar::kDelta14, 0);
  E2->SetOscPar(OscPar::kDelta24, 0);
  E2->SetOscPar(OscPar::kTh34, 0);
  E2->SetOscPar(OscPar::kDm41, 0);
  E2->OscillatePrediction();

  E3->SetOscPar(OscPar::kTh12, th12);
  E3->SetOscPar(OscPar::kDeltaM12, dm21);
  E3->SetOscPar(OscPar::kTh23, 0);
  E3->SetOscPar(OscPar::kDeltaM23, 0);
  E3->SetOscPar(OscPar::kTh13, 0);
  E3->SetOscPar(OscPar::kDelta, 0);
  E3->SetOscPar(OscPar::kDelta14, 0);
  E3->SetOscPar(OscPar::kDelta24, 0);
  E3->SetOscPar(OscPar::kTh34, 0);
  E3->SetOscPar(OscPar::kDm41, 0);
  E3->OscillatePrediction();

  // Runs 11, 12, 13  box opening
  TH1D *nobs = new TH1D("nobs", "", 12, -0.5, 11.5);
  nobs->SetBinContent(1, 18); // LEM [0.7, 0.8]; E [6,   7]
  nobs->SetBinContent(2, 26); // LEM [0.8, 1.0]; E [6,   7]
  nobs->SetBinContent(3, 11); // LEM [0.7, 0.8]; E [7,   8]
  nobs->SetBinContent(4, 20); // LEM [0.8, 1.0]; E [7,   8]
  nobs->SetBinContent(5, 8);  // LEM [0.7, 0.8]; E [8,   9]
  nobs->SetBinContent(6, 16); // LEM [0.8, 1.0]; E [8,   9]
  nobs->SetBinContent(7, 7);  // LEM [0.7, 0.8]; E [9,  10]
  nobs->SetBinContent(8, 7);  // LEM [0.8, 1.0]; E [9,  10]
  nobs->SetBinContent(9, 5);  // LEM [0.7, 0.8]; E [10, 11]
  nobs->SetBinContent(10, 2); // LEM [0.8, 1.0]; E [10, 11]
  nobs->SetBinContent(11, 3); // LEM [0.7, 0.8]; E [11, 12]
  nobs->SetBinContent(12, 7); // LEM [0.8, 1.0]; E [11, 12]

  NueFit2D *S = new NueFit2D();
  S->AddError(E);
  S->AddExtrap(E1);
  S->AddExtrap(E2);
  S->AddExtrap(E3);
  S->SetNObs(nobs);
  S->SetFitMethod(4);

  S->SetCombineFit(performComboFit);

  std::vector<double> TH34Values;
  TH34Values.push_back(0.0000);
  TH34Values.push_back(0.5000);
  TH34Values.push_back(0.0000);
  TH34Values.push_back(6.2832);
  S->AddTMinuitParams(OscPar::kTh34, "Theta34", TH34Values);

  std::vector<double> Delta24Values;
  Delta24Values.push_back(0.0000);
  Delta24Values.push_back(0.5000);
  Delta24Values.push_back(0.0000);
  Delta24Values.push_back(6.2832);
  S->AddTMinuitParams(OscPar::kDelta24, "Delta24", Delta24Values);

  std::vector<double> Delta14Values;
  Delta14Values.push_back(0.0000);
  Delta14Values.push_back(0.5000);
  Delta14Values.push_back(0.0000);
  Delta14Values.push_back(6.2832);
  S->AddTMinuitParams(OscPar::kDelta14, "Delta14", Delta14Values);

  std::vector<double> Delta13Values;
  Delta13Values.push_back(2.3562);
  Delta13Values.push_back(0.5000);
  Delta13Values.push_back(0.0000);
  Delta13Values.push_back(6.2832);
  S->AddTMinuitParams(OscPar::kDelta, "Delta13", Delta13Values);
  
  std::vector<double> TH23Values;
  TH23Values.push_back(0.7854);
  TH23Values.push_back(0.1000);
  TH23Values.push_back(0.6109);
  TH23Values.push_back(0.9600);
  S->AddTMinuitParams(OscPar::kTh23, "Theta23", TH23Values);
  
  std::vector<double> TH13Values;
  TH13Values.push_back(0.17453);
  TH13Values.push_back(0.10000);
  TH13Values.push_back(0.08727);
  TH13Values.push_back(0.26180);
  S->AddTMinuitParams(OscPar::kTh13, "Theta13", TH13Values);
 
  std::vector<double> DMSQ32Values;
  DMSQ32Values.push_back(2.48059E-3);
  DMSQ32Values.push_back(0.10000E-3);
  DMSQ32Values.push_back(2.10000E-3);
  DMSQ32Values.push_back(2.90000E-3);
  S->AddTMinuitParams(OscPar::kDeltaM23, "Dmsq32", DMSQ32Values);

  // Theta13 Penalty Term (https://pdg.lbl.gov/2020/listings/rpp2020-list-neutrino-mixing.pdf PAGE42)
  // Theta13 = 0.14819 (mean) - 0.14577 (lower) - 0.15057 (upper)
  //                            2.42E-3           2.38E-3
  S->SetPenaltyConstraintTheta13(0.14819, 2.42E-3);

  // Dmsq32 constraint from MINOS/MINOS+ (https://minos-docdb.fnal.gov/cgi-bin/private/RetrieveFile?docid=13844&filename=MAAM_3flav_07132020.pdf&version=2)
  S->SetPenaltyConstraintDmsq32(2.48E-3, 0.09E-3);

  // Theta23 constraint from MINOS/MINOS+ (https://minos-docdb.fnal.gov/cgi-bin/private/RetrieveFile?docid=13844&filename=MAAM_3flav_07132020.pdf&version=2)
  S->SetPenaltyConstraintTheta23Upper(0.922105, 5.195E-3);
  S->SetPenaltyConstraintTheta23Lower(0.66905, 0.036);

  S->Run2DSterileSlice_Ana2021(dmsq41, ssqth14, ssqth24);
  return;
}
