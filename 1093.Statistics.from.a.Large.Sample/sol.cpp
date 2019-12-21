#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
  vector<double> sampleStats(vector<int>& count) {
    int min_of_sample = 256;
    int max_of_sample = -1;
    int max_count = -1;
    int mode = -1;

    double sum_of_sample = 0;
    int num_of_sample = 0;

  	int num_count = 0;
  	for (size_t i = 0; i < count.size(); ++i)
  	{
  	  num_count = count[i];
  	  if (num_count != 0)
  	  {
  	    // min_of_sample has not been signed
	    if (min_of_sample == 256)
		{
			min_of_sample = i;
		}

		max_of_sample = i;

		// sum
		sum_of_sample += i * count[i];
		num_of_sample += count[i];
  	  	
  	  	// mode
  	  	if (count[i] > max_count)
  	  	{
  	  	  max_count = count[i];
  	  	  mode = i;
  	  	}	
  	  }
  	}

  	double median = -99;
  	if (num_of_sample % 2 == 1)
  	{
  	  int to_minus = num_of_sample / 2 + 1;
  	  for (size_t i = 0; i < 256; ++i)
  	  {
  	    to_minus -= count[i];
  	    if (to_minus <= 0)
  	    {
  	      median = i;
  	      break;
  	    }
  	  }
  	}
  	else if (num_of_sample % 2 == 0)
  	{
  	  int to_minus = num_of_sample / 2;
  	  for (size_t i = 0; i < 256; ++i)
  	  {
  	    to_minus -= count[i];
  	    if (to_minus == 0)
  	    {
  	      median = (i + i+1) / 2.0;  	      
  	      break;
  	    }
  	    else if (to_minus < 0)
  	    {
  	      median = i;
  	      break;
  	    }
  	  }
  	}


    vector<double> result;
    result.push_back(min_of_sample);
    result.push_back(max_of_sample); 
    double mean = sum_of_sample / num_of_sample;
    result.push_back(mean); 
    result.push_back(median);
    result.push_back(mode);
    return result;
  }
};


int main(int argc, char* argv[])
{
  vector<int> sample(256, 0);
  sample[1] = 1;
  sample[2] = 3;
  sample[3] = 4;
  Solution s;
  vector<double> d = s.sampleStats(sample);
  for (size_t i = 0; i < d.size(); ++i)
  {
    cout << d.at(i) << " " << endl;
  }
  return 0;
}
