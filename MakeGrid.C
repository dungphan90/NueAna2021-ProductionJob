void AddLogAxis(std::vector<double>& axis, double minrange, unsigned int nBins, double maxrange) {
  double log10minrange = TMath::Log10(minrange);
  double log10maxrange = TMath::Log10(maxrange);
  double log10stepsize = (log10maxrange - log10minrange) / (double) nBins;
  for (unsigned int i = 0; i <= nBins; ++i) {
    double logval = log10minrange + log10stepsize * (double) i;
    axis.push_back(TMath::Power(10, logval));
  }
}

void AddLinAxis(std::vector<double>& axis, double minrange, unsigned int nBins, double maxrange) {
  double stepsize = (maxrange - minrange) / (double) nBins;
  for (unsigned int i = 1; i <= nBins; ++i) {
    axis.push_back(minrange + stepsize * (double) i);
  }
}

std::vector<double> MakeLogLinearAxis(double min, unsigned int lognbins, double cut, unsigned int linnbins, double max) {
  std::vector<double> axis;
  AddLogAxis(axis, min, lognbins, cut);
  AddLinAxis(axis, cut, linnbins, max);

  return axis;
}


void MakeGrid(double dmsq41   = 1E-3,
              double max_axis = 0.5,
              double min_axis = 1E-3,
              double loglincut = 0.1,
              unsigned int logNBins = 20,
              unsigned int linNBins = 20) {
  std::vector<double> axis = MakeLogLinearAxis(min_axis, logNBins, loglincut, linNBins, max_axis);

  std::ofstream gridfile(Form("GridFiles/GRID_%1.5f.txt", dmsq41));
  TGraph* testGr = new TGraph();
  for (unsigned int i = 0; i < axis.size(); ++i) {
    for (unsigned int j = 0; j < axis.size(); ++j) {
      std::cout << Form("%1.5f, %1.5f, %1.5f", dmsq41, axis.at(i), axis.at(j)) << std::endl;
      gridfile << Form("%1.5f, %1.5f, %1.5f", dmsq41, axis.at(i), axis.at(j)) << std::endl;
      testGr->SetPoint(testGr->GetN(), axis.at(i), axis.at(j));
    }
  }
  gridfile.close();
  TCanvas* c = new TCanvas("c", "c", 800, 800);
  testGr->SetMarkerStyle(20);
  testGr->SetMarkerColor(kRed);
  testGr->Draw("AP");
  c->SaveAs("GridFiles/Grid.pdf");

  return;
}

std::vector<double> MakeMassGrid(double min, unsigned int nBins, double max) {
  double log10min = TMath::Log10(min);
  double log10max = TMath::Log10(max);
  double log10step = (log10max - log10min) / (double) nBins;
  std::vector<double> massgrid;
  for (unsigned int i = 0; i <= nBins; ++i) {
    massgrid.push_back(TMath::Power(10, log10min + log10step * (double)i));    
  }

  return massgrid;
}

void MakeGridWithMass() {
  double min_mass = 1E-3;
  double max_mass = 1E0;
  unsigned int nBins = 30;
  std::vector<double> massgrid = MakeMassGrid(min_mass, nBins, max_mass);
  for (unsigned int i = 0; i < massgrid.size(); ++i) {
    MakeGrid(massgrid.at(i));
  }
}
