
#include"parser.h"
#include"jsonFormat.h"
#include <iostream>
#include <algorithm>
#include <memory>
using namespace std;














int main()
{
  std::vector<string> vNameOfFileWithFreezeFilter;
  std::vector<  std::vector<std::pair<float,float> > > vectorOfStreams;
  vNameOfFileWithFreezeFilter.emplace_back("file.txt");
  vNameOfFileWithFreezeFilter.emplace_back("secondFile.txt");
  float totalPeriod = 0;
  vector<float>vAggregatedPeriods;
  vector<float>vLongestValidPeriod;
  for(auto&iter : vNameOfFileWithFreezeFilter)
  {
    unique_ptr<eParser> l_parser = make_unique<parser>(iter);
    l_parser->Parse();
    l_parser->Print();
    // vector<float>>vecForStream;
    vAggregatedPeriods.emplace_back(l_parser->GetAggregatedPeriod());
    vLongestValidPeriod.emplace_back(l_parser->GetLongestValidPeriod());
    // cout<<" aggregated period "<<l_parser->GetAggregatedPeriod()
    // <<" logenst valid period "<<l_parser->GetLongestValidPeriod()<<endl;
    totalPeriod += l_parser->GetAggregatedPeriod();
    vectorOfStreams.emplace_back(move(l_parser->GetVec()));
  }

  // cout<<"vAggregatedPeriods "<<endl;
  for(auto&iter : vAggregatedPeriods)
  {
    cout<<iter<<endl;
  }

  // cout<<"vLongestValidPeriod "<<endl;

  // for(auto&iter : vLongestValidPeriod)
  // {
  //   cout<<"iter"<<iter<<endl;
  // }
  // cout<<"vectorOfStreams"<<endl;
  for(auto& iter :vectorOfStreams)
  {
    cout<<"prints vector"<<endl;
    for(auto& iter2 :iter)
    {
      cout<<iter2.first<<" "<<iter2.second<<endl;
    }
  }
  bool bAll_videos_freeze_frame_synced = true;
  string sFilename = "outputjson.txt";
  unique_ptr<eJsonFormat> l_jsonFormat = make_unique<jsonFormat>(vAggregatedPeriods,
  vLongestValidPeriod,totalPeriod,bAll_videos_freeze_frame_synced,sFilename,vectorOfStreams);
  l_jsonFormat->CreateJsonFormat();

  return 0;
}
