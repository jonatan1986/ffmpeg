/*
 * jsonFormat.h
 *
 *  Created on: Sep 22, 2020
 *      Author: yonathan
 */

#ifndef JSONFORMAT_H_
#define JSONFORMAT_H_

#include <iostream>
#include <algorithm>
#include <memory>
#include<fstream>

using namespace std;

class eJsonFormat
{
public:
  virtual ~eJsonFormat(){}
  virtual void CreateJsonFormat()const = 0;
};

class jsonFormat : public eJsonFormat
{
public:
  jsonFormat(  vector<float> &vAggregatedPeriods,vector<float>&vLongestValidPeriod,
  float totalPeriod, bool bAll_videos_freeze_frame_synced,  string &sFilename,
  vector<vector<pair<float,float> > > &vectorOfStreams):
  m_vAggregatedPeriods(vAggregatedPeriods),
  m_vLongestValidPeriod(vLongestValidPeriod),
  m_totalPeriod(totalPeriod),
  m_bAll_videos_freeze_frame_synced(bAll_videos_freeze_frame_synced),
  m_sFilename(sFilename),
  m_vectorOfStreams(vectorOfStreams)
  {
    // cout<<"cotwers"<<endl;
  }
  void CreateJsonFormat()const override
  {
    ofstream outputfile;
    outputfile.open(m_sFilename,ios::app);
    outputfile<<"{"<<endl;
      outputfile<<"all_videos_freeze_frame_synced"<<m_bAll_videos_freeze_frame_synced<<endl;
      outputfile<<"videos :["<<endl;
          // for(auto& iter1  = m_vLongestValidPeriod.begin(),
          // auto& iter2  = m_vAggregatedPeriods.begin() ;iter1!= m_vLongestValidPeriod.end();++iter1,++iter2)
          // {
          //   outputfile<<"{"<<endl<<"longest_valid_period"<<*iter1<<","<<endl
          //   <<"valid_video_percentage:"<<(*iter2)*100/m_totalPeriod<<","<<endl
          //   <<"valid_periods"<<":["<<endl;
          //
          //   if (iter1 != m_vLongestValidPeriod.end()-1)
          //   {
          //       outputfile<<","<<endl;
          //   }
          //   outputfile<<"}"<<endl;
          // }
      outputfile<<"]"<<endl;
    outputfile<<"}"<<endl;
    outputfile.close();
  }
private:
  vector<float> m_vAggregatedPeriods;
  vector<float> m_vLongestValidPeriod;
  float m_totalPeriod;
  bool m_bAll_videos_freeze_frame_synced;
  string m_sFilename;
  vector<vector<pair<float,float> > > m_vectorOfStreams;

};



#endif /* JSONFORMAT_H_ */
