#include <iostream>
#include <vector>
#include <utility>

using namespace std;
// array of prices, find buy,sell date maximum profit
pair<unsigned, unsigned> maxProfit(const vector<float> &prices)
{
  float maxProfit = 0.0;
  int buy=0, maxSell = (int)prices.size() -1, sell=(int)prices.size() -1;
  for ( int i = (int)prices.size() -2 ; i >=0 ; --i){
    if (prices[i] > prices[sell]) {
      maxSell = i;
    }
    if ((prices[maxSell] - prices[i]) > maxProfit){
      maxProfit = prices[sell] - prices[i];
      buy = i;
      sell = maxSell;
    }
  }
  return make_pair(buy,sell);
}

int main(int argc, const char * argv[])
{
  vector<float> vec1 = {110,120,13,5,18,10,11,112,15,16,20};
  auto ret = maxProfit(vec1);
  cout << vec1[ret.first] <<"->" << vec1[ret.second] << "\n";
  return 0;
}
