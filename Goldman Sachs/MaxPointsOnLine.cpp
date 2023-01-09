#include<bits/stdc++.h>
using namespace std;
 int maxPoints(vector< pair<int, int> > points) {
        int ans=1;
        int n=points.size();
        //to find slope of every line
        for(int i=0;i<n-1;i++)
        {
            map<double,int>mp;
            for(int j=i+1;j<n;j++)
            {
               double slope=double(points[j].second-points[i].second)/double(points[j].first-points[i].first); //finding slope
               if((points[j].second-points[i].second)<0 && points[j].first-points[i].first==0 )
               mp[abs(slope)]++;//making it positive
               else
               mp[slope]++; //storing the slope into map
            }
            int temp=0;
            //to find maximum slope
            for(auto it:mp)
            {
                temp=max(temp,it.second+1);//+1 to consider the current point
            }
            ans=max(ans,temp); //return max of all slope of all points
        }
      return ans;
    }

int main()
{
    const int N = 6;
    int arr[N][2] = {{-1, 1}, {0, 0}, {1, 1}, {2, 2},
                    {3, 3}, {3, 4}};
 
    vector< pair<int, int> > points;
    for (int i = 0; i < N; i++)
        points.push_back(make_pair(arr[i][0], arr[i][1]));
 
    cout << maxPoints(points) << endl;
    return 0;
}