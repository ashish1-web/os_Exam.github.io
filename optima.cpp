#include<bits/stdc++.h>
using namespace std;

int main()
{
	cout<<"INPUT FOR OPTIMAL PAGE REPLACEMENT"<<endl;
	
	int reference_string[25], frames[25], interval[25];                 //initiaizing the reference string , frames and intervals
      int pages, total_frames, page_faults = 0;							//intializing other variables
      int m, n, temp, flag, found;   
      int position, maximum_interval, previous_frame = -1;
      cout<<"\nEnter Total Number of Pages:\t";							//taking input the pages	
      cin>>pages;
      cout<<"\nEnter Values of Reference String\n";  					//taking input the reference string
      for(m = 0; m < pages; m++)
      { 
            cout<<"Value No.["<<m+1<<"]:\t";
            cin>>reference_string[m];									//storing the reference string
      }
      cout<<"\nEnter Total Number of Frames:\t";						//taking input the total no. of frames
      cin>>total_frames;						
      for(m = 0; m < total_frames; m++) 
      {
            frames[m] = -1;												//initializing the value of totoal frames an -1 
      }
      for(m = 0; m < pages; m++)                                       //looping for the number of pages
      {
            flag = 0;													//initialily setting the flag 0
            for(n = 0; n < total_frames; n++)							//itterating through all the frames
            {
                  if(frames[n] == reference_string[m])					//if the value is found in the string means if there is a hit
                  {
                        flag = 1;
                        cout<<"\t";
                        break;											//then break the loop
                  }
            }
            if(flag == 0) 												//if the pages is not found in the frame
            {
                  if (previous_frame == total_frames - 1)				//checking if the all the frames are filled up
                  {
                        for(n = 0; n < total_frames; n++)                //itterating through the entire frames
                        {      
                              for(temp = m + 1; temp < pages; temp++)    //loop to store the intervals to the next most page
                              {      
                                    interval[n] = 0;
                                    if (frames[n] == reference_string[temp])
                                    {      
                                          interval[n] = temp - m;
                                          break;
                                    }
                              }
                        }
                        found = 0;                
                        for(n = 0; n < total_frames; n++) //looping to find  if there is any empty frame and allocating its position and setint the flag
                        {
                              if(interval[n] == 0)
                              {                 
                                    position = n;
                                    found = 1;
                                    break;
                              }            
                        }
                  }
                  else
                  {
                        position = ++previous_frame;           //if the number of frames are not full then just put that value in that page and increment the page value
                        found = 1;
                  }
                  if(found == 0)      							
                  {
                        maximum_interval = interval[0];
                        position = 0;
                        for(n = 1; n < total_frames; n++)
                        {
                              if(maximum_interval < interval[n])			//finding out the maximum interval and then retrievign its positions
                              {
                                    maximum_interval = interval[n];
                                    position = n;
                              }
                        }
                   }     
                   frames[position] = reference_string[m];
                   cout<<"FAULT\t";
                   page_faults++;
            }
            
            for(n = 0; n < total_frames; n++)   			//if all the frames are filled then we are just ouptting all the frames
            {
                  if(frames[n] != -1) 
                  {
                        cout<<frames[n]<<"\t";
                  }
            }
            cout<<"\n";
      }
      cout<<"\nTotal Number of Page Faults:\t"<<page_faults<<"\n";  //printing all total number of page faults	
}



//Output

//Enter Total Number of Pages:    13
//Enter Values of Reference String
//Value No.[1]:   7
//Value No.[2]:   0
//Value No.[3]:   1
//Value No.[4]:   2
//Value No.[5]:   0
//Value No.[6]:   3
//Value No.[7]:   0
//Value No.[8]:   4
//Value No.[9]:   2
//Value No.[10]:  3
//Value No.[11]:  0
//Value No.[12]:  3
//Value No.[13]:  2
//Enter Total Number of Frames:   4
//FAULT   7
//FAULT   7       0
//FAULT   7       0       1
//FAULT   7       0       1       2
//        7       0       1       2
//FAULT   3       0       1       2
//        3       0       1       2
//FAULT   3       0       4       2
//        3       0       4       2
//        3       0       4       2
//        3       0       4       2
//        3       0       4       2
//        3       0       4       2
//Total Number of Page Faults:    6
