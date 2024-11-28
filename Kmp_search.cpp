#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tareq()                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

vector<int> compute_lps(string pattern)
{
  int patternlen = pattern.size();
  vector<int> lps_array(patternlen, 0);
  int i = 1, j = 0;
  lps_array[0] = 0;
  while (i < patternlen)
  {
    if (pattern[i] == pattern[j])
    {
      lps_array[i] = j + 1;
      j++;
      i++;
    }
    else
    {
      if (j != 0)
      {
        j = lps_array[j - 1];
      }
      else
      {
        lps_array[i] = 0;
        i++;
      }
    }
  }
  return lps_array;
}

int kmp_search(string pattern, string text, vector<int> lps)
{
  int textlen = text.size();
  int patternlen = pattern.size();
 // cout << textlen << " " << patternlen << endl;
  int i = 0, j = 0 , count = 0;
  while (i < textlen)
  {
    if (text[i] == pattern[j])
    {
      j++;
      i++;
    }
    else
    {
      if (j != 0)
      {
        j = lps[j - 1];
      }
      else
      {
        i++;
      }
    }
    // cout << j << " " << i << endl;
    if (j == patternlen)
    {  
      count++;
     // cout << j << " " << i << endl;
      //return (i - j);
      j = lps[j - 1];
      
    }
  }
  return count;
}

int32_t main()
{
  tareq()
  string text,pattern;
  cin >> text >> pattern;
  vector<int> lps = compute_lps(pattern);

  // for( auto u : lps ) {
  //   cout << u << " ";
  // }
  // cout << endl;
  cout << kmp_search(pattern, text, lps) << endl;
  /*
  some issues in return statement
  */
}