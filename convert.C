{

  TFile f("/pnfs/dune/scratch/users/tjyang/v09_16_01/sps/sps/anahist.root");
  TTree *spt = (TTree*)f.Get("sps/spt");

  int run, subrun, event;
  std::vector<double> *vx;
  std::vector<double> *vy;
  std::vector<double> *vz;
  std::vector<double> *vcharge;
  std::vector<int> *vtrackid;
  std::vector<int> *vg4id;

  spt->SetBranchAddress("run",&run);
  spt->SetBranchAddress("subrun",&subrun);
  spt->SetBranchAddress("event",&event);
  spt->SetBranchAddress("vx",&vx);
  spt->SetBranchAddress("vy",&vy);
  spt->SetBranchAddress("vz",&vz);
  spt->SetBranchAddress("vcharge",&vcharge);
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
      pt.push_back((*vcharge)[j]);
      ptmap[(*vg4id)[j]].push_back(pt);
    }
    outfile<<"Run "<<run<<" SubRun "<<subrun<<" Event "<<event<<endl;
    int oldid = -1;
    int ntrks = 0;
    for (auto iter = ptmap.begin(); iter!=ptmap.end(); ++iter){
      for (size_t j = 0; j<(iter->second).size(); ++j){
        if (!iter->first) continue;
        if (oldid!=iter->first){
          oldid = iter->first;
          ++ntrks;
        }
        outfile<<ntrks<<" "<<(iter->second)[j][0]<<" "<<(iter->second)[j][1]<<" "<<(iter->second)[j][2]<<" "<<(iter->second)[j][3]<<endl;
      }
    }
  }
  outfile.close();
}
