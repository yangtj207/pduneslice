{

  TFile f("eventtree.root");
  TTree *spt = (TTree*)f.Get("sps/spt");

  std::vector<double> *vx;
  std::vector<double> *vy;
  std::vector<double> *vz;
  std::vector<int> *vtrackid;
  std::vector<int> *vg4id;

  spt->SetBranchAddress("vx",&vx);
  spt->SetBranchAddress("vy",&vy);
  spt->SetBranchAddress("vz",&vz);
  spt->SetBranchAddress("vtrackid",&vtrackid);
  spt->SetBranchAddress("vg4id",&vg4id);

  ofstream outfile("points.txt");

  int nentries = spt->GetEntries();
  std::cout<<spt->GetEntries()<<std::endl;
  for (int i = 0; i<nentries; ++i){
    cout<<"i = "<<i<<endl;
    spt->GetEntry(i);
    std::map<int, std::vector<std::vector<double>>> ptmap;
    for (size_t j = 0; j<vx->size(); ++j){
      if ((*vtrackid)[j]!=-1) continue;
      std::vector<double> pt;
      pt.push_back((*vx)[j]);
      pt.push_back((*vy)[j]);
      pt.push_back((*vz)[j]);
      ptmap[(*vg4id)[j]].push_back(pt);
    }
    int oldid = -1;
    int ntrks = 0;
    for (auto iter = ptmap.begin(); iter!=ptmap.end(); ++iter){
      for (size_t j = 0; j<(iter->second).size(); ++j){
        if (!iter->first) continue;
        if (oldid!=iter->first){
          oldid = iter->first;
          ++ntrks;
        }
        outfile<<ntrks<<" "<<(iter->second)[j][0]<<" "<<(iter->second)[j][1]<<" "<<(iter->second)[j][2]<<endl;
      }
    }
  }
  outfile.close();
}
