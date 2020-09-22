

/*
 * parser.h
 *
 *  Created on: Sep 22, 2020
 *      Author: yonathan
 */

#ifndef PARSER_H_
#define PARSER_H_







#include<fstream>
#include <iostream>
#include<vector>
#include <algorithm>
#include <math.h>


class eParser
{
public:
  virtual ~eParser(){}
  virtual void Parse() = 0;
  virtual void Print()const = 0;
  virtual float  GetTotalDuration()const = 0;
  virtual float GetLongestValidPeriod()const = 0;
  virtual float GetAggregatedPeriod()const = 0;
  virtual std::vector<std::pair<float,float>>& GetVec() = 0;
};
//
// using std::string;
// using std::cout;
// using std::endl;;
// using std::pair;
using namespace std;


class parser :public eParser
{
public:
  parser() = default;
  parser(string nameOfFile):m_nameOfFile(nameOfFile){}
  void Parse()
  {
      std::ifstream infile;
      infile.open(m_nameOfFile);
      size_t startPos = 0;
      std::string line;

      std::string startframe  = "lavfi.freezedetect.freeze_start: ";
      std::string endframe  = "lavfi.freezedetect.freeze_end: ";
      float nStartTime  = 0,nEndTime = 0;
      bool isFirstTime(true);
      while (std::getline(infile, line))
      {
        // cout<<line<<endl;
        int lineLength = line.length();
        if ((startPos = line.find(startframe)) !=std::string::npos)
        {
          startPos += startframe.length();
          string sStartTime = line.substr(startPos,lineLength - startPos);
          nStartTime = stof(sStartTime);
          nStartTime   = roundf(nStartTime * 100) / 100;
          // cout<<sStartTime<<" "<<nStartTime<<endl;
          pair<float,float> l_pair;
          if (isFirstTime)
          {
            isFirstTime = false;
            l_pair = make_pair<float,float>(0.00f,(float)nStartTime);
          }
          else
          {
            l_pair = make_pair<float,float>((float)nEndTime,(float)nStartTime);
          }
          float  l_validPeriod  = (float)nStartTime -(float)nEndTime;
          m_aggregatedPeriod += l_validPeriod;
          // cout<<"l_validPeriod "<<l_validPeriod
          // << " m_longestValidPeriod "<<m_longestValidPeriod<<endl;
          if (m_longestValidPeriod < l_validPeriod)
          {
            m_longestValidPeriod = l_validPeriod;
            m_longestValidPeriod = roundf(m_longestValidPeriod * 100) / 100;
              // cout<<"max vm_longestValidPeriod"<<m_longestValidPeriod<<endl;
          }
          m_vecFloat.emplace_back(l_pair);
          // bStartTimePassed = true;
        }
        else if ((startPos = line.find(endframe)) !=std::string::npos)
        {
          startPos += endframe.length();
          string sEndTime = line.substr(startPos,lineLength - startPos);
          nEndTime = stof(sEndTime);
          nEndTime = roundf(nEndTime * 100) / 100;
          // cout<<sEndTime<<" "<<nEndTime<<endl;
          // bStartTimePassed = false;
        }
      }
      infile.close();
  }
  void Print()const override
  {
    cout<<"vector of pairs"<<endl;
    for (auto& iter: m_vecFloat)
    {
      cout<<iter.first<<" "<<iter.second<<endl;
    }
  }
  float GetTotalDuration()const
  {
    float res = 0;
    for (auto& iter: m_vecFloat)
    {
      res += (float)iter.second - (float)iter.first;
    }
    return res;
  }
  float GetLongestValidPeriod()const override
  {

    return m_longestValidPeriod;
  }
  float GetAggregatedPeriod()const override
  {

    return m_aggregatedPeriod;
  }
  std::vector<std::pair<float,float>>& GetVec()
  {
    return m_vecFloat;
  }
private:
  std::vector<std::pair<std::string,std::string>> m_vecStr;
  std::vector<std::pair<float,float>> m_vecFloat;
  float m_longestValidPeriod = 0;
  float m_aggregatedPeriod = 0;
  string m_nameOfFile;
  // std::vector<std::pair<int,int> >vec;
};

#endif /* PARSER_H_ */
