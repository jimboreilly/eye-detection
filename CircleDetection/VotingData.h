#ifndef VOTINGDATA_H
#define VOTINGDATA_H
class VotingData {
  int height;
  int width;
  int range;
  int ***data;
public:
  VotingData(int h, int w, int r);
  ~VotingData();                           //destructor
  VotingData(const VotingData & votes);            //copy constructor
  VotingData & operator=(const VotingData & votes); //assignment
  int getHeight();
  int getWidth();
  int getRange();
  int getVal(int i, int j, int k);
  void setVal(int i, int j, int k, int val);
private:
  void init(int h, int w, int r);
  void del();
  void cpy(const VotingData & votes);
  void areIndecesValid(int h, int w, int r);
};
#endif
